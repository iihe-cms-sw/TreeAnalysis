ZJetsAndDPS::ZJetsAndDPS(string fileName_, float lumiScale_, float puScale_, bool useTriggerCorrection_, bool useEfficiencyCorrection_, 
    int systematics_, int direction_, float xsecfactor_, int jetPtCutMin_, int jetPtCutMax_, int ZEtaCutMin_, int ZEtaCutMax_, bool nEvents_10000_) : 
  HistoSet(fileName_.substr(0, fileName_.find("_"))), nEvents_10000(nEvents_10000_), outputDirectory("HistoFiles/"),
  fileName(fileName_), lumiScale(lumiScale_), puScale(puScale_), useTriggerCorrection(useTriggerCorrection_), useEfficiencyCorrection(useEfficiencyCorrection_), 
  systematics(systematics_), direction(direction_), xsecfactor(xsecfactor_), jetPtCutMin(jetPtCutMin_), jetPtCutMax(jetPtCutMax_), ZEtaCutMin(ZEtaCutMin_), ZEtaCutMax(ZEtaCutMax_)
{

  // if parameter tree is not specified (or zero), connect the file
  // used to generate this class and read the Tree.

  TChain *chain = new TChain("","");
  isData = false;

  if (fileName.find("DMu_") == 0) leptonFlavor = "Muons";
  else if (fileName.find("DE_") == 0)  leptonFlavor = "Electrons"; 
  else if (fileName.find("SMu_") == 0) leptonFlavor = "SingleMuon";
  else if (fileName.find("SE_") == 0)  leptonFlavor = "SingleElectron";
  else if (fileName.find("SMuE_") == 0) leptonFlavor = "TTMuE";


  if (fileName.find("Data") != string::npos ) isData = true; 

  string fullFileName =  "../Data_Z_5311/" + fileName;
  if (fileName.find("List") == string::npos){
    fullFileName += ".root";
    string treePath = fullFileName + "/tree/tree";

    cout << "Loading file: " << fullFileName << endl;
    chain->Add(treePath.c_str());
  }
  else {
    fullFileName += ".txt";
    ifstream infile(fullFileName.c_str());
    string line; 
    int countFiles(0);
    while (getline(infile, line)){
      countFiles++;
      //cout << " we are using LIST as input:" << line << "   " << countFiles <<endl;
      string treePath =  line + "/tree/tree";
      //      cout << treePath << endl;
      chain->Add(treePath.c_str());
    }
  }
  fChain = chain;
}

ZJetsAndDPS::~ZJetsAndDPS(){
  if (!fChain) return;
  delete fChain->GetCurrentFile();
}

string ZJetsAndDPS::CreateOutputFileName(bool useRoch, bool doFlat, int doPUStudy, bool doVarWidth, bool doBJets, bool doQCD){
  ostringstream result;
  result << outputDirectory << fileName;
  result << "_EffiCorr_" << useEfficiencyCorrection;
  result << "_TrigCorr_" << useTriggerCorrection;
  result << "_Syst_" << systematics;

  if (direction == 1) result << "_Up";
  else if (direction == -1) result << "_Down";
  result << "_JetPtMin_" << jetPtCutMin;
  if (jetPtCutMax > jetPtCutMin) result << "_JetPtMax_" << jetPtCutMax;
  if (ZEtaCutMin > -999999 && ZEtaCutMin <  0) result << "_ZEtaMin_m" << abs(ZEtaCutMin);
  if (ZEtaCutMin > -999999 && ZEtaCutMin >= 0) result << "_ZEtaMin_"  << abs(ZEtaCutMin);
  if (ZEtaCutMax <  999999 && ZEtaCutMax >= 0) result << "_ZEtaMax_"  << abs(ZEtaCutMax);
  if (ZEtaCutMax <  999999 && ZEtaCutMax <  0) result << "_ZEtaMax_m" << abs(ZEtaCutMax);

  if (useRoch) result << "_rochester";
  if (!isData && doFlat) result << "_Flat";
  if (doPUStudy >= 0) result << "_Beta" << doPUStudy;
  if (doVarWidth) result << "_VarWidth";
  if (doBJets) result << "_BJets";
  if (doQCD) result << "_QCD";

  //--- Add your test names here ---
  // result << "_AdditionalFlag";
  
  result << ".root";
  return result.str();
}

