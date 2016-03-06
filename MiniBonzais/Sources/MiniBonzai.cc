#include "MiniBonzai.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLorentzVector.h>
#include <TMath.h>
#include "functions.h"
#include "ConfigVJets.h"
#include "standalone_LumiReWeighting.h"
#include <sys/time.h>
#include <TDatime.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <TObject.h>
#include "LHAPDF/LHAPDF.h"

using namespace std;

void MiniBonzai::Loop(bool hasRecoInfo, bool hasGenInfo, TString pdfSet, int pdfMember, double muR, double muF)
{
    //***********Counters****************
    unsigned int nEvents(0);

    //--- Initialize PDF from LHAPDF if needed ---
    if (pdfSet != "") initLHAPDF(pdfSet, pdfMember);

    ///****************************establish the output MiniBonzai root file************************
    //    TString outputfilename = outDir + fileName + "_MiniBonzai.root";
    TString outputfileName = CreateOutputFileName(pdfSet, pdfMember, muR, muF);
    TFile *outputfile = new TFile(outputfileName, "RECREATE"); 
    TTree *ZJets = new TTree("ZJets","ZJets");

    ///*******************Define reco variables that need to be stored in MiniBonzai*********************
    unsigned short NJets_inclusive; 

    double Z_pt;
    double Z_eta;
    double Z_phi;
    double Z_m;
    double Z_y;

    double FirstJet_pt;
    double FirstJet_eta;
    double FirstJet_phi;
    double FirstJet_e;
    double FirstJet_y;

    double SecondJet_pt;
    double SecondJet_eta;
    double SecondJet_phi;
    double SecondJet_e;
    double SecondJet_y;

    double ZFirstJet_Sumy;
    double ZFirstJet_Dify;
    double ZSecondJet_Sumy;
    double ZSecondJet_Dify;
    double DiJets_Sumy;
    double DiJets_Dify;
    double ZDiJets_Sumy;
    double ZDiJets_Dify;

    double ZFirstJet_Sumeta;
    double ZFirstJet_Difeta;
    double ZSecondJet_Sumeta;
    double ZSecondJet_Difeta;
    double DiJets_Sumeta;
    double DiJets_Difeta;
    double ZDiJets_Sumeta;
    double ZDiJets_Difeta;

    vector<double> EventWeight;
    double SumNominalWeight = 0;
    double SumWeight = 0;
    ///*********************Branches initialize for the correponding variables*******************
    ZJets->Branch("NJets_inclusive", &NJets_inclusive, "NJets_inclusive/S");

    ZJets->Branch("Z_pt", &Z_pt, "Z_pt/D");
    ZJets->Branch("Z_eta", &Z_eta, "Z_eta/D");
    ZJets->Branch("Z_phi", &Z_phi, "Z_phi/D");
    ZJets->Branch("Z_m", &Z_m, "Z_m/D");
    ZJets->Branch("Z_y", &Z_y, "Z_y/D");

    ZJets->Branch("FirstJet_pt", &FirstJet_pt, "FirstJet_pt/D");
    ZJets->Branch("FirstJet_eta", &FirstJet_eta, "FirstJet_eta/D"); 
    ZJets->Branch("FirstJet_phi", &FirstJet_phi, "FirstJet_phi/D");
    ZJets->Branch("FirstJet_e", &FirstJet_e, "FirstJet_e/D");
    ZJets->Branch("FirstJet_y", &FirstJet_y, "FirstJet_y/D");

    ZJets->Branch("SecondJet_pt", &SecondJet_pt, "SecondJet_pt/D");
    ZJets->Branch("SecondJet_eta", &SecondJet_eta, "SecondJet_eta/D");
    ZJets->Branch("SecondJet_phi", &SecondJet_phi, "SecondJet_phi/D");
    ZJets->Branch("SecondJet_e", &SecondJet_e, "SecondJet_e/D");
    ZJets->Branch("SecondJet_y", &SecondJet_y, "SecondJet_y/D");

    ZJets->Branch("ZFirstJet_Sumy", &ZFirstJet_Sumy, "ZFirstJet_Sumy/D");
    ZJets->Branch("ZFirstJet_Dify", &ZFirstJet_Dify, "ZFirstJet_Dify/D");
    ZJets->Branch("ZSecondJet_Sumy", &ZSecondJet_Sumy, "ZSecondJet_Sumy/D");
    ZJets->Branch("ZSecondJet_Dify", &ZSecondJet_Dify, "ZSecondJet_Dify/D");
    ZJets->Branch("DiJets_Sumy", &DiJets_Sumy, "DiJets_Sumy/D");
    ZJets->Branch("DiJets_Dify", &DiJets_Dify, "DiJets_Dify/D");
    ZJets->Branch("ZDiJets_Sumy", &ZDiJets_Sumy, "ZDiJets_Sumy/D");
    ZJets->Branch("ZDiJets_Dify", &ZDiJets_Dify, "ZDiJets_Dify/D");

    ZJets->Branch("ZFirstJet_Sumeta", &ZFirstJet_Sumeta, "ZFirstJet_Sumeta/D");
    ZJets->Branch("ZFirstJet_Difeta", &ZFirstJet_Difeta, "ZFirstJet_Difeta/D");
    ZJets->Branch("ZSecondJet_Sumeta", &ZSecondJet_Sumeta, "ZSecondJet_Sumeta/D");
    ZJets->Branch("ZSecondJet_Difeta", &ZSecondJet_Difeta, "ZSecondJet_Difeta/D");
    ZJets->Branch("DiJets_Sumeta", &DiJets_Sumeta, "DiJets_Sumeta/D");
    ZJets->Branch("DiJets_Difeta", &DiJets_Difeta, "DiJets_Difeta/D");
    ZJets->Branch("ZDiJets_Sumeta", &ZDiJets_Sumeta, "ZDiJets_Sumeta/D");
    ZJets->Branch("ZDiJets_Difeta", &ZDiJets_Difeta, "ZDiJets_Difeta/D");

    ZJets->Branch("EventWeight", &EventWeight);
    ///*******************Define gen variables that need to be stored in MiniBonzai*********************
    unsigned short genNJets_inclusive; 

    double genZ_pt;
    double genZ_eta;
    double genZ_phi;
    double genZ_m;
    double genZ_y;

    double genFirstJet_pt;
    double genFirstJet_eta;
    double genFirstJet_phi;
    double genFirstJet_e;
    double genFirstJet_y;

    double genSecondJet_pt;
    double genSecondJet_eta;
    double genSecondJet_phi;
    double genSecondJet_e;
    double genSecondJet_y;

    double genZFirstJet_Sumy;
    double genZFirstJet_Dify;
    double genZSecondJet_Sumy;
    double genZSecondJet_Dify;
    double genDiJets_Sumy;
    double genDiJets_Dify;
    double genZDiJets_Sumy;
    double genZDiJets_Dify;

    double genZFirstJet_Sumeta;
    double genZFirstJet_Difeta;
    double genZSecondJet_Sumeta;
    double genZSecondJet_Difeta;
    double genDiJets_Sumeta;
    double genDiJets_Difeta;
    double genZDiJets_Sumeta;
    double genZDiJets_Difeta;

    ///*********************Branches initialize for the correponding variables*******************
    ZJets->Branch("genNJets_inclusive", &genNJets_inclusive, "genNJets_inclusive/S");

    ZJets->Branch("genZ_pt", &genZ_pt, "genZ_pt/D");
    ZJets->Branch("genZ_eta", &genZ_eta, "genZ_eta/D");
    ZJets->Branch("genZ_phi", &genZ_phi, "genZ_phi/D");
    ZJets->Branch("genZ_m", &genZ_m, "genZ_m/D");
    ZJets->Branch("genZ_y", &genZ_y, "genZ_y/D");

    ZJets->Branch("genFirstJet_pt", &genFirstJet_pt, "genFirstJet_pt/D");
    ZJets->Branch("genFirstJet_eta", &genFirstJet_eta, "genFirstJet_eta/D"); 
    ZJets->Branch("genFirstJet_phi", &genFirstJet_phi, "genFirstJet_phi/D");
    ZJets->Branch("genFirstJet_e", &genFirstJet_e, "genFirstJet_e/D");
    ZJets->Branch("genFirstJet_y", &genFirstJet_y, "genFirstJet_y/D");

    ZJets->Branch("genSecondJet_pt", &genSecondJet_pt, "genSecondJet_pt/D");
    ZJets->Branch("genSecondJet_eta", &genSecondJet_eta, "genSecondJet_eta/D");
    ZJets->Branch("genSecondJet_phi", &genSecondJet_phi, "genSecondJet_phi/D");
    ZJets->Branch("genSecondJet_e", &genSecondJet_e, "genSecondJet_e/D");
    ZJets->Branch("genSecondJet_y", &genSecondJet_y, "genSecondJet_y/D");

    ZJets->Branch("genZFirstJet_Sumy", &genZFirstJet_Sumy, "genZFirstJet_Sumy/D");
    ZJets->Branch("genZFirstJet_Dify", &genZFirstJet_Dify, "genZFirstJet_Dify/D");
    ZJets->Branch("genZSecondJet_Sumy", &genZSecondJet_Sumy, "genZSecondJet_Sumy/D");
    ZJets->Branch("genZSecondJet_Dify", &genZSecondJet_Dify, "genZSecondJet_Dify/D");
    ZJets->Branch("genDiJets_Sumy", &genDiJets_Sumy, "genDiJets_Sumy/D");
    ZJets->Branch("genDiJets_Dify", &genDiJets_Dify, "genDiJets_Dify/D");
    ZJets->Branch("genZDiJets_Sumy", &genZDiJets_Sumy, "genZDiJets_Sumy/D");
    ZJets->Branch("genZDiJets_Dify", &genZDiJets_Dify, "genZDiJets_Dify/D");

    ZJets->Branch("genZFirstJet_Sumeta", &genZFirstJet_Sumeta, "genZFirstJet_Sumeta/D");
    ZJets->Branch("genZFirstJet_Difeta", &genZFirstJet_Difeta, "genZFirstJet_Difeta/D");
    ZJets->Branch("genZSecondJet_Sumeta", &genZSecondJet_Sumeta, "genZSecondJet_Sumeta/D");
    ZJets->Branch("genZSecondJet_Difeta", &genZSecondJet_Difeta, "genZSecondJet_Difeta/D");
    ZJets->Branch("genDiJets_Sumeta", &genDiJets_Sumeta, "genDiJets_Sumeta/D");
    ZJets->Branch("genDiJets_Difeta", &genDiJets_Difeta, "genDiJets_Difeta/D");
    ZJets->Branch("genZDiJets_Sumeta", &genZDiJets_Sumeta, "genZDiJets_Sumeta/D");
    ZJets->Branch("genZDiJets_Difeta", &genZDiJets_Difeta, "genZDiJets_Difeta/D");

    //***************************Load efficiency tables**************************
    table TableJESunc("EfficiencyTables/JESUnce_FT_53_V21_AN4_Uncertainty_AK5PFchs.txt");
    table LeptIso, LeptID, LeptTrig, Ele_Rec;
    //electron SF
    table Ele_Rec_8TeV("EfficiencyTables/Ele_SF_Reconstruction_2012.txt");
    table SC_Ele_2012EA("EfficiencyTables/Ele_SF_EA2012.txt");
    // muon SF
    table TrigMu17Mu8SF("EfficiencyTables/Efficiency_SF_Mu17Mu8.txt");
    table SC_RunABCD_TightID("EfficiencyTables/Muon_IDTight_Efficiencies_Run_2012ABCD_53X_Eta_Pt.txt");
    table SC_RunABCD_LooseIso("EfficiencyTables/Muon_ISOLoose_forTight_Efficiencies_Run_2012ABCD_53X_Eta_Pt.txt");
    table TrigIsoMu24SF("EfficiencyTables/Efficiency_SF_IsoMu24_eta2p1.txt");

    LeptID = SC_RunABCD_TightID;
    LeptIso = SC_RunABCD_LooseIso;
    LeptTrig = TrigMu17Mu8SF;
    Ele_Rec = Ele_Rec_8TeV;
    if (lepSel == "DE") LeptID = SC_Ele_2012EA;

    double xsec = 1.;
    int ZMCutLow(71), ZMCutHigh(111);
    //	 double ZptRange[6] = {0, 40, 80, 120, 160, 1000};
    int LeptonID(11);
    if (lepSel == "DMu") LeptonID = 13;

    // Systematics, if necessary in the analysis
    int scale(0);
    int smearJet(0);

    // setting weight when running on MIX of exclusive DY/WJets files to match number of parton events
    double mixingWeightsDY[4] = {0.192686, 0.0718097, 0.04943495, 0.0360337}; // here we match all partons, and combine electron and muon side

    //************************begin to loop over all the events*******************
    Init(hasRecoInfo, hasGenInfo);
    if (fChain == 0) return;
    Long64_t nentries = fChain->GetEntries();
    if (0 <= nMaxEvents && nMaxEvents  < nentries) nentries = nMaxEvents;//specialize the entries
    std::cout << "We will run on " << nentries << " events" << std::endl;

    struct timeval t0;
    gettimeofday(&t0, 0);
    int mess_every_n = std::min(10000LL, nentries/10);

    //   Long64_t nbytes = 0, nb = 0;
    for (Long64_t jentry=0; jentry<nentries;jentry++) {
        Long64_t ientry = LoadTree(jentry);
        if (ientry < 0) break;

        if (jentry % mess_every_n == 0 && jentry > 0){
            timeval t1;
            gettimeofday(&t1, 0);
            double dt = (t1.tv_sec - t0.tv_sec) + 1.e-6*(t1.tv_usec - t0.tv_usec);
            dt *= double(nentries  - jentry) / mess_every_n;
            int dt_s = int(dt + 0.5);
            int dt_h = int(dt_s) / 3600;
            dt_s -= dt_h * 3600;
            int dt_m = dt_s / 60;
            dt_s -= dt_m *60;
            std::cout << TString::Format("%4.1f%%", (100. * jentry) / nentries)
                << "\t" << std::setw(11) << jentry << " / " << nentries
                << "\t " << std::setw(4) << int(dt / mess_every_n * 1.e6 + 0.5) << " us/event"
                << "\t Remaining time for this dataset loop: "
                << std::setw(2) << dt_h << " h "
                << std::setw(2) << dt_m << " min "
                << std::setw(2) << dt_s << " s" << endl
                << "\r" << std::flush;
            t0 = t1;
        }
        fChain->GetEntry(jentry);
        nEvents++;

        // *******Weight of pileup and MC*****************
        double weight(1);
        //			if (hasRecoInfo && !isData) weight *= puWeight.weight(int(PU_npT));
        weight *= lumiScale * xsec;

        /*			if(addPuWeights){
                    double add_w_ = addPuWeights->GetBinContent(addPuWeights->GetXaxis()->FindBin(EvtInfo_NumVtx));
                    if(add_w_ > 0) weight *= add_w_;
                    }*/

        if (fileName.Index("DYJets") >= 0 && fileName.Index("MIX") >= 0 && nup_ > 5) weight *= mixingWeightsDY[nup_ - 6];


        //********Retrieve leptons********************
        bool passesLeptonCut(0);
        unsigned short nLeptons(0); // nVetoMuons(0), nVetoElectrons(0);
        vector<leptonStruct> leptons;
        vector<leptonStruct> vetoMuons;
        vector<leptonStruct> vetoElectrons;
        TLorentzVector EWKBoson;

        if(hasRecoInfo)
        {
            if(lepSel == "DMu") getMuons(leptons, vetoMuons);
            if(lepSel == "DE") getElectrons(leptons, vetoElectrons);

            nLeptons = leptons.size();
            //				nVetoMuons = vetoMuons.size();
            //				nVetoElectrons = vetoElectrons.size();

            sort(leptons.begin(), leptons.end(), LepDescendingOrder);
            sort(vetoMuons.begin(), vetoMuons.end(), LepDescendingOrder);
            sort(vetoElectrons.begin(), vetoElectrons.end(), LepDescendingOrder);

            if ((lepSel == "DMu" || lepSel == "DE") && nLeptons >= 2)
            {
                EWKBoson = leptons[0].v + leptons[1].v;
                if (leptons[0].charge * leptons[1].charge < 0 && EWKBoson.M() > ZMCutLow && EWKBoson.M() < ZMCutHigh) passesLeptonCut = 1;

                //apply scale factor on MC***
                if (!isData) 
                {
                    double effWeight = 1.;
                    if (lepSel == "DMu") {
                        effWeight *= LeptID.getEfficiency(leptons[0].v.Pt(), fabs(leptons[0].v.Eta()));
                        effWeight *= LeptID.getEfficiency(leptons[1].v.Pt(), fabs(leptons[1].v.Eta()));
                        effWeight *= LeptIso.getEfficiency(leptons[0].v.Pt(), fabs(leptons[0].v.Eta()));
                        effWeight *= LeptIso.getEfficiency(leptons[1].v.Pt(), fabs(leptons[1].v.Eta()));
                        if (useTriggerCorrection) effWeight *= LeptTrig.getEfficiency(fabs(leptons[0].v.Eta()), fabs(leptons[1].v.Eta()));
                    }
                    else if (lepSel == "DE") {
                        effWeight *= Ele_Rec.getEfficiency(leptons[0].v.Pt(), fabs(leptons[0].scEta));
                        effWeight *= Ele_Rec.getEfficiency(leptons[1].v.Pt(), fabs(leptons[1].scEta));
                        effWeight *= LeptID.getEfficiency(leptons[0].v.Pt(), fabs(leptons[0].scEta));
                        effWeight *= LeptID.getEfficiency(leptons[1].v.Pt(), fabs(leptons[1].scEta));
                    }
                    weight *= effWeight;
                } // end if MC scale factor ***
            } // end if Z boson selection ***
        } // end if reco info ***

        //***************Retrieve Gen leptons***********************
        bool passesgenLeptonCut(0);
        unsigned short nTotgenLeptons(0), ngenLeptons(0), nTotGenPhotons(0);
        vector<leptonStruct> genLeptons;
        vector<int> usedGenPho;
        TLorentzVector genEWKBoson;

        if(hasGenInfo)
        {
            nTotGenPhotons = genPhoEta_->size();
            nTotgenLeptons = genLepEta_->size();
            // retrieve gen leptons with status 1 i.e. matrix element******
            for(unsigned short i(0); i < nTotgenLeptons; i++)
            {
                bool lepToBeConsidered(false);
                if ((lepSel == "DMu" || lepSel == "DE") && abs(genLepId_->at(i)) == LeptonID) lepToBeConsidered = true;
                if (!lepToBeConsidered) continue;

                int charge;
                if (abs(genLepId_->at(i)) == 12 || abs(genLepId_->at(i)) == 14 || abs(genLepId_->at(i)) == 16) charge = 0;
                else if (genLepId_->at(i) < 0) charge = -1;
                else charge = 1;

                leptonStruct genLep(genLepPt_->at(i), genLepEta_->at(i), genLepPhi_->at(i), genLepE_->at(i), charge, 0, 0, 0, 0);
                leptonStruct genLepNoFSR(genLepPt_->at(i), genLepEta_->at(i), genLepPhi_->at(i), genLepE_->at(i), charge, 0, 0, 0, 0);

                //******dress the leptons with photon (DR = 0.1). Only for leptons with status 1 (after FSR)******
                if(genLepSt_->at(i) == 1 && lepToBeConsidered)
                {
                    for (unsigned short j(0); j < nTotGenPhotons; j++)
                    {
                        TLorentzVector tmpGenPho;
                        tmpGenPho.SetPtEtaPhiM(genPhoPt_->at(j), genPhoEta_->at(j), genPhoPhi_->at(j), 0.);
                        int used(0);
                        for (unsigned short k(0); k < usedGenPho.size(); k++)
                        {
                            if (j == usedGenPho[k]) used = 1;
                        }
                        if (deltaR(tmpGenPho.Phi(), tmpGenPho.Eta(), genLepNoFSR.v.Phi(), genLepNoFSR.v.Eta()) < 0.1 && !used)
                        {
                            genLep.v += tmpGenPho;
                            usedGenPho.push_back(j);
                        }
                    }// end loop all the gen photons

                    if(genLep.v.Pt() >= lepPtCutMin && fabs(genLep.v.Eta()) <= 0.1*lepEtaCutMax && abs(genLep.charge) > 0)
                    {
                        genLeptons.push_back(genLep);
                    }
                }// end if photon and lepton separation
            } // end loop all the gen leptons

            ngenLeptons = genLeptons.size();

            //sort gen leptons by PT
            sort(genLeptons.begin(), genLeptons.end(), LepDescendingOrder);

            //good gen leptons selection
            if ((lepSel == "DMu" || lepSel == "DE") && ngenLeptons >= 2)
            {
                genEWKBoson = genLeptons[0].v + genLeptons[1].v;
                if (genLeptons[0].charge * genLeptons[1].charge < 0 && genEWKBoson.M() > ZMCutLow && genEWKBoson.M() < ZMCutHigh)  passesgenLeptonCut = 1;
            }

        } // end if gen info

        ///******************Retrieve good jets***************************************
        unsigned short nGoodJets(0), nTotJets(0); 
        bool bTagJetFound(false);
        vector<jetStruct> jets;
        TLorentzVector dijet;

        if(hasRecoInfo)
        {
            nTotJets = patJetPfAk05Eta_->size();
            for (unsigned short i(0); i < nTotJets; i++)
            {
                bool passesBJets = false;
                if (fileName.Index("Sherpa") < 0) passesBJets = (patJetPfAk05OCSV_->at(i) >= 0.679);
                jetStruct jet(patJetPfAk05Pt_->at(i), patJetPfAk05Eta_->at(i), patJetPfAk05Phi_->at(i), patJetPfAk05En_->at(i), i, passesBJets);

                // apply jet energy scale uncertainty
                double jetEnergyCorr = 0.;
                bool jetPassesPtCut(jet.v.Pt() >= 10);
                jetEnergyCorr = TableJESunc.getEfficiency(jet.v.Pt(), jet.v.Eta());
                jet.v.SetPtEtaPhiE(jet.v.Pt() * (1 + scale * jetEnergyCorr), jet.v.Eta(), jet.v.Phi(), jet.v.E() * (1 + scale * jetEnergyCorr));
                bool jetPassesEtaCut(fabs(jet.v.Rapidity()) <= 0.1*jetEtaCutMax);
                bool jetPassesIdCut(patJetPfAk05LooseId_->at(i) > 0);
                bool jetPassesMVACut(patJetPfAk05jetpuMVA_->at(i) > 0);

                bool jetPassesdRCut(1);
                unsigned short nRemovedLep = min(int(nLeptons), 2);
                for (unsigned short j(0); j < nRemovedLep; j++)
                {
                    if (deltaR(jet.v, leptons[j].v) < 0.5) jetPassesdRCut = 0;
                }//end loop lepton jet separation

                if (jetPassesPtCut && jetPassesEtaCut && jetPassesIdCut && jetPassesMVACut && jetPassesdRCut)
                {
                    jets.push_back(jet);
                    bTagJetFound = (bTagJetFound || passesBJets);
                }

            } // end looping all the reco jets

            nGoodJets = jets.size();

        }// end if reco info 

        ///************Retrieve good gen jets*********************************
        signed short nGoodGenJets(0), nTotGenJets(0);
        vector<jetStruct> genJets;
        TLorentzVector gendijet;

        if (hasGenInfo)
        {
            nTotGenJets = genJetEta_->size();

            for (unsigned short i(0); i < nTotGenJets; i++)
            {
                jetStruct genJet(genJetPt_->at(i), genJetEta_->at(i), genJetPhi_->at(i), genJetE_->at(i), i, 0);
                bool genJetPassesdRCut(1);
                for(unsigned short j(0); j < ngenLeptons; j++)
                {
                    if (deltaR(genJet.v, genLeptons[j].v) < 0.5) genJetPassesdRCut = 0;
                } //end loop gen lepton and gen jet separation

                if (genJet.v.Pt() >= 10 && fabs(genJet.v.Eta()) <= 5.0 && genJetPassesdRCut) genJets.push_back(genJet);
            }// end loop all the gen jets

            nGoodGenJets = genJets.size();

        }// end if gen info


        ////**************Match reco and gen jets****************************
        vector<int> genJetsIndex(nGoodGenJets, 0);
        vector<vector<int>> matchingTable(nGoodJets, genJetsIndex);

        if(hasRecoInfo && hasGenInfo)
        {
            for (unsigned short i(0); i < nGoodJets; i++)
            {
                double mindR(0.15);
                int index(-1);
                double dR(9999);
                for (unsigned short j(0); j < nGoodGenJets; j++)
                {
                    dR = deltaR(genJets[j].v, jets[i].v);
                    if (dR < mindR)
                    {
                        mindR = dR;
                        index = j;
                    } // end if DR separation
                } // end loop all the good gen jets
                if(index > -1 )
                {
                    matchingTable[i][index] = 1;
                    double oldJetPt = jets[i].v.Pt();
                    double newJetPt = SmearJetPt(oldJetPt, genJets[index].v.Pt(), jets[i].v.Eta(), smearJet);
                    jets[i].v.SetPtEtaPhiE(newJetPt, jets[i].v.Eta(), jets[i].v.Phi(), jets[i].v.E() * newJetPt /oldJetPt);
                } // end if new smeared jet set up
            }//end loop all the good reco jets
        }// end if RecoInfo and GenInfo

        /////***********After smearing jet Pt for MC, jets collections need to be re-analyzed**********
        if(hasRecoInfo)
        {
            vector<jetStruct> tmpJets;
            for (unsigned short i(0); i < nGoodJets; i++)
            {
                if (jets[i].v.Pt() >= jetPtCutMin) tmpJets.push_back(jets[i]);
            } // loop all the good reco jets

            jets.clear();
            jets = tmpJets;
            tmpJets.clear();
            nGoodJets = jets.size();

            if(nGoodJets>=1) sort(jets.begin(), jets.end(), JetDescendingOrder);
            if(nGoodJets>=2) dijet = jets[0].v + jets[1].v;

        }// end if has Reco info

        if(hasGenInfo)
        {
            vector<jetStruct> tmpGenJets;
            for (unsigned short i(0); i < nGoodGenJets; i++)
            {
                if (genJets[i].v.Pt() >= jetPtCutMin && fabs(genJets[i].v.Rapidity()) <= 0.1*jetEtaCutMax) tmpGenJets.push_back(genJets[i]);
                genJets.clear();
                genJets = tmpGenJets;
                tmpGenJets.clear();
                nGoodGenJets = genJets.size();

                if(nGoodGenJets>=1) sort(genJets.begin(), genJets.end(), JetDescendingOrder);
                if(nGoodGenJets>=2) gendijet = genJets[0].v + genJets[1].v;

            } // end loop all the good gen jets
        }// end if has gen info

        //*****************Initialize all the interesting variables***************************************
        NJets_inclusive = 0; 

        Z_pt = -999.;
        Z_eta = -999.;
        Z_phi = -999.;
        Z_m = -999.;
        Z_y = -999.;

        FirstJet_pt = -999.;
        FirstJet_eta = -999.;
        FirstJet_phi = -999.;
        FirstJet_e = -999.;
        FirstJet_y = -999.;

        SecondJet_pt = -999.;
        SecondJet_eta = -999.;
        SecondJet_phi = -999.;
        SecondJet_e = -999.;
        SecondJet_y = -999.;

        ZFirstJet_Sumy = -999.;
        ZFirstJet_Dify = -999.;
        ZSecondJet_Sumy = -999.;
        ZSecondJet_Dify = -999.;
        DiJets_Sumy = -999.;
        DiJets_Dify = -999.;
        ZDiJets_Sumy = -999.;
        ZDiJets_Dify = -999.;

        ZFirstJet_Sumeta = -999.;
        ZFirstJet_Difeta = -999.;
        ZSecondJet_Sumeta = -999.;
        ZSecondJet_Difeta = -999.;
        DiJets_Sumeta = -999.;
        DiJets_Difeta = -999.;
        ZDiJets_Sumeta = -999.;
        ZDiJets_Difeta = -999.;

        //************Specialize all the branches corresponding to the interesting variables*********************
        NJets_inclusive = nGoodJets;

        if(nGoodJets>=1 && passesLeptonCut)
        {
            Z_pt = EWKBoson.Pt();
            Z_eta = EWKBoson.Eta();
            Z_phi = EWKBoson.Phi();
            Z_m = EWKBoson.M();
            Z_y = EWKBoson.Rapidity();
        } //end if nGoodJets>=1**********

        if(nGoodJets>=1 && passesLeptonCut)
        {
            FirstJet_pt = jets[0].v.Pt();
            FirstJet_eta = jets[0].v.Eta();
            FirstJet_phi = jets[0].v.Phi();
            FirstJet_e = jets[0].v.E();
            FirstJet_y = jets[0].v.Rapidity();

            ZFirstJet_Sumy = fabs(EWKBoson.Rapidity()+jets[0].v.Rapidity())/2.0;
            ZFirstJet_Dify = fabs(EWKBoson.Rapidity()-jets[0].v.Rapidity())/2.0;

            ZFirstJet_Sumeta = fabs(EWKBoson.Eta()+jets[0].v.Eta())/2.0;
            ZFirstJet_Difeta = fabs(EWKBoson.Eta()-jets[0].v.Eta())/2.0;
        }// end if nGoodJets>=1*******************

        if(nGoodJets>=2 && passesLeptonCut)
        {
            SecondJet_pt = jets[1].v.Pt();
            SecondJet_eta = jets[1].v.Eta();
            SecondJet_phi = jets[1].v.Phi();
            SecondJet_e = jets[1].v.E();
            SecondJet_y = jets[1].v.Rapidity();

            ZSecondJet_Sumy = fabs(EWKBoson.Rapidity()+jets[1].v.Rapidity())/2.0;
            ZSecondJet_Dify = fabs(EWKBoson.Rapidity()-jets[1].v.Rapidity())/2.0;

            ZSecondJet_Sumeta = fabs(EWKBoson.Eta()+jets[1].v.Eta())/2.0;
            ZSecondJet_Difeta = fabs(EWKBoson.Eta()-jets[1].v.Eta())/2.0;

            ///////////////////////////////////////////////////////////////////
            //DiJets system////
            ///////////////////////////////////////////////////////////////////
            DiJets_Sumy = fabs(jets[0].v.Rapidity()+jets[1].v.Rapidity())/2.0;
            DiJets_Dify = fabs(jets[0].v.Rapidity()-jets[1].v.Rapidity())/2.0;

            DiJets_Sumeta = fabs(jets[0].v.Eta()+jets[1].v.Eta())/2.0;
            DiJets_Difeta = fabs(jets[0].v.Eta()-jets[1].v.Eta())/2.0;

            ZDiJets_Sumy = fabs(EWKBoson.Rapidity()+dijet.Rapidity());
            ZDiJets_Dify = fabs(EWKBoson.Rapidity()-dijet.Rapidity());

            ZDiJets_Sumeta = fabs(EWKBoson.Eta()+dijet.Eta());
            ZDiJets_Difeta = fabs(EWKBoson.Eta()-dijet.Eta());
        } // end if nGoodJets>=2**********************

        //*************Initialize all the gen variables*********************************************
        genNJets_inclusive = 0; 

        genZ_pt = -999.;
        genZ_eta = -999.;
        genZ_phi = -999.;
        genZ_m = -999.;
        genZ_y = -999.;

        genFirstJet_pt = -999.;
        genFirstJet_eta = -999.;
        genFirstJet_phi = -999.;
        genFirstJet_e = -999.;
        genFirstJet_y = -999.;

        genSecondJet_pt = -999.;
        genSecondJet_eta = -999.;
        genSecondJet_phi = -999.;
        genSecondJet_e = -999.;
        genSecondJet_y = -999.;

        genZFirstJet_Sumy = -999.;
        genZFirstJet_Dify = -999.;
        genZSecondJet_Sumy = -999.;
        genZSecondJet_Dify = -999.;
        genDiJets_Sumy = -999.;
        genDiJets_Dify = -999.;
        genZDiJets_Sumy = -999.;
        genZDiJets_Dify = -999.;

        genZFirstJet_Sumeta = -999.;
        genZFirstJet_Difeta = -999.;
        genZSecondJet_Sumeta = -999.;
        genZSecondJet_Difeta = -999.;
        genDiJets_Sumeta = -999.;
        genDiJets_Difeta = -999.;
        genZDiJets_Sumeta = -999.;
        genZDiJets_Difeta = -999.;

        EventWeight.clear();

        //************Specialize all the interesting gen variables*********************
        genNJets_inclusive = nGoodGenJets;

        if(nGoodGenJets>=1 && passesgenLeptonCut)
        {
            genZ_pt = genEWKBoson.Pt();
            genZ_eta = genEWKBoson.Eta();
            genZ_phi = genEWKBoson.Phi();
            genZ_m = genEWKBoson.M();
            genZ_y = genEWKBoson.Rapidity();
        } //end if nGoodGenJets>=1**********

        if(nGoodGenJets>=1 && passesgenLeptonCut)
        {
            genFirstJet_pt = genJets[0].v.Pt();
            genFirstJet_eta = genJets[0].v.Eta();
            genFirstJet_phi = genJets[0].v.Phi();
            genFirstJet_e = genJets[0].v.E();
            genFirstJet_y = genJets[0].v.Rapidity();

            genZFirstJet_Sumy = fabs(genEWKBoson.Rapidity()+genJets[0].v.Rapidity())/2.0;
            genZFirstJet_Dify = fabs(genEWKBoson.Rapidity()-genJets[0].v.Rapidity())/2.0;

            genZFirstJet_Sumeta = fabs(genEWKBoson.Eta()+genJets[0].v.Eta())/2.0;
            genZFirstJet_Difeta = fabs(genEWKBoson.Eta()-genJets[0].v.Eta())/2.0;

            if(fileName.Index("mcatnlo") >= 0){
                for(int k=0;k<110;k++){
                    if(k==1 || k==6 || k==8) continue;
                    EventWeight.push_back(mcEventWeight_->at(k));
                }
            }
        }// end if nGoodGenJets>=1*******************

        if(nGoodGenJets>=2 && passesgenLeptonCut)
        {
            genSecondJet_pt = genJets[1].v.Pt();
            genSecondJet_eta = genJets[1].v.Eta();
            genSecondJet_phi = genJets[1].v.Phi();
            genSecondJet_e = genJets[1].v.E();
            genSecondJet_y = genJets[1].v.Rapidity();

            genZSecondJet_Sumy = fabs(genEWKBoson.Rapidity()+genJets[1].v.Rapidity())/2.0;
            genZSecondJet_Dify = fabs(genEWKBoson.Rapidity()-genJets[1].v.Rapidity())/2.0;

            genZSecondJet_Sumeta = fabs(genEWKBoson.Eta()+genJets[1].v.Eta())/2.0;
            genZSecondJet_Difeta = fabs(genEWKBoson.Eta()-genJets[1].v.Eta())/2.0;

            ///////////////////////////////////////////////////////////////////
            //DiJets system////
            ///////////////////////////////////////////////////////////////////
            genDiJets_Sumy = fabs(genJets[0].v.Rapidity()+genJets[1].v.Rapidity())/2.0;
            genDiJets_Dify = fabs(genJets[0].v.Rapidity()-genJets[1].v.Rapidity())/2.0;

            genDiJets_Sumeta = fabs(genJets[0].v.Eta()+genJets[1].v.Eta())/2.0;
            genDiJets_Difeta = fabs(genJets[0].v.Eta()-genJets[1].v.Eta())/2.0;

            genZDiJets_Sumy = fabs(genEWKBoson.Rapidity()+gendijet.Rapidity());
            genZDiJets_Dify = fabs(genEWKBoson.Rapidity()-gendijet.Rapidity());

            genZDiJets_Sumeta = fabs(genEWKBoson.Eta()+gendijet.Eta());
            genZDiJets_Difeta = fabs(genEWKBoson.Eta()-gendijet.Eta());

        } // end if nGoodGenJets>=2**********************

        if((nGoodJets>=1 && passesLeptonCut) || (nGoodGenJets>=1 && passesgenLeptonCut)){
            ZJets->Fill();
        }

        SumNominalWeight += mcEventWeight_->at(0);
        SumWeight += mcEventWeight_->at(1);

    }//end event(entry) loop

    ///*******************************write the output file********************
    outputfile->cd();
    ZJets->Write("ZJets", TObject::kOverwrite);
    delete ZJets;
    outputfile->Close();	
    cout << "Sum of nominal weight: " << SumNominalWeight << endl
         << "Sum of second normal weight: " << SumWeight << endl 
         << "Finish!" << endl; 
}

