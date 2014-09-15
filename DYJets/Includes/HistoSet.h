#ifndef _HistoSet_h_
#define _HistoSet_h_

#include <iostream>
#include <TObject.h>
#include <TH1.h>
#include <TH2.h>
#include <RooUnfoldResponse.h>
#include "TAxis.h" 
#include <TArray.h>
#include <vector>
#include <cstdarg>

using namespace std;

class HistoSet: public TObject{
    public:

        vector<TH1*> listOfHistograms;
        vector<RooUnfoldResponse*> listOfResponses;
        HistoSet(string leptonFlavor = "DMu");
        ~HistoSet();

        vector<double> makeVector(int num, ...);
        void insertVector(vector<double>& veca, int num, ...);
        TH1D* newTH1D(string, string, string, int, double*);
        TH1D* newTH1D(string, string, string, int, double, double);
        TH1D* newTH1D(string, string, string, vector<double>&);
        TH2D* newTH2D(string, string, int, double*, int, double*);
        TH2D* newTH2D(string, string, int, double*, int, double, double);
        TH2D* newTH2D(string, string, int, double, double, int, double*);
        TH2D* newTH2D(string, string, int, double, double, int, double, double);
        int NbinsEta2Dtest; 
        static const int NbinsEta2D = 9 ;
        double j_pT_range[NbinsEta2D];
        double j_Y_range[NbinsEta2D];


        //    const int NbinsEta2D(9) ;
        RooUnfoldResponse* newResp(TH1D*, TH1D*);
        RooUnfoldResponse* newResp(TH2D*, TH2D*);



        TH1D *NumberPFcandidates;
        TH1D *ZMass_lowDeltaR;
        TH1D *ZMass_Zinc0jet_test;
        TH1D *ZMassAllPassLep;
        TH1D *AllPassLepID;
        TH1D *AllPassWithMassCutLepID;
        TH1D *AllPassWithMassCutLepIDCharge;


        TH1D *ZMass_Zinc0jet;
        TH1D *ZMass_Zinc1jet;
        TH1D *ZMass_Zinc2jet;
        TH1D *ZMass_Zinc3jet;
        TH1D *ZMass_Zinc4jet;
        TH1D *ZMass_Zinc5jet;
        TH1D *ZMass_Zinc6jet;
        TH1D *genZMass_Zinc0jet_test;
        TH1D *genZMass_Zinc0jet;
        TH1D *genZMass_Zinc1jet;
        TH1D *genZMass_Zinc2jet;
        TH1D *genZMass_Zinc3jet;
        TH1D *genZMass_Zinc4jet;
        TH1D *genZMass_Zinc5jet;
        TH1D *genZMass_Zinc6jet;
        TH1D *ZMass_Zexc0jet;
        TH1D *ZMass_Zexc1jet;
        TH1D *ZMass_Zexc2jet;
        TH1D *ZMass_Zexc3jet;
        TH1D *ZMass_Zexc4jet;
        TH1D *ZMass_Zexc5jet;
        TH1D *ZMass_Zexc6jet;
        TH1D *ZPt_Zinc0jet;
        TH1D *ZPt_Zinc1jet;
        TH1D *ZPt_Zinc2jet;
        TH1D *ZPt_Zinc3jet;
        TH1D *ZPt_Zinc4jet;
        TH1D *ZPt_Zinc5jet;
        TH1D *ZPt_Zinc6jet;
        TH1D *genZPt_Zinc0jet;
        TH1D *genZPt_Zinc1jet;
        TH1D *genZPt_Zinc2jet;
        TH1D *genZPt_Zinc3jet;
        TH1D *genZPt_Zinc4jet;
        TH1D *genZPt_Zinc5jet;
        TH1D *genZPt_Zinc6jet;
        TH1D *ZPt_Zexc0jet;
        TH1D *ZPt_Zexc1jet;
        TH1D *ZPt_Zexc2jet;
        TH1D *ZPt_Zexc3jet;
        TH1D *ZPt_Zexc4jet;
        TH1D *ZPt_Zexc5jet;
        TH1D *ZPt_Zexc6jet;
        TH1D *ZRapidity_Zinc0jet;
        TH1D *ZRapidity_Zinc1jet;
        TH1D *ZRapidity_Zinc2jet;
        TH1D *ZRapidity_Zinc3jet;
        TH1D *ZRapidity_Zinc4jet;
        TH1D *ZRapidity_Zinc5jet;
        TH1D *ZRapidity_Zinc6jet;
        TH1D *genZRapidity_Zinc0jet;
        TH1D *genZRapidity_Zinc1jet;
        TH1D *genZRapidity_Zinc2jet;
        TH1D *genZRapidity_Zinc3jet;
        TH1D *genZRapidity_Zinc4jet;
        TH1D *genZRapidity_Zinc5jet;
        TH1D *genZRapidity_Zinc6jet;
        TH1D *ZRapidity_Zexc0jet;
        TH1D *ZRapidity_Zexc1jet;
        TH1D *ZRapidity_Zexc2jet;
        TH1D *ZRapidity_Zexc3jet;
        TH1D *ZRapidity_Zexc4jet;
        TH1D *ZRapidity_Zexc5jet;
        TH1D *ZRapidity_Zexc6jet;
        TH1D *ZEta_Zinc0jet;
        TH1D *ZEta_Zinc1jet;
        TH1D *ZEta_Zinc2jet;
        TH1D *ZEta_Zinc3jet;
        TH1D *ZEta_Zinc4jet;
        TH1D *ZEta_Zinc5jet;
        TH1D *ZEta_Zinc6jet;
        TH1D *genZEta_Zinc0jet;
        TH1D *genZEta_Zinc1jet;
        TH1D *genZEta_Zinc2jet;
        TH1D *genZEta_Zinc3jet;
        TH1D *genZEta_Zinc4jet;
        TH1D *genZEta_Zinc5jet;
        TH1D *genZEta_Zinc6jet;
        TH1D *ZEta_Zexc0jet;
        TH1D *ZEta_Zexc1jet;
        TH1D *ZEta_Zexc2jet;
        TH1D *ZEta_Zexc3jet;
        TH1D *ZEta_Zexc4jet;
        TH1D *ZEta_Zexc5jet;
        TH1D *ZEta_Zexc6jet;
        TH1D *lepEta_Zinc0jet;
        TH1D *lepEta_Zinc1jet;
        TH1D *lepEta_Zinc2jet;
        TH1D *lepEta_Zinc3jet;
        TH1D *lepEta_Zinc4jet;
        TH1D *lepEta_Zinc5jet;

        TH1D *lepPhi_Zexc0jet;
        TH1D *lepPhi_Zexc1jet;
        TH1D *lepPhi_Zexc2jet;
        TH1D *lepPhi_Zexc3jet;
        TH1D *lepPhi_Zexc4jet;
        TH1D *lepPhi_Zexc5jet;

        TH1D *lepPhi_Zinc0jet;
        TH1D *lepPhi_Zinc1jet;
        TH1D *genlepEta_Zinc0jet;
        TH1D *genlepEta_Zinc1jet;
        TH1D *genlepEta_Zinc2jet;
        TH1D *lepEta_Zexc0jet;
        TH1D *lepEta_Zexc1jet;
        TH1D *lepEta_Zexc2jet;
        TH1D *lepEta_Zexc3jet;
        TH1D *lepEta_Zexc4jet;
        TH1D *lepEta_Zexc5jet;
        TH2D *lepEtaEta_Zinc0jet;
        TH1D *FirstJetEta_Zinc1jet;
        TH1D *SecondJetEta_Zinc2jet;
        TH1D *ThirdJetEta_Zinc3jet;
        TH1D *FourthJetEta_Zinc4jet;
        TH1D *FifthJetEta_Zinc5jet;
        TH1D *SixthJetEta_Zinc6jet;
        TH1D *FirstJetEtaFull_Zinc1jet;
        TH1D *SecondJetEtaFull_Zinc2jet;
        TH1D *ThirdJetEtaFull_Zinc3jet;
        TH1D *FourthJetEtaFull_Zinc4jet;
        TH1D *FifthJetEtaFull_Zinc5jet;
        TH1D *SixthJetEtaFull_Zinc6jet;

