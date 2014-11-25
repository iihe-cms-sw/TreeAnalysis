#include <iostream>
#include <TH1.h>
#include <TH2.h>
#include <TFile.h>
#include <sstream>
#include <RooUnfoldResponse.h>

using namespace std;


void MergeTop();
void runMergeTop(TString lepSelection, int systematics, int lepPtCutMin, int lepEtaCutMax, int jetPtCutMin, int jetRapidityCutMax, Long_t maxEvents, TString outDir);
