#include <iostream>
#include <TH1.h>
#include <TH2.h>
#include <TFile.h>
#include <sstream>
#include <RooUnfoldResponse.h>

using namespace std;

void runMergeTop(TString lepSelection = "DE", int systematics = 0, float jetPtCutMin = 30, float jetEtaCutMax = 2.4, bool do10000Events = 0, TString outDir = "TEST");

void MergeTop();

void runMergeTop(TString lepSelection, int systematics, float jetPtCutMin, float jetEtaCutMax, bool do10000Events, TString outDir);