        TH1D *genFirstJetEta_Zinc1jet;
        TH1D *genSecondJetEta_Zinc2jet;
        TH1D *genThirdJetEta_Zinc3jet;
        TH1D *genFourthJetEta_Zinc4jet;
        TH1D *genFifthJetEta_Zinc5jet;
        TH1D *genSixthJetEta_Zinc6jet;
        TH1D *FirstJetEta_Zexc1jet;
        TH1D *SecondJetEta_Zexc2jet;
        TH1D *AllJetEta_Zinc1jet;
        TH1D *AllJetEta_Zinc2jet;
        TH1D *AllJetEta_Zinc3jet;
        TH1D *AllJetEta_Zinc4jet;
        TH1D *FirstJetPhi_Zinc1jet;
        TH1D *SecondJetPhi_Zinc2jet;
        TH1D *ThirdJetPhi_Zinc3jet;
        TH1D *FourthJetPhi_Zinc4jet;
        TH1D *FifthJetPhi_Zinc5jet;
        TH1D *SixthJetPhi_Zinc6jet;
        TH1D *FirstJetPhi_Zexc1jet;
        TH1D *SecondJetPhi_Zexc2jet;
        TH1D *AllJetPhi_Zinc1jet;
        TH1D *AllJetPhi_Zinc2jet;
        TH1D *AllJetPhi_Zinc3jet;
        TH1D *AllJetPhi_Zinc4jet;
        TH1D *lepPt_Zinc0jet;
        TH1D *lepPt_Zinc1jet;
        TH1D *lepPt_Zinc2jet;
        TH1D *lepPt_Zinc3jet;
        TH1D *lepPt_Zinc4jet;
        TH1D *lepPt_Zinc5jet;
        TH1D *genlepPt_Zinc0jet;
        TH1D *genlepPt_Zinc1jet;
        TH1D *genlepPt_Zinc2jet;
        TH1D *lepPt_Zexc0jet;
        TH1D *lepPt_Zexc1jet;
        TH1D *lepPt_Zexc2jet;
        TH1D *lepPt_Zexc3jet;
        TH1D *lepPt_Zexc4jet;
        TH1D *lepPt_Zexc5jet;
        TH1D *dPhiLeptons_Zexc0jet;
        TH1D *dPhiLeptons_Zexc1jet;
        TH1D *dPhiLeptons_Zexc2jet;
        TH1D *dPhiLeptons_Zexc3jet;
        TH1D *dPhiLeptons_Zexc4jet;
        TH1D *dPhiLeptons_Zexc5jet;
        TH1D *dPhiLeptons_Zinc0jet;
        TH1D *dPhiLeptons_Zinc1jet;
        TH1D *dPhiLeptons_Zinc2jet;
        TH1D *dPhiLeptons_Zinc3jet;
        TH1D *dPhiLeptons_Zinc4jet;
        TH1D *dPhiLeptons_Zinc5jet;
        TH1D *dEtaLeptons_Zexc0jet;
        TH1D *dEtaLeptons_Zexc1jet;
        TH1D *dEtaLeptons_Zexc2jet;
        TH1D *dEtaLeptons_Zexc3jet;
        TH1D *dEtaLeptons_Zexc4jet;
        TH1D *dEtaLeptons_Zexc5jet;
        TH1D *dEtaLeptons_Zinc0jet;
        TH1D *dEtaLeptons_Zinc1jet;
        TH1D *dEtaLeptons_Zinc2jet;
        TH1D *dEtaLeptons_Zinc3jet;
        TH1D *dEtaLeptons_Zinc4jet;
        TH1D *dEtaLeptons_Zinc5jet;
        TH1D *dRLeptons_Zinc0jet;
        TH1D *dRLeptons_Zinc1jet;
        TH1D *dRLeptons_Zinc2jet;
        TH1D *dRLeptons_Zinc3jet;
        TH1D *dRLeptons_Zinc4jet;
        TH1D *dRLeptons_Zinc5jet;
        TH1D *SpTLeptons_Zexc0jet;
        TH1D *SpTLeptons_Zexc1jet;
        TH1D *SpTLeptons_Zexc2jet;
        TH1D *SpTLeptons_Zexc3jet;
        TH1D *SpTLeptons_Zexc4jet;
        TH1D *SpTLeptons_Zexc5jet;
        TH1D *genSpTLeptons_Zexc2jet;
        TH1D *SpTLeptons_Zinc0jet;
        TH1D *SpTLeptons_Zinc1jet;
        TH1D *SpTLeptons_Zinc2jet;
        TH1D *SpTLeptons_Zinc3jet;
        TH1D *SpTLeptons_Zinc4jet;
        TH1D *SpTLeptons_Zinc5jet;
        TH1D *genSpTLeptons_Zinc2jet;

        TH1D *JetsHT_Zinc1jet;
        TH1D *JetsHT_1_Zinc1jet;
        TH1D *JetsHT_2_Zinc1jet;
        TH1D *JetsHT_3_Zinc1jet;
        TH1D *JetsHT_4_Zinc1jet;

        TH1D *JetsHT_Zinc2jet;
        TH1D *JetsHT_1_Zinc2jet;
        TH1D *JetsHT_2_Zinc2jet;
        TH1D *JetsHT_3_Zinc2jet;
        TH1D *JetsHT_4_Zinc2jet;

        TH1D *JetsHT_Zinc3jet;
        TH1D *JetsHT_1_Zinc3jet;
        TH1D *JetsHT_2_Zinc3jet;
        TH1D *JetsHT_3_Zinc3jet;
        TH1D *JetsHT_4_Zinc3jet;

        TH1D *JetsHT_Zinc4jet;
        TH1D *JetsHT_Zinc5jet;
        TH1D *JetsHT_Zinc6jet;

        TH1D *genJetsHT_Zinc1jet;
        TH1D *genJetsHT_1_Zinc1jet;
        TH1D *genJetsHT_2_Zinc1jet;
        TH1D *genJetsHT_3_Zinc1jet;
        TH1D *genJetsHT_4_Zinc1jet;

        TH1D *genJetsHT_Zinc2jet;
        TH1D *genJetsHT_1_Zinc2jet;
        TH1D *genJetsHT_2_Zinc2jet;
        TH1D *genJetsHT_3_Zinc2jet;
        TH1D *genJetsHT_4_Zinc2jet;

        TH1D *genJetsHT_Zinc3jet;
        TH1D *genJetsHT_1_Zinc3jet;
        TH1D *genJetsHT_2_Zinc3jet;
        TH1D *genJetsHT_3_Zinc3jet;
        TH1D *genJetsHT_4_Zinc3jet;

        TH1D *genJetsHT_Zinc4jet;
        TH1D *genJetsHT_Zinc5jet;
        TH1D *genJetsHT_Zinc6jet;

        TH1D *FirstJetPt_Zinc1jet;
        TH1D *FirstJetPt_1_Zinc1jet;
        TH1D *FirstJetPt_2_Zinc1jet;
        TH1D *FirstJetPt_3_Zinc1jet;
        TH1D *FirstJetPt_4_Zinc1jet;

        TH1D *SecondJetPt_Zinc2jet;
        TH1D *SecondJetPt_1_Zinc2jet;
        TH1D *SecondJetPt_2_Zinc2jet;
        TH1D *SecondJetPt_3_Zinc2jet;
        TH1D *SecondJetPt_4_Zinc2jet;

        TH1D *ThirdJetPt_Zinc3jet;
        TH1D *ThirdJetPt_1_Zinc3jet;
        TH1D *ThirdJetPt_2_Zinc3jet;
        TH1D *ThirdJetPt_3_Zinc3jet;
        TH1D *ThirdJetPt_4_Zinc3jet;

        TH1D *FourthJetPt_Zinc4jet;
        TH1D *FifthJetPt_Zinc5jet;
        TH1D *SixthJetPt_Zinc6jet;
        TH1D *RatioJetPt21_Zinc2jet;
        TH1D *RatioJetPt32_Zinc3jet;

        TH1D *genFirstJetPt_Zinc1jet;
        TH1D *genFirstJetPt_1_Zinc1jet;
        TH1D *genFirstJetPt_2_Zinc1jet;
        TH1D *genFirstJetPt_3_Zinc1jet;
        TH1D *genFirstJetPt_4_Zinc1jet;

        TH1D *genSecondJetPt_Zinc2jet;
        TH1D *genSecondJetPt_1_Zinc2jet;
        TH1D *genSecondJetPt_2_Zinc2jet;
        TH1D *genSecondJetPt_3_Zinc2jet;
        TH1D *genSecondJetPt_4_Zinc2jet;

        TH1D *genThirdJetPt_Zinc3jet;
        TH1D *genThirdJetPt_1_Zinc3jet;
        TH1D *genThirdJetPt_2_Zinc3jet;
        TH1D *genThirdJetPt_3_Zinc3jet;
        TH1D *genThirdJetPt_4_Zinc3jet;