void MiniBonzai::initLHAPDF(TString pdfSet, int pdfMember)
{
    LHAPDF::initPDFSet(1, pdfSet.Data(), pdfMember);
    //LHAPDF::initPDFSet(1, "CT10.LHgrid");
    LHAPDF::initPDFSet(2, "cteq6ll.LHpdf");
    if (pdfMember > LHAPDF::numberPDF(1) + 1) {
        cout << "Warning pdfMember to high" << endl;
        return;
    }
}


MiniBonzai::MiniBonzai(TString fileName_, float lumiScale_, bool useTriggerCorrection_, int lepPtCutMin_, int lepEtaCutMax_, int jetPtCutMin_, int jetEtaCutMax_, Long_t nMaxEvents_, TString outDir_, TString bonzaiDir_)
{
    fileName = fileName_;
    lumiScale = lumiScale_;
    useTriggerCorrection = useTriggerCorrection_;
    lepPtCutMin = lepPtCutMin_;
    lepEtaCutMax = lepEtaCutMax_;
    jetPtCutMin = jetPtCutMin_;
    jetEtaCutMax = jetEtaCutMax_;
    nMaxEvents = nMaxEvents_;
    outDir = outDir_;
    bonzaiDir = bonzaiDir_;

    if(nMaxEvents>0)
    {
        outDir.Remove(TString::kTrailing, '/');
        outDir += TString::Format("_%ldevts/", nMaxEvents);
        cout << "Output directory has been changed to " << outDir << endl;
    }

    TString command = "mkdir -p " + outDir;
    system(command);

    TChain *chain = new TChain("", "");
    isData = (fileName.Index("Data") >= 0);
    TString fullFileName = bonzaiDir + fileName;

    if (fileName.BeginsWith("DMu_")) lepSel = "DMu";
    else if (fileName.BeginsWith("DE_"))  lepSel = "DE";

    rejectBTagEvents = lepSel.BeginsWith("S");

    if (fileName.Index("List") < 0){
        fullFileName += ".root";
        TString treePath = fullFileName + "/tree/tree";
        if (fileName.Index("mcatnlo") >= 0) treePath = fullFileName + "/tree";
        if (fileName.Index("MG-MLM") >= 0) treePath = fullFileName + "/tree";
        if (fileName.Index("Sherpa") >= 0) treePath = fullFileName + "/tree";
        cout << "Loading file: " << fullFileName << endl;
        chain->Add(treePath);
    }
    else {
        fullFileName += ".txt";
        ifstream infile(fullFileName.Data());
        string line; 
        int countFiles(0);
        while (getline(infile, line)){
            countFiles++;
            TString treePath = line + "/tree/tree";
            if (fileName.Index("Sherpa") >= 0) treePath = line + "/tree";
            chain->Add(treePath);     
        }
    }    
    fChain = chain;
}

