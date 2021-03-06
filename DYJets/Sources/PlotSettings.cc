#include "PlotSettings.h"
#include "TStyle.h"
#include "TFile.h"
#include "TMath.h"
#include <sstream>
#include <string>
using namespace std;

void setAndDrawTPad(TString canvasName, TPad *plot, int plotNumber, int numbOfGenerator)
{
    if (numbOfGenerator == 1) {
        if (plotNumber == 1) {
            plot->SetPad(0.01, 0.35, 0.99, 0.99);
            plot->SetTopMargin(0.11);
            plot->SetBottomMargin(0.005);
        }
        else if (plotNumber == 2) {
            plot->SetPad(0.01, 0.01, 0.99, 0.35);
            plot->SetTopMargin(0.0);
            plot->SetBottomMargin(0.3);
        }
    }
    else if (numbOfGenerator == 2) {
        if (plotNumber == 1) {
            plot->SetPad(0.01, 0.45, 0.99, 0.99);
            plot->SetTopMargin(0.11);
            plot->SetBottomMargin(0.005);
        }
        else if (plotNumber == 2) {
            plot->SetPad(0.01, 0.27, 0.99, 0.45);
            plot->SetTopMargin(0.0);
            plot->SetBottomMargin(0.0);
        }
        else if (plotNumber == 3) {
            plot->SetPad(0.01, 0.01, 0.99, 0.27);
            plot->SetTopMargin(0.0);
            plot->SetBottomMargin(0.3);
        }

    }
    else if (numbOfGenerator == 3) {
        if (plotNumber == 1) {
            plot->SetPad(0.01, 0.55, 0.99, 0.99);
            plot->SetTopMargin(0.11);
            plot->SetBottomMargin(0.005);
        }
        else if (plotNumber == 2) {
            plot->SetPad(0.01, 0.39, 0.99, 0.55);
            plot->SetTopMargin(0.0);
            plot->SetBottomMargin(0.0);
        }
        else if (plotNumber == 3) {
            plot->SetPad(0.01, 0.23, 0.99, 0.39);
            plot->SetTopMargin(0.0);
            plot->SetBottomMargin(0.0);
        }
        else if (plotNumber == 4) {
            plot->SetPad(0.01, 0.01, 0.99, 0.23);
            plot->SetTopMargin(0.0);
            plot->SetBottomMargin(0.3);
        }
    }


    if (plotNumber == 1 && (canvasName.Index("Eta") < 0 && canvasName.Index("AbsRapidity") < 0 && canvasName.Index("DPhi") < 0)) plot->SetLogy();
    if (plotNumber == 1 && canvasName.Index("DPhiZFirstJet") > 0) plot->SetLogy();
    plot->SetLeftMargin(0.13);
    plot->SetRightMargin(0.07);
    plot->SetFillStyle(0);
    plot->Draw();
    plot->cd();
}

void customizeLegend(TLegend *legend, int numbOfGenerator)
{
    legend->SetFillColor(0);
    legend->SetFillStyle(1001);
    legend->SetBorderSize(1);
    if (numbOfGenerator == 1) {
        legend->SetX1(0.39);
        legend->SetY1(0.84);
        legend->SetX2(0.96);
        legend->SetY2(0.98);
        legend->SetTextSize(.029);
    }
    else if (numbOfGenerator == 2) {
        legend->SetX1(0.39);
        legend->SetY1(0.77);
        legend->SetX2(0.96);
        legend->SetY2(0.98);
        legend->SetTextSize(.034);
    }
    else if (numbOfGenerator == 3) {
        legend->SetX1(0.54);
        legend->SetY1(0.78);
        legend->SetX2(0.98);
        legend->SetY2(0.98);
        legend->SetTextSize(.037);
    }
}

void customizeLegend(TLegend *legend, int genNumb, int numbOfGenerator)
{
    legend->SetFillColor(0);
    legend->SetFillStyle(ZJetsFillStyle);
    legend->SetBorderSize(0);
    //legend->SetTextSize(.075);
    legend->SetTextSize(.12);

    if (genNumb == numbOfGenerator) {
        if (numbOfGenerator == 1) {
            legend->SetY1(0.35);
            legend->SetX2(0.43);
            legend->SetY2(0.45);
            //legend->SetTextSize(0.06);
            legend->SetTextSize(0.08);
        }

        if (numbOfGenerator == 2) {
            legend->SetY1(0.34);
            legend->SetX2(0.43);
            legend->SetY2(0.45);
            //legend->SetTextSize(0.06);
            legend->SetTextSize(0.08);
        }
        if (numbOfGenerator == 3) {
            legend->SetY1(0.34);
            legend->SetX2(0.43);
            legend->SetY2(0.45);
            //legend->SetTextSize(0.06);
            legend->SetTextSize(0.09);
        }
    }

}

void customizeCentralNorm(TGraphAsymmErrors *grCentralNorm, bool ratio)
{
    grCentralNorm->SetLineColor(kMagenta);
    grCentralNorm->SetLineWidth(0.5);
    grCentralNorm->SetMarkerStyle(29);
    grCentralNorm->SetFillColor(12);
    gStyle->SetHatchesSpacing(1.5);
    gStyle->SetHatchesLineWidth(0.5);
    grCentralNorm->SetFillStyle(3345);
    grCentralNorm->SetMarkerColor(kMagenta);

    grCentralNorm->GetXaxis()->SetTitleOffset(1.0);
    grCentralNorm->GetXaxis()->SetTitleSize(0.05);
    grCentralNorm->GetXaxis()->SetLabelSize(0.0);
    grCentralNorm->GetXaxis()->SetLabelFont(42);
    grCentralNorm->GetXaxis()->SetTitleFont(42);

    grCentralNorm->GetYaxis()->SetTitleOffset(1.1);
    grCentralNorm->GetYaxis()->SetTitleSize(0.07);
    grCentralNorm->GetYaxis()->SetLabelSize(0.05);
    grCentralNorm->GetYaxis()->SetLabelFont(42);
    grCentralNorm->GetYaxis()->SetTitleFont(42);

    grCentralNorm->SetTitle();
    grCentralNorm->GetXaxis()->SetTitle();
    if (ratio) grCentralNorm->SetMarkerSize(0);
}

void customizeCentral(TGraphAsymmErrors *grCentral, bool ratio)
{
    customizeCentral(grCentral, (TLegend*) NULL);
    if (ratio) grCentral->SetMarkerSize(0);
}

void customizeCentral(TGraphAsymmErrors *grCentral, TLegend *legend, TString legText)
{
    grCentral->SetLineColor(kBlack);
    grCentral->SetLineWidth(2);
    grCentral->SetMarkerStyle(20);
    grCentral->SetFillColor(12);
    gStyle->SetHatchesSpacing(1.5);
    gStyle->SetHatchesLineWidth(2);
    grCentral->SetFillStyle(3354);
    grCentral->SetMarkerColor(kBlack);

    grCentral->GetXaxis()->SetTitleOffset(1.0);
    grCentral->GetXaxis()->SetTitleSize(0.05);
    grCentral->GetXaxis()->SetLabelSize(0.0);
    grCentral->GetXaxis()->SetLabelFont(42);
    grCentral->GetXaxis()->SetTitleFont(42);

    grCentral->GetYaxis()->SetTitleOffset(1.1);
    grCentral->GetYaxis()->SetTitleSize(0.07);
    grCentral->GetYaxis()->SetLabelSize(0.05);
    grCentral->GetYaxis()->SetLabelFont(42);
    grCentral->GetYaxis()->SetTitleFont(42);

    grCentral->SetTitle();
    grCentral->GetXaxis()->SetTitle();
    if (legend) legend->AddEntry(grCentral, legText, "PLEF");

}

TGraphAsymmErrors* createGrFromHist(const TH1D *h)
{
    int nPoints = h->GetNbinsX();
    double *xCoor = new double[nPoints];
    double *yCoor = new double[nPoints];
    double *xErr  = new double[nPoints];
    double *yErr = new double[nPoints];

    for (int i(0); i < nPoints; i++) {
        xCoor[i] = h->GetBinCenter(i+1);
        xErr[i]  = 0.5*h->GetBinWidth(i+1);
        yCoor[i] = h->GetBinContent(i+1);
        yErr[i] = h->GetBinError(i+1);
    }

    TGraphAsymmErrors *gr = new TGraphAsymmErrors(nPoints, xCoor, yCoor, xErr, xErr, yErr, yErr);

    delete [] xCoor; delete [] yCoor; delete [] xErr; delete [] yErr; 
    return gr;
}

//======================================================================
// This function creates a TGraphAsymmErrors from a TGraphAsymmErrors.
// The output TGraph has all yCoor set to 1. and y low and high errors
// representing the relative errors of the input TGraph.
//======================================================================
TGraphAsymmErrors* createRatioGraph(const TGraphAsymmErrors* grCentral)
{       
    int nPoints = grCentral->GetN();
    double *xCoor = new double[nPoints];
    double *yCoor = new double[nPoints];
    double *xErr  = new double[nPoints];
    double *yErrL = new double[nPoints];
    double *yErrH = new double[nPoints];

    for (int i(0); i < nPoints; i++) {
        grCentral->GetPoint(i, xCoor[i], yCoor[i]);
        xErr[i] = grCentral->GetErrorXlow(i);
        yErrL[i] = grCentral->GetErrorYlow(i)/yCoor[i];
        yErrH[i] = grCentral->GetErrorYhigh(i)/yCoor[i];
        yCoor[i] = 1.;
    }   

    TGraphAsymmErrors *grCentralRatio = new TGraphAsymmErrors(nPoints, xCoor, yCoor, xErr, xErr, yErrL, yErrH);

    delete [] xCoor; delete [] yCoor; delete [] xErr; delete [] yErrL; delete [] yErrH; 
    return grCentralRatio;
}

//======================================================================
// This function creates a TGraphErrors from a TGraphErrors.
// The output TGraph has all yCoor set to 1. and y errors
// representing the relative errors of the input TGraph.
//======================================================================
TGraphErrors* createRatioGraph(const TGraphErrors* grCentral)
{       
    int nPoints = grCentral->GetN();
    double *xCoor = new double[nPoints];
    double *yCoor = new double[nPoints];
    double *xErr  = new double[nPoints];
    double *yErr = new double[nPoints];

    for (int i(0); i < nPoints; i++) {
        grCentral->GetPoint(i, xCoor[i], yCoor[i]);
        xErr[i] = grCentral->GetErrorX(i);
        yErr[i] = grCentral->GetErrorY(i)/yCoor[i];
        yCoor[i] = 1.;
    }   

    TGraphErrors *grCentralRatio = new TGraphErrors(nPoints, xCoor, yCoor, xErr, yErr);

    delete [] xCoor; delete [] yCoor; delete [] xErr; delete [] yErr; 
    return grCentralRatio;
}

//================================================================================
// This function creates a TGraphAsymmErrors from a TH1D and a TGraphAsymmErrors.
// The output TGraph is the ratio of the TH1D by the TGraphAsymmErrors.
//================================================================================
TGraphAsymmErrors *createGenToCentral(const TH1D *gen, const TGraphAsymmErrors *grCentral)
{
    int nPoints = grCentral->GetN();
    double *xCoor = new double[nPoints];
    double *yCoor = new double[nPoints];
    double *xErr  = new double[nPoints];
    double *yErr  = new double[nPoints];

    for (int i(0); i < nPoints; i++) {
        grCentral->GetPoint(i, xCoor[i], yCoor[i]);
        xErr[i] = grCentral->GetErrorXlow(i);
        yErr[i] = 0.;
        if (yCoor[i] != 0) {
            yErr[i]  = gen->GetBinError(i+1)/yCoor[i];
            yCoor[i] = gen->GetBinContent(i+1)/yCoor[i];
        }
    }

    TGraphAsymmErrors *grGenToCentral = new TGraphAsymmErrors(nPoints, xCoor, yCoor, xErr, xErr, yErr, yErr);
    delete [] xCoor; delete [] yCoor; delete [] xErr; delete [] yErr; 
    return grGenToCentral;
}

TGraphAsymmErrors* createScaleSystGraph(TString lepSel, TString variable, const TGraphAsymmErrors *grGenToCentral)
{
    int nPoints = grGenToCentral->GetN();
    double *xCoor    = new double[nPoints];
    double *yCoor    = new double[nPoints];
    double *xErr     = new double[nPoints];
    double *yErrUp   = new double[nPoints];
    double *yErrDown = new double[nPoints];

    TFile *fDE;
    if (lepSel == "DE" || lepSel == "") {
        fDE = new TFile("HistoFilesUnc/DE_8TeV_DYJetsToLL_M-50_TuneCUETP8M1_8TeV-amcatnloFXFX-Bonzai_fixed_allWeights_dR_TrigCorr_1_Syst_0_JetPtMin_30_JetEtaMax_24.root");
    }

    TFile *fDMu;
    if (lepSel == "DMu" || lepSel == "") {
        fDMu = new TFile("HistoFilesUnc/DMu_8TeV_DYJetsToLL_M-50_TuneCUETP8M1_8TeV-amcatnloFXFX-Bonzai_fixed_allWeights_dR_TrigCorr_1_Syst_0_JetPtMin_30_JetEtaMax_24.root");
    }

    TGraphAsymmErrors *grDE, *grDMu;
    if (lepSel == "DE" || lepSel == "") {
        grDE = (TGraphAsymmErrors*) fDE->Get("gen" + variable + "_scaleUnc");
    }
    if (lepSel == "DMu" || lepSel == "") {
        grDMu = (TGraphAsymmErrors*) fDMu->Get("gen" + variable + "_scaleUnc");
    }

    // ---- this variable is used to fetch the TGraph of scale uncertainty from input file ----
    double *xMeanDMu  = new double[nPoints];
    double *yMeanDMu  = new double[nPoints];
    double *xMeanDE   = new double[nPoints];
    double *yMeanDE   = new double[nPoints];

    for (int i(0); i < nPoints; i++) {
        grGenToCentral->GetPoint(i, xCoor[i], yCoor[i]);

        xErr[i] = grGenToCentral->GetErrorXlow(i);

        yErrUp[i] = pow(grGenToCentral->GetErrorYhigh(i), 2);
        yErrDown[i] = pow(grGenToCentral->GetErrorYlow(i), 2);

        if (lepSel == "DMu") {
            grDMu->GetPoint(i, xMeanDMu[i], yMeanDMu[i]);
            yErrUp[i] += pow((grDMu->GetErrorYhigh(i)/yMeanDMu[i]) * yCoor[i], 2);
            yErrDown[i] += pow((grDMu->GetErrorYlow(i)/yMeanDMu[i]) * yCoor[i], 2);
        }

        if (lepSel == "DE") {
            grDE->GetPoint(i, xMeanDE[i], yMeanDE[i]);
            yErrUp[i] += pow((grDE->GetErrorYhigh(i)/yMeanDE[i]) * yCoor[i], 2);
            yErrDown[i] += pow((grDE->GetErrorYlow(i)/yMeanDE[i]) * yCoor[i], 2);
        }

        if (lepSel == "") {
            grDMu->GetPoint(i, xMeanDMu[i], yMeanDMu[i]);
            grDE->GetPoint(i, xMeanDE[i], yMeanDE[i]);
            yErrUp[i] += pow(((grDMu->GetErrorYhigh(i) + grDE->GetErrorYhigh(i)) / (yMeanDMu[i] + yMeanDE[i])) * yCoor[i], 2);
            yErrDown[i] += pow(((grDMu->GetErrorYlow(i) + grDE->GetErrorYlow(i)) / (yMeanDMu[i] + yMeanDE[i])) * yCoor[i], 2);
        }

        yErrUp[i] = sqrt(yErrUp[i]);
        yErrDown[i] = sqrt(yErrDown[i]);

    }

    TGraphAsymmErrors *grScaleSyst = new TGraphAsymmErrors(nPoints, xCoor, yCoor, xErr, xErr, yErrDown, yErrUp);
    delete [] xCoor; delete [] yCoor; delete [] xErr; delete [] yErrDown; delete [] yErrUp;
    delete [] xMeanDMu; delete [] yMeanDMu; delete [] xMeanDE; delete [] yMeanDE;
    if (lepSel == "DE" || lepSel == "") {
        fDE->Close();
    }
    if (lepSel == "DMu" || lepSel == "") {
        fDMu->Close();
    }
    return grScaleSyst;

}

