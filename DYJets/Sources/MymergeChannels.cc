#include <TFile.h>
#include <TCanvas.h>
#include <TMatrixD.h>
#include <TVectorD.h>
#include <TDecompLU.h>
#include <TDecompSVD.h>
#include <TSystem.h>
#include <TLegend.h>
#include <TLegendEntry.h>
#include <TGraphAsymmErrors.h>
#include <TLatex.h>
#include <TPaveText.h>
#include <iostream>
#include <TH1.h>
#include <TH2.h>
#include <TPad.h>
#include <TGraph.h>
#include <TStyle.h>
#include <TMath.h>
#include <TString.h>
#include <fstream>
#include <sstream>
#include <iomanip> 
#include <RooUnfoldResponse.h>
#include <RooUnfoldSvd.h>
#include <RooUnfoldBayes.h>
#include <RooUnfoldBinByBin.h>
#include <RooUnfoldInvert.h>
#include <TSVDUnfold.h>
#include "unfoldingFunctions.h"
#include "fileNames.h"
#include "getFilesAndHistograms.h"
#include "variablesOfInterestVarWidth.h"
#include "UnfoldingError.h"
#include "makeZJetsPlots.h"
#include "setTDRStyle.h"

#define DEBUG              0
using namespace std;


//-- prototypes ---------------------------------------------------------------------------------//
void mergeChannelsRun(string var = "ZNGoodJets_Zexc", bool logZ = 0, bool decrease = 0);
void plotLepRatioComb(string variable, TH1D* h_combine, TH1D* hMuon, TH1D* hEle);
void plotCombination(string variable, TH1D* hCombinedStat, TH1D* hCombinedTot, TH1D* genMadTemp[], TH1D* genSheTemp[], TH1D* genPowTemp[]);
void dumpElements(TMatrixD& a);
void dumpElements(TVectorD& a);
//-----------------------------------------------------------------------------------------------//

//-- global variables ---------------------------------------------------------------------------//
string VARIABLE  =   "ZNGoodJets_Zexc" ;
string OUTPUTDIRECTORY = "PNGFiles/NiceUnfold_2_1000_Toys/";

int optionCorr = 2;      
// 0 - simple weighted average, 
// 1 - full cov matrix for each channel 
// 2 - full cov matrix for each channel and  correlation = 1 for same bins in the two channels 
// 3 - full cov matrix for each channel is geometric average for two channels (for each bin)  
// 4 - full cov matrix for each channel and  correlation = 1 for ALL bins between the two channels 

bool LOGZ = 0, DECREASE = 0;
int doXSec  =  1;
int doNormalize  =  0;
double Luminosity(19549.);
bool doVarWidth  =  true ;
double mergedValuesAllOpt[30][10] = {{0}};
double mergedErrorsAllOpt[30][10] = {{0}};
int tempNBin = 0;
int kCorrMax = 1; 
int SelComb[] = {0,1,3,4,5} ; //selection Of Combination Opi
//-----------------------------------------------------------------------------------------------//


//--- Main function -----------------------------------------------------------------------------//
void MymergeChannels(int start = 0, int end = -1)
{
    setTDRStyle();
    gStyle->SetOptStat(0);
    gStyle->SetErrorX(0.5);
    gStyle->SetPadGridX(0);
    gStyle->SetPadGridY(0);

    if (end == -1) end = start + 1;
    for (int i(start); i < end/*NVAROFINTERESTZJETS*/; i++){
        std::cout << "Processing variable n°: " << i << "  " << VAROFINTERESTZJETS[i].name << std::endl;
        for (int k(0); k < kCorrMax; k++){
            optionCorr = SelComb[k];
            mergeChannelsRun(VAROFINTERESTZJETS[i].name, VAROFINTERESTZJETS[i].log, VAROFINTERESTZJETS[i].decrease);
        }
    }
}
//-----------------------------------------------------------------------------------------------//

