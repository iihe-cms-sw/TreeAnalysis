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
#include "UnfoldingSyst.h"
#include "getFilesAndHistograms.h"
#include "FinalUnfold.h"


using namespace std;

//--  Setting global variables --------------------------------------------------------------
#include "fileNames.h"
#include "variablesOfInterestVarWidth.h"
//-------------------------------------------------------------------------------------------

void FinalUnfold(int start, int end)
{
    bool isMuon(0);
    if (end == -1) end = start + 1;
    for (int i(start); i < end/*NVAROFINTERESTZJETS*/; i++) {
        for (int j(0); j < 2; j++){
            isMuon = j;
            if (isMuon) FuncUnfold(isMuon, VAROFINTERESTZJETS[i].name, VAROFINTERESTZJETS[i].MuBayeskterm, VAROFINTERESTZJETS[i].MuSVDkterm);
            else FuncUnfold(isMuon, VAROFINTERESTZJETS[i].name, VAROFINTERESTZJETS[i].EBayeskterm, VAROFINTERESTZJETS[i].ESVDkterm);
        }
    }

}


void FuncUnfold(bool isMuon, string variable, int UsedKtermBayes, int UsedKtermSVD, bool doFlat, bool doVarWidth)
{
    string energy = getEnergy();
    string unfAlg = "Bayes";
    string leptonFlavor = "DMu";
    if (!isMuon) leptonFlavor = "DE";
    int JetPtMin(30);
    int JetPtMax(0);
    string outputDirectory = "PNGFiles/FinalUnfold/";
    TH1::SetDefaultSumw2();

    JetPtMin = 30;
    if (JetPtMin == 30) outputDirectory = "PNGFiles/FinalUnfold_30_50_Toys/";
    else if (JetPtMin == 20) outputDirectory = "PNGFiles/FinalUnfold_20_50_Toys/";
    if (variable.find("JetPt")!= string::npos && variable.find("Highest") == string::npos && JetPtMin == 20) JetPtMin = 15;
    if (variable.find("JetPt")!= string::npos && variable.find("Highest") == string::npos && JetPtMin == 30) JetPtMin = 20;


    int NumberOfToys(50), oppNumberOfToys(4);
    int UsedKterm = UsedKtermBayes, oppUsedKterm = UsedKtermSVD;
    string oppUnfAlg = "SVD";
    if (unfAlg == "SVD") {
        UsedKterm = UsedKtermSVD; 
        NumberOfToys = 3;  
        oppNumberOfToys = 400;
        oppUnfAlg = "Bayes";
        oppUsedKterm = UsedKtermBayes;
    }
    // set efficiency errors
    double muonIDIsoHLTError = 0.025;// 2012 : id,iso = 0.005, 0.002 --> 1.4% for dimuon + HLT: 2% ??????
    double electronIDIsoHLTError = 0.005; // SF factors for 2012: 0.002
    double EffError = muonIDIsoHLTError;
    if (!isMuon) EffError = electronIDIsoHLTError;


    cout << " We now unfold:  " << variable << " jet pt:" << JetPtMin << " - " << JetPtMax << endl;

    //-- fetch the data files and histograms --------------
    TFile *fData[5] = {NULL};             // 0 = central, 1 = JES Up, 2 = JES Down , 3 - SF Up , 4 - SF down
    TH1D *hData[5] = {NULL};  
    getFiles(FILESDIRECTORY, fData, leptonFlavor, energy, ProcessInfo[DATAFILENAME].filename, JetPtMin, JetPtMax, doFlat, doVarWidth, 0, 0, 0, 0, 0, 1);
    getHistos(hData, fData, variable);
    //-----------------------------------------------------


    //-- fetch the DY files and histograms ----------------
    TFile *fDYMadGraph[4] = {NULL}; // 0 = central, 1 = PU Up,  2 = PU Down,  3 = JER Up
    TFile *fDYSherpa = NULL;               
    TFile *fDYPowheg = NULL;//, *fDYPowhegUp = NULL, *fDYPowhegDown = NULL;
    getFiles(FILESDIRECTORY, fDYMadGraph, leptonFlavor, energy, ProcessInfo[DYMADGRAPHFILENAME].filename, JetPtMin, JetPtMin, doFlat, doVarWidth, 0, 0, 0, 0, 0, 1);
    fDYSherpa = getFile(FILESDIRECTORY, leptonFlavor, energy, DYSHERPAFILENAME, JetPtMin, JetPtMin, doFlat, doVarWidth);
    fDYPowheg = getFile(FILESDIRECTORY, leptonFlavor, energy, DYPOWHEGFILENAME, JetPtMin, JetPtMin, doFlat, doVarWidth);
    //fDYPowhegUp = getFile(FILESDIRECTORY, leptonFlavor, energy, DYPOWHEGUPFILENAME, JetPtMin, JetPtMin, doFlat, doVarWidth);
    //fDYPowhegDown = getFile(FILESDIRECTORY, leptonFlavor, energy, DYPOWHEGDOWNFILENAME, JetPtMin, JetPtMin, doFlat, doVarWidth);

    TH1D *hDY[4] = {NULL}; // 0 = central, 1 = PU Up,  2 = PU Down,  3 = JER Up
    TH1D *hDYGenMadGraph = NULL, *hDYGenSherpa = NULL, *hDYGenPowheg = NULL;//, *hDYGenPowhegUp = NULL, *hDYGenPowhegDown = NULL;
    getHistos(hDY, fDYMadGraph, variable);
    hDYGenMadGraph = getHisto(fDYMadGraph[0], "gen" + variable);
    if (fDYSherpa->IsOpen()) hDYGenSherpa = getHisto(fDYSherpa, "gen" + variable);
    else {
        hDYGenSherpa = (TH1D*) hDYGenMadGraph->Clone();
        hDYGenSherpa->SetDirectory(0);
    }
    if (fDYPowheg->IsOpen()) hDYGenPowheg = getHisto(fDYPowheg, "gen" + variable);
    else {
        hDYGenPowheg = (TH1D*) hDYGenMadGraph->Clone();
        hDYGenPowheg->SetDirectory(0);
    }
    //hDYGenPowhegUp = getHisto(fDYPowhegUp, "gen" + variable);
    //hDYGenPowhegDown = getHisto(fDYPowhegDown, "gen" + variable);

    //--- Get MadGraph Resp Matrix ---
    RooUnfoldResponse *resDY[4] = {NULL}; 
    getResps(resDY, fDYMadGraph, "response" + variable);
    //-----------------------------------------------------

    //--- Get Sherpa Resp Matrix ---
    stringstream sheUnfFile;
    sheUnfFile << "HistoFiles/" << leptonFlavor << "_" << energy << "_DYJets_Sherpa_UNFOLDING_dR_5311_Inf_mcEveWeight_EffiCorr_0_TrigCorr_1_Syst_0_JetPtMin_" << JetPtMin << "_VarWidth.root";
    TFile *sheUnf = new TFile(sheUnfFile.str().c_str());
    RooUnfoldResponse *resDYSherpa = NULL;
    if (sheUnf->IsOpen()) resDYSherpa = (RooUnfoldResponse*) sheUnf->Get(string("response" + variable).c_str()); 
    else resDYSherpa = (RooUnfoldResponse*) resDY[0]->Clone();
    //-----------------------------------------------------


    //-- fetch the BG files and histograms ----------------
    cout << " Fetch background files " << endl;
    const int NBkgGroups(6);
    const int NBkgSyst(5);
    int nFilesBkg(0);

    TFile *fBG[15][NBkgSyst] = {{NULL}};  // 0 = central, 1 = PU Up,  2 = PU Down,  3 = XS Up,  4 = XS Down 
    TH1D *hBG[15][10] = {{NULL}}, *hSumBG[NBkgSyst] = {NULL}, *hSumBGgroup[15][10] = {{NULL}};
    int group = -1;
    double sumEve = 0.;
    int nFiles = NFILESDYJETS; // from "Includes/fileNames.h"
    bool isDoubleLep(1);
    if (leptonFlavor == "SMuE" || leptonFlavor == "SMu" || leptonFlavor == "Muon") {
        isDoubleLep = 0;
        nFiles = NFILESTTBAR;
    }
    int countFiles = 0;
    int countBGp[2] = {-1,-1};
    for (int i(0); i < nFiles; i++){
        int fileSelect = FilesDYJets[i];
        if (!isDoubleLep) fileSelect = FilesTTbarWJets[i];
        string fileNameTemp = ProcessInfo[fileSelect].filename;
        // Tau is not considered as background. It is taken into account by the unfolding
        if (fileNameTemp.find("Tau") != string::npos || fileNameTemp.find("Data") != string::npos) continue;
        // DYJets is not a background, it is the signal (for double lepton)
        if (isDoubleLep && fileNameTemp.find("DYJets") != string::npos) continue;
        // WJets is not a background, it is the signal (for single lepton)
        if (!isDoubleLep && fileNameTemp.find("WJets") != string::npos && fileNameTemp.find("UNF") != string::npos) continue;
        nFilesBkg++;

        //--- fetch the BG file and histos ---
        getFiles(FILESDIRECTORY, fBG[countFiles], leptonFlavor, energy, fileNameTemp, JetPtMin, JetPtMax, doFlat, doVarWidth, 0, 0, 0, 0, 0, 1);
        getHistos(hBG[countFiles], fBG[countFiles], variable);
        //------------------------------------

        if (isDoubleLep){
            if (fileNameTemp.find("ZZ") != string::npos){
                if (countBGp[0] == -1) group++;
            }
            else if (fileNameTemp.find("WZ") != string::npos){
                if (countBGp[1] == -1) group++;          
            }
            else group++;
        }
        else group++;

        for (int j(0); j < NBkgSyst; j++){
            if (countFiles == 0) hSumBG[j] = (TH1D*) hBG[countFiles][j]->Clone();
            else hSumBG[j]->Add(hBG[countFiles][j]);

            if (fileNameTemp.find("ZZ") != string::npos ) {
                if (countBGp[0] == -1) { 
                    if (j == 4) countBGp[0] = group;  
                    hSumBGgroup[j][group] = (TH1D*) hBG[countFiles][j]->Clone();
                }
                else {
                    hSumBGgroup[j][countBGp[0]]->Add(hBG[countFiles][j]);
                }
            }
            else if (fileNameTemp.find("WZ") != string::npos) {
                if (countBGp[1] == -1) { 
                    if (j == 4) countBGp[1] = group;   
                    hSumBGgroup[j][group] = (TH1D*) hBG[countFiles][j]->Clone();
                }
                else {
                    hSumBGgroup[j][countBGp[1]]->Add(hBG[countFiles][j]);
                }   
            }
            else {
                hSumBGgroup[j][group] = (TH1D*) hBG[countFiles][j]->Clone();
            }

            if ( j == 0 ) {
                sumEve += hBG[countFiles][j]->GetBinContent(1);
            }
        }
        countFiles++;
    }
    //-----------------------------------------------------

    // unfold central and shifted data and MC 
    cout << " loaded all unfolded files"<<endl;
    // set the output
    string outputRootFileName = outputDirectory + leptonFlavor + "_" + energy + "_unfolded_" + variable + "_histograms_" + unfAlg;
    if (doVarWidth) outputRootFileName += "_VarWidth";
    outputRootFileName += ".root";
    TFile* outputRootFile = new TFile(outputRootFileName.c_str(), "RECREATE");

    //-- save data reco
    outputRootFile->cd(); hData[0]->Write("Data"); hData[1]->Write("DataJECup"); hData[2]->Write("DataJECdown");
    //-- save madgraph gen also in the file
    outputRootFile->cd(); hDYGenMadGraph->Write("genMad");	
    cout << " saved data reco and madgraph files" << endl;
    //-- save sherpa and powheg gen also in the file
    outputRootFile->cd();  
    cout << __LINE__ << endl;
    hDYGenSherpa->Write("genShe");
    cout << __LINE__ << endl;
    //-- save powheg gen also in the file
    outputRootFile->cd();  
    cout << "lepton flavor: " << leptonFlavor << endl;
    hDYGenPowheg->Write("genPow");  
    //hDYGenPowhegUp->Write("genPowUp");  
    //hDYGenPowhegDown->Write("genPowDown");
    cout << "Start unfolding offseted histograms on RECO "<<endl;


    // add other interesting MC samples for MPI for example
    if ( energy == "7TeV"){
        const	int NAddGEN = 5 ;
        string names[NAddGEN] = {"MadZ2MPIoff","MadZ2Star","MadZ2StarMPIoff","P84C","PowZjjMiNLO"};
        for (int i(0); i < NAddGEN; i++){
            cout << GenMCFILENAMES[i] << endl;
            TFile* fDYGenTemp = NULL ;
            fDYGenTemp = getFile(FILESDIRECTORY, leptonFlavor, energy, GenMCFILENAMES[i], JetPtMin, JetPtMin, doFlat, doVarWidth);
            TH1D *hDYGenTempAdd = NULL;
            hDYGenTempAdd = getHisto(fDYGenTemp, "gen" + variable);
            string histoName = "gen" + names[i] ;
            outputRootFile->cd();  hDYGenTempAdd->Write(histoName.c_str());	
        }
    }


    string hNames[8] = {"Central", "JECup", "JECdown", "PUup", "PUdown", "XSECup", "XSECdown", "JERup"};
    int SelData[8] = {0, 1, 2, 0, 0, 0, 0, 0}; 
    int SelDY[8]   = {0, 0, 0, 1, 2, 0, 0, 3}; 
    int SelBG[8]   = {0, 0, 0, 1, 2, 3, 4, 0}; 
    for ( int i(0); i < 8; i++){
        //Unfold with SHerpa for the Central only
        if (i == 0) {
            TH1D* hUnfoldedWithSherpa = Unfold(unfAlg, resDYSherpa, hData[SelData[i]], hSumBG[SelBG[i]],  UsedKterm, hNames[i]); 
            outputRootFile->cd();  hUnfoldedWithSherpa->Write("unfWithSherpa");
        }
        TH1D* hUnfolded = Unfold(unfAlg, resDY[SelDY[i]], hData[SelData[i]], hSumBG[SelBG[i]],  UsedKterm, hNames[i]); 
        outputRootFile->cd();  hUnfolded->Write();
        cout << "Start unfolding offseted histograms on RECO "<<endl;
        if ( i == 3 ) { 
            hData[SelData[i]]->Write("testData");
            resDY[SelDY[i]]->Write("testDY");
            hSumBG[SelBG[i]]->Write("testBG");
        }
    }

    // unfold with the opposite methode to compute systematic error
    // from new prescription this is not to be used in the error estimation!!! but we can stil unfold
    TH1D* opphUnfolded = Unfold(oppUnfAlg, resDY[SelDY[0]], hData[SelData[0]], hSumBG[SelBG[0]], oppUsedKterm, "oppCentral"); 
    outputRootFile->cd(); opphUnfolded->Write();

    int xbin(hData[0]->GetNbinsX());	
    // now for central values compute Roounfold Cov matrix
    TH2D* covCentralRoo    = CovFromRoo(unfAlg, resDY[0], hData[0], hSumBG[0], UsedKterm, "CentralCov", 1);
    TH2D* covCentralRooToy = CovFromRoo(unfAlg, resDY[0], hData[0], hSumBG[0], UsedKterm, "CentralCovToy", NumberOfToys);
    outputRootFile->cd();  covCentralRoo->Write();  covCentralRooToy->Write();

    TH2D*  corCentralRoo= CovToCorr2((TH2D*) covCentralRoo->Clone("RooCor"), "RooCor");
    TH2D*  corCentralRooToy= CovToCorr2((TH2D*) covCentralRooToy->Clone("RooCorToy"), "RooCorToy");
    outputRootFile->cd();  corCentralRoo->Write();  corCentralRooToy->Write();

    //// now the covariance and correlation of the Opposite Algo
    TH2D* covCentralRooOpp    = CovFromRoo(oppUnfAlg, resDY[0], hData[0], hSumBG[0], oppUsedKterm, "CentralCovOpp", 1);
    TH2D* covCentralRooToyOpp = CovFromRoo(oppUnfAlg, resDY[0], hData[0], hSumBG[0], oppUsedKterm, "CentralCovToyOpp", NumberOfToys);
    outputRootFile->cd();  covCentralRooOpp->Write("CentralCovOpp");  covCentralRooToyOpp->Write("CentralCovToyOpp");

    TH2D* corCentralRooOpp = CovToCorr2((TH2D*) covCentralRooOpp->Clone("RooCorOpp"), "RooCorOpp");
    TH2D* corCentralRooToyOpp = CovToCorr2((TH2D*) covCentralRooToyOpp->Clone("RooCorToyOpp"), "RooCorToyOpp");
    outputRootFile->cd();  corCentralRooOpp->Write();  corCentralRooToyOpp->Write();

    // finished with central stuff, now do covariance 
    // and my toy error propagation --> MY PRIVATE MAGIC 
    // first set errors
    //TH1D *hDataJES = SetSystErrorsMax(hData[0], hData[1], hData[2], "JESerrors");     // JES errors
    TH1D *hDataJES = SetSystErrorsMean(hData[0], hData[1], hData[2], "JESerrors");     // JES errors
    TH1D *hDataEFF = SetSystErrorsMean(hData[0], EffError, "EFFerrors");     // lepton EFF errors
    //hData[3]->Draw();
    //  if ( leptonFlavor == "DE" ) hDataEFF = SetSystErrorsMean(hData[0], hData[0], hData[3], hData[4], EffError, "EFFerrors");     // lepton EFF errors
    TH1D *hDataJER = SetSystErrorsMean(hData[0], hDY[0], hDY[3], hDY[3], "JERerrors");     // JER errors
    TH1D *hDataPU = SetSystErrorsMean(hData[0], hDY[0], hDY[1], hDY[2], "JERerrors");      // PU errors
    TH2D *hResPUErrors = SetResponseErrors( (TH2D*) resDY[0]->Hresponse(), (TH2D*) resDY[1]->Hresponse(), (TH2D*) resDY[2]->Hresponse());	// PU effect on response 
    TH2D *hResJERErrors = SetResponseErrors( (TH2D*) resDY[0]->Hresponse(), (TH2D*) resDY[3]->Hresponse(), (TH2D*) resDY[3]->Hresponse());	// JER effect on response 

    // my stat variation of data, BG and response object 
    RooUnfoldResponse *responseNEW[3];
    responseNEW[0] = new RooUnfoldResponse((TH1D*) resDY[0]->Hmeasured(), (TH1D*) resDY[0]->Htruth(), resDY[0]->Hresponse());
    responseNEW[1] = new RooUnfoldResponse((TH1D*) resDY[0]->Hmeasured(), (TH1D*) resDY[0]->Htruth(), hResPUErrors);
    responseNEW[2] = new RooUnfoldResponse((TH1D*) resDY[0]->Hmeasured(), (TH1D*) resDY[0]->Htruth(), hResJERErrors);

    // PU and XSEC errors on background
    TH1D* hSumBGErrors[3];
    hSumBGErrors[0] = (TH1D*) hSumBG[0]->Clone();
    hSumBGErrors[1] = SetSystErrorsMax(hSumBG[0], hSumBG[1], hSumBG[2],"BGPUerrors");    // PU errors
    hSumBGErrors[2] = SetSystErrorsMax(hSumBG[0], hSumBG[3], hSumBG[4],"BGXSECerrors");  //  XSEC errors

    TH1D* hSumBGgroupErrors[5][NBkgGroups] = {{NULL}};
    for (int i(0); i < NBkgGroups; i++){
        hSumBGgroupErrors[0][i] = (TH1D*) hSumBGgroup[0][i]->Clone();
        hSumBGgroupErrors[1][i] = SetSystErrorsMax(hSumBGgroup[0][i], hSumBGgroup[1][i], hSumBGgroup[2][i], "gBGPUerrors");
        hSumBGgroupErrors[2][i] = SetSystErrorsMax(hSumBGgroup[0][i], hSumBGgroup[3][i], hSumBGgroup[4][i], "gBGXSECerrors");
    }


    const int nUnfold =9; 
    string Cov[nUnfold] = {"MyToy", "MyToyMC", "MyToyJES", "MyToyPU", "MyToyXSEC", "MyToyJER", "MyToyEFF","MyToyJER2","MyToyPU2"};
    int selRes[nUnfold] = {0, 0, 0, 1, 0, 2, 0, 0, 0};
    int selBGerrors[nUnfold] = {0, 0, 0, 1, 2, 0, 0, 0, 0};
    TH2D *hCovariance[nUnfold];
    TH2D *hCorrelation[nUnfold];
    TH1D *hOyMySyst[nUnfold];
    int SetTypeOfVariation[nUnfold] = {1, 101, 10, 2, 11, 4, 10, 10, 10}; // select what and how to varry
    /// option 3 --- data bins are varries independently; option 10 -- global variation pf all bins
    //int SetTypeOfVariation[6] = {1, 3, 2, 11, 4 , 3}; // select what and how to varry : ORIGINAL SELECTION
    //if (variable.find("ZNG")!= string::npos ) SetTypeOfVariation[1] = 103 ;
    // option (1)10: systeamtics is completly correlated on reco --> translated to cov matrix
    // option 3: assume errors in reco bins are uncorrelated
    //int myToyN[5] = {400, 400, 400, 400, 400};

    for (int i(0); i < nUnfold; i++){	
        cout << endl;
        cout << endl;
        cout << "Doing my TOY " << Cov[i] << " with type  " << SetTypeOfVariation[i] << endl;
        cout << endl;
        string CovName = Cov[i] + "Cov";
        string CorName = Cov[i] + "Cor";
        string hNameTemp = "h" + Cov[i];
        TH1D *hDataTem = (TH1D*) hData[0]->Clone(); 
        if (i == 2) hDataTem = (TH1D*) hDataJES->Clone();
        if (i == 6) hDataTem = (TH1D*) hDataEFF->Clone();
        if (i == 7) hDataTem = (TH1D*) hDataJER->Clone();
        if (i == 8) hDataTem = (TH1D*) hDataPU->Clone();
        hCovariance[i] = new TH2D(CovName.c_str(), CovName.c_str(), xbin, 0.5, xbin+0.5, xbin, 0.5, xbin+0.5);
        hCorrelation[i] = new TH2D(CorName.c_str(), CorName.c_str(), xbin, 0.5, xbin+0.5, xbin, 0.5, xbin+0.5);
        RooUnfoldResponse *responseTemp = (RooUnfoldResponse*) responseNEW[selRes[i]]->Clone(); 
        TH1D* vhBack[1] ;
        vhBack[0] = (TH1D*) hSumBG[selBGerrors[i]]->Clone();
        // this function has to be cleaned
        TH1D *hToy2 ;
        if ( i == 4 ) hToy2 = (TH1D*) ToyMCErrorsStat(unfAlg, hDataTem, hSumBGgroupErrors[selBGerrors[i]], responseTemp, UsedKterm, hCovariance[i], hCorrelation[i], NumberOfToys , SetTypeOfVariation[i]);
        else hToy2 = (TH1D*) ToyMCErrorsStat(unfAlg, hDataTem, vhBack, responseTemp, UsedKterm, hCovariance[i], hCorrelation[i], NumberOfToys, SetTypeOfVariation[i]);
        hOyMySyst[i] = (TH1D*) hToy2->Clone(hNameTemp.c_str());

        outputRootFile->cd();
        hOyMySyst[i]->Write();
        hCovariance[i]->Write();
        hCorrelation[i]->Write();
    }

    //-- Close all the files ------------------------------
    outputRootFile->Close();
    //closeFile(outputRootFile);
    closeFiles(fData);
    closeFiles(fDYMadGraph);
    if (fDYSherpa->IsOpen()) closeFile(fDYSherpa);
    if (fDYPowheg->IsOpen()) closeFile(fDYPowheg);
    if (sheUnf->IsOpen()) sheUnf->Close();
    //closeFile(fDYPowhegUp);
    //closeFile(fDYPowhegDown);
    for (int i(0); i < nFilesBkg; i++) closeFiles(fBG[i]);
    //-----------------------------------------------------

}



