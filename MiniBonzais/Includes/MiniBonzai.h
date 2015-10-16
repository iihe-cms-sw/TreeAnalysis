#ifndef MiniBonzai_h
#define MiniBonzai_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TMath.h>
#include <TLorentzVector.h>
#include <TString.h>
#include <TTree.h>
#include <TBranch.h>
#include "functions.h"
#include "ConfigVJets.h"
#include <vector>

using namespace std;

class MiniBonzai {
    public :
        TTree          *fChain;   //!pointer to the analyzed TTree or TChain
        Int_t           fCurrent; //!current Tree number in a TChain

        // Declaration of leaf types
        Int_t           EvtInfo_NumVtx;
        Int_t           EvtInfo_RunNum;
        Int_t           EvtInfo_EventNum;
        Int_t           nup_;
        Double_t        PU_npT;
        Double_t        PU_npIT;
        vector<double>  *pdfInfo_;
        vector<double>  *genLepId_;
        vector<double>  *genLepSt_;
        vector<double>  *genLepQ_;
        vector<double>  *genLepPt_;
        vector<double>  *genLepEta_;
        vector<double>  *genLepPhi_;
        vector<double>  *genLepE_;
        vector<double>  *genPhoPt_;
        vector<double>  *genPhoEta_;
        vector<double>  *genPhoPhi_;
        vector<double>  *genJetPt_;
        vector<double>  *genJetEta_;
        vector<double>  *genJetPhi_;
        vector<double>  *genJetE_;
        vector<double>  *genJetChF_;
        Int_t           eventElecTrig;
        vector<double>  *patElecPt_;
        vector<double>  *patElecEta_;
        vector<double>  *patElecPhi_;
        vector<double>  *patElecEn_;
        vector<double>  *patElecCharge_;
        vector<double>  *patElecID_;
        vector<double>  *patElecTrig_;
        vector<double>  *patElecPfIsoRho_;
        vector<double>  *patElecScEta_;
        Int_t           eventMuonTrig;
        vector<double>  *patMuonPt_;
        vector<double>  *patMuonEta_;
        vector<double>  *patMuonPhi_;
        vector<double>  *patMuonVtxZ_;
        vector<double>  *patMuonEn_;
        vector<double>  *patMuonCharge_;
        vector<double>  *patMuonDxy_;
        //   vector<double>  *patMuonCombId_;
        vector<double>  *patMuonCombId_Double;
        vector<int>     *patMuonCombId_Int;
        vector<double>  *patMuonTrig_;
        vector<double>  *patMuonPfIsoDbeta_;
        vector<double>  *patJetPfAk05En_;
        vector<double>  *patJetPfAk05Pt_;
        vector<double>  *patJetPfAk05Eta_;
        vector<double>  *patJetPfAk05Phi_;
        vector<double>  *patJetPfAk05LooseId_;
        vector<double>  *patJetPfAk05jetBSZ_;
        vector<double>  *patJetPfAk05jetBZ_;
        vector<double>  *patJetPfAk05jetpuMVA_;
        vector<double>  *patJetPfAk05OCSV_;
        vector<double>  *patJetPfAk05PartonFlavour_;
        vector<double>  *patMetPt_;
        vector<double>  *patMetPhi_;
        vector<double>  *patMetSig_;

        vector<double>  *mcEventWeight_;

