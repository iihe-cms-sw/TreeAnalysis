#ifndef _UNFOLDINGZJETS_h_
#define _UNFOLDINGZJETS_h_

#include <tuple>
#include <RooUnfold.h>
#include <TCanvas.h>

void UnfoldingZJets(TString lepSel, TString algo, TString histoDir, TString unfoldDir, 
        int jetPtMin, int jetEtaMax, TString variable = "");
void UnfoldData(const TString algo, RooUnfoldResponse *resp, TH1D *hRecData, int nIter, TH1D* &hUnfData, TH2D* &hUnfDataStatCov, TH2D* &hUnfMCStatCov, TString name, double integratedLumi);
TH2D* M2H(TMatrixD m);
TH2D* makeCovFromUpAndDown(const TH1D* hUnfDataCentral, const TH1D* hUnfDataUp, const TH1D* hUnfDataDown, TString name);
TH1D* makeCrossSectionHist(TH1D* hGenDYJets, double integratedLumi);
TCanvas* makeCrossSectionPlot(TString variable, TH1D *hData, TH2D *hCovSyst, TH1D *hGen, TString lepSel = "");
#endif
