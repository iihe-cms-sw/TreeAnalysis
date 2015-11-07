#define HistMaker_cxx
#include "HistMaker.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <math.h>
#include <TFile.h>
#include <TH1.h>
#include <iostream>
using namespace std;

void HistMaker::Loop()
{
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;

   TFile *f = new TFile("FirstJetPtPDFReweight.root","RECREATE");
   TH1D* temhist;
   int nJetPt_Zinc1jet(20);
   double jetPt_Zinc1jet[21] = {30, 39, 49, 60, 72, 85, 100, 117, 136, 157, 187, 220, 258, 300, 350, 400, 450, 500, 590, 700, 1000};

   for(int j=0;j<100;j++){
       temhist = newTH1D("FirstJetPt_Zinc1jet", "1st jet p_{T} (N_{jets} #geq 1)", "p_{T}(j_{1}) [GeV]", nJetPt_Zinc1jet, jetPt_Zinc1jet);
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

       for(int i=1;i<101;i++){
           double nominal = EventWeight->at(0);
           double pdfweight = EventWeight->at(i);
           double ratio = pdfweight/nominal;
           if(fabs(ratio-1)>0.5){
               listOfHistograms[i-1]->Fill(genFirstJet_pt,nominal);
               temp += 1;
               sumanowt += 1;
           }
           else{
               listOfHistograms[i-1]->Fill(genFirstJet_pt,pdfweight);
           }
       }

       if(temp > 0) sumanoeve += 1;
   }

   cout << "*** The number of events with reset reweight: " << sumanoeve << endl
       << "*** The number of reset PDF reweight: " << sumanowt << endl;

   for(int j=0;j<100;j++){
       listOfHistograms[j]->Write();
   }

   cout << "Finish filling histograms!" << endl;
   f->Close();
}
