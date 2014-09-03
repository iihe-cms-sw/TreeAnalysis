#define PI 3.14159265359
#define DEBUG              0
#define PRINTEVENT         0

#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLorentzVector.h>
#include <TDatime.h>
#include <TMath.h>
#include <TRandom3.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "LHAPDF/LHAPDF.h"
#include "functions.h"
#include "standalone_LumiReWeighting.h"
#include "HistoSetZJets.h"
#include "ZJets.h"


using namespace std;

void ZJets::Loop(bool hasRecoInfo, bool hasGenInfo, string pdfSet, int pdfMember)
{

    //--- Initialize PDF from LHAPDF if needed ---
    if (pdfSet != "") {
        LHAPDF::initPDFSet(1, pdfSet.c_str(), pdfMember);
        //LHAPDF::initPDFSet(1, "CT10.LHgrid");
        LHAPDF::initPDFSet(2, "cteq6ll.LHpdf");
        const int numberPDFS(LHAPDF::numberPDF(1) + 1);
        if (pdfMember > numberPDFS) {
            std::cout << "Warning pdfMember to high" << std::endl;
            return;
        }
    }
    //--------------------------------------------

    //--- Counters to check the yields ---
    unsigned int nEvents(0), nEventsIncl0Jets(0), nEventsUNFOLDIncl0Jets(0);
    unsigned int nEventsWithTwoGoodLeptonsNoChargeNoMass(0), nEventsWithTwoGoodLeptonsNoMass(0), nEventsWithTwoGoodLeptons(0);
    unsigned int nEventsExcl0Jets(0), nEventsExcl1Jets(0), nEventsExcl2Jets(0), nEventsExcl3Jets(0);
    unsigned int GENnEventsIncl0Jets(0), GENnEventsIncl1Jets(0), GENnEventsIncl2Jets(0), GENnEventsIncl3Jets(0);
    unsigned int NZtotal = 0;
    double TotalGenWeight(0.), TotalGenWeightPassGEN(0.), TotalGenWeightPassGENPU(0.), TotalGenWeightPassRECO(0.), TotalRecoWeightPassRECO(0.);
    //------------------------------------


    //==========================================================================================================//
    int ZMCutLow(71), ZMCutHigh(111);
    // additional variables
    double ZptRange[6] = {0, 40, 80, 120, 160, 1000};
    int LeptonID(11);
    if (leptonFlavor == "Muons") LeptonID = 13;
    

    //==========================================================================================================//
    //         Output file name           //
    //===================================//
    string outputFileName = CreateOutputFileName(pdfSet, pdfMember);
    TFile *outputFile = new TFile(outputFileName.c_str(), "RECREATE");
    //==========================================================================================================//

    //--- weight variable ---
    double weight(1.);
    double genWeight(1.);
    //-----------------------


    if (DEBUG) cout << "Stop after line " << __LINE__ << endl;
    //==========================================================================================================//
    //       Load efficiency tables        //
    //====================================//
    table TableJESunc("EfficiencyTables/JESUnce_FT_53_V21_AN4_Uncertainty_AK5PFchs.txt");
    table LeptIso, LeptID, LeptTrig, Ele_Rec;
    // electron SF
    table Ele_Rec_8TeV("EfficiencyTables/Ele_SF_Reconstruction_2012.txt");
    table SC_Ele_2012EA("EfficiencyTables/Ele_SF_EA2012.txt");
    // muon SF
    table TrigMu17Mu8SF("EfficiencyTables/Efficiency_SF_Mu17Mu8.txt");
    table SC_RunABCD_TightID("EfficiencyTables/Muon_IDTight_Efficiencies_Run_2012ABCD_53X_Eta_Pt.txt");
    table SC_RunABCD_LooseIso("EfficiencyTables/Muon_ISOLoose_forTight_Efficiencies_Run_2012ABCD_53X_Eta_Pt.txt");

    LeptID = SC_RunABCD_TightID;
    LeptIso = SC_RunABCD_LooseIso;
    LeptTrig = TrigMu17Mu8SF;
    Ele_Rec = Ele_Rec_8TeV;
    if (leptonFlavor == "Electrons") LeptID = SC_Ele_2012EA;
    //==========================================================================================================//


    if (DEBUG) cout << "Stop after line " << __LINE__ << endl;
    //==========================================================================================================//
    //     Systematics: jec, pu, xsec     //
    //====================================//
    cout << "Lepton Flavor: " << leptonFlavor << endl;
    int puYear(2013); 
    cout << "Pile Up Distribution: " << puYear << endl;
    standalone_LumiReWeighting puWeight(leptonFlavor, puYear), puUp(leptonFlavor, puYear, 1), puDown(leptonFlavor, puYear, -1);
    cout << "systematics: " << systematics << "  direction: " << direction << endl;

    if (systematics == 1 && direction ==  1) puWeight = puUp;
    if (systematics == 1 && direction == -1) puWeight = puDown;

    int scale(0); //0,+1,-1; (keep 0 for noJEC shift study)
    if (systematics == 2 && direction ==  1) scale =  1;
    if (systematics == 2 && direction == -1) scale = -1;

    double xsec(1.);
    if (systematics == 3 && direction ==  1) xsec = 1. + xsecfactor;
    if (systematics == 3 && direction == -1) xsec = 1. - xsecfactor;

    int smearJet(0);
    if (systematics == 4 && direction ==  1) smearJet =  1; 
    if (systematics == 4 && direction == -1) smearJet = -1; 

    int smearLepSF(0);
    if (systematics == 5 && direction ==  1) smearLepSF = 1;
    if (systematics == 5 && direction == -1) smearLepSF = -1;



    //==========================================================================================================//



    // setting weight when running on MIX of exclusive DY/WJets files to match number of parton events
    double mixingWeightsDY[4] = {0.192686, 0.0718097, 0.04943495, 0.0360337}; // here we match all partons, and combine electron and muon side

    //==========================================================================================================//
    // Start looping over all the events //
    //===================================//
    cout << endl;
    printf("\nProcessing : %s    -->   %s \n", fileName.c_str(), outputFileName.c_str()); 

    //--- Initialize the tree branches ---
    Init(hasRecoInfo, hasGenInfo);
    if (fChain == 0) return;
    Long64_t nentries = fChain->GetEntries();
    if (do10000Events) nentries = 10000;
    
    std::cout << "We will run on " << nentries << " events" << std::endl;
    //------------------------------------

    for (Long64_t jentry(0); jentry < nentries; jentry += 1){
        Long64_t ientry = LoadTree(jentry);
        if (ientry < 0) break;

        if (jentry % 100000 == 0) std::cout << jentry << std::endl;
        fChain->GetEntry(jentry);  
        nEvents++;

        //=======================================================================================================//
        //         Continue Statements        //
        //====================================//
        //if (jentry % 2 == 0) continue;
        //if (EvtInfo_NumVtx <= 14) continue;
        //if (PRINTEVENT && EvtInfo_RunNum != 190733) continue ;

        //=======================================================================================================//


        if (DEBUG) cout << "Stop after line " << __LINE__ << endl;
        //=======================================================================================================//
        //         Computing weight           //
        //====================================//
        weight = 1.;
        // for data PU_npT == -2
        // line below is to see distributions as provided with default MC PU distribution
        if (hasRecoInfo && PU_npT > 0) weight *= puWeight.weight(int(PU_npT));

        if (weight > 10000 || weight < 0) {
            cout << "Oopss such a big weight " << weight << endl;
            weight = 1;
        }
        weight *= lumiScale * xsec;

        if (fileName.find("DYJets") != string::npos && fileName.find("MIX") != string::npos && nup_ > 5) weight *= mixingWeightsDY[nup_ - 6]; 
        

        //==========================================================================================================//
        // Compute the weight for PDF syst   //
        //===================================//
        //-- get the pdgId of the two colliding partons 
        double wPdf(1);
        if (pdfSet != "") {
            int id1 = pdfInfo_->at(0);
            int id2 = pdfInfo_->at(1);
            if (id1 == 21) id1 = 0; // 21 is Pythia convention for gluon, but needs to be 0 for LHAPDF
            if (id2 == 21) id2 = 0;

            double pdf1  = LHAPDF::xfx(1, pdfInfo_->at(2), pdfInfo_->at(4), id1);
            double pdf2  = LHAPDF::xfx(1, pdfInfo_->at(3), pdfInfo_->at(4), id2);
            double pdf01 = LHAPDF::xfx(2, pdfInfo_->at(2), pdfInfo_->at(4), id1);
            double pdf02 = LHAPDF::xfx(2, pdfInfo_->at(3), pdfInfo_->at(4), id2);

            if (pdfInfo_->at(2) * pdfInfo_->at(3) > 0) {
                wPdf = pdf1 * pdf2;
                if (pdf01*pdf02 <= 0 || pdf1*pdf2 <= 0) {
                    cout << "Small problem" << endl;
                    wPdf = 1;
                }
                else {
                    wPdf /= (pdf01 * pdf02);
                }
            }
        }
        //==========================================================================================================//

        //--- There is no pile-up so no need to reweight for that ---
        genWeight = weight * wPdf;
        double genWeightBackup(genWeight);
        TotalGenWeight += genWeightBackup;
        //=======================================================================================================//


        if (DEBUG) cout << "Stop after line " << __LINE__ << endl;
        //=======================================================================================================//
        //         Retrieving leptons           //
        //====================================//
        bool doMuons(leptonFlavor == "Muons");
        bool doElectrons(leptonFlavor == "Electrons");
        bool passesLeptonCut(0);
        unsigned short nTotLeptons(0), nLeptons(0);
        vector<leptonStruct> leptons;
        TLorentzVector lep1, lep2, Z;

        if (hasRecoInfo) {

            //--- DO MUONS ---
            if (doMuons){
                nTotLeptons = patMuonEta_->size();
                for (unsigned short i(0); i < nTotLeptons; i++) {
                    leptonStruct mu = {patMuonPt_->at(i), patMuonEta_->at(i), patMuonPhi_->at(i), patMuonEn_->at(i), patMuonCharge_->at(i), patMuonPfIsoDbeta_->at(i), patMuonEta_->at(i)};
                    int whichTrigger(patMuonTrig_->at(i));
                    bool muPassesPtCut(mu.pt >= 20.);
                    bool muPassesEtaCut(fabs(mu.eta) <= 2.4);
                    bool muPassesIdCut(int(patMuonCombId_->at(i)) & 0x1);

                    bool muPassesIsoCut(patMuonPfIsoDbeta_->at(i) < 0.2);  
                    bool muPassesAnyTrig(whichTrigger & 0x8); // 8TeV comment: Mu17Mu8Tk = 4; Mu17Mu8 = 8 
                    /// for files obtained form bugra
                    if (fileName.find("DYJets_Sherpa_UNFOLDING_dR_5311") != string::npos && whichTrigger > 0) muPassesAnyTrig = 1; // Bugra only keeps the double electron trigger !!!!! 

                    // select the good muons only
                    if (muPassesPtCut && muPassesEtaCut && muPassesIdCut && muPassesIsoCut && (!useTriggerCorrection || muPassesAnyTrig)) {
                        leptons.push_back(mu); 
                    }
                }//End of loop over all the muons
            }

            //--- DO ELECTRONS -------
            bool eventTrigger = false;
            if (doElectrons) {
                nTotLeptons = 0;
                nTotLeptons = patElecEta_->size();
                // if we don't really care to match both leptons to trigger
                for (unsigned short i(0); i < nTotLeptons; i++){
                    int whichTrigger(patElecTrig_->at(i));
                    if (whichTrigger & 0x2) eventTrigger = true;
                }
                for (unsigned short i(0); i < nTotLeptons; i++){
                    leptonStruct ele = {patElecPt_->at(i), patElecEta_->at(i), patElecPhi_->at(i), patElecEn_->at(i),  patElecCharge_->at(i), 0., patElecScEta_->at(i)};
                    int whichTrigger(patElecTrig_->at(i));
                    bool elePassesPtCut(ele.pt >= 20.);
                    bool elePassesEtaCut(fabs(patElecScEta_->at(i)) <= 1.4442 || (fabs(patElecScEta_->at(i)) >= 1.566 && fabs(patElecScEta_->at(i)) <= 2.4));
                    bool elePassesIdCut(int(patElecID_->at(i)) >= 4); /// 4 is medium ID; 2 is Loose ID
                    bool elePassesIsoCut(patElecPfIsoRho_->at(i) < 0.15);
                    bool elePassesAnyTrig(whichTrigger & 0x2);

                    // select the good electrons only
                    if (elePassesPtCut && elePassesEtaCut && elePassesIdCut && elePassesIsoCut && (!useTriggerCorrection || elePassesAnyTrig || eventTrigger)){
                        leptons.push_back(ele);
                    }
                }//End of loop over all the electrons
            }

            nLeptons = leptons.size();

            //-- determine if the event passes the leptons requirements for Z Boson
            if (nLeptons >= 2){
                // sort leptons by descending pt
                sort(leptons.begin(), leptons.end(), LepDescendingOrder);

                lep1.SetPtEtaPhiE(leptons[0].pt, leptons[0].eta, leptons[0].phi, leptons[0].energy);
                lep2.SetPtEtaPhiE(leptons[1].pt, leptons[1].eta, leptons[1].phi, leptons[1].energy);
                Z = lep1 + lep2;

                // apply charge, mass and eta cut
                if (leptons[0].charge * leptons[1].charge < 0 && Z.M() > ZMCutLow && Z.M() < ZMCutHigh) passesLeptonCut = 1;

                // apply only scale factors.
                if (!isData) {
                    double effWeight = 1.;
                    if (leptonFlavor == "Muons") {
                        effWeight *= LeptID.getEfficiency(leptons[0].pt, fabs(leptons[0].eta));
                        effWeight *= LeptID.getEfficiency(leptons[1].pt, fabs(leptons[1].eta));
                        effWeight *= LeptIso.getEfficiency(leptons[0].pt, fabs(leptons[0].eta)); 
                        effWeight *= LeptIso.getEfficiency(leptons[1].pt, fabs(leptons[1].eta)); 

                        if (useTriggerCorrection) effWeight *= LeptTrig.getEfficiency(fabs(leptons[0].eta), fabs(leptons[1].eta));

                    }
                    else if (leptonFlavor == "Electrons") {
                        if (smearLepSF == 0) {
                            effWeight *= Ele_Rec.getEfficiency(leptons[0].pt, fabs(leptons[0].scEta));
                            effWeight *= Ele_Rec.getEfficiency(leptons[1].pt, fabs(leptons[1].scEta));
                            effWeight *= LeptID.getEfficiency(leptons[0].pt, fabs(leptons[0].scEta));
                            effWeight *= LeptID.getEfficiency(leptons[1].pt, fabs(leptons[1].scEta)); 
                        }
                        else if (smearLepSF == -1) {
                            effWeight *= Ele_Rec.getEfficiencyLow(leptons[0].pt, fabs(leptons[0].scEta));
                            effWeight *= Ele_Rec.getEfficiencyLow(leptons[1].pt, fabs(leptons[1].scEta));
                            effWeight *= LeptID.getEfficiencyLow(leptons[0].pt, fabs(leptons[0].scEta));
                            effWeight *= LeptID.getEfficiencyLow(leptons[1].pt, fabs(leptons[1].scEta)); 
                        }
                        else if (smearLepSF == 1) {
                            effWeight *= Ele_Rec.getEfficiencyHigh(leptons[0].pt, fabs(leptons[0].scEta));
                            effWeight *= Ele_Rec.getEfficiencyHigh(leptons[1].pt, fabs(leptons[1].scEta));
                            effWeight *= LeptID.getEfficiencyHigh(leptons[0].pt, fabs(leptons[0].scEta));
                            effWeight *= LeptID.getEfficiencyHigh(leptons[1].pt, fabs(leptons[1].scEta)); 
                        }
                    }
                    weight *= effWeight;
                }

            } // end if nLeptons>=2

        }// end has reco info


        if (DEBUG) std::cout << "Stop after line " << __LINE__ << std::endl;
        //=======================================================================================================//
        //       Retrieving gen leptons        //
        //====================================//
        bool passesGenLeptonCut(0);
        unsigned short nTotGenLeptons(0), nGenLeptons(0), nTotGenPhotons(0);
        vector<leptonStruct> genLeptons;
        vector<int> usedGenPho;
        TLorentzVector genLep1, genLep2, genZ;
        int countTauS3 = 0;
        int nTauWithStatus3 = 0;

        if (hasGenInfo) {
            if (hasRecoInfo) countTauS3 = 2;
            nTotGenPhotons = genPhoEta_->size();
            nTotGenLeptons = genLepEta_->size();
            //-- retriveing generated leptons with status 1
            for (unsigned short i(0); i < nTotGenLeptons; i++) {
                // following two lines should give the same result
                if (genLepSt_->at(i) == 3 && abs(genLepId_->at(i)) != LeptonID && (abs(genLepId_->at(i)) == 15 || abs(genLepId_->at(i)) == 13 || abs(genLepId_->at(i)) == 11)) countTauS3++;
                if (genLepSt_->at(i) == 3 && abs(genLepId_->at(i)) == LeptonID) countTauS3--;

                if (genLepSt_->at(i) == 3 && abs(genLepId_->at(i)) == 15) nTauWithStatus3++;

                if (abs(genLepId_->at(i)) != LeptonID) continue;

                leptonStruct genLep = {genLepPt_->at(i), genLepEta_->at(i), genLepPhi_->at(i), genLepE_->at(i), genLepQ_->at(i), 0., 0.};
                leptonStruct genLepNoFSR = {genLepPt_->at(i), genLepEta_->at(i), genLepPhi_->at(i), genLepE_->at(i), genLepQ_->at(i), 0., 0.};

                //-- dress the leptons with photon (cone size = 0.1). Only for status 1 leptons (after FSR)
                if (genLepSt_->at(i) == 1 &&  abs(genLepId_->at(i)) == LeptonID) {
                    TLorentzVector tmpGenLep;
                    tmpGenLep.SetPtEtaPhiE(genLep.pt, genLep.eta, genLep.phi, genLep.energy);
                    for (unsigned short j(0); j < nTotGenPhotons; j++){
                        TLorentzVector tmpGenPho;
                        tmpGenPho.SetPtEtaPhiM(genPhoPt_->at(j), genPhoEta_->at(j), genPhoPhi_->at(j), 0.);
                        int used(0);
                        for (unsigned short k(0); k < usedGenPho.size(); k++){
                            if (j == usedGenPho[k]) used = 1;
                        }
                        if (deltaR(tmpGenPho.Phi(), tmpGenPho.Eta(), genLepNoFSR.phi, genLepNoFSR.eta) < 0.1 && !used){
                            tmpGenLep += tmpGenPho;
                            usedGenPho.push_back(j);
                        }
                    }   
                    genLep.pt = tmpGenLep.Pt(); 
                    genLep.eta = tmpGenLep.Eta(); 
                    genLep.phi = tmpGenLep.Phi();
                    genLep.energy = tmpGenLep.E();
                    if (genLep.pt >= 20 && fabs(genLep.eta) <= 2.4) {
                        genLeptons.push_back(genLep);
                    }
                }
            }
            nGenLeptons = genLeptons.size();

            if (countTauS3 == 0 && fileName.find("UNFOLDING") != string::npos) {
                partonsN->Fill(nup_-5);
                partonsNWeighted->Fill(nup_-5, genWeight);
            }

            //--- if there are taus, but we do not run on the Tau file, thus we run on the DYJets file, 
            //    then we don't count the event at reco.
            if (countTauS3 > 0 && fileName.find("Tau") == string::npos) passesLeptonCut = 0; 

            //-- determine if the event passes the leptons requirements
            if (nGenLeptons >= 2){
                // sort leptons by descending pt
                sort(genLeptons.begin(), genLeptons.end(), LepDescendingOrder);

                // build the TLorentzVectors, the Z candidate and the kinematic
                genLep1.SetPtEtaPhiE(genLeptons[0].pt, genLeptons[0].eta, genLeptons[0].phi, genLeptons[0].energy);
                genLep2.SetPtEtaPhiE(genLeptons[1].pt, genLeptons[1].eta, genLeptons[1].phi, genLeptons[1].energy);

                genZ = genLep1 + genLep2;

                // apply charge, mass and eta cut
                if (genLeptons[0].charge * genLeptons[1].charge < 0 && genZ.M() > ZMCutLow && genZ.M() < ZMCutHigh) {
                    passesGenLeptonCut = 1;
                }
                //--- if there are taus we don't want the gen level
                if (countTauS3 > 0) passesGenLeptonCut = 0;
            }
        }

        if (passesGenLeptonCut) {
            TotalGenWeightPassGEN += genWeightBackup; 
            TotalGenWeightPassGENPU += weight;
            partonsNAfterGenCut->Fill(nup_ - 5); 
            partonsNAfterGenCutWeighted->Fill(nup_ - 5, genWeight); 
        }
        //=======================================================================================================//


        if (DEBUG) cout << "Stop after line " << __LINE__ << endl;
        //=======================================================================================================//
        //          Retrieving jets           //
        //====================================//
        unsigned short nGoodJets(0), nGoodJets_20(0), nTotJets(0);
        double jetsHT(0);
        vector<jetStruct> jets;
        vector<jetStruct> jets_20;
        TLorentzVector leadJ, secondJ, jet1Plus2, jet1Minus2;
        TLorentzVector leadJ_20, secondJ_20, jet1Plus2_20, jet1Minus2_20;

        if (hasRecoInfo) {
            nTotJets = patJetPfAk05Eta_->size();
            for (unsigned short i(0); i < nTotJets; i++) {
                jetStruct jet = {patJetPfAk05Pt_->at(i), patJetPfAk05Eta_->at(i), patJetPfAk05Phi_->at(i), patJetPfAk05En_->at(i), i, 0};

                //-- apply jet energy scale uncertainty (need to change the scale when initiating the object)
                double jetEnergyCorr = 0.; 
                bool jetPassesPtCut(jet.pt >= 10); 
                jetEnergyCorr = TableJESunc.getEfficiency(jet.pt, jet.eta);

                jet.pt *= (1 + scale * jetEnergyCorr);
                jet.energy *= (1 + scale * jetEnergyCorr);

                bool jetPassesEtaCut(fabs(jet.eta) <= 0.1*jetEtaCutMax); 
                bool jetPassesIdCut(patJetPfAk05LooseId_->at(i) > 0);
                bool jetPassesMVACut(patJetPfAk05jetpuMVA_->at(i) > 0);

                bool jetPassesdRCut(1);
                unsigned short nRemovedLep = min(int(nLeptons), 2);
                for (unsigned short j(0); j < nRemovedLep; j++) {
                    if (deltaR(jet.phi, jet.eta, leptons[j].phi, leptons[j].eta) < 0.5) {
                        jetPassesdRCut = 0;
                    }
                }

                if (jetPassesPtCut && jetPassesEtaCut && jetPassesIdCut && jetPassesMVACut && jetPassesdRCut) {
                    jets.push_back(jet);
                    jets_20.push_back(jet);
                }
            } //End of loop over all the jets 


            nGoodJets = jets.size();
            nGoodJets_20 = jets_20.size();

            // line below to test reco events that originate from TAU
            if (fileName.find("Tau") != string::npos && countTauS3 == 0 && hasGenInfo) {
                passesLeptonCut = 0;
            }
        }  // END IF HAS RECO
        //=======================================================================================================//


        if (DEBUG) cout << "Stop after line " << __LINE__ << endl;
        //=======================================================================================================//
        //        Print Event Information     //
        //====================================//
        if (PRINTEVENT && passesLeptonCut){
            vector<jetStruct> tmpJets;
            for (unsigned short i(0); i < nGoodJets; i++){
                if (jets[i].pt >= jetPtCutMin) tmpJets.push_back(jets[i]);
            }
            //unsigned short tempnGoodJets(tmpJets.size());
            NZtotal++;
            cout << EvtInfo_RunNum << ":" << EvtInfo_EventNum << ":" << weight << endl;
            //cout << "event " << EvtInfo_EventNum;
            //cout << "Z event #" << NZtotal << "  Zmass : " << Z.M() << "  Zpt : " << Z.Pt() << " NJets : " << tempnGoodJets <<"    " <<weight << endl;
            //if (nGoodJets > 0) cout << "JETS:"<< endl;
            //for (unsigned short i(0); i < tempnGoodJets; i++) 
            //    cout << " jet #" << i + 1 << "  pt: " << tmpJets[i].pt << "  eta:"<<tmpJets[i].eta << "   " << endl;
            //cout << "-----------------------------------------------------------------------------------------"<< endl;
        }
        //=======================================================================================================//


        if (DEBUG) cout << "Stop after line " << __LINE__ << endl;
        //=======================================================================================================//
        //        Retrieving gen jets          //
        //====================================//
        bool passesGenJetCut(1);
        unsigned short nGoodGenJets(0), nGoodGenJets_20(0), nTotGenJets(0);
        double genJetsHT(0);
        vector<jetStruct> genJets;
        vector<jetStruct> genJets_20;
        TLorentzVector genLeadJ, genSecondJ, genJet1Plus2, genJet1Minus2;
        TLorentzVector genLeadJ_20, genSecondJ_20, genJet1Plus2_20, genJet1Minus2_20;

        if (hasGenInfo){
            nTotGenJets = genJetEta_->size();
            //-- retrieving generated jets
            for (unsigned short i(0); i < nTotGenJets; i++){
                jetStruct genJet = {genJetPt_->at(i), genJetEta_->at(i), genJetPhi_->at(i), genJetE_->at(i), i, 0};
                bool genJetPassesdRCut(1);
                for (unsigned short j(0); j < nGenLeptons; j++){ 
                    if (deltaR(genJet.phi, genJet.eta, genLeptons[j].phi, genLeptons[j].eta) < 0.5){
                        genJetPassesdRCut = 0;
                    }
                }
                if (genJet.pt >= 10 && genJet.pt < 1000. && fabs(genJet.eta) <= 4.7 && genJetPassesdRCut){
                    genJets.push_back(genJet);                  
                }
            }
            nGoodGenJets = genJets.size();

        }
        //=======================================================================================================//



        if (DEBUG) cout << "Stop after line " << __LINE__ << endl;
        //=======================================================================================================//
        //     Matching gen and reco jets     //
        //====================================//
        vector<int> genJetsIndex(nGoodGenJets, 0);
        vector<vector<int> > matchingTable(nGoodJets, genJetsIndex);
        if (hasRecoInfo && hasGenInfo){
            for (unsigned short i(0); i < nGoodJets; i++){
                double mindR(0.15);
                int index(-1);
                double dR(9999);
                for (unsigned short j(0); j < nGoodGenJets; j++){
                    dR = deltaR(genJets[j].phi, genJets[j].eta, jets[i].phi, jets[i].eta);
                    if (dR < mindR){
                        mindR = dR;
                        index = j;
                    }
                }
                if (index > -1 ){
                    matchingTable[i][index] = 1; 
                    double oldJetPt = jets[i].pt;
                    jets[i].pt = SmearJetPt(oldJetPt, genJets[index].pt, jets[i].eta, smearJet);
                    jets[i].energy *= jets[i].pt / oldJetPt; 
                }
            }

            //-- print the mathcing table
            //cout << "\n mathcing Table: \n" << endl; 
            //for (int i = 0; i < int(matchingTable.size()); i++){
            //  for (int j = 0; j < int(matchingTable[i].size()); j++){
            //    cout << matchingTable[i][j] << "  ";
            //  }
            //  cout << endl;
            //}

        }

        //=======================================================================================================//
        // Re-analyze the jets collections and Cut on the Pt    //
        // we can do it only now since we needed to smear      //
        // the jet pt distribution for the MC                 //
        //===================================================//

        if (hasRecoInfo){     
            vector<jetStruct> tmpJets;
            vector<jetStruct> tmpJets_20;
            for (unsigned short i(0); i < nGoodJets; i++){
                if (jets[i].pt >= jetPtCutMin) tmpJets.push_back(jets[i]);
                if (jets[i].pt >= 20) tmpJets_20.push_back(jets[i]);
            }
            jets.clear(); 
            jets = tmpJets; 
            tmpJets.clear(); 
            nGoodJets = jets.size();
            jets_20.clear();
            jets_20 = tmpJets_20;
            nGoodJets_20 = jets_20.size();
            if (nGoodJets >= 1){
                sort(jets.begin(), jets.end(), JetDescendingOrder);
                leadJ.SetPtEtaPhiE(jets[0].pt, jets[0].eta, jets[0].phi, jets[0].energy);               
            }
            if (nGoodJets >= 2){
                secondJ.SetPtEtaPhiE(jets[1].pt, jets[1].eta, jets[1].phi, jets[1].energy);               
                jet1Plus2 = leadJ + secondJ;
                jet1Minus2 = leadJ - secondJ;
            }
            jetsHT = 0;
            for (unsigned short i(0); i < nGoodJets; i++){
                jetsHT += jets[i].pt;  
            }

            if (nGoodJets_20 >= 1){
                sort(jets_20.begin(), jets_20.end(), JetDescendingOrder);
                leadJ_20.SetPtEtaPhiE(jets_20[0].pt, jets_20[0].eta, jets_20[0].phi, jets_20[0].energy);               
            }
            if (nGoodJets_20 >= 2){
                secondJ_20.SetPtEtaPhiE(jets_20[1].pt, jets_20[1].eta, jets_20[1].phi, jets_20[1].energy);               
                jet1Plus2_20 = leadJ_20 + secondJ_20;
                jet1Minus2_20 = leadJ_20 - secondJ_20;
            }
        }

        if (hasGenInfo){
            vector<jetStruct> tmpGenJets;
            vector<jetStruct> tmpGenJets_20;
            for (unsigned short i(0); i < nGoodGenJets; i++){
                if (genJets[i].pt >= jetPtCutMin && fabs(genJets[i].eta) <= 0.1*jetEtaCutMax) tmpGenJets.push_back(genJets[i]);
                if (genJets[i].pt >= 20 && fabs(genJets[i].eta) <= 0.1*jetEtaCutMax) tmpGenJets_20.push_back(genJets[i]);
            }
            genJets.clear();
            genJets = tmpGenJets; 
            tmpGenJets.clear(); 
            nGoodGenJets = genJets.size();
            genJets_20.clear();
            genJets_20 = tmpGenJets_20; 
            tmpGenJets_20.clear(); 
            nGoodGenJets_20 = genJets_20.size();
            if (nGoodGenJets >= 1){
                sort(genJets.begin(), genJets.end(), JetDescendingOrder);
                genLeadJ.SetPtEtaPhiE(genJets[0].pt, genJets[0].eta, genJets[0].phi, genJets[0].energy);               
            }
            if (nGoodGenJets >= 2){
                genSecondJ.SetPtEtaPhiE(genJets[1].pt, genJets[1].eta, genJets[1].phi, genJets[1].energy);               
                genJet1Plus2 = genLeadJ + genSecondJ;
                genJet1Minus2 = genLeadJ - genSecondJ;
            }
            genJetsHT = 0.;
            for (unsigned short i(0); i < nGoodGenJets; i++){
                genJetsHT += genJets[i].pt;  
            }

            if (nGoodGenJets_20 >= 1){
                sort(genJets_20.begin(), genJets_20.end(), JetDescendingOrder);
                genLeadJ_20.SetPtEtaPhiE(genJets_20[0].pt, genJets_20[0].eta, genJets_20[0].phi, genJets_20[0].energy);               
            }
            if (nGoodGenJets_20 >= 2){
                genSecondJ_20.SetPtEtaPhiE(genJets_20[1].pt, genJets_20[1].eta, genJets_20[1].phi, genJets_20[1].energy);               
                genJet1Plus2_20 = genLeadJ_20 + genSecondJ_20;
                genJet1Minus2_20 = genLeadJ_20 - genSecondJ_20;
            }

        }
        //=======================================================================================================//


        if (DEBUG) cout << "Stop after line " << __LINE__ << endl;
        //=======================================================================================================//
        // Select the best pair of jets for DPS  //
        //=======================================//
        pair<TLorentzVector, TLorentzVector> bestTwoJets;
        TLorentzVector bestJet1Plus2, bestJet1Minus2;
        if (hasRecoInfo){
            bestTwoJetsCandidatesPt(jets, bestTwoJets);
            //bestTwoJetsCandidatesPhi(jets, bestTwoJets);
            if (nGoodJets >= 2){
                bestJet1Plus2 = bestTwoJets.first + bestTwoJets.second;
                bestJet1Minus2 = bestTwoJets.first - bestTwoJets.second;
            }
        }

        pair<TLorentzVector, TLorentzVector> genBestTwoJets;
        TLorentzVector genBestJet1Plus2, genBestJet1Minus2;
        if (hasGenInfo){
            bestTwoJetsCandidatesPt(genJets, genBestTwoJets);
            //bestTwoJetsCandidatesPhi(genJets, genBestTwoJets);
            if (nGoodGenJets >= 2){
                genBestJet1Plus2 = genBestTwoJets.first + genBestTwoJets.second; 
                genBestJet1Minus2 = genBestTwoJets.first - genBestTwoJets.second; 
            }
        }
        //=======================================================================================================//



        if (DEBUG) cout << "Stop after line " << __LINE__ << endl;
        //=======================================================================================================//
        //   Filling gen end parton histos    //
        //====================================//

        double gentau_sum(0), gentau_max(0);
        double gentau_c_sum(0), gentau_c_max(0);
        double gentau_cm_sum(0), gentau_cm_max(0);
        double gentau_c_cm_sum(0), gentau_c_cm_max(0); 

        if (hasGenInfo){
            if (passesGenLeptonCut && passesGenJetCut){
                GENnEventsIncl0Jets++;
                genZNGoodJets_Zexc->Fill(nGoodGenJets, genWeight);
                genZNGoodJets_Zinc->Fill(0., genWeight);
                genZMass_Zinc0jet->Fill(genZ.M(), genWeight);
                genZPt_Zinc0jet->Fill(genZ.Pt(), genWeight);
                genZRapidity_Zinc0jet->Fill(genZ.Rapidity(), genWeight);
                genZEta_Zinc0jet->Fill(genZ.Eta(), genWeight);
                genlepPt_Zinc0jet->Fill(genLep1.Pt(), genWeight);
                genlepPt_Zinc0jet->Fill(genLep2.Pt(), genWeight);
                genlepEta_Zinc0jet->Fill(genLep1.Eta(), genWeight);
                genlepEta_Zinc0jet->Fill(genLep2.Eta(), genWeight);

                if (nGoodGenJets_20 >= 1) genFirstJetPt_Zinc1jet->Fill(genLeadJ_20.Pt(), genWeight);
                if (nGoodGenJets >= 1){


                    for (unsigned short i(0); i < nGoodGenJets; i++) {
                        TLorentzVector tmpJet(0, 0, 0, 0);
                        tmpJet.SetPtEtaPhiE(genJets[i].pt, genJets[i].eta, genJets[i].phi, genJets[i].energy);
                        double trans_mass = tmpJet.Mt();

                        gentau_sum += trans_mass * exp(-fabs(tmpJet.Rapidity() - genZ.Rapidity())); 
                        gentau_max = max(gentau_max, trans_mass * exp(-fabs(tmpJet.Rapidity() - genZ.Rapidity()))); 

                        gentau_c_sum += trans_mass / (2 * cosh(tmpJet.Rapidity() - genZ.Rapidity()));
                        gentau_c_max = max(gentau_c_max, trans_mass / (2 * cosh(tmpJet.Rapidity() - genZ.Rapidity())));

                        gentau_cm_sum += trans_mass * exp(-fabs(tmpJet.Rapidity())); 
                        gentau_cm_max = max(gentau_cm_max, trans_mass * exp(-fabs(tmpJet.Rapidity()))); 

                        gentau_c_cm_sum += trans_mass / (2 * cosh(tmpJet.Rapidity()));
                        gentau_c_cm_max = max(gentau_c_cm_max, trans_mass / (2 * cosh(tmpJet.Rapidity())));

                    }


                    for (unsigned short i(0); i < 5; i++) {
                        if (genZ.Pt() > ZptRange[i] && genZ.Pt() <= ZptRange[i+1]) {
                            gentau_sum_Zinc1jet[i]->Fill(gentau_sum, genWeight);
                            gentau_max_Zinc1jet[i]->Fill(gentau_max, genWeight);
                            gentau_c_sum_Zinc1jet[i]->Fill(gentau_c_sum, genWeight);
                            gentau_c_max_Zinc1jet[i]->Fill(gentau_c_max, genWeight);
                            gentau_cm_sum_Zinc1jet[i]->Fill(gentau_cm_sum, genWeight);
                            gentau_cm_max_Zinc1jet[i]->Fill(gentau_cm_max, genWeight);
                            gentau_c_cm_sum_Zinc1jet[i]->Fill(gentau_c_cm_sum, genWeight);
                            gentau_c_cm_max_Zinc1jet[i]->Fill(gentau_c_cm_max, genWeight);
                        }
                    }

                    GENnEventsIncl1Jets++;
                    genZNGoodJets_Zinc->Fill(1., genWeight);
                    genZPt_Zinc1jet->Fill(genZ.Pt(), genWeight);
                    genZRapidity_Zinc1jet->Fill(genZ.Rapidity(), genWeight);
                    genZEta_Zinc1jet->Fill(genZ.Eta(), genWeight);
                    genFirstJetEta_Zinc1jet->Fill(fabs(genLeadJ.Eta()), genWeight);
                    genJetsHT_Zinc1jet->Fill(genJetsHT, genWeight);
                    if (nGoodGenJets == 1){
                        genFirstJetPt_Zexc1jet->Fill(genLeadJ.Pt(), genWeight);
                    }
                }
                if (nGoodGenJets_20 >= 2) genSecondJetPt_Zinc2jet->Fill(genSecondJ_20.Pt(), genWeight);
                if (nGoodGenJets >= 2) {
                    TLorentzVector genJet1Plus2PlusZ = genJet1Plus2 + genZ;
                    GENnEventsIncl2Jets++;
                    genZNGoodJets_Zinc->Fill(2., genWeight);
                    genTwoJetsPtDiff_Zinc2jet->Fill(genJet1Minus2.Pt(), genWeight);
                    genBestTwoJetsPtDiff_Zinc2jet->Fill(genBestJet1Minus2.Pt(), genWeight);
                    genJetsMass_Zinc2jet->Fill(genJet1Plus2.M(), genWeight);
                    genZPt_Zinc2jet->Fill(genZ.Pt(), genWeight);
                    genZRapidity_Zinc2jet->Fill(genZ.Rapidity(), genWeight);
                    genZEta_Zinc2jet->Fill(genZ.Eta(), genWeight);
                    genSecondJetEta_Zinc2jet->Fill(fabs(genSecondJ.Eta()), genWeight);
                    genJetsHT_Zinc2jet->Fill(genJetsHT, genWeight);
                    genptBal_Zinc2jet->Fill(genJet1Plus2PlusZ.Pt(), genWeight);
                    gendPhiJets_Zinc2jet->Fill(deltaPhi(genLeadJ, genSecondJ), genWeight);
                    genBestdPhiJets_Zinc2jet->Fill(deltaPhi(genBestTwoJets.first, genBestTwoJets.second), genWeight);
                    gendEtaJets_Zinc2jet->Fill(genLeadJ.Eta() - genSecondJ.Eta(), genWeight);
                    gendEtaFirstJetZ_Zinc2jet->Fill(genLeadJ.Eta() - genZ.Eta(), genWeight);
                    gendEtaSecondJetZ_Zinc2jet->Fill(genSecondJ.Eta() - genZ.Eta(), genWeight);
                    gendEtaJet1Plus2Z_Zinc2jet->Fill(genJet1Plus2.Eta() - genZ.Eta(), genWeight);
                    genPHI_Zinc2jet->Fill(PHI(genLep1, genLep2, genLeadJ, genSecondJ), genWeight);
                    genBestPHI_Zinc2jet->Fill(PHI(genLep1, genLep2, genBestTwoJets.first, genBestTwoJets.second), genWeight);
                    genPHI_T_Zinc2jet->Fill(PHI_T(genLep1, genLep2, genLeadJ, genSecondJ), genWeight);
                    genBestPHI_T_Zinc2jet->Fill(PHI_T(genLep1, genLep2, genBestTwoJets.first, genBestTwoJets.second), genWeight);
                    genSpT_Zinc2jet->Fill(SpT(genLep1, genLep2, genLeadJ, genSecondJ), genWeight);
                    genBestSpT_Zinc2jet->Fill(SpT(genLep1, genLep2, genBestTwoJets.first, genBestTwoJets.second), genWeight);
                    genSpTJets_Zinc2jet->Fill(SpTsub(genLeadJ, genSecondJ), genWeight);
                    genBestSpTJets_Zinc2jet->Fill(SpTsub(genBestTwoJets.first, genBestTwoJets.second), genWeight);
                    genSpTLeptons_Zinc2jet->Fill(SpTsub(genLep1, genLep2), genWeight);
                    genSPhi_Zinc2jet->Fill(SPhi(genLep1, genLep2, genLeadJ, genSecondJ), genWeight);
                    genBestSPhi_Zinc2jet->Fill(SPhi(genLep1, genLep2, genBestTwoJets.first, genBestTwoJets.second), genWeight);

                    if (genZ.Pt() < 25){
                        genptBal_LowPt_Zinc2jet->Fill(genJet1Plus2PlusZ.Pt(), genWeight);
                        gendPhiJets_LowPt_Zinc2jet->Fill(deltaPhi(genLeadJ, genSecondJ), genWeight);
                        genBestdPhiJets_LowPt_Zinc2jet->Fill(deltaPhi(genBestTwoJets.first, genBestTwoJets.second), genWeight);
                        genPHI_T_LowPt_Zinc2jet->Fill(PHI_T(genLep1, genLep2, genLeadJ, genSecondJ), genWeight);
                        genBestPHI_T_LowPt_Zinc2jet->Fill(PHI_T(genLep1, genLep2, genBestTwoJets.first, genBestTwoJets.second), genWeight);
                        genPHI_LowPt_Zinc2jet->Fill(PHI(genLep1, genLep2, genLeadJ, genSecondJ), genWeight);
                        genBestPHI_LowPt_Zinc2jet->Fill(PHI(genLep1, genLep2, genBestTwoJets.first, genBestTwoJets.second), genWeight);
                        genSpTJets_LowPt_Zinc2jet->Fill(SpTsub(genLeadJ, genSecondJ), genWeight);
                        genBestSpTJets_LowPt_Zinc2jet->Fill(SpTsub(genBestTwoJets.first, genBestTwoJets.second), genWeight);
                        genSpTLeptons_LowPt_Zinc2jet->Fill(SpTsub(genLep1, genLep2), genWeight);
                        genSpT_LowPt_Zinc2jet->Fill(SpT(genLep1, genLep2, genLeadJ, genSecondJ), genWeight);
                        genBestSpT_LowPt_Zinc2jet->Fill(SpT(genLep1, genLep2, genBestTwoJets.first, genBestTwoJets.second), genWeight);
                        genSPhi_LowPt_Zinc2jet->Fill(SPhi(genLep1, genLep2, genLeadJ, genSecondJ), genWeight);
                        genBestSPhi_LowPt_Zinc2jet->Fill(SPhi(genLep1, genLep2, genBestTwoJets.first, genBestTwoJets.second), genWeight);
                        if (SpT(genLep1, genLep2, genLeadJ, genSecondJ) < 0.5){ 
                            genPHI_LowSpT_LowPt_Zinc2jet->Fill(PHI(genLep1, genLep2, genLeadJ, genSecondJ), genWeight);
                            genSPhi_LowSpT_LowPt_Zinc2jet->Fill(SPhi(genLep1, genLep2, genLeadJ, genSecondJ), genWeight);
                        }
                        else {
                            genPHI_HighSpT_LowPt_Zinc2jet->Fill(PHI(genLep1, genLep2, genLeadJ, genSecondJ), genWeight);
                            genSPhi_HighSpT_LowPt_Zinc2jet->Fill(SPhi(genLep1, genLep2, genLeadJ, genSecondJ), genWeight);
                        }
                        if (SPhi(genLep1, genLep2, genLeadJ, genSecondJ) < 0.5){
                            genSpT_LowSPhi_LowPt_Zinc2jet->Fill(SpT(genLep1, genLep2, genLeadJ, genSecondJ), genWeight);
                        }
                        else {
                            genSpT_HighSPhi_LowPt_Zinc2jet ->Fill(SpT(genLep1, genLep2, genLeadJ, genSecondJ), genWeight);
                        }
                    }
                    else {
                        genptBal_HighPt_Zinc2jet->Fill(genJet1Plus2PlusZ.Pt(), genWeight);
                        gendPhiJets_HighPt_Zinc2jet->Fill(deltaPhi(genLeadJ, genSecondJ), genWeight);
                        genPHI_HighPt_Zinc2jet->Fill(PHI(genLep1, genLep2, genLeadJ, genSecondJ), genWeight);
                        genPHI_T_HighPt_Zinc2jet->Fill(PHI_T(genLep1, genLep2, genLeadJ, genSecondJ), genWeight);
                        genSpTJets_HighPt_Zinc2jet->Fill(SpTsub(genLeadJ, genSecondJ), genWeight);
                        genSpTLeptons_HighPt_Zinc2jet->Fill(SpTsub(genLep1, genLep2), genWeight);
                        genSpT_HighPt_Zinc2jet->Fill(SpT(genLep1, genLep2, genLeadJ, genSecondJ), genWeight);
                        genSPhi_HighPt_Zinc2jet->Fill(SPhi(genLep1, genLep2, genLeadJ, genSecondJ), genWeight);
                    }
                    if (nGoodGenJets == 2){
                        genTwoJetsPtDiff_Zexc2jet->Fill(genJet1Minus2.Pt(), genWeight);
                        genJetsMass_Zexc2jet->Fill(genJet1Plus2.M(), genWeight);
                        genSecondJetPt_Zexc2jet->Fill(genSecondJ.Pt(), genWeight);
                        gendPhiJets_Zexc2jet->Fill(deltaPhi(genLeadJ, genSecondJ), genWeight);
                        genPHI_Zexc2jet->Fill(PHI(genLep1, genLep2, genLeadJ, genSecondJ), genWeight);
                        genPHI_T_Zexc2jet->Fill(PHI_T(genLep1, genLep2, genLeadJ, genSecondJ), genWeight);
                        gendEtaJets_Zexc2jet->Fill(genLeadJ.Eta() - genSecondJ.Eta(), genWeight);
                        gendEtaFirstJetZ_Zexc2jet->Fill(genLeadJ.Eta() - genZ.Eta(), genWeight);
                        gendEtaSecondJetZ_Zexc2jet->Fill(genSecondJ.Eta() - genZ.Eta(), genWeight);
                        gendEtaJet1Plus2Z_Zexc2jet->Fill(genJet1Plus2.Eta() - genZ.Eta(), genWeight);
                        genSpT_Zexc2jet->Fill(SpT(genLep1, genLep2, genLeadJ, genSecondJ), genWeight);
                        genSpTJets_Zexc2jet->Fill(SpTsub(genLeadJ, genSecondJ), genWeight);
                        genSpTLeptons_Zexc2jet->Fill(SpTsub(genLep1, genLep2), genWeight);
                        genSPhi_Zexc2jet->Fill(SPhi(genLep1, genLep2, genLeadJ, genSecondJ), genWeight);
                        genptBal_Zexc2jet->Fill(genJet1Plus2PlusZ.Pt(), genWeight);

                        if (genZ.Pt() < 25){
                            genptBal_LowPt_Zexc2jet->Fill(genJet1Plus2PlusZ.Pt(), genWeight);
                            gendPhiJets_LowPt_Zexc2jet->Fill(deltaPhi(genLeadJ, genSecondJ), genWeight);
                            genPHI_T_LowPt_Zexc2jet->Fill(PHI_T(genLep1, genLep2, genLeadJ, genSecondJ), genWeight);
                            genPHI_LowPt_Zexc2jet->Fill(PHI(genLep1, genLep2, genLeadJ, genSecondJ), genWeight);
                            genSpTJets_LowPt_Zexc2jet->Fill(SpTsub(genLeadJ, genSecondJ), genWeight);
                            genSpTLeptons_LowPt_Zexc2jet->Fill(SpTsub(genLep1, genLep2), genWeight);
                            genSpT_LowPt_Zexc2jet->Fill(SpT(genLep1, genLep2, genLeadJ, genSecondJ), genWeight);
                            genSPhi_LowPt_Zexc2jet->Fill(SPhi(genLep1, genLep2, genLeadJ, genSecondJ), genWeight);
                            if (SpT(genLep1, genLep2, genLeadJ, genSecondJ) < 0.5) { 
                                genPHI_LowSpT_LowPt_Zexc2jet->Fill(PHI(genLep1, genLep2, genLeadJ, genSecondJ), genWeight);
                                genSPhi_LowSpT_LowPt_Zexc2jet->Fill(SPhi(genLep1, genLep2, genLeadJ, genSecondJ), genWeight);
                            }
                            else {
                                genPHI_HighSpT_LowPt_Zexc2jet->Fill(PHI(genLep1, genLep2, genLeadJ, genSecondJ), genWeight);
                                genSPhi_HighSpT_LowPt_Zexc2jet->Fill(SPhi(genLep1, genLep2, genLeadJ, genSecondJ), genWeight);
                            }
                            if (SPhi(genLep1, genLep2, genLeadJ, genSecondJ) < 0.5) {
                                genSpT_LowSPhi_LowPt_Zexc2jet->Fill(SpT(genLep1, genLep2, genLeadJ, genSecondJ), genWeight);
                            }
                            else {
                                genSpT_HighSPhi_LowPt_Zexc2jet ->Fill(SpT(genLep1, genLep2, genLeadJ, genSecondJ), genWeight);
                            }
                        }
                        else {
                            genptBal_HighPt_Zexc2jet->Fill(genJet1Plus2PlusZ.Pt(), genWeight);
                            gendPhiJets_HighPt_Zexc2jet->Fill(deltaPhi(genLeadJ, genSecondJ), genWeight);
                            genPHI_HighPt_Zexc2jet->Fill(PHI(genLep1, genLep2, genLeadJ, genSecondJ), genWeight);
                            genPHI_T_HighPt_Zexc2jet->Fill(PHI_T(genLep1, genLep2, genLeadJ, genSecondJ), genWeight);
                            genSpTJets_HighPt_Zexc2jet->Fill(SpTsub(genLeadJ, genSecondJ), genWeight);
                            genSpTLeptons_HighPt_Zexc2jet->Fill(SpTsub(genLep1, genLep2), genWeight);
                            genSpT_HighPt_Zexc2jet->Fill(SpT(genLep1, genLep2, genLeadJ, genSecondJ), genWeight);
                            genSPhi_HighPt_Zexc2jet->Fill(SPhi(genLep1, genLep2, genLeadJ, genSecondJ), genWeight);
                        }
                    }

                }
                if (nGoodGenJets_20 >= 3) genThirdJetPt_Zinc3jet->Fill(genJets_20[2].pt, genWeight);
                if (nGoodGenJets >= 3){
                    GENnEventsIncl3Jets++;
                    genZNGoodJets_Zinc->Fill(3., genWeight);
                    genThirdJetEta_Zinc3jet->Fill(fabs(genJets[2].eta), genWeight);
                    genJetsHT_Zinc3jet->Fill(genJetsHT, genWeight);
                }
                if (nGoodGenJets_20 >= 4) genFourthJetPt_Zinc4jet->Fill(genJets_20[3].pt, genWeight);
                if (nGoodGenJets >= 4){
                    genZNGoodJets_Zinc->Fill(4., genWeight);
                    genFourthJetEta_Zinc4jet->Fill(fabs(genJets[3].eta), genWeight);
                    genJetsHT_Zinc4jet->Fill(genJetsHT, genWeight);
                }
                if (nGoodGenJets_20 >= 5) genFifthJetPt_Zinc5jet->Fill(genJets_20[4].pt, genWeight);
                if (nGoodGenJets >= 5){
                    genZNGoodJets_Zinc->Fill(5., genWeight);
                    genFifthJetEta_Zinc5jet->Fill(fabs(genJets[4].eta), genWeight);
                    genJetsHT_Zinc5jet->Fill(genJetsHT, genWeight);
                }
                if (nGoodGenJets_20 >= 6) genSixthJetPt_Zinc6jet->Fill(genJets_20[5].pt, genWeight);
                if (nGoodGenJets >= 6){
                    genZNGoodJets_Zinc->Fill(6., genWeight);
                    genSixthJetEta_Zinc6jet->Fill(fabs(genJets[5].eta), genWeight);
                    genJetsHT_Zinc6jet->Fill(genJetsHT, genWeight);
                }
                if (nGoodGenJets >= 7) {
                    genZNGoodJets_Zinc->Fill(7., genWeight);               
                }
                if (nGoodGenJets >= 8) {
                    genZNGoodJets_Zinc->Fill(8., genWeight);
                }
            }
        }
        //=======================================================================================================//
        if (DEBUG) cout << "Stop after line " << __LINE__ << endl;




        //=======================================================================================================//
        //      Selection fo Reco Histos      //
        //====================================//
        double tau_sum(0), tau_max(0);
        double tau_c_sum(0), tau_c_max(0);
        double tau_cm_sum(0), tau_cm_max(0);
        double tau_c_cm_sum(0), tau_c_cm_max(0); 

        if (hasRecoInfo && passesLeptonCut) { 
            //=======================================================================================================//


            if (DEBUG) cout << "Stop after line " << __LINE__ << endl;
            //=======================================================================================================//
            //      Start filling histograms      //
            //====================================//

            TotalRecoWeightPassRECO+=weight;
            TotalGenWeightPassRECO+=genWeightBackup;
            NVtx->Fill(EvtInfo_NumVtx, weight);

            nEventsIncl0Jets++;
            ZNGoodJetsNVtx_Zexc->Fill(nGoodJets, EvtInfo_NumVtx  , weight);
            ZNGoodJets_Zinc->Fill(0., weight);
            ZNGoodJets_Zexc->Fill(nGoodJets, weight);
            ZNGoodJets_Zinc_NoWeight->Fill(0.);
            ZMass_Zinc0jet->Fill(Z.M(), weight);
            ZPt_Zinc0jet->Fill(Z.Pt(), weight);
            ZRapidity_Zinc0jet->Fill(Z.Rapidity(), weight);
            ZEta_Zinc0jet->Fill(Z.Eta(), weight);
            lepPt_Zinc0jet->Fill(leptons[0].pt, weight);
            lepEta_Zinc0jet->Fill(leptons[0].eta, weight);
            lepPhi_Zinc0jet->Fill(leptons[0].phi, weight);
            lepPt_Zinc0jet->Fill(leptons[1].pt, weight);
            lepEta_Zinc0jet->Fill(leptons[1].eta, weight);
            lepPhi_Zinc0jet->Fill(leptons[1].phi, weight);
            dPhiLeptons_Zinc0jet->Fill(deltaPhi(lep1, lep2), weight);
            dEtaLeptons_Zinc0jet->Fill(leptons[0].eta - leptons[1].eta, weight);
            dRLeptons_Zinc0jet->Fill(deltaR(leptons[0].phi, leptons[0].eta, leptons[1].phi, leptons[1].eta), weight);
            SpTLeptons_Zinc0jet->Fill(SpTsub(lep1, lep2), weight);
            if (nGoodJets == 0){
                //TruePU_0->Fill(PU_npT, weight);
                //PU_0->Fill(PU_npIT, weight);
                PU_0->Fill(EvtInfo_NumVtx, weight);
                nEventsExcl0Jets++;
                ZNGoodJets_Zexc_NoWeight->Fill(0.);
                ZPt_Zexc0jet->Fill(Z.Pt(), weight);
                ZRapidity_Zexc0jet->Fill(Z.Rapidity(), weight);
                ZEta_Zexc0jet->Fill(Z.Eta(), weight);
                lepPt_Zexc0jet->Fill(leptons[0].pt, weight);
                lepEta_Zexc0jet->Fill(leptons[0].eta, weight);
                lepPt_Zexc0jet->Fill(leptons[1].pt, weight);
                lepEta_Zexc0jet->Fill(leptons[1].eta, weight);
                dPhiLeptons_Zexc0jet->Fill(deltaPhi(lep1, lep2), weight);
                dEtaLeptons_Zexc0jet->Fill(leptons[0].eta - leptons[1].eta, weight);
                SpTLeptons_Zexc0jet->Fill(SpTsub(lep1, lep2), weight);
            }

            if (nGoodJets_20 >= 1) FirstJetPt_Zinc1jet->Fill(jets_20[0].pt, weight);
            if (nGoodJets >= 1){
                ZNGoodJets_Zinc->Fill(1., weight);
                ZNGoodJets_Zinc_NoWeight->Fill(1.);
                ZPt_Zinc1jet->Fill(Z.Pt(), weight);
                ZRapidity_Zinc1jet->Fill(Z.Rapidity(), weight);
                ZEta_Zinc1jet->Fill(Z.Eta(), weight);
                SpTLeptons_Zinc1jet->Fill(SpTsub(lep1, lep2), weight);
                FirstJetEta_Zinc1jet->Fill(fabs(jets[0].eta), weight);
                FirstJetEtaFull_Zinc1jet->Fill(jets[0].eta, weight);
                FirstJetPhi_Zinc1jet->Fill(jets[0].phi, weight);
                JetsHT_Zinc1jet->Fill(jetsHT, weight);
                dEtaBosonJet_Zinc1jet->Fill(fabs(jets[0].eta-Z.Eta()), weight);

                for (unsigned short i(0); i < nGoodJets; i++) {
                    TLorentzVector tmpJet(0, 0, 0, 0);
                    tmpJet.SetPtEtaPhiE(jets[i].pt, jets[i].eta, jets[i].phi, jets[i].energy);
                    double trans_mass = tmpJet.Mt();

                    tau_sum += trans_mass * exp(-fabs(tmpJet.Rapidity() - Z.Rapidity())); 
                    tau_max = max(tau_max, trans_mass * exp(-fabs(tmpJet.Rapidity() - Z.Rapidity()))); 

                    tau_c_sum += trans_mass / (2 * cosh(tmpJet.Rapidity() - Z.Rapidity()));
                    tau_c_max = max(tau_c_max, trans_mass / (2 * cosh(tmpJet.Rapidity() - Z.Rapidity())));

                    tau_cm_sum += trans_mass * exp(-fabs(tmpJet.Rapidity())); 
                    tau_cm_max = max(tau_cm_max, trans_mass * exp(-fabs(tmpJet.Rapidity()))); 

                    tau_c_cm_sum += trans_mass / (2 * cosh(tmpJet.Rapidity()));
                    tau_c_cm_max = max(tau_c_cm_max, trans_mass / (2 * cosh(tmpJet.Rapidity())));
                }

                for (unsigned short i(0); i < 5; i++) {
                    if (Z.Pt() > ZptRange[i] && Z.Pt() <= ZptRange[i+1]) {
                        tau_sum_Zinc1jet[i]->Fill(tau_sum, weight);
                        tau_max_Zinc1jet[i]->Fill(tau_max, weight);
                        tau_c_sum_Zinc1jet[i]->Fill(tau_c_sum, weight);
                        tau_c_max_Zinc1jet[i]->Fill(tau_c_max, weight);
                        tau_cm_sum_Zinc1jet[i]->Fill(tau_cm_sum, weight);
                        tau_cm_max_Zinc1jet[i]->Fill(tau_cm_max, weight);
                        tau_c_cm_sum_Zinc1jet[i]->Fill(tau_c_cm_sum, weight);
                        tau_c_cm_max_Zinc1jet[i]->Fill(tau_c_cm_max, weight);
                    }
                }

                if (nGoodJets == 1){
                    //TruePU_1->Fill(PU_npT, weight);
                    //PU_1->Fill(PU_npIT, weight);
                    PU_1->Fill(EvtInfo_NumVtx, weight);
                    nEventsExcl1Jets++;
                    ZNGoodJets_Zexc_NoWeight->Fill(1.);
                    ZPt_Zexc1jet->Fill(Z.Pt(), weight);
                    ZRapidity_Zexc1jet->Fill(Z.Rapidity(), weight);
                    ZEta_Zexc1jet->Fill(Z.Eta(), weight);
                    SpTLeptons_Zexc1jet->Fill(SpTsub(lep1, lep2), weight);
                    FirstJetPt_Zexc1jet->Fill(jets[0].pt, weight);
                    FirstJetEta_Zexc1jet->Fill(jets[0].eta, weight);
                    FirstJetPhi_Zexc1jet->Fill(jets[0].phi, weight);
                    dEtaBosonJet_Zexc1jet->Fill(fabs(jets[0].eta-Z.Eta()), weight);

                }
            }
            if (nGoodJets_20 >= 2) SecondJetPt_Zinc2jet->Fill(jets_20[1].pt, weight);
            if (nGoodJets >= 2){
                TLorentzVector jet1Plus2PlusZ = jet1Plus2 + Z;
                ZNGoodJets_Zinc->Fill(2., weight);
                ZNGoodJets_Zinc_NoWeight->Fill(2.);
                TwoJetsPtDiff_Zinc2jet->Fill(jet1Minus2.Pt(), weight);
                BestTwoJetsPtDiff_Zinc2jet->Fill(bestJet1Minus2.Pt(), weight);
                JetsMass_Zinc2jet->Fill(jet1Plus2.M(), weight);
                ZPt_Zinc2jet->Fill(Z.Pt(), weight);
                ZRapidity_Zinc2jet->Fill(Z.Rapidity(), weight);
                ZEta_Zinc2jet->Fill(Z.Eta(), weight);
                SpTLeptons_Zinc2jet->Fill(SpTsub(lep1, lep2), weight);
                SecondJetEta_Zinc2jet->Fill(fabs(jets[1].eta), weight);
                SecondJetEtaFull_Zinc2jet->Fill(jets[1].eta, weight);
                SecondJetPhi_Zinc2jet->Fill(jets[1].phi, weight);        
                JetsHT_Zinc2jet->Fill(jetsHT, weight);
                ptBal_Zinc2jet->Fill(jet1Plus2PlusZ.Pt(), weight);
                dPhiJets_Zinc2jet->Fill(deltaPhi(leadJ, secondJ), weight);
                BestdPhiJets_Zinc2jet->Fill(deltaPhi(bestTwoJets.first, bestTwoJets.second), weight);
                dEtaJets_Zinc2jet->Fill(leadJ.Eta() - secondJ.Eta(), weight);
                dEtaFirstJetZ_Zinc2jet->Fill(leadJ.Eta() - Z.Eta(), weight);
                dEtaSecondJetZ_Zinc2jet->Fill(secondJ.Eta() - Z.Eta(), weight);
                dEtaJet1Plus2Z_Zinc2jet->Fill(jet1Plus2.Eta() - Z.Eta(), weight);
                PHI_Zinc2jet->Fill(PHI(lep1, lep2, leadJ, secondJ), weight);
                BestPHI_Zinc2jet->Fill(PHI(lep1, lep2, bestTwoJets.first, bestTwoJets.second), weight);
                PHI_T_Zinc2jet->Fill(PHI_T(lep1, lep2, leadJ, secondJ), weight);
                BestPHI_T_Zinc2jet->Fill(PHI_T(lep1, lep2, bestTwoJets.first, bestTwoJets.second), weight);
                SpT_Zinc2jet->Fill(SpT(lep1, lep2, leadJ, secondJ), weight);
                BestSpT_Zinc2jet->Fill(SpT(lep1, lep2, bestTwoJets.first, bestTwoJets.second), weight);
                SpTJets_Zinc2jet->Fill(SpTsub(leadJ, secondJ), weight);
                BestSpTJets_Zinc2jet->Fill(SpTsub(bestTwoJets.first, bestTwoJets.second), weight);
                SPhi_Zinc2jet->Fill(SPhi(lep1, lep2, leadJ, secondJ), weight);
                BestSPhi_Zinc2jet->Fill(SPhi(lep1, lep2, bestTwoJets.first, bestTwoJets.second), weight);

                if (Z.Pt() < 25){
                    ptBal_LowPt_Zinc2jet->Fill(jet1Plus2PlusZ.Pt(), weight);
                    dPhiJets_LowPt_Zinc2jet->Fill(deltaPhi(leadJ, secondJ), weight);
                    BestdPhiJets_LowPt_Zinc2jet->Fill(deltaPhi(bestTwoJets.first, bestTwoJets.second), weight);
                    dPhiLeptons_LowPt_Zinc2jet->Fill(deltaPhi(lep1, lep2), weight);
                    PHI_LowPt_Zinc2jet->Fill(PHI(lep1, lep2, leadJ, secondJ), weight);
                    BestPHI_LowPt_Zinc2jet->Fill(PHI(lep1, lep2, bestTwoJets.first, bestTwoJets.second), weight);
                    PHI_T_LowPt_Zinc2jet->Fill(PHI_T(lep1, lep2, leadJ, secondJ), weight);
                    BestPHI_T_LowPt_Zinc2jet->Fill(PHI_T(lep1, lep2, bestTwoJets.first, bestTwoJets.second), weight);
                    SpT_LowPt_Zinc2jet->Fill(SpT(lep1, lep2, leadJ, secondJ), weight);
                    BestSpT_LowPt_Zinc2jet->Fill(SpT(lep1, lep2, bestTwoJets.first, bestTwoJets.second), weight);
                    SpTJets_LowPt_Zinc2jet->Fill(SpTsub(leadJ, secondJ), weight);
                    BestSpTJets_LowPt_Zinc2jet->Fill(SpTsub(bestTwoJets.first, bestTwoJets.second), weight);
                    SpTLeptons_LowPt_Zinc2jet->Fill(SpTsub(lep1, lep2), weight);
                    SPhi_LowPt_Zinc2jet->Fill(SPhi(lep1, lep2, leadJ, secondJ), weight);
                    BestSPhi_LowPt_Zinc2jet->Fill(SPhi(lep1, lep2, bestTwoJets.first, bestTwoJets.second), weight);
                    if (SpT(lep1, lep2, leadJ, secondJ) < 0.5){ 
                        PHI_LowSpT_LowPt_Zinc2jet->Fill(PHI(lep1, lep2, leadJ, secondJ), weight);
                        SPhi_LowSpT_LowPt_Zinc2jet->Fill(SPhi(lep1, lep2, leadJ, secondJ), weight);
                    }
                    else {
                        PHI_HighSpT_LowPt_Zinc2jet->Fill(PHI(lep1, lep2, leadJ, secondJ), weight);
                        SPhi_HighSpT_LowPt_Zinc2jet->Fill(SPhi(lep1, lep2, leadJ, secondJ), weight);
                    }
                    if (SPhi(lep1, lep2, leadJ, secondJ) < 0.5){
                        SpT_LowSPhi_LowPt_Zinc2jet->Fill(SpT(lep1, lep2, leadJ, secondJ), weight);
                    }
                    else {
                        SpT_HighSPhi_LowPt_Zinc2jet->Fill(SpT(lep1, lep2, leadJ, secondJ), weight);
                    }
                }
                else {
                    ptBal_HighPt_Zinc2jet->Fill(jet1Plus2PlusZ.Pt(),weight);
                    dPhiJets_HighPt_Zinc2jet->Fill(deltaPhi(leadJ, secondJ), weight);
                    dPhiLeptons_HighPt_Zinc2jet->Fill(deltaPhi(lep1, lep2), weight);
                    PHI_HighPt_Zinc2jet->Fill(PHI(lep1, lep2, leadJ, secondJ), weight);
                    PHI_T_HighPt_Zinc2jet->Fill(PHI_T(lep1, lep2, leadJ, secondJ), weight);
                    SpT_HighPt_Zinc2jet->Fill(SpT(lep1, lep2, leadJ, secondJ), weight);
                    SpTJets_HighPt_Zinc2jet->Fill(SpTsub(leadJ, secondJ), weight);
                    SpTLeptons_HighPt_Zinc2jet->Fill(SpTsub(lep1, lep2), weight);
                    SPhi_HighPt_Zinc2jet->Fill(SPhi(lep1, lep2, leadJ, secondJ), weight);
                    if (SpT(lep1, lep2, leadJ, secondJ) < 0.5){
                        PHI_LowSpT_HighPt_Zinc2jet->Fill(PHI(lep1, lep2, leadJ, secondJ), weight);
                        SPhi_LowSpT_HighPt_Zinc2jet->Fill(SPhi(lep1, lep2, leadJ, secondJ), weight); 
                    }
                    else {
                        PHI_HighSpT_HighPt_Zinc2jet->Fill(PHI(lep1, lep2, leadJ, secondJ), weight); 
                        SPhi_HighSpT_HighPt_Zinc2jet->Fill(SPhi(lep1, lep2, leadJ, secondJ), weight);
                    }
                    if (SPhi(lep1, lep2, leadJ, secondJ) < 0.5){
                        SpT_LowSPhi_HighPt_Zinc2jet->Fill(SpT(lep1, lep2, leadJ, secondJ), weight);
                    }
                    else {
                        SpT_HighSPhi_HighPt_Zinc2jet->Fill(SpT(lep1, lep2, leadJ, secondJ), weight);
                    }
                }
                if (SPhi(lep1, lep2, leadJ, secondJ) < 0.5){
                    SpT_LowSPhi_Zinc2jet->Fill(SpT(lep1, lep2, leadJ, secondJ), weight);
                }
                else {
                    SpT_HighSPhi_Zinc2jet->Fill(SpT(lep1, lep2, leadJ, secondJ), weight);
                }
                if (SpT(lep1, lep2, leadJ, secondJ) < 0.5){
                    PHI_LowSpT_Zinc2jet->Fill(PHI(lep1, lep2, leadJ, secondJ), weight);
                    SPhi_LowSpT_Zinc2jet->Fill(SPhi(lep1, lep2, leadJ, secondJ), weight);
                }
                else {
                    PHI_HighSpT_Zinc2jet->Fill(PHI(lep1, lep2, leadJ, secondJ), weight);
                    SPhi_HighSpT_Zinc2jet->Fill(SPhi(lep1, lep2, leadJ, secondJ), weight);
                }
                if (nGoodJets == 2){
                    nEventsExcl2Jets++;
                    //TruePU_2->Fill(PU_npT, weight);
                    //PU_2->Fill(PU_npIT, weight);              
                    PU_2->Fill(EvtInfo_NumVtx, weight);
                    ZNGoodJets_Zexc_NoWeight->Fill(2.);
                    ZPt_Zexc2jet->Fill(Z.Pt(), weight);
                    ZRapidity_Zexc2jet->Fill(Z.Rapidity(), weight);
                    ZEta_Zexc2jet->Fill(Z.Eta(), weight);
                    SpTLeptons_Zexc2jet->Fill(SpTsub(lep1, lep2), weight);
                    SecondJetPt_Zexc2jet->Fill(jets[1].pt, weight);
                    SecondJetEta_Zexc2jet->Fill(jets[1].eta, weight);
                    SecondJetPhi_Zexc2jet->Fill(jets[1].phi, weight); 

                    //-- DPS Histograms
                    TwoJetsPtDiff_Zexc2jet->Fill(jet1Minus2.Pt(), weight);
                    JetsMass_Zexc2jet->Fill(jet1Plus2.M(), weight);
                    ptBal_Zexc2jet->Fill(jet1Plus2PlusZ.Pt(), weight);
                    dPhiJets_Zexc2jet->Fill(deltaPhi(leadJ, secondJ), weight);
                    dEtaJets_Zexc2jet->Fill(leadJ.Eta() - secondJ.Eta(), weight);
                    dEtaFirstJetZ_Zexc2jet->Fill(leadJ.Eta() - Z.Eta(), weight);
                    dEtaSecondJetZ_Zexc2jet->Fill(secondJ.Eta() - Z.Eta(), weight);
                    dEtaJet1Plus2Z_Zexc2jet->Fill(jet1Plus2.Eta() - Z.Eta(), weight);
                    PHI_Zexc2jet->Fill(PHI(lep1, lep2, leadJ, secondJ), weight);
                    PHI_T_Zexc2jet->Fill(PHI_T(lep1, lep2, leadJ, secondJ), weight);
                    SpT_Zexc2jet->Fill(SpT(lep1, lep2, leadJ, secondJ), weight);
                    SpTJets_Zexc2jet->Fill(SpTsub(leadJ, secondJ), weight);
                    SPhi_Zexc2jet->Fill(SPhi(lep1, lep2, leadJ, secondJ), weight);
                    if (Z.Pt() < 25){
                        ptBal_LowPt_Zexc2jet->Fill(jet1Plus2PlusZ.Pt(), weight);
                        dPhiJets_LowPt_Zexc2jet->Fill(deltaPhi(leadJ, secondJ), weight);
                        PHI_LowPt_Zexc2jet->Fill(PHI(lep1, lep2, leadJ, secondJ), weight);
                        PHI_T_LowPt_Zexc2jet->Fill(PHI_T(lep1, lep2, leadJ, secondJ), weight);
                        SpT_LowPt_Zexc2jet->Fill(SpT(lep1, lep2, leadJ, secondJ), weight);
                        SpTJets_LowPt_Zexc2jet->Fill(SpTsub(leadJ, secondJ), weight);
                        SpTLeptons_LowPt_Zexc2jet->Fill(SpTsub(lep1, lep2), weight);
                        SPhi_LowPt_Zexc2jet->Fill(SPhi(lep1, lep2, leadJ, secondJ), weight);
                        if (SpT(lep1, lep2, leadJ, secondJ) < 0.5){ 
                            PHI_LowSpT_LowPt_Zexc2jet->Fill(PHI(lep1, lep2, leadJ, secondJ), weight);
                            SPhi_LowSpT_LowPt_Zexc2jet->Fill(SPhi(lep1, lep2, leadJ, secondJ), weight);
                        }
                        else {
                            PHI_HighSpT_LowPt_Zexc2jet->Fill(PHI(lep1, lep2, leadJ, secondJ), weight);
                            SPhi_HighSpT_LowPt_Zexc2jet->Fill(SPhi(lep1, lep2, leadJ, secondJ), weight);
                        }
                        if (SPhi(lep1, lep2, leadJ, secondJ) < 0.5){
                            SpT_LowSPhi_LowPt_Zexc2jet->Fill(SpT(lep1, lep2, leadJ, secondJ), weight);
                        }
                        else {
                            SpT_HighSPhi_LowPt_Zexc2jet ->Fill(SpT(lep1, lep2, leadJ, secondJ), weight);
                        }
                    }
                    else {
                        ptBal_HighPt_Zexc2jet->Fill(jet1Plus2PlusZ.Pt(),weight);
                        dPhiJets_HighPt_Zexc2jet->Fill(deltaPhi(leadJ, secondJ), weight);
                        PHI_HighPt_Zexc2jet->Fill(PHI(lep1, lep2, leadJ, secondJ), weight);
                        PHI_T_HighPt_Zexc2jet->Fill(PHI_T(lep1, lep2, leadJ, secondJ), weight);
                        SpT_HighPt_Zexc2jet->Fill(SpT(lep1, lep2, leadJ, secondJ), weight);
                        SpTJets_HighPt_Zexc2jet->Fill(SpTsub(leadJ, secondJ), weight);
                        SpTLeptons_HighPt_Zexc2jet->Fill(SpTsub(lep1, lep2), weight);
                        SPhi_HighPt_Zexc2jet->Fill(SPhi(lep1, lep2, leadJ, secondJ), weight);
                        if (SpT(lep1, lep2, leadJ, secondJ) < 0.5){
                            PHI_LowSpT_HighPt_Zexc2jet->Fill(PHI(lep1, lep2, leadJ, secondJ), weight);
                            SPhi_LowSpT_HighPt_Zexc2jet->Fill(SPhi(lep1, lep2, leadJ, secondJ), weight); 
                        }
                        else {
                            PHI_HighSpT_HighPt_Zexc2jet->Fill(PHI(lep1, lep2, leadJ, secondJ), weight); 
                            SPhi_HighSpT_HighPt_Zexc2jet->Fill(SPhi(lep1, lep2, leadJ, secondJ), weight);
                        }
                        if (SPhi(lep1, lep2, leadJ, secondJ) < 0.5){
                            SpT_LowSPhi_HighPt_Zexc2jet->Fill(SpT(lep1, lep2, leadJ, secondJ), weight);
                        }
                        else {
                            SpT_HighSPhi_HighPt_Zexc2jet->Fill(SpT(lep1, lep2, leadJ, secondJ), weight);
                        }
                    }
                    if (SPhi(lep1, lep2, leadJ, secondJ) < 0.5){
                        SpT_LowSPhi_Zexc2jet->Fill(SpT(lep1, lep2, leadJ, secondJ), weight);
                    }
                    else {
                        SpT_HighSPhi_Zexc2jet->Fill(SpT(lep1, lep2, leadJ, secondJ), weight);
                    }
                    if (SpT(lep1, lep2, leadJ, secondJ) < 0.5){
                        PHI_LowSpT_Zexc2jet->Fill(PHI(lep1, lep2, leadJ, secondJ), weight);
                        SPhi_LowSpT_Zexc2jet->Fill(SPhi(lep1, lep2, leadJ, secondJ), weight);
                    }
                    else {
                        PHI_HighSpT_Zexc2jet->Fill(PHI(lep1, lep2, leadJ, secondJ), weight);
                        SPhi_HighSpT_Zexc2jet->Fill(SPhi(lep1, lep2, leadJ, secondJ), weight);
                    }
                }
            }
            if (nGoodJets_20 >= 3) ThirdJetPt_Zinc3jet->Fill(jets_20[2].pt, weight);
            if (nGoodJets >= 3) {
                ZNGoodJets_Zinc->Fill(3., weight);
                ZNGoodJets_Zinc_NoWeight->Fill(3.);
                ThirdJetEta_Zinc3jet->Fill(fabs(jets[2].eta), weight);
                ThirdJetEtaFull_Zinc3jet->Fill(jets[2].eta, weight);
                ThirdJetPhi_Zinc3jet->Fill(jets[2].phi, weight);        
                JetsHT_Zinc3jet->Fill(jetsHT, weight);
                if (nGoodJets == 3){
                    nEventsExcl3Jets++;
                    //TruePU_3->Fill(PU_npT, weight);
                    //PU_3->Fill(PU_npIT, weight);
                    PU_3->Fill(EvtInfo_NumVtx, weight);
                    ZNGoodJets_Zexc_NoWeight->Fill(3.);
                }
            }
            if (nGoodJets_20 >= 4) FourthJetPt_Zinc4jet->Fill(jets_20[3].pt, weight);
            if (nGoodJets >= 4){
                ZNGoodJets_Zinc->Fill(4., weight);
                ZNGoodJets_Zinc_NoWeight->Fill(4.);
                FourthJetEta_Zinc4jet->Fill(fabs(jets[3].eta), weight);
                FourthJetEtaFull_Zinc4jet->Fill(jets[3].eta, weight);
                FourthJetPhi_Zinc4jet->Fill(jets[3].phi, weight);        
                JetsHT_Zinc4jet->Fill(jetsHT, weight);
                if (nGoodJets == 4){
                    //TruePU_4->Fill(PU_npT, weight);
                    //PU_4->Fill(PU_npIT, weight);
                    PU_4->Fill(EvtInfo_NumVtx, weight);
                    ZNGoodJets_Zexc_NoWeight->Fill(4.);
                }
            }    
            if (nGoodJets_20 >= 5) FifthJetPt_Zinc5jet->Fill(jets_20[4].pt, weight);
            if (nGoodJets >= 5){
                ZNGoodJets_Zinc->Fill(5., weight);
                ZNGoodJets_Zinc_NoWeight->Fill(5.);
                FifthJetEta_Zinc5jet->Fill(fabs(jets[4].eta), weight);
                FifthJetEtaFull_Zinc5jet->Fill(jets[4].eta, weight);
                FifthJetPhi_Zinc5jet->Fill(jets[4].phi, weight);        
                JetsHT_Zinc5jet->Fill(jetsHT, weight);
                if (nGoodJets == 5){
                    //TruePU_5->Fill(PU_npT, weight);
                    //PU_5->Fill(PU_npIT, weight);
                    PU_5->Fill(EvtInfo_NumVtx, weight);
                    ZNGoodJets_Zexc_NoWeight->Fill(5.);
                }
            }    
            if (nGoodJets_20 >= 6) SixthJetPt_Zinc6jet->Fill(jets_20[5].pt, weight);
            if (nGoodJets >= 6){
                ZNGoodJets_Zinc->Fill(6., weight);
                ZNGoodJets_Zinc_NoWeight->Fill(6.);
                SixthJetEta_Zinc6jet->Fill(fabs(jets[5].eta), weight);
                SixthJetEtaFull_Zinc6jet->Fill(jets[5].eta, weight);
                SixthJetPhi_Zinc6jet->Fill(jets[5].phi, weight);        
                JetsHT_Zinc6jet->Fill(jetsHT, weight);
                if (nGoodJets == 6){
                    //TruePU_6->Fill(PU_npT, weight);
                    //PU_6->Fill(PU_npIT, weight);
                    PU_6->Fill(EvtInfo_NumVtx, weight);
                    ZNGoodJets_Zexc_NoWeight->Fill(6.);
                }
            }
            if (nGoodJets >= 7){
                ZNGoodJets_Zinc->Fill(7., weight);
                if (nGoodJets == 7 ){
                    //TruePU_7->Fill(PU_npT, weight);
                    //PU_7->Fill(PU_npIT, weight);
                    PU_7->Fill(EvtInfo_NumVtx, weight);
                }
            }
            if (nGoodJets >= 8){
                ZNGoodJets_Zinc->Fill(8., weight);
            }

            //=======================================================================================================//
        }

        //=======================================================================================================//
        //             Unfolding              //
        //====================================//
        if (hasRecoInfo && hasGenInfo) {

            //-- Z Mass and jet multiplicity
            if (passesGenLeptonCut) {
                if (passesLeptonCut) {
                    nEventsUNFOLDIncl0Jets++;
                    //responseZMass->Fill(Z.M(), genZ.M(), weight);
                    //responseZNGoodJets_Zexc->Fill(nGoodJets, nGoodGenJets, weight);
                    hresponseZNGoodJets_Zexc->Fill(nGoodJets, nGoodGenJets, weight);
                }
            }

            //-- First Jet Pt 
            if (nGoodGenJets >= 1 && passesGenLeptonCut) {
                if (nGoodJets >= 1 && passesLeptonCut) {
                    //responseFirstJetEta->Fill(fabs(jets[0].eta), fabs(genJets[0].eta), weight);      
                    hresponseFirstJetEta_Zinc1jet->Fill(fabs(jets[0].eta), fabs(genJets[0].eta), weight);      
                    //responseJetsHt1Jet->Fill(jetsHT, genJetsHT, weight);
                    hresponseJetsHT_Zinc1jet->Fill(jetsHT, genJetsHT, weight);
                    FirstJetdEtaGenReco_Zinc1->Fill(fabs(jets[0].eta - genJets[0].eta));
                    //responsedEtaBosonJet_Zinc1->Fill(fabs(jets[0].eta-Z.Eta()), fabs(genJets[0].eta - genZ.Eta()), weight);
                    for (unsigned short i(0); i < 5; i++) {
                        if (Z.Pt() > ZptRange[i] && Z.Pt() <= ZptRange[i+1]) {
                            hresponsetau_sum_Zinc1jet[i]->Fill(tau_sum, gentau_sum, weight);
                            hresponsetau_max_Zinc1jet[i]->Fill(tau_max, gentau_max, weight);
                            hresponsetau_c_sum_Zinc1jet[i]->Fill(tau_c_sum, gentau_c_sum, weight);
                            hresponsetau_c_max_Zinc1jet[i]->Fill(tau_c_max, gentau_c_max, weight);
                            hresponsetau_cm_sum_Zinc1jet[i]->Fill(tau_cm_sum, gentau_cm_sum, weight);
                            hresponsetau_cm_max_Zinc1jet[i]->Fill(tau_cm_max, gentau_cm_max, weight);
                            hresponsetau_c_cm_sum_Zinc1jet[i]->Fill(tau_c_cm_sum, gentau_c_cm_sum, weight);
                            hresponsetau_c_cm_max_Zinc1jet[i]->Fill(tau_c_cm_max, gentau_c_cm_max, weight);
                        }
                    }
                }
            } 

            if (nGoodGenJets_20 >= 1 && passesGenLeptonCut) {
                if (nGoodJets_20 >= 1 && passesLeptonCut) {
                    hresponseFirstJetPt_Zinc1jet->Fill(jets_20[0].pt, genJets_20[0].pt, weight);      
                }
            } 

            //-- Second Jet Pt inclusive 
            if (nGoodGenJets >= 2 && passesGenLeptonCut) {
                if (nGoodJets >= 2 && passesLeptonCut) {
                    //responseSecondJetEta->Fill(fabs(jets[1].eta), fabs(genJets[1].eta), weight);      
                    hresponseSecondJetEta_Zinc2jet->Fill(fabs(jets[1].eta), fabs(genJets[1].eta), weight);      
                    //responseJetsHt2Jet->Fill(jetsHT, genJetsHT, weight);
                    hresponseJetsHT_Zinc2jet->Fill(jetsHT, genJetsHT, weight);
                    //responseTwoJetsPtDiffInc->Fill(jet1Minus2.Pt(), genJet1Minus2.Pt(), weight);
                    //responseBestTwoJetsPtDiffInc->Fill(bestJet1Minus2.Pt(), genBestJet1Minus2.Pt(), weight);
                    //responseJetsMassInc->Fill(jet1Plus2.M(), genJet1Plus2.M(), weight);
                    hresponseJetsMass_Zinc2jet->Fill(jet1Plus2.M(), genJet1Plus2.M(), weight);
                    //responseBestJetsMassInc->Fill(bestJet1Plus2.M(), genBestJet1Plus2.M(), weight);
                    //responseSpTJets_Zinc2jet->Fill(SpTsub(leadJ, secondJ), SpTsub(genLeadJ, genSecondJ), weight);
                    //responseBestSpTJets_Zinc2jet->Fill(SpTsub(bestTwoJets.first, bestTwoJets.second), SpTsub(genBestTwoJets.first, genBestTwoJets.second), weight);
                    //responseSpT_Zinc2jet->Fill(SpT(lep1, lep2, leadJ, secondJ), SpT(genLep1, genLep2, genLeadJ, genSecondJ), weight);
                    //responseBestSpT_Zinc2jet->Fill(SpT(lep1, lep2, bestTwoJets.first, bestTwoJets.second), SpT(genLep1, genLep2, genBestTwoJets.first, genBestTwoJets.second), weight);
                    //responsedPhiJets_Zinc2jet->Fill(deltaPhi(leadJ, secondJ), deltaPhi(genLeadJ, genSecondJ), weight);
                    //responseBestdPhiJets_Zinc2jet->Fill(deltaPhi(bestTwoJets.first, bestTwoJets.second), deltaPhi(genBestTwoJets.first, genBestTwoJets.second), weight);
                    //responsePHI_Zinc2jet->Fill(PHI(lep1, lep2, leadJ, secondJ), PHI(genLep1, genLep2, genLeadJ, genSecondJ), weight);
                    //responseBestPHI_Zinc2jet->Fill(PHI(lep1, lep2, bestTwoJets.first, bestTwoJets.second), PHI(genLep1, genLep2, genBestTwoJets.first, genBestTwoJets.second), weight);
                    //responsePHI_T_Zinc2jet->Fill(PHI_T(lep1, lep2, leadJ, secondJ), PHI_T(genLep1, genLep2, genLeadJ, genSecondJ), weight);
                    //responseBestPHI_T_Zinc2jet->Fill(PHI_T(lep1, lep2, bestTwoJets.first, bestTwoJets.second), PHI_T(genLep1, genLep2, genBestTwoJets.first, genBestTwoJets.second), weight);
                    //responseSPhi_Zinc2jet->Fill(SPhi(lep1, lep2, leadJ, secondJ), SPhi(genLep1, genLep2, genLeadJ, genSecondJ), weight);
                    //responsedEtaJets_Zinc2jet->Fill(fabs(genJets[0].eta-genJets[1].eta),fabs(jets[0].eta-jets[1].eta), weight);
                    //responseBestSPhi_Zinc2jet->Fill(SPhi(lep1, lep2, bestTwoJets.first, bestTwoJets.second), SPhi(genLep1, genLep2, genBestTwoJets.first, genBestTwoJets.second), weight);
                }

                //-- for low Z pt < 25 GeV
                if (genZ.Pt() < 25 && nGoodJets >= 2 && passesLeptonCut && genZ.Pt() < 25) {
                    //responseTwoJetsPtDiffLowPtInc->Fill(jet1Minus2.Pt(), genJet1Minus2.Pt(), genWeight);
                    //responseBestTwoJetsPtDiffLowPtInc->Fill(bestJet1Minus2.Pt(), genBestJet1Minus2.Pt(), weight);
                    //responseJetsMassLowPtInc->Fill(jet1Plus2.M(), genJet1Plus2.M(), weight);
                    //responseBestJetsMassLowPtInc->Fill(bestJet1Plus2.M(), genBestJet1Plus2.M(), weight);
                    //responseSpTJets_LowPt_Zinc2jet->Fill(SpTsub(leadJ, secondJ), SpTsub(genLeadJ, genSecondJ), weight);
                    //responseBestSpTJets_LowPt_Zinc2jet->Fill(SpTsub(bestTwoJets.first, bestTwoJets.second), SpTsub(genBestTwoJets.first, genBestTwoJets.second), weight);
                    //responseSpT_LowPt_Zinc2jet->Fill(SpT(lep1, lep2, leadJ, secondJ), SpT(genLep1, genLep2, genLeadJ, genSecondJ), weight);
                    //responseBestSpT_LowPt_Zinc2jet->Fill(SpT(lep1, lep2, bestTwoJets.first, bestTwoJets.second), SpT(genLep1, genLep2, genBestTwoJets.first, genBestTwoJets.second), weight);
                    //responsedPhiJets_LowPt_Zinc2jet->Fill(deltaPhi(leadJ, secondJ), deltaPhi(genLeadJ, genSecondJ), weight);
                    //responseBestdPhiJets_LowPt_Zinc2jet->Fill(deltaPhi(bestTwoJets.first, bestTwoJets.second), deltaPhi(genBestTwoJets.first, genBestTwoJets.second), weight);
                    //responsePHI_LowPt_Zinc2jet->Fill(PHI(lep1, lep2, leadJ, secondJ), PHI(genLep1, genLep2, genLeadJ, genSecondJ), weight);
                    //responseBestPHI_LowPt_Zinc2jet->Fill(PHI(lep1, lep2, bestTwoJets.first, bestTwoJets.second), PHI(genLep1, genLep2, genBestTwoJets.first, genBestTwoJets.second), weight);
                    //responsePHI_T_LowPt_Zinc2jet->Fill(PHI_T(lep1, lep2, leadJ, secondJ), PHI_T(genLep1, genLep2, genLeadJ, genSecondJ), weight);
                    //responseBestPHI_T_LowPt_Zinc2jet->Fill(PHI_T(lep1, lep2, bestTwoJets.first, bestTwoJets.second), PHI_T(genLep1, genLep2, genBestTwoJets.first, genBestTwoJets.second), weight);
                    //responseSPhi_LowPt_Zinc2jet->Fill(SPhi(lep1, lep2, leadJ, secondJ), SPhi(genLep1, genLep2, genLeadJ, genSecondJ), weight);
                    //responseBestSPhi_LowPt_Zinc2jet->Fill(SPhi(lep1, lep2, bestTwoJets.first, bestTwoJets.second), SPhi(genLep1, genLep2, genBestTwoJets.first, genBestTwoJets.second), weight);
                }

            }


            if (nGoodGenJets_20 >= 2 && passesGenLeptonCut) {
                if (nGoodJets_20 >= 2 && passesLeptonCut) {
                    //responseSecondJetPt->Fill(jets_20[1].pt, genJets_20[1].pt, weight);      
                    hresponseSecondJetPt_Zinc2jet->Fill(jets_20[1].pt, genJets_20[1].pt, weight);      
                }
            }

            //-- Second Jet Pt exclusive
            if (nGoodGenJets == 2 && passesGenLeptonCut) {
                if (nGoodJets == 2 && passesLeptonCut) {
                    //responseTwoJetsPtDiffExc->Fill(jet1Minus2.Pt(), genJet1Minus2.Pt(), weight);
                    //responseJetsMassExc->Fill(jet1Plus2.M(), genJet1Plus2.M(), weight);
                    //responseSpTJets_Zexc2jet->Fill(SpTsub(leadJ, secondJ), SpTsub(genLeadJ, genSecondJ), weight);
                    //responseSpT_Zexc2jet->Fill(SpT(lep1, lep2, leadJ, secondJ), SpT(genLep1, genLep2, genLeadJ, genSecondJ), weight);
                    //responsedPhiJets_Zexc2jet->Fill(deltaPhi(leadJ, secondJ), deltaPhi(genLeadJ, genSecondJ), weight);
                    //responsePHI_Zexc2jet->Fill(PHI(lep1, lep2, leadJ, secondJ), PHI(genLep1, genLep2, genLeadJ, genSecondJ), weight);
                    //responsePHI_T_Zexc2jet->Fill(PHI_T(lep1, lep2, leadJ, secondJ), PHI_T(genLep1, genLep2, genLeadJ, genSecondJ), weight);
                    //responsedEtaJets_Zexc2jet->Fill(fabs(genJets[0].eta-genJets[1].eta),fabs(jets[0].eta-jets[1].eta), weight);
                    //responseSPhi_Zexc2jet->Fill(SPhi(lep1, lep2, leadJ, secondJ), SPhi(genLep1, genLep2, genLeadJ, genSecondJ), weight);
                }
                //-- for low Z pt < 25 GeV
                if (genZ.Pt() < 25 && nGoodJets == 2 && passesLeptonCut && genZ.Pt() < 25) {
                    //responseTwoJetsPtDiffLowPtExc->Fill(jet1Minus2.Pt(), genJet1Minus2.Pt(), weight);
                    //responseJetsMassLowPtExc->Fill(jet1Plus2.M(), genJet1Plus2.M(), weight);
                    //responseSpTJets_LowPt_Zexc2jet->Fill(SpTsub(leadJ, secondJ), SpTsub(genLeadJ, genSecondJ), weight);
                    //responseSpT_LowPt_Zexc2jet->Fill(SpT(lep1, lep2, leadJ, secondJ), SpT(genLep1, genLep2, genLeadJ, genSecondJ), weight);
                    //responsedPhiJets_LowPt_Zexc2jet->Fill(deltaPhi(leadJ, secondJ), deltaPhi(genLeadJ, genSecondJ), weight);
                    //responsePHI_LowPt_Zexc2jet->Fill(PHI(lep1, lep2, leadJ, secondJ), PHI(genLep1, genLep2, genLeadJ, genSecondJ), weight);
                    //responsePHI_T_LowPt_Zexc2jet->Fill(PHI_T(lep1, lep2, leadJ, secondJ), PHI_T(genLep1, genLep2, genLeadJ, genSecondJ), weight);
                    //responseSPhi_LowPt_Zexc2jet->Fill(SPhi(lep1, lep2, leadJ, secondJ), SPhi(genLep1, genLep2, genLeadJ, genSecondJ), weight);
                }
            }

            //-- Third Jet Pt  
            if (nGoodGenJets >= 3 && passesGenLeptonCut) {
                if (nGoodJets >= 3 && passesLeptonCut) {
                    //responseThirdJetEta->Fill(fabs(jets[2].eta), fabs(genJets[2].eta), weight);      
                    hresponseThirdJetEta_Zinc3jet->Fill(fabs(jets[2].eta), fabs(genJets[2].eta), weight);      
                    //responseJetsHt3Jet->Fill(jetsHT, genJetsHT, weight);
                    hresponseJetsHT_Zinc3jet->Fill(jetsHT, genJetsHT, weight);
                }
            } 

            if (nGoodGenJets_20 >= 3 && passesGenLeptonCut) {
                if (nGoodJets_20 >= 3 && passesLeptonCut) {
                    //responseThirdJetPt->Fill(jets_20[2].pt, genJets_20[2].pt, weight);      
                    hresponseThirdJetPt_Zinc3jet->Fill(jets_20[2].pt, genJets_20[2].pt, weight);      
                }
            } 

            //-- Fourth Jet Pt  
            if (nGoodGenJets >= 4 && passesGenLeptonCut){
                if (nGoodJets >= 4 && passesLeptonCut){
                    //responseFourthJetEta->Fill(fabs(jets[3].eta), fabs(genJets[3].eta), weight);      
                    hresponseFourthJetEta_Zinc4jet->Fill(fabs(jets[3].eta), fabs(genJets[3].eta), weight);      
                    //responseJetsHt4Jet->Fill(jetsHT, genJetsHT, weight);
                    hresponseJetsHT_Zinc4jet->Fill(jetsHT, genJetsHT, weight);
                    FourthJetdEtaGenReco_Zinc4->Fill(fabs(jets[3].eta - genJets[3].eta));
                }
            }

            if (nGoodGenJets_20 >= 4 && passesGenLeptonCut){
                if (nGoodJets_20 >= 4 && passesLeptonCut){
                    //responseFourthJetPt->Fill(jets_20[3].pt, genJets_20[3].pt, weight);      
                    hresponseFourthJetPt_Zinc4jet->Fill(jets_20[3].pt, genJets_20[3].pt, weight);      
                }
            }

            //-- Fifth Jet Pt  
            if (nGoodGenJets >= 5 && passesGenLeptonCut){
                if (nGoodJets >= 5 && passesLeptonCut){
                    //responseFifthJetEta->Fill(fabs(jets[4].eta), fabs(genJets[4].eta), weight);      
                    hresponseFifthJetEta_Zinc5jet->Fill(fabs(jets[4].eta), fabs(genJets[4].eta), weight);      
                    //responseJetsHt5Jet->Fill(jetsHT, genJetsHT, weight);
                    hresponseJetsHT_Zinc5jet->Fill(jetsHT, genJetsHT, weight);
                }
            } 

            if (nGoodGenJets_20 >= 5 && passesGenLeptonCut){
                if (nGoodJets_20 >= 5 && passesLeptonCut){
                    //responseFifthJetPt->Fill(jets_20[4].pt, genJets_20[4].pt, weight);      
                    hresponseFifthJetPt_Zinc5jet->Fill(jets_20[4].pt, genJets_20[4].pt, weight);      
                }
            } 

            //-- Sixth Jet Pt  
            if (nGoodGenJets >= 6 && passesGenLeptonCut){
                if (nGoodJets >= 6 && passesLeptonCut){
                    //responseSixthJetPt->Fill(jets[5].pt, genJets[5].pt, weight);      
                    //responseSixthJetEta->Fill(fabs(jets[5].eta), fabs(genJets[5].eta), weight);      
                    //responseJetsHt6Jet->Fill(jetsHT, genJetsHT, weight);
                }
            } 

            if (nGoodGenJets_20 >= 6 && passesGenLeptonCut){
                if (nGoodJets_20 >= 6 && passesLeptonCut){
                    //responseSixthJetPt->Fill(jets_20[5].pt, genJets_20[5].pt, weight);      
                    //hresponseSixthJetPt_Zinc6jet->Fill(jets_20[5].pt, genJets_20[5].pt, weight);      
                }
            } 
        }
        //=======================================================================================================//

    } //End of loop over all the events
    //==========================================================================================================//

    if (DEBUG) cout << "Stop after line " << __LINE__ << endl;
    //==========================================================================================================//
    //         Writing file              //
    //==================================//

    outputFile->cd();

    //--- Save all the histograms ---
    unsigned short numbOfHistograms = listOfHistograms.size();
    for (unsigned short i(0); i < numbOfHistograms; i++){
        string hName = listOfHistograms[i]->GetName();
        if ((!hasGenInfo && hName.find("gen") != string::npos) || (!hasRecoInfo && hName.find("gen") == string::npos)) continue; 
        listOfHistograms[i]->Write();        
    }

    outputFile->Write();
    outputFile->Close();

    //==========================================================================================================//


    cout << "Number of events                               : " << nEvents << endl;
    cout << "Total GEN weight of all events                 : " << TotalGenWeight << endl;
    cout << "Number with two good leptons no charge no mass : " << nEventsWithTwoGoodLeptonsNoChargeNoMass << endl;
    cout << "Number with two good leptons no mass           : " << nEventsWithTwoGoodLeptonsNoMass << endl;
    cout << "Total GEN pass: RECO weight of all events      : " << TotalGenWeightPassGENPU << endl;
    cout << "Total GEN pass: GEN weight of all events       : " << TotalGenWeightPassGEN << endl;
    cout << "Total RECO pass: RECO weight of all events     : " << TotalRecoWeightPassRECO << endl;
    cout << "Total RECO pass: GEN weight of all events      : " << TotalGenWeightPassRECO << endl;
    cout << "Number with two good leptons                   : " << nEventsWithTwoGoodLeptons << endl;
    cout << "How many times do we visit unfolding 0 jets    : " << nEventsUNFOLDIncl0Jets << endl;
    cout << "Number Inclusif 0 jets                         : " << nEventsIncl0Jets << endl;
    cout << "Number Exclusif 0 jets                         : " << nEventsExcl0Jets << endl;
    cout << "Number Exclusif 1 jets                         : " << nEventsExcl1Jets << endl;
    cout << "Number Exclusif 2 jets                         : " << nEventsExcl2Jets << endl;
    cout << "Number Exclusif 3 jets                         : " << nEventsExcl3Jets << endl;
    cout << "Number GEN Inclusif 0 jets                     : " << GENnEventsIncl0Jets << endl;
    cout << "Number GEN Inclusif 1 jets                     : " << GENnEventsIncl1Jets << endl;
    cout << "Number GEN Inclusif 2 jets                     : " << GENnEventsIncl2Jets << endl;
    cout << "Number GEN Inclusif 3 jets                     : " << GENnEventsIncl3Jets << endl;
}

