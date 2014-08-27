#include <iostream>
#include <sstream>
#include <RooUnfoldResponse.h>
#include <TFile.h>
#include <TString.h>
#include <TSystem.h>
#include <algorithm>
#include "getFilesAndHistogramsZJets.h"
using namespace std;

//------------------------------------------------------------
// getEnergy() returns a TString, either "7TeV" or "8TeV"
// according to the name of the directory from which the 
// code is being executed.
//------------------------------------------------------------
TString getEnergy()
{
    TString energy = "";
    TString fileBeingProcessed = __FILE__;
    if (fileBeingProcessed.Index("2012") >= 0) {
        energy = "8TeV";
    }
    else if (fileBeingProcessed.Index("2011") >= 0) {
        energy = "7TeV";
    }
    else 
    {
        std::cout << "WARNING ! Impossible to retrieve te energy from the current location !" << std::endl;
        energy = "Unknown";
    }

    return energy;
}
//------------------------------------------------------------

TFile* getFile(TString histoDir, TString lepSel, TString energy, TString Name, int jetPtMin, int jetEtaMax, TString closureTest, TString syst)
{
    
    TString fileName = histoDir; // TString to contain the name of the file
    if (!fileName.EndsWith("/")) fileName += "/";

    //--- make sure lepSel is short version ---
    if (lepSel == "Muons" || lepSel == "DMu_") lepSel = "DMu";
    else if (lepSel == "Electrons" || lepSel == "DE_") lepSel = "DE";

    fileName += lepSel + "_" + energy + "_" + Name; // update fileName with lepton information
    //-----------------------------------------------


    //--- deal with efficiency correction applied or not ---
    TString trigCorr = "0";
    if (Name.Index("Data") == 0 || energy == "8TeV") trigCorr = "1"; // trigger correction is applied to data and MC at 8TeV but only to data at 7TeV 

    //--- special case for the generator comparison ---
    if (Name.Index("Powheg") >= 0 || Name.Index("Sherpa") >= 0) trigCorr = "0"; 
    //-------------------------------------------------

    //--- update fileName with trigger correction ----------
    fileName += "_TrigCorr_" + trigCorr;
    //------------------------------------------------------

    //--- update fileName for a bunch of other things ---
    fileName += "_Syst_" + syst;
    fileName += "_JetPtMin_";
    fileName += jetPtMin;
    fileName += "_JetEtaMax_";
    fileName += jetEtaMax; 
    if (closureTest != "") fileName += closureTest;
    //---------------------------------------------------

    //--- fileName is complete: just add the extension and open it ---
    fileName += ".root";
    TFile *File = new TFile(fileName, "READ");
    std::cout << "Opening: " << fileName << "   --->   Opened ? " << File->IsOpen() << std::endl;
    return File;
    //----------------------------------------------------------------
}

void getFiles(TString histoDir, TFile *Files[], TString lepSel, TString energy, TString Name, int jetPtMin, int jetEtaMax)
{

    //--- make sure lepSel is short version ---
    if (lepSel == "Muons" || lepSel == "DMu_") lepSel = "DMu";
    else if (lepSel == "Electrons" || lepSel == "DE_") lepSel = "DE";
    //-----------------------------------------------

    vector<TString> Syst;
    if (Name.Index("Data") >= 0) { // for data we have:
        Syst.push_back("0");                 //   0: central
        Syst.push_back("2_Up");              //   2 up: JES up
        Syst.push_back("2_Down");            //   2 down: JES down
    }
    else if (Name.Index("UNFOLDING") >= 0 && Name.Index("DYJets") >= 0 && Name.Index("Tau") < 0) {
        // for DYJets in case of Z+Jets or for WJets in case of W+Jets analysis we have:
        Syst.push_back("0");         // 0: central
        Syst.push_back("1_Up");      // 1 up: PU up
        Syst.push_back("1_Down");    // 1 down: PU down
        Syst.push_back("4_Up");      // 4 up: JER up
        Syst.push_back("4_Down");    // 4 up: JER down
    }
    else { // for background we have
        Syst.push_back("0");         // 0: central
        Syst.push_back("1_Up");      // 1 up: PU up
        Syst.push_back("1_Down");    // 1 down: PU down
        Syst.push_back("3_Up");      // 3 up: XSec up
        Syst.push_back("3_Down");    // 3 down: Xsec down
    };

    //--- determnie how many files we have and open them all ---
    int nSyst(Syst.size());
    for (int i(0); i < nSyst; i++) {
        Files[i] = getFile(histoDir, lepSel, energy, Name, jetPtMin, jetEtaMax, "", Syst[i]);
    }
    //----------------------------------------------------------
}