        TH1D *genFourthJetPt_Zinc4jet;
        TH1D *genFifthJetPt_Zinc5jet;
        TH1D *genSixthJetPt_Zinc6jet;
        TH1D *genRatioJetPt21_Zinc2jet;
        TH1D *genRatioJetPt32_Zinc3jet;
        TH1D *FirstJetPt_Zinc1jet_test;
        TH1D *SecondJetPt_Zinc2jet_test;
        TH1D *ThirdJetPt_Zinc3jet_test;
        TH1D *FourthJetPt_Zinc4jet_test;
        TH1D *FifthJetPt_Zinc5jet_test;
        TH1D *SixthJetPt_Zinc6jet_test;
        TH1D *genFirstJetPt_Zinc1jet_test;
        TH1D *genSecondJetPt_Zinc2jet_test;
        TH1D *genThirdJetPt_Zinc3jet_test;
        TH1D *genFourthJetPt_Zinc4jet_test;
        TH1D *genFifthJetPt_Zinc5jet_test;
        TH1D *genSixthJetPt_Zinc6jet_test;
        TH1D *genRatioJetPt21_Zinc2jet_test;
        TH1D *genRatioJetPt32_Zinc3jet_test;
        TH1D *FirstJetPt_Zexc1jet;
        TH1D *SecondJetPt_Zexc2jet;
        TH1D *genFirstJetPt_Zexc1jet;
        TH1D *genSecondJetPt_Zexc2jet;
        TH1D *FirstHighestJetPt_Zinc1jet;
        TH1D *FirstHighestJetPt_Zinc2jet;
        TH1D *FirstHighestJetPt_Zinc3jet;
        TH1D *FirstHighestJetPt_Zinc4jet;
        TH1D *FirstHighestJetPt_Zinc5jet;
        TH1D *FirstHighestJetPt_Zinc6jet;
        TH1D *genFirstHighestJetPt_Zinc1jet;
        TH1D *genFirstHighestJetPt_Zinc2jet;
        TH1D *genFirstHighestJetPt_Zinc3jet;
        TH1D *genFirstHighestJetPt_Zinc4jet;
        TH1D *genFirstHighestJetPt_Zinc5jet;
        TH1D *genFirstHighestJetPt_Zinc6jet;
        TH1D *FirstHighestJetPt_Zinc1jet_test;
        TH1D *FirstHighestJetPt_Zinc2jet_test;
        TH1D *FirstHighestJetPt_Zinc3jet_test;
        TH1D *FirstHighestJetPt_Zinc4jet_test;
        TH1D *FirstHighestJetPt_Zinc5jet_test;
        TH1D *FirstHighestJetPt_Zinc6jet_test;
        TH1D *genFirstHighestJetPt_Zinc1jet_test;
        TH1D *genFirstHighestJetPt_Zinc2jet_test;
        TH1D *genFirstHighestJetPt_Zinc3jet_test;
        TH1D *genFirstHighestJetPt_Zinc4jet_test;
        TH1D *genFirstHighestJetPt_Zinc5jet_test;
        TH1D *genFirstHighestJetPt_Zinc6jet_test;
        TH1D *SecondHighestJetPt_Zinc2jet;
        TH1D *SecondHighestJetPt_Zinc3jet;
        TH1D *SecondHighestJetPt_Zinc4jet;
        TH1D *SecondHighestJetPt_Zinc5jet;
        TH1D *SecondHighestJetPt_Zinc6jet;
        TH1D *genSecondHighestJetPt_Zinc2jet;
        TH1D *genSecondHighestJetPt_Zinc3jet;
        TH1D *genSecondHighestJetPt_Zinc4jet;
        TH1D *genSecondHighestJetPt_Zinc5jet;
        TH1D *genSecondHighestJetPt_Zinc6jet;
        TH1D *SecondHighestJetPt_Zinc2jet_test;
        TH1D *SecondHighestJetPt_Zinc3jet_test;
        TH1D *SecondHighestJetPt_Zinc4jet_test;
        TH1D *SecondHighestJetPt_Zinc5jet_test;
        TH1D *SecondHighestJetPt_Zinc6jet_test;
        TH1D *genSecondHighestJetPt_Zinc2jet_test;
        TH1D *genSecondHighestJetPt_Zinc3jet_test;
        TH1D *genSecondHighestJetPt_Zinc4jet_test;
        TH1D *genSecondHighestJetPt_Zinc5jet_test;
        TH1D *genSecondHighestJetPt_Zinc6jet_test;
        TH1D *ThirdHighestJetPt_Zinc3jet;
        TH1D *ThirdHighestJetPt_Zinc4jet;
        TH1D *ThirdHighestJetPt_Zinc5jet;
        TH1D *ThirdHighestJetPt_Zinc6jet;
        TH1D *genThirdHighestJetPt_Zinc3jet;
        TH1D *genThirdHighestJetPt_Zinc4jet;
        TH1D *genThirdHighestJetPt_Zinc5jet;
        TH1D *genThirdHighestJetPt_Zinc6jet;
        TH1D *ThirdHighestJetPt_Zinc3jet_test;
        TH1D *ThirdHighestJetPt_Zinc4jet_test;
        TH1D *ThirdHighestJetPt_Zinc5jet_test;
        TH1D *ThirdHighestJetPt_Zinc6jet_test;
        TH1D *genThirdHighestJetPt_Zinc3jet_test;
        TH1D *genThirdHighestJetPt_Zinc4jet_test;
        TH1D *genThirdHighestJetPt_Zinc5jet_test;
        TH1D *genThirdHighestJetPt_Zinc6jet_test;
        TH1D *AllJetPt_Zinc1jet;
        TH1D *AllJetPt_Zinc2jet;
        TH1D *AllJetPt_Zinc3jet;
        TH1D *AllJetPt_Zinc4jet;
        TH2D *hPtEtaBackJet_Zexc1jet;
        TH2D *hPtEtaBackJetMVA_Zexc1jet;
        TH2D *FirstJetPtEta_Zinc1jet;
        TH2D *SecondJetPtEta_Zinc2jet;
        TH2D *ThirdJetPtEta_Zinc3jet;
        TH2D *FourthJetPtEta_Zinc4jet;
        TH2D *FifthJetPtEta_Zinc5jet;
        TH2D *SixthJetPtEta_Zinc6jet;
        TH2D *genFirstJetPtEta_Zinc1jet;
        TH2D *genSecondJetPtEta_Zinc2jet;
        TH2D *genThirdJetPtEta_Zinc3jet;
        TH2D *genFourthJetPtEta_Zinc4jet;
        TH2D *genFifthJetPtEta_Zinc5jet;
        TH2D *genSixthJetPtEta_Zinc6jet;
        TH1D *ZNGoodJets_Zexc;
        TH2D *ZNGoodJetsNVtx_Zexc;
        TH1D *ZNGoodJets_Zexc_test;
        TH1D *ZNGoodJets_Zinc_test;
        TH1D *ZNGoodJets_Zinc;
        TH1D *ZNGoodJets_Zexc_check;
        TH1D *ZNGoodJets_Zexc_NoWeight;
        TH1D *ZNGoodJets_Zinc_NoWeight;