ZJets::ZJets(TString fileName_, float lumiScale_, bool useTriggerCorrection_,
        int systematics_, int direction_, float xsecfactor_, int jetPtCutMin_, int jetEtaCutMax_,  bool do10000Events_, TString outDir_): 
    HistoSetZJets(fileName_(0, fileName_.Index("_"))), outputDirectory(outDir_),
    fileName(fileName_), lumiScale(lumiScale_), useTriggerCorrection(useTriggerCorrection_), 
    systematics(systematics_), direction(direction_), xsecfactor(xsecfactor_), jetPtCutMin(jetPtCutMin_), jetEtaCutMax(jetEtaCutMax_), do10000Events(do10000Events_)
{

    //--- Create output directory if necessary ---
    if (do10000Events) {
        outputDirectory = "HistoFilesTest/";
        cout << "Doing test for 10000 events  => output directory has been changed to HistoFilesTest/" << endl;
    }
    TString command = "mkdir -p " + outputDirectory;
    system(command);
    //--------------------------------------------

    TChain *chain = new TChain("", "");

    isData = (fileName.find("Data") != string::npos); 
    string fullFileName = "~/ZJetsFiles/" + fileName;


    if (fileName.find("DMu_") == 0) leptonFlavor = "Muons";
    else if (fileName.find("DE_") == 0)  leptonFlavor = "Electrons"; 

    if (fileName.find("List") == string::npos){
        fullFileName += ".root";
        string treePath = fullFileName + "/tree/tree";
        if (fileName.find("Sherpa") != string::npos) treePath = fullFileName + "/tree";
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
            string treePath = line + "/tree/tree";
            if (fileName.find("Sherpa") != string::npos) treePath = line + "/tree";
            chain->Add(treePath.c_str());       
        }
    }
    fChain = chain;
}