void getAllFiles(TString histoDir, TString lepSel, TString energy, int jetPtMin, int jetEtaMax, TFile *fData[3], TFile *fDYJets[5], TFile *fBg[][5], int nBg)
{
    //--- Open data files ---------------------------------------------------------------------- 
    getFiles(histoDir, fData, lepSel, energy, Samples[DATA].name, jetPtMin, jetEtaMax); 
    //------------------------------------------------------------------------------------------ 

    //--- Open DYJets files --------------------------------------------------------------------
    getFiles(histoDir, fDYJets, lepSel, energy, Samples[DYJETS].name, jetPtMin, jetEtaMax); 
    //------------------------------------------------------------------------------------------ 

    //--- Open Bg files ------------------------------------------------------------------------
    for (unsigned short iBg = 0; iBg < nBg; ++iBg) {
        getFiles(histoDir, fBg[iBg], lepSel, energy, Samples[iBg+1].name, jetPtMin, jetEtaMax);
    }
    //------------------------------------------------------------------------------------------ 
}

void getAllHistos(TString variable, TH1D *hRecData[3], TFile *fData[3], TH1D *hRecDYJets[5], TH1D *hGenDYJets[5], TH2D *hResDYJets[5], RooUnfoldResponse *respDYJets[5], TFile *fDYJets[5], TH1D *hRecBg[][5], TH1D *hRecSumBg[5], TFile *fBg[][5], int nBg)
{

    //--- get rec Data histograms ---
    getHistos(hRecData, fData, variable);

    //--- get rec DYJets histograms ---
    getHistos(hRecDYJets, fDYJets, variable);

    //--- get gen DYJets histograms ---
    getHistos(hGenDYJets, fDYJets, "gen" + variable);

    //--- get res DYJets histograms ---
    getHistos(hResDYJets, fDYJets, "hresponse" + variable);

    //--- get response DYJets objects ---
    getResps(respDYJets, fDYJets, variable);

    //--- get rec Bg histograms ---
    for (unsigned short iBg = 0; iBg < nBg; ++iBg) {
        getHistos(hRecBg[iBg], fBg[iBg], variable);
        for (unsigned short iSyst = 0; iSyst < 5; ++iSyst) { 
            if (iSyst == 0) hRecSumBg[iSyst] = (TH1D*) hRecBg[iBg][iSyst]->Clone();
            else hRecSumBg[iSyst]->Add(hRecBg[iBg][iSyst]);
        }
    }


}

//------------------------------------------------------------
// Close the file if open and delete the pointer
//------------------------------------------------------------
void closeFile(TFile *File)
{
    if (File) {
        if (File->IsOpen()) File->Close();
        cout << "Closing: " << File->GetName() << "   --->   Closed ? " << (!(File->IsOpen())) << endl;
    }
}

void closeFiles(TFile *Files[])
{
    if (Files[0]) {
        TString fileName = Files[0]->GetName();
        int nFiles;
        if (fileName.Index("Data") >= 0) {
            nFiles = 3; 
        }
        else nFiles = 5; 

        for (int i(0); i < nFiles; i++){
            closeFile(Files[i]);
        }
    }
}

void closeFiles(TFile *Files[], int nFiles)
{
    TString fileName = Files[0]->GetName();
    for (int i(0); i < nFiles; i++){
        closeFile(Files[i]);
        cout << "Closing file: " << Files[i]->GetName() << "   --->   Closed ? " << (!(Files[i]->IsOpen())) << endl;
    }
}

void closeAllFiles(TFile *fData[3], TFile *fDYJets[5], TFile *fBg[][5], int nBg)
{
    //--- Close data files ---------------------------------------------------------------------
    closeFiles(fData);
    //------------------------------------------------------------------------------------------ 

    //--- Close DYJets files -------------------------------------------------------------------
    closeFiles(fDYJets);
    //------------------------------------------------------------------------------------------ 

    //--- Close Bg files -----------------------------------------------------------------------
    for (unsigned short iBg = 0; iBg < nBg; ++iBg) {
        closeFiles(fBg[iBg]);
    }
    //------------------------------------------------------------------------------------------ 
}

TH1D* getHisto(TFile *File, const TString variable)
{
    TH1D *histo = (TH1D*) File->Get(variable);
    histo->SetDirectory(0);
    return histo;
}

void getHistos(TH1D *histograms[], TFile *Files[], TString variable)
{
    TString fileName = Files[0]->GetName();
    int nFiles;
    if (fileName.Index("Data") >= 0) nFiles = 3; 
    else nFiles = 5;

    for (int i(0); i < nFiles; i++){
        histograms[i] = (TH1D*) Files[i]->Get(variable);
    } 
}

void getHistos(TH2D *histograms[], TFile *Files[], TString variable)
{
    TString fileName = Files[0]->GetName();
    int nFiles;
    if (fileName.Index("Data") >= 0) nFiles = 3; 
    else nFiles = 5;

    for (int i(0); i < nFiles; i++){
        histograms[i] = (TH2D*) Files[i]->Get(variable);
    } 
}

