#ifndef _PLOTSETTINGS_H_
#define _PLOTSETTINGS_H_

#include <iostream>
#include <TGraphAsymmErrors.h>
#include <TGraphErrors.h>
#include <TH1.h>
#include <TH2.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TLegendEntry.h>
#include <TMath.h>
#include <TAxis.h>
#include <TLatex.h>

const int ZJetsFillColor[3] = {kBlue-10, kOrange-2, kGreen-8};
const int ZJetsPdfFillColor[3] = {kBlue-6, kOrange-5, kGreen-2};
const int ZJetsLineColor[3] = {kBlue, kOrange+10, kGreen+3};;
const int ZJetsMarkerColor[3] = {ZJetsLineColor[0], ZJetsLineColor[1], ZJetsLineColor[2]};
const int ZJetsMarkerStyle[3] = {24, 25, 26};
const int ZJetsFillStyle = 1001;


void setAndDrawTPad(TString canvasName, TPad *plot, int plotNumber, int numbOfGenerator);
std::string getYaxisTitle(const TH1D *gen1);
void customizeLegend(TLegend *legend, int numbOfGenerator);
void customizeLegend(TLegend *legend, int genNumb, int numbOfGenerator);
void configYaxis(TGraphAsymmErrors *grCentralSyst, TH1D *gen1, TH1D *gen2 = NULL, TH1D *gen3 = NULL);
void configXaxis(TGraphAsymmErrors *grCentralSyst, TH1D *gen1);
void customizeCentral(TGraphAsymmErrors *grCentral, bool ratio);
void customizeCentral(TGraphAsymmErrors *grCentral, TLegend *legend, TString legText = "");
void customizeGenHist(TH1D *gen, int genNumb, TLegend *legend, TString legText);
void customizeGenGraph(TGraphAsymmErrors *gen, TGraphAsymmErrors *gPDF, int genNumb, TString yTitle, int numbOfGenerator, TLegend *legend = NULL);
TGraphAsymmErrors* createGrFromHist(const TH1D *h);
TGraphAsymmErrors* createRatioGraph(const TGraphAsymmErrors* grCentral);
TGraphErrors* createRatioGraph(const TGraphErrors* grCentral);
TGraphAsymmErrors *createGenToCentral(const TH1D *gen, const TGraphAsymmErrors *grCentral);
TGraphAsymmErrors* createPDFSystGraph(const TH1D *hPDFUp, const TH1D *hPDFDown, const TGraphAsymmErrors *grGenToCentral);

#endif