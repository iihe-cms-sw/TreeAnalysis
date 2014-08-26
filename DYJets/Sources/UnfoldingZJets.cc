#include <iostream>
#include <TApplication.h>
#include <TCanvas.h>
#include "fileNamesZJets.h"
#include "getFilesAndHistogramsZJets.h"

using namespace std;

int main(int argc, char **argv)
{
    TApplication* rootapp = new TApplication("rootapp", &argc, argv);
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
    //------------------------------------------------------------------------------------------ 

    //--- Now run on the different variables ---------------------------------------------------
    
    TCanvas *can = new TCanvas("can", "can", 900, 600);
    can->Connect("TCanvas", "Closed()", "TApplication", gApplication, "Terminate()");
    can->cd();
    TH1D *hData[3] = {NULL};
    getHistos(hData, fData, variable);
    hData[0]->DrawCopy();
    hData[1]->SetLineColor(kGreen);
    hData[1]->DrawCopy("same");
    cout << "say my name" << fData[1]->GetName() << endl;
    hData[2]->SetLineColor(kRed);
    hData[2]->DrawCopy("same");
    can->Update();
    //------------------------------------------------------------------------------------------ 

    rootapp->Run(kTRUE);

    //--- Close all files ----------------------------------------------------------------------
    closeAllFiles(fData, fDYJets, fBg, NBGDYJETS);
    //------------------------------------------------------------------------------------------ 

    return 0;

}