// ---- create PDF systematic graph with other uncertainty in quadrature ----
TGraphAsymmErrors* createPDFSystGraph(TString lepSel, TString variable, const TGraphAsymmErrors *grGenToCentral, const TGraphAsymmErrors *grGen3ScaleSyst)
{
    int nPoints = grGenToCentral->GetN();
    double *xCoor    = new double[nPoints];
    double *yCoor    = new double[nPoints];
    double *xErr     = new double[nPoints];
    double *yErrUp   = new double[nPoints];
    double *yErrDown = new double[nPoints];

    TFile *fDE;
    if (lepSel == "DE" || lepSel == "") {
        fDE = new TFile("HistoFilesUnc/DE_8TeV_DYJetsToLL_M-50_TuneCUETP8M1_8TeV-amcatnloFXFX-Bonzai_fixed_allWeights_dR_TrigCorr_1_Syst_0_JetPtMin_30_JetEtaMax_24.root");
    }

    TFile *fDMu;
    if (lepSel == "DMu" || lepSel == "") {
        fDMu = new TFile("HistoFilesUnc/DMu_8TeV_DYJetsToLL_M-50_TuneCUETP8M1_8TeV-amcatnloFXFX-Bonzai_fixed_allWeights_dR_TrigCorr_1_Syst_0_JetPtMin_30_JetEtaMax_24.root");
    }

    TGraphAsymmErrors *grDE, *grDMu;
    if (lepSel == "DE" || lepSel == "") {
        grDE = (TGraphAsymmErrors*) fDE->Get("gen" + variable + "_pdfUnc");
    }
    if (lepSel == "DMu" || lepSel == "") {
        grDMu = (TGraphAsymmErrors*) fDMu->Get("gen" + variable + "_pdfUnc");
    }

    // ---- this variable is used to fetch the TGraph of scale uncertainty from input file ----
    double *xMeanDMu  = new double[nPoints];
    double *yMeanDMu  = new double[nPoints];
    double *xMeanDE   = new double[nPoints];
    double *yMeanDE   = new double[nPoints];

    for (int i(0); i < nPoints; i++) {
        grGenToCentral->GetPoint(i, xCoor[i], yCoor[i]);

        xErr[i] = grGenToCentral->GetErrorXlow(i);
        yErrUp[i] = pow(grGenToCentral->GetErrorYhigh(i), 2) + pow(grGen3ScaleSyst->GetErrorYhigh(i), 2);
        yErrDown[i] = pow(grGenToCentral->GetErrorYlow(i), 2) + pow(grGen3ScaleSyst->GetErrorYlow(i), 2);

        if (lepSel == "DMu") {
            grDMu->GetPoint(i, xMeanDMu[i], yMeanDMu[i]);
            yErrUp[i] += pow((grDMu->GetErrorYhigh(i)/yMeanDMu[i]) * yCoor[i], 2);
            yErrDown[i] += pow((grDMu->GetErrorYlow(i)/yMeanDMu[i]) * yCoor[i], 2);
        }

        if (lepSel == "DE") {
            grDE->GetPoint(i, xMeanDE[i], yMeanDE[i]);
            yErrUp[i] += pow((grDE->GetErrorYhigh(i)/yMeanDE[i]) * yCoor[i], 2);
            yErrDown[i] += pow((grDE->GetErrorYlow(i)/yMeanDE[i]) * yCoor[i], 2);
        }

        if (lepSel == "") {
            grDMu->GetPoint(i, xMeanDMu[i], yMeanDMu[i]);
            grDE->GetPoint(i, xMeanDE[i], yMeanDE[i]);
            yErrUp[i] += pow(((grDMu->GetErrorYhigh(i) + grDE->GetErrorYhigh(i)) / (yMeanDMu[i] + yMeanDE[i])) * yCoor[i], 2);
            yErrDown[i] += pow(((grDMu->GetErrorYlow(i) + grDE->GetErrorYlow(i)) / (yMeanDMu[i] + yMeanDE[i])) * yCoor[i], 2);
        }

        yErrUp[i] = sqrt(yErrUp[i]);
        yErrDown[i] = sqrt(yErrDown[i]);

    }

    TGraphAsymmErrors *grPDFSyst = new TGraphAsymmErrors(nPoints, xCoor, yCoor, xErr, xErr, yErrDown, yErrUp);
    delete [] xCoor; delete [] yCoor; delete [] xErr; delete [] yErrDown; delete [] yErrUp;
    delete [] xMeanDMu; delete [] yMeanDMu; delete [] xMeanDE; delete [] yMeanDE;

    if (lepSel == "DE" || lepSel == "") {
        fDE->Close();
    }
    if (lepSel == "DMu" || lepSel == "") {
        fDMu->Close();
    }

    return grPDFSyst;
}


// ---- create PDF systematical graph without other uncertainty in quadrature ----
TGraphAsymmErrors* createPDFSystGraph(TString lepSel, TString variable, const TGraphAsymmErrors *grGenToCentral)
{
    int nPoints = grGenToCentral->GetN();
    double *xCoor    = new double[nPoints];
    double *yCoor    = new double[nPoints];
    double *xErr     = new double[nPoints];
    double *yErrUp   = new double[nPoints];
    double *yErrDown = new double[nPoints];

    TFile *fDE;
    if (lepSel == "DE" || lepSel == "") {
        fDE = new TFile("HistoFilesUnc/DE_8TeV_DYJetsToLL_M-50_TuneCUETP8M1_8TeV-amcatnloFXFX-Bonzai_fixed_allWeights_dR_TrigCorr_1_Syst_0_JetPtMin_30_JetEtaMax_24.root");
    }

    TFile *fDMu;
    if (lepSel == "DMu" || lepSel == "") {
        fDMu = new TFile("HistoFilesUnc/DMu_8TeV_DYJetsToLL_M-50_TuneCUETP8M1_8TeV-amcatnloFXFX-Bonzai_fixed_allWeights_dR_TrigCorr_1_Syst_0_JetPtMin_30_JetEtaMax_24.root");
    }

    TGraphAsymmErrors *grDE, *grDMu;
    if (lepSel == "DE" || lepSel == "") {
        grDE = (TGraphAsymmErrors*) fDE->Get("gen" + variable + "_pdfUnc");
    }
    if (lepSel == "DMu" || lepSel == "") {
        grDMu = (TGraphAsymmErrors*) fDMu->Get("gen" + variable + "_pdfUnc");
    }

    // ---- this variable is used to fetch the TGraph of scale uncertainty from input file ----
    double *xMeanDMu  = new double[nPoints];
    double *yMeanDMu  = new double[nPoints];
    double *xMeanDE   = new double[nPoints];
    double *yMeanDE   = new double[nPoints];

    for (int i(0); i < nPoints; i++) {
        grGenToCentral->GetPoint(i, xCoor[i], yCoor[i]);

        xErr[i] = grGenToCentral->GetErrorXlow(i);

        if (lepSel == "DMu") {
            grDMu->GetPoint(i, xMeanDMu[i], yMeanDMu[i]);
            yErrUp[i] += pow((grDMu->GetErrorYhigh(i)/yMeanDMu[i]) * yCoor[i], 2);
            yErrDown[i] += pow((grDMu->GetErrorYlow(i)/yMeanDMu[i]) * yCoor[i], 2);
        }

        if (lepSel == "DE") {
            grDE->GetPoint(i, xMeanDE[i], yMeanDE[i]);
            yErrUp[i] += pow((grDE->GetErrorYhigh(i)/yMeanDE[i]) * yCoor[i], 2);
            yErrDown[i] += pow((grDE->GetErrorYlow(i)/yMeanDE[i]) * yCoor[i], 2);
        }

        if (lepSel == "") {
            grDMu->GetPoint(i, xMeanDMu[i], yMeanDMu[i]);
            grDE->GetPoint(i, xMeanDE[i], yMeanDE[i]);
            yErrUp[i] += pow(((grDMu->GetErrorYhigh(i) + grDE->GetErrorYhigh(i)) / (yMeanDMu[i] + yMeanDE[i])) * yCoor[i], 2);
            yErrDown[i] += pow(((grDMu->GetErrorYlow(i) + grDE->GetErrorYlow(i)) / (yMeanDMu[i] + yMeanDE[i])) * yCoor[i], 2);
        }

    }

    TGraphAsymmErrors *grPDFSyst = new TGraphAsymmErrors(nPoints, xCoor, yCoor, xErr, xErr, yErrDown, yErrUp);
    delete [] xCoor; delete [] yCoor; delete [] xErr; delete [] yErrDown; delete [] yErrUp;
    delete [] xMeanDMu; delete [] yMeanDMu; delete [] xMeanDE; delete [] yMeanDE;

    if (lepSel == "DE" || lepSel == "") {
        fDE->Close();
    }
    if (lepSel == "DMu" || lepSel == "") {
        fDMu->Close();
    }

    return grPDFSyst;
}

void customizeGenGraph(TH1D *hSyst, TGraphAsymmErrors *gen, TGraphAsymmErrors *gScale, TGraphAsymmErrors *gPDF, int genNum, TString yTitle, int numbOfGenerator, TLegend *legend)
{
    hSyst->GetYaxis()->SetRangeUser(0.2, 1.8);
    hSyst->GetYaxis()->SetNdivisions(507);
    hSyst->GetYaxis()->SetLabelSize(0.15);
    hSyst->GetYaxis()->SetTitle(yTitle);
    hSyst->GetYaxis()->SetTitleSize(0.14);
    hSyst->GetYaxis()->SetTitleOffset(0.45);
    hSyst->GetYaxis()->CenterTitle();
    //hSyst->SetTitle();
    gen->SetFillColor(ZJetsFillColor[genNum-1]);
    gen->SetFillStyle(ZJetsFillStyle);
    gen->SetLineColor(ZJetsLineColor[genNum-1]);
    gen->SetLineWidth(2);
    gen->SetMarkerColor(ZJetsLineColor[genNum-1]);
    gen->SetMarkerStyle(ZJetsMarkerStyle[genNum-1]);

    gScale->SetFillStyle(ZJetsFillStyle);
    gScale->SetLineColor(ZJetsLineColor[genNum-1]);
    gScale->SetLineWidth(2);
    gScale->SetFillColor(kGreen-8);

    gPDF->SetFillStyle(0);
    gPDF->SetLineColor(ZJetsLineColor[genNum-1]);
    gPDF->SetLineWidth(2);

    if (genNum == numbOfGenerator) {
        hSyst->GetYaxis()->SetLabelSize(0.09);
        if (numbOfGenerator == 2) hSyst->GetYaxis()->SetLabelSize(0.105);
        if (numbOfGenerator == 3) hSyst->GetYaxis()->SetLabelSize(0.115);
        hSyst->GetYaxis()->SetTitleSize(0.08);
        if (numbOfGenerator == 2) hSyst->GetYaxis()->SetTitleSize(0.100);
        if (numbOfGenerator == 3) hSyst->GetYaxis()->SetTitleSize(0.10);
        hSyst->GetYaxis()->SetTitleOffset(0.8);
        if (numbOfGenerator == 2) hSyst->GetYaxis()->SetTitleOffset(0.63);
        if (numbOfGenerator == 3) hSyst->GetYaxis()->SetTitleOffset(0.60);
        hSyst->GetXaxis()->SetLabelSize(0.12);
        hSyst->GetXaxis()->SetTitleSize(0.12);
        hSyst->GetXaxis()->SetTitleOffset(1.0);
    }
    else {
        hSyst->GetXaxis()->SetTitle();
    }

    if (legend) {
        TLegendEntry *leEntry;
        TLegendEntry *statEntry;
        TLegendEntry *pdfEntry;
        if(genNum == 3) {
            legend->SetX2(0.9);
            legend->SetNColumns(3);
            statEntry = legend->AddEntry(gen, "Stat. unc.", "f");
            leEntry = legend->AddEntry(gScale, "Stat #oplus Theory. unc. ", "f");
            pdfEntry = legend->AddEntry(gPDF, "Stat #oplus Theory #oplus PDF. unc.", "f");

            statEntry->SetFillColor(ZJetsFillColor[genNum-1]);
            statEntry->SetFillStyle(ZJetsFillStyle);
            leEntry->SetFillStyle(ZJetsFillStyle);
            pdfEntry->SetFillStyle(0);
        }
        else {
            leEntry = legend->AddEntry(gen, "Stat. unc.", "f");
            leEntry->SetFillColor(ZJetsFillColor[genNum-1]);
            leEntry->SetFillStyle(ZJetsFillStyle);
        }
    }
}


void customizeGenGraph(TH1D *hSyst, TGraphAsymmErrors *gen, TGraphAsymmErrors *gPDF, int genNum, TString yTitle, int numbOfGenerator, TLegend *legend)
{
    hSyst->GetYaxis()->SetRangeUser(0.2, 1.8);
    hSyst->GetYaxis()->SetNdivisions(507);
    hSyst->GetYaxis()->SetLabelSize(0.15);
    hSyst->GetYaxis()->SetTitle(yTitle);
    hSyst->GetYaxis()->SetTitleSize(0.14);
    hSyst->GetYaxis()->SetTitleOffset(0.45);
    hSyst->GetYaxis()->CenterTitle();
    //hSyst->SetTitle();
    gen->SetFillColor(ZJetsFillColor[genNum-1]);
    gen->SetFillStyle(ZJetsFillStyle);
    gen->SetLineColor(ZJetsLineColor[genNum-1]);
    gen->SetLineWidth(2);
    gen->SetMarkerColor(ZJetsLineColor[genNum-1]);
    gen->SetMarkerStyle(ZJetsMarkerStyle[genNum-1]);

    gPDF->SetFillStyle(0);
    gPDF->SetLineColor(ZJetsLineColor[genNum-1]);
    gPDF->SetLineWidth(2);

    if (genNum == numbOfGenerator) {
        hSyst->GetYaxis()->SetLabelSize(0.09);
        if (numbOfGenerator == 2) hSyst->GetYaxis()->SetLabelSize(0.105);
        if (numbOfGenerator == 3) hSyst->GetYaxis()->SetLabelSize(0.115);
        hSyst->GetYaxis()->SetTitleSize(0.08);
        if (numbOfGenerator == 2) hSyst->GetYaxis()->SetTitleSize(0.100);
        if (numbOfGenerator == 3) hSyst->GetYaxis()->SetTitleSize(0.10);
        hSyst->GetYaxis()->SetTitleOffset(0.8);
        if (numbOfGenerator == 2) hSyst->GetYaxis()->SetTitleOffset(0.63);
        if (numbOfGenerator == 3) hSyst->GetYaxis()->SetTitleOffset(0.60);
        hSyst->GetXaxis()->SetLabelSize(0.12);
        hSyst->GetXaxis()->SetTitleSize(0.12);
        hSyst->GetXaxis()->SetTitleOffset(1.0);
    }
    else {
        hSyst->GetXaxis()->SetTitle();
    }

    if (legend) {
        TLegendEntry *leEntry;
        TLegendEntry *statEntry;
        TLegendEntry *pdfEntry;
        if(genNum == 3) {
            legend->SetX2(0.9);
            legend->SetNColumns(3);
            statEntry = legend->AddEntry(gen, "Stat. unc.", "el");
            leEntry = legend->AddEntry(gen, "Stat #oplus Theory. unc. ", "f");
            pdfEntry = legend->AddEntry(gPDF, "Stat #oplus Theory #oplus PDF. unc.", "f");

            statEntry->SetFillColor(ZJetsFillColor[genNum-1]);
            statEntry->SetFillStyle(ZJetsFillStyle);
            leEntry->SetFillStyle(ZJetsFillStyle);
            pdfEntry->SetFillStyle(0);
        }
        else {
            leEntry = legend->AddEntry(gen, "Stat. unc.", "f");
            leEntry->SetFillColor(ZJetsFillColor[genNum-1]);
            leEntry->SetFillStyle(ZJetsFillStyle);
        }
    }
}

void customizeGenHist(TH1D *gen, int genNumb, TLegend *legend, TString legText)
{

    //--- Customize gen Sherpa ---
    gen->SetFillColor(ZJetsFillColor[genNumb-1]);
    gen->SetFillStyle(ZJetsFillStyle);
    gen->SetLineColor(ZJetsLineColor[genNumb-1]);
    gen->SetLineWidth(2);
    gen->SetMarkerColor(ZJetsMarkerColor[genNumb-1]);
    gen->SetMarkerStyle(ZJetsMarkerStyle[genNumb-1]);
    TLegendEntry *le = legend->AddEntry(gen, legText, "pefl");
    le->SetFillColor(ZJetsFillColor[genNumb-1]);
    le->SetFillStyle(ZJetsFillStyle);
    le->SetLineColor(ZJetsLineColor[genNumb-1]);
    le->SetMarkerColor(ZJetsMarkerColor[genNumb-1]);
    le->SetMarkerStyle(ZJetsMarkerStyle[genNumb-1]);
}


