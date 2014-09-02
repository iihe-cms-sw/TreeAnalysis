#ifndef _MAKEZJETSPOTS_H_
#define _MAKEZJETSPOTS_H_

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

TCanvas* makeZJetsPlots(TH1D *hStat, TH2D *hCovSyst, TH1D *gen1, TH1D *gen2 = NULL, TH1D *gen3 = NULL);
TCanvas* makeZJetsPlots(TH1D *hStat, TH1D *hSyst, TH1D *hPDFUp, TH1D *hPDFDown, TH1D *gen1, TH1D *gen2 = NULL, TH1D *gen3 = NULL);
TCanvas* makeZJetsPlots(TGraphAsymmErrors *grStat, TGraphAsymmErrors *grSyst, TH1D *hPDFUp, TH1D *hPDFDown, TH1D *gen1, TH1D *gen2 = NULL, TH1D *gen3 = NULL);
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