        //******** additional plots for WJets ********//
        //Jets Rapidity
        TH1D *FirstJetRapidity_Zinc1jet;
        TH1D *SecondJetRapidity_Zinc2jet;
        TH1D *ThirdJetRapidity_Zinc3jet;
        TH1D *FourthJetRapidity_Zinc4jet;
        TH1D *FirstJetRapidityFull_Zinc1jet;
        TH1D *SecondJetRapidityFull_Zinc2jet;
        TH1D *ThirdJetRapidityFull_Zinc3jet;
        TH1D *FourthJetRapidityFull_Zinc4jet;
        TH1D *genFirstJetRapidity_Zinc1jet;
        TH1D *genSecondJetRapidity_Zinc2jet;
        TH1D *genThirdJetRapidity_Zinc3jet;
        TH1D *genFourthJetRapidity_Zinc4jet;
        TH1D *genFirstJetRapidityFull_Zinc1jet;
        TH1D *genSecondJetRapidityFull_Zinc2jet;
        TH1D *genThirdJetRapidityFull_Zinc3jet;
        TH1D *genFourthJetRapidityFull_Zinc4jet;
        RooUnfoldResponse *responseFirstJetRapidity_Zinc1jet;
        RooUnfoldResponse *responseSecondJetRapidity_Zinc2jet;
        RooUnfoldResponse *responseThirdJetRapidity_Zinc3jet;
        RooUnfoldResponse *responseFourthJetRapidity_Zinc4jet;
        RooUnfoldResponse *responseFirstJetRapidityFull_Zinc1jet;
        RooUnfoldResponse *responseSecondJetRapidityFull_Zinc2jet;
        RooUnfoldResponse *responseThirdJetRapidityFull_Zinc3jet;
        RooUnfoldResponse *responseFourthJetRapidityFull_Zinc4jet;
        // Jets Mass
        TH1D *FirstJetmass_Zinc1jet;
        TH1D *SecondJetmass_Zinc2jet;
        TH1D *ThirdJetmass_Zinc3jet;
        TH1D *FourthJetmass_Zinc4jet;
        TH1D *FirstJetmass_1_Zinc1jet;
        TH1D *SecondJetmass_1_Zinc2jet;
        TH1D *ThirdJetmass_1_Zinc3jet;
        TH1D *FourthJetmass_1_Zinc4jet;
        // dijet Rapidity
        TH1D *dRapidityJets_Zinc2jet;
        TH1D *dRapidityJets_Zinc3jet;
        TH1D *dRapidityJets_Zinc4jet;
        TH1D *gendRapidityJets_Zinc2jet;
        TH1D *gendRapidityJets_Zinc3jet;
        TH1D *gendRapidityJets_Zinc4jet;
        RooUnfoldResponse *responsedRapidityJets_Zinc2jet;
        RooUnfoldResponse *responsedRapidityJets_Zinc3jet;
        RooUnfoldResponse *responsedRapidityJets_Zinc4jet;
        // dRapidity
        TH1D *dRapidityJets_First_Third_Zinc3jet;
        TH1D *dRapidityJets_Second_Third_Zinc3jet;
        TH1D *gendRapidityJets_First_Third_Zinc3jet;
        TH1D *gendRapidityJets_Second_Third_Zinc3jet;
        RooUnfoldResponse *responsedRapidityJets_First_Third_Zinc3jet;
        RooUnfoldResponse *responsedRapidityJets_Second_Third_Zinc3jet;
        TH1D *dRapidityJetsFB_Zinc2jet;
        TH1D *dRapidityJetsFB_Zinc3jet;
        TH1D *dRapidityJetsFB_Zinc4jet;
        TH1D *gendRapidityJetsFB_Zinc2jet;
        TH1D *gendRapidityJetsFB_Zinc3jet;
        TH1D *gendRapidityJetsFB_Zinc4jet;
        RooUnfoldResponse *responsedRapidityJetsFB_Zinc2jet;
        RooUnfoldResponse *responsedRapidityJetsFB_Zinc3jet;
        RooUnfoldResponse *responsedRapidityJetsFB_Zinc4jet;
        // dijet mass
        TH1D *diJetMass_Zinc2jet;
        TH1D *diJetMass_Zinc3jet;
        TH1D *diJetMass_Zinc4jet;
        TH1D *gendiJetMass_Zinc2jet;
        TH1D *gendiJetMass_Zinc3jet;
        TH1D *gendiJetMass_Zinc4jet;
        RooUnfoldResponse *responsediJetMass_Zinc2jet;
        RooUnfoldResponse *responsediJetMass_Zinc3jet;
        RooUnfoldResponse *responsediJetMass_Zinc4jet;
        // dPhi dR diJetPt
        TH1D *dPhiJetsFB_Zinc2jet;
        TH1D *dRJets_Zinc2jet;
        TH1D *diJetPt_Zinc2jet;
        TH1D *diJetPt_Zinc3jet;
        TH1D *diJetPt_Zinc4jet;
        TH1D *gendPhiJetsFB_Zinc2jet;
        TH1D *gendRJets_Zinc2jet;
        TH1D *gendiJetPt_Zinc2jet;
        TH1D *gendiJetPt_Zinc3jet;
        TH1D *gendiJetPt_Zinc4jet;
        RooUnfoldResponse *responsedPhiJetsFB_Zinc2jet;
        RooUnfoldResponse *responsedRJets_Zinc2jet;
        RooUnfoldResponse *responsediJetPt_Zinc2jet;
        RooUnfoldResponse *responsediJetPt_Zinc3jet;
        RooUnfoldResponse *responsediJetPt_Zinc4jet;
        // mean number of jets
        TH2D *MeanNJetsHT_Zinc1jet;
        TH2D *MeanNJetsHT_Zinc2jet;
        TH2D *MeanNJetsdRapidity_Zinc2jet;
        TH2D *MeanNJetsdRapidityFB_Zinc2jet;
        TH2D *genMeanNJetsHT_Zinc1jet;
        TH2D *genMeanNJetsHT_Zinc2jet;
        TH2D *genMeanNJetsdRapidity_Zinc2jet;
        TH2D *genMeanNJetsdRapidityFB_Zinc2jet;
        RooUnfoldResponse *responseMeanNJetsHT_Zinc1jet;
        RooUnfoldResponse *responseMeanNJetsHT_Zinc2jet;
        RooUnfoldResponse *responseMeanNJetsdRapidity_Zinc2jet;
        RooUnfoldResponse *responseMeanNJetsdRapidityFB_Zinc2jet;
        //******** end additional plots for WJets ********//

        TH1D *TwoJetsPtDiff_Zexc2jet;
        TH1D *genTwoJetsPtDiff_Zexc2jet;
        TH1D *JetsMass_Zexc2jet;
        TH1D *genJetsMass_Zexc2jet;
        TH1D *JetsMass_Zexc2jet_test;
        TH1D *genJetsMass_Zexc2jet_test;
        TH1D *ptBal_Zexc2jet;
        TH1D *genptBal_Zexc2jet;
        TH1D *dPhiJets_Zexc2jet;
        TH1D *gendPhiJets_Zexc2jet;
        TH1D *dEtaJets_Zexc2jet;
        TH1D *gendEtaJets_Zexc2jet;
        TH1D *dEtaFirstJetZ_Zexc2jet;
        TH1D *gendEtaFirstJetZ_Zexc2jet;
        TH1D *dEtaSecondJetZ_Zexc2jet;
        TH1D *gendEtaSecondJetZ_Zexc2jet;
        TH1D *dEtaJet1Plus2Z_Zexc2jet;
        TH1D *gendEtaJet1Plus2Z_Zexc2jet;
        TH1D *PHI_Zexc2jet;
        TH1D *genPHI_Zexc2jet;
        TH1D *PHI_T_Zexc2jet;
        TH1D *genPHI_T_Zexc2jet;
        TH1D *SpT_Zexc2jet;
        TH1D *genSpT_Zexc2jet;
        TH1D *SpTJets_Zexc2jet;
        TH1D *genSpTJets_Zexc2jet;
        TH1D *SPhi_Zexc2jet;
        TH1D *genSPhi_Zexc2jet;

        TH1D *TwoJetsPtDiff_Zinc2jet;
        TH1D *genTwoJetsPtDiff_Zinc2jet;
        TH1D *BestTwoJetsPtDiff_Zinc2jet;
        TH1D *genBestTwoJetsPtDiff_Zinc2jet;
        TH1D *JetsMass_Zinc2jet;
        TH1D *genJetsMass_Zinc2jet;
        TH1D *BestJetsMass_Zinc2jet;
        TH1D *genBestJetsMass_Zinc2jet;
        TH1D *JetsMass_Zinc2jet_test;
        TH1D *genJetsMass_Zinc2jet_test;
        TH1D *ptBal_Zinc2jet;
        TH1D *genptBal_Zinc2jet;
        TH1D *dPhiJets_Zinc2jet;
        TH1D *gendPhiJets_Zinc2jet;
        TH1D *BestdPhiJets_Zinc2jet;
        TH1D *genBestdPhiJets_Zinc2jet;
        TH1D *dEtaJets_Zinc2jet;
        TH1D *gendEtaJets_Zinc2jet;
        TH1D *dEtaFirstJetZ_Zinc2jet;
        TH1D *gendEtaFirstJetZ_Zinc2jet;
        TH1D *dEtaSecondJetZ_Zinc2jet;
        TH1D *gendEtaSecondJetZ_Zinc2jet;
        TH1D *dEtaJet1Plus2Z_Zinc2jet;
        TH1D *gendEtaJet1Plus2Z_Zinc2jet;
        TH1D *PHI_Zinc2jet;
        TH1D *genPHI_Zinc2jet;
        TH1D *BestPHI_Zinc2jet;
        TH1D *genBestPHI_Zinc2jet;
        TH1D *PHI_T_Zinc2jet;
        TH1D *genPHI_T_Zinc2jet;
        TH1D *BestPHI_T_Zinc2jet;
        TH1D *genBestPHI_T_Zinc2jet;
        TH1D *SpT_Zinc2jet;
        TH1D *genSpT_Zinc2jet;
        TH1D *BestSpT_Zinc2jet;
        TH1D *genBestSpT_Zinc2jet;
        TH1D *SpTJets_Zinc2jet;
        TH1D *genSpTJets_Zinc2jet;
        TH1D *BestSpTJets_Zinc2jet;
        TH1D *genBestSpTJets_Zinc2jet;
        TH1D *SPhi_Zinc2jet;
        TH1D *genSPhi_Zinc2jet;
        TH1D *BestSPhi_Zinc2jet;
        TH1D *genBestSPhi_Zinc2jet;