void configYaxis(TH1D *grCentralSyst, TH1D *gen1, TH1D *gen2, TH1D *gen3)
{
    //--- Configure Y axis of the plot ---
    double minimumToPlot = grCentralSyst->GetMinimum();
    minimumToPlot = TMath::Min(minimumToPlot, gen1->GetBinContent(gen1->GetMinimumBin()));
    //if (gen2) minimumToPlot = TMath::Min(minimumToPlot, gen2->GetBinContent(gen2->GetMinimumBin()));
    //if (gen3) minimumToPlot = TMath::Min(minimumToPlot, gen3->GetBinContent(gen3->GetMinimumBin()));

    double maximumToPlot = grCentralSyst->GetMaximum();
    maximumToPlot = TMath::Max(maximumToPlot, gen1->GetBinContent(gen1->GetMaximumBin()));
    //if (gen2) maximumToPlot = TMath::Max(maximumToPlot, gen2->GetBinContent(gen2->GetMaximumBin()));
    //if (gen3) maximumToPlot = TMath::Max(maximumToPlot, gen3->GetBinContent(gen3->GetMaximumBin()));

    grCentralSyst->GetYaxis()->SetRangeUser(0.2*minimumToPlot, 5*maximumToPlot);
    //if (TString(grCentralSyst->GetName()).Contains("Eta")) {
    //    grCentralSyst->GetYaxis()->SetRangeUser(0.001, 1.4*maximumToPlot);
    //}
}

//void configXaxis(TGraphAsymmErrors *grCentralSyst, TH1D *gen1)
void configXaxis(TH1D *grCentralSyst, TH1D *gen1, TString variable)
{
    //--- Configure X axis of the plot ---
    //double minX, tmp;
    //double maxX;
    //TString variable = gen1->GetName();
    //grCentralSyst->GetPoint(firstBin, minX, tmp);
    //grCentralSyst->GetPoint(grCentralSyst->GetN()-1, maxX, tmp);
    //minX -= grCentralSyst->GetErrorXlow(firstBin); 
    //maxX += grCentralSyst->GetErrorXhigh(grCentralSyst->GetN()-1);
    if (variable.Index("ZNGoodJets_Zexc") >= 0) {
        //grCentralSyst->GetXaxis()->Set(maxX-minX, minX, maxX);
        grCentralSyst->GetXaxis()->SetBinLabel(1, "= 0");
        grCentralSyst->GetXaxis()->SetBinLabel(2, "= 1");
        grCentralSyst->GetXaxis()->SetBinLabel(3, "= 2");
        grCentralSyst->GetXaxis()->SetBinLabel(4, "= 3");
        grCentralSyst->GetXaxis()->SetBinLabel(5, "= 4");
        grCentralSyst->GetXaxis()->SetBinLabel(6, "= 5");
        grCentralSyst->GetXaxis()->SetBinLabel(7, "= 6");
        grCentralSyst->GetXaxis()->SetBinLabel(8, "= 7");
        grCentralSyst->GetXaxis()->SetBinLabel(9, "= 8");
        grCentralSyst->GetXaxis()->SetLabelSize(0.17);
        grCentralSyst->GetXaxis()->SetLabelOffset(0.01);
    }
    else if (variable.Index("ZNGoodJets_Zinc") >= 0) {
        //grCentralSyst->GetXaxis()->Set(maxX-minX, minX, maxX);
        grCentralSyst->GetXaxis()->SetBinLabel(1, "#geq 0");
        grCentralSyst->GetXaxis()->SetBinLabel(2, "#geq 1");
        grCentralSyst->GetXaxis()->SetBinLabel(3, "#geq 2");
        grCentralSyst->GetXaxis()->SetBinLabel(4, "#geq 3");
        grCentralSyst->GetXaxis()->SetBinLabel(5, "#geq 4");
        grCentralSyst->GetXaxis()->SetBinLabel(6, "#geq 5");
        grCentralSyst->GetXaxis()->SetBinLabel(7, "#geq 6");
        grCentralSyst->GetXaxis()->SetBinLabel(8, "#geq 7");
        grCentralSyst->GetXaxis()->SetLabelSize(0.17);
        grCentralSyst->GetXaxis()->SetLabelOffset(0.01);
    }
    //grCentralSyst->GetXaxis()->SetRangeUser(minX, maxX);
    TString xtitle = gen1->GetXaxis()->GetTitle();
    if (xtitle.Index("^{gen}") >= 0) xtitle = xtitle.ReplaceAll("^{gen}","");
    if (xtitle.Index("H_{T}") >= 0) {
        TString njets;
        if (variable.Index("Zinc1jet") >= 0) njets = "1";
        else if (variable.Index("Zinc2jet") >= 0) njets = "2";
        else if (variable.Index("Zinc3jet") >= 0) njets = "3";
        else if (variable.Index("Zinc4jet") >= 0) njets = "4";
        else if (variable.Index("Zinc5jet") >= 0) njets = "5";
        else if (variable.Index("Zinc6jet") >= 0) njets = "6";
        else if (variable.Index("Zinc7jet") >= 0) njets = "7";
        else if (variable.Index("Zinc8jet") >= 0) njets = "8";
        xtitle = "H_{T}, N_{jets} #geq " + njets + " [GeV]";
    }
    grCentralSyst->GetXaxis()->SetTitle(xtitle);
    grCentralSyst->GetXaxis()->SetTitleSize(0.12);
    //-----------------------------------------

}

std::string getYaxisTitle(bool doNormalized, const TH1D *gen1)
{
    std::string title = "";
    std::string xtitle = gen1->GetXaxis()->GetTitle();
    std::string shortVar = xtitle.substr(0, xtitle.find(" "));
    std::string unit = "";
    if (xtitle.find("^{gen}") != std::string::npos) {
        xtitle.replace(xtitle.find("^{gen}"),6,"");
    }
    if (xtitle.find("[") != std::string::npos){
        size_t begin = xtitle.find("[") + 1;
        unit = xtitle.substr(begin);
        unit = unit.substr(0, unit.find("]"));
    }
    title = "d#sigma/d" + shortVar;
    if (doNormalized) {
        title = "1/#sigma " + title;
    }
    else {
        title += "  [pb";
        if (unit != "" ) title += "/" + unit;
        title += "]";
    }
    return title;
}