void getResp(RooUnfoldResponse *response, TFile *File, TString variable)
{
    response = new RooUnfoldResponse(
            (TH1D*) File->Get(variable), 
            (TH1D*) File->Get("gen" + variable), 
            (TH2D*) File->Get("hresponse" + variable)
            ); 
    if (!response) std::cout << "Couldn't load response" << std::endl;
}

RooUnfoldResponse* getResp(TFile *File, TString variable)
{
    RooUnfoldResponse *response = new RooUnfoldResponse(
            (TH1D*) File->Get(variable), 
            (TH1D*) File->Get("gen" + variable), 
            (TH2D*) File->Get("hresponse" + variable)
            ); 
    return response;
}

void getResps(RooUnfoldResponse *responses[], TFile *Files[], TString variable)
{
    TString fileName = Files[0]->GetName();
    int nFiles;
    if (fileName.Index("Data") >= 0) nFiles = 3; 
    else nFiles = 5;

    for (int i(0); i < nFiles; i++){
        responses[i] = new RooUnfoldResponse(
                (TH1D*) Files[i]->Get(variable), 
                (TH1D*) Files[i]->Get("gen" + variable), 
                (TH2D*) Files[i]->Get("hresponse" + variable)
                ); 
    } 
}


void getStatistics(TString lepSel, int jetPtMin, int jetEtaMax)
{
    TString variable = "ZNGoodJets_Zexc";
    TString energy = getEnergy();

    //--- make sure lepSel is short version ---
    if (lepSel == "Muons" || lepSel == "DMu_") lepSel = "DMu";
    else if (lepSel == "Electrons" || lepSel == "DE_") lepSel = "DE";
    //-----------------------------------------------

    // jet counter
    int NBins = 8;
    double DataEv[20][20] = {{0}};

    //-- fetch the data files and histograms --------------
    int usedFiles = NFILESDYJETS; 

    for (int i(0); i < usedFiles; i++) {
        TFile *fData;
        int sel = FilesDYJets[i];

        fData = getFile(FILESDIRECTORY,  lepSel, energy, Samples[sel].name, jetPtMin, jetEtaMax);
        TH1D *hTemp = getHisto(fData, variable);

        for (int j = 1 ; j < NBins + 1 ; j++ ){
            Double_t binContent = hTemp->GetBinContent(j);
            DataEv[i][j] = binContent;
            if ( i > 0 ) DataEv[usedFiles][j]+=int(binContent);
        }
        // close all input root files
        fData->Close();
    }

    cout << "Closed all files" << endl;

    ostringstream nameStr;
    nameStr << "outputTable_" << lepSel << "_JetPtMin_" << jetPtMin << "_JetEtaMax_" << jetEtaMax;
    nameStr << ".tex";

    FILE *outFile = fopen(nameStr.str().c_str(),"w");
    fprintf( outFile, "\\footnotesize{\n\\begin{tabular}{l|cccccccc} \n ");
    fprintf( outFile, " &  $N_{\\text{jets}} = 0 $ & $N_{\\text{jets}} = 1 $ & $N_{\\text{jets}} = 2 $ & $N_{\\text{jets}} = 3 $ & $N_{\\text{jets}} = 4 $ & $N_{\\text{jets}} = 5 $ & $N_{\\text{jets}} = 6 $ & $N_{\\text{jets}} = 7$ \\\\ \\hline \n ");

    //// print statistics of all the MC samples
    for (int i=1; i< usedFiles + 1 ; i++){
        int sel = FilesDYJets[i];

        if (i < usedFiles) fprintf(outFile, " %s        & ", Samples[sel].legendAN.Data());
        else {
            fprintf( outFile, "\\hline \n");
            fprintf( outFile, " TOTAL & ");
        }
        for (int j = 1 ; j < NBins + 1  ; j++ ) {
            if (j < NBins ) fprintf( outFile, "%d & ", int(DataEv[i][j]));
            else fprintf( outFile, "%d \\\\ \n ", int(DataEv[i][j]));

        }
        std::cout << std::endl;
    }

    // print data statistics
    fprintf( outFile, "\\hline \n");
    fprintf( outFile, " Data          & ");
    for (int j = 1; j< NBins + 1 ; j++){
        if (j < NBins ) fprintf( outFile, "%d & ",  int(DataEv[0][j]));
        else fprintf( outFile, "%d \\\\ \n ",  int(DataEv[0][j]));
    }
    // print ratio of MC/data
    fprintf( outFile, " Ratio          & ");
    for (int j=1; j<NBins + 1; j++){
        double temp= DataEv[usedFiles][j]/DataEv[0][j];
        std:: cout << DataEv[usedFiles][j] << "   " << DataEv[0][j] << std::endl;
        if (j<NBins) fprintf( outFile, "%f & ", float(temp));
        else fprintf( outFile, "%f \\\\ \n ",temp);

    }
    fprintf( outFile, "\\end{tabular}}");
    fclose(outFile);
}



