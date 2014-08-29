#include <iostream>
#include <tuple>
#include <TApplication.h>
#include <TCanvas.h>
#include <RooUnfoldBayes.h>
#include "fileNamesZJets.h"
#include "getFilesAndHistogramsZJets.h"
#include "UnfoldingZJets.h"

using namespace std;

void UnfoldingZJets(int* argc, char **argv)
{
    // The TApplication is necessary only if we want to use TCanvas
    TApplication* rootapp = new TApplication("rootapp", argc, argv);
    // We connect the TCanvas close to the terminate of the TApplication
    TCanvas::Connect("TCanvas", "Closed()", "TApplication", gApplication, "Terminate()");

    TString histoDir = "HistoFilesAugust";
    //TString variable = "FourthJetEta_Zinc4jet";
    TString variable = "ZNGoodJets_Zexc";
    TString lepSel = "DMu";
    TString algo = "Bayes";
    TString outDir = "PNGFilesAugust/FinalUnfoldZJets/";
    TString energy = "8TeV"; 
    int jetPtMin = 30;
    int jetEtaMax = 24;

    // Here we declare the different arrays of TFiles. 
    // fData is for the three data files: 
    // 0 - central, 1 - JES up, 2 - JES down
    TFile *fData[3] = {NULL}; 
    // fDYJets is for the five DYJets files:
    // 0 - central, 1 - PU up, 2 - PU down, 3 - JER up, 4 - JER down 
    TFile *fDYJets[5] = {NULL};
    // fBg is for the NBGDYJETS x 5 systematics files:
    // 0 - central, 1 - PU up, 2 - PU down, 3 - XSEc up, 4 - XSEC down 
    TFile *fBg[NBGDYJETS][5] = {{NULL}};

    //--- Open all files ---------------------------------------------------------------------- 
    getAllFiles(histoDir, lepSel, "8TeV", jetPtMin, jetEtaMax, fData, fDYJets, fBg, NBGDYJETS);
    //----------------------------------------------------------------------------------------- 

    //----------------------------------------------------------------------------------------- 
    //--- Now run on the different variables ---
    
    TString outputRootFileName = outDir + lepSel + "_" + energy; 
    outputRootFileName += "_unfolded_" + variable + "_" + algo;
    outputRootFileName += ".root";
    TFile *outputRootFile = new TFile(outputRootFileName, "RECREATE");
            

    //--- rec Data histograms ---
    TH1D *hRecData[3] = {NULL};
    //--- rec DYJets histograms ---
    TH1D *hRecDYJets[9] = {NULL};
    //--- gen DYJets histograms ---
    TH1D *hGenDYJets[9] = {NULL};
    //--- res DYJets histograms ---
    TH2D *hResDYJets[9] = {NULL};
    //--- rec Bg histograms ---
    TH1D *hRecBg[NBGDYJETS][9] = {{NULL}};
    //--- rec Sum Bg histograms ---
    TH1D *hRecSumBg[9] = {NULL};
    //--- response DYJets objects ---
    RooUnfoldResponse *respDYJets[13] = {NULL};

    //--- Get all histograms ---
    getAllHistos(variable, hRecData, fData, 
            hRecDYJets, hGenDYJets, hResDYJets, fDYJets,
            hRecBg, hRecSumBg, fBg, NBGDYJETS, respDYJets);
    //----------------------------------------------------------------------------------------- 
    
    // Here is an array of TH1D to store the various unfolded data:
    // 0 - Central, 
    // 1 - JES up, 2 - JES down, 
    // 3 - PU up, 4 - PU down, 
    // 5 - JER up, 6 - JER down, 
    // 7 - XSEC up, 8 - XSEC down
    // 9 - Lumi up, 10 - Lumi down
    // 11 - SF up, 12 - SF down
    TString name[] = {"Central", "JesUp", "JesDown", "PUUp", "PUDown", "JERUp", "JERDown", "XSECUp", "XSECDown", "LumiUp", "LumiDown", "SFUp", "SFDown"};
    TH1D *hUnfData[13] = {NULL};
    TH2D *hUnfDataStatCov[13] = {NULL};
    TH2D *hUnfMCStatCov[13] = {NULL};

    int nIter = 4;
    //--- Unfold the Data histograms for each systematic ---
    for (unsigned short iSyst = 0; iSyst < 13; ++iSyst) {
        //--- only JES up and down (iSyst = 1 and 2) is applied on data ---
        unsigned short iData = (iSyst < 3) ? iSyst : 0;
        UnfoldData(algo, respDYJets[iSyst], hRecData[iData], nIter, hUnfData[iSyst], hUnfDataStatCov[iSyst], hUnfMCStatCov[iSyst], name[iSyst]);
        outputRootFile->cd(); hUnfData[iSyst]->Write();
    }
    //----------------------------------------------------------------------------------------- 

    cout << hUnfData[0]->GetBinContent(2)/19584. << endl;

    if (hUnfDataStatCov[0]) std::cout << "yeah " << std::endl;
    else std::cout << "problem" << std::endl;

    outputRootFile->cd();
    hRecData[0]->Write("hRecDataCentral");
    hRecSumBg[0]->Write("hRecSumBgCentral");
    hRecDYJets[0]->Write("hRecDYJetsCentral");
    hGenDYJets[0]->Write("hGenDYJetsCentral");
    respDYJets[0]->Write("respDYJetsCentral");
    //----------------------------------------------------------------------------------------- 


    TCanvas *can1 = new TCanvas("can1", "can1", 900, 600);
    can1->cd();
    hUnfData[0]->SetLineColor(kRed);
    hUnfData[0]->DrawCopy();
    for (unsigned short i = 1; i < 13; ++i) {
       hUnfData[i]->DrawCopy("samehist");
    }
    can1->Update();

    TCanvas *can2 = new TCanvas("can2", "can2", 700, 700);
    can2->cd();
    hUnfDataStatCov[0]->Draw("text");
    can2->Update();

    TCanvas *can3 = new TCanvas("can3", "can3", 700, 700);
    can3->cd();
    hUnfMCStatCov[0]->Draw("text");
    can3->Update();
    //------------------------------------------------------------------------------------------ 

    rootapp->Run(kTRUE);
    //--- Close all files ----------------------------------------------------------------------
    outputRootFile->Close();
    closeAllFiles(fData, fDYJets, fBg, NBGDYJETS);
    //------------------------------------------------------------------------------------------ 

}