        //-- low Z pT;
        TH1D *TwoJetsPtDiff_LowPt_Zexc2jet;
        TH1D *genTwoJetsPtDiff_LowPt_Zexc2jet;
        TH1D *JetsMass_LowPt_Zexc2jet;
        TH1D *genJetsMass_LowPt_Zexc2jet;
        TH1D *ptBal_LowPt_Zexc2jet;
        TH1D *genptBal_LowPt_Zexc2jet;
        TH1D *dPhiJets_LowPt_Zexc2jet;
        TH1D *gendPhiJets_LowPt_Zexc2jet;
        TH1D *dPhiLeptons_LowPt_Zexc2jet;
        TH1D *gendPhiLeptons_LowPt_Zexc2jet;
        TH1D *PHI_LowPt_Zexc2jet;
        TH1D *genPHI_LowPt_Zexc2jet;
        TH1D *PHI_T_LowPt_Zexc2jet;
        TH1D *genPHI_T_LowPt_Zexc2jet;
        TH1D *SpT_LowPt_Zexc2jet;
        TH1D *genSpT_LowPt_Zexc2jet;
        TH1D *SpTJets_LowPt_Zexc2jet;
        TH1D *genSpTJets_LowPt_Zexc2jet;
        TH1D *SpTLeptons_LowPt_Zexc2jet;
        TH1D *genSpTLeptons_LowPt_Zexc2jet;
        TH1D *SPhi_LowPt_Zexc2jet;
        TH1D *genSPhi_LowPt_Zexc2jet;

        TH1D *TwoJetsPtDiff_LowPt_Zinc2jet;
        TH1D *genTwoJetsPtDiff_LowPt_Zinc2jet;
        TH1D *BestTwoJetsPtDiff_LowPt_Zinc2jet;
        TH1D *genBestTwoJetsPtDiff_LowPt_Zinc2jet;

        TH1D *JetsMass_LowPt_Zinc2jet;
        TH1D *genJetsMass_LowPt_Zinc2jet;
        TH1D *BestJetsMass_LowPt_Zinc2jet;
        TH1D *genBestJetsMass_LowPt_Zinc2jet;
        TH1D *ptBal_LowPt_Zinc2jet;
        TH1D *genptBal_LowPt_Zinc2jet;
        TH1D *dPhiJets_LowPt_Zinc2jet;
        TH1D *gendPhiJets_LowPt_Zinc2jet;
        TH1D *BestdPhiJets_LowPt_Zinc2jet;
        TH1D *genBestdPhiJets_LowPt_Zinc2jet;
        TH1D *dPhiLeptons_LowPt_Zinc2jet;
        TH1D *gendPhiLeptons_LowPt_Zinc2jet;
        TH1D *PHI_LowPt_Zinc2jet;
        TH1D *genPHI_LowPt_Zinc2jet;
        TH1D *BestPHI_LowPt_Zinc2jet;
        TH1D *genBestPHI_LowPt_Zinc2jet;
        TH1D *PHI_T_LowPt_Zinc2jet;
        TH1D *genPHI_T_LowPt_Zinc2jet;
        TH1D *BestPHI_T_LowPt_Zinc2jet;
        TH1D *genBestPHI_T_LowPt_Zinc2jet;
        TH1D *SpT_LowPt_Zinc2jet;
        TH1D *genSpT_LowPt_Zinc2jet;
        TH1D *BestSpT_LowPt_Zinc2jet;
        TH1D *genBestSpT_LowPt_Zinc2jet;
        TH1D *SpTJets_LowPt_Zinc2jet;
        TH1D *genSpTJets_LowPt_Zinc2jet;
        TH1D *BestSpTJets_LowPt_Zinc2jet;
        TH1D *genBestSpTJets_LowPt_Zinc2jet;
        TH1D *SpTLeptons_LowPt_Zinc2jet;
        TH1D *genSpTLeptons_LowPt_Zinc2jet;
        TH1D *SPhi_LowPt_Zinc2jet;
        TH1D *genSPhi_LowPt_Zinc2jet;
        TH1D *BestSPhi_LowPt_Zinc2jet;
        TH1D *genBestSPhi_LowPt_Zinc2jet;

        //-- low Z pT and low SpT;
        TH1D *PHI_LowSpT_LowPt_Zexc2jet;
        TH1D *genPHI_LowSpT_LowPt_Zexc2jet;
        TH1D *SPhi_LowSpT_LowPt_Zexc2jet;
        TH1D *genSPhi_LowSpT_LowPt_Zexc2jet;

        TH1D *PHI_LowSpT_LowPt_Zinc2jet;
        TH1D *genPHI_LowSpT_LowPt_Zinc2jet;
        TH1D *SPhi_LowSpT_LowPt_Zinc2jet;
        TH1D *genSPhi_LowSpT_LowPt_Zinc2jet;

        //-- low Z pT and high SpT;
        TH1D *PHI_HighSpT_LowPt_Zexc2jet;
        TH1D *genPHI_HighSpT_LowPt_Zexc2jet;
        TH1D *SPhi_HighSpT_LowPt_Zexc2jet;
        TH1D *genSPhi_HighSpT_LowPt_Zexc2jet;

        TH1D *PHI_HighSpT_LowPt_Zinc2jet;
        TH1D *genPHI_HighSpT_LowPt_Zinc2jet;
        TH1D *SPhi_HighSpT_LowPt_Zinc2jet;
        TH1D *genSPhi_HighSpT_LowPt_Zinc2jet;

        //-- low Z pT and low SPhi;
        TH1D *SpT_LowSPhi_LowPt_Zexc2jet;
        TH1D *genSpT_LowSPhi_LowPt_Zexc2jet;

        TH1D *SpT_LowSPhi_LowPt_Zinc2jet;
        TH1D *genSpT_LowSPhi_LowPt_Zinc2jet;

        //-- low Z pT and high SPhi;
        TH1D *SpT_HighSPhi_LowPt_Zexc2jet;
        TH1D *genSpT_HighSPhi_LowPt_Zexc2jet;
        ;
        TH1D *SpT_HighSPhi_LowPt_Zinc2jet;
        TH1D *genSpT_HighSPhi_LowPt_Zinc2jet;

        //-- high Z pT;
        TH1D *ptBal_HighPt_Zexc2jet;
        TH1D *genptBal_HighPt_Zexc2jet;
        TH1D *dPhiJets_HighPt_Zexc2jet;
        TH1D *gendPhiJets_HighPt_Zexc2jet;
        TH1D *dPhiLeptons_HighPt_Zexc2jet;
        TH1D *gendPhiLeptons_HighPt_Zexc2jet;
        TH1D *PHI_HighPt_Zexc2jet;
        TH1D *genPHI_HighPt_Zexc2jet;
        TH1D *PHI_T_HighPt_Zexc2jet;
        TH1D *genPHI_T_HighPt_Zexc2jet;
        TH1D *SpT_HighPt_Zexc2jet;
        TH1D *genSpT_HighPt_Zexc2jet;
        TH1D *SpTJets_HighPt_Zexc2jet;
        TH1D *genSpTJets_HighPt_Zexc2jet;
        TH1D *SpTLeptons_HighPt_Zexc2jet;
        TH1D *genSpTLeptons_HighPt_Zexc2jet;
        TH1D *SPhi_HighPt_Zexc2jet;
        TH1D *genSPhi_HighPt_Zexc2jet;

        TH1D *ptBal_HighPt_Zinc2jet;
        TH1D *genptBal_HighPt_Zinc2jet;
        TH1D *dPhiJets_HighPt_Zinc2jet;
        TH1D *gendPhiJets_HighPt_Zinc2jet;
        TH1D *dPhiLeptons_HighPt_Zinc2jet;
        TH1D *gendPhiLeptons_HighPt_Zinc2jet;
        TH1D *PHI_HighPt_Zinc2jet;
        TH1D *genPHI_HighPt_Zinc2jet;
        TH1D *PHI_T_HighPt_Zinc2jet;
        TH1D *genPHI_T_HighPt_Zinc2jet;
        TH1D *SpT_HighPt_Zinc2jet;
        TH1D *genSpT_HighPt_Zinc2jet;
        TH1D *SpTJets_HighPt_Zinc2jet;
        TH1D *genSpTJets_HighPt_Zinc2jet;
        TH1D *SpTLeptons_HighPt_Zinc2jet;
        TH1D *genSpTLeptons_HighPt_Zinc2jet;
        TH1D *SPhi_HighPt_Zinc2jet;
        TH1D *genSPhi_HighPt_Zinc2jet;

        //-- high Z pT and low SpT
        TH1D *PHI_LowSpT_HighPt_Zexc2jet;
        TH1D *SPhi_LowSpT_HighPt_Zexc2jet;

        TH1D *PHI_LowSpT_HighPt_Zinc2jet;
        TH1D *SPhi_LowSpT_HighPt_Zinc2jet;

        //-- high Z pT and high SpT
        TH1D *PHI_HighSpT_HighPt_Zexc2jet;
        TH1D *SPhi_HighSpT_HighPt_Zexc2jet;

        TH1D *PHI_HighSpT_HighPt_Zinc2jet;
        TH1D *SPhi_HighSpT_HighPt_Zinc2jet;