//-----------------------------------------------------------------------------------------------//
void mergeChannelsRun(string var, bool logZ, bool decrease)
{
    string ENERGY =  getEnergy();
    string unfAlg  =  "Bayes";
    LOGZ = logZ; 
    DECREASE = decrease;
    VARIABLE = var;
    TH1::SetDefaultSumw2();

    //-- fetch Muon and Electron files produced by FinalUnfold.cc ---------------------
    string fileNameEl = "PNGFiles/FinalUnfold_30_1000_Toys/DE_"  + ENERGY + "_unfolded_" + VARIABLE + "_histograms_Bayes_VarWidth.root";
    string fileNameMu = "PNGFiles/FinalUnfold_30_1000_Toys/DMu_" + ENERGY + "_unfolded_" + VARIABLE + "_histograms_Bayes_VarWidth.root";

    TFile *f[2];
    f[0] = new TFile(fileNameEl.c_str());
    f[1] = new TFile(fileNameMu.c_str());
    //---------------------------------------------------------------------------------

    //-- Retrieve histograms from the files -------------------------------------------
    TH1D *dataReco[2], *dataCentral[2], *dataUnfWithSherpa[2], *unfErrorDistr[2], *dataCentralOppAlgo[2], *genMad[2], *genShe[2], *genPow[2];
    TH1D *dataPUup[2], *dataPUdown[2], *dataJERup[2], *dataPU[2], *dataJER[2];
    TH2D *myToyStatCov[2], *myToyJESCov[2], *myToyPUCov[2], *myToyXSECCov[2], *myToyJERCov[2], *myToyEFFCov[2], *myToyLUMICov[2];

    double luminosityErr = 0.026;

    //--- loop to run on muon (i=1) and electron (i=0) ---
    for (int i(0); i < 2; i++) {
        dataReco[i]           = (TH1D*) f[i]->Get("Data");
        dataCentral[i]        = (TH1D*) f[i]->Get("Central");
        dataUnfWithSherpa[i]  = (TH1D*) f[i]->Get("unfWithSherpa");
        dataCentralOppAlgo[i] = (TH1D*) f[i]->Get("oppCentral");
        genMad[i]             = (TH1D*) f[i]->Get("genMad");
        genShe[i]             = (TH1D*) f[i]->Get("genShe");
        genPow[i]             = (TH1D*) f[i]->Get("genPow");

        dataPUup[i]           = (TH1D*) f[i]->Get("PUup");
        dataPUdown[i]         = (TH1D*) f[i]->Get("PUdown");
        dataJERup[i]          = (TH1D*) f[i]->Get("JERup");
        myToyStatCov[i]       = (TH2D*) f[i]->Get("MyToyCov");
        myToyJESCov[i]        = (TH2D*) f[i]->Get("MyToyJESCov");
        myToyPUCov[i]         = (TH2D*) f[i]->Get("MyToyPU2Cov");
        myToyXSECCov[i]       = (TH2D*) f[i]->Get("MyToyXSECCov");
        myToyJERCov[i]        = (TH2D*) f[i]->Get("MyToyJER2Cov");
        myToyEFFCov[i]        = (TH2D*) f[i]->Get("MyToyEFFCov");

        //--- call errors from unfolding with Sherpa and MadGraph ----
        unfErrorDistr[i] = getErrors(dataCentral[i], dataUnfWithSherpa[i]);

        //--- compute error for PU ---
        dataPU[i] = getPUErrors(dataCentral[i], dataPUup[i], dataPUdown[i]);

        //--- compute error for JER ---
        dataJER[i] = getJERErrors(dataCentral[i], dataJERup[i]);

        // set covariance for luminosity uncertainty --> take correlation from JES and rescale
        myToyLUMICov[i] = setCovariance(myToyJESCov[i], dataCentral[i], luminosityErr);

    }
    //---------------------------------------------------------------------------------

    TH1D* h_combine = (TH1D*) dataReco[0]->Clone();
    h_combine->SetDirectory(0);

    // declare the big matrix
    int nbins = dataCentral[0]->GetNbinsX();
    tempNBin = nbins;
    //nbins =  8 ;
    const int NELE = 2 * nbins;
    TMatrixD errorM(NELE, NELE);

    TMatrixD U(NELE, nbins);
    for(int irow = 0; irow < NELE; irow++) {
        for(int icol = 0; icol < nbins; icol++) {
            U(irow,icol) = ((irow == icol) || (irow == icol + nbins));
        }
    }

    // debug
    if (DEBUG) dumpElements(U);

    TMatrixD transposeU(nbins,NELE);
    transposeU.Transpose(U);
    if (DEBUG) dumpElements(transposeU);

    TVectorD measurement(NELE);
    // jet energy scale for electron channel
    TVectorD jesSys_ele(nbins);
    TVectorD jesSys_muo(nbins);


    ////////////////////////////////////////////////////////////////////////////////

    // set correlation between channels
    double correlationSameBin = 0.;
    double correlationDiffBin = 0.;
    if (optionCorr == 1) correlationSameBin = 0.;
    if (optionCorr == 2) correlationSameBin = 1.;
    if (optionCorr == 3) correlationSameBin = 1.;
    if (optionCorr == 4) {
        correlationSameBin = 1.;
        correlationDiffBin = 1.;
    }

    /// calculate statistical contribution to error
    int optStat = 0 ; 
    if (optionCorr > 0) optStat = 1;
    TMatrixD covMatrixStat = getCovMatrixOfCombination(myToyStatCov[0], myToyStatCov[1], optStat, 1);
    TMatrixD covMatrixJES  = getCovMatrixOfCombination(myToyJESCov[0], myToyJESCov[1], optionCorr, 1);
    TMatrixD covMatrixPU   = getCovMatrixOfCombination(myToyPUCov[0], dataPU[0], dataPU[1], optionCorr, 1);
    //TMatrixD covMatrixPU   = getCovMatrixOfCombination(myToyPUCov[0], myToyPUCov[1], optionCorr, 1);
    TMatrixD covMatrixXSEC = getCovMatrixOfCombination(myToyXSECCov[0], myToyXSECCov[1], optionCorr, 1);
    TMatrixD covMatrixJER  = getCovMatrixOfCombination(myToyJERCov[0], dataJER[0], dataJER[1], optionCorr, 1);
    //TMatrixD covMatrixJER  = getCovMatrixOfCombination(myToyJERCov[0], myToyJERCov[1], optionCorr, 1);
    TMatrixD covMatrixUNF  = getCovMatrixOfCombinationUNF(unfErrorDistr[0], unfErrorDistr[1], dataCentral[0], dataCentral[1], dataCentralOppAlgo[0], dataCentralOppAlgo[1], optionCorr, 1);

    TMatrixD covMatrixLUMI = setCovMatrixOfCombination(luminosityErr, dataCentral[0], dataCentral[1], optionCorr);
    TMatrixD covMatrixLEP  = getCovMatrixOfCombination(myToyEFFCov[0], myToyEFFCov[1], optStat, 1); // two  leptons are independednt

    // create total covariance matrix
    // sum all matrices
    errorM = covMatrixStat;
    errorM += covMatrixJES; 
    errorM += covMatrixPU;
    errorM += covMatrixXSEC;
    errorM += covMatrixJER;
    errorM += covMatrixLEP;

    // if ( doXSec )  errorM += covMatrixLUMI ; // WE SHOULD ADD THIS AFTER COMBINATION ?
    // there is something shity when you use full covariance (options 3, 4 ) of luminosity --> correlation of ALL bins =1 
    // test this with  unmarking line below
    //errorM = covMatrixLUMI ;


    //errorM = covMatrixJES;
    //errorM = covMatrixXSEC;
    // now loop over bins to set the matrix content
    double norm = 1.; // this I use to have a reasonable value for determinant ( not needed in general) -> important for inversion so that matrices don't deal with small/big numbers
    for(int ibin = 0; ibin<nbins; ibin++){
        // electron channel
        double value_e = dataCentral[0]->GetBinContent(ibin+1);
        // muon channel
        double value_m = dataCentral[1]->GetBinContent(ibin+1);
        measurement(ibin) = value_e / norm;
        measurement(nbins+ibin) = value_m / norm;
    }

    // add unfolding covariance matrix
    errorM += covMatrixUNF;

    // rescale error matrix for numerics, so the numbers are not to big (or small). should not effect resuls.
    for(int ibin = 0; ibin < 2 * nbins; ibin++){
        for(int jbin = 0; jbin < 2 * nbins; jbin++){
            errorM(ibin,jbin) = errorM(ibin,jbin) /(norm * norm );
        }
    }

    TMatrixD errorInverse  =  errorM;
    if (DEBUG) dumpElements(errorInverse);

    double* det = NULL;
    errorInverse.Invert(det);
    if (DEBUG) dumpElements(errorInverse);

    TMatrixD matrixRight(nbins,NELE);  
    matrixRight = transposeU*errorInverse;
    if (DEBUG) dumpElements(matrixRight);
    if (DEBUG) dumpElements(transposeU);

    TMatrixD matrixLeft(nbins,nbins);
    matrixLeft = transposeU*(errorInverse*U);
    TMatrixD matrixLeft1(2*nbins,nbins);
    matrixLeft1 = (errorInverse*U);

    if (DEBUG)  dumpElements(matrixLeft);

    TDecompSVD svd(matrixLeft);
    TMatrixD matrixLeftInverse = svd.Invert();

    if (DEBUG)  dumpElements(matrixLeftInverse);

    TMatrixD lambda(nbins,NELE);
    lambda = matrixLeftInverse*matrixRight;
    if (DEBUG) dumpElements(lambda);

    TMatrixD transposeLambda(NELE,nbins);
    transposeLambda.Transpose(lambda);
    if (DEBUG) dumpElements(transposeLambda);

    TVectorD combined_value(nbins);
    combined_value = lambda*measurement;
    if (DEBUG) dumpElements(combined_value);

    TMatrixD combined_error_LUMI(nbins,nbins);
    TMatrixD combined_error(nbins,nbins);
    combined_error = lambda*(errorM*transposeLambda);

    // after all matrix operation, now set the histogram
    // store combined result and all the individual contributions to error in vector
    double result[10][10];
    for(int i(0); i < nbins; i++){

        h_combine->SetBinContent(i+1, combined_value(i) * norm );
        combined_error_LUMI(i,i) = pow(luminosityErr * combined_value(i) * norm , 2 );
        double error  =  combined_error(i,i) * norm * norm + combined_error_LUMI(i,i);
        /// add luminosity error to the combination result instead of each of channels before the combination
        //		error +=  pow(luminosityErr *  h_combine->GetBinContent(i+1),2 ) ;
        if (error > 1e-10) error = sqrt(error);
        else error = 1e-10;

        h_combine->SetBinError(i+1,error);
        mergedValuesAllOpt[i][optionCorr] = h_combine->GetBinContent(i+1);
        mergedErrorsAllOpt[i][optionCorr] = error;

        result[0][i] = h_combine->GetBinContent(i);
        result[1][i] = error;
    }
    /// NOW ADD LUMI ERRORS TO COMBINATION
    combined_error += combined_error_LUMI;

    /// set covariance matrices for individual errors
    //int optStat = 0 ; if (optionCorr > 0 ) optStat = 1 ;
    //TMatrixD covMatrixStat = getCovMatrixOfCombination(myToyStatCov[0],myToyStatCov[1], optStat , 1 );	
    TMatrixD combined_error_stat(nbins,nbins);
    TMatrixD combined_error_JES(nbins,nbins);
    TMatrixD combined_error_PU(nbins,nbins);
    TMatrixD combined_error_XSEC(nbins,nbins);
    TMatrixD combined_error_JER(nbins,nbins);
    TMatrixD combined_error_UNF(nbins,nbins);
    TMatrixD combined_error_LEP(nbins,nbins);

    combined_error_stat = lambda * (covMatrixStat * transposeLambda);
    combined_error_JES  = lambda * (covMatrixJES * transposeLambda);
    combined_error_PU   = lambda * (covMatrixPU * transposeLambda);
    combined_error_XSEC = lambda * (covMatrixXSEC * transposeLambda);
    combined_error_JER  = lambda * (covMatrixJER * transposeLambda);
    combined_error_UNF  = lambda * (covMatrixUNF * transposeLambda);
    combined_error_LEP  = lambda * (covMatrixLEP * transposeLambda);
    //	combined_error_LUMI  =  lambda * (covMatrixLUMI * transposeLambda); // 
    // 	combined_error_LUMI = setCovMatrixOfCombination(luminosityErr, (TH1D*) h_combine->Clone(), (TH1D*) h_combine->Clone() , 0);


    TH2D* allErrorsTH2[9];
    allErrorsTH2[0] = new TH2D(combined_error);
    allErrorsTH2[1] = new TH2D(combined_error_stat);
    allErrorsTH2[2] = new TH2D(combined_error_JES);
    allErrorsTH2[3] = new TH2D(combined_error_PU);
    allErrorsTH2[4] = new TH2D(combined_error_XSEC);
    allErrorsTH2[5] = new TH2D(combined_error_JER);
    allErrorsTH2[6] = new TH2D(combined_error_LUMI);
    allErrorsTH2[7] = new TH2D(combined_error_UNF);
    allErrorsTH2[8] = new TH2D(combined_error_LEP);


    // lets create som tables
    ostringstream optionCorrStr; optionCorrStr << optionCorr ;

    string command = "mkdir -p " + OUTPUTDIRECTORY;
    system(command.c_str());
    string fileNameTable = OUTPUTDIRECTORY + "/TableSystematics_" + ENERGY + "_" + VARIABLE + "_" + unfAlg;
    fileNameTable += "_CorrelationOption_" + optionCorrStr.str();
    if (doVarWidth) fileNameTable += "_VarWidth";
    fileNameTable += ".tex";
    createTexTable(VARIABLE, fileNameTable, h_combine, allErrorsTH2, doXSec, doNormalize, Luminosity);
    // end table creation


    // create combination histogram with statistical errors
    TH1D* h_combine_stat = SetHistWithErrors(h_combine, combined_error_stat, "Stat");

    /// PLOT COMPARISON OF ELECTRONS AND MUONS TO COMBINED
    //plotLepRatioComb(VARIABLE, (TH1D*) h_combine->Clone(), (TH1D*) dataCentral[0]->Clone(),(TH1D*) dataCentral[1]->Clone() );

    /// PLOT FINAL PLOTS: COMBINATION VS MC
    plotCombination(VARIABLE, (TH1D*) h_combine_stat->Clone(), (TH1D*) h_combine->Clone(), genMad, genShe, genPow);

    std::cout << f[0]->IsOpen() << std::endl;
    std::cout << f[1]->IsOpen() << std::endl;

    f[0]->Close();
    f[1]->Close();

    std::cout << f[0]->IsOpen() << std::endl;
    std::cout << f[1]->IsOpen() << std::endl;
}


