#include <iostream>
#include <TApplication.h>
#include <TCanvas.h>
#include "fileNamesZJets.h"
#include "getFilesAndHistogramsZJets.h"

using namespace std;

void UnfoldingZJets(int* argc, char **argv)
{
    TApplication* rootapp = new TApplication("rootapp", argc, argv);
    TCanvas::Connect("TCanvas", "Closed()", "TApplication", gApplication, "Terminate()");
    TString histoDir = "HistoFilesAugust";
    TString variable = "ZNGoodJets_Zexc";
    TString lepSel = "DMu";
    int jetPtMin = 30;
    int jetEtaMax = 24;

    // 0 - central, 1 - JES up, 2 - JES down
    TFile *fData[3] = {NULL}; 
    // 0 - central, 1 - PU up, 2 - PU down, 3 - JER up, 4 - JER down 
    TFile *fDYJets[5] = {NULL};
    // 0 - central, 1 - PU up, 2 - PU down, 3 - XSEc up, 4 - XSEC down 
    TFile *fBg[NBGDYJETS][5] = {{NULL}};

    //--- Open all files ---------------------------------------------------------------------- 
    getAllFiles(histoDir, lepSel, "8TeV", jetPtMin, jetEtaMax, fData, fDYJets, fBg, NBGDYJETS);
    //----------------------------------------------------------------------------------------- 

    //--- Now run on the different variables --------------------------------------------------
    
            

    //--- rec Data histograms ---
    TH1D *hRecData[3] = {NULL};
    //--- rec DYJets histograms ---
    TH1D *hRecDYJets[5] = {NULL};
    //--- gen DYJets histograms ---
    TH1D *hGenDYJets[5] = {NULL};
    //--- res DYJets histograms ---
    TH2D *hResDYJets[5] = {NULL};
    //--- response DYJets objects ---
    RooUnfoldResponse *respDYJets[5] = {NULL};
    //--- rec Bg histograms ---
    TH1D *hRecBg[NBGDYJETS][5] = {{NULL}};
    //--- rec Sum Bg histograms ---
    TH1D *hRecSumBg[5] = {NULL};

    //--- Get all histograms ------------------------------------------------------------------
    getAllHistos(variable, hRecData, fData, 
            hRecDYJets, hGenDYJets, hResDYJets, respDYJets, fDYJets,
            hRecBg, hRecSumBg, fBg, NBGDYJETS);
    //----------------------------------------------------------------------------------------- 
    



    TCanvas *can1 = new TCanvas("can1", "can1", 900, 600);
    can1->cd();
    hRecData[0]->DrawCopy();
    hRecData[1]->SetLineColor(kGreen);
    hRecData[1]->DrawCopy("same");
    hRecData[2]->SetLineColor(kRed);
    hRecData[2]->DrawCopy("same");
    can1->Update();
    //------------------------------------------------------------------------------------------ 


    rootapp->Run(kTRUE);

    //--- Close all files ----------------------------------------------------------------------
    closeAllFiles(fData, fDYJets, fBg, NBGDYJETS);
    //------------------------------------------------------------------------------------------ 

}
