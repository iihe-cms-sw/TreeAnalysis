#ifndef _getFilesAndhistogramsZJets_h_
#define _getFilesAndhistogramsZJets_h_

#include <iostream>
#include <TH1.h>
#include <TH2.h>
#include <TFile.h>
#include <RooUnfoldResponse.h>
#include <TString.h>
#include <vector>
#include "fileNamesZJets.h"

using namespace std;

TString getEnergy();
TFile* getFile(TString, TString, TString, TString, int jetPtMin = 30, int jetEtaMax = 24, TString closureTest = "", TString syst = "0");
void getFiles(TString, TFile *Files[], TString, TString, TString, int jetPtMin = 30, int jetEtaMax = 24);
void getAllFiles(TString histoDir, TString lepSel, TString energy, int jetPtMin, int jetEtaMax, TFile *fData[3], TFile *fDYJets[5], TFile *fBg[][5], int nBg);
void closeFile(TFile*);
void closeFiles(TFile *Files[]);
void closeFiles(TFile *Files[], int nFiles);
void closeAllFiles(TFile *fData[3], TFile *fDYJets[5], TFile *fBg[][5], int nBg);
TH1D* getHisto(TFile*, TString);
void getHistos(TH1D *histograms[], TFile *Files[], TString);
void getHistos(TH2D *histograms[], TFile *Files[], TString);
void getResp(RooUnfoldResponse*, TFile*, TString);
RooUnfoldResponse* getResp(TFile*, TString);
void getResps(RooUnfoldResponse *responses[], TFile *Files[], TString);
void getResps(RooUnfoldResponse *responses[13], TH1D *hRecDYJets[9], TH1D *hRecSumBg[9], TH1D *hGenDYJets[7], TH2D *hResDYJets[9]);
void getAllHistos(TString variable, TH1D *hRecData[3], TFile *fData[3], TH1D *hRecDYJets[9], TH1D *hGenDYJets[7], TH2D *hResDYJets[9], TFile *fDYJets[5], TH1D *hRecBg[][9], TH1D *hRecSumBg[9], TFile *fBg[][5], int nBg, RooUnfoldResponse *respDYJets[13]);
void getStatistics(TString lepSel = "DMu",  int jetPtMin = 30, int jetEtaMax = 24);
#endif