//////////////////////////////////
void plotCombination(string variable, TH1D* hCombinedStat, TH1D* hCombinedTot, TH1D* genMadTemp[], TH1D* genSheTemp[], TH1D* genPowTemp[])
{

    //--- fetch the generated histograms for electrons ([0]) and muons ([1]) 
    // and add theim together ---
    TH1D* genMad = (TH1D*) genMadTemp[0]->Clone();
    genMad->SetDirectory(0);
    TH1D* genShe = (TH1D*) genSheTemp[0]->Clone();
    genShe->SetDirectory(0);
    TH1D* genPow = (TH1D*) genPowTemp[0]->Clone();
    genPow->SetDirectory(0);
    genMad->Add(genMadTemp[1]);
    genMad->Scale(0.5);
    genShe->Add(genSheTemp[1]);
    genShe->Scale(0.5);
    genPow->Add(genPowTemp[1]);
    genPow->Scale(0.5);
    //-----------------------------

    //--- load PDF systematic file ---
    string genVariable = "gen" + variable;
    string PDFfileName = "PDFSystFiles/PDFSyst_" + genVariable + ".root";
    TFile *fPDF = new TFile(PDFfileName.c_str());

    // get histograms from PDF file
    TH1D *hPDF = (TH1D*) fPDF->Get(genVariable.c_str());
    hPDF->SetTitle("");

    const int nBins(hCombinedStat->GetNbinsX());
    // renormalize first
    if (doXSec) {
        for (int i(1); i <= nBins; i++){ 
            double binW = hCombinedStat->GetBinWidth(i);
            hCombinedStat->SetBinContent(i, hCombinedStat->GetBinContent(i)*1./(Luminosity*binW));
            hCombinedTot->SetBinContent(i, hCombinedTot->GetBinContent(i)*1./(Luminosity*binW));
            genMad->SetBinContent(i, genMad->GetBinContent(i)*1./(Luminosity*binW));
            genShe->SetBinContent(i, genShe->GetBinContent(i)*1./(Luminosity*binW));
            genPow->SetBinContent(i, genPow->GetBinContent(i)*1./(Luminosity*binW));

            hCombinedStat->SetBinError(i, hCombinedStat->GetBinError(i)*1./(Luminosity*binW));
            hCombinedTot->SetBinError(i, hCombinedTot->GetBinError(i)*1./(Luminosity*binW));
            genMad->SetBinError(i, genMad->GetBinError(i)*1./(Luminosity*binW));
            genShe->SetBinError(i, genShe->GetBinError(i)*1./(Luminosity*binW));
            genPow->SetBinError(i, genPow->GetBinError(i)*1./(Luminosity*binW));

            if (DEBUG) cout << i << "   "  << hCombinedTot->GetBinContent(i)  << "     "   <<  hCombinedStat->GetBinError(i) << "     "  <<  hCombinedTot->GetBinError(i)   << endl;
            if (DEBUG) cout << i << "   "  << hCombinedTot->GetBinContent(i)  << "     "   <<genPow->GetBinContent(i)  << "     "   <<  hCombinedStat->GetBinError(i) << "     "  <<  genPow->GetBinError(i)   << endl;
        }
    }

    TCanvas *plots = makeZJetsPlots(hCombinedStat, hCombinedTot, hPDF, genShe, genPow, genMad);

    string outputFileNamePNG  =  OUTPUTDIRECTORY;
    if (doXSec) outputFileNamePNG +=  "Combination_XSec_";
    else if (doNormalize)  outputFileNamePNG +=  "Combination_Normalized_";

    outputFileNamePNG +=  variable;
    ostringstream optionCorrStr; optionCorrStr << optionCorr;
    outputFileNamePNG +="_CorrelationOption_" + optionCorrStr.str();
    if (doVarWidth)  outputFileNamePNG += "_VarWidth";
    outputFileNamePNG +=  ".pdf";

    plots->Print(outputFileNamePNG.c_str());

    fPDF->Close();

}


