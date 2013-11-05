#include <iostream>
#include <sstream>
#include <RooUnfoldResponse.h>
#include <TFile.h>
#include "fileNames.h"
#include "getFilesAndHistograms.h"

using namespace std;

string getEnergy()
{
   string energy = "";
   ostringstream fileBeingProcessed; fileBeingProcessed << __FILE__;
   if (fileBeingProcessed.str().find("Analysis2012") != string::npos) {
      cout << "This is 2012 !" << endl;
      energy = "8TeV";
   }
   else if (fileBeingProcessed.str().find("Analysis2011") != string::npos) {
      cout << "This is 2011 !" << endl;
      energy = "7TeV";
   }
   else 
   {
      cout << "WARNING ! Impossible to retrieve te energy form the current location !" << endl;
   }
   fileBeingProcessed.str("");

   return energy;
}

TFile* getFile(string histoFilesDirectory, string leptonFlavor, string energy, string Name, int JetPtMin, int JetPtMax, bool doFlat, bool doVarWidth, int doQCD,  bool doSSign,  bool doInvMassCut,  string closureTest, string syst, bool dodR)
{
   if (leptonFlavor == "Muons" || leptonFlavor == "DMu_") leptonFlavor = "DMu";
   else if (leptonFlavor == "Electrons" || leptonFlavor == "DE_") leptonFlavor = "DE";
   else if (leptonFlavor == "Muon" || leptonFlavor == "SMu") leptonFlavor = "SMu";
   else if (leptonFlavor == "Electron" || leptonFlavor == "SE_") leptonFlavor = "SE";
   else if (leptonFlavor == "MuonElectron" || leptonFlavor == "SMuE_") leptonFlavor = "SMuE";

   ostringstream JetPtMinStr;  JetPtMinStr << JetPtMin;
   ostringstream JetPtMaxStr;  JetPtMaxStr << JetPtMax;
   ostringstream doQCDStr ; doQCDStr << doQCD ;

   string effiCorr = "1", trigCorr = "0";
   if (Name.find("Data") == 0) effiCorr = "0";
   if ( useUnfoldingFiles ){
	 effiCorr = "0";
	 if (Name.find("Data") == 0) effiCorr = "1";
   }
   if (Name.find("Data") == 0 || energy == "8TeV") trigCorr = "1";
   if (Name.find("HepMC") !=  string::npos ||  Name.find("UNF")  !=  string::npos )  trigCorr = "1";
   if (Name.find("HepMC") !=  string::npos || Name.find("Powh") !=  string::npos) {trigCorr = "0"; effiCorr = "0";}

   string fileName = histoFilesDirectory + leptonFlavor + "_" + energy + "_" + Name;
   fileName += "_EffiCorr_" + effiCorr + "_TrigCorr_" + trigCorr + "_Syst_" + syst + "_JetPtMin_" + JetPtMinStr.str();
   if (JetPtMax != 0 && JetPtMax > JetPtMin) fileName += "_JetPtMax_" + JetPtMaxStr.str();
   if (doFlat && Name.find("Data") == string::npos) fileName += "_Flat";
   fileName += closureTest;
   if (doVarWidth )  fileName += "_VarWidth";
   if ( dodR ) fileName += "_dR5";
   if (doInvMassCut) fileName += "_InvMass";
   if (doSSign )   fileName += "_SS";
/*   if ( doQCD > 0){
	if ( leptonFlavor == "SMuE") fileName +="_SS";
	else  fileName += "_QCD" + doQCDStr.str();
   }
*/
    if (doQCD>0) fileName += "_QCD" + doQCDStr.str();
//   if (doInvMassCut)  fileName += "_InvMass";
   fileName += ".root";

   TFile *File; 
   File = new TFile(fileName.c_str(), "READ");
   cout << "Opening: " << fileName << "   --->   Opened ? " << File->IsOpen() << endl;
   return File; 
}

void getFiles(string histoFilesDirectory, TFile *Files[], string leptonFlavor, string energy, string Name, int JetPtMin, int JetPtMax, bool doFlat,  bool doVarWidth, int doQCD, bool doInvMassCut )
{
   if (leptonFlavor == "Muons" || leptonFlavor == "DMu_") leptonFlavor = "DMu";
   else if (leptonFlavor == "Electrons" || leptonFlavor == "DE_") leptonFlavor = "DE";

   vector<string> Syst;
   if (Name.find("Data") != string::npos){ 
      Syst.push_back("0");
      Syst.push_back("2_Up");
      Syst.push_back("2_Down");
   }
   else if (Name.find("UNFOLDING") != string::npos){
      Syst.push_back("0");
      Syst.push_back("1_Up");
      Syst.push_back("1_Down");
      Syst.push_back("4_Up");
   }
   else {
      Syst.push_back("0");
      Syst.push_back("1_Up");
      Syst.push_back("1_Down");
      Syst.push_back("3_Up");
      Syst.push_back("3_Down");
   };

   int nSyst(Syst.size());

   for (int i(0); i < nSyst; i++) {
      Files[i] = getFile(histoFilesDirectory, leptonFlavor, energy, Name, JetPtMin, JetPtMax, doFlat, doVarWidth , doQCD, doInvMassCut, "", Syst[i]);
   }

}




void closeFile(TFile *File){
   if (File->IsOpen()) File->Close();
   cout << "Closing file: " << File->GetName() << "   --->   Closed ? " << (!(File->IsOpen())) << endl;
}

