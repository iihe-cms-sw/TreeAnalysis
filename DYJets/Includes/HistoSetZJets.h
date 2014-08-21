#ifndef _HistoSetZJets_h_
#define _HistoSetZJets_h_

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

class HistoSetZJets: public TObject{
    public:

        vector<TH1*> listOfHistograms;
        vector<RooUnfoldResponse*> listOfResponses;
        HistoSetZJets(string leptonFlavor = "DMu");
        ~HistoSetZJets();

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


        TH1D *ZMass_Zinc0jet;
        TH1D *genZMass_Zinc0jet;
        TH1D *ZPt_Zinc0jet;
        TH1D *ZPt_Zinc1jet;
        TH1D *ZPt_Zinc2jet;
        TH1D *genZPt_Zinc0jet;
        TH1D *genZPt_Zinc1jet;
        TH1D *genZPt_Zinc2jet;
        TH1D *ZPt_Zexc0jet;
        TH1D *ZPt_Zexc1jet;
        TH1D *ZPt_Zexc2jet;
        TH1D *ZRapidity_Zinc0jet;
        TH1D *ZRapidity_Zinc1jet;
        TH1D *ZRapidity_Zinc2jet;
        TH1D *genZRapidity_Zinc0jet;
        TH1D *genZRapidity_Zinc1jet;
        TH1D *genZRapidity_Zinc2jet;
        TH1D *ZRapidity_Zexc0jet;
        TH1D *ZRapidity_Zexc1jet;
        TH1D *ZRapidity_Zexc2jet;
        TH1D *ZEta_Zinc0jet;
        TH1D *ZEta_Zinc1jet;
        TH1D *ZEta_Zinc2jet;
        TH1D *genZEta_Zinc0jet;
        TH1D *genZEta_Zinc1jet;
        TH1D *genZEta_Zinc2jet;
        TH1D *ZEta_Zexc0jet;
        TH1D *ZEta_Zexc1jet;
        TH1D *ZEta_Zexc2jet;
        TH1D *lepEta_Zinc0jet;
        TH1D *genlepEta_Zinc0jet;
        TH1D *lepEta_Zexc0jet;
        TH1D *lepPhi_Zinc0jet;
        TH1D *lepPhi_Zexc0jet;
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
        TH1D *FirstJetPhi_Zinc1jet;
        TH1D *SecondJetPhi_Zinc2jet;
        TH1D *ThirdJetPhi_Zinc3jet;
        TH1D *FourthJetPhi_Zinc4jet;
        TH1D *FifthJetPhi_Zinc5jet;
        TH1D *SixthJetPhi_Zinc6jet;
        TH1D *FirstJetPhi_Zexc1jet;
        TH1D *SecondJetPhi_Zexc2jet;
        TH1D *lepPt_Zinc0jet;
        TH1D *genlepPt_Zinc0jet;
        TH1D *lepPt_Zexc0jet;
        TH1D *dPhiLeptons_Zexc0jet;
        TH1D *dPhiLeptons_Zinc0jet;
        TH1D *dEtaLeptons_Zexc0jet;
        TH1D *dEtaLeptons_Zinc0jet;
        TH1D *dRLeptons_Zinc0jet;
        TH1D *SpTLeptons_Zexc0jet;
        TH1D *SpTLeptons_Zexc1jet;
        TH1D *SpTLeptons_Zexc2jet;
        TH1D *genSpTLeptons_Zexc2jet;
        TH1D *SpTLeptons_Zinc0jet;
        TH1D *SpTLeptons_Zinc1jet;
        TH1D *SpTLeptons_Zinc2jet;
        TH1D *genSpTLeptons_Zinc2jet;

        TH1D *JetsHT_Zinc1jet;
        TH1D *JetsHT_Zinc2jet;
        TH1D *JetsHT_Zinc3jet;
        TH1D *JetsHT_Zinc4jet;
        TH1D *JetsHT_Zinc5jet;
        TH1D *JetsHT_Zinc6jet;

        TH1D *genJetsHT_Zinc1jet;
        TH1D *genJetsHT_Zinc2jet;
        TH1D *genJetsHT_Zinc3jet;
        TH1D *genJetsHT_Zinc4jet;
        TH1D *genJetsHT_Zinc5jet;
        TH1D *genJetsHT_Zinc6jet;

        TH1D *FirstJetPt_Zinc1jet;
        TH1D *SecondJetPt_Zinc2jet;
        TH1D *ThirdJetPt_Zinc3jet;
        TH1D *FourthJetPt_Zinc4jet;
        TH1D *FifthJetPt_Zinc5jet;
        TH1D *SixthJetPt_Zinc6jet;

