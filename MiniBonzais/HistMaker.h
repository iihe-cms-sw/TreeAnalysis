//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Nov  6 22:29:26 2015 by ROOT version 5.34/18
// from TTree ZJets/ZJets
// found on file: MiniBonzaiTuples/DMu_8TeV_DYJetsToLL_M-50_TuneCUETP8M1_8TeV-amcatnloFXFX-Bonzai_fixed_allWeights_dR_MiniBonzai.root
//////////////////////////////////////////////////////////

#ifndef HistMaker_h
#define HistMaker_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <cstdarg>
#include <TH1.h>
// Header file for the classes stored in the TTree if any.
#include <vector>

// Fixed size dimensions of array or collections stored in the TTree if any.

class HistMaker {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Short_t         NJets_inclusive;
   Double_t        Z_pt;
   Double_t        Z_eta;
   Double_t        Z_phi;
   Double_t        Z_m;
   Double_t        Z_y;
   Double_t        FirstJet_pt;
   Double_t        FirstJet_eta;
   Double_t        FirstJet_phi;
   Double_t        FirstJet_e;
   Double_t        FirstJet_y;
   Double_t        SecondJet_pt;
   Double_t        SecondJet_eta;
   Double_t        SecondJet_phi;
   Double_t        SecondJet_e;
   Double_t        SecondJet_y;
   Double_t        ZFirstJet_Sumy;
   Double_t        ZFirstJet_Dify;
   Double_t        ZSecondJet_Sumy;
   Double_t        ZSecondJet_Dify;
   Double_t        DiJets_Sumy;
   Double_t        DiJets_Dify;
   Double_t        ZDiJets_Sumy;
   Double_t        ZDiJets_Dify;
   Double_t        ZFirstJet_Sumeta;
   Double_t        ZFirstJet_Difeta;
   Double_t        ZSecondJet_Sumeta;
   Double_t        ZSecondJet_Difeta;
   Double_t        DiJets_Sumeta;
   Double_t        DiJets_Difeta;
   Double_t        ZDiJets_Sumeta;
   Double_t        ZDiJets_Difeta;
   vector<double>  *EventWeight;
   Short_t         genNJets_inclusive;
   Double_t        genZ_pt;
   Double_t        genZ_eta;
   Double_t        genZ_phi;
   Double_t        genZ_m;
   Double_t        genZ_y;
   Double_t        genFirstJet_pt;
   Double_t        genFirstJet_eta;
   Double_t        genFirstJet_phi;
   Double_t        genFirstJet_e;
   Double_t        genFirstJet_y;
   Double_t        genSecondJet_pt;
   Double_t        genSecondJet_eta;
   Double_t        genSecondJet_phi;
   Double_t        genSecondJet_e;
   Double_t        genSecondJet_y;
   Double_t        genZFirstJet_Sumy;
   Double_t        genZFirstJet_Dify;
   Double_t        genZSecondJet_Sumy;
   Double_t        genZSecondJet_Dify;
   Double_t        genDiJets_Sumy;
   Double_t        genDiJets_Dify;
   Double_t        genZDiJets_Sumy;
   Double_t        genZDiJets_Dify;
   Double_t        genZFirstJet_Sumeta;
   Double_t        genZFirstJet_Difeta;
   Double_t        genZSecondJet_Sumeta;
   Double_t        genZSecondJet_Difeta;
   Double_t        genDiJets_Sumeta;
   Double_t        genDiJets_Difeta;
   Double_t        genZDiJets_Sumeta;
   Double_t        genZDiJets_Difeta;

