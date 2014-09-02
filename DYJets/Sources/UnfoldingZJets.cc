#include <iostream>
#include <math.h>
#include <TApplication.h>
#include <TCanvas.h>
#include <RooUnfoldBayes.h>
#include "fileNamesZJets.h"
#include "getFilesAndHistogramsZJets.h"
#include "UnfoldingZJets.h"
#include "PlotSettings.h"

using namespace std;

extern int ZJetsFillColor[3];
extern int ZJetsPdfFillColor[3];
extern int ZJetsLineColor[3];
extern int ZJetsMarkerColor[3];
extern int ZJetsMarkerStyle[3];
extern int ZJetsFillStyle;

void UnfoldingZJets(int* argc, char **argv)
{
    // The TApplication is necessary only if we want to use TCanvas
    TApplication* rootapp = new TApplication("rootapp", argc, argv);
    // We connect the TCanvas close to the terminate of the TApplication
    TCanvas::Connect("TCanvas", "Closed()", "TApplication", gApplication, "Terminate()");

    TString histoDir = "HistoFilesAugust";
    //TString variable = "FourthJetEta_Zinc4jet";
    TString variable = "ZNGoodJets_Zexc";
    TString lepSel = "DMu";
    TString algo = "Bayes";
    TString outDir = "PNGFilesAugust/FinalUnfoldZJets/";
    TString energy = "8TeV"; 
    int jetPtMin = 30;
    int jetEtaMax = 24;

    double integratedLumi = (lepSel == "DMu") ? 19584 : 19618;
    // Here we declare the different arrays of TFiles. 
    // fData is for the three data files: 
    // 0 - central, 1 - JES up, 2 - JES down
    TFile *fData[3] = {NULL}; 
    // fDYJets is for the five DYJets files:
    // 0 - central, 1 - PU up, 2 - PU down, 3 - JER up, 4 - JER down 
    TFile *fDYJets[5] = {NULL};
    // fBg is for the NBGDYJETS x 5 systematics files:
    // 0 - central, 1 - PU up, 2 - PU down, 3 - XSEc up, 4 - XSEC down 
    TFile *fBg[NBGDYJETS][5] = {{NULL}};

    //--- Open all files ---------------------------------------------------------------------- 
    getAllFiles(histoDir, lepSel, "8TeV", jetPtMin, jetEtaMax, fData, fDYJets, fBg, NBGDYJETS);
    //----------------------------------------------------------------------------------------- 

    //----------------------------------------------------------------------------------------- 
    //--- Now run on the different variables ---
    
    TString outputRootFileName = outDir + lepSel + "_" + energy; 
    outputRootFileName += "_unfolded_" + variable + "_" + algo;
    outputRootFileName += ".root";
    TFile *outputRootFile = new TFile(outputRootFileName, "RECREATE");
            

    //--- rec Data histograms ---
    TH1D *hRecData[3] = {NULL};
    //--- rec DYJets histograms ---
    TH1D *hRecDYJets[9] = {NULL};
    //--- gen DYJets histograms ---
    TH1D *hGenDYJets[7] = {NULL};
    //--- res DYJets histograms ---
    TH2D *hResDYJets[9] = {NULL};
    //--- rec Bg histograms ---
    TH1D *hRecBg[NBGDYJETS][9] = {{NULL}};
    //--- rec Sum Bg histograms ---
    TH1D *hRecSumBg[9] = {NULL};
    //--- response DYJets objects ---
    RooUnfoldResponse *respDYJets[13] = {NULL};

    //--- Get all histograms ---
    getAllHistos(variable, hRecData, fData, 
            hRecDYJets, hGenDYJets, hResDYJets, fDYJets,
            hRecBg, hRecSumBg, fBg, NBGDYJETS, respDYJets);
    //----------------------------------------------------------------------------------------- 

    TH1D *hGenCrossSection = makeCrossSectionHist(hGenDYJets[0], integratedLumi);
    
    // Here is an array of TH1D to store the various unfolded data:
    // 0 - Central, 
    // 1 - JES up, 2 - JES down, 
    // 3 - PU up, 4 - PU down, 
    // 5 - JER up, 6 - JER down, 
    // 7 - XSEC up, 8 - XSEC down
    // 9 - Lumi up, 10 - Lumi down
    // 11 - SF up, 12 - SF down
    TString name[] = {"Central", "JesUp", "JesDown", "PUUp", "PUDown", "JERUp", "JERDown", 
        "XSECUp", "XSECDown", "LumiUp", "LumiDown", "SFUp", "SFDown"};
    TH1D *hUnfData[13] = {NULL};
    TH2D *hUnfDataStatCov[13] = {NULL};
    TH2D *hUnfMCStatCov[13] = {NULL};

    int nIter = 4;
    //--- Unfold the Data histograms for each systematic ---
    for (unsigned short iSyst = 0; iSyst < 13; ++iSyst) {
        //--- only JES up and down (iSyst = 1 and 2) is applied on data ---
        unsigned short iData = (iSyst < 3) ? iSyst : 0;
        UnfoldData(algo, respDYJets[iSyst], hRecData[iData], nIter, hUnfData[iSyst], 
                hUnfDataStatCov[iSyst], hUnfMCStatCov[iSyst], name[iSyst], integratedLumi);
        outputRootFile->cd(); hUnfData[iSyst]->Write();
    }
    //----------------------------------------------------------------------------------------- 

    //--- Now create the covariance matrices ---
    TH2D *hCov[9] = {NULL};
    hCov[0] = (TH2D*) hUnfDataStatCov[0]->Clone("CovDataStat");
    hCov[1] = (TH2D*) hUnfMCStatCov[0]->Clone("CovMCStat");
    hCov[2] = makeCovFromUpAndDown(hUnfData[0], hUnfData[1], hUnfData[2], "CovJES");
    hCov[3] = makeCovFromUpAndDown(hUnfData[0], hUnfData[3], hUnfData[4], "CovPU");
    hCov[4] = makeCovFromUpAndDown(hUnfData[0], hUnfData[5], hUnfData[6], "CovJER");
    hCov[5] = makeCovFromUpAndDown(hUnfData[0], hUnfData[7], hUnfData[8], "CovXSec");
    hCov[6] = makeCovFromUpAndDown(hUnfData[0], hUnfData[9], hUnfData[10], "CovLumi");
    hCov[7] = makeCovFromUpAndDown(hUnfData[0], hUnfData[11], hUnfData[12], "CovSF");

    hCov[8] = (TH2D*) hUnfMCStatCov[0]->Clone("CovTotSyst");
    for (int i = 2; i < 8; ++i) hCov[8]->Add(hCov[i]);

    
    TCanvas *crossSectionPlot = makeCrossSectionPlot(variable, hUnfData[0], hCov[8], hGenCrossSection); 
    crossSectionPlot->Draw();
   
    ////--- print out break down of errors ---
    //for (int i = 2; i < 8; ++i) {
    //    cout << hUnfData[0]->GetBinContent(i);
    //    for (int j = 0; j < 8; ++j) {
    //        cout << " +/- " << sqrt(hCov[j]->GetBinContent(i,i))*1./hUnfData[0]->GetBinContent(i);
    //    }
    //    cout << endl;
    //}
    ////--------------------------------------



    outputRootFile->cd();
    hRecData[0]->Write("hRecDataCentral");
    hRecSumBg[0]->Write("hRecSumBgCentral");
    hRecDYJets[0]->Write("hRecDYJetsCentral");
    hGenDYJets[0]->Write("hGenDYJetsCentral");
    respDYJets[0]->Write("respDYJetsCentral");
    //----------------------------------------------------------------------------------------- 


    //TCanvas *can1 = new TCanvas("can1", "can1", 900, 600);
    //can1->cd();
    //hUnfData[0]->SetLineColor(kRed);
    //hUnfData[0]->DrawCopy();
    //for (unsigned short i = 5; i < 7; ++i) {
    //    hUnfData[i]->DrawCopy("samehist");
    //}
    //can1->Update();

    //TCanvas *can2 = new TCanvas("can2", "can2", 700, 700);
    //can2->cd();
    //hUnfDataStatCov[0]->Draw("text");
    //can2->Update();

    //TCanvas *can3 = new TCanvas("can3", "can3", 700, 700);
    //can3->cd();
    //hUnfMCStatCov[0]->Draw("text");
    //can3->Update();
    //------------------------------------------------------------------------------------------ 

    rootapp->Run(kTRUE);
    //--- Close all files ----------------------------------------------------------------------
    outputRootFile->Close();
    closeAllFiles(fData, fDYJets, fBg, NBGDYJETS);
    //------------------------------------------------------------------------------------------ 

}