ZJets::~ZJets(){
    if (!fChain) return;
    delete fChain->GetCurrentFile();
}

string ZJets::CreateOutputFileName(string pdfSet, int pdfMember)
{
    ostringstream result;
    result << outputDirectory << fileName;
    result << "_TrigCorr_" << useTriggerCorrection;
    result << "_Syst_" << systematics;
    if (direction == 1) result << "_Up";
    else if (direction == -1) result << "_Down";
    result << "_JetPtMin_" << jetPtCutMin;
    result << "_JetEtaMax_" << jetEtaCutMax;

    if (pdfSet != "") result << "_PDF_" << pdfSet << "_" << pdfMember;
    //--- Add your test names here ---
    //result << "_NoPUCut";
    //result << "_LooseID";

    result << ".root";
    return result.str();
}

Int_t ZJets::GetEntry(Long64_t entry){
    // Read contents of entry.
    if (!fChain) return 0;
    return fChain->GetEntry(entry);
}

Long64_t ZJets::LoadTree(Long64_t entry){
    // Set the environment to read one entry
    if (!fChain) return -5;
    Long64_t centry = fChain->LoadTree(entry);
    if (centry < 0) return centry;
    if (fChain->GetTreeNumber() != fCurrent) {
        fCurrent = fChain->GetTreeNumber();Notify();  }
    return centry;
}

