#ifndef _getFilesAndhistograms_h_
#define _getFilesAndhistograms_h_

#include <iostream>
#include <TH1.h>
#include <TFile.h>
#include <RooUnfoldResponse.h>

using namespace std;

const bool useUnfoldingFiles(false);

string getEnergy();
TFile* getFile(string histoFilesDirectory, string leptonFlavor, string energy, string Name, 
        int JetPtMin = 20, int JetPtMax = 0, bool doFlat = false, bool doVarWidth = false, 
        int doQCD = 0, bool doSSign = false, bool doInvMassCut = false, string closureTest = "", string syst = "0", bool dodR = false);
void getFiles(string, TFile *Files[], string, string, string, int JetPtMin = 20, int JetPtMax = 0, bool doFlat = false , bool doVarWidth = false, int doQCD = 0, bool doInvMassCut = false);
void closeFile(TFile*);
void closeFiles(TFile *Files[]);
TH1D* getHisto(TFile*, string);
void getHistos(TH1D *histograms[], TFile *Files[], string);
void getResp(RooUnfoldResponse*, TFile*, string);
RooUnfoldResponse* getResp(TFile*, string);
void getResps(RooUnfoldResponse *responses[], TFile *Files[], string);
void getStatistics(string leptonFlavor = "Muons", int JetPtMin = 30, int JetPtMax = 0, bool doFlat = false, bool doVarWidth = true, int doQCD = 0, bool doSSign = false, bool doInvMassCut = false);
#endif