void UnfoldData(const TString algo, RooUnfoldResponse *resp, TH1D *hRecData, int nIter, 
        TH1D* &hUnfData, TH2D* &hUnfDataStatCov, TH2D* &hUnfMCStatCov, TString name, 
        double integratedLumi)
{
    //--- make sure we use OverFlow (should already be set to true) ---
    resp->UseOverflow();

    //--- Set the required unfolding algorithm ---
    RooUnfold::Algorithm alg = RooUnfold::kBayes;
    if (algo == "SVD") alg = RooUnfold::kSVD;

    //--- Unfold data minus background ---
    RooUnfold *RObject = RooUnfold::New(alg, resp, hRecData, nIter);
    RObject->SetVerbose(0);

    //--- get the unfolded result ---
    hUnfData = (TH1D*) RObject->Hreco(RooUnfold::kCovariance);
    hUnfData->SetName("UnfData" + name);
    hUnfData->SetTitle(hRecData->GetTitle());

    if (algo == "Bayes") {
        //--- get covariance from statistics on Data ---
        hUnfDataStatCov = M2H(RObject->GetDataStatCov());
        hUnfDataStatCov->SetName("UnfDataStatCov" + name);
        hUnfDataStatCov->SetTitle(hRecData->GetTitle());

        //--- get covariance from MC stat ---
        hUnfMCStatCov = M2H(RObject->GetMCStatCov());
        hUnfMCStatCov->SetName("UnfMCStatCov" + name);
        hUnfMCStatCov->SetTitle(hRecData->GetTitle());
    }

    //--- divide by luminosity ---
    hUnfData->Scale(1./integratedLumi);
    hUnfDataStatCov->Scale(1./(integratedLumi*integratedLumi));
    hUnfMCStatCov->Scale(1./(integratedLumi*integratedLumi));
    if ("LumiUp" == name) {
        hUnfData->Scale(1./1.026);
        hUnfDataStatCov->Scale(1./(1.026*1.026));
        hUnfMCStatCov->Scale(1./(1.026*1.026));
    }
    else if ("LumiDown" == name) {
        hUnfData->Scale(1./0.974);
        hUnfDataStatCov->Scale(1./(0.974*0.974));
        hUnfMCStatCov->Scale(1./(0.974*0.974));
    }

    //--- divide by bin width to get cross section ---
    int nBins = hUnfData->GetNbinsX();
    for (int i = 1; i <= nBins; ++i) {
        double binWidth = hUnfData->GetBinWidth(i);
        hUnfData->SetBinContent(i, hUnfData->GetBinContent(i)*1./binWidth);
        hUnfData->SetBinError(i, hUnfData->GetBinError(i)*1./binWidth);
        for (int j = 1; j <= nBins; ++j) {
            hUnfDataStatCov->SetBinContent(i, j, hUnfDataStatCov->GetBinContent(i, j)*1./(binWidth*binWidth));
            hUnfDataStatCov->SetBinError(i, j, hUnfDataStatCov->GetBinError(i, j)*1./(binWidth*binWidth));
            hUnfMCStatCov->SetBinContent(i, j, hUnfMCStatCov->GetBinContent(i, j)*1./(binWidth*binWidth));
            hUnfMCStatCov->SetBinError(i, j, hUnfMCStatCov->GetBinError(i, j)*1./(binWidth*binWidth));
        }
    }

    delete RObject;
}


