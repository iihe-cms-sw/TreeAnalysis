#ifndef _UNFOLDINGZJETS_h_
#define _UNFOLDINGZJETS_h_

#include <tuple>
#include <RooUnfold.h>

void UnfoldingZJets(int* argc, char **argv);
void UnfoldData(TString algo, RooUnfoldResponse *resp, TH1D *hRecData, int nIter, TH1D* &hUnfData, TH2D* &hUnfDataStatCov, TH2D* &hUnfMCStatCov, TString name);
TH2D* M2H(TMatrixD m);
#endif