        TH1D *genFirstJetPt_Zinc1jet;
        TH1D *genSecondJetPt_Zinc2jet;
        TH1D *genThirdJetPt_Zinc3jet;
        TH1D *genFourthJetPt_Zinc4jet;
        TH1D *genFifthJetPt_Zinc5jet;
        TH1D *genSixthJetPt_Zinc6jet;
        TH1D *FirstJetPt_Zexc1jet;
        TH1D *SecondJetPt_Zexc2jet;
        TH1D *genFirstJetPt_Zexc1jet;
        TH1D *genSecondJetPt_Zexc2jet;
        TH1D *ZNGoodJets_Zexc;
        TH2D *ZNGoodJetsNVtx_Zexc;
        TH1D *ZNGoodJets_Zinc;
        TH1D *ZNGoodJets_Zexc_NoWeight;
        TH1D *ZNGoodJets_Zinc_NoWeight;


        TH1D *TwoJetsPtDiff_Zexc2jet;
        TH1D *genTwoJetsPtDiff_Zexc2jet;
        TH1D *JetsMass_Zexc2jet;
        TH1D *genJetsMass_Zexc2jet;
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
        TH1D *genZNGoodJets_Zinc;
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
        TH1D *PUWeight0;
        TH1D *PUWeight1;

        //--- number of addtion genrated parton
        TH1D *partonsN;         
        TH1D *partonsNWeighted;  
        TH1D *partonsNAfterGenCut;        
        TH1D *partonsNAfterGenCutWeighted; 

        // -- Vector boson jet properties
        TH1D *dEtaBosonJet_Zexc1jet;
        TH1D *dEtaBosonJet_Zinc1jet;
        TH1D *gendEtaBosonJet_Zexc1jet;
        TH1D *gendEtaBosonJet_Zinc1jet;

        TH1D *trMass;
        TH1D *trE;
        TH1D *E;
        TH1D *eta;
        TH1D *rapidity;

        TH1D *tau_sum_Zinc1jet[5];
        TH1D *tau_max_Zinc1jet[5];
        TH1D *tau_c_sum_Zinc1jet[5];
        TH1D *tau_c_max_Zinc1jet[5];
        TH1D *tau_cm_sum_Zinc1jet[5];
        TH1D *tau_cm_max_Zinc1jet[5];
        TH1D *tau_c_cm_sum_Zinc1jet[5];
        TH1D *tau_c_cm_max_Zinc1jet[5];

        TH1D *gentau_sum_Zinc1jet[5];
        TH1D *gentau_max_Zinc1jet[5];
        TH1D *gentau_c_sum_Zinc1jet[5];
        TH1D *gentau_c_max_Zinc1jet[5];
        TH1D *gentau_cm_sum_Zinc1jet[5];
        TH1D *gentau_cm_max_Zinc1jet[5];
        TH1D *gentau_c_cm_sum_Zinc1jet[5];
        TH1D *gentau_c_cm_max_Zinc1jet[5];

        // TH2D for reponse objects

        TH2D *hresponsetau_sum_Zinc1jet[5];
        TH2D *hresponsetau_max_Zinc1jet[5];
        TH2D *hresponsetau_c_sum_Zinc1jet[5];
        TH2D *hresponsetau_c_max_Zinc1jet[5];
        TH2D *hresponsetau_cm_sum_Zinc1jet[5];
        TH2D *hresponsetau_cm_max_Zinc1jet[5];
        TH2D *hresponsetau_c_cm_sum_Zinc1jet[5];
        TH2D *hresponsetau_c_cm_max_Zinc1jet[5];

        TH2D *hresponseZNGoodJets_Zexc;              

        TH2D *hresponseFirstJetPt_Zinc1jet;              
        TH2D *hresponseSecondJetPt_Zinc2jet;              
        TH2D *hresponseThirdJetPt_Zinc3jet;              
        TH2D *hresponseFourthJetPt_Zinc4jet;              
        TH2D *hresponseFifthJetPt_Zinc5jet;              

        TH2D *hresponseJetsHT_Zinc1jet;  
        TH2D *hresponseJetsHT_Zinc2jet; 
        TH2D *hresponseJetsHT_Zinc3jet;
        TH2D *hresponseJetsHT_Zinc4jet;
        TH2D *hresponseJetsHT_Zinc5jet;
             
        TH2D *hresponseFirstJetEta_Zinc1jet; 
        TH2D *hresponseSecondJetEta_Zinc2jet; 
        TH2D *hresponseThirdJetEta_Zinc3jet; 
        TH2D *hresponseFourthJetEta_Zinc4jet;
        TH2D *hresponseFifthJetEta_Zinc5jet; 

        

        //--- RooUnfoldResponses ---
        //RooUnfoldResponse *responseZNGoodJets_Zexc;              
        //RooUnfoldResponse *responseZMass;                      
        //RooUnfoldResponse *responseTwoJetsPtDiffExc;           
        //RooUnfoldResponse *responseTwoJetsPtDiffInc;           
        //RooUnfoldResponse *responseBestTwoJetsPtDiffInc;       
        //RooUnfoldResponse *responseTwoJetsPtDiffLowPtExc;        
        //RooUnfoldResponse *responseTwoJetsPtDiffLowPtInc;      
        //RooUnfoldResponse *responseBestTwoJetsPtDiffLowPtInc;  
        //RooUnfoldResponse *responseJetsMassExc;                
        //RooUnfoldResponse *responseJetsMassInc;                
        //RooUnfoldResponse *responseBestJetsMassInc;            
        //RooUnfoldResponse *responseJetsMassLowPtExc;           
        //RooUnfoldResponse *responseJetsMassLowPtInc;           
        //RooUnfoldResponse *responseBestJetsMassLowPtInc;       

