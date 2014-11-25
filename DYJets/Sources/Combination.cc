#include <iostream>
#include <vector>
#include <TFile.h>
#include <TH1D.h>
#include <TH2D.h>
#include <TCanvas.h>
#include "variablesOfInterestZJets.h"
#include "PlotSettings.h"
#include "Combination.h"
#include "BLUEMeth.h"

using namespace std;

void Combination(TString unfoldDir, TString combDir, TString algo, int jetPtMin, int jetRapidityMax, bool diagXChanCov, bool fullXChanCov, bool fullSChanCov, TString variable)
{
    //--- create output directory if does not exist ---
    system("mkdir -p " + combDir);

    int start = 0;
    int end = NVAROFINTERESTZJETS;

    if (variable != "") {
        start = findVariable(variable);
        if (start >= 0) {
            end = start + 1;
        }
        else {
            cerr << "\nError: variable " << variable << " is not interesting." << endl;
            cerr << "See below the list of interesting variables:" << endl;
            for (unsigned int i = 0; i < NVAROFINTERESTZJETS; ++i) {
                cerr << "\t" << i << ": " << VAROFINTERESTZJETS[i].name << "\n" << endl;
            }
            return;
        }
    }

    //--- loop over the variable of interest ---
    for (int i = start; i < end; ++i) {
        variable = VAROFINTERESTZJETS[i].name;

        //--- fetch the electron and muon unfolded files ---
        TString commonName = "_unfolded_" + variable + "_" + algo;
        commonName += "_jetPtMin_";
        commonName += jetPtMin;
        commonName += "_jetRapidityMax_";
        commonName += jetRapidityMax;
        commonName += ".root";
        TFile *fDE = new TFile(unfoldDir + "DE" + commonName);
        if (!fDE->IsOpen()) {
            cerr << "\nError: file " << unfoldDir + "DE" + commonName << " does not exist." << endl;
            cerr << "       You can create it using\n\t ./runUnfoldingZJets lepSel=DE variable=" << variable << endl;
            cerr << "Skipping variable " << variable << ".\n" << endl;
            continue;
        }

        TFile *fDMu = new TFile(unfoldDir + "DMu" + commonName);
        if (!fDMu->IsOpen()) {
            cerr << "\nError: file " << unfoldDir + "DMu" + commonName << " does not exist." << endl;
            cerr << "       You can create it using\n\t ./runUnfoldingZJets lepSel=DMu variable=" << variable << endl;
            cerr << "Skipping variable " << variable << ".\n" << endl;
            continue;
        }
        //---------------------------------------------------------------------

        //--- fetch the cross section histogram and the covariance matrices ---
        fDE->cd();
        TH1D *hUnfDE = (TH1D*) fDE->Get("UnfDataCentral");
        TH1D *hMadGenDE = (TH1D*) fDE->Get("hMadGenDYJetsCrossSection");
        TH1D *hSheGenDE = (TH1D*) fDE->Get("hSheGenDYJetsCrossSection");
        TH1D *hPowGenDE = (TH1D*) fDE->Get("hPowGenDYJetsCrossSection");
        TH2D *hCovDataStatDE = (TH2D*) fDE->Get("CovDataStat");
        TH2D *hCovMCStatDE = (TH2D*) fDE->Get("CovMCStat");
        TH2D *hCovPUSystDE = (TH2D*) fDE->Get("CovPU");
        TH2D *hCovJERSystDE = (TH2D*) fDE->Get("CovJER");
        TH2D *hCovXSecSystDE = (TH2D*) fDE->Get("CovXSec");
        TH2D *hCovLumiSystDE = (TH2D*) fDE->Get("CovLumi");
        TH2D *hCovSFSystDE = (TH2D*) fDE->Get("CovSF");
        TH2D *hCovJESSystDE = (TH2D*) fDE->Get("CovJES");
        TH2D *hCovSherpaUnfSystDE = (TH2D*) fDE->Get("CovSherpaUnf");

        fDMu->cd();
        TH1D *hUnfDMu = (TH1D*) fDMu->Get("UnfDataCentral");
        TH1D *hMadGenDMu = (TH1D*) fDMu->Get("hMadGenDYJetsCrossSection");
        TH1D *hSheGenDMu = (TH1D*) fDMu->Get("hSheGenDYJetsCrossSection");
        TH1D *hPowGenDMu = (TH1D*) fDMu->Get("hPowGenDYJetsCrossSection");
        TH2D *hCovDataStatDMu = (TH2D*) fDMu->Get("CovDataStat");
        TH2D *hCovMCStatDMu = (TH2D*) fDMu->Get("CovMCStat");
        TH2D *hCovPUSystDMu = (TH2D*) fDMu->Get("CovPU");
        TH2D *hCovJERSystDMu = (TH2D*) fDMu->Get("CovJER");
        TH2D *hCovXSecSystDMu = (TH2D*) fDMu->Get("CovXSec");
        TH2D *hCovLumiSystDMu = (TH2D*) fDMu->Get("CovLumi");
        TH2D *hCovSFSystDMu = (TH2D*) fDMu->Get("CovSF");
        TH2D *hCovJESSystDMu = (TH2D*) fDMu->Get("CovJES");
        TH2D *hCovSherpaUnfSystDMu = (TH2D*) fDMu->Get("CovSherpaUnf");
        //---------------------------------------------------------------------

        //--- create the output root file ---
        TString outputFileName = combDir + variable + "_" + algo;
        outputFileName += "_diagXChanCov_"; 
        outputFileName += (int) diagXChanCov;
        outputFileName += "_fullXChanCov_"; 
        outputFileName += (int) fullXChanCov;
        outputFileName += "_fullSChanCov_"; 
        outputFileName += (int) fullSChanCov;
        outputFileName += "_jetPtMin_";
        outputFileName += jetPtMin;
        outputFileName += "_jetRapidityMax_";
        outputFileName += jetRapidityMax;

        TFile *outputRootFile = new TFile(outputFileName + ".root", "RECREATE");
        //---------------------------------------------------------------------


        //--- fill in the vector of measurements ---
        vector<TH1D*> measurements{hUnfDE, hUnfDMu};
        //---------------------------------------------------------------------

        //--- fill in the vector of vector of covariances ---
        vector<vector<TH2D*>> covariances{
            {hCovDataStatDE, hCovMCStatDE, hCovPUSystDE, hCovJERSystDE, hCovXSecSystDE, hCovLumiSystDE, hCovSFSystDE, hCovJESSystDE, hCovSherpaUnfSystDE}, 
                {hCovDataStatDMu, hCovMCStatDMu, hCovPUSystDMu, hCovJERSystDMu, hCovXSecSystDMu, hCovLumiSystDMu, hCovSFSystDMu, hCovJESSystDMu, hCovSherpaUnfSystDMu}
        };
        //---------------------------------------------------------------------


        //--- create objects to be filled with output of combination ---
        vector<TH2D*> covuxaxb(covariances[0].size(), NULL); // each covariance matrix
        TH2D* covxaxb = NULL; // total covariance matrix
        TH2D* covxaxbSyst = NULL; // total syst covariance matrix
        TH1D* hCombination = NULL; // combined cross section
        TH1D* hMadGenCombined = NULL;
        TH1D* hSheGenCombined = NULL;
        TH1D* hPowGenCombined = NULL;
        //---------------------------------------------------------------------

        //--- create the BLUEMeth object to compute the covariance ---
        BLUEMeth* blue = new BLUEMeth(measurements, covariances, variable);
        //---------------------------------------------------------------------

        //--- set up how you want to combine the channels and do the combination ---
        //one could rerun first do the combination with simple weighted average 
        //
        // hCombination = blue->GetCombination(false, false, false, covuxaxb, covxaxb);
        //
        //and then do it with full covariance to get the proper error without fetching 
        //the output of the measurement:
        //
        // blue->GetCombination(true, true, true, covuxaxb, covxaxb);
        //
        hCombination = blue->GetCombination(diagXChanCov, fullXChanCov, fullSChanCov, covuxaxb, covxaxb);

        covxaxbSyst = (TH2D*) covxaxb->Clone();
        covxaxbSyst->Add(covuxaxb[0], -1);
        covxaxbSyst->SetName("CombCovTotSyst");

        int nbins = covxaxb->GetNbinsX();
        for (int i = 1; i <= nbins; i++) {
            std::cout << i << "  " << sqrt(covxaxb->GetBinContent(i, i)) << std::endl;
        }
        hMadGenCombined = (TH1D*) hMadGenDE->Clone();
        hMadGenCombined->Add(hMadGenDMu);
        hMadGenCombined->Scale(0.5);
        hMadGenCombined->SetName("hMadCombGenDYJetsCrossSection");

        hSheGenCombined = (TH1D*) hSheGenDE->Clone();
        hSheGenCombined->Add(hSheGenDMu);
        hSheGenCombined->Scale(0.5);
        hSheGenCombined->SetName("hSheCombGenDYJetsCrossSection");

        hPowGenCombined = (TH1D*) hPowGenDE->Clone();
        hPowGenCombined->Add(hPowGenDMu);
        hPowGenCombined->Scale(0.5);
        hPowGenCombined->SetName("hPowCombGenDYJetsCrossSection");

        //---------------------------------------------------------------------


        //TCanvas *crossSectionPlot = makeCrossSectionPlot("", variable, hCombination, covxaxbSyst, hMadGenCombined, hSheGenCombined, hPowGenCombined); 
        TCanvas *crossSectionPlot = makeCrossSectionPlot("", variable, hCombination, covxaxbSyst, hMadGenCombined); 
        crossSectionPlot->Draw();
        crossSectionPlot->SaveAs(outputFileName + ".png");
        crossSectionPlot->SaveAs(outputFileName + ".pdf");
        crossSectionPlot->SaveAs(outputFileName + ".ps");
        crossSectionPlot->SaveAs(outputFileName + ".C");

        //--- print out the combined cross section measurement ---
        for (int i = 1; i <= hCombination->GetNbinsX(); ++i) {
            cout << hCombination->GetBinContent(i) << endl;
        }

        //--- save results and inputs to root file ---
        outputRootFile->cd();
        crossSectionPlot->Write();
        hCombination->Write("CombDataCentral");
        hMadGenCombined->Write();
        hSheGenCombined->Write();
        hPowGenCombined->Write();
        covxaxb->Write("CombCovTot");
        covxaxbSyst->Write("CombCovTotSyst");
        for (unsigned int i = 0; i < covuxaxb.size(); ++i) {
            covuxaxb[i]->Write();
        }

        hUnfDE->Write("DEUnfDataCentral");
        hCovDataStatDE->Write("DECovDataStat");
        hCovMCStatDE->Write("DECovMCStat");
        hCovPUSystDE->Write("DECovPU");
        hCovJERSystDE->Write("DECovJER");
        hCovXSecSystDE->Write("DECovXSec");
        hCovLumiSystDE->Write("DECovLumi");
        hCovSFSystDE->Write("DECovSF");
        hCovJESSystDE->Write("DECovJES");

        hUnfDMu->Write("DMuUnfDataCentral");
        hCovDataStatDMu->Write("DMuCovDataStat");
        hCovMCStatDMu->Write("DMuCovMCStat");
        hCovPUSystDMu->Write("DMuCovPU");
        hCovJERSystDMu->Write("DMuCovJER");
        hCovXSecSystDMu->Write("DMuCovXSec");
        hCovLumiSystDMu->Write("DMuCovLumi");
        hCovSFSystDMu->Write("DMuCovSF");
        hCovJESSystDMu->Write("DMuCovJES");

        //--- Close all files ---
        outputRootFile->Close();
        fDE->Close();
        fDMu->Close();

        if (end == start + 1) system("display " + outputFileName + ".png &");
    }
}