void closeFiles(TFile *Files[])
{
   string fileName = Files[0]->GetName();
   int nFiles;
   if (fileName.find("Data") != string::npos) nFiles = 3; 
   else if (fileName.find("UNFOLDING") != string::npos) nFiles = 4; 
   else nFiles = 5;

   for (int i(0); i < nFiles; i++){
      closeFile(Files[i]);
   }
}

TH1D* getHisto(TFile *File, string variable)
{
   TH1D *histo = (TH1D*) File->Get(variable.c_str());
   return histo;
}

void getHistos(TH1D *histograms[], TFile *Files[], string variable)
{
   string fileName = Files[0]->GetName();
   int nFiles;
   if (fileName.find("Data") != string::npos) nFiles = 3; 
   else if (fileName.find("UNFOLDING") != string::npos) nFiles = 4; 
   else nFiles = 5;

   for (int i(0); i < nFiles; i++){
      histograms[i] = (TH1D*) Files[i]->Get(variable.c_str());
   } 
}

void getResp(RooUnfoldResponse *response, TFile *File, string variable)
{
   response = (RooUnfoldResponse*) File->Get(variable.c_str());
   if (!response) cout << "Couldn't load response" << endl;
}

RooUnfoldResponse* getResp(TFile *File, string variable)
{
   RooUnfoldResponse *response = (RooUnfoldResponse*) File->Get(variable.c_str());
   return response;
}

void getResps(RooUnfoldResponse *responses[], TFile *Files[], string variable)
{
   string fileName = Files[0]->GetName();
   int nFiles;
   if (fileName.find("Data") != string::npos) nFiles = 3; 
   else if (fileName.find("UNFOLDING") != string::npos) nFiles = 4; 
   else nFiles = 5;

   for (int i(0); i < nFiles; i++){
      responses[i] = (RooUnfoldResponse*) Files[i]->Get(variable.c_str());
   } 
}


void getStatistics(string leptonFlavor, int JetPtMin, int JetPtMax, bool doFlat, bool doVarWidth, int doQCD, bool doSSign, bool doInvMassCut){
	std::string  variable = "ZNGoodJets_Zexc";
	string energy = getEnergy();

	cout <<" let us get jet multiplicity statistics " <<endl;
	// jet counter
	int NBins = 0 ;
	double DataEv[20][20] = {{0}};
	
	//-- fetch the data files and histograms --------------
	int usedFiles = NFILESWJETS ; 
	bool doDY(0) ;
	if (leptonFlavor.find("Muons") != string::npos ||  leptonFlavor.find("Electrons") != string::npos){
        usedFiles = NFILESDYJETS; 
        doDY = true;
    }
	for (int i = 0; i < usedFiles; i++){
		TFile *fData;           
		int sel = i;   
        if (doDY) sel = FilesDYJets[i];
		fData = getFile(FILESDIRECTORY, leptonFlavor, energy, ProcessInfo[sel].filename, JetPtMin, JetPtMax, doFlat, doVarWidth, doQCD, doSSign, doInvMassCut, "", "0");
		TH1D *hTemp = getHisto(fData, variable);
		//NBins = hTemp ->GetNbinsX();

		NBins = 8 ; /// FIXED !!!!

		for (int j = 1 ; j < NBins + 1 ; j++ ){
			Double_t binContent = hTemp->GetBinContent(j);
			DataEv[i][j] = binContent;
			if ( i > 0 ) DataEv[usedFiles][j]+=int(binContent);
		}
        // close all input root files
        fData->Close();
	}

cout << "Closed all files" << endl;

ostringstream nameStr;  nameStr << "outputTable_" << leptonFlavor <<"_JetPtMin_" <<JetPtMin;
if (doInvMassCut) nameStr << "_InvMass";
if (doSSign )   nameStr << "_SS";
//if (doBJets) nameStr << "_BJets";
if (doQCD>0) nameStr << "_QCD"<<doQCD;

nameStr<<".tex";

FILE *outFile = fopen(nameStr.str().c_str(),"w");
fprintf( outFile, "\\footnotesize{\n\\begin{tabular}{l|cccccccc} \n ");
fprintf( outFile, " &  $N_{\\text{jets}} = 0 $ & $N_{\\text{jets}} = 1 $ & $N_{\\text{jets}} = 2 $ & $N_{\\text{jets}} = 3 $ & $N_{\\text{jets}} = 4 $ & $N_{\\text{jets}} = 5 $ & $N_{\\text{jets}} = 6 $ & $N_{\\text{jets}} = 7$ \\\\ \\hline \n ");

//// print statistics of all the MC samples
for (int i=1; i< usedFiles + 1 ; i++){
	int sel = i ;   if ( doDY ) sel = FilesDYJets[i];
	if ( i < usedFiles )	fprintf( outFile, " %s        & ", ProcessInfo[sel].legend.c_str()  );
	else {
		fprintf( outFile, "\\hline \n");
		fprintf( outFile, " TOTAL & ");
	}
	for (int j = 1 ; j < NBins + 1  ; j++ ) {
		if (j < NBins ) fprintf( outFile, "%d & ", int(DataEv[i][j]));
		else fprintf( outFile, "%d \\\\ \n ", int(DataEv[i][j]));

	}
	cout << endl;
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
    cout << DataEv[usedFiles][j]<<"   " <<DataEv[0][j]<< endl;
    if (j<NBins) fprintf( outFile, "%f & ", float(temp));
    else fprintf( outFile, "%f \\\\ \n ",temp);

  }

fprintf( outFile, "\\end{tabular}}");
fclose(outFile);



}