string MiniBonzai::CreateOutputFileName(TString pdfSet, int pdfMember, double muR, double muF)
{
    ostringstream result;
    result << outDir << fileName << "_MiniBonzai";

    if (muR != 0 && muF != 0) result << "_muR_" << muR << "_muF_" << muF;
    if (pdfSet != "") result << "_PDF_" << pdfSet << "_" << pdfMember;
    if (pdfSet == "" && pdfMember != -1) result << "_NNPDF_" << pdfMember;
    //--- Add your test names here ---
    //result << "_NoPUCut";
    //result << "_LooseID";

    result << ".root";
    return result.str();
}


MiniBonzai::~MiniBonzai()
{
    if (!fChain) return;
    delete fChain->GetCurrentFile();
}

Int_t MiniBonzai::GetEntry(Long64_t entry)
{
    // Read contents of entry.
    if (!fChain) return 0;
    return fChain->GetEntry(entry);
}

Long64_t MiniBonzai::LoadTree(Long64_t entry)
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

void MiniBonzai::Init(bool hasRecoInfo, bool hasGenInfo)
{
    // Set object pointer
    pdfInfo_ = 0;
    genLepId_ = 0;
    genLepSt_ = 0;
    genLepQ_ = 0;
    genLepPt_ = 0;
    genLepEta_ = 0;
    genLepPhi_ = 0;
    genLepE_ = 0;
    genPhoPt_ = 0;
    genPhoEta_ = 0;
    genPhoPhi_ = 0;
    genJetPt_ = 0;
    genJetEta_ = 0;
    genJetPhi_ = 0;
    genJetE_ = 0;
    genJetChF_ = 0;

    patElecPt_ = 0;
    patElecEta_ = 0;
    patElecPhi_ = 0;
    patElecEn_ = 0;
    patElecCharge_ = 0;
    patElecID_ = 0;
    patElecTrig_ = 0;
    patElecPfIsoRho_ = 0;
    patElecScEta_ = 0;

    patMuonPt_ = 0;
    patMuonEta_ = 0;
    patMuonPhi_ = 0;
    patMuonEn_ = 0;
    patMuonCharge_ = 0;
    //   patMuonCombId_ = 0;
    patMuonCombId_Int = 0;
    patMuonCombId_Double = 0;
    patMuonTrig_ = 0;
    patMuonPfIsoDbeta_ = 0;

    patJetPfAk05En_ = 0;
    patJetPfAk05Pt_ = 0;
    patJetPfAk05Eta_ = 0;
    patJetPfAk05Phi_ = 0;
    patJetPfAk05LooseId_ = 0;
    patJetPfAk05jetpuMVA_ = 0;
    patJetPfAk05OCSV_ = 0;

    mcEventWeight_ = 0;

    // Set branch addresses and branch pointers
    fCurrent = -1;
    fChain->SetMakeClass(1);

    if (fileName.Index("Data") < 0)
    {
        fChain->SetBranchAddress("PU_npT", &PU_npT, &b_PU_npT);
        fChain->SetBranchAddress("PU_npIT", &PU_npIT, &b_PU_npIT);
    }

    if(hasRecoInfo)
    {
        fChain->SetBranchAddress("EvtInfo_NumVtx", &EvtInfo_NumVtx, &b_EvtInfo_NumVtx);
        fChain->SetBranchAddress("EvtInfo_RunNum", &EvtInfo_RunNum, &b_EvtInfo_RunNum);
        fChain->SetBranchAddress("EvtInfo_EventNum", &EvtInfo_EventNum, &b_EvtInfo_EventNum);
        fChain->SetBranchAddress("patJetPfAk05En_", &patJetPfAk05En_, &b_patJetPfAk05En_);
        fChain->SetBranchAddress("patJetPfAk05Pt_", &patJetPfAk05Pt_, &b_patJetPfAk05Pt_);
        fChain->SetBranchAddress("patJetPfAk05Eta_", &patJetPfAk05Eta_, &b_patJetPfAk05Eta_);
        fChain->SetBranchAddress("patJetPfAk05Phi_", &patJetPfAk05Phi_, &b_patJetPfAk05Phi_);
        fChain->SetBranchAddress("patJetPfAk05LooseId_", &patJetPfAk05LooseId_, &b_patJetPfAk05LooseId_);
        fChain->SetBranchAddress("patJetPfAk05jetpuMVA_", &patJetPfAk05jetpuMVA_, &b_patJetPfAk05jetpuMVA_);
        fChain->SetBranchAddress("patJetPfAk05OCSV_", &patJetPfAk05OCSV_, &b_patJetPfAk05OCSV_);

        if (lepSel == "DE")
        {
            fChain->SetBranchAddress("patElecPt_", &patElecPt_, &b_patElecPt_);
            fChain->SetBranchAddress("patElecEta_", &patElecEta_, &b_patElecEta_);
            fChain->SetBranchAddress("patElecPhi_", &patElecPhi_, &b_patElecPhi_);
            fChain->SetBranchAddress("patElecEnergy_", &patElecEn_, &b_patElecEn_);
            fChain->SetBranchAddress("patElecCharge_", &patElecCharge_, &b_patElecCharge_);
            fChain->SetBranchAddress("patElecID_", &patElecID_, &b_patElecID_);
            fChain->SetBranchAddress("patElecTrig_", &patElecTrig_, &b_patElecTrig_);
            fChain->SetBranchAddress("patElecPfIsoRho_", &patElecPfIsoRho_, &b_patElecPfIsoRho_);
            fChain->SetBranchAddress("patElecScEta_", &patElecScEta_, &b_patElecScEta_);
        }

        if (lepSel == "DMu")
        {
            fChain->SetBranchAddress("patMuonPt_", &patMuonPt_, &b_patMuonPt_);
            fChain->SetBranchAddress("patMuonEta_", &patMuonEta_, &b_patMuonEta_);
            fChain->SetBranchAddress("patMuonPhi_", &patMuonPhi_, &b_patMuonPhi_);
            fChain->SetBranchAddress("patMuonEn_", &patMuonEn_, &b_patMuonEn_);
            fChain->SetBranchAddress("patMuonCharge_", &patMuonCharge_, &b_patMuonCharge_);
            //       fChain->SetBranchAddress("patMuonCombId_", &patMuonCombId_, &b_patMuonCombId_);

            if(fileName.Index("mcatnlo") >= 0 || fileName.Index("MG-MLM") >= 0)
            {
                fChain->SetBranchAddress("patMuonCombId_", &patMuonCombId_Int, &b_patMuonCombId_Int);

            }

            else{
                fChain->SetBranchAddress("patMuonCombId_", &patMuonCombId_Double, &b_patMuonCombId_Double);
            }
            fChain->SetBranchAddress("patMuonTrig_", &patMuonTrig_, &b_patMuonTrig_);
            fChain->SetBranchAddress("patMuonPfIsoDbeta_", &patMuonPfIsoDbeta_, &b_patMuonPfIsoDbeta_);
        }

    }

    if(hasGenInfo)
    {
        fChain->SetBranchAddress("nup_", &nup_, &b_nup_);
        fChain->SetBranchAddress("pdfInfo_", &pdfInfo_, &b_pdfInfo_);
        fChain->SetBranchAddress("genLepId_", &genLepId_, &b_genLepId_);
        fChain->SetBranchAddress("genLepSt_", &genLepSt_, &b_genLepSt_);
        fChain->SetBranchAddress("genLepQ_", &genLepQ_, &b_genLepQ_);
        fChain->SetBranchAddress("genLepPt_", &genLepPt_, &b_genLepPt_);
        fChain->SetBranchAddress("genLepEta_", &genLepEta_, &b_genLepEta_);
        fChain->SetBranchAddress("genLepPhi_", &genLepPhi_, &b_genLepPhi_);
        fChain->SetBranchAddress("genLepE_", &genLepE_, &b_genLepE_);
        fChain->SetBranchAddress("genPhoPt_", &genPhoPt_, &b_genPhoPt_);
        fChain->SetBranchAddress("genPhoEta_", &genPhoEta_, &b_genPhoEta_);
        fChain->SetBranchAddress("genPhoPhi_", &genPhoPhi_, &b_genPhoPhi_);
        fChain->SetBranchAddress("genJetPt_", &genJetPt_, &b_genJetPt_);
        fChain->SetBranchAddress("genJetEta_", &genJetEta_, &b_genJetEta_);
        fChain->SetBranchAddress("genJetPhi_", &genJetPhi_, &b_genJetPhi_);
        fChain->SetBranchAddress("genJetE_", &genJetE_, &b_genJetE_);

        if((fileName.Index("Sherpa") >= 0 && fileName.Index("UNFOLDING") >= 0) || fileName.Index("mcatnlo") >= 0)
        {
            fChain->SetBranchAddress("mcEventWeight_", &mcEventWeight_, &b_mcEventWeight_);
        }

    }

    Notify();
}