        //RooUnfoldResponse *responseFirstJetPt;                 
        //RooUnfoldResponse *responseSecondJetPt;                
        //RooUnfoldResponse *responseThirdJetPt;                 
        //RooUnfoldResponse *responseFourthJetPt;                
        //RooUnfoldResponse *responseFifthJetPt;                 
        //RooUnfoldResponse *responseSixthJetPt;                 

        //RooUnfoldResponse *responseFirstJetEta;                
        //RooUnfoldResponse *responseSecondJetEta;               
        //RooUnfoldResponse *responseThirdJetEta;                
        //RooUnfoldResponse *responseFourthJetEta;               
        //RooUnfoldResponse *responseFifthJetEta;                
        //RooUnfoldResponse *responseSixthJetEta;                

        //RooUnfoldResponse *responseJetsHt1Jet;                 
        //RooUnfoldResponse *responseJetsHt2Jet;                 
        //RooUnfoldResponse *responseJetsHt3Jet;                 
        //RooUnfoldResponse *responseJetsHt4Jet;                 
        //RooUnfoldResponse *responseJetsHt5Jet;                 
        //RooUnfoldResponse *responseJetsHt6Jet;                 

        //RooUnfoldResponse *responseSpTJets_Zexc2jet;           
        //RooUnfoldResponse *responseSpTJets_Zinc2jet;           
        //RooUnfoldResponse *responseBestSpTJets_Zinc2jet;       
        //RooUnfoldResponse *responseSpTJets_LowPt_Zexc2jet;     
        //RooUnfoldResponse *responseSpTJets_LowPt_Zinc2jet;     
        //RooUnfoldResponse *responseBestSpTJets_LowPt_Zinc2jet; 
        //RooUnfoldResponse *responseSpT_Zexc2jet;               
        //RooUnfoldResponse *responseSpT_Zinc2jet;               
        //RooUnfoldResponse *responseBestSpT_Zinc2jet;           
        //RooUnfoldResponse *responseSpT_LowPt_Zexc2jet;         
        //RooUnfoldResponse *responseSpT_LowPt_Zinc2jet;         
        //RooUnfoldResponse *responseBestSpT_LowPt_Zinc2jet;     
        //RooUnfoldResponse *responsedPhiJets_Zexc2jet;          
        //RooUnfoldResponse *responsedPhiJets_Zinc2jet;          
        //RooUnfoldResponse *responseBestdPhiJets_Zinc2jet;      
        //RooUnfoldResponse *responsedPhiJets_LowPt_Zexc2jet;    
        //RooUnfoldResponse *responsedPhiJets_LowPt_Zinc2jet;    
        //RooUnfoldResponse *responseBestdPhiJets_LowPt_Zinc2jet;
        //RooUnfoldResponse *responsePHI_Zexc2jet;               
        //RooUnfoldResponse *responsePHI_Zinc2jet;               
        //RooUnfoldResponse *responseBestPHI_Zinc2jet;           
        //RooUnfoldResponse *responsePHI_LowPt_Zexc2jet;         
        //RooUnfoldResponse *responsePHI_LowPt_Zinc2jet;         
        //RooUnfoldResponse *responseBestPHI_LowPt_Zinc2jet;     
        //RooUnfoldResponse *responsePHI_T_Zexc2jet;             
        //RooUnfoldResponse *responsePHI_T_Zinc2jet;             
        //RooUnfoldResponse *responseBestPHI_T_Zinc2jet;         
        //RooUnfoldResponse *responsePHI_T_LowPt_Zexc2jet;       
        //RooUnfoldResponse *responsePHI_T_LowPt_Zinc2jet;       
        //RooUnfoldResponse *responseBestPHI_T_LowPt_Zinc2jet;   
        //RooUnfoldResponse *responseSPhi_Zexc2jet;              
        //RooUnfoldResponse *responseSPhi_Zinc2jet;              
        //RooUnfoldResponse *responsedEtaJets_Zexc2jet;          
        //RooUnfoldResponse *responsedEtaJets_Zinc2jet;          
        //RooUnfoldResponse *responseBestSPhi_Zinc2jet;          
        //RooUnfoldResponse *responseSPhi_LowPt_Zexc2jet;        
        //RooUnfoldResponse *responseSPhi_LowPt_Zinc2jet;        
        //RooUnfoldResponse *responseBestSPhi_LowPt_Zinc2jet;    

        //// vector boson and single jet 
        //RooUnfoldResponse *responsedEtaBosonJet_Zexc1;
        //RooUnfoldResponse *responsedEtaBosonJet_Zinc1;

        ClassDef(HistoSetZJets,10);
};

#endif
