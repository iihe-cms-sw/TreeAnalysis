#include <iostream>
#include "UnfoldingZJets.h"

using namespace std;

void UnfoldingZJets()
{
    TString histoDir = "HistoFilesAugust";
    TString variable = "ZNGoodJets_Zexc";
    TString lepSel = "DMu";
    float jetPtMin = 30;
    float jetEtaMax = 2.4;

    //--- Open data files --- 
    TFile *fData[3] = {NULL}; // 0 - central, 1 - JES down, 2 - JES up
    getiFiles("HistoFilesAugust", fData, lepSel, "8TeV", ProcessInfo[DATAFILENAME], jetPtMin, jetEtaMax); 

}