   // List of branches
   TBranch        *b_NJets_inclusive;   //!
   TBranch        *b_Z_pt;   //!
   TBranch        *b_Z_eta;   //!
   TBranch        *b_Z_phi;   //!
   TBranch        *b_Z_m;   //!
   TBranch        *b_Z_y;   //!
   TBranch        *b_FirstJet_pt;   //!
   TBranch        *b_FirstJet_eta;   //!
   TBranch        *b_FirstJet_phi;   //!
   TBranch        *b_FirstJet_e;   //!
   TBranch        *b_FirstJet_y;   //!
   TBranch        *b_SecondJet_pt;   //!
   TBranch        *b_SecondJet_eta;   //!
   TBranch        *b_SecondJet_phi;   //!
   TBranch        *b_SecondJet_e;   //!
   TBranch        *b_SecondJet_y;   //!
   TBranch        *b_ZFirstJet_Sumy;   //!
   TBranch        *b_ZFirstJet_Dify;   //!
   TBranch        *b_ZSecondJet_Sumy;   //!
   TBranch        *b_ZSecondJet_Dify;   //!
   TBranch        *b_DiJets_Sumy;   //!
   TBranch        *b_DiJets_Dify;   //!
   TBranch        *b_ZDiJets_Sumy;   //!
   TBranch        *b_ZDiJets_Dify;   //!
   TBranch        *b_ZFirstJet_Sumeta;   //!
   TBranch        *b_ZFirstJet_Difeta;   //!
   TBranch        *b_ZSecondJet_Sumeta;   //!
   TBranch        *b_ZSecondJet_Difeta;   //!
   TBranch        *b_DiJets_Sumeta;   //!
   TBranch        *b_DiJets_Difeta;   //!
   TBranch        *b_ZDiJets_Sumeta;   //!
   TBranch        *b_ZDiJets_Difeta;   //!
   TBranch        *b_EventWeight;   //!
   TBranch        *b_genNJets_inclusive;   //!
   TBranch        *b_genZ_pt;   //!
   TBranch        *b_genZ_eta;   //!
   TBranch        *b_genZ_phi;   //!
   TBranch        *b_genZ_m;   //!
   TBranch        *b_genZ_y;   //!
   TBranch        *b_genFirstJet_pt;   //!
   TBranch        *b_genFirstJet_eta;   //!
   TBranch        *b_genFirstJet_phi;   //!
   TBranch        *b_genFirstJet_e;   //!
   TBranch        *b_genFirstJet_y;   //!
   TBranch        *b_genSecondJet_pt;   //!
   TBranch        *b_genSecondJet_eta;   //!
   TBranch        *b_genSecondJet_phi;   //!
   TBranch        *b_genSecondJet_e;   //!
   TBranch        *b_genSecondJet_y;   //!
   TBranch        *b_genZFirstJet_Sumy;   //!
   TBranch        *b_genZFirstJet_Dify;   //!
   TBranch        *b_genZSecondJet_Sumy;   //!
   TBranch        *b_genZSecondJet_Dify;   //!
   TBranch        *b_genDiJets_Sumy;   //!
   TBranch        *b_genDiJets_Dify;   //!
   TBranch        *b_genZDiJets_Sumy;   //!
   TBranch        *b_genZDiJets_Dify;   //!
   TBranch        *b_genZFirstJet_Sumeta;   //!
   TBranch        *b_genZFirstJet_Difeta;   //!
   TBranch        *b_genZSecondJet_Sumeta;   //!
   TBranch        *b_genZSecondJet_Difeta;   //!
   TBranch        *b_genDiJets_Sumeta;   //!
   TBranch        *b_genDiJets_Difeta;   //!
   TBranch        *b_genZDiJets_Sumeta;   //!
   TBranch        *b_genZDiJets_Difeta;   //!

   vector<TH1*> listOfHistograms;
   HistMaker(TTree *tree=0);
   virtual ~HistMaker();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
   TH1D* newTH1D(string name, string title, string xTitle, int nBins, double *xBins);
};

#endif

#ifdef HistMaker_cxx
HistMaker::HistMaker(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("MiniBonzaiTuples/DMu_8TeV_DYJetsToLL_M-50_TuneCUETP8M1_8TeV-amcatnloFXFX-Bonzai_fixed_allWeights_dR_MiniBonzai.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("MiniBonzaiTuples/DMu_8TeV_DYJetsToLL_M-50_TuneCUETP8M1_8TeV-amcatnloFXFX-Bonzai_fixed_allWeights_dR_MiniBonzai.root");
      }
      f->GetObject("ZJets",tree);

   }
   Init(tree);
}