void ZJets::Init(bool hasRecoInfo, bool hasGenInfo){
    // The Init() function is called when the selector needs to initialize
    // a new tree or chain. Typically here the branch addresses and branch
    // pointers of the tree will be set.
    // It is normally not necessary to make changes to the generated
    // code, but the routine can be extended by the user if needed.
    // Init() will be called many times when running on PROOF
    // (once per file to be processed).

    // Set object pointer
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
    patMuonCombId_ = 0;
    patMuonTrig_ = 0;
    patMuonPfIsoDbeta_ = 0;

    patJetPfAk05En_ = 0;
    patJetPfAk05Pt_ = 0;
    patJetPfAk05Eta_ = 0;
    patJetPfAk05Phi_ = 0;
    patJetPfAk05LooseId_ = 0;
    patJetPfAk05jetpuMVA_ = 0;

    // Set branch addresses and branch pointers
    fCurrent = -1;
    fChain->SetMakeClass(1);
    if (fileName.find("Data") == string::npos) {
        fChain->SetBranchAddress("PU_npT", &PU_npT, &b_PU_npT);
        fChain->SetBranchAddress("PU_npIT", &PU_npIT, &b_PU_npIT);
    }
    if (hasRecoInfo){
        fChain->SetBranchAddress("EvtInfo_NumVtx", &EvtInfo_NumVtx, &b_EvtInfo_NumVtx);
        fChain->SetBranchAddress("EvtInfo_RunNum", &EvtInfo_RunNum, &b_EvtInfo_RunNum); 
        fChain->SetBranchAddress("EvtInfo_EventNum", &EvtInfo_EventNum, &b_EvtInfo_EventNum); 
        fChain->SetBranchAddress("patJetPfAk05En_", &patJetPfAk05En_, &b_patJetPfAk05En_);
        fChain->SetBranchAddress("patJetPfAk05Pt_", &patJetPfAk05Pt_, &b_patJetPfAk05Pt_);
        fChain->SetBranchAddress("patJetPfAk05Eta_", &patJetPfAk05Eta_, &b_patJetPfAk05Eta_);
        fChain->SetBranchAddress("patJetPfAk05Phi_", &patJetPfAk05Phi_, &b_patJetPfAk05Phi_);
        fChain->SetBranchAddress("patJetPfAk05LooseId_", &patJetPfAk05LooseId_, &b_patJetPfAk05LooseId_);
        fChain->SetBranchAddress("patJetPfAk05jetpuMVA_", &patJetPfAk05jetpuMVA_, &b_patJetPfAk05jetpuMVA_);

        if (leptonFlavor != "Muons"){
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
        if (leptonFlavor != "Electrons"){
            fChain->SetBranchAddress("patMuonPt_", &patMuonPt_, &b_patMuonPt_);
            fChain->SetBranchAddress("patMuonEta_", &patMuonEta_, &b_patMuonEta_);
            fChain->SetBranchAddress("patMuonPhi_", &patMuonPhi_, &b_patMuonPhi_);
            fChain->SetBranchAddress("patMuonEn_", &patMuonEn_, &b_patMuonEn_);
            fChain->SetBranchAddress("patMuonCharge_", &patMuonCharge_, &b_patMuonCharge_);
            fChain->SetBranchAddress("patMuonCombId_", &patMuonCombId_, &b_patMuonCombId_);
            fChain->SetBranchAddress("patMuonTrig_", &patMuonTrig_, &b_patMuonTrig_);
            fChain->SetBranchAddress("patMuonPfIsoDbeta_", &patMuonPfIsoDbeta_, &b_patMuonPfIsoDbeta_);
        }
    }
    if (hasGenInfo){
        fChain->SetBranchAddress("genLepPt_", &genLepPt_, &b_genLepPt_);
        fChain->SetBranchAddress("genLepEta_", &genLepEta_, &b_genLepEta_);
        fChain->SetBranchAddress("genLepPhi_", &genLepPhi_, &b_genLepPhi_);
        fChain->SetBranchAddress("genLepE_", &genLepE_, &b_genLepE_);
        fChain->SetBranchAddress("genLepQ_", &genLepQ_, &b_genLepQ_);
        fChain->SetBranchAddress("genLepId_", &genLepId_, &b_genLepId_);
        fChain->SetBranchAddress("genLepSt_", &genLepSt_, &b_genLepSt_);
        fChain->SetBranchAddress("genJetPt_", &genJetPt_, &b_genJetPt_);
        fChain->SetBranchAddress("genJetEta_", &genJetEta_, &b_genJetEta_);
        fChain->SetBranchAddress("genJetPhi_", &genJetPhi_, &b_genJetPhi_);
        fChain->SetBranchAddress("genJetE_", &genJetE_, &b_genJetE_);
        fChain->SetBranchAddress("genPhoPt_", &genPhoPt_, &b_genPhoPt_);
        fChain->SetBranchAddress("genPhoEta_", &genPhoEta_, &b_genPhoEta_);
        fChain->SetBranchAddress("genPhoPhi_", &genPhoPhi_, &b_genPhoPhi_);
        fChain->SetBranchAddress("pdfInfo_", &pdfInfo_, &b_pdfInfo_);
        fChain->SetBranchAddress("nup_", &nup_, &b_nup_);
    }
    Notify();
    cout << "Branches are properly initialized." << endl;
}

Bool_t ZJets::Notify(){
    // The Notify() function is called when a new file is opened. This
    // can be either for a new TTree in a TChain or when when a new TTree
    // is started when using PROOF. It is normally not necessary to make changes
    // to the generated code, but the routine can be extended by the
    // user if needed. The return value is currently not used.

    return kTRUE;
}

void ZJets::Show(Long64_t entry){
    // Print contents of entry.
    // If entry is not specified, print current entry
    if (!fChain) return;
    fChain->Show(entry);
}

Int_t ZJets::Cut(Long64_t entry){
    // This function may be called from Loop.
    // returns  1 if entry is accepted.
    // returns -1 otherwise.
    printf("entry %lld", entry);
    return 1;
}