void UnfoldData(TString algo, RooUnfoldResponse *resp, TH1D *hRecData, int nIter, TH1D* &hUnfData, TH2D* &hUnfDataStatCov, TH2D* &hUnfMCStatCov, TString name)
{
    //--- make sure we use OverFlow (should already be set to true) ---
    resp->UseOverflow();

    //--- Set the required unfolding algorithm ---
    RooUnfold::Algorithm alg = RooUnfold::kBayes;
    if (algo == "SVD") alg = RooUnfold::kSVD;

    //--- Unfold data minus background ---
    RooUnfold *RObject = RooUnfold::New(alg, resp, hRecData, nIter);
    //RObject->SetVerbose(0);

    //--- get the unfolded result ---
    hUnfData = (TH1D*) RObject->Hreco(RooUnfold::kCovariance);
    hUnfData->SetName("UnfData" + name);

    //--- get covariance from statistics on Data ---
    hUnfDataStatCov = M2H(RObject->GetDataStatCov());
    hUnfDataStatCov->SetName("UnfDataStatCov" + name);

    //--- get covariance from MC stat ---
    hUnfMCStatCov = M2H(RObject->GetMCStatCov());
    hUnfMCStatCov->SetName("UnfMCStatCov" + name);

    delete RObject;
}

TH2D* M2H(TMatrixD m) 
{
    int nBinsY = m.GetNrows();
    int nBinsX = m.GetNrows();

    TH2D *h = new TH2D(m.GetName(), m.GetName(), nBinsX-2, 0, nBinsX-2, nBinsY-2, 0, nBinsY-2);
    for (int i = 0; i < nBinsX; ++i) {
        for (int j = 0; j < nBinsY; ++j) {
            h->SetBinContent(i, j, m(i, j));
        }
    }

    return h;
}

