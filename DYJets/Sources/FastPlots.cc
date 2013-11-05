#include <TFile.h>
#include <TStyle.h>
#include <TH1.h>
#include <TH2.h>
#include <TCanvas.h>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <RooUnfoldResponse.h>
#include <RooUnfoldSvd.h>
#include <RooUnfoldBayes.h>
#include <RooUnfoldBinByBin.h>
#include <RooUnfoldInvert.h>
#include <TSVDUnfold.h>
#include <TCanvas.h>
#include <TPad.h>
#include <TLegend.h>
#include <TList.h>
#include "getFilesAndHistograms.h"
#include "unfoldingFunctions.h"
#include "writeFastPlotsTex.h"
#include "FastPlots.h"

//-- Setting global variables --------------------------------------------------------------
#include "fileNames.h"
#include "variablesOfInterestVarWidth.h"

void FastPlots(string var, string leptonFlavor)
{
    TH1::SetDefaultSumw2();
    TH2::SetDefaultSumw2();
    gStyle->SetOptStat(0);
    gStyle->SetPaintTextFormat("1.2f");

    //--- load the proper VAROFINTERST structure: Z+jets or W+jets ---
    variableStruct *varStruct = NULL;
    TList *varList = new TList();
    int nVarStruct;
    if (leptonFlavor == "DMu" || leptonFlavor == "DE"){
        nVarStruct = NVAROFINTERESTZJETS;
        varStruct = new variableStruct[nVarStruct];
        varStruct = VAROFINTERESTZJETS;
        makeLISTOFVAROFINTERESTZJETS();
        varList = LISTOFVAROFINTERESTZJETS;
    }
    else if (leptonFlavor == "SMu" || leptonFlavor == "SE"){
        nVarStruct = NVAROFINTERESTWJETS;
        varStruct = new variableStruct[nVarStruct];
        varStruct = VAROFINTERESTWJETS;
        makeLISTOFVAROFINTERESTWJETS();
        varList = LISTOFVAROFINTERESTWJETS;
    }
    //---------------------------------------------

    //--- check wether muon or electron is used ---
    bool ISMUON;
    if (leptonFlavor.find("Mu") != string::npos) ISMUON = 1;
    else ISMUON = 0;
    //---------------------------------------------

    if (var == ""){
        nVarStruct = 1;
        for (int i(0); i < nVarStruct; i++){
            cout << setw(3) << i << ") Processing variable: " << varStruct[i].name << endl; 
            if (!ISMUON) FastPlotsRun(leptonFlavor, varStruct[i].name, varStruct[i].log, varStruct[i].decrease, varStruct[i].ESVDkterm, varStruct[i].EBayeskterm);
            if (ISMUON)  FastPlotsRun(leptonFlavor, varStruct[i].name, varStruct[i].log, varStruct[i].decrease, varStruct[i].MuSVDkterm, varStruct[i].MuBayeskterm);
        }
    }
    else{
        if(varList->Contains(var.c_str())){
            TObjString *name = new TObjString(var.c_str());
            unsigned short j(varList->IndexOf(name));
            cout << setw(3) << " " << ") Processing variable: " << varStruct[j].name << endl; 
            if (!ISMUON) FastPlotsRun(leptonFlavor, varStruct[j].name, varStruct[j].log, varStruct[j].decrease, varStruct[j].ESVDkterm, varStruct[j].EBayeskterm);
            if (ISMUON)  FastPlotsRun(leptonFlavor, varStruct[j].name, varStruct[j].log, varStruct[j].decrease, varStruct[j].MuSVDkterm, varStruct[j].MuBayeskterm);
        }
        else{
            if (!ISMUON) FastPlotsRun(leptonFlavor, var.c_str(),1,1,5,5);
            if (ISMUON)  FastPlotsRun(leptonFlavor, var.c_str(),1,1,5,5);
        }
    }

    delete varList;
    delete [] varStruct;
}