void MiniBonzai::getMuons(vector<leptonStruct>& leptons,  vector<leptonStruct>& vetoMuons)
{
    //--- get the number of Muon candidates from the vector size ---
    unsigned short nTotLeptons(patMuonEta_->size());

    bool eventTrigger = false;
    // we also have event trigger variables --> we should at least match one of the leptons to trigger
    for (unsigned short i(0); i < nTotLeptons; i++) {
        int whichTrigger(patMuonTrig_->at(i));
        if (lepSel == "SMu" && (whichTrigger & 0x1)) eventTrigger = true;
    }

    for (unsigned short i(0); i < nTotLeptons; i++) {
        double muonId = 0;

        if(fileName.Index("mcatnlo") >= 0 || fileName.Index("MG-MLM") >= 0) {
            muonId = (double) patMuonCombId_Int->at(i);
        }
        else { 
            muonId = (double) patMuonCombId_Double->at(i);
        }

        leptonStruct mu(patMuonPt_->at(i), 
                patMuonEta_->at(i), 
                patMuonPhi_->at(i), 
                patMuonEn_->at(i), 
                patMuonCharge_->at(i), 
                //                patMuonCombId_->at(i), 
                muonId, 
                patMuonPfIsoDbeta_->at(i), 
                patMuonEta_->at(i),
                patMuonTrig_->at(i));

        //--- good muons ---
        bool muPassesPtCut(mu.v.Pt() >= lepPtCutMin);
        bool muPassesEtaCut(fabs(mu.v.Eta()) <= 0.1*lepEtaCutMax);
        bool muPassesIdCut(mu.id & 0x1); // Tight muon Id
        bool muPassesIsoCut(0);
        if (lepSel == "DMu" && mu.iso < 0.2) muPassesIsoCut = 1;  
        else if (lepSel == "SMu" && mu.iso < 0.12) muPassesIsoCut = 1;  
        bool muPassesTrig(0);
        if (lepSel == "DMu" && (mu.trigger & 0x8)) muPassesTrig = 1;       // HLT_Mu17_Mu8 
        else if (lepSel == "SMu" && (mu.trigger & 0x1)) muPassesTrig = 1;  // HLT_IsoMu24_eta2p1_v

        //--- veto muons ---
        bool muPassesVetoPtCut(mu.v.Pt() >= 15);
        bool muPassesVetoEtaCut(fabs(mu.v.Eta()) <= 2.4);
        bool muPassesVetoIdCut(mu.id > 0); // muon Id

        /// for files obtained form bugra
        if (fileName.Index("Sherpa_Bugra_1_13_UNFOLDING") >= 0 && mu.trigger > 0) muPassesTrig = 1; // Bugra only keeps the double electron trigger !!!!! 

        // select the good muons only
        //cout << i << " pt=" << mu.v.Pt() << " eta=" << mu.v.Eta() << " phi=" << mu.v.Phi() << endl; 
        //cout << "id=" << muPassesIdCut << " iso=" << muPassesIsoCut << " trig=" << muPassesTrig << endl;
        if (muPassesPtCut && muPassesEtaCut && muPassesIdCut && muPassesIsoCut && (!useTriggerCorrection || muPassesTrig || eventTrigger)) {
            leptons.push_back(mu); 
        }
        // select the veto muons
        else if (lepSel == "SMu" && muPassesVetoPtCut && muPassesVetoEtaCut && muPassesVetoIdCut) {
            vetoMuons.push_back(mu); 
        }

    }//End of loop over all the muons
}