Int_t ZJetsAndDPS::GetEntry(Long64_t entry){
  // Read contents of entry.
  if (!fChain) return 0;
  return fChain->GetEntry(entry);
}

Long64_t ZJetsAndDPS::LoadTree(Long64_t entry){
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

//void ZJetsAndDPS::Init(TTree *tree_, bool hasRecoInfo, bool hasGenInfo, bool hasPartonInfo){
void ZJetsAndDPS::Init(bool hasRecoInfo, bool hasGenInfo, bool hasPartonInfo){
  // The Init() function is called when the selector needs to initialize
  // a new tree or chain. Typically here the branch addresses and branch
  // pointers of the tree will be set.
  // It is normally not necessary to make changes to the generated
  // code, but the routine can be extended by the user if needed.
  // Init() will be called many times when running on PROOF
  // (once per file to be processed).

  // Set object pointer
  mcSherpaWeights_ = 0 ;
  pdfInfo_ = 0;
  genLepPt_ = 0;
  genLepEta_ = 0;
  genLepPhi_ = 0;
  genLepE_ = 0;
  genLepQ_ = 0;
  genLepId_ = 0;
  genLepSt_ = 0;
  genPhoPt_ = 0;
  genPhoEta_ = 0;
  genPhoPhi_ = 0;
  genJetPt_ = 0;
  genJetEta_ = 0;
  genJetPhi_ = 0;
  genJetE_ = 0;
  dpsParton_Pt = 0;
  dpsParton_Eta = 0;
  dpsParton_Phi = 0;
  dpsParton_E = 0;
  genMatchDPSpar = 0;
  dpsParton_dR = 0;

  gsfElecPt_ = 0;
  gsfElecEta_ = 0;
  gsfElecPhi_ = 0;
  gsfElecEnergy_ = 0;
  patElecPt_ = 0;
  patElecEta_ = 0;
  patElecPhi_ = 0;
  patElecEn_ = 0;
  patElecCharge_ = 0;
  patElecID_ = 0;
  patElecTrig_ = 0;
  patElecDetIso_ = 0;
  patElecPfIsoRho_ = 0;
  patElecScEta_ = 0;
  patElecIsPF_ = 0;

  patMuonPt_ = 0;
  patMuonEta_ = 0;
  patMuonPhi_ = 0;
  patMuonVtxZ_ = 0;
  patMuonEn_ = 0;
  patMuonCharge_ = 0;
  patMuonDxy_ = 0;
  patMuonCombId_ = 0;
  patMuonTrig_ = 0;
  patMuonPfIsoDbeta_ = 0;

  patJetPfAk05En_ = 0;
  patJetPfAk05Pt_ = 0;
  patJetPfAk05Eta_ = 0;
  patJetPfAk05Phi_ = 0;
  patJetPfAk05LooseId_ = 0;
  patJetPfAk05jetBSZ_ = 0;
  patJetPfAk05jetBZ_ = 0;
  patJetPfAk05jetpuMVA_ = 0;
  patJetPfAk05OCSV_ = 0 ;
  patMetPt_ = 0 ;
  patMetPhi_= 0 ;
  patMetSig_= 0 ;

  // Set branch addresses and branch pointers
  //if (!tree_) return;
  //fChain = tree_;
  fCurrent = -1;
  fChain->SetMakeClass(1);


  if (fileName.find("Data") == string::npos) fChain->SetBranchAddress("PU_npT", &PU_npT, &b_PU_npT);
  if (fileName.find("UNFOLDING") != string::npos) fChain->SetBranchAddress("nup_", &nup_, &b_nup_);
  if (hasRecoInfo){
    fChain->SetBranchAddress("EvtInfo_NumVtx", &EvtInfo_NumVtx, &b_EvtInfo_NumVtx);
    //fChain->SetBranchAddress("EvtInfo_RunNum", &EvtInfo_RunNum, &b_EvtInfo_RunNum); // not used
    //fChain->SetBranchAddress("EvtInfo_EventNum", &EvtInfo_EventNum, &b_EvtInfo_EventNum); // not used

    fChain->SetBranchAddress("patJetPfAk05En_", &patJetPfAk05En_, &b_patJetPfAk05En_);
    fChain->SetBranchAddress("patJetPfAk05Pt_", &patJetPfAk05Pt_, &b_patJetPfAk05Pt_);
    fChain->SetBranchAddress("patJetPfAk05Eta_", &patJetPfAk05Eta_, &b_patJetPfAk05Eta_);
    fChain->SetBranchAddress("patJetPfAk05Phi_", &patJetPfAk05Phi_, &b_patJetPfAk05Phi_);
    fChain->SetBranchAddress("patJetPfAk05LooseId_", &patJetPfAk05LooseId_, &b_patJetPfAk05LooseId_);
    fChain->SetBranchAddress("patJetPfAk05jetBSZ_", &patJetPfAk05jetBSZ_, &b_patJetPfAk05jetBSZ_);
    fChain->SetBranchAddress("patJetPfAk05jetBZ_", &patJetPfAk05jetBZ_, &b_patJetPfAk05jetBZ_);
    fChain->SetBranchAddress("patJetPfAk05jetpuMVA_", &patJetPfAk05jetpuMVA_, &b_patJetPfAk05jetpuMVA_);
    fChain->SetBranchAddress("patJetPfAk05OCSV_", &patJetPfAk05OCSV_, &b_patJetPfAk05OCSV_);

    if (leptonFlavor != "Muons"){
      //fChain->SetBranchAddress("gsfElecPt_", &gsfElecPt_, &b_gsfElecPt_); // not used
      //fChain->SetBranchAddress("gsfElecEta_", &gsfElecEta_, &b_gsfElecEta_); // not used
      //fChain->SetBranchAddress("gsfElecPhi_", &gsfElecPhi_, &b_gsfElecPhi_); // not used
      //fChain->SetBranchAddress("gsfElecEnergy_", &gsfElecEnergy_, &b_gsfElecEnergy_); // not used
      fChain->SetBranchAddress("patElecPt_", &patElecPt_, &b_patElecPt_);
      fChain->SetBranchAddress("patElecEta_", &patElecEta_, &b_patElecEta_);
      fChain->SetBranchAddress("patElecPhi_", &patElecPhi_, &b_patElecPhi_);
      fChain->SetBranchAddress("patElecEnergy_", &patElecEn_, &b_patElecEn_);
      fChain->SetBranchAddress("patElecCharge_", &patElecCharge_, &b_patElecCharge_);
      fChain->SetBranchAddress("patElecID_", &patElecID_, &b_patElecID_);
      fChain->SetBranchAddress("patElecTrig_", &patElecTrig_, &b_patElecTrig_);
      //fChain->SetBranchAddress("patElecDetIso_", &patElecDetIso_, &b_patElecDetIso_); // not used
      //fChain->SetBranchAddress("patElecPfIsoRho_", &patElecPfIsoRho_, &b_patElecPfIsoRho_); // not used
      fChain->SetBranchAddress("patElecScEta_", &patElecScEta_, &b_patElecScEta_);
      //fChain->SetBranchAddress("patElecIsPF_", &patElecIsPF_, &b_patElecIsPF_); // not used

    }
    if (leptonFlavor != "Electrons"){
      fChain->SetBranchAddress("patMuonPt_", &patMuonPt_, &b_patMuonPt_);
      fChain->SetBranchAddress("patMuonEta_", &patMuonEta_, &b_patMuonEta_);
      fChain->SetBranchAddress("patMuonPhi_", &patMuonPhi_, &b_patMuonPhi_);
      //fChain->SetBranchAddress("patMuonVtxZ_", &patMuonVtxZ_, &b_patMuonVtxZ_); // not used
      fChain->SetBranchAddress("patMuonEn_", &patMuonEn_, &b_patMuonEn_);
      fChain->SetBranchAddress("patMuonCharge_", &patMuonCharge_, &b_patMuonCharge_);
      fChain->SetBranchAddress("patMuonDxy_", &patMuonDxy_, &b_patMuonDxy_);
      fChain->SetBranchAddress("patMuonCombId_", &patMuonCombId_, &b_patMuonCombId_);
      fChain->SetBranchAddress("patMuonTrig_", &patMuonTrig_, &b_patMuonTrig_);
      fChain->SetBranchAddress("patMuonPfIsoDbeta_", &patMuonPfIsoDbeta_, &b_patMuonPfIsoDbeta_);
    }
    if (leptonFlavor == "SingleElectron"  || leptonFlavor == "SingleMuon"){
      fChain->SetBranchAddress("patMetPt_", &patMetPt_, &b_patMetPt_);
      fChain->SetBranchAddress("patMetPhi_", &patMetPhi_, &b_patMetPhi_);
      //fChain->SetBranchAddress("patMetSig_", &patMetSig_, &b_patMetSig_); // not used
    }
  }
  if (hasGenInfo){
    fChain->SetBranchAddress("genLepPt_", &genLepPt_, &b_genLepPt_);
    fChain->SetBranchAddress("genLepEta_", &genLepEta_, &b_genLepEta_);
    fChain->SetBranchAddress("genLepPhi_", &genLepPhi_, &b_genLepPhi_);
    fChain->SetBranchAddress("genLepE_", &genLepE_, &b_genLepE_);
    fChain->SetBranchAddress("genLepQ_", &genLepQ_, &b_genLepQ_);
    fChain->SetBranchAddress("genJetPt_", &genJetPt_, &b_genJetPt_);
    fChain->SetBranchAddress("genJetEta_", &genJetEta_, &b_genJetEta_);
    fChain->SetBranchAddress("genJetPhi_", &genJetPhi_, &b_genJetPhi_);
    fChain->SetBranchAddress("genJetE_", &genJetE_, &b_genJetE_);

    if (fileName.find("Sherpa") != string::npos || 
        fileName.find("UNFOLDING") != string::npos || 
        fileName.find("Powheg") != string::npos || 
        fileName.find("P8") != string::npos || 
        fileName.find("Z2") != string::npos){

      fChain->SetBranchAddress("pdfInfo_", &pdfInfo_, &b_pdfInfo_);
      fChain->SetBranchAddress("genLepId_", &genLepId_, &b_genLepId_);
      fChain->SetBranchAddress("genLepSt_", &genLepSt_, &b_genLepSt_);
      fChain->SetBranchAddress("genPhoPt_", &genPhoPt_, &b_genPhoPt_);
      fChain->SetBranchAddress("genPhoEta_", &genPhoEta_, &b_genPhoEta_);
      fChain->SetBranchAddress("genPhoPhi_", &genPhoPhi_, &b_genPhoPhi_);

      if (fileName.find("ZjjMiNLO") != string::npos || 
          fileName.find("mcEveWeight") != string::npos || 
          fileName.find("HepMC") != string::npos){
        fChain->SetBranchAddress("mcEveWeight_", &mcEveWeight_, &b_mcEveWeight_);
      }

      if (fileName.find("HepMC") != string::npos){
        fChain->SetBranchAddress("mcSherpaSumWeight3_", &mcSherpaSumWeight3_, &b_mcSherpaSumWeight3_);
        fChain->SetBranchAddress("mcSherpaWeights_", &mcSherpaWeights_, &b_mcSherpaWeights_);
      }

    }
  }
  if (hasPartonInfo){
    fChain->SetBranchAddress("dpsParton_Pt", &dpsParton_Pt, &b_dpsParton_Pt);
    fChain->SetBranchAddress("dpsParton_Eta", &dpsParton_Eta, &b_dpsParton_Eta);
    fChain->SetBranchAddress("dpsParton_Phi", &dpsParton_Phi, &b_dpsParton_Phi);
    fChain->SetBranchAddress("dpsParton_E", &dpsParton_E, &b_dpsParton_E);
    fChain->SetBranchAddress("genMatchDPSpar", &genMatchDPSpar, &b_genMatchDPSpar);
    fChain->SetBranchAddress("dpsParton_dR", &dpsParton_dR, &b_dpsParton_dR);
  }
  Notify();
  cout << "Branches are properly initialized." << endl;
}

Bool_t ZJetsAndDPS::Notify(){
  // The Notify() function is called when a new file is opened. This
  // can be either for a new TTree in a TChain or when when a new TTree
  // is started when using PROOF. It is normally not necessary to make changes
  // to the generated code, but the routine can be extended by the
  // user if needed. The return value is currently not used.

  return kTRUE;
}

void ZJetsAndDPS::Show(Long64_t entry){
  // Print contents of entry.
  // If entry is not specified, print current entry
  if (!fChain) return;
  fChain->Show(entry);
}

Int_t ZJetsAndDPS::Cut(Long64_t entry){
  // This function may be called from Loop.
  // returns  1 if entry is accepted.
  // returns -1 otherwise.
  printf("entry %lld", entry);
  return 1;
}