        // List of branches
        TBranch        *b_mcEventWeight_;   //!
        TBranch        *b_EvtInfo_NumVtx;   //!
        TBranch        *b_EvtInfo_RunNum;   //!
        TBranch        *b_EvtInfo_EventNum;   //!
        TBranch        *b_nup_;   //!
        TBranch        *b_PU_npT;   //!
        TBranch        *b_PU_npIT;   //!
        TBranch        *b_pdfInfo_;   //!
        TBranch        *b_genLepId_;   //!
        TBranch        *b_genLepSt_;   //!
        TBranch        *b_genLepQ_;   //!
        TBranch        *b_genLepPt_;   //!
        TBranch        *b_genLepEta_;   //!
        TBranch        *b_genLepPhi_;   //!
        TBranch        *b_genLepE_;   //!
        TBranch        *b_genPhoPt_;   //!
        TBranch        *b_genPhoEta_;   //!
        TBranch        *b_genPhoPhi_;   //!
        TBranch        *b_genJetPt_;   //!
        TBranch        *b_genJetEta_;   //!
        TBranch        *b_genJetPhi_;   //!
        TBranch        *b_genJetE_;   //!
        TBranch        *b_genJetChF_;   //!
        TBranch        *b_eventElecTrig;   //!
        TBranch        *b_patElecPt_;   //!
        TBranch        *b_patElecEta_;   //!
        TBranch        *b_patElecPhi_;   //!
        TBranch        *b_patElecEn_;   //!
        TBranch        *b_patElecCharge_;   //!
        TBranch        *b_patElecID_;   //!
        TBranch        *b_patElecTrig_;   //!
        TBranch        *b_patElecPfIsoRho_;   //!
        TBranch        *b_patElecScEta_;   //!
        TBranch        *b_eventMuonTrig;   //!
        TBranch        *b_patMuonPt_;   //!
        TBranch        *b_patMuonEta_;   //!
        TBranch        *b_patMuonPhi_;   //!
        TBranch        *b_patMuonVtxZ_;   //!
        TBranch        *b_patMuonEn_;   //!
        TBranch        *b_patMuonCharge_;   //!
        TBranch        *b_patMuonDxy_;   //!
        //   TBranch        *b_patMuonCombId_;   //!
        TBranch        *b_patMuonCombId_Double;
        TBranch        *b_patMuonCombId_Int;
        TBranch        *b_patMuonTrig_;   //!
        TBranch        *b_patMuonPfIsoDbeta_;   //!
        TBranch        *b_patJetPfAk05En_;   //!
        TBranch        *b_patJetPfAk05Pt_;   //!
        TBranch        *b_patJetPfAk05Eta_;   //!
        TBranch        *b_patJetPfAk05Phi_;   //!
        TBranch        *b_patJetPfAk05LooseId_;   //!
        TBranch        *b_patJetPfAk05jetBSZ_;   //!
        TBranch        *b_patJetPfAk05jetBZ_;   //!
        TBranch        *b_patJetPfAk05jetpuMVA_;   //!
        TBranch        *b_patJetPfAk05OCSV_;   //!
        TBranch        *b_patJetPfAk05PartonFlavour_;   //!
        TBranch        *b_patMetPt_;   //!
        TBranch        *b_patMetPhi_;   //!
        TBranch        *b_patMetSig_;   //!

        MiniBonzai(TString fileName_, float lumiScale_, bool useTriggerCorrection_, int lepPtCutMin_, int lepEtaCutMax_, int jetPtCutMin_, int jetEtaCutMax_, Long_t nMaxEvents_, TString outDir_, TString bonzaiDir_);
        ~MiniBonzai();
        string   CreateOutputFileName(TString pdfSet = "", int pdfMember = -1, double muR = 0, double muF = 0);
        Int_t    Cut(Long64_t entry);
        Int_t    GetEntry(Long64_t entry);
        Long64_t LoadTree(Long64_t entry);
        void     Init(bool hasRecoInfo, bool hasGenInfo);
        void     initLHAPDF(TString pdfSet, int pdfMember);
        void     Loop(bool hasRecoInfo, bool hasGenInfo, TString pdfSet = "", int pdfMember = -1, double muR = 0, double muF = 0);
        void     getMuons(vector<leptonStruct>& leptons,  vector<leptonStruct>& vetoMuons);
        void     getElectrons(vector<leptonStruct>& leptons,  vector<leptonStruct>& vetoElectrons);
        Bool_t   Notify();
        void     Show(Long64_t entry = -1);

        TString  outDir;	 
        TString  fileName;
        Long_t   nMaxEvents;
        float    lumiScale;
        bool     useTriggerCorrection;
        bool     isData;
        int      lepPtCutMin;
        int      lepEtaCutMax;
        int      jetPtCutMin;
        int      jetEtaCutMax; 
        TString  lepSel;
        bool     rejectBTagEvents;
        TString  bonzaiDir;
        ConfigVJets cfg_;
};

#endif