void MiniBonzai::getElectrons(vector<leptonStruct>& leptons,  vector<leptonStruct>& vetoElectrons)
{
    //--- get the number of Electron candidates from the vector size ---
    unsigned short nTotLeptons(patElecEta_->size());

    // if we don't really care to match both leptons to trigger
    bool eventTrigger = false;
    for (unsigned short i(0); i < nTotLeptons; i++){
        int whichTrigger(patElecTrig_->at(i));
        if (lepSel == "DE" && (whichTrigger & 0x2)) eventTrigger = true;      // HLT_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v
        else if (lepSel == "SE" && (whichTrigger & 0x1)) eventTrigger = true; // HLT_Ele27_WP80_v
    }
    for (unsigned short i(0); i < nTotLeptons; i++){

        leptonStruct ele(patElecPt_->at(i), 
                patElecEta_->at(i), 
                patElecPhi_->at(i), 
                patElecEn_->at(i), 
                patElecCharge_->at(i), 
                patElecID_->at(i), 
                patElecPfIsoRho_->at(i), 
                patElecScEta_->at(i), 
                patElecTrig_->at(i));

        //--- good electrons ---
        bool elePassesPtCut(ele.v.Pt() >= lepPtCutMin);
        bool elePassesEtaCut(fabs(ele.scEta) <= min(1.4442, 0.1*lepEtaCutMax) || (fabs(ele.scEta) >= 1.566 && fabs(ele.scEta) <= 0.1*lepEtaCutMax));
        bool elePassesIdCut(ele.id >= 4); /// 4 is medium ID, 2 is Loose ID
        bool elePassesIsoCut(ele.iso < 0.15);
        bool elePassesAnyTrig(ele.trigger & 0x2);
        if (fileName.Index("Sherpa_Bugra_1_13_UNFOLDING") > 0) elePassesAnyTrig = true;

        //--- veto electrons ---
        bool elePassesVetoPtCut(ele.v.Pt() >= 15);
        bool elePassesVetoEtaCut(fabs(ele.v.Eta()) <= 2.4);
        bool elePassesVetoIdCut(ele.id >= 2); // ele Id
        bool elePassesVetoIsoCut(ele.iso < 0.25);

        // select the good electrons only
        if (elePassesPtCut && elePassesEtaCut && elePassesIdCut && elePassesIsoCut && (!useTriggerCorrection || elePassesAnyTrig || eventTrigger)){
            leptons.push_back(ele);
        }
        // select the veto electrons
        else if (elePassesVetoPtCut && elePassesVetoEtaCut && elePassesVetoIdCut && elePassesVetoIsoCut) {
            vetoElectrons.push_back(ele);
        }

    }//End of loop over all the electrons
}

Bool_t MiniBonzai::Notify()
{
    // The Notify() function is called when a new file is opened. This
    // can be either for a new TTree in a TChain or when when a new TTree
    // is started when using PROOF. It is normally not necessary to make changes
    // to the generated code, but the routine can be extended by the
    // user if needed. The return value is currently not used.

    return kTRUE;
}

void MiniBonzai::Show(Long64_t entry)
{
    // Print contents of entry.
    // If entry is not specified, print current entry
    if (!fChain) return;
    fChain->Show(entry);
}

Int_t MiniBonzai::Cut(Long64_t entry)
{
    // This function may be called from Loop.
    // returns  1 if entry is accepted.
    // returns -1 otherwise.
    printf("entry %lld",entry);
    return 1;
}
