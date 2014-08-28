#ifndef _UNFOLDINGZJETS_h_
#define _UNFOLDINGZJETS_h_

#include <RooUnfold.h>

void UnfoldingZJets(int* argc, char **argv);
TH1D* UnfoldData(TString algo, RooUnfoldResponse* resp, TH1D* hRecData, int nIter, TString name);

#endif