TCanvas* makeCrossSectionPlot(TString lepSel, TString variable, TH1D *hStat, TH2D *hCovSyst, TH1D *hStatNorm, TH2D *hCovSystNorm, TH1D *hGen1, TH1D *hGen2, TH1D* hGen3)
{

    gStyle->SetOptStat(0);
    //--- Determine how many comparison we have ---
    int numbOfGenerator = 1;
    if (hGen2) numbOfGenerator = 2;
    if (hGen3) numbOfGenerator = 3;
    //---------------------------------------------

    //TH1D *hPDFUp = (TH1D*) hStat->Clone("hPDFUp");
    //hPDFUp->Scale(1.10);
    //TH1D *hPDFDown = (TH1D*) hStat->Clone("hPDFDown");
    //hPDFDown->Scale(0.75);

    TH1D *hSyst = (TH1D*) hStat->Clone("hSyst");
    int nBins = hSyst->GetNbinsX();
    for (int i = 1; i <= nBins; ++i) {
        hSyst->SetBinError(i, sqrt(pow(hStat->GetBinError(i), 2) + hCovSyst->GetBinContent(i, i)));
    }

    TH1D *hSystNorm = (TH1D*) hStatNorm->Clone("hSystNorm");
    for (int i = 1; i <= nBins; ++i) {
        hSystNorm->SetBinError(i, sqrt(pow(hStatNorm->GetBinError(i), 2) + hCovSystNorm->GetBinContent(i, i)));
    }

    //--- Declare all additional TGraphs ---
    TGraphAsymmErrors *grCentralStat = createGrFromHist(hStat);
    grCentralStat->SetName("gr" + variable + "CentralStatError"); 
    TGraphAsymmErrors *grCentralSyst = createGrFromHist(hSyst);
    grCentralSyst->SetName("gr" + variable + "CentralTotError"); 
    TGraphAsymmErrors *grCentralStatRatio = createRatioGraph(grCentralStat);
    TGraphAsymmErrors *grCentralSystRatio = createRatioGraph(grCentralSyst);
    TGraphAsymmErrors *grGen1ToCentral = createGenToCentral(hGen1, grCentralStat);
    TGraphAsymmErrors *grGen1PDFSyst = createPDFSystGraph(lepSel, variable, grGen1ToCentral); 
    TGraphAsymmErrors *grGen2ToCentral = NULL;
    TGraphAsymmErrors *grGen2PDFSyst = NULL;
    if (hGen2) {
        grGen2ToCentral = createGenToCentral(hGen2, grCentralStat);
        grGen2PDFSyst = createPDFSystGraph(lepSel, variable, grGen2ToCentral); 
    }
    TGraphAsymmErrors *grGen3ToCentral = NULL;
    TGraphAsymmErrors *grGen3PDFSyst = NULL;
    TGraphAsymmErrors *grGen3ScaleSyst = NULL;
    if (hGen3) {
        grGen3ToCentral = createGenToCentral(hGen3, grCentralStat);
        grGen3ScaleSyst = createScaleSystGraph(lepSel, variable, grGen3ToCentral);
        grGen3PDFSyst = createPDFSystGraph(lepSel, variable, grGen3ToCentral, grGen3ScaleSyst); 
    }
    //---------------------------------------------
    // --- For normalisation band ---
    TGraphAsymmErrors *grCentralSystNorm = createGrFromHist(hSystNorm);
    grCentralSystNorm->SetName("gr" + variable + "CentralTotNormError"); 
    TGraphAsymmErrors *grCentralSystRatioNorm = createRatioGraph(grCentralSystNorm);

    //--- Main Canvas ---
    double maximum = hGen1->GetMaximum();
    double minimum = hGen1->GetMinimum();
    TString canvasName = "canvas" + variable;
    TCanvas *plots = new TCanvas(canvasName, hStat->GetTitle(), 600, 800);
    //-------------------

    //--- First Pad ---
    plots->cd();
    TPad *plot1 = new TPad("plot1", "plot1", 0., 0., 0., 0.);
    setAndDrawTPad(canvasName, plot1, 1, numbOfGenerator);

    //--- TLegend ---
    TLegend *legend = new TLegend(0.7, 0.74, 0.99, 0.98);
    customizeLegend(legend, numbOfGenerator);
    //------------------

    customizeCentral(grCentralSyst, legend, "Data");
    customizeCentral(grCentralStat, false);
    customizeCentral(grCentralSystRatio, true);
    customizeCentralNorm(grCentralSystRatioNorm, true); // normalisation band in ratio pad
    customizeCentral(grCentralStatRatio, true);
    hSyst->SetLineColor(kWhite);
    hSyst->SetMarkerColor(kWhite);
    hSyst->SetTitle("");
    hSyst->GetXaxis()->SetLabelSize(0);
    hSyst->GetYaxis()->SetTitle("");
    hSyst->GetYaxis()->SetLabelSize(0.055);
    configXaxis(hSyst, hGen1, variable);
    configYaxis(hSyst, hGen1, hGen2, hGen3);
    if (canvasName.Contains("ZNGoodJets")) {
        hSyst->GetXaxis()->SetRangeUser(0, hSyst->GetXaxis()->GetXmax());
    }
    if (canvasName.Contains("JetPt_Zinc")) {
        hSyst->GetXaxis()->SetRangeUser(30, hSyst->GetXaxis()->GetXmax());
    }
    if (canvasName.Contains("Eta") || canvasName.Contains("AbsRapidity")) {
        hSyst->GetYaxis()->SetRangeUser(0.001, 1.4*maximum);
    }
    if (canvasName.Contains("DPhi") && (!canvasName.Contains("DPhiZFirstJet"))) {
        hSyst->GetYaxis()->SetRangeUser(0.1*minimum, 2.0*maximum);
    }
    hSyst->DrawCopy("e");
    grCentralSyst->SetName("grCentralSyst");
    grCentralSyst->Draw("2");
    customizeGenHist(hGen1, 1, legend, hGen1->GetZaxis()->GetTitle());
    hGen1->SetName("hGen1");
    hGen1->DrawCopy("ESAME");

    if (hGen2) {
        customizeGenHist(hGen2, 2, legend, hGen2->GetZaxis()->GetTitle());
        hGen2->SetName("hGen2");
        hGen2->DrawCopy("ESAME");
    }
    if (hGen3) {
        customizeGenHist(hGen3, 3, legend, hGen3->GetZaxis()->GetTitle());
        hGen3->SetName("hGen3");
        hGen3->DrawCopy("ESAME");
    }

    grCentralStat->SetName("grCentralStat");
    grCentralStat->Draw("p");

    legend->Draw("same");

    //--- TLatex stuff ---
    TLatex *latexLabel = new TLatex(); 
    latexLabel->SetNDC();
    latexLabel->SetTextSize(0.035);
    if (hGen2) latexLabel->SetTextSize(0.035);
    if (hGen3) latexLabel->SetTextSize(0.05);
    latexLabel->SetTextFont(42);
    latexLabel->SetLineWidth(2);

    latexLabel->SetTextFont(61);
    latexLabel->DrawLatex(0.18,0.83,"CMS");
    latexLabel->SetTextFont(52);
    //latexLabel->DrawLatex(0.25,0.83,"Preliminary");
    latexLabel->SetTextFont(42);
    latexLabel->DrawLatex(0.13,0.95-0.045,"19.6 fb^{-1} (8 TeV)");

    if(canvasName.Index("DPhi") > 0 && canvasName.Contains("ZFirstJet")){
        latexLabel->DrawLatex(0.66,0.21-0.04,"anti-k_{T} (R = 0.5) Jets");
    }

    else if(canvasName.Index("DPhi") > 0 && canvasName.Contains("ZSecondJet")){
        latexLabel->DrawLatex(0.18,0.7,"anti-k_{T} (R = 0.5) Jets");
    }

    else if(canvasName.Index("DPhi") > 0 && canvasName.Contains("ZThirdJet")){
        latexLabel->DrawLatex(0.18,0.7,"anti-k_{T} (R = 0.5) Jets");
    }

    else if(canvasName.Index("DPhi") > 0 && canvasName.Contains("FirstSecondJet") && (!canvasName.Contains("ZPt150")) && (!canvasName.Contains("ZPt300"))){
        latexLabel->DrawLatex(0.18,0.7,"anti-k_{T} (R = 0.5) Jets");
    }

    else if(canvasName.Index("DPhi") > 0 && canvasName.Contains("FirstThirdJet")){
        latexLabel->DrawLatex(0.18,0.7,"anti-k_{T} (R = 0.5) Jets");
    }

    else{
        latexLabel->DrawLatex(0.18,0.21-0.05,"anti-k_{T} (R = 0.5) Jets");
    }

    // ------------------------------------------------------------------------------------
    if (canvasName.Contains("FirstJetPt50") && canvasName.Index("Rapidity") > 0){
        latexLabel->DrawLatex(0.18,0.21-0.11,"p_{T}^{jet} > 50 GeV, |y^{jet}| < 2.4 ");
    }

    else if (canvasName.Contains("FirstJetPt80") && canvasName.Index("Rapidity") > 0){
        latexLabel->DrawLatex(0.18,0.21-0.11,"p_{T}^{jet} > 80 GeV, |y^{jet}| < 2.4 ");
    }

    else if (canvasName.Contains("ZPt150") && canvasName.Index("Rapidity") > 0){
        latexLabel->DrawLatex(0.18,0.21-0.11,"p_{T}^{Z} > 150 GeV, p_{T}^{jet} > 30 GeV, |y^{jet}| < 2.4 ");
    }

    else if (canvasName.Contains("ZPt300") && canvasName.Index("Rapidity") > 0){
        latexLabel->DrawLatex(0.18,0.21-0.11,"p_{T}^{Z} > 300 GeV, p_{T}^{jet} > 30 GeV, |y^{jet}| < 2.4 ");
    }

    else if (canvasName.Contains("DifJetRapidityl2") && canvasName.Index("Rapidity") > 0){
        latexLabel->DrawLatex(0.18,0.21-0.11,"p_{T}^{jet} > 30 GeV, |y^{jet}| < 2.4, |y_{jet1}-y_{jet2}| > 2 ");
    }

    else if (canvasName.Contains("DifJetRapiditys2") && canvasName.Index("Rapidity") > 0){
        latexLabel->DrawLatex(0.18,0.21-0.11,"p_{T}^{jet} > 30 GeV, |y^{jet}| < 2.4, |y_{jet1}-y_{jet2}| < 2 ");
    }

    else if (canvasName.Contains("ZPt150_HT300") && canvasName.Index("Rapidity") > 0){
        latexLabel->DrawLatex(0.18,0.21-0.11,"p_{T}^{Z} > 150 GeV, p_{T}^{jet} > 30 GeV, |y^{jet}| < 2.4, H_{T}^{jet} > 300 GeV ");
    }

    else if ((!canvasName.Contains("ZPt150")) && (!canvasName.Contains("ZPt300")) && (!canvasName.Contains("HT300")) && canvasName.Contains("DPhiZFirstJet")){
        latexLabel->DrawLatex(0.6,0.21-0.11,"p_{T}^{jet} > 30 GeV, |y^{jet}| < 2.4 ");
    }

    else if (canvasName.Contains("ZPt150") && (!canvasName.Contains("HT300")) && canvasName.Contains("DPhiZFirstJet")){
        latexLabel->DrawLatex(0.45,0.21-0.11,"p_{T}^{Z} > 150 GeV, p_{T}^{jet} > 30 GeV, |y^{jet}| < 2.4 ");
    }

    else if (canvasName.Contains("ZPt150_HT300") && canvasName.Contains("DPhiZFirstJet")){
        latexLabel->DrawLatex(0.23,0.21-0.11,"p_{T}^{Z} > 150 GeV, p_{T}^{jet} > 30 GeV, |y^{jet}| < 2.4, H_{T}^{jet} > 300 GeV ");
    }

    else if (canvasName.Contains("ZPt300") && canvasName.Contains("DPhiZFirstJet")){
        latexLabel->DrawLatex(0.45,0.21-0.11,"p_{T}^{Z} > 300 GeV, p_{T}^{jet} > 30 GeV, |y^{jet}| < 2.4 ");
    }

    else if (canvasName.Contains("ZPt150") && (!canvasName.Contains("HT300")) && canvasName.Contains("DPhiZSecondJet")){
        latexLabel->DrawLatex(0.18,0.63,"p_{T}^{Z} > 150 GeV, p_{T}^{jet} > 30 GeV, |y^{jet}| < 2.4 ");
    }

    else if ((!canvasName.Contains("ZPt150")) && (!canvasName.Contains("ZPt300")) && (!canvasName.Contains("HT300")) && canvasName.Contains("DPhiZSecondJet")){
        latexLabel->DrawLatex(0.18,0.63,"p_{T}^{jet} > 30 GeV, |y^{jet}| < 2.4 ");
    }

    else if (canvasName.Contains("ZPt150_HT300") && canvasName.Contains("DPhiZSecondJet")){
        latexLabel->DrawLatex(0.18,0.63,"p_{T}^{Z} > 150 GeV, p_{T}^{jet} > 30 GeV, |y^{jet}| < 2.4, H_{T}^{jet} > 300 GeV ");
    }

    else if (canvasName.Contains("ZPt300") && canvasName.Contains("DPhiZSecondJet")){
        latexLabel->DrawLatex(0.18,0.63,"p_{T}^{Z} > 300 GeV, p_{T}^{jet} > 30 GeV, |y^{jet}| < 2.4 ");
    }

    else if (canvasName.Contains("ZPt150") && (!canvasName.Contains("HT300")) && canvasName.Contains("DPhiZThirdJet")){
        latexLabel->DrawLatex(0.18,0.63,"p_{T}^{Z} > 150 GeV, p_{T}^{jet} > 30 GeV, |y^{jet}| < 2.4 ");
    }

    else if ((!canvasName.Contains("ZPt150")) && (!canvasName.Contains("ZPt300")) && (!canvasName.Contains("HT300")) && canvasName.Contains("DPhiZThirdJet")){
        latexLabel->DrawLatex(0.18,0.63,"p_{T}^{jet} > 30 GeV, |y^{jet}| < 2.4 ");
    }

    else if (canvasName.Contains("ZPt150_HT300") && canvasName.Contains("DPhiZThirdJet")){
        latexLabel->DrawLatex(0.18,0.63,"p_{T}^{Z} > 150 GeV, p_{T}^{jet} > 30 GeV, |y^{jet}| < 2.4, H_{T}^{jet} > 300 GeV ");
    }

    else if (canvasName.Contains("ZPt300") && canvasName.Contains("DPhiZThirdJet")){
        latexLabel->DrawLatex(0.18,0.63,"p_{T}^{Z} > 300 GeV, p_{T}^{jet} > 30 GeV, |y^{jet}| < 2.4 ");
    }

    else if (canvasName.Contains("DPhiFirstSecondJet") && (!canvasName.Contains("ZPt150")) && (!canvasName.Contains("ZPt300"))){
        latexLabel->DrawLatex(0.18,0.63,"p_{T}^{jet} > 30 GeV, |y^{jet}| < 2.4 ");
    }

    else if (canvasName.Contains("DPhiFirstSecondJet") && (canvasName.Contains("ZPt150"))){
        latexLabel->DrawLatex(0.18,0.21-0.11,"p_{T}^{Z} > 150 GeV, p_{T}^{jet} > 30 GeV, |y^{jet}| < 2.4 ");
    }

    else if (canvasName.Contains("DPhiFirstSecondJet") && (canvasName.Contains("ZPt300"))){
        latexLabel->DrawLatex(0.18,0.21-0.11,"p_{T}^{Z} > 300 GeV, p_{T}^{jet} > 30 GeV, |y^{jet}| < 2.4 ");
    }

    else if (canvasName.Contains("DPhiFirstThirdJet") && (!canvasName.Contains("ZPt150")) && (!canvasName.Contains("ZPt300"))){
        latexLabel->DrawLatex(0.18,0.63,"p_{T}^{jet} > 30 GeV, |y^{jet}| < 2.4 ");
    }

    else if (canvasName.Contains("DPhiFirstThirdJet") && (canvasName.Contains("ZPt150"))){
        latexLabel->DrawLatex(0.18,0.63,"p_{T}^{Z} > 150 GeV, p_{T}^{jet} > 30 GeV, |y^{jet}| < 2.4 ");
    }

    else if (canvasName.Contains("DPhiFirstThirdJet") && (canvasName.Contains("ZPt300"))){
        latexLabel->DrawLatex(0.18,0.63,"p_{T}^{Z} > 300 GeV, p_{T}^{jet} > 30 GeV, |y^{jet}| < 2.4 ");
    }

    else if (canvasName.Contains("DPhiSecondThirdJet") && (!canvasName.Contains("ZPt150")) && (!canvasName.Contains("ZPt300"))){
        latexLabel->DrawLatex(0.18,0.21-0.11,"p_{T}^{jet} > 30 GeV, |y^{jet}| < 2.4 ");
    }

    else if (canvasName.Contains("DPhiSecondThirdJet") && (canvasName.Contains("ZPt150"))){
        latexLabel->DrawLatex(0.18,0.21-0.11,"p_{T}^{Z} > 150 GeV, p_{T}^{jet} > 30 GeV, |y^{jet}| < 2.4 ");
    }

    else if (canvasName.Contains("DPhiSecondThirdJet") && (canvasName.Contains("ZPt300"))){
        latexLabel->DrawLatex(0.18,0.21-0.11,"p_{T}^{Z} > 300 GeV, p_{T}^{jet} > 30 GeV, |y^{jet}| < 2.4 ");
    }

    else{
        latexLabel->DrawLatex(0.18,0.21-0.11,"p_{T}^{jet} > 30 GeV, |y^{jet}| < 2.4 ");
    }

    // --------------------------------------------------------------------------------------------
    if(canvasName.Index("DPhi") > 0 && canvasName.Contains("ZFirstJet")){
        if (lepSel == "") latexLabel->DrawLatex(0.66,0.21-0.18,"Z/#gamma*#rightarrow ll channel");
        else if (lepSel == "DMu") latexLabel->DrawLatex(0.66,0.21-0.18,"Z/#gamma*#rightarrow #mu#mu channel");
        else if (lepSel == "DE") latexLabel->DrawLatex(0.66,0.21-0.18,"Z/#gamma*#rightarrow ee channel");
    }

    else if(canvasName.Index("DPhi") > 0 && canvasName.Contains("ZSecondJet")){
        if (lepSel == "") latexLabel->DrawLatex(0.18,0.56,"Z/#gamma*#rightarrow ll channel");
        else if (lepSel == "DMu") latexLabel->DrawLatex(0.18,0.56,"Z/#gamma*#rightarrow #mu#mu channel");
        else if (lepSel == "DE") latexLabel->DrawLatex(0.18,0.56,"Z/#gamma*#rightarrow ee channel");
    }

    else if(canvasName.Index("DPhi") > 0 && canvasName.Contains("ZThirdJet")){
        if (lepSel == "") latexLabel->DrawLatex(0.18,0.56,"Z/#gamma*#rightarrow ll channel");
        else if (lepSel == "DMu") latexLabel->DrawLatex(0.18,0.56,"Z/#gamma*#rightarrow #mu#mu channel");
        else if (lepSel == "DE") latexLabel->DrawLatex(0.18,0.56,"Z/#gamma*#rightarrow ee channel");
    }

    else if(canvasName.Index("DPhi") > 0 && canvasName.Contains("FirstSecondJet") && (!canvasName.Contains("ZPt150")) && (!canvasName.Contains("ZPt300"))){
        if (lepSel == "") latexLabel->DrawLatex(0.18,0.56,"Z/#gamma*#rightarrow ll channel");
        else if (lepSel == "DMu") latexLabel->DrawLatex(0.18,0.56,"Z/#gamma*#rightarrow #mu#mu channel");
        else if (lepSel == "DE") latexLabel->DrawLatex(0.18,0.56,"Z/#gamma*#rightarrow ee channel");
    }

    else if(canvasName.Index("DPhi") > 0 && canvasName.Contains("FirstThirdJet")){
        if (lepSel == "") latexLabel->DrawLatex(0.18,0.56,"Z/#gamma*#rightarrow ll channel");
        else if (lepSel == "DMu") latexLabel->DrawLatex(0.18,0.56,"Z/#gamma*#rightarrow #mu#mu channel");
        else if (lepSel == "DE") latexLabel->DrawLatex(0.18,0.56,"Z/#gamma*#rightarrow ee channel");
    }

    else{
        if (lepSel == "") latexLabel->DrawLatex(0.18,0.21-0.17,"Z/#gamma*#rightarrow ll channel");
        else if (lepSel == "DMu") latexLabel->DrawLatex(0.18,0.21-0.17,"Z/#gamma*#rightarrow #mu#mu channel");
        else if (lepSel == "DE") latexLabel->DrawLatex(0.18,0.21-0.17,"Z/#gamma*#rightarrow ee channel");
    }

    latexLabel->SetName("latexLabel");
    latexLabel->Draw("same");


    TLatex *ytitle = new TLatex();
    ytitle->SetName("ytitle");
    ytitle->SetTextSize(0.04);
    if (hGen2) ytitle->SetTextSize(0.05);
    if (hGen3) ytitle->SetTextSize(0.06);
    ytitle->SetTextFont(42);
    ytitle->SetLineWidth(2);
    ytitle->SetTextColor(kBlack);
    ytitle->SetNDC();
    ytitle->SetTextAlign(33);
    ytitle->SetTextAngle(90);
    std::string strYtitle = getYaxisTitle(false, hGen1);
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
    setAndDrawTPad(canvasName, plot2, 2, numbOfGenerator);


    //--- TLegend ---
    TLegend *legend2 = new TLegend(0.16, 0.05, 0.42, 0.20);
    customizeLegend(legend2, 1, numbOfGenerator);
    TString generator1 = hGen1->GetZaxis()->GetTitle();
    generator1 = generator1(0, generator1.Index(" "));
    customizeGenGraph(hSyst, grGen1ToCentral, grGen1PDFSyst, 1, generator1 + "/Data", numbOfGenerator, legend2);
    configXaxis(hSyst, hGen1, variable);
    hSyst->DrawCopy("e");
    grGen1ToCentral->SetName("grGen1ToCentral");
    grGen1ToCentral->Draw("2");
    //grGen1PDFSyst->Draw("2");
    grCentralSystRatio->SetName("grCentralSystRatio");
    grCentralSystRatio->Draw("2");
    grCentralSystRatioNorm->SetName("grCentralSystRatioNorm");
    grCentralSystRatioNorm->Draw("2");
    grCentralStatRatio->Draw("p");
    grGen1ToCentral->Draw("Xp");
    legend2->Draw("same");
    //if (canvasName.Contains("JetPt_Zinc")) {
    //    grGen1ToCentral->GetXaxis()->SetRangeUser(30, x + ex);
    //}
    plot2->RedrawAxis();
    //--- End of Second Pad ---

    if (hGen2) {
        //--- Third Pad ---
        plots->cd();
        TPad *plot3 = new TPad("plot3", "plot3", 0., 0., 0., 0.);
        setAndDrawTPad(canvasName, plot3, 3, numbOfGenerator);

        //--- TLegend ---
        TLegend *legend3 = new TLegend(0.16, 0.05, 0.42, 0.20);
        customizeLegend(legend3, 2, numbOfGenerator);
        TString generator2 = hGen2->GetZaxis()->GetTitle();
        generator2 = generator2(0, generator2.Index(" "));
        customizeGenGraph(hSyst, grGen2ToCentral, grGen2PDFSyst, 2, generator2 + "/Data", numbOfGenerator, legend3);
        configXaxis(hSyst, hGen2, variable);
        hSyst->DrawCopy("e");
        grGen2ToCentral->SetName("grGen2ToCentral");
        grGen2ToCentral->Draw("2");
        //grGen2PDFSyst->Draw("2");
        grCentralSystRatio->SetName("grCentralSystRatio");
        grCentralSystRatio->Draw("2");
        grCentralSystRatioNorm->SetName("grCentralSystRatioNorm");
        grCentralSystRatioNorm->Draw("2");
        grCentralStatRatio->Draw("p");
        grGen2ToCentral->Draw("Xp");
        legend3->Draw("same");
        //if (canvasName.Contains("JetPt_Zinc")) {
        //    grGen2ToCentral->GetXaxis()->SetRangeUser(30, x + ex);
        //}
        plot3->RedrawAxis();
        //--- End of Third Pad ---
    }

    if (hGen3) {
        //--- Fourth Pad ---
        plots->cd();
        TPad *plot4 = new TPad("plot4", "plot4", 0., 0., 0., 0.);
        setAndDrawTPad(canvasName, plot4, 4, numbOfGenerator);

        //--- TLegend ---
        TLegend *legend4 = new TLegend(0.16, 0.05, 0.42, 0.20);
        customizeLegend(legend4, 3, numbOfGenerator);
        TString generator3 = hGen3->GetZaxis()->GetTitle();
        generator3 = generator3(0, generator3.Index(" "));
        customizeGenGraph(hSyst, grGen3ToCentral, grGen3ScaleSyst, grGen3PDFSyst, 3, generator3 + "/Data", numbOfGenerator, legend4);
        configXaxis(hSyst, hGen3, variable);
        hSyst->DrawCopy("e");
        grGen3ToCentral->SetName("grGen3ToCentral");
        grGen3ToCentral->Draw("2");
        grGen3ScaleSyst->Draw("2");
        grGen3ToCentral->Draw("2");
        grCentralSystRatio->SetName("grCentralSystRatio");
        grCentralSystRatio->Draw("2");
        grCentralSystRatioNorm->SetName("grCentralSystRatioNorm");
        grCentralSystRatioNorm->Draw("2");
        grCentralStatRatio->Draw("p");
        grGen3ToCentral->Draw("Xp");
        grGen3PDFSyst->Draw("2");
        legend4->Draw("same");
        //if (canvasName.Contains("JetPt_Zinc")) {
        //    grGen3ToCentral->GetXaxis()->SetRangeUser(30, x + ex);
        //}
        plot4->RedrawAxis();
        //--- End of Fourth Pad ---
    }
    plots->Update();
    return plots;
}


