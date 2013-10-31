#include <vector>
#include <TDirectory.h>
#include <TFile.h>
#include <TROOT.h>
#include <TStyle.h>
#include <TKey.h>
#include <TH1.h>
#include <TH2.h>
#include <THStack.h>
#include <TCanvas.h>
#include <TPad.h>
#include <TGraph.h>
#include <TPaveStats.h>
#include <TText.h>
#include <TLegend.h>
#include <iostream>
#include <sstream>
#include <TLorentzVector.h>
#include <RooUnfoldResponse.h>
#include <RooUnfold.h>
#include <RooUnfoldBayes.h>
#include <RooUnfoldSvd.h>
#include <RooUnfoldBinByBin.h>
#include <RooUnfoldInvert.h>
#include <TSVDUnfold.h>
#include <TLatex.h>
#include <TStyle.h>
#include <TDatime.h>
#include <TRandom3.h>
#include <TMatrixD.h>
#include "getFilesAndHistograms.h"
#include "DataDrivenQCD.h"
using namespace std;

//--  Setting global variables --------------------------------------------------------------
#include "fileNames.h"
#include "variablesOfInterestVarWidth.h"
string outputDirectory="DataDrivenQCD/";

bool isMuon(0);
string unfAlg = "Bayes";
string energy = getEnergy();
int JetPtMin(30);
int JetPtMax(0);
TFile *fOut = new TFile("DataDrivenQCD/out.root","recreate");
// TFile* outputRootFile = new TFile(outputRootFileName.c_str(), "RECREATE");

//-------------------------------------------------------------------------------------------
void DataDrivenQCD(){
	for (int i(0); i < 1/*NVAROFINTEREST*/; i++){
		FuncDataDrivenQCD();
	}
	fOut ->Close();
}

void FuncDataDrivenQCD(string variable, string leptonFlavor, bool doFlat , bool doVarWidth){

cout << " test" << endl;
//-- fetch the data files and histograms --------------
  const int NQCD = 4 ;
  TFile *fData[NQCD],*fSignal[NQCD];             // 0 = central, 1 = JES Up, 2 = JES Down 
  TH1D *hData[NQCD],*hSignal[NQCD],*hBack[NQCD];
  for ( int i=0 ; i < NQCD ; i++){
	  //getFiles(FILESDIRECTORY, fData, leptonFlavor, energy, DATAFILENAME, JetPtMin, JetPtMax, doFlat, doVarWidth);
	  fData[i] = getFile(FILESDIRECTORY,  leptonFlavor, energy, DATAFILENAME, JetPtMin, JetPtMax, doFlat, doVarWidth, i ,"","0");
	  cout << " got data " << variable << endl;
	  TH1D *hTemp = getHisto(fData[i], variable);
	  hData[i] = (TH1D *) hTemp->Clone();
	  cout << " got data histos " << ProcessInfo[i].filename << endl;
//	  fData[i]->Close();
  }
  //-----------------------------------------------------
  cout << " now open all the MC of interest " << endl;
  // ----------------- get all MC histos ---
  for ( int i=0 ; i < NQCD ; i++){
	  for ( int j = 1 ; j < NFilesWJets ; j++){

		  TFile *fTemp = getFile(FILESDIRECTORY,  leptonFlavor, energy, ProcessInfo[j].filename, JetPtMin, JetPtMax, doFlat, doVarWidth, i ,"","0");
		  TH1D *hTemp = getHisto(fTemp, variable);
		  //fOut ->cd(); hTemp->Write(); 
		  if ( ProcessInfo[j].filename.find("WJetsALL") != -1 ) {
		  cout << ProcessInfo[i].filename << endl;
			  hSignal[i] = (TH1D *) hTemp->Clone();
		  }
		  else{
			  if ( j == 1 ) {hBack[i] = (TH1D *) hTemp->Clone();}
			  else { cout << " adding " << endl; hBack[i]->Add(hTemp);  }
		  }
		  //fTemp->Close();
		  cout << " got histo" << i << "    " << j << endl; 
	  }

  }
  // QCD estiamtion procedure
  cout << " to QCD estimation " << endl;
  // followed as descirbed in AN2012_331 pages 10,11
TH1D* scaledMC[NQCD], *hQCD[NQCD];
  // step 0 : initial normalization of Wjets and data  
  cout << " normalization of signal "  <<hData[0]->Integral() <<"   " << hSignal[0]->Integral() <<"  " <<  hBack[0]->Integral() << endl;
//  TH1D *hSigInData = (TH1D*) hData[0]->Clone() ;
//  hSigInData->Add(hBack[0], -1 );
  double NormFactor = (hData[0]->Integral() - hBack[0]->Integral() ) / hSignal[0]->Integral() ;
  cout << " normalization of signal " << NormFactor <<hData[0]->Integral() <<"   " << hSignal[0]->Integral() <<"  " <<  hBack[0]->Integral() << endl;
 // step 1: 
 for ( int i = 0  ; i < NQCD ; i++){
	 scaledMC[i] = (TH1D*) hSignal[i]->Clone();
	 scaledMC[i]->Scale(NormFactor) ;
	 hQCD[i] = (TH1D*) hData[1]->Clone("QCD");
	 hQCD[i]->Add(scaledMC[i],-1);
	 hQCD[i]->Add(hBack[i],-1);
 }

 // step 2: isoaltion fake rate
    double NormFactorISO =  hQCD[1]->Integral() - hQCD[3]->Integral();
    cout << " ratio of regions B to C " << NormFactorISO << "   " << hQCD[1]->Integral() <<"   " << hQCD[3]->Integral() <<  endl;

// step 3 : isolation fake-rate from step 2 is aplied to QCD[0]
   hQCD[0] = (TH1D*) hQCD[2]->Clone();
   hQCD[0] ->Scale(NormFactorISO) ;
 
  // ---- save to file
  cout << " now save results to file " << endl; 
  fOut ->cd();
  cout << " now save results to file " << endl; 
  hData[0]->Write();
  cout << " now save results to file " << endl; 
  hSignal[0]->Write();
  cout << " now save results to file " << endl; 
  hBack[0]->Write();
  cout << " now save results to file " << endl; 

 for ( int i = 0  ; i < NQCD ; i++){
         hQCD[i] -> Write();
}
}

