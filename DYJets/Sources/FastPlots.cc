#include <TFile.h>
#include <TStyle.h>
#include <TH1.h>
#include <TH2.h>
#include <TCanvas.h>
#include <iostream>
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
#include "getFilesAndHistograms.h"
#include "unfoldingFunctions.h"
#include "writeFastPlotsTex.h"
#include "FastPlots.h"

//-- Setting global variables --------------------------------------------------------------
bool ISMUON(1);
#include "fileNames.h"
#include "variablesOfInterestVarWidth.h"
//--- for system command ---
#include <cstdlib>

void FastPlots(string var)
{
    TH1::SetDefaultSumw2();
    TH2::SetDefaultSumw2();
    gStyle->SetOptStat(0);
    gStyle->SetPaintTextFormat("1.2f");

    if (var == ""){
        //NVAROFINTEREST = 2;
        for (int i(1); i < 2/*NVAROFINTEREST*/; i++){
            cout << setw(3) << i << ") Processing variable: " << VAROFINTEREST[i].name << endl; 
            if (!ISMUON) FastPlotsRun(VAROFINTEREST[i].name, VAROFINTEREST[i].log, VAROFINTEREST[i].decrease, VAROFINTEREST[i].ESVDkterm, VAROFINTEREST[i].EBayeskterm );
            if (ISMUON)  FastPlotsRun(VAROFINTEREST[i].name, VAROFINTEREST[i].log, VAROFINTEREST[i].decrease, VAROFINTEREST[i].MuSVDkterm, VAROFINTEREST[i].MuBayeskterm );
        }
    }
    else{
        makeLISTOFVAROFINTEREST();
        if(LISTOFVAROFINTEREST->Contains(var.c_str())){
            TObjString *name = new TObjString(var.c_str());
            unsigned short j(LISTOFVAROFINTEREST->IndexOf(name));
            cout << setw(3) << " " << ") Processing variable: " << VAROFINTEREST[j].name << endl; 
            if (!ISMUON) FastPlotsRun(VAROFINTEREST[j].name, VAROFINTEREST[j].log, VAROFINTEREST[j].decrease, VAROFINTEREST[j].ESVDkterm, VAROFINTEREST[j].EBayeskterm );
            if (ISMUON)  FastPlotsRun(VAROFINTEREST[j].name, VAROFINTEREST[j].log, VAROFINTEREST[j].decrease, VAROFINTEREST[j].MuSVDkterm, VAROFINTEREST[j].MuBayeskterm );
        }
        else{
            if (!ISMUON) FastPlotsRun(var.c_str(),1,1,5,5);
            if (ISMUON)  FastPlotsRun(var.c_str(),1,1,5,5);
        }
    }
}


void FastPlotsRun(string variable, bool logZ, bool decrease, int SVDkterm, int Bayeskterm, bool closureTest, int JetPtMin, int JetPtMax, bool doFlat, bool doVarWidth)
{
    //-- retreive the year from curren location and set the energy accordingly
    string energy = getEnergy();

    ostringstream jetPtMin; jetPtMin << JetPtMin;
    string outputDirectory = "PNGFiles/FastPlots_" + jetPtMin.str() ;
    if (doVarWidth)  outputDirectory+= "_VarWidth";
    string command = "mkdir -p " + outputDirectory;
    system(command.c_str());
    outputDirectory +=  "/";

    string leptonFlavor = "DE_";
    if (ISMUON) leptonFlavor = "DMu_";

    string outputRootFileName = outputDirectory + leptonFlavor + energy + "_" + variable + "_fastplots";
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
    TH1D *genMad;
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