        //-- high Z pT and low SPhi
        TH1D *SpT_LowSPhi_HighPt_Zexc2jet;
        TH1D *SpT_LowSPhi_HighPt_Zinc2jet;

        //-- high Z pT and high SPhi
        TH1D *SpT_HighSPhi_HighPt_Zexc2jet;
        TH1D *SpT_HighSPhi_HighPt_Zinc2jet;

        //-- low SPhi
        TH1D *SpT_LowSPhi_Zexc2jet;
        TH1D *SpT_LowSPhi_Zinc2jet;

        //-- high SPhi
        TH1D *SpT_HighSPhi_Zexc2jet;
        TH1D *SpT_HighSPhi_Zinc2jet;

        //-- low SpT
        TH1D *PHI_LowSpT_Zexc2jet;
        TH1D *SPhi_LowSpT_Zexc2jet;

        TH1D *PHI_LowSpT_Zinc2jet;
        TH1D *SPhi_LowSpT_Zinc2jet;

        //-- high SpT
        TH1D *PHI_HighSpT_Zexc2jet; 
        TH1D *SPhi_HighSpT_Zexc2jet;

        TH1D *PHI_HighSpT_Zinc2jet; 
        TH1D *SPhi_HighSpT_Zinc2jet;

        //-- gen stuff
        TH1D *gendPhiJetsDeltaR_Zexc2jet;
        TH1D *resdPhiJetsDeltaR_Zexc2jet;
        TH1D *genPHI_TDeltaR_Zexc2jet;
        TH1D *resPHI_TDeltaR_Zexc2jet;
        TH1D *genSpTJetsDeltaR_Zexc2jet;
        TH1D *resSpTJetsDeltaR_Zexc2jet;
        TH1D *genSpTDeltaR_Zexc2jet;
        TH1D *resSpTDeltaR_Zexc2jet;

        TH1D *gendPhiJetsDPS_Zexc2jet;
        TH1D *gendPhiJetsDPSDeltaR_Zexc2jet;
        TH1D *genPHI_TDPS_Zexc2jet;
        TH1D *genPHI_TDPSDeltaR_Zexc2jet;
        TH1D *genSpTJetsDPS_Zexc2jet;
        TH1D *genSpTJetsDPSDeltaR_Zexc2jet;
        TH1D *genSpTDPS_Zexc2jet;
        TH1D *genSpTDPSDeltaR_Zexc2jet;
        TH1D *genSpTDPSPartons_Zexc2jet;
        TH1D *genZNGoodJets_Zinc_test;
        TH1D *genZNGoodJets_Zinc;
        TH1D *genZNGoodJets_Zexc_test;
        TH1D *genZNGoodJets_Zexc;
        TH2D *gendPhiJetsDPSDeltaR_ZpT_Zexc2jet;
        TH2D *partonX2D;

        TH1D *gendeltaRjetMu;

        /// additional information
        // Muoisolation

        TH1D *MuDetIsoRhoCorr;
        TH1D *MuPFIsoDBetaCorr;

        TH1D *deltaRjetMu;
        TH1D *deltaPtjetMu;
        TH1D *NVtx;
        TH1D *TruePU_0;
        TH1D *TruePU_1;
        TH1D *TruePU_2;
        TH1D *TruePU_3;
        TH1D *TruePU_4;
        TH1D *TruePU_5;
        TH1D *TruePU_6;
        TH1D *TruePU_7;

        TH1D *PU_0;
        TH1D *PU_1;
        TH1D *PU_2;
        TH1D *PU_3;
        TH1D *PU_4;
        TH1D *PU_5;
        TH1D *PU_6;
        TH1D *PU_7;

        TH1D *Beta;
        TH1D *BetaStar;
        TH2D *ZNGoodJetsBeta_Zexc;
        TH1D *puBeta_JetsMatchGenJets;
        TH1D *puBetaStar_JetsMatchGenJets;
        TH1D *puBeta_JetsNoMatchGenJets;
        TH1D *puBetaStar_JetsNoMatchGenJets;
        TH1D *puMVA;
        TH1D *puMVA_JetsMatchGenJets;
        TH1D *puMVA_JetsNoMatchGenJets;
        TH1D *jetsEta_JetsMatchGenJets;
        TH1D *jetsEta_JetsNoMatchGenJets;
        TH1D *FirstJetdEtaGenReco_Zinc1;
        TH1D *FourthJetdEtaGenReco_Zinc4; 
        TH2D *puMVAvsBeta;
        TH1D *PUWeight;
        TH1D *fullMET;
        TH1D *fullMET_pfMETPFlow;
        TH1D *fullMET_pfMet;
        TH1D *fullMET_pfType1CorrectedMet;
        TH1D *fullMET_pfType1p2CorrectedMet;
        TH1D *fullMT;
        TH2D *METvslepIso;
        TH2D *MTvslepIso;
        TH1D *PUWeight0;
        TH1D *PUWeight1;
        TH1D *MuPlusPt;
        TH1D *MuMinusPt;
        TH1D *MuPlusEta;
        TH1D *MuMinusEta;

        TH1D *MET_Zinc0jet;
        TH1D *MET_Zinc1jet;
        TH1D *MET_Zinc2jet;
        TH1D *MET_Zinc3jet;

        TH1D *METphi_Zinc0jet;
        TH1D *METphi_Zinc1jet;
        TH1D *METphi_Zinc2jet;
        TH1D *METphi_Zinc3jet;

        TH1D *MT_Zinc0jet;
        TH1D *MT_Zinc1jet;
        TH1D *MT_Zinc2jet;
        TH1D *MT_Zinc3jet;
        TH1D *ZNGoodJetsEWK_Zexc;
        TH1D *ZNGoodJetsEWKbtw_Zexc;
        TH1D *METEWK_Zinc2jet;      
        TH1D *METEWK_Zinc3jet;     

        TH1D *METphiEWK_Zinc2jet;   
        TH1D *METphiEWK_Zinc3jet;   

        TH1D *MTEWK_Zinc2jet;       
        TH1D *MTEWK_Zinc3jet;       
        TH1D *FirstJetPtEWK_Zinc2jet;    
        TH1D *SecondJetPtEWK_Zinc2jet;   

        TH1D *FirstJetEtaEWK_Zinc2jet;   
        TH1D *SecondJetEtaEWK_Zinc2jet;  
        TH1D *FirstJetPhiEWK_Zinc2jet;   
        TH1D *SecondJetPhiEWK_Zinc2jet;  

        TH1D *ForwardJetPtEWK_Zinc2jet;  
        TH1D *ForwardJetEtaEWK_Zinc2jet; 
        TH1D *ForwardJetPhiEWK_Zinc2jet; 

        TH1D *CentralJetPtEWK_Zinc2jet;  
        TH1D *CentralJetEtaEWK_Zinc2jet; 
        TH1D *CentralJetPhiEWK_Zinc2jet; 



        TH1D *ThirdJetPtEWK_Zinc2jet;   
        TH1D *ThirdJetPhiEWK_Zinc2jet;   
        TH1D *ThirdJetEtaEWK_Zinc2jet;   
        /// additional activity > 15 GeV
        TH1D *ThirdJetPtEWKadd_Zinc2jet; 
        TH1D *ThirdJetPhiEWKadd_Zinc2jet;
        TH1D *ThirdJetEtaEWKadd_Zinc2jet;
        TH1D *SumEtaJetsEWK_Zinc2jet;     
        TH1D *AbsSumEtaJetsEWK_Zinc2jet;  
        TH1D *SumEtaJetsEWK_Zinc3jet;     


        TH1D *dEtaJetsEWK_Zinc2jet;       

        TH1D *TwoJetsPtDiffEWK_Zinc2jet;  


        TH1D *ptBalEWK_Zinc2jet;          
        TH1D* SpTJetsEWK_Zinc2jet;        

        TH1D *dPhiJetsEWK_Zinc2jet;       


        TH1D *JetsHTEWK_Zinc2jet;         


        TH1D *JetsMassEWK_Zinc2jet;       


        //// third jet properties
        TH1D *EtaThirdJetsEWK_Zinc3jet;   

        /// all jets between leading two 
        TH1D *AllJetPtEWKbtw_Zinc2jet;    
        TH1D *AllJetPhiEWKbtw_Zinc2jet;  
        TH1D *AllJetEtaEWKbtw_Zinc2jet;   
        TH1D *JetsHTEWKbtw_Zinc2jet; 
        //TH1D *JetsHTEWKbtw_Zinc2jet    

        // third jet between
        TH1D *ThirdJetPtEWKbtw_Zinc2jet;
        TH1D *ThirdJetPhiEWKbtw_Zinc2jet;
        TH1D *ThirdJetEtaEWKbtw_Zinc2jet; 

        TH1D *genZNGoodJetsEWK_Zexc;
        TH1D *genZNGoodJetsEWKbtw_Zexc;
        TH1D *genFirstJetPtEWK_Zinc2jet;     
        TH1D *genSecondJetPtEWK_Zinc2jet;    

