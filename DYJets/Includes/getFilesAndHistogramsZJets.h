#ifndef _getFilesAndhistogramsZJets_h_
#define _getFilesAndhistogramsZJets_h_

#include <iostream>
#include <TH1.h>
#include <TH2.h>
#include <TFile.h>
#include <RooUnfoldResponse.h>
#include <TString.h>
#include <vector>
using namespace std;

TString getEnergy();
TFile* getFile(TString, TString, TString, TString, int jetPtMin = 30, int jetEtaMax = 24, TString closureTest = "", TString syst = "0");
void getFiles(TString, TFile *Files[], TString, TString, TString, int jetPtMin = 30, int jetEtaMax = 24);
void closeFile(TFile*);
void closeFiles(TFile *Files[]);
void closeFiles(TFile *Files[], int nFiles);
TH1D* getHisto(TFile*, TString);
void getHistos(TH1D *histograms[], TFile *Files[], TString);
void getResp(RooUnfoldResponse*, TFile*, TString);
RooUnfoldResponse* getResp(TFile*, TString);
void getResps(RooUnfoldResponse *responses[], TFile *Files[], TString);
void getStatistics(TString lepSel = "DMu",  int jetPtMin = 30, int jetEtaMax = 24);
#endif

