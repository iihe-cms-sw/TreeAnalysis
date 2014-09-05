#include <iostream>
#include <vector>
#include <TFile.h>
#include <TH1D.h>
#include <TH2D.h>
#include "variablesOfInterestZJets.h"
#include "BLUEMeth.h"

using namespace std;

void Combination(TString unfoldDir, TString combDir, TString algo, int jetPtMin, int jetEtaMax)
{
    for (unsigned int i = 0; i < 1/*NVAROFINTERESTZJETS*/; ++i) {
        TString variable = VAROFINTERESTZJETS[i].name;

        //--- fetch the electron and muon unfolded files ---
        TString commonName = "_unfolded_" + variable + "_" + algo;
        commonName += "_jetPtMin_";
        commonName += jetPtMin;
        commonName += "_jetEtaMax_";
        commonName += jetEtaMax;
        commonName += ".root";
        TFile *fDE = new TFile(unfoldDir + "DE" + commonName);
        TFile *fDMu = new TFile(unfoldDir + "DMu" + commonName);
        
        fDE->cd();
        TH1D *hUnfDE = (TH1D*) fDE->Get("UnfDataCentral");
        TH2D *hCovDataStatDE = (TH2D*) fDE->Get("CovDataStat");
        TH2D *hCovMCStatDE = (TH2D*) fDE->Get("CovMCStat");
        TH2D *hCovPUSystDE = (TH2D*) fDE->Get("CovPU");
        TH2D *hCovJERSystDE = (TH2D*) fDE->Get("CovJER");
        TH2D *hCovXSecSystDE = (TH2D*) fDE->Get("CovXSec");
        TH2D *hCovLumiSystDE = (TH2D*) fDE->Get("CovLumi");
        TH2D *hCovSFSystDE = (TH2D*) fDE->Get("CovSF");
        TH2D *hCovJESSystDE = (TH2D*) fDE->Get("CovJES");
        fDMu->cd();
        TH1D *hUnfDMu = (TH1D*) fDMu->Get("UnfDataCentral");
        TH2D *hCovDataStatDMu = (TH2D*) fDMu->Get("CovDataStat");
        TH2D *hCovMCStatDMu = (TH2D*) fDMu->Get("CovMCStat");
        TH2D *hCovPUSystDMu = (TH2D*) fDMu->Get("CovPU");
        TH2D *hCovJERSystDMu = (TH2D*) fDMu->Get("CovJER");
        TH2D *hCovXSecSystDMu = (TH2D*) fDMu->Get("CovXSec");
        TH2D *hCovLumiSystDMu = (TH2D*) fDMu->Get("CovLumi");
        TH2D *hCovSFSystDMu = (TH2D*) fDMu->Get("CovSF");
        TH2D *hCovJESSystDMu = (TH2D*) fDMu->Get("CovJES");

        vector<TH1D*> measurements{hUnfDE, hUnfDMu};
        vector<vector<TH2D*>> covariances{
            {hCovDataStatDE, hCovMCStatDE, hCovPUSystDE, hCovJERSystDE, hCovXSecSystDE, hCovLumiSystDE, hCovSFSystDE, hCovJESSystDE}, 
            {hCovDataStatDMu, hCovMCStatDMu, hCovPUSystDMu, hCovJERSystDMu, hCovXSecSystDMu, hCovLumiSystDMu, hCovSFSystDMu, hCovJESSystDMu}
        };


        vector<TH2D*> covuxaxb(covariances[0].size(), NULL);
        TH2D* covxaxb = NULL;
        TH1D* hCombination = NULL;
        BLUEMeth* blue = new BLUEMeth(measurements, covariances, variable);
        bool diagCrossChannelCov = true;
        bool fullCrossChannelCov = true;
        bool fullIndivChannelCov = true;
        hCombination = blue->GetCombination(diagCrossChannelCov, fullCrossChannelCov, fullIndivChannelCov, covuxaxb, covxaxb);

        for (int i = 1; i <= hCombination->GetNbinsX(); ++i) {
            cout << hCombination->GetBinContent(i) << endl;
        }


        //--- Close all files ---
        fDE->Close();
        fDMu->Close();
    }
}