void FastPlotsRun(string leptonFlavor, string variable, bool logZ, bool decrease, int SVDkterm, int Bayeskterm, bool closureTest, int JetPtMin, int JetPtMax, bool doFlat, bool doVarWidth)
{
    //-- retreive the year from curren location and set the energy accordingly
    string energy = getEnergy();

    ostringstream jetPtMin; jetPtMin << JetPtMin;
    string outputDirectory = "PNGFiles/FastPlots_" + jetPtMin.str() ;
    if (doVarWidth)  outputDirectory+= "_VarWidth";
    string command = "mkdir -p " + outputDirectory;
    system(command.c_str());
    outputDirectory +=  "/";

    string outputRootFileName = outputDirectory + leptonFlavor + "_" + energy + "_" + variable + "_fastplots";
    if (closureTest) outputRootFileName += "_ClosureTest";
    if (doVarWidth) outputRootFileName += "_VarWidth";
    string outputTexFileName = outputRootFileName;
    outputRootFileName += ".root";
    outputTexFileName += ".tex";

    TFile *outputRootFile = new TFile(outputRootFileName.c_str(), "RECREATE");
    ofstream outputTexFile(outputTexFileName.c_str());
    writeHeaderPage(outputTexFile, leptonFlavor, variable);

    //-- get data histogram (or DY Even for closure test) ----------------------------

    TFile *DataFile;
    if (!closureTest) DataFile = getFile(FILESDIRECTORY, leptonFlavor, energy, DATAFILENAME, JetPtMin, JetPtMax, doFlat, doVarWidth);
    else DataFile = getFile(FILESDIRECTORY, leptonFlavor, energy, DYMADGRAPHFILENAME, JetPtMin, JetPtMax, doFlat, doVarWidth, 0, false, "_Even");
    TH1D *meas = getHisto(DataFile, variable);
    TH1D *measSubBG = (TH1D*) meas->Clone();

    //-- get DY madgraph histograms (or DY Odd for closure test) ---------------------
    TFile *DY;
    if (!closureTest) DY = getFile(FILESDIRECTORY, leptonFlavor, energy, DYMADGRAPHFILENAME, JetPtMin, JetPtMax, doFlat, doVarWidth);
    else DY = getFile(FILESDIRECTORY, leptonFlavor, energy, DYMADGRAPHFILENAME, JetPtMin, JetPtMax, doFlat, doVarWidth, 0, false, "_Odd");


    //-- get Powheg histograms -------------------------------------------------------
    //TFile *Powheg = getFile(FILESDIRECTORY, leptonFlavor, energy, DYPOWHEGFILENAME, JetPtMin, JetPtMax, doFlat);

    //-- get Powheg histograms -------------------------------------------------------
    //TFile *Sherpa = getFile(FILESDIRECTORY, leptonFlavor, energy, DYSHERPAFILENAME, JetPtMin, JetPtMax, doFlat);

    //-- get BG histograms -----------------------------------------------------------

    int nBG(9);
    TFile *BG[9];
    TH1D *hBG[9];
    for (int i(0); i < nBG; i++){
        BG[i] = getFile(FILESDIRECTORY, leptonFlavor, energy, BGFILENAMES[i], JetPtMin, JetPtMax, doFlat, doVarWidth);
        hBG[i] = getHisto(BG[i], variable);
        if (!closureTest && i != 6) measSubBG->Add(hBG[i], -1);
    }

    //-- build the repsonse matrix, MCtruth, MCreco, d and SV ------------------------
    string respName = "response" + variable;
    cout << __LINE__ << "  " << respName << endl;
    RooUnfoldResponse *response = (RooUnfoldResponse*) DY->Get(respName.c_str());
    cout << __LINE__ << endl;
    response->UseOverflow();
    string genName = "gen" + variable;
    TH1D *genMad = NULL;
    if (!closureTest) genMad = (TH1D*) DY->Get(genName.c_str());
    //else genMad = (TH1D*) DataFile->Get(genName.c_str());

    cout << __LINE__ << endl;
    TH2D *hResponse = (TH2D*) response->Hresponse();
    cout << __LINE__ << endl;
    TH2D *hNormResp = (TH2D*) hResponse->Clone(); 
    cout << __LINE__ << endl;
    normalizeTH2D(hNormResp);
    cout << __LINE__ << endl;
    TH1D *MCtruth   = (TH1D*) response->Htruth();
    cout << __LINE__ << endl;
    TH1D *MCreco    = (TH1D*) response->Hmeasured();
    cout << __LINE__ << endl;

    TSVDUnfold *unfoldTSVD = new TSVDUnfold(measSubBG, MCtruth, MCreco, hResponse);
    TH1D *unfresult = (TH1D*) unfoldTSVD->Unfold(1);
    unfresult->SetName(unfresult->GetName()); // Just ot get rid of the ennoying warning !
    TH1D *hmodD     = (TH1D*) unfoldTSVD->GetD();
    TH1D *hSV       = (TH1D*) unfoldTSVD->GetSV();

    //-------------------------------------------------------------------------------

    //-- get TH2D from Powheg -------------------------------------------------------
    //RooUnfoldResponse *respPow = (RooUnfoldResponse*) Powheg->Get(respName.c_str());
    //TH2D *hRespPow = (TH2D*) respPow->Hresponse();

    //-- get TH2D from Sherpa -------------------------------------------------------
    //RooUnfoldResponse *respShe = (RooUnfoldResponse*) Sherpa->Get(respName.c_str());
    //TH2D *hRespShe = (TH2D*) respShe->Hresponse();


    //if (closureTest) nBG = 0;
    //-- draw normalized response matrix --------------------------------------------
    cout << __LINE__ << endl;
    plotHNormResp(hNormResp, leptonFlavor, variable, energy, outputDirectory, outputRootFile, closureTest);
    cout << __LINE__ << endl;
    //-- draw singular values -------------------------------------------------------
    plotSVVector(hSV, hNormResp, leptonFlavor, variable, energy, outputDirectory, outputRootFile, closureTest);
    //-- draw d-vector --------------------------------------------------------------
    plotDVector(hmodD, SVDkterm, hNormResp, leptonFlavor, variable, energy, outputDirectory, outputRootFile, closureTest);
    //-- draw SVD unfolded distribution in a TH2 ------------------------------------
    plotSVDUnfoldedHistograms(response, meas, hBG, nBG, leptonFlavor, variable, energy, logZ, decrease, outputDirectory, outputRootFile, closureTest);
    //-- draw SVD selected kTerm and +/- 1 ------------------------------------------
    plotSelectedMethod("SVD", response, genMad, SVDkterm, meas, hBG, nBG, leptonFlavor, variable, logZ, decrease, outputDirectory, outputRootFile, closureTest);
    //-- draw chi2 of change --------------------------------------------------------
    plotChi2OfChange(response, Bayeskterm, meas, hBG, nBG, leptonFlavor, variable, energy, outputDirectory, outputRootFile, closureTest);
    //-- draw Bayes unfolded distribution in a TH2 ----------------------------------
    plotBayesUnfoldedHistograms(response, meas, hBG, nBG, leptonFlavor, variable, energy, logZ, decrease, outputDirectory, outputRootFile, closureTest);
    //-- draw Bayes selected kTerm and +/- 1 ----------------------------------------
    plotSelectedMethod("Bayes", response, genMad, Bayeskterm, meas, hBG, nBG, leptonFlavor, variable, logZ, decrease, outputDirectory, outputRootFile, closureTest);
    //-- compare SVD, Bayes, Bin by Bin ---------------------------------------------
    plotSVDvsBayesvsBBB(response, genMad, SVDkterm, Bayeskterm, meas, hBG, nBG, leptonFlavor, variable, logZ, decrease, outputDirectory, outputRootFile, closureTest);
    ////-- use Powheg for the response matrix with SVD ----------------------------------
    ////plotComparisonMadPowShe("SVD", hRespPow, hRespShe, response, SVDkterm, meas, hBG, nBG, leptonFlavor, variable, logZ, decrease, outputDirectory, outputRootFile, closureTest); 
    ////-- use Powheg for the response matrix with Bayes --------------------------------
    ////plotComparisonMadPowShe("Bayes", hRespPow, hRespShe, response, Bayeskterm, meas, hBG, nBG, leptonFlavor, variable, logZ, decrease, outputDirectory, outputRootFile, closureTest); 

    //writeComparisonPage(outputTexFile, leptonFlavor, variable, energy, JetPtMin, doFlat, logZ, closureTest, doVarWidth);
    //writeMethodPage(outputTexFile, leptonFlavor, variable, energy, JetPtMin, "SVD", closureTest, doVarWidth);
    //writeMethodPage(outputTexFile, leptonFlavor, variable, energy, JetPtMin, "Bayes", closureTest, doVarWidth);


    //-- close every files ----------------------------------------------------------
    outputRootFile->Close();
    closeFile(DataFile);
    closeFile(DY);
    //closeFile(Powheg);
    //closeFile(Sherpa);
    //if (closureTest) nBG = 8;
    for (int i(0); i < nBG; i++) closeFile(BG[i]);

    outputTexFile.close();
}




