#ifndef _MAKEZJETSPOTS_H_
#define _MAKEZJETSPOTS_H_

#include <iostream>
#include <string>
#include <TGraphAsymmErrors.h>
#include <TGraphErrors.h>
#include <TH1.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TLegendEntry.h>
#include <TMath.h>
#include <TAxis.h>
#include <TLatex.h>

TCanvas* makeZJetsPlots(TGraphAsymmErrors *grCentralStat, TGraphAsymmErrors *grCentralSyst, TH1D *gen1, TH1D *gen2 = NULL, TH1D *gen3 = NULL);
void setAndDrawTPad(TPad *plot, int plotNumber, int numbOfGenerator);
string getYaxisTitle(const TH1D *gen1);
void customizeLegend(TLegend *legend, int numbOfGenerator);
void customizeLegend(TLegend *legend, int genNumb, int numbOfGenerator);
void configYaxis(TGraphAsymmErrors *grCentralSyst, TH1D *gen1, TH1D *gen2 = NULL, TH1D *gen3 = NULL);
void configXaxis(TGraphAsymmErrors *grCentralSyst, TH1D *gen1);
void customizeCentral(TGraphAsymmErrors *grCentral, bool ratio);
void customizeCentral(TGraphAsymmErrors *grCentral, TLegend *legend, string legText = "");
void customizeGenHist(TH1D *gen, int genNumb, TLegend *legend, string legText);
void customizeGenGraph(TGraphAsymmErrors *gen, int genNumb, string yTitle, int numbOfGenerator, TLegend *legend = NULL);
TGraphAsymmErrors* createRatioGraph(const TGraphAsymmErrors* grCentral);
TGraphErrors* createRatioGraph(const TGraphErrors* grCentral);
TGraphAsymmErrors *createGenToCentral(const TH1D *gen, const TGraphAsymmErrors *grCentral);

#endif
