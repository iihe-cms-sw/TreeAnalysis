#define HistMaker_cxx
#include "HistMaker.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <math.h>
#include <TFile.h>
#include <TH1.h>
#include <iostream>
#include <sstream>
using namespace std;

void HistMaker::Loop()
{
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;

   TFile *f = new TFile("FirstJetPtScalePDFReweight.root","RECREATE");
   TH1D* temhist;
   int nJetPt_Zinc1jet(22);
   double jetPt_Zinc1jet[23] = {20, 24, 30, 39, 49, 60, 72, 85, 100, 117, 136, 157, 187, 220, 258, 300, 350, 400, 450, 500, 590, 700, 1000};

   for(int j=0;j<106;j++){
       stringstream histName("");
       histName << "FirstJetPt_Zinc1jet_" << (j+1); 
       temhist = newTH1D(histName.str().c_str(), "1st jet p_{T} (N_{jets} #geq 1)", "p_{T}(j_{1}) [GeV]", nJetPt_Zinc1jet, jetPt_Zinc1jet);
   }

   double sumanoeve = 0;
   double sumanowt = 0;
   double temp = 0;

   cout << "There are totally " << nentries << " events !" << endl;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
       Long64_t ientry = LoadTree(jentry);
       if (ientry < 0) break;
       nb = fChain->GetEntry(jentry);   nbytes += nb;
       if (jentry%100000 == 0) cout << "Looping on " << jentry << " event ..." << endl;
       temp = 0;

       for(int i=1;i<107;i++){
           double nominal = EventWeight->at(0);
           double scalepdfweight = EventWeight->at(i);
           double ratio = scalepdfweight/nominal;
           listOfHistograms[i-1]->Fill(genFirstJet_pt,scalepdfweight);
           /*if(fabs(ratio-1)>0.5){
               listOfHistograms[i-1]->Fill(genFirstJet_pt,nominal);
               temp += 1;
               sumanowt += 1;
           }
           else{
               listOfHistograms[i-1]->Fill(genFirstJet_pt,scalepdfweight);
           }*/
       }

       if(temp > 0) sumanoeve += 1;
   }

   cout << "*** The number of events with reset reweight: " << sumanoeve << endl
       << "*** The number of reset scale/PDF reweight: " << sumanowt << endl;

   for(int j=0;j<106;j++){
       listOfHistograms[j]->Write();
   }

   cout << "Finish filling histograms!" << endl;
   f->Close();
}