TH2D* M2H(const TMatrixD m) 
{
    int nBinsY = m.GetNrows();
    int nBinsX = m.GetNrows();

    TH2D *h = new TH2D(m.GetName(), m.GetName(), nBinsX-2, 0, nBinsX-2, nBinsY-2, 0, nBinsY-2);
    for (int i = 0; i < nBinsX; ++i) {
        for (int j = 0; j < nBinsY; ++j) {
            h->SetBinContent(i, j, m(i, j));
        }
    }

    return h;
}

TH2D* makeCovFromUpAndDown(const TH1D* hUnfDataCentral, const TH1D* hUnfDataUp, const TH1D* hUnfDataDown, TString name)
{
    int nBins = hUnfDataCentral->GetNbinsX();
    TH2D* h = new TH2D(name, name, nBins, 0, nBins, nBins, 0, nBins);

    for (int i = 1; i < nBins; ++i) {
        double sigmaMeani = 0.5*fabs(hUnfDataUp->GetBinContent(i) - hUnfDataDown->GetBinContent(i)); 
        int signi = (hUnfDataUp->GetBinContent(i) - hUnfDataDown->GetBinContent(i) < 0) ? -1 : 1;

        for (int j = 1; j < nBins; ++j) {
            double sigmaMeanj = 0.5*fabs(hUnfDataUp->GetBinContent(j) - hUnfDataDown->GetBinContent(j)); 
            int signj = (hUnfDataUp->GetBinContent(j) - hUnfDataDown->GetBinContent(j) < 0) ? -1 : 1;

            h->SetBinContent(i, j, signi * signj * sigmaMeani * sigmaMeanj);
        }
    }

    return h;
}