        TH1D *genFirstJetEtaEWK_Zinc2jet;  
        TH1D *genSecondJetEtaEWK_Zinc2jet;   
        TH1D *genFirstJetPhiEWK_Zinc2jet;    
        TH1D *genSecondJetPhiEWK_Zinc2jet;   

        TH1D *genForwardJetPtEWK_Zinc2jet;   
        TH1D *genForwardJetEtaEWK_Zinc2jet;  
        TH1D *genForwardJetPhiEWK_Zinc2jet;  

        TH1D *genCentralJetPtEWK_Zinc2jet;   
        TH1D *genCentralJetEtaEWK_Zinc2jet;  
        TH1D *genCentralJetPhiEWK_Zinc2jet; 





        TH1D *genThirdJetPtEWK_Zinc2jet;     
        TH1D *genThirdJetPhiEWK_Zinc2jet;    
        TH1D *genThirdJetEtaEWK_Zinc2jet;    
        /// additional activity > 15 GeV ful
        TH1D *genThirdJetPtEWKadd_Zinc2jet;  
        TH1D *genThirdJetPhiEWKadd_Zinc2jet; 
        TH1D *genThirdJetEtaEWKadd_Zinc2jet; 


        /////  dijet properties
        TH1D *genSumEtaJetsEWK_Zinc2jet;     
        TH1D *genAbsSumEtaJetsEWK_Zinc2jet;  
        TH1D *genSumEtaJetsEWK_Zinc3jet;     


        TH1D *gendEtaJetsEWK_Zinc2jet;       

        TH1D *genTwoJetsPtDiffEWK_Zinc2jet; 


        TH1D *genptBalEWK_Zinc2jet;          
        TH1D* genSpTJetsEWK_Zinc2jet;        

        TH1D *gendPhiJetsEWK_Zinc2jet;       


        TH1D *genJetsHTEWK_Zinc2jet;         


        TH1D *genJetsMassEWK_Zinc2jet;       


        //// third jet properties
        TH1D *genEtaThirdJetsEWK_Zinc3jet;   

        /// all jets between leading two jet
        TH1D *genAllJetPtEWKbtw_Zinc2jet;    
        TH1D *genAllJetPhiEWKbtw_Zinc2jet;   
        TH1D *genAllJetEtaEWKbtw_Zinc2jet;   


        TH1D *genJetsHTEWKbtw_Zinc2jet;      
        //TH1D *genJetsHTEWKbtw_Zinc2jet    

        // third jet between
        TH1D *genThirdJetPtEWKbtw_Zinc2jet;  
        TH1D *genThirdJetPhiEWKbtw_Zinc2jet; 
        TH1D *genThirdJetEtaEWKbtw_Zinc2jet; 

        TH1D *ZNGoodJetsEWKfwd_Zexc;
        // met properties
        TH1D *METEWKfwd_Zinc2jet;              
        TH1D *METEWKfwd_Zinc3jet;              

        TH1D *METphiEWKfwd_Zinc2jet;           
        TH1D *METphiEWKfwd_Zinc3jet;           

        TH1D *MTEWKfwd_Zinc2jet;               
        TH1D *MTEWKfwd_Zinc3jet;               

        // jet hisotgrams
        TH1D *FirstJetPtEWKfwd_Zinc2jet;       
        TH1D *SecondJetPtEWKfwd_Zinc2jet;      
        TH1D *FirstJetEtaEWKfwd_Zinc2jet;      
        TH1D *SecondJetEtaEWKfwd_Zinc2jet;    

        TH1D *FirstJetPhiEWKfwd_Zinc2jet;      
        TH1D *SecondJetPhiEWKfwd_Zinc2jet;     


        TH1D *SumEtaJetsEWKfwd_Zinc2jet;       
        TH1D *SumEtaJetsEWKfwd_Zinc3jet;       
        TH1D *genSumEtaJetsEWKfwd_Zinc2jet;    


        TH1D *dEtaJetsEWKfwd_Zinc2jet;         
        TH1D *gendEtaJetsEWKfwd_Zinc2jet;      

        TH1D *TwoJetsPtDiffEWKfwd_Zinc2jet;    
        TH1D *genTwoJetsPtDiffEWKfwd_Zinc2jet; 


        TH1D *ptBalEWKfwd_Zinc2jet;            
        TH1D* SpTJetsEWKfwd_Zinc2jet;          
        TH1D *genSpTJetsEWKfwd_Zinc2jet;       

        TH1D *dPhiJetsEWKfwd_Zinc2jet;         
        TH1D *gendPhiJetsEWKfwd_Zinc2jet;      


        TH1D *JetsHTEWKfwd_Zinc2jet;           
        TH1D *genJetsHTEWKfwd_Zinc2jet;       


        TH1D *JetsMassEWKfwd_Zinc2jet;         
        TH1D *genJetsMassEWKfwd_Zinc2jet;      

        TH1D *ZNGoodJetsEWKmjj_Zexc;

        TH1D *METEWKmjj_Zinc2jet;               
        TH1D *METEWKmjj_Zinc3jet;               
        TH1D *METphiEWKmjj_Zinc2jet;            
        ///TH1D *METphiEWKmjj_Zinc3jet         

        TH1D *MTEWKmjj_Zinc2jet;                
        //TH1D *MTEWKmjj_Zinc3jet              

        // jet hisotgrams
        TH1D *FirstJetPtEWKmjj_Zinc2jet;        
        TH1D *SecondJetPtEWKmjj_Zinc2jet;       
        TH1D *ThirdJetPtEWKmjj_Zinc3jet;        

        TH1D *FirstJetEtaEWKmjj_Zinc2jet;       
        TH1D *SecondJetEtaEWKmjj_Zinc2jet;      

        TH1D *FirstJetPhiEWKmjj_Zinc2jet;       
        TH1D *SecondJetPhiEWKmjj_Zinc2jet;      


        TH1D *SumEtaJetsEWKmjj_Zinc2jet;        
        TH1D *SumEtaJetsEWKmjj_Zinc3jet;        
        TH1D *genSumEtaJetsEWKmjj_Zinc2jet;     


        TH1D *dEtaJetsEWKmjj_Zinc2jet;          

        TH1D *gendEtaJetsEWKmjj_Zinc2jet;       

        TH1D *TwoJetsPtDiffEWKmjj_Zinc2jet;     
        TH1D *genTwoJetsPtDiffEWKmjj_Zinc2jet;  


        TH1D *ptBalEWKmjj_Zinc2jet;             
        TH1D* SpTJetsEWKmjj_Zinc2jet;          
        TH1D *genSpTJetsEWKmjj_Zinc2jet;        

        TH1D *dPhiJetsEWKmjj_Zinc2jet;          
        TH1D *gendPhiJetsEWKmjj_Zinc2jet;       


        TH1D *JetsHTEWKmjj_Zinc2jet;            
        TH1D *genJetsHTEWKmjj_Zinc2jet;         

        TH1D *JetsHTEWKmjjAdd_Zinc2jet;         

        TH1D *JetsMassEWKmjj_Zinc2jet;          
        TH1D *genJetsMassEWKmjj_Zinc2jet;       

        //// third jet properties
        TH1D *ThirdJetEtaEWKmjj_Zinc3jet;      
        TH1D *genThirdJetEtaEWKmjj_Zinc3jet;      

        //--- number of addtion genrated parton
        TH1D *partonsN;         
        TH1D *partonsNWeighted;  
        TH1D *partonsNAfterGenCut;        
        TH1D *partonsNAfterGenCutWeighted; 

        // -- Vector boson jet properties
        TH1D * dEtaBosonJet_Zexc1jet;
        TH1D * dEtaBosonJet_Zinc1jet;
        TH1D * gendEtaBosonJet_Zexc1jet;
        TH1D * gendEtaBosonJet_Zinc1jet;


        //--- RooUnfoldResponses ---
        RooUnfoldResponse *responseZNGoodJetsExc;              
        RooUnfoldResponse *responseZMass;                      
        RooUnfoldResponse *responseTwoJetsPtDiffExc;           
        RooUnfoldResponse *responseTwoJetsPtDiffInc;           
        RooUnfoldResponse *responseBestTwoJetsPtDiffInc;       
        RooUnfoldResponse *responseTwoJetsPtDiffLowPtExc;        
        RooUnfoldResponse *responseTwoJetsPtDiffLowPtInc;      
        RooUnfoldResponse *responseBestTwoJetsPtDiffLowPtInc;  
        RooUnfoldResponse *responseJetsMassExc;                
        RooUnfoldResponse *responseJetsMassInc;                
        RooUnfoldResponse *responseBestJetsMassInc;            
        RooUnfoldResponse *responseJetsMassLowPtExc;           
        RooUnfoldResponse *responseJetsMassLowPtInc;           
        RooUnfoldResponse *responseBestJetsMassLowPtInc;       
        RooUnfoldResponse *responseFirstJetPt;                 
        RooUnfoldResponse *responseFirstJetPt_1;                 
        RooUnfoldResponse *responseFirstJetPt_2;                 
        RooUnfoldResponse *responseFirstJetPt_3;                 
        RooUnfoldResponse *responseFirstJetPt_4;                 