TCanvas* makeCrossSectionPlot(TString lepSel, TString variable, bool doNormalized, TH1D *hStat, TH2D *hCovSyst, TH1D *hGen1, TH1D *hGen2, TH1D* hGen3)
{

    gStyle->SetOptStat(0);
    //--- Determine how many comparison we have ---
    int numbOfGenerator = 1;
    if (hGen2) numbOfGenerator = 2;
    if (hGen3) numbOfGenerator = 3;
    //---------------------------------------------

    //TH1D *hPDFUp = (TH1D*) hStat->Clone("hPDFUp");
    //hPDFUp->Scale(1.10);
    //TH1D *hPDFDown = (TH1D*) hStat->Clone("hPDFDown");
    //hPDFDown->Scale(0.75);

    TH1D *hSyst = (TH1D*) hStat->Clone("hSyst");
    int nBins = hSyst->GetNbinsX();
    for (int i = 1; i <= nBins; ++i) {
        hSyst->SetBinError(i, sqrt(pow(hStat->GetBinError(i), 2) + hCovSyst->GetBinContent(i, i)));
    }

    //--- Declare all additional TGraphs ---
    TGraphAsymmErrors *grCentralStat = createGrFromHist(hStat);
    grCentralStat->SetName("gr" + variable + "CentralStatError"); 
    TGraphAsymmErrors *grCentralSyst = createGrFromHist(hSyst);
    grCentralSyst->SetName("gr" + variable + "CentralTotError"); 
    TGraphAsymmErrors *grCentralStatRatio = createRatioGraph(grCentralStat);
    TGraphAsymmErrors *grCentralSystRatio = createRatioGraph(grCentralSyst);
    TGraphAsymmErrors *grGen1ToCentral = createGenToCentral(hGen1, grCentralStat);
    TGraphAsymmErrors *grGen1PDFSyst = createPDFSystGraph(lepSel, variable, grGen1ToCentral); 
    TGraphAsymmErrors *grGen2ToCentral = NULL;
    TGraphAsymmErrors *grGen2PDFSyst = NULL;
    if (hGen2) {
        grGen2ToCentral = createGenToCentral(hGen2, grCentralStat);
        grGen2PDFSyst = createPDFSystGraph(lepSel, variable, grGen2ToCentral); 
    }
    TGraphAsymmErrors *grGen3ToCentral = NULL;
    TGraphAsymmErrors *grGen3PDFSyst = NULL;
    TGraphAsymmErrors *grGen3ScaleSyst = NULL;
    if (hGen3) {
        grGen3ToCentral = createGenToCentral(hGen3, grCentralStat);
        grGen3ScaleSyst = createScaleSystGraph(lepSel, variable, grGen3ToCentral);
        grGen3PDFSyst = createPDFSystGraph(lepSel, variable, grGen3ToCentral, grGen3ScaleSyst); 
    }
    //---------------------------------------------

    //--- Main Canvas ---
    double maximum = hGen1->GetMaximum();
    double minimum = hGen1->GetMinimum();
    TString canvasName = "canvas" + variable;
    TCanvas *plots = new TCanvas(canvasName, hStat->GetTitle(), 600, 800);
    //-------------------

    //--- First Pad ---
    plots->cd();
    TPad *plot1 = new TPad("plot1", "plot1", 0., 0., 0., 0.);
    setAndDrawTPad(canvasName, plot1, 1, numbOfGenerator);

    //--- TLegend ---
    TLegend *legend = new TLegend(0.7, 0.74, 0.99, 0.98);
    customizeLegend(legend, numbOfGenerator);
    //------------------

    customizeCentral(grCentralSyst, legend, "Data");
    customizeCentral(grCentralStat, false);
    customizeCentral(grCentralSystRatio, true);
    customizeCentral(grCentralStatRatio, true);
    hSyst->SetLineColor(kWhite);
    hSyst->SetMarkerColor(kWhite);
    hSyst->SetTitle("");
    hSyst->GetXaxis()->SetLabelSize(0);
    hSyst->GetYaxis()->SetTitle("");
    hSyst->GetYaxis()->SetLabelSize(0.055);
    configXaxis(hSyst, hGen1, variable);
    configYaxis(hSyst, hGen1, hGen2, hGen3);
    if (canvasName.Contains("ZNGoodJets")) {
        hSyst->GetXaxis()->SetRangeUser(0, hSyst->GetXaxis()->GetXmax());
    }
    if (canvasName.Contains("JetPt_Zinc")) {
        hSyst->GetXaxis()->SetRangeUser(30, hSyst->GetXaxis()->GetXmax());
    }
    if (canvasName.Contains("Eta") || canvasName.Contains("AbsRapidity")) {
        hSyst->GetYaxis()->SetRangeUser(0.001, 1.4*maximum);
    }
    if (canvasName.Contains("DPhi") && (!canvasName.Contains("DPhiZFirstJet"))) {
        hSyst->GetYaxis()->SetRangeUser(0.1*minimum, 2.0*maximum);
    }
    hSyst->DrawCopy("e");
    grCentralSyst->SetName("grCentralSyst");
    grCentralSyst->Draw("2");
    customizeGenHist(hGen1, 1, legend, hGen1->GetZaxis()->GetTitle());
    hGen1->SetName("hGen1");
    hGen1->DrawCopy("ESAME");

    if (hGen2) {
        customizeGenHist(hGen2, 2, legend, hGen2->GetZaxis()->GetTitle());
        hGen2->SetName("hGen2");
        hGen2->DrawCopy("ESAME");
    }
    if (hGen3) {
        customizeGenHist(hGen3, 3, legend, hGen3->GetZaxis()->GetTitle());
        hGen3->SetName("hGen3");
        hGen3->DrawCopy("ESAME");
    }

    grCentralStat->SetName("grCentralStat");
    grCentralStat->Draw("p");

    legend->Draw("same");

    //--- TLatex stuff ---
    TLatex *latexLabel = new TLatex(); 
    latexLabel->SetNDC();
    latexLabel->SetTextSize(0.035);
    if (hGen2) latexLabel->SetTextSize(0.035);
    if (hGen3) latexLabel->SetTextSize(0.05);
    latexLabel->SetTextFont(42);
    latexLabel->SetLineWidth(2);

    latexLabel->SetTextFont(61);
    latexLabel->DrawLatex(0.18,0.83,"CMS");
    latexLabel->SetTextFont(52);
    //latexLabel->DrawLatex(0.25,0.83,"Preliminary");
    latexLabel->SetTextFont(42);
    latexLabel->DrawLatex(0.13,0.95-0.045,"19.6 fb^{-1} (8 TeV)");

    if(canvasName.Index("DPhi") > 0 && canvasName.Contains("ZFirstJet")){
        latexLabel->DrawLatex(0.66,0.21-0.04,"anti-k_{T} (R = 0.5) Jets");
    }

    else if(canvasName.Index("DPhi") > 0 && canvasName.Contains("ZSecondJet")){
        latexLabel->DrawLatex(0.18,0.7,"anti-k_{T} (R = 0.5) Jets");
    }

    else if(canvasName.Index("DPhi") > 0 && canvasName.Contains("ZThirdJet")){
        latexLabel->DrawLatex(0.18,0.7,"anti-k_{T} (R = 0.5) Jets");
    }

    else if(canvasName.Index("DPhi") > 0 && canvasName.Contains("FirstSecondJet") && (!canvasName.Contains("ZPt150")) && (!canvasName.Contains("ZPt300"))){
        latexLabel->DrawLatex(0.18,0.7,"anti-k_{T} (R = 0.5) Jets");
    }

    else if(canvasName.Index("DPhi") > 0 && canvasName.Contains("FirstThirdJet")){
        latexLabel->DrawLatex(0.18,0.7,"anti-k_{T} (R = 0.5) Jets");
    }

    else{
        latexLabel->DrawLatex(0.18,0.21-0.05,"anti-k_{T} (R = 0.5) Jets");
    }

    // ----------------------------------------------------------------------------------
    if (canvasName.Contains("FirstJetPt50") && canvasName.Index("Rapidity") > 0){
        latexLabel->DrawLatex(0.18,0.21-0.11,"p_{T}^{jet} > 50 GeV, |y^{jet}| < 2.4 ");
    }

    else if (canvasName.Contains("FirstJetPt80") && canvasName.Index("Rapidity") > 0){
        latexLabel->DrawLatex(0.18,0.21-0.11,"p_{T}^{jet} > 80 GeV, |y^{jet}| < 2.4 ");
    }

    else if (canvasName.Contains("ZPt150") && canvasName.Index("Rapidity") > 0){
        latexLabel->DrawLatex(0.18,0.21-0.11,"p_{T}^{Z} > 150 GeV, p_{T}^{jet} > 30 GeV, |y^{jet}| < 2.4 ");
    }

    else if (canvasName.Contains("ZPt300") && canvasName.Index("Rapidity") > 0){
        latexLabel->DrawLatex(0.18,0.21-0.11,"p_{T}^{Z} > 300 GeV, p_{T}^{jet} > 30 GeV, |y^{jet}| < 2.4 ");
    }

    else if (canvasName.Contains("DifJetRapidityl2") && canvasName.Index("Rapidity") > 0){
        latexLabel->DrawLatex(0.18,0.21-0.11,"p_{T}^{jet} > 30 GeV, |y^{jet}| < 2.4, |y_{jet1}-y_{jet2}| > 2 ");
    }

    else if (canvasName.Contains("DifJetRapiditys2") && canvasName.Index("Rapidity") > 0){
        latexLabel->DrawLatex(0.18,0.21-0.11,"p_{T}^{jet} > 30 GeV, |y^{jet}| < 2.4, |y_{jet1}-y_{jet2}| < 2 ");
    }

    else if (canvasName.Contains("ZPt150_HT300") && canvasName.Index("Rapidity") > 0){
        latexLabel->DrawLatex(0.18,0.21-0.11,"p_{T}^{Z} > 150 GeV, p_{T}^{jet} > 30 GeV, |y^{jet}| < 2.4, H_{T}^{jet} > 300 GeV ");
    }

    else if ((!canvasName.Contains("ZPt150")) && (!canvasName.Contains("ZPt300")) && (!canvasName.Contains("HT300")) && canvasName.Contains("DPhiZFirstJet")){
        latexLabel->DrawLatex(0.6,0.21-0.11,"p_{T}^{jet} > 30 GeV, |y^{jet}| < 2.4 ");
    }

    else if (canvasName.Contains("ZPt150") && (!canvasName.Contains("HT300")) && canvasName.Contains("DPhiZFirstJet")){
        latexLabel->DrawLatex(0.45,0.21-0.11,"p_{T}^{Z} > 150 GeV, p_{T}^{jet} > 30 GeV, |y^{jet}| < 2.4 ");
    }

    else if (canvasName.Contains("ZPt150_HT300") && canvasName.Contains("DPhiZFirstJet")){
        latexLabel->DrawLatex(0.23,0.21-0.11,"p_{T}^{Z} > 150 GeV, p_{T}^{jet} > 30 GeV, |y^{jet}| < 2.4, H_{T}^{jet} > 300 GeV ");
    }

    else if (canvasName.Contains("ZPt300") && canvasName.Contains("DPhiZFirstJet")){
        latexLabel->DrawLatex(0.45,0.21-0.11,"p_{T}^{Z} > 300 GeV, p_{T}^{jet} > 30 GeV, |y^{jet}| < 2.4 ");
    }

    else if (canvasName.Contains("ZPt150") && (!canvasName.Contains("HT300")) && canvasName.Contains("DPhiZSecondJet")){
        latexLabel->DrawLatex(0.18,0.63,"p_{T}^{Z} > 150 GeV, p_{T}^{jet} > 30 GeV, |y^{jet}| < 2.4 ");
    }

    else if ((!canvasName.Contains("ZPt150")) && (!canvasName.Contains("ZPt300")) && (!canvasName.Contains("HT300")) && canvasName.Contains("DPhiZSecondJet")){
        latexLabel->DrawLatex(0.18,0.63,"p_{T}^{jet} > 30 GeV, |y^{jet}| < 2.4 ");
    }

    else if (canvasName.Contains("ZPt150_HT300") && canvasName.Contains("DPhiZSecondJet")){
        latexLabel->DrawLatex(0.18,0.63,"p_{T}^{Z} > 150 GeV, p_{T}^{jet} > 30 GeV, |y^{jet}| < 2.4, H_{T}^{jet} > 300 GeV ");
    }

    else if (canvasName.Contains("ZPt300") && canvasName.Contains("DPhiZSecondJet")){
        latexLabel->DrawLatex(0.18,0.63,"p_{T}^{Z} > 300 GeV, p_{T}^{jet} > 30 GeV, |y^{jet}| < 2.4 ");
    }

    else if (canvasName.Contains("ZPt150") && (!canvasName.Contains("HT300")) && canvasName.Contains("DPhiZThirdJet")){
        latexLabel->DrawLatex(0.18,0.63,"p_{T}^{Z} > 150 GeV, p_{T}^{jet} > 30 GeV, |y^{jet}| < 2.4 ");
    }

    else if ((!canvasName.Contains("ZPt150")) && (!canvasName.Contains("ZPt300")) && (!canvasName.Contains("HT300")) && canvasName.Contains("DPhiZThirdJet")){
        latexLabel->DrawLatex(0.18,0.63,"p_{T}^{jet} > 30 GeV, |y^{jet}| < 2.4 ");
    }

    else if (canvasName.Contains("ZPt150_HT300") && canvasName.Contains("DPhiZThirdJet")){
        latexLabel->DrawLatex(0.18,0.63,"p_{T}^{Z} > 150 GeV, p_{T}^{jet} > 30 GeV, |y^{jet}| < 2.4, H_{T}^{jet} > 300 GeV ");
    }

    else if (canvasName.Contains("ZPt300") && canvasName.Contains("DPhiZThirdJet")){
        latexLabel->DrawLatex(0.18,0.63,"p_{T}^{Z} > 300 GeV, p_{T}^{jet} > 30 GeV, |y^{jet}| < 2.4 ");
    }

    else if (canvasName.Contains("DPhiFirstSecondJet") && (!canvasName.Contains("ZPt150")) && (!canvasName.Contains("ZPt300"))){
        latexLabel->DrawLatex(0.18,0.63,"p_{T}^{jet} > 30 GeV, |y^{jet}| < 2.4 ");
    }

    else if (canvasName.Contains("DPhiFirstSecondJet") && (canvasName.Contains("ZPt150"))){
        latexLabel->DrawLatex(0.18,0.21-0.11,"p_{T}^{Z} > 150 GeV, p_{T}^{jet} > 30 GeV, |y^{jet}| < 2.4 ");
    }

    else if (canvasName.Contains("DPhiFirstSecondJet") && (canvasName.Contains("ZPt300"))){
        latexLabel->DrawLatex(0.18,0.21-0.11,"p_{T}^{Z} > 300 GeV, p_{T}^{jet} > 30 GeV, |y^{jet}| < 2.4 ");
    }

    else if (canvasName.Contains("DPhiFirstThirdJet") && (!canvasName.Contains("ZPt150")) && (!canvasName.Contains("ZPt300"))){
        latexLabel->DrawLatex(0.18,0.63,"p_{T}^{jet} > 30 GeV, |y^{jet}| < 2.4 ");
    }

    else if (canvasName.Contains("DPhiFirstThirdJet") && (canvasName.Contains("ZPt150"))){
        latexLabel->DrawLatex(0.18,0.63,"p_{T}^{Z} > 150 GeV, p_{T}^{jet} > 30 GeV, |y^{jet}| < 2.4 ");
    }

    else if (canvasName.Contains("DPhiFirstThirdJet") && (canvasName.Contains("ZPt300"))){
        latexLabel->DrawLatex(0.18,0.63,"p_{T}^{Z} > 300 GeV, p_{T}^{jet} > 30 GeV, |y^{jet}| < 2.4 ");
    }

    else if (canvasName.Contains("DPhiSecondThirdJet") && (!canvasName.Contains("ZPt150")) && (!canvasName.Contains("ZPt300"))){
        latexLabel->DrawLatex(0.18,0.21-0.11,"p_{T}^{jet} > 30 GeV, |y^{jet}| < 2.4 ");
    }

    else if (canvasName.Contains("DPhiSecondThirdJet") && (canvasName.Contains("ZPt150"))){
        latexLabel->DrawLatex(0.18,0.21-0.11,"p_{T}^{Z} > 150 GeV, p_{T}^{jet} > 30 GeV, |y^{jet}| < 2.4 ");
    }

    else if (canvasName.Contains("DPhiSecondThirdJet") && (canvasName.Contains("ZPt300"))){
        latexLabel->DrawLatex(0.18,0.21-0.11,"p_{T}^{Z} > 300 GeV, p_{T}^{jet} > 30 GeV, |y^{jet}| < 2.4 ");
    }

    else{
        latexLabel->DrawLatex(0.18,0.21-0.11,"p_{T}^{jet} > 30 GeV, |y^{jet}| < 2.4 ");
    }

    // -------------------------------------------------------------------------------------------------
    if(canvasName.Index("DPhi") > 0 && canvasName.Contains("ZFirstJet")){
        if (lepSel == "") latexLabel->DrawLatex(0.66,0.21-0.18,"Z/#gamma*#rightarrow ll channel");
        else if (lepSel == "DMu") latexLabel->DrawLatex(0.66,0.21-0.18,"Z/#gamma*#rightarrow #mu#mu channel");
        else if (lepSel == "DE") latexLabel->DrawLatex(0.66,0.21-0.18,"Z/#gamma*#rightarrow ee channel");
    }

    else if(canvasName.Index("DPhi") > 0 && canvasName.Contains("ZSecondJet")){
        if (lepSel == "") latexLabel->DrawLatex(0.18,0.56,"Z/#gamma*#rightarrow ll channel");
        else if (lepSel == "DMu") latexLabel->DrawLatex(0.18,0.56,"Z/#gamma*#rightarrow #mu#mu channel");
        else if (lepSel == "DE") latexLabel->DrawLatex(0.18,0.56,"Z/#gamma*#rightarrow ee channel");
    }

    else if(canvasName.Index("DPhi") > 0 && canvasName.Contains("ZThirdJet")){
        if (lepSel == "") latexLabel->DrawLatex(0.18,0.56,"Z/#gamma*#rightarrow ll channel");
        else if (lepSel == "DMu") latexLabel->DrawLatex(0.18,0.56,"Z/#gamma*#rightarrow #mu#mu channel");
        else if (lepSel == "DE") latexLabel->DrawLatex(0.18,0.56,"Z/#gamma*#rightarrow ee channel");
    }

    else if(canvasName.Index("DPhi") > 0 && canvasName.Contains("FirstSecondJet") && (!canvasName.Contains("ZPt150")) && (!canvasName.Contains("ZPt300"))){
        if (lepSel == "") latexLabel->DrawLatex(0.18,0.56,"Z/#gamma*#rightarrow ll channel");
        else if (lepSel == "DMu") latexLabel->DrawLatex(0.18,0.56,"Z/#gamma*#rightarrow #mu#mu channel");
        else if (lepSel == "DE") latexLabel->DrawLatex(0.18,0.56,"Z/#gamma*#rightarrow ee channel");
    }

    else if(canvasName.Index("DPhi") > 0 && canvasName.Contains("FirstThirdJet")){
        if (lepSel == "") latexLabel->DrawLatex(0.18,0.56,"Z/#gamma*#rightarrow ll channel");
        else if (lepSel == "DMu") latexLabel->DrawLatex(0.18,0.56,"Z/#gamma*#rightarrow #mu#mu channel");
        else if (lepSel == "DE") latexLabel->DrawLatex(0.18,0.56,"Z/#gamma*#rightarrow ee channel");
    }

    else{
        if (lepSel == "") latexLabel->DrawLatex(0.18,0.21-0.17,"Z/#gamma*#rightarrow ll channel");
        else if (lepSel == "DMu") latexLabel->DrawLatex(0.18,0.21-0.17,"Z/#gamma*#rightarrow #mu#mu channel");
        else if (lepSel == "DE") latexLabel->DrawLatex(0.18,0.21-0.17,"Z/#gamma*#rightarrow ee channel");
    }

    latexLabel->SetName("latexLabel");
    latexLabel->Draw("same");


    TLatex *ytitle = new TLatex();
    ytitle->SetName("ytitle");
    ytitle->SetTextSize(0.04);
    if (hGen2) ytitle->SetTextSize(0.05);
    if (hGen3) ytitle->SetTextSize(0.06);
    ytitle->SetTextFont(42);
    ytitle->SetLineWidth(2);
    ytitle->SetTextColor(kBlack);
    ytitle->SetNDC();
    ytitle->SetTextAlign(33);
    ytitle->SetTextAngle(90);
    std::string strYtitle = getYaxisTitle(doNormalized, hGen1);
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
    setAndDrawTPad(canvasName, plot2, 2, numbOfGenerator);


    //--- TLegend ---
    TLegend *legend2 = new TLegend(0.16, 0.05, 0.42, 0.20);
    customizeLegend(legend2, 1, numbOfGenerator);
    TString generator1 = hGen1->GetZaxis()->GetTitle();
    generator1 = generator1(0, generator1.Index(" "));
    customizeGenGraph(hSyst, grGen1ToCentral, grGen1PDFSyst, 1, generator1 + "/Data", numbOfGenerator, legend2);
    configXaxis(hSyst, hGen1, variable);
    hSyst->DrawCopy("e");
    grGen1ToCentral->SetName("grGen1ToCentral");
    grGen1ToCentral->Draw("2");
    //grGen1PDFSyst->Draw("2");
    grCentralSystRatio->SetName("grCentralSystRatio");
    grCentralSystRatio->Draw("2");
    grCentralStatRatio->Draw("p");
    grGen1ToCentral->Draw("Xp");
    legend2->Draw("same");
    //if (canvasName.Contains("JetPt_Zinc")) {
    //    grGen1ToCentral->GetXaxis()->SetRangeUser(30, x + ex);
    //}
    plot2->RedrawAxis();
    //--- End of Second Pad ---

    if (hGen2) {
        //--- Third Pad ---
        plots->cd();
        TPad *plot3 = new TPad("plot3", "plot3", 0., 0., 0., 0.);
        setAndDrawTPad(canvasName, plot3, 3, numbOfGenerator);

        //--- TLegend ---
        TLegend *legend3 = new TLegend(0.16, 0.05, 0.42, 0.20);
        customizeLegend(legend3, 2, numbOfGenerator);
        TString generator2 = hGen2->GetZaxis()->GetTitle();
        generator2 = generator2(0, generator2.Index(" "));
        customizeGenGraph(hSyst, grGen2ToCentral, grGen2PDFSyst, 2, generator2 + "/Data", numbOfGenerator, legend3);
        configXaxis(hSyst, hGen2, variable);
        hSyst->DrawCopy("e");
        grGen2ToCentral->SetName("grGen2ToCentral");
        grGen2ToCentral->Draw("2");
        //grGen2PDFSyst->Draw("2");
        grCentralSystRatio->SetName("grCentralSystRatio");
        grCentralSystRatio->Draw("2");
        grCentralStatRatio->Draw("p");
        grGen2ToCentral->Draw("Xp");
        legend3->Draw("same");
        //if (canvasName.Contains("JetPt_Zinc")) {
        //    grGen2ToCentral->GetXaxis()->SetRangeUser(30, x + ex);
        //}
        plot3->RedrawAxis();
        //--- End of Third Pad ---
    }

    if (hGen3) {
        //--- Fourth Pad ---
        plots->cd();
        TPad *plot4 = new TPad("plot4", "plot4", 0., 0., 0., 0.);
        setAndDrawTPad(canvasName, plot4, 4, numbOfGenerator);

        //--- TLegend ---
        TLegend *legend4 = new TLegend(0.16, 0.05, 0.42, 0.20);
        customizeLegend(legend4, 3, numbOfGenerator);
        TString generator3 = hGen3->GetZaxis()->GetTitle();
        generator3 = generator3(0, generator3.Index(" "));
        customizeGenGraph(hSyst, grGen3ToCentral, grGen3ScaleSyst, grGen3PDFSyst, 3, generator3 + "/Data", numbOfGenerator, legend4);
        configXaxis(hSyst, hGen3, variable);
        hSyst->DrawCopy("e");
        grGen3ToCentral->SetName("grGen3ToCentral");
        grGen3ToCentral->Draw("2");
        grGen3ScaleSyst->Draw("2");
        grGen3ToCentral->Draw("2");
        grCentralSystRatio->SetName("grCentralSystRatio");
        grCentralSystRatio->Draw("2");
        grCentralStatRatio->Draw("p");
        grGen3ToCentral->Draw("Xp");
        grGen3PDFSyst->Draw("2");
        legend4->Draw("same");
        //if (canvasName.Contains("JetPt_Zinc")) {
        //    grGen3ToCentral->GetXaxis()->SetRangeUser(30, x + ex);
        //}
        plot4->RedrawAxis();
        //--- End of Fourth Pad ---
    }
    plots->Update();
    return plots;
}