TH1D* makeCrossSectionHist(TH1D* hGenDYJets, double integratedLumi)
{
    TH1D *hGenCrossSection = (TH1D*) hGenDYJets->Clone();
    //--- divide by luminosity ---
    hGenCrossSection->Scale(1./integratedLumi);

    int nBins = hGenCrossSection->GetNbinsX();
    for (int i = 1; i <= nBins; ++i) {
        double binWidth = hGenCrossSection->GetBinWidth(i);
        hGenCrossSection->SetBinContent(i, hGenCrossSection->GetBinContent(i)*1./binWidth);
        hGenCrossSection->SetBinError(i, hGenCrossSection->GetBinError(i)*1./binWidth);
    }

    return hGenCrossSection;
}

TCanvas* makeCrossSectionPlot(TString variable, TH1D *hStat, TH2D *hCovSyst, TH1D *hGen)
{

    double maximum = hGen->GetMaximum();
    TH1D *hPDFUp = (TH1D*) hStat->Clone();
    hPDFUp->Scale(1.10);
    TH1D *hPDFDown = (TH1D*) hStat->Clone();
    hPDFDown->Scale(0.75);

    //--- Main Canvas ---
    TString canvasName = "canvas" + variable;
    TCanvas *plots = new TCanvas(canvasName, hStat->GetTitle(), 600, 800);
    //-------------------

    //--- First Pad ---
    plots->cd();
    TPad *plot1 = new TPad("plot1", "plot1", 0., 0., 0., 0.);
    setAndDrawTPad(canvasName, plot1, 1, 1);

    //--- TLegend ---
    TLegend *legend = new TLegend(0.47, 0.74, 0.99, 0.98);
    customizeLegend(legend, 1);
    //------------------
   
    TH1D *hSyst = (TH1D*) hStat->Clone();
    int nBins = hSyst->GetNbinsX();

    for (int i = 1; i <= nBins; ++i) {
        hSyst->SetBinError(i, sqrt(pow(hStat->GetBinError(i), 2) + hCovSyst->GetBinContent(i, i)));
    }

    TGraphAsymmErrors *grCentralStat = createGrFromHist(hStat);
    grCentralStat->SetName("gr" + variable + "CentralStatError"); 
    TGraphAsymmErrors *grCentralSyst = createGrFromHist(hSyst);
    grCentralSyst->SetName("gr" + variable + "CentralTotError"); 
    TGraphAsymmErrors *grCentralStatRatio = createRatioGraph(grCentralStat);
    TGraphAsymmErrors *grCentralSystRatio = createRatioGraph(grCentralSyst);
    TGraphAsymmErrors *grGen1ToCentral = createGenToCentral(hGen, grCentralStat);
    TGraphAsymmErrors *grGen1PDFSyst = createPDFSystGraph(hPDFUp, hPDFDown, grGen1ToCentral); 

    customizeCentral(grCentralSyst, legend, "Data");
    customizeCentral(grCentralStat, false);
    customizeCentral(grCentralSystRatio, true);
    customizeCentral(grCentralStatRatio, (bool)true);
    grCentralSyst->Draw("a2");
    customizeGenHist(hGen, 1, legend, "Madgraph + Pythia6 (#leq4j@LO + PS)");
    hGen->DrawCopy("ESAME");

    configYaxis(grCentralSyst, hGen);
    configXaxis(grCentralSyst, hGen);
    grCentralStat->Draw("p");

    if (canvasName.Index("Eta") >= 0) {
        grCentralSyst->GetHistogram()->GetYaxis()->SetRangeUser(0.001, 1.4*maximum);
    }
    legend->Draw("same");

    //--- TLatex stuff ---
    TLatex *latexLabel = new TLatex(); 
    latexLabel->SetNDC();
    latexLabel->SetTextSize(0.035);
    latexLabel->SetTextFont(42);
    latexLabel->SetLineWidth(2);

    latexLabel->SetTextFont(61);
    latexLabel->DrawLatex(0.13,0.95,"CMS");
    latexLabel->SetTextFont(52);
    latexLabel->DrawLatex(0.20,0.95,"Preliminary");
    latexLabel->SetTextFont(42);
    latexLabel->DrawLatex(0.13,0.95-0.045,"19.6 fb^{-1} (8 TeV)");
    latexLabel->DrawLatex(0.18,0.21-0.05,"anti-k_{T} (R = 0.5) Jets");
    latexLabel->DrawLatex(0.18,0.21-0.11,"p_{T}^{jet} > 30 GeV, |#eta^{jet}| < 2.4 ");
    latexLabel->DrawLatex(0.18,0.21-0.17,"Z/#gamma*#rightarrow ll channel");
    latexLabel->Draw("same");

    TLatex *ytitle = new TLatex();
    ytitle->SetTextSize(0.04);
    ytitle->SetTextFont(42);
    ytitle->SetLineWidth(2);
    ytitle->SetTextColor(kBlack);
    ytitle->SetNDC();
    ytitle->SetTextAlign(33);
    ytitle->SetTextAngle(90);
    std::string strYtitle = getYaxisTitle(hGen);
    cout << strYtitle << endl;
    if (strYtitle.find("eta") != std::string::npos) {
        size_t first = strYtitle.find("#eta");
        std::string tmp1 = strYtitle.substr(0, first);
        std::string tmp2 = strYtitle.substr(first);
        strYtitle = tmp1 + "|" + tmp2;
        size_t second = strYtitle.find(")");
        tmp1 = strYtitle.substr(0, second+1);
        tmp2 = strYtitle.substr(second+1);
        strYtitle = tmp1 + "|" + tmp2;
    }
    ytitle->DrawLatex(0.008,0.91,strYtitle.c_str());
    //--- End Of first Pad ---
    
    //--- Second Pad ---
    plots->cd();
    TPad *plot2 = new TPad("plot2", "plot2", 0., 0., 0., 0.);
    setAndDrawTPad(canvasName, plot2, 2, 1);


    //--- TLegend ---
    TLegend *legend2 = new TLegend(0.16, 0.05, 0.42, 0.20);
    customizeLegend(legend2, 1, 1);
    customizeGenGraph(grGen1ToCentral, grGen1PDFSyst, 1, "MadGraph/Data", 1, legend2);
    configXaxis(grGen1ToCentral, hGen);
    grGen1PDFSyst->SetFillStyle(1001);
    grGen1PDFSyst->SetFillColor(kBlue-6);
    grGen1ToCentral->Draw("a2");
    grGen1ToCentral->Draw("2");
    grCentralSystRatio->Draw("2");
    grCentralStatRatio->Draw("p");
    grGen1ToCentral->Draw("p");
    legend2->Draw("same");
    plot2->RedrawAxis();
    //--- End of Second Pad ---

    plots->Update();
    return plots;
}