        RooUnfoldResponse *responseSecondJetPt;                
        RooUnfoldResponse *responseSecondJetPt_1;                
        RooUnfoldResponse *responseSecondJetPt_2;                
        RooUnfoldResponse *responseSecondJetPt_3;                
        RooUnfoldResponse *responseSecondJetPt_4;                

        RooUnfoldResponse *responseThirdJetPt;                 
        RooUnfoldResponse *responseThirdJetPt_1;                 
        RooUnfoldResponse *responseThirdJetPt_2;                 
        RooUnfoldResponse *responseThirdJetPt_3;                 
        RooUnfoldResponse *responseThirdJetPt_4;                 

        RooUnfoldResponse *responseFirstJetEta;                
        RooUnfoldResponse *responseFirstJetPtEta;             
        RooUnfoldResponse *responseSecondJetEta;               
        RooUnfoldResponse *responseSecondJetPtEta;             
        RooUnfoldResponse *responseThirdJetEta;                
        RooUnfoldResponse *responseThirdJetPtEta;              
        RooUnfoldResponse *responseFourthJetPt;                
        RooUnfoldResponse *responseFourthJetEta;               
        RooUnfoldResponse *responseFourthJetPtEta;             
        RooUnfoldResponse *responseFifthJetPt;                 
        RooUnfoldResponse *responseFifthJetEta;                
        RooUnfoldResponse *responseFifthJetPtEta;              
        RooUnfoldResponse *responseSixthJetPt;                 
        RooUnfoldResponse *responseSixthJetEta;                
        RooUnfoldResponse *responseSixthJetPtEta;              

        RooUnfoldResponse *responseJetsHt1Jet;                 
        RooUnfoldResponse *responseJetsHt1Jet_1;                 
        RooUnfoldResponse *responseJetsHt1Jet_2;                 
        RooUnfoldResponse *responseJetsHt1Jet_3;                 
        RooUnfoldResponse *responseJetsHt1Jet_4;                 

        RooUnfoldResponse *responseJetsHt2Jet;                 
        RooUnfoldResponse *responseJetsHt2Jet_1;                 
        RooUnfoldResponse *responseJetsHt2Jet_2;                 
        RooUnfoldResponse *responseJetsHt2Jet_3;                 
        RooUnfoldResponse *responseJetsHt2Jet_4;                 

        RooUnfoldResponse *responseJetsHt3Jet;                 
        RooUnfoldResponse *responseJetsHt3Jet_1;                 
        RooUnfoldResponse *responseJetsHt3Jet_2;                 
        RooUnfoldResponse *responseJetsHt3Jet_3;                 
        RooUnfoldResponse *responseJetsHt3Jet_4;                 

        RooUnfoldResponse *responseJetsHt4Jet;                 
        RooUnfoldResponse *responseJetsHt5Jet;                 
        RooUnfoldResponse *responseJetsHt6Jet;                 
        RooUnfoldResponse *responseFirstHighestJetPt_Zinc1jet; 
        RooUnfoldResponse *responseFirstHighestJetPt_Zinc2jet; 
        RooUnfoldResponse *responseFirstHighestJetPt_Zinc3jet; 
        RooUnfoldResponse *responseFirstHighestJetPt_Zinc4jet; 
        RooUnfoldResponse *responseFirstHighestJetPt_Zinc5jet; 
        RooUnfoldResponse *responseFirstHighestJetPt_Zinc6jet; 
        RooUnfoldResponse *responseSecondHighestJetPt_Zinc2jet;
        RooUnfoldResponse *responseSecondHighestJetPt_Zinc3jet;
        RooUnfoldResponse *responseSecondHighestJetPt_Zinc4jet;
        RooUnfoldResponse *responseSecondHighestJetPt_Zinc5jet;
        RooUnfoldResponse *responseSecondHighestJetPt_Zinc6jet;
        RooUnfoldResponse *responseThirdHighestJetPt_Zinc3jet; 
        RooUnfoldResponse *responseThirdHighestJetPt_Zinc4jet; 
        RooUnfoldResponse *responseThirdHighestJetPt_Zinc5jet; 
        RooUnfoldResponse *responseThirdHighestJetPt_Zinc6jet; 
        RooUnfoldResponse *responseSpTJets_Zexc2jet;           
        RooUnfoldResponse *responseSpTJets_Zinc2jet;           
        RooUnfoldResponse *responseBestSpTJets_Zinc2jet;       
        RooUnfoldResponse *responseSpTJets_LowPt_Zexc2jet;     
        RooUnfoldResponse *responseSpTJets_LowPt_Zinc2jet;     
        RooUnfoldResponse *responseBestSpTJets_LowPt_Zinc2jet; 
        RooUnfoldResponse *responseSpT_Zexc2jet;               
        RooUnfoldResponse *responseSpT_Zinc2jet;               
        RooUnfoldResponse *responseBestSpT_Zinc2jet;           
        RooUnfoldResponse *responseSpT_LowPt_Zexc2jet;         
        RooUnfoldResponse *responseSpT_LowPt_Zinc2jet;         
        RooUnfoldResponse *responseBestSpT_LowPt_Zinc2jet;     
        RooUnfoldResponse *responsedPhiJets_Zexc2jet;          
        RooUnfoldResponse *responsedPhiJets_Zinc2jet;          
        RooUnfoldResponse *responseBestdPhiJets_Zinc2jet;      
        RooUnfoldResponse *responsedPhiJets_LowPt_Zexc2jet;    
        RooUnfoldResponse *responsedPhiJets_LowPt_Zinc2jet;    
        RooUnfoldResponse *responseBestdPhiJets_LowPt_Zinc2jet;
        RooUnfoldResponse *responsePHI_Zexc2jet;               
        RooUnfoldResponse *responsePHI_Zinc2jet;               
        RooUnfoldResponse *responseBestPHI_Zinc2jet;           
        RooUnfoldResponse *responsePHI_LowPt_Zexc2jet;         
        RooUnfoldResponse *responsePHI_LowPt_Zinc2jet;         
        RooUnfoldResponse *responseBestPHI_LowPt_Zinc2jet;     
        RooUnfoldResponse *responsePHI_T_Zexc2jet;             
        RooUnfoldResponse *responsePHI_T_Zinc2jet;             
        RooUnfoldResponse *responseBestPHI_T_Zinc2jet;         
        RooUnfoldResponse *responsePHI_T_LowPt_Zexc2jet;       
        RooUnfoldResponse *responsePHI_T_LowPt_Zinc2jet;       
        RooUnfoldResponse *responseBestPHI_T_LowPt_Zinc2jet;   
        RooUnfoldResponse *responseSPhi_Zexc2jet;              
        RooUnfoldResponse *responseSPhi_Zinc2jet;              
        RooUnfoldResponse *responsedEtaJets_Zexc2jet;          
        RooUnfoldResponse *responsedEtaJets_Zinc2jet;          
        RooUnfoldResponse *responseBestSPhi_Zinc2jet;          
        RooUnfoldResponse *responseSPhi_LowPt_Zexc2jet;        
        RooUnfoldResponse *responseSPhi_LowPt_Zinc2jet;        
        RooUnfoldResponse *responseBestSPhi_LowPt_Zinc2jet;    

        //  ratio plots
        RooUnfoldResponse *responseRatioJetPt21;               
        RooUnfoldResponse *responseRatioJetPt32;               

        // vector boson and single jet 
        RooUnfoldResponse *responsedEtaBosonJet_Zexc1;
        RooUnfoldResponse *responsedEtaBosonJet_Zinc1;

        // for 2D unfolding --- create 1D histograms for different rapidity ranges
        //int NbinsEta = 9 ;
        //double j_pT_range[9]={30.,50.,70.,100.,130.,170.,220.,350.,1000.};
        //double j_Y_range[9]={0.,0.5,1.0,1.5,2.0,2.5,3.0,3.2,4.7};
        TH1D *FirstJetPt_Zinc1jet_Eta[10];
        TH1D *genFirstJetPt_Zinc1jet_Eta[10];
        TH1D *SecondJetPt_Zinc2jet_Eta[10];
        TH1D *genSecondJetPt_Zinc2jet_Eta[10];

        RooUnfoldResponse *responseFirstJetPt_Zinc1jet_Eta[10];
        RooUnfoldResponse *responseSecondJetPt_Zinc2jet_Eta[10];



        ClassDef(HistoSet,0);
};

#endif