//////////////////////// NICE plots
void plotLepRatioComb(string variable, TH1D* hCombined,  TH1D* hEle , TH1D* hMuon){

    TH1D* hCombErr = (TH1D *) hCombined ->Clone();
    hCombErr->GetYaxis()->SetTitle("");
    /*	if ( doXSec   ==   1 ){
        h_combine->Scale(1/(hCombined->GetBinWidth(1)*Luminosity));
        dataCentral[0]->Scale(1/(h_combine->GetBinWidth(1)*Luminosity));
        dataCentral[1->Scale(1/(h_combine->GetBinWidth(1)*19380.));
        }
        */
    const int nBins =  hCombined->GetNbinsX();	
    double xCoor[nBins], yCoor[nBins], xErr[nBins], yStat[nBins];
    double yCoorMuonRatio[nBins], yStatMuonRatio[nBins], ySystDownMuonRatio[nBins], ySystUpMuonRatio[nBins];
    double yCoorEleRatio[nBins], yStatEleRatio[nBins], ySystDownEleRatio[nBins], ySystUpEleRatio[nBins];

    for(int bin = 1; bin  <=   nBins; bin++){
        hCombErr->SetBinContent(bin , 1 );
        double ErrCom = hCombined->GetBinError(bin) / hCombined->GetBinContent(bin)  ;
        hCombErr->SetBinError(bin , ErrCom );
        if (DEBUG ) cout << " Error : " << ErrCom << "  "  <<  hCombined->GetBinError(bin) <<  endl;
        double binNormWidth  =  1.;
        if ( doXSec   ==   1) { binNormWidth  =  hCombined->GetBinWidth(bin) * Luminosity ;
            double aCom = hCombined->GetBinContent(bin) / binNormWidth ;
            double aMu = hMuon->GetBinContent(bin) / binNormWidth ;
            double aE  = hEle->GetBinContent(bin) / binNormWidth ;
            double ErrMu =  hMuon->GetBinError(bin) / binNormWidth;
            double ErrEle = hEle->GetBinError(bin) / binNormWidth ;
            ErrCom = hCombined->GetBinError(bin) /binNormWidth ;
            hCombined->SetBinContent(bin , aCom );
            hCombined->SetBinError(bin , ErrCom );
            hEle->SetBinContent(bin , aE );
            hEle->SetBinError(bin , ErrEle );
            hMuon->SetBinContent(bin , aMu );
            hMuon->SetBinError(bin , ErrMu );
        }

        double totalSystematicsUp(0.), totalSystematicsDown(0.);
        double totalStatistics(hCombined->GetBinError(bin));
        double centralValue(hCombined->GetBinContent(bin));


        xCoor[bin-1]     =  hCombined->GetBinCenter(bin);
        yCoor[bin-1]     =  centralValue;
        xErr[bin-1]      =  0.;			
        yStat[bin-1]     =  totalStatistics;

        /// get ratio od muon to merged
        yCoorMuonRatio[bin-1]  =  (hMuon->GetBinContent(bin)) / centralValue ;
        yStatMuonRatio[bin-1]     =  totalStatistics / centralValue ;
        ySystDownMuonRatio[bin-1]    =  sqrt(totalStatistics * totalStatistics + totalSystematicsDown )/(hMuon->GetBinContent(bin));
        ySystUpMuonRatio[bin-1]      =  sqrt(totalStatistics * totalStatistics + totalSystematicsUp )/(hMuon->GetBinContent(bin));

        /// get ratio od Electron to merged
        yCoorEleRatio[bin-1]  =  (hEle->GetBinContent(bin)) / centralValue ;
        yStatEleRatio[bin-1]     =  totalStatistics / centralValue ;
        ySystDownEleRatio[bin-1]    =  sqrt(totalStatistics * totalStatistics + totalSystematicsDown )/(hMuon->GetBinContent(bin));
        ySystUpEleRatio[bin-1]      =  sqrt(totalStatistics * totalStatistics + totalSystematicsUp )/(hMuon->GetBinContent(bin));
        // set errors to zero
        yStatMuonRatio[bin-1]        = 0. ;
        ySystDownMuonRatio[bin-1]    = 0. ;
        ySystUpMuonRatio[bin-1]      = 0. ;

        yStatEleRatio[bin-1]        = 0. ;
        ySystDownEleRatio[bin-1]    = 0. ;
        ySystUpEleRatio[bin-1]      = 0. ; 
        // set errors to zero




        if ( DEBUG ) cout << " merging bin " << bin <<" of "<< nBins << "   " << centralValue  <<"   " << hEle->GetBinContent(bin) << "  "  << hMuon->GetBinContent(bin) << endl; 

    }
    cout<< " things are merged lets go to the plotting"<< endl;
    TGraph *mcGraph  =  new TGraph(nBins, xCoor, yCoor);
    TGraphAsymmErrors *grCentralStat       =  new TGraphAsymmErrors(nBins, xCoor, yCoor, xErr, xErr, yStat, yStat);
    TGraphAsymmErrors *grCentralStatMuonRatio  =  new TGraphAsymmErrors(nBins, xCoor, yCoorMuonRatio, xErr, xErr, yStatMuonRatio, yStatMuonRatio);
    TGraphAsymmErrors *grCentralStatEleRatio  =  new TGraphAsymmErrors(nBins, xCoor, yCoorEleRatio, xErr, xErr, yStatEleRatio, yStatEleRatio);
    TGraphAsymmErrors *grCentralSystMuonRatio  =  new TGraphAsymmErrors(nBins, xCoor, yCoorMuonRatio, xErr, xErr, ySystDownMuonRatio, ySystUpMuonRatio);
    TGraphAsymmErrors *grCentralSystEleRatio  =  new TGraphAsymmErrors(nBins, xCoor, yCoorEleRatio, xErr, xErr, ySystDownEleRatio, ySystUpEleRatio);


    cout<< " TGraphs are done"<< endl;
    //	grCentralStat->Draw();
    //	grCentralStatMuonRatio->Draw("same");


    grCentralStat->SetMarkerStyle(20);
    grCentralStat->SetMarkerSize(0.8);
    grCentralStat->SetMarkerColor(kBlack);
    grCentralStat->SetLineColor(kBlack);
    //grCentralStat->SetLineWidth(2);
    TGraphAsymmErrors *grCentralSyst  =  new TGraphAsymmErrors(nBins, xCoor, yCoor, xErr, xErr, yStat, yStat);
    grCentralSyst->SetLineColor(kRed+1);
    //grCentralSyst->SetLineWidth(2);
    grCentralSyst->SetMarkerStyle(20);
    grCentralSyst->SetMarkerSize(0.8);



    ////////////////////////////////////// now do the canvas
    string mVariable = "Merged_" + variable;
    TCanvas *can = new TCanvas(mVariable.c_str(), mVariable.c_str(), 600, 900);
    can->cd();
    TPad *pad1 = new TPad("pad1","pad1", 0, 0.4, 1, 1);
    pad1->SetBottomMargin(0);
    pad1->SetRightMargin(0.05);
    pad1->SetLeftMargin(0.1);
    if (LOGZ) pad1->SetLogy(); pad1->SetLogy();
    pad1->SetTickx();
    pad1->SetTicky();
    pad1->Draw();
    pad1->cd();
    grCentralSyst->GetXaxis()->SetLimits(hMuon->GetXaxis()->GetXmin(),hMuon->GetXaxis()->GetXmax());
    //grCentralSyst->GetYaxis()->SetLimits(yCoor[0]-0.4,xCoor[nBins-1]+0.4);
    //grCentralSyst->Draw("AP");
    double MineYMax = hMuon->GetMaximum();
    if (grCentralSyst->GetMaximum() > MineYMax) {
        MineYMax = grCentralSyst->GetMaximum();
    }
    hMuon->GetXaxis()->SetRangeUser(hMuon->GetXaxis()->GetXmin(),hMuon->GetXaxis()->GetXmax());
    if (variable.find("ZNGood") !=  std::string::npos) {
        MineYMax = 65.;
        hMuon->GetXaxis()->SetRangeUser(hMuon->GetXaxis()->GetXmin()+hMuon->GetBinWidth(1),hMuon->GetXaxis()->GetXmax()- 2*hMuon->GetBinWidth(1));
        grCentralSyst->GetXaxis()->SetLimits(hMuon->GetXaxis()->GetXmin()+hMuon->GetBinWidth(1),hMuon->GetXaxis()->GetXmax() -2* hMuon->GetBinWidth(1));
    }


    hMuon->SetFillStyle(3001);
    hMuon->SetFillColor(kRed);
    hMuon->SetLineColor(kRed);
    hMuon->GetYaxis()->SetTitleSize(0.05);
    hMuon->GetYaxis()->SetTitleOffset(0.95);
    if (LOGZ) hMuon->SetMaximum(MineYMax*5);
    else hMuon->SetMaximum(MineYMax*1.5);
    if (doXSec || doNormalize) { 
        hMuon->GetYaxis()->SetTitle("");
        string temp;
        temp = "d#sigma/dH_{T} [pb/GeV]";
        if (variable.find("Pt") != std::string::npos) temp = "d#sigma/dp_{T} [pb/GeV]";
        if (variable.find("Eta") != std::string::npos) temp = "d#sigma/d#eta [pb]";
        if (variable.find("ZNGood") != std::string::npos){
            temp = "d#sigma/dN [pb]";

        }
        if (variable.find("ZNGood") != std::string::npos){
            temp = "d#sigma/dN [pb]";
        }

        if (variable.find("SpT") != std::string::npos) {temp = "d#sigma/dSpT [pb]";
            if (doNormalize) temp = "1/#sigma d#sigma/dSpT";
        }
        if (variable.find("PHI") != std::string::npos || variable.find("Phi") !=  std::string::npos ) {temp = "d#sigma/d#Delta#Phi  [pb]";
            if (doNormalize) temp = "1/#sigma d#sigma/d#Delta#Phi";
        }
        const char *tempYAxisTitle = temp.c_str();
        hMuon->GetYaxis()->SetTitle(tempYAxisTitle);
        hEle->GetYaxis()->SetTitle(tempYAxisTitle);

    }
    hMuon->Draw("E2");
    mcGraph->SetLineColor(kRed);
    hEle->SetFillStyle(3002);
    hEle->SetFillColor(kBlue);
    hEle->SetLineColor(kBlue);
    hEle->Draw("E2 same");
    grCentralSyst->Draw("P same");
    grCentralStat->Draw("P same");
    pad1->Draw();
    TPaveText *pt  =  new TPaveText(0.07,0.88,0.99,0.98,"NDC");
    pt->AddText("CMS Preliminary                    #sqrt{s}  =  8 TeV                    #int L dt  =  19.8 fb^{-1}  ");
    pt->SetBorderSize(0);
    pt->SetFillStyle(0);
    pt->Draw();
    // set the legend
    double xLowLeg(0.65), xHighLeg(0.95);
    if (!DECREASE){
        xLowLeg = 0.14;
        xHighLeg = 0.47;
    }
    TLegend *legend = new TLegend(xLowLeg, 0.66, xHighLeg, 0.91);
    legend->SetHeader("  ");
    hMuon->SetTitle("");
    legend->SetFillStyle(0);
    legend->SetBorderSize(0);
    legend->AddEntry(hMuon, "Muon", "f");
    legend->AddEntry(hEle, "Electron", "f");
    legend->AddEntry(grCentralStat, "Combination", "pl");
    legend->AddEntry(hCombErr, " Comb. Err.", "f");
    legend->Draw();

    can->cd();
    TPad *pad2  =  new TPad("pad2","pad2", 0, 0.236, 1, 0.4);
    pad2->SetTopMargin(0);
    pad2->SetBottomMargin(0);
    pad2->SetRightMargin(0.05);
    pad2->SetLeftMargin(0.1);
    pad2->SetGridy();
    pad2->SetTickx();
    pad2->SetTicky();
    pad2->Draw();
    pad2->cd();
    grCentralStatMuonRatio->SetMarkerStyle(20);
    grCentralStatMuonRatio->SetMarkerSize(0.8);
    grCentralStatMuonRatio->SetMarkerColor(kBlack);
    grCentralStatMuonRatio->SetLineColor(kBlack);
    grCentralSystMuonRatio->SetLineColor(kRed+1);
    grCentralSystMuonRatio->SetMarkerStyle(20);
    grCentralSystMuonRatio->SetMarkerSize(0.8);
    grCentralSystMuonRatio->GetXaxis()->SetLimits(hMuon->GetXaxis()->GetXmin(),hMuon->GetXaxis()->GetXmax());
    if (variable.find("ZNGood") !=  std::string::npos) grCentralSystMuonRatio->GetXaxis()->SetLimits(hMuon->GetXaxis()->GetXmin()+hMuon->GetBinWidth(1),hMuon->GetXaxis()->GetXmax() - hMuon->GetBinWidth(1));
    //grCentralSystMuonRatio->GetYaxis()->SetRangeUser(0.41,1.59);
    grCentralSystMuonRatio->GetYaxis()->SetRangeUser(0.7,1.3);
    grCentralSystMuonRatio->GetYaxis()->SetTitle("Muon / Comb.");
    grCentralSystMuonRatio->GetYaxis()->SetTitleSize(0.14);
    grCentralSystMuonRatio->GetYaxis()->SetTitleOffset(0.35);
    grCentralSystMuonRatio->GetYaxis()->CenterTitle();
    grCentralSystMuonRatio->GetYaxis()->SetLabelSize(0.12);
    grCentralSystMuonRatio->GetYaxis()->SetLabelOffset(0.01);
    grCentralSystMuonRatio->SetTitle("");
    grCentralSystMuonRatio->Draw("AP");
    hCombErr->SetFillColor(kGreen-3);
    hCombErr->SetLineColor(kGreen-3);
    hCombErr->SetFillStyle(3001);
    hCombErr->DrawCopy("E2 same");
    grCentralSystMuonRatio->Draw("P same");
    grCentralStatMuonRatio->Draw("P same");
    TLatex *latexLabel  =  new TLatex();
    latexLabel->SetTextSize(0.15);
    latexLabel->SetTextFont(42);
    latexLabel->SetLineWidth(2);
    latexLabel->SetTextColor(kAzure-5);
    latexLabel->SetNDC();
    latexLabel->DrawLatex(0.15,0.09,"Muon");
    pad2->Draw();
    pad2->cd();

    can->cd();
    TPad *pad3  =  new TPad("pad3","pad3", 0, 0., 1, 0.236);
    pad3->SetTopMargin(0);
    pad3->SetBottomMargin(0.3);
    pad3->SetRightMargin(0.05);
    pad3->SetLeftMargin(0.1);
    pad3->SetGridy();
    pad3->SetTickx();
    pad3->SetTicky();
    pad3->Draw();
    pad3->cd();
    grCentralStatEleRatio->SetMarkerStyle(20);
    grCentralStatEleRatio->SetMarkerSize(0.8);
    grCentralStatEleRatio->SetMarkerColor(kBlack);
    grCentralStatEleRatio->SetLineColor(kBlack);
    grCentralSystEleRatio->SetLineColor(kRed+1);
    grCentralSystEleRatio->SetMarkerStyle(20);
    grCentralSystEleRatio->SetMarkerSize(0.8);
    grCentralSystEleRatio->GetXaxis()->SetLimits(hMuon->GetXaxis()->GetXmin(),hMuon->GetXaxis()->GetXmax());
    if (variable.find("ZNGood") !=  std::string::npos) grCentralSystEleRatio->GetXaxis()->SetLimits(hMuon->GetXaxis()->GetXmin()+hMuon->GetBinWidth(1),hMuon->GetXaxis()->GetXmax() - hMuon->GetBinWidth(1));
    grCentralSystEleRatio->GetXaxis()->SetTitle(hMuon->GetXaxis()->GetTitle());
    grCentralSystEleRatio->GetXaxis()->SetTitleSize(0.1);
    grCentralSystEleRatio->GetXaxis()->SetTitleOffset(1.14);
    grCentralSystEleRatio->GetXaxis()->SetLabelSize(0.1);
    grCentralSystEleRatio->GetXaxis()->SetLabelOffset(0.014);
    grCentralSystEleRatio->GetYaxis()->SetRangeUser(0.65,1.35);
    grCentralSystEleRatio->GetYaxis()->SetTitle("Elec. / Comb.");
    grCentralSystEleRatio->GetYaxis()->SetTitleSize(0.1);
    grCentralSystEleRatio->GetYaxis()->SetTitleOffset(0.48);
    grCentralSystEleRatio->GetYaxis()->CenterTitle();
    grCentralSystEleRatio->GetYaxis()->SetLabelSize(0.085);
    grCentralSystEleRatio->GetYaxis()->SetLabelOffset(0.012);
    grCentralSystEleRatio->SetTitle("");
    grCentralSystEleRatio->Draw("AP");
    hCombErr->SetFillColor(kGreen-3);
    hCombErr->SetLineColor(kGreen-3);
    hCombErr->SetFillStyle(3001);
    hCombErr->DrawCopy("E2 same");
    grCentralStatEleRatio->Draw("P same");
    TLatex *latexLabel1  =  new TLatex();
    latexLabel1->SetTextSize(0.11);
    latexLabel1->SetTextFont(42);
    latexLabel1->SetLineWidth(2);
    latexLabel1->SetTextColor(kOrange+2);
    latexLabel1->SetNDC();
    latexLabel1->DrawLatex(0.15,0.35,"Electron");
    pad3->Draw();
    pad3->cd();
    can->cd();

    string outputFileNamePNG = OUTPUTDIRECTORY;
    if (doXSec) outputFileNamePNG += "CompLeptonsAndComb_XSec_";
    else if (doNormalize) outputFileNamePNG += "CompLeptonsAndComb_Normalized_";

    ostringstream optionCorrStr; optionCorrStr << optionCorr;
    outputFileNamePNG += variable;
    outputFileNamePNG += "_CorrelationOption_" + optionCorrStr.str();
    if (doVarWidth) outputFileNamePNG += "_VarWidth";
    outputFileNamePNG += ".pdf";

    can->Print(outputFileNamePNG.c_str());

}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void dumpElements(TMatrixD& a)
{
    cout << endl << endl;
    const int nrows  =  a.GetNrows();
    const int ncols  =  a.GetNcols();
    if(nrows  ==  ncols) cout << "determinent  =  " << a.Determinant() << endl;
    a.Print();
    cout << endl << endl;
    return;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void dumpElements(TVectorD& a)
{
    cout << endl << endl;
    a.Print();
    cout << endl << endl;
    return;
}

