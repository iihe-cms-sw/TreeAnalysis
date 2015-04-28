#include <iostream>
#include <TH1D.h>
#include <TFile.h>
#include <TCanvas.h>

using namespace std;

void makeScaleUncertainties() {

    TString varName = "genZNGoodJets_Zexc";

    
    TFile *f[9];
    f[0] = new TFile("HistoFilesApr/DMu_8TeV_DYJetsToLL_M-50_TuneCUETP8M1_8TeV-amcatnloFXFX-Bonzai_fixed_allWeights_dR_TrigCorr_1_Syst_0_JetPtMin_30_JetEtaMax_24_muR_1_muF_1.root");
    f[1] = new TFile("HistoFilesApr/DMu_8TeV_DYJetsToLL_M-50_TuneCUETP8M1_8TeV-amcatnloFXFX-Bonzai_fixed_allWeights_dR_TrigCorr_1_Syst_0_JetPtMin_30_JetEtaMax_24_muR_0.5_muF_0.5.root");
    f[2] = new TFile("HistoFilesApr/DMu_8TeV_DYJetsToLL_M-50_TuneCUETP8M1_8TeV-amcatnloFXFX-Bonzai_fixed_allWeights_dR_TrigCorr_1_Syst_0_JetPtMin_30_JetEtaMax_24_muR_0.5_muF_1.root");
    f[3] = new TFile("HistoFilesApr/DMu_8TeV_DYJetsToLL_M-50_TuneCUETP8M1_8TeV-amcatnloFXFX-Bonzai_fixed_allWeights_dR_TrigCorr_1_Syst_0_JetPtMin_30_JetEtaMax_24_muR_0.5_muF_2.root");
    f[4] = new TFile("HistoFilesApr/DMu_8TeV_DYJetsToLL_M-50_TuneCUETP8M1_8TeV-amcatnloFXFX-Bonzai_fixed_allWeights_dR_TrigCorr_1_Syst_0_JetPtMin_30_JetEtaMax_24_muR_1_muF_0.5.root");
    f[5] = new TFile("HistoFilesApr/DMu_8TeV_DYJetsToLL_M-50_TuneCUETP8M1_8TeV-amcatnloFXFX-Bonzai_fixed_allWeights_dR_TrigCorr_1_Syst_0_JetPtMin_30_JetEtaMax_24_muR_1_muF_2.root");
    f[6] = new TFile("HistoFilesApr/DMu_8TeV_DYJetsToLL_M-50_TuneCUETP8M1_8TeV-amcatnloFXFX-Bonzai_fixed_allWeights_dR_TrigCorr_1_Syst_0_JetPtMin_30_JetEtaMax_24_muR_2_muF_0.5.root");
    f[7] = new TFile("HistoFilesApr/DMu_8TeV_DYJetsToLL_M-50_TuneCUETP8M1_8TeV-amcatnloFXFX-Bonzai_fixed_allWeights_dR_TrigCorr_1_Syst_0_JetPtMin_30_JetEtaMax_24_muR_2_muF_1.root");
    f[8] = new TFile("HistoFilesApr/DMu_8TeV_DYJetsToLL_M-50_TuneCUETP8M1_8TeV-amcatnloFXFX-Bonzai_fixed_allWeights_dR_TrigCorr_1_Syst_0_JetPtMin_30_JetEtaMax_24_muR_2_muF_2.root");


    TH1D *h[9];
    for (int i(0); i < 9; ++i) {
        h[i] = (TH1D*) f[i]->Get(varName);
    }

    for (int i(1); i < 9; ++i) {
        h[i]->Divide(h[0]);
    }

    int nBins(h[0]->GetNbinsX());
    TH1D *hErrorsUp = new TH1D("hErrorsUp", "hErrorsUp", 0, nBins, nBins);
    TH1D *hErrorsDown = new TH1D("hErrorsDown", "hErrorsDown", 0, nBins, nBins);
    for (int i(1); i <= nBins; ++i) {
        hErrorsUp->SetBinContent(i, 1);
        hErrorsDown->SetBinContent(i, 1);
        for (int j(1); j < 9; ++j) {
            //hErrorsUp->SetBinContent(i, max(hErrorsUp->GetBinContent(i), h[j]->GetBinContent(i)));
            cout << max(hErrorsUp->GetBinContent(i), h[j]->GetBinContent(i)) << endl;
            hErrorsDown->SetBinContent(i, min(hErrorsUp->GetBinContent(i), h[j]->GetBinContent(i)));
        }
    }
    
    TCanvas *c = new TCanvas("c", "c", 600, 800);
    c->cd();
    hErrorsUp->Draw();

}