void createTitleVariableAnddSigma(TString variable, bool doNormalized, TString xtitle, TString& title, TString& var, TString& dSigma) 
{

    // jet multiplicity
    if (variable.Index("ZNGoodJets_Zexc") >= 0) {
        title = "Exclusive jet multiplicity";
        var = "$N_{\\text{jets}}$";
        dSigma = "$\\frac{d\\sigma}{dN_{\\text{jets}}} \\tiny{\\left[\\text{pb}\\right]}$";
    }
    if (variable.Index("ZNGoodJets_Zinc") >= 0) {
        title = "Inclusive jet multiplicity";
        var = "$N_{\\text{jets}}$";
        dSigma = "$\\frac{d\\sigma}{dN_{\\text{jets}}} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (xtitle.Index("p_{T}(Z)") >= 0) {
        title = "$p_{T}^{Z}$";
        var = "$p_{\\text{T}}(Z)$ \\tiny{[GeV]}";
        dSigma = "$\\frac{d\\sigma}{dp_{\\text{T}}(Z)} \\tiny{\\left[\\frac{\\text{pb}}{\\text{GeV}}\\right]}$";
    }

    // Z Boson and Jet rapidity
    if (variable.Index("AbsZRapidity_Zexc1jet") >= 0) {
        title = "$|y_\\text{Z}|$ ($N_{\\text{jets}} = 1$)";
        var = "$|y_{\\text{Z}}|$";
        dSigma = "$\\frac{d\\sigma}{d|y_{\\text{Z}}|} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("AbsZRapidity_Zinc1jet") >= 0) {
        title = "$|y_\\text{Z}|$ ($N_{\\text{jets}} \\geq 1$)";
        var = "$|y_{\\text{Z}}|$";
        dSigma = "$\\frac{d\\sigma}{d|y_{\\text{Z}}|} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("AbsJetRapidity_Zexc1jet") >= 0) {
        title = "$|y_\\text{jet}|$ ($N_{\\text{jets}} = 1$)";
        var = "$|y_{\\text{jet}}|$";
        dSigma = "$\\frac{d\\sigma}{d|y_{\\text{jet}}|} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("AbsFirstJetRapidity_Zinc1jet") >= 0) {
        title = "$|y_\\text{jet1}|$ ($N_{\\text{jets}} \\geq 1$)";
        var = "$|y_{\\text{jet1}}|$";
        dSigma = "$\\frac{d\\sigma}{d|y_{\\text{jet1}}|} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("SumZJetRapidity_Zexc1jet") >= 0) {
        title = "$y_\\text{sum}$ ($N_{\\text{jets}} = 1$)";
        var = "$y_{\\text{sum}}$";
        dSigma = "$\\frac{d\\sigma}{dy_{\\text{sum}}} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("SumZFirstJetRapidity_Zinc1jet") >= 0) {
        title = "$y_\\text{sum(Z,jet1)}$ ($N_{\\text{jets}} \\geq 1$)";
        var = "$y_{\\text{sum(Z,jet1)}}$";
        dSigma = "$\\frac{d\\sigma}{dy_{\\text{sum(Z,jet1)}}} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("DifZJetRapidity_Zexc1jet") >= 0) {
        title = "$y_\\text{diff}$ ($N_{\\text{jets}} = 1$)";
        var = "$y_{\\text{diff}}$";
        dSigma = "$\\frac{d\\sigma}{dy_{\\text{diff}}} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("DifZFirstJetRapidity_Zinc1jet") >= 0) {
        title = "$y_\\text{diff(Z,jet1)}$ ($N_{\\text{jets}} \\geq 1$)";
        var = "$y_{\\text{diff(Z,jet1)}}$";
        dSigma = "$\\frac{d\\sigma}{dy_{\\text{diff(Z,jet1)}}} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("AbsZRapidity_Zinc2jet") >= 0) {
        title = "$|y_\\text{Z}|$ ($N_{\\text{jets}} \\geq 2$)";
        var = "$|y_{\\text{Z}}|$";
        dSigma = "$\\frac{d\\sigma}{d|y_{\\text{Z}}|} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("AbsFirstJetRapidity_Zinc2jet") >= 0) {
        title = "$|y_\\text{jet1}|$ ($N_{\\text{jets}} \\geq 2$)";
        var = "$|y_{\\text{jet1}}|$";
        dSigma = "$\\frac{d\\sigma}{d|y_{\\text{jet1}}|} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("AbsSecondJetRapidity_Zinc2jet") >= 0) {
        title = "$|y_\\text{jet2}|$ ($N_{\\text{jets}} \\geq 2$)";
        var = "$|y_{\\text{jet2}}|$";
        dSigma = "$\\frac{d\\sigma}{d|y_{\\text{jet2}}|} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("SumZFirstJetRapidity_Zinc2jet") >= 0) {
        title = "$y_\\text{sum(Z,jet1)}$ ($N_{\\text{jets}} \\geq 2$)";
        var = "$y_{\\text{sum(Z,jet1)}}$";
        dSigma = "$\\frac{d\\sigma}{dy_{\\text{sum(Z,jet1)}}} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("SumZSecondJetRapidity_Zinc2jet") >= 0) {
        title = "$y_\\text{sum(Z,jet2)}$ ($N_{\\text{jets}} \\geq 2$)";
        var = "$y_{\\text{sum(Z,jet2)}}$";
        dSigma = "$\\frac{d\\sigma}{dy_{\\text{sum(Z,jet2)}}} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("SumFirstSecondJetRapidity_Zinc2jet") >= 0) {
        title = "$y_\\text{sum(jet1,jet2)}$ ($N_{\\text{jets}} \\geq 2$)";
        var = "$y_{\\text{sum(jet1,jet2)}}$";
        dSigma = "$\\frac{d\\sigma}{dy_{\\text{sum(jet1,jet2)}}} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("DifZFirstJetRapidity_Zinc2jet") >= 0) {
        title = "$y_\\text{diff(Z,jet1)}$ ($N_{\\text{jets}} \\geq 2$)";
        var = "$y_{\\text{diff(Z,jet1)}}$";
        dSigma = "$\\frac{d\\sigma}{dy_{\\text{diff(Z,jet1)}}} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("DifZSecondJetRapidity_Zinc2jet") >= 0) {
        title = "$y_\\text{diff(Z,jet2)}$ ($N_{\\text{jets}} \\geq 2$)";
        var = "$y_{\\text{diff(Z,jet2)}}$";
        dSigma = "$\\frac{d\\sigma}{dy_{\\text{diff(Z,jet2)}}} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("DifFirstSecondJetRapidity_Zinc2jet") >= 0) {
        title = "$y_\\text{diff(jet1,jet2)}$ ($N_{\\text{jets}} \\geq 2$)";
        var = "$y_{\\text{diff(jet1,jet2)}}$";
        dSigma = "$\\frac{d\\sigma}{dy_{\\text{diff(jet1,jet2)}}} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("SumZTwoJetsRapidity_Zinc2jet") >= 0) {
        title = "$y_\\text{sum(Z,jet1+jet2)}$ ($N_{\\text{jets}} \\geq 2$)";
        var = "$y_{\\text{sum(Z,jet1+jet2)}}$";
        dSigma = "$\\frac{d\\sigma}{dy_{\\text{sum(Z,jet1+jet2)}}} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("DifZTwoJetsRapidity_Zinc2jet") >= 0) {
        title = "$y_\\text{diff(Z,jet1+jet2)}$ ($N_{\\text{jets}} \\geq 2$)";
        var = "$y_{\\text{diff(Z,jet1+jet2)}}$";
        dSigma = "$\\frac{d\\sigma}{dy_{\\text{diff(Z,jet1+jet2)}}} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("AbsZRapidity_ZPt150_Zinc1jet") >= 0) {
        title = "$|y_\\text{Z}|$ ($N_{\\text{jets}} \\geq 1, p_{\\text{T}}^{\\text{Z}} \\geq 150 \\text{GeV}$)";
        var = "$|y_{\\text{Z}}|$";
        dSigma = "$\\frac{d\\sigma}{d|y_{\\text{Z}}|} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("AbsZRapidity_ZPt300_Zinc1jet") >= 0) {
        title = "$|y_\\text{Z}|$ ($N_{\\text{jets}} \\geq 1, p_{\\text{T}}^{\\text{Z}} \\geq 300 \\text{GeV}$)";
        var = "$|y_{\\text{Z}}|$";
        dSigma = "$\\frac{d\\sigma}{d|y_{\\text{Z}}|} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("AbsFirstJetRapidity_ZPt150_Zinc1jet") >= 0) {
        title = "$|y_\\text{jet1}|$ ($N_{\\text{jets}} \\geq 1, p_{\\text{T}}^{\\text{Z}} \\geq 150 \\text{GeV}$)";
        var = "$|y_{\\text{jet1}}|$";
        dSigma = "$\\frac{d\\sigma}{d|y_{\\text{jet1}}|} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("AbsFirstJetRapidity_ZPt300_Zinc1jet") >= 0) {
        title = "$|y_\\text{jet1}|$ ($N_{\\text{jets}} \\geq 1, p_{\\text{T}}^{\\text{Z}} \\geq 300 \\text{GeV}$)";
        var = "$|y_{\\text{jet1}}|$";
        dSigma = "$\\frac{d\\sigma}{d|y_{\\text{jet1}}|} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("SumZFirstJetRapidity_ZPt150_Zinc1jet") >= 0) {
        title = "$y_\\text{sum(Z,jet1)}$ ($N_{\\text{jets}} \\geq 1, p_{\\text{T}}^{\\text{Z}} \\geq 150 \\text{GeV}$)";
        var = "$y_{\\text{sum(Z,jet1)}}$";
        dSigma = "$\\frac{d\\sigma}{dy_{\\text{sum(Z,jet1)}}} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("SumZFirstJetRapidity_ZPt300_Zinc1jet") >= 0) {
        title = "$y_\\text{sum(Z,jet1)}$ ($N_{\\text{jets}} \\geq 1, p_{\\text{T}}^{\\text{Z}} \\geq 300 \\text{GeV}$)";
        var = "$y_{\\text{sum(Z,jet1)}}$";
        dSigma = "$\\frac{d\\sigma}{dy_{\\text{sum(Z,jet1)}}} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("DifZFirstJetRapidity_ZPt150_Zinc1jet") >= 0) {
        title = "$y_\\text{diff(Z,jet1)}$ ($N_{\\text{jets}} \\geq 1, p_{\\text{T}}^{\\text{Z}} \\geq 150 \\text{GeV}$)";
        var = "$y_{\\text{diff(Z,jet1)}}$";
        dSigma = "$\\frac{d\\sigma}{dy_{\\text{diff(Z,jet1)}}} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("DifZFirstJetRapidity_ZPt300_Zinc1jet") >= 0) {
        title = "$y_\\text{diff(Z,jet1)}$ ($N_{\\text{jets}} \\geq 1, p_{\\text{T}}^{\\text{Z}} \\geq 300 \\text{GeV}$)";
        var = "$y_{\\text{diff(Z,jet1)}}$";
        dSigma = "$\\frac{d\\sigma}{dy_{\\text{diff(Z,jet1)}}} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("SumZFirstJetRapidity_FirstJetPt50_Zinc1jet") >= 0) {
        title = "$y_\\text{sum(Z,jet1)}$ ($N_{\\text{jets}} \\geq 1, p_{\\text{T}}^{\\text{jet1}} \\geq 50 \\text{GeV}$)";
        var = "$y_{\\text{sum(Z,jet1)}}$";
        dSigma = "$\\frac{d\\sigma}{dy_{\\text{sum(Z,jet1)}}} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("SumZFirstJetRapidity_FirstJetPt80_Zinc1jet") >= 0) {
        title = "$y_\\text{sum(Z,jet1)}$ ($N_{\\text{jets}} \\geq 1, p_{\\text{T}}^{\\text{jet1}} \\geq 80 \\text{GeV}$)";
        var = "$y_{\\text{sum(Z,jet1)}}$";
        dSigma = "$\\frac{d\\sigma}{dy_{\\text{sum(Z,jet1)}}} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("DifZFirstJetRapidity_FirstJetPt50_Zinc1jet") >= 0) {
        title = "$y_\\text{diff(Z,jet1)}$ ($N_{\\text{jets}} \\geq 1, p_{\\text{T}}^{\\text{jet1}} \\geq 50 \\text{GeV}$)";
        var = "$y_{\\text{diff(Z,jet1)}}$";
        dSigma = "$\\frac{d\\sigma}{dy_{\\text{diff(Z,jet1)}}} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("DifZFirstJetRapidity_FirstJetPt80_Zinc1jet") >= 0) {
        title = "$y_\\text{diff(Z,jet1)}$ ($N_{\\text{jets}} \\geq 1, p_{\\text{T}}^{\\text{jet1}} \\geq 80 \\text{GeV}$)";
        var = "$y_{\\text{diff(Z,jet1)}}$";
        dSigma = "$\\frac{d\\sigma}{dy_{\\text{diff(Z,jet1)}}} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("AbsZRapidity_DifJetRapiditys2_Zinc2jet") >= 0) {
        title = "$|y_\\text{Z}|$ ($N_{\\text{jets}} \\geq 2, |y_{jet1} - y_{jet2}| \\leq 2 $)";
        var = "$|y_{\\text{Z}}|$";
        dSigma = "$\\frac{d\\sigma}{d|y_{\\text{Z}}|} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("AbsZRapidity_DifJetRapidityl2_Zinc2jet") >= 0) {
        title = "$|y_\\text{Z}|$ ($N_{\\text{jets}} \\geq 2, |y_{jet1} - y_{jet2}| \\geq 2 $)";
        var = "$|y_{\\text{Z}}|$";
        dSigma = "$\\frac{d\\sigma}{d|y_{\\text{Z}}|} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("AbsFirstJetRapidity_DifJetRapiditys2_Zinc2jet") >= 0) {
        title = "$|y_\\text{jet1}|$ ($N_{\\text{jets}} \\geq 2, |y_{jet1} - y_{jet2}| \\leq 2 $)";
        var = "$|y_{\\text{jet1}}|$";
        dSigma = "$\\frac{d\\sigma}{d|y_{\\text{jet1}}|} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("AbsFirstJetRapidity_DifJetRapidityl2_Zinc2jet") >= 0) {
        title = "$|y_\\text{jet1}|$ ($N_{\\text{jets}} \\geq 2, |y_{jet1} - y_{jet2}| \\geq 2 $)";
        var = "$|y_{\\text{jet1}}|$";
        dSigma = "$\\frac{d\\sigma}{d|y_{\\text{jet1}}|} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("SumZFirstJetRapidity_DifJetRapiditys2_Zinc2jet") >= 0) {
        title = "$y_\\text{sum(Z,jet1)}$ ($N_{\\text{jets}} \\geq 2, |y_{jet1} - y_{jet2}| \\leq 2 $)";
        var = "$y_{\\text{sum(Z,jet1)}}$";
        dSigma = "$\\frac{d\\sigma}{dy_{\\text{sum(Z,jet1)}}} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("SumZFirstJetRapidity_DifJetRapidityl2_Zinc2jet") >= 0) {
        title = "$y_\\text{sum(Z,jet1)}$ ($N_{\\text{jets}} \\geq 2, |y_{jet1} - y_{jet2}| \\geq 2 $)";
        var = "$y_{\\text{sum(Z,jet1)}}$";
        dSigma = "$\\frac{d\\sigma}{dy_{\\text{sum(Z,jet1)}}} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("DifZFirstJetRapidity_DifJetRapiditys2_Zinc2jet") >= 0) {
        title = "$y_\\text{diff(Z,jet1)}$ ($N_{\\text{jets}} \\geq 2, |y_{jet1} - y_{jet2}| \\leq 2 $)";
        var = "$y_{\\text{diff(Z,jet1)}}$";
        dSigma = "$\\frac{d\\sigma}{dy_{\\text{diff(Z,jet1)}}} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("DifZFirstJetRapidity_DifJetRapidityl2_Zinc2jet") >= 0) {
        title = "$y_\\text{diff(Z,jet1)}$ ($N_{\\text{jets}} \\geq 2, |y_{jet1} - y_{jet2}| \\geq 2 $)";
        var = "$y_{\\text{diff(Z,jet1)}}$";
        dSigma = "$\\frac{d\\sigma}{dy_{\\text{diff(Z,jet1)}}} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("SumZFirstJetEta_Zinc1jet") >= 0) {
        title = "$\\eta_\\text{sum(Z,jet1)}$ ($N_{\\text{jets}} \\geq 1 $)";
        var = "$\\eta_{\\text{sum(Z,jet1)}}$";
        dSigma = "$\\frac{d\\sigma}{d\\eta_{\\text{sum(Z,jet1)}}} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("DifZFirstJetEta_Zinc1jet") >= 0) {
        title = "$\\eta_\\text{diff(Z,jet1)}$ ($N_{\\text{jets}} \\geq 1 $)";
        var = "$\\eta_{\\text{diff(Z,jet1)}}$";
        dSigma = "$\\frac{d\\sigma}{d\\eta_{\\text{diff(Z,jet1)}}} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("DPhiZFirstJet_Zinc1jet") >= 0) {
        title = "$\\Delta\\phi_\\text{Z,jet1}$ ($N_{\\text{jets}} \\geq 1 $)";
        var = "$\\Delta\\phi_{\\text{Z,jet1}}$";
        dSigma = "$\\frac{d\\sigma}{d\\Delta\\phi_{\\text{Z,jet1}}} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("DPhiZFirstJet_Zinc2jet") >= 0) {
        title = "$\\Delta\\phi_\\text{Z,jet1}$ ($N_{\\text{jets}} \\geq 2 $)";
        var = "$\\Delta\\phi_{\\text{Z,jet1}}$";
        dSigma = "$\\frac{d\\sigma}{d\\Delta\\phi_{\\text{Z,jet1}}} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("DPhiZFirstJet_Zinc3jet") >= 0) {
        title = "$\\Delta\\phi_\\text{Z,jet1}$ ($N_{\\text{jets}} \\geq 3 $)";
        var = "$\\Delta\\phi_{\\text{Z,jet1}}$";
        dSigma = "$\\frac{d\\sigma}{d\\Delta\\phi_{\\text{Z,jet1}}} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("DPhiZFirstJet_ZPt150_Zinc1jet") >= 0) {
        title = "$\\Delta\\phi_\\text{Z,jet1}$ ($N_{\\text{jets}} \\geq 1, p_{\\text{T}}^{\\text{Z}} \\geq 150 \\text{GeV}$)";
        var = "$\\Delta\\phi_{\\text{Z,jet1}}$";
        dSigma = "$\\frac{d\\sigma}{d\\Delta\\phi_{\\text{Z,jet1}}} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("DPhiZFirstJet_ZPt150_Zinc2jet") >= 0) {
        title = "$\\Delta\\phi_\\text{Z,jet1}$ ($N_{\\text{jets}} \\geq 2, p_{\\text{T}}^{\\text{Z}} \\geq 150 \\text{GeV}$)";
        var = "$\\Delta\\phi_{\\text{Z,jet1}}$";
        dSigma = "$\\frac{d\\sigma}{d\\Delta\\phi_{\\text{Z,jet1}}} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("DPhiZFirstJet_ZPt150_Zinc3jet") >= 0) {
        title = "$\\Delta\\phi_\\text{Z,jet1}$ ($N_{\\text{jets}} \\geq 3, p_{\\text{T}}^{\\text{Z}} \\geq 150 \\text{GeV}$)";
        var = "$\\Delta\\phi_{\\text{Z,jet1}}$";
        dSigma = "$\\frac{d\\sigma}{d\\Delta\\phi_{\\text{Z,jet1}}} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("DPhiZFirstJet_ZPt300_Zinc1jet") >= 0) {
        title = "$\\Delta\\phi_\\text{Z,jet1}$ ($N_{\\text{jets}} \\geq 1, p_{\\text{T}}^{\\text{Z}} \\geq 300 \\text{GeV}$)";
        var = "$\\Delta\\phi_{\\text{Z,jet1}}$";
        dSigma = "$\\frac{d\\sigma}{d\\Delta\\phi_{\\text{Z,jet1}}} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("DPhiZFirstJet_ZPt300_Zinc2jet") >= 0) {
        title = "$\\Delta\\phi_\\text{Z,jet1}$ ($N_{\\text{jets}} \\geq 2, p_{\\text{T}}^{\\text{Z}} \\geq 300 \\text{GeV}$)";
        var = "$\\Delta\\phi_{\\text{Z,jet1}}$";
        dSigma = "$\\frac{d\\sigma}{d\\Delta\\phi_{\\text{Z,jet1}}} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("DPhiZFirstJet_ZPt300_Zinc3jet") >= 0) {
        title = "$\\Delta\\phi_\\text{Z,jet1}$ ($N_{\\text{jets}} \\geq 3, p_{\\text{T}}^{\\text{Z}} \\geq 300 \\text{GeV}$)";
        var = "$\\Delta\\phi_{\\text{Z,jet1}}$";
        dSigma = "$\\frac{d\\sigma}{d\\Delta\\phi_{\\text{Z,jet1}}} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("DPhiZSecondJet_Zinc3jet") >= 0) {
        title = "$\\Delta\\phi_\\text{Z,jet2}$ ($N_{\\text{jets}} \\geq 3 $)";
        var = "$\\Delta\\phi_{\\text{Z,jet2}}$";
        dSigma = "$\\frac{d\\sigma}{d\\Delta\\phi_{\\text{Z,jet2}}} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("DPhiZThirdJet_Zinc3jet") >= 0) {
        title = "$\\Delta\\phi_\\text{Z,jet3}$ ($N_{\\text{jets}} \\geq 3 $)";
        var = "$\\Delta\\phi_{\\text{Z,jet3}}$";
        dSigma = "$\\frac{d\\sigma}{d\\Delta\\phi_{\\text{Z,jet3}}} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("DPhiZSecondJet_ZPt150_Zinc3jet") >= 0) {
        title = "$\\Delta\\phi_\\text{Z,jet2}$ ($N_{\\text{jets}} \\geq 3, p_{\\text{T}}^{\\text{Z}} \\geq 150 \\text{GeV}$)";
        var = "$\\Delta\\phi_{\\text{Z,jet2}}$";
        dSigma = "$\\frac{d\\sigma}{d\\Delta\\phi_{\\text{Z,jet2}}} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("DPhiZThirdJet_ZPt150_Zinc3jet") >= 0) {
        title = "$\\Delta\\phi_\\text{Z,jet3}$ ($N_{\\text{jets}} \\geq 3, p_{\\text{T}}^{\\text{Z}} \\geq 150 \\text{GeV}$)";
        var = "$\\Delta\\phi_{\\text{Z,jet3}}$";
        dSigma = "$\\frac{d\\sigma}{d\\Delta\\phi_{\\text{Z,jet3}}} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("DPhiZSecondJet_ZPt300_Zinc3jet") >= 0) {
        title = "$\\Delta\\phi_\\text{Z,jet2}$ ($N_{\\text{jets}} \\geq 3, p_{\\text{T}}^{\\text{Z}} \\geq 300 \\text{GeV}$)";
        var = "$\\Delta\\phi_{\\text{Z,jet2}}$";
        dSigma = "$\\frac{d\\sigma}{d\\Delta\\phi_{\\text{Z,jet2}}} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("DPhiZThirdJet_ZPt300_Zinc3jet") >= 0) {
        title = "$\\Delta\\phi_\\text{Z,jet3}$ ($N_{\\text{jets}} \\geq 3, p_{\\text{T}}^{\\text{Z}} \\geq 300 \\text{GeV}$)";
        var = "$\\Delta\\phi_{\\text{Z,jet3}}$";
        dSigma = "$\\frac{d\\sigma}{d\\Delta\\phi_{\\text{Z,jet3}}} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("DPhiFirstSecondJet_Zinc3jet") >= 0) {
        title = "$\\Delta\\phi_\\text{jet1,jet2}$ ($N_{\\text{jets}} \\geq 3 $)";
        var = "$\\Delta\\phi_{\\text{jet1,jet2}}$";
        dSigma = "$\\frac{d\\sigma}{d\\Delta\\phi_{\\text{jet1,jet2}}} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("DPhiFirstThirdJet_Zinc3jet") >= 0) {
        title = "$\\Delta\\phi_\\text{jet1,jet3}$ ($N_{\\text{jets}} \\geq 3 $)";
        var = "$\\Delta\\phi_{\\text{jet1,jet3}}$";
        dSigma = "$\\frac{d\\sigma}{d\\Delta\\phi_{\\text{jet1,jet3}}} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("DPhiSecondThirdJet_Zinc3jet") >= 0) {
        title = "$\\Delta\\phi_\\text{jet2,jet3}$ ($N_{\\text{jets}} \\geq 3 $)";
        var = "$\\Delta\\phi_{\\text{jet2,jet3}}$";
        dSigma = "$\\frac{d\\sigma}{d\\Delta\\phi_{\\text{jet2,jet3}}} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("DPhiFirstSecondJet_ZPt150_Zinc3jet") >= 0) {
        title = "$\\Delta\\phi_\\text{jet1,jet2}$ ($N_{\\text{jets}} \\geq 3, p_{\\text{T}}^{\\text{Z}} \\geq 150 \\text{GeV}$)";
        var = "$\\Delta\\phi_{\\text{jet1,jet2}}$";
        dSigma = "$\\frac{d\\sigma}{d\\Delta\\phi_{\\text{jet1,jet2}}} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("DPhiFirstThirdJet_ZPt150_Zinc3jet") >= 0) {
        title = "$\\Delta\\phi_\\text{jet1,jet3}$ ($N_{\\text{jets}} \\geq 3, p_{\\text{T}}^{\\text{Z}} \\geq 150 \\text{GeV}$)";
        var = "$\\Delta\\phi_{\\text{jet1,jet3}}$";
        dSigma = "$\\frac{d\\sigma}{d\\Delta\\phi_{\\text{jet1,jet3}}} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("DPhiSecondThirdJet_ZPt150_Zinc3jet") >= 0) {
        title = "$\\Delta\\phi_\\text{jet2,jet3}$ ($N_{\\text{jets}} \\geq 3, p_{\\text{T}}^{\\text{Z}} \\geq 150 \\text{GeV}$)";
        var = "$\\Delta\\phi_{\\text{jet2,jet3}}$";
        dSigma = "$\\frac{d\\sigma}{d\\Delta\\phi_{\\text{jet2,jet3}}} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("DPhiFirstSecondJet_ZPt300_Zinc3jet") >= 0) {
        title = "$\\Delta\\phi_\\text{jet1,jet2}$ ($N_{\\text{jets}} \\geq 3, p_{\\text{T}}^{\\text{Z}} \\geq 300 \\text{GeV}$)";
        var = "$\\Delta\\phi_{\\text{jet1,jet2}}$";
        dSigma = "$\\frac{d\\sigma}{d\\Delta\\phi_{\\text{jet1,jet2}}} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("DPhiFirstThirdJet_ZPt300_Zinc3jet") >= 0) {
        title = "$\\Delta\\phi_\\text{jet1,jet3}$ ($N_{\\text{jets}} \\geq 3, p_{\\text{T}}^{\\text{Z}} \\geq 300 \\text{GeV}$)";
        var = "$\\Delta\\phi_{\\text{jet1,jet3}}$";
        dSigma = "$\\frac{d\\sigma}{d\\Delta\\phi_{\\text{jet1,jet3}}} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("DPhiSecondThirdJet_ZPt300_Zinc3jet") >= 0) {
        title = "$\\Delta\\phi_\\text{jet2,jet3}$ ($N_{\\text{jets}} \\geq 3, p_{\\text{T}}^{\\text{Z}} \\geq 300 \\text{GeV}$)";
        var = "$\\Delta\\phi_{\\text{jet2,jet3}}$";
        dSigma = "$\\frac{d\\sigma}{d\\Delta\\phi_{\\text{jet2,jet3}}} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("DPhiZFirstJet_ZPt150_HT300_Zinc3jet") >= 0) {
        title = "$\\Delta\\phi_\\text{Z,jet1}$ ($N_{\\text{jets}} \\geq 3, p_{\\text{T}}^{\\text{Z}} \\geq 150 \\text{GeV}, H_{\\text{T}} \\geq 300 \\text{GeV}$)";
        var = "$\\Delta\\phi_{\\text{Z,jet1}}$";
        dSigma = "$\\frac{d\\sigma}{d\\Delta\\phi_{\\text{Z,jet1}}} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("DPhiZSecondJet_ZPt150_HT300_Zinc3jet") >= 0) {
        title = "$\\Delta\\phi_\\text{Z,jet2}$ ($N_{\\text{jets}} \\geq 3, p_{\\text{T}}^{\\text{Z}} \\geq 150 \\text{GeV}, H_{\\text{T}} \\geq 300 \\text{GeV}$)";
        var = "$\\Delta\\phi_{\\text{Z,jet2}}$";
        dSigma = "$\\frac{d\\sigma}{d\\Delta\\phi_{\\text{Z,jet2}}} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("DPhiZThirdJet_ZPt150_HT300_Zinc3jet") >= 0) {
        title = "$\\Delta\\phi_\\text{Z,jet3}$ ($N_{\\text{jets}} \\geq 3, p_{\\text{T}}^{\\text{Z}} \\geq 150 \\text{GeV}, H_{\\text{T}} \\geq 300 \\text{GeV}$)";
        var = "$\\Delta\\phi_{\\text{Z,jet3}}$";
        dSigma = "$\\frac{d\\sigma}{d\\Delta\\phi_{\\text{Z,jet3}}} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    //jet rapidity distributions
    if (variable.Index("FirstJetAbsRapidity_Zinc1jet") >= 0) {
        title = "$|y_\\text{jet1}|$ ($N_{\\text{jets}} \\geq 1$)";
        var = "$|y_{\\text{jet1}}|$";
        dSigma = "$\\frac{d\\sigma}{d|y_{\\text{jet1}}|} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("SecondJetAbsRapidity_Zinc2jet") >= 0) {
        title = "$|y_\\text{jet2}|$ ($N_{\\text{jets}} \\geq 2$)";
        var = "$|y_{\\text{jet2}}|$";
        dSigma = "$\\frac{d\\sigma}{d|y_{\\text{jet2}}|} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("ThirdJetAbsRapidity_Zinc3jet") >= 0) {
        title = "$|y_\\text{jet3}|$ ($N_{\\text{jets}} \\geq 3$)";
        var = "$|y_{\\text{jet3}}|$";
        dSigma = "$\\frac{d\\sigma}{d|y_{\\text{jet3}}|} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("FourthJetAbsRapidity_Zinc4jet") >= 0) {
        title = "$|y_\\text{jet4}|$ ($N_{\\text{jets}} \\geq 4$)";
        var = "$|y_{\\text{jet4}}|$";
        dSigma = "$\\frac{d\\sigma}{d|y_{\\text{jet4}}|} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    if (variable.Index("FifthJetAbsRapidity_Zinc5jet") >= 0) {
        title = "$|y_\\text{jet5}|$ ($N_{\\text{jets}} \\geq 5$)";
        var = "$|y_{\\text{jet5}}|$";
        dSigma = "$\\frac{d\\sigma}{d|y_{\\text{jet5}}|} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    // jet pt distributions
    if (xtitle.Index("p_{T}(j_{1})") >= 0) {
        title = "$1^{\\text{st}}$ jet $p_{\\text{T}}$ ($N_{\\text{jets}} \\geq 1$)";
        var = "$p_{\\text{T}}(j_{1})$ \\tiny{[GeV]}";
        dSigma = "$\\frac{d\\sigma}{dp_{\\text{T}}(j_{1})} \\tiny{\\left[\\frac{\\text{pb}}{\\text{GeV}}\\right]}$";
    }
    if (xtitle.Index("p_{T}(j_{2})") >= 0) {
        title = "$2^{\\text{nd}}$ jet $p_{\\text{T}}$ ($N_{\\text{jets}} \\geq 2$)";
        var = "$p_{\\text{T}}(j_{2})$ \\tiny{[GeV]}";
        dSigma = "$\\frac{d\\sigma}{dp_{\\text{T}}(j_{2})} \\tiny{\\left[\\frac{\\text{pb}}{\\text{GeV}}\\right]}$";
    }
    if (xtitle.Index("p_{T}(j_{3})") >= 0) {
        title = "$3^{\\text{rd}}$ jet $p_{\\text{T}}$ ($N_{\\text{jets}} \\geq 3$)";
        var = "$p_{\\text{T}}(j_{3})$ \\tiny{[GeV]}";
        dSigma = "$\\frac{d\\sigma}{dp_{\\text{T}}(j_{3})} \\tiny{\\left[\\frac{\\text{pb}}{\\text{GeV}}\\right]}$";
    }
    if (xtitle.Index("p_{T}(j_{4})") >= 0) {
        title = "$4^{\\text{th}}$ jet $p_{\\text{T}}$ ($N_{\\text{jets}} \\geq 4$)";
        var = "$p_{\\text{T}}(j_{4})$ \\tiny{[GeV]}";
        dSigma = "$\\frac{d\\sigma}{dp_{\\text{T}}(j_{4})} \\tiny{\\left[\\frac{\\text{pb}}{\\text{GeV}}\\right]}$";
    }
    if (xtitle.Index("p_{T}(j_{5})") >= 0) {
        title = "$5^{\\text{th}}$ jet $p_{\\text{T}}$ ($N_{\\text{jets}} \\geq 5$)";
        var = "$p_{\\text{T}}(j_{5})$ \\tiny{[GeV]}";
        dSigma = "$\\frac{d\\sigma}{dp_{\\text{T}}(j_{5})} \\tiny{\\left[\\frac{\\text{pb}}{\\text{GeV}}\\right]}$";
    }
    if (xtitle.Index("p_{T}(j_{6})") >= 0) {
        title = "$6^{\\text{th}}$ jet $p_{\\text{T}}$ ($N_{\\text{jets}} \\geq 6$)";
        var = "$p_{\\text{T}}(j_{6})$ \\tiny{[GeV]}";
        dSigma = "$\\frac{d\\sigma}{dp_{\\text{T}}(j_{6})} \\tiny{\\left[\\frac{\\text{pb}}{\\text{GeV}}\\right]}$";
    }

    // jet HT distributions
    if (xtitle.Index("H_{T}") >= 0 && title.Index("N_{jets} #geq 1") >= 0) {
        title = "$H_{\\text{T}}$ ($N_{\\text{jets}} \\geq 1$)";
        var = "$H_{\\text{T}}$ \\tiny{[GeV]}";
        dSigma = "$\\frac{d\\sigma}{dH_{\\text{T}}} \\tiny{\\left[\\frac{\\text{pb}}{\\text{GeV}}\\right]}$";
    }
    if (xtitle.Index("H_{T}") >= 0 && title.Index("N_{jets} #geq 2") >= 0) {
        title = "$H_{\\text{T}}$ ($N_{\\text{jets}} \\geq 2$)";
        var = "$H_{\\text{T}}$ \\tiny{[GeV]}";
        dSigma = "$\\frac{d\\sigma}{dH_{\\text{T}}} \\tiny{\\left[\\frac{\\text{pb}}{\\text{GeV}}\\right]}$";
    }
    if (xtitle.Index("H_{T}") >= 0 && title.Index("N_{jets} #geq 3") >= 0) {
        title = "$H_{\\text{T}}$ ($N_{\\text{jets}} \\geq 3$)";
        var = "$H_{\\text{T}}$ \\tiny{[GeV]}";
        dSigma = "$\\frac{d\\sigma}{dH_{\\text{T}}} \\tiny{\\left[\\frac{\\text{pb}}{\\text{GeV}}\\right]}$";
    }
    if (xtitle.Index("H_{T}") >= 0 && title.Index("N_{jets} #geq 4") >= 0) {
        title = "$H_{\\text{T}}$ ($N_{\\text{jets}} \\geq 4$)";
        var = "$H_{\\text{T}}$ \\tiny{[GeV]}";
        dSigma = "$\\frac{d\\sigma}{dH_{\\text{T}}} \\tiny{\\left[\\frac{\\text{pb}}{\\text{GeV}}\\right]}$";
    }
    if (xtitle.Index("H_{T}") >= 0 && title.Index("N_{jets} #geq 5") >= 0) {
        title = "$H_{\\text{T}}$ ($N_{\\text{jets}} \\geq 5$)";
        var = "$H_{\\text{T}}$ \\tiny{[GeV]}";
        dSigma = "$\\frac{d\\sigma}{dH_{\\text{T}}} \\tiny{\\left[\\frac{\\text{pb}}{\\text{GeV}}\\right]}$";
    }
    if (xtitle.Index("H_{T}") >= 0 && title.Index("N_{jets} #geq 6") >= 0) {
        title = "$H_{\\text{T}}$ ($N_{\\text{jets}} \\geq 6$)";
        var = "$H_{\\text{T}}$ \\tiny{[GeV]}";
        dSigma = "$\\frac{d\\sigma}{dH_{\\text{T}}} \\tiny{\\left[\\frac{\\text{pb}}{\\text{GeV}}\\right]}$";
    }

    // jet eta distributions
    if (xtitle.Index("eta(j_{1})") >= 0) {
        title = "$1^{\\text{st}}$ jet $\\vert\\eta\\vert$ ($N_{\\text{jets}} \\geq 1$)";
        var = "$\\eta(j_{1})$";
        dSigma = "$\\frac{d\\sigma}{d\\eta(j_{1})} \\tiny{\\left[\\text{pb}\\right]}$";
    }
    if (xtitle.Index("eta(j_{2})") >= 0) {
        title = "$2^{\\text{nd}}$ jet $\\vert\\eta\\vert$ ($N_{\\text{jets}} \\geq 2$)";
        var = "$\\eta(j_{2})$";
        dSigma = "$\\frac{d\\sigma}{d\\eta(j_{2})} \\tiny{\\left[\\text{pb}\\right]}$";
    }
    if (xtitle.Index("eta(j_{3})") >= 0) {
        title = "$3^{\\text{rd}}$ jet $\\vert\\eta\\vert$ ($N_{\\text{jets}} \\geq 3$)";
        var = "$\\eta(j_{3})$";
        dSigma = "$\\frac{d\\sigma}{d\\eta(j_{3})} \\tiny{\\left[\\text{pb}\\right]}$";
    }
    if (xtitle.Index("eta(j_{4})") >= 0) {
        title = "$4^{\\text{th}}$ jet $\\vert\\eta\\vert$ ($N_{\\text{jets}} \\geq 4$)";
        var = "$\\eta(j_{4})$";
        dSigma = "$\\frac{d\\sigma}{d\\eta(j_{4})} \\tiny{\\left[\\text{pb}\\right]}$";
    }
    if (xtitle.Index("eta(j_{5})") >= 0) {
        title = "$5^{\\text{th}}$ jet $\\vert\\eta\\vert$ ($N_{\\text{jets}} \\geq 5$)";
        var = "$\\eta(j_{5})$";
        dSigma = "$\\frac{d\\sigma}{d\\eta(j_{5})} \\tiny{\\left[\\text{pb}\\right]}$";
    }
    if (xtitle.Index("eta(j_{6})") >= 0) {
        title = "$6^{\\text{th}}$ jet $\\vert\\eta\\vert$ ($N_{\\text{jets}} \\geq 6$)";
        var = "$\\eta(j_{6})$";
        dSigma = "$\\frac{d\\sigma}{d\\eta(j_{6})} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    // dijet mass distribution
    if (xtitle.Index("M_{j_{1}j_{2}}") >= 0) {
        title = "dijet mass $M_{jj}$ ($N_{\\text{jets}} \\geq 2$)";
        var = "$M_{jj}$ \\tiny{[GeV]}";
        dSigma = "$\\frac{d\\sigma}{dM_{jj}} \\tiny{\\left[\\frac{\\text{pb}}{\\text{GeV}}\\right]}$";
    }

    if (doNormalized) {
        dSigma = "$\\frac{1}{\\sigma}$ " + dSigma;
        dSigma.ReplaceAll("\\frac{\\text{pb}}", "\\frac{1}");
        dSigma.ReplaceAll("\\tiny{\\left[\\text{pb}\\right]}", "");
    }

}