HistMaker::~HistMaker()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t HistMaker::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t HistMaker::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void HistMaker::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   EventWeight = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("NJets_inclusive", &NJets_inclusive, &b_NJets_inclusive);
   fChain->SetBranchAddress("Z_pt", &Z_pt, &b_Z_pt);
   fChain->SetBranchAddress("Z_eta", &Z_eta, &b_Z_eta);
   fChain->SetBranchAddress("Z_phi", &Z_phi, &b_Z_phi);
   fChain->SetBranchAddress("Z_m", &Z_m, &b_Z_m);
   fChain->SetBranchAddress("Z_y", &Z_y, &b_Z_y);
   fChain->SetBranchAddress("FirstJet_pt", &FirstJet_pt, &b_FirstJet_pt);
   fChain->SetBranchAddress("FirstJet_eta", &FirstJet_eta, &b_FirstJet_eta);
   fChain->SetBranchAddress("FirstJet_phi", &FirstJet_phi, &b_FirstJet_phi);
   fChain->SetBranchAddress("FirstJet_e", &FirstJet_e, &b_FirstJet_e);
   fChain->SetBranchAddress("FirstJet_y", &FirstJet_y, &b_FirstJet_y);
   fChain->SetBranchAddress("SecondJet_pt", &SecondJet_pt, &b_SecondJet_pt);
   fChain->SetBranchAddress("SecondJet_eta", &SecondJet_eta, &b_SecondJet_eta);
   fChain->SetBranchAddress("SecondJet_phi", &SecondJet_phi, &b_SecondJet_phi);
   fChain->SetBranchAddress("SecondJet_e", &SecondJet_e, &b_SecondJet_e);
   fChain->SetBranchAddress("SecondJet_y", &SecondJet_y, &b_SecondJet_y);
   fChain->SetBranchAddress("ZFirstJet_Sumy", &ZFirstJet_Sumy, &b_ZFirstJet_Sumy);
   fChain->SetBranchAddress("ZFirstJet_Dify", &ZFirstJet_Dify, &b_ZFirstJet_Dify);
   fChain->SetBranchAddress("ZSecondJet_Sumy", &ZSecondJet_Sumy, &b_ZSecondJet_Sumy);
   fChain->SetBranchAddress("ZSecondJet_Dify", &ZSecondJet_Dify, &b_ZSecondJet_Dify);
   fChain->SetBranchAddress("DiJets_Sumy", &DiJets_Sumy, &b_DiJets_Sumy);
   fChain->SetBranchAddress("DiJets_Dify", &DiJets_Dify, &b_DiJets_Dify);
   fChain->SetBranchAddress("ZDiJets_Sumy", &ZDiJets_Sumy, &b_ZDiJets_Sumy);
   fChain->SetBranchAddress("ZDiJets_Dify", &ZDiJets_Dify, &b_ZDiJets_Dify);
   fChain->SetBranchAddress("ZFirstJet_Sumeta", &ZFirstJet_Sumeta, &b_ZFirstJet_Sumeta);
   fChain->SetBranchAddress("ZFirstJet_Difeta", &ZFirstJet_Difeta, &b_ZFirstJet_Difeta);
   fChain->SetBranchAddress("ZSecondJet_Sumeta", &ZSecondJet_Sumeta, &b_ZSecondJet_Sumeta);
   fChain->SetBranchAddress("ZSecondJet_Difeta", &ZSecondJet_Difeta, &b_ZSecondJet_Difeta);
   fChain->SetBranchAddress("DiJets_Sumeta", &DiJets_Sumeta, &b_DiJets_Sumeta);
   fChain->SetBranchAddress("DiJets_Difeta", &DiJets_Difeta, &b_DiJets_Difeta);
   fChain->SetBranchAddress("ZDiJets_Sumeta", &ZDiJets_Sumeta, &b_ZDiJets_Sumeta);
   fChain->SetBranchAddress("ZDiJets_Difeta", &ZDiJets_Difeta, &b_ZDiJets_Difeta);
   fChain->SetBranchAddress("EventWeight", &EventWeight, &b_EventWeight);
   fChain->SetBranchAddress("genNJets_inclusive", &genNJets_inclusive, &b_genNJets_inclusive);
   fChain->SetBranchAddress("genZ_pt", &genZ_pt, &b_genZ_pt);
   fChain->SetBranchAddress("genZ_eta", &genZ_eta, &b_genZ_eta);
   fChain->SetBranchAddress("genZ_phi", &genZ_phi, &b_genZ_phi);
   fChain->SetBranchAddress("genZ_m", &genZ_m, &b_genZ_m);
   fChain->SetBranchAddress("genZ_y", &genZ_y, &b_genZ_y);
   fChain->SetBranchAddress("genFirstJet_pt", &genFirstJet_pt, &b_genFirstJet_pt);
   fChain->SetBranchAddress("genFirstJet_eta", &genFirstJet_eta, &b_genFirstJet_eta);
   fChain->SetBranchAddress("genFirstJet_phi", &genFirstJet_phi, &b_genFirstJet_phi);
   fChain->SetBranchAddress("genFirstJet_e", &genFirstJet_e, &b_genFirstJet_e);
   fChain->SetBranchAddress("genFirstJet_y", &genFirstJet_y, &b_genFirstJet_y);
   fChain->SetBranchAddress("genSecondJet_pt", &genSecondJet_pt, &b_genSecondJet_pt);
   fChain->SetBranchAddress("genSecondJet_eta", &genSecondJet_eta, &b_genSecondJet_eta);
   fChain->SetBranchAddress("genSecondJet_phi", &genSecondJet_phi, &b_genSecondJet_phi);
   fChain->SetBranchAddress("genSecondJet_e", &genSecondJet_e, &b_genSecondJet_e);
   fChain->SetBranchAddress("genSecondJet_y", &genSecondJet_y, &b_genSecondJet_y);
   fChain->SetBranchAddress("genZFirstJet_Sumy", &genZFirstJet_Sumy, &b_genZFirstJet_Sumy);
   fChain->SetBranchAddress("genZFirstJet_Dify", &genZFirstJet_Dify, &b_genZFirstJet_Dify);
   fChain->SetBranchAddress("genZSecondJet_Sumy", &genZSecondJet_Sumy, &b_genZSecondJet_Sumy);
   fChain->SetBranchAddress("genZSecondJet_Dify", &genZSecondJet_Dify, &b_genZSecondJet_Dify);
   fChain->SetBranchAddress("genDiJets_Sumy", &genDiJets_Sumy, &b_genDiJets_Sumy);
   fChain->SetBranchAddress("genDiJets_Dify", &genDiJets_Dify, &b_genDiJets_Dify);
   fChain->SetBranchAddress("genZDiJets_Sumy", &genZDiJets_Sumy, &b_genZDiJets_Sumy);
   fChain->SetBranchAddress("genZDiJets_Dify", &genZDiJets_Dify, &b_genZDiJets_Dify);
   fChain->SetBranchAddress("genZFirstJet_Sumeta", &genZFirstJet_Sumeta, &b_genZFirstJet_Sumeta);
   fChain->SetBranchAddress("genZFirstJet_Difeta", &genZFirstJet_Difeta, &b_genZFirstJet_Difeta);
   fChain->SetBranchAddress("genZSecondJet_Sumeta", &genZSecondJet_Sumeta, &b_genZSecondJet_Sumeta);
   fChain->SetBranchAddress("genZSecondJet_Difeta", &genZSecondJet_Difeta, &b_genZSecondJet_Difeta);
   fChain->SetBranchAddress("genDiJets_Sumeta", &genDiJets_Sumeta, &b_genDiJets_Sumeta);
   fChain->SetBranchAddress("genDiJets_Difeta", &genDiJets_Difeta, &b_genDiJets_Difeta);
   fChain->SetBranchAddress("genZDiJets_Sumeta", &genZDiJets_Sumeta, &b_genZDiJets_Sumeta);
   fChain->SetBranchAddress("genZDiJets_Difeta", &genZDiJets_Difeta, &b_genZDiJets_Difeta);
   Notify();
}

TH1D* HistMaker::newTH1D(string name, string title, string xTitle, int nBins, double *xBins){
    TH1D* hist = new TH1D(name.c_str(), title.c_str(), nBins, xBins);
    hist->GetXaxis()->SetTitle(xTitle.c_str());
    hist->GetYaxis()->SetTitle("# Events");
    listOfHistograms.push_back(hist);
    return hist;
}

Bool_t HistMaker::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void HistMaker::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t HistMaker::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef HistMaker_cxx
