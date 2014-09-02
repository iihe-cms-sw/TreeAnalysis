#include "makeZJetsPlots.h"
#include <TStyle.h>
#include <sstream>


int ZJetsFillColor[3] = {kBlue-10, kOrange-2, kGreen-8};
int ZJetsPdfFillColor[3] = {kBlue-6, kOrange-5, kGreen-2};
int ZJetsLineColor[3] = {kBlue, kOrange+10, kGreen+3};;
int ZJetsMarkerColor[3] = {ZJetsLineColor[0], ZJetsLineColor[1], ZJetsLineColor[2]};
int ZJetsMarkerStyle[3] = {24, 25, 26};
int ZJetsFillStyle = 1001;

TCanvas* makeZJetsPlots(TH1D *hStat, TH2D *hCovSyst, TH1D *gen1, TH1D *gen2, TH1D *gen3)
{
    TH1D *hSyst = (TH1D*) hStat->Clone();
    int nBins = hSyst->GetNbinsX();

    for (int i = 1; i <= nBins; ++i) {
        hSyst->SetBinError(i, sqrt(pow(hStat->GetBinError(i), 2) + hCovSyst->GetBinContent(i, i)));
    }

    TH1D *hPDFUp = (TH1D*) hStat->Clone();
    hPDFUp->Scale(1.10);
    TH1D *hPDFDown = (TH1D*) hStat->Clone();
    hPDFDown->Scale(0.75);

    TCanvas *can = makeZJetsPlots(hStat, hSyst, hPDFUp, hPDFDown, gen1);
    can->Update();

    return can;


}

TCanvas* makeZJetsPlots(TH1D *hStat, TH1D *hSyst, TH1D *hPDFUp, TH1D *hPDFDown, TH1D *gen1, TH1D *gen2, TH1D *gen3)
{
    TGraphAsymmErrors *grCentralStat = createGrFromHist(hStat);
    TGraphAsymmErrors *grCentralSyst = createGrFromHist(hSyst);

    TCanvas *plots = makeZJetsPlots(grCentralStat, grCentralSyst, hPDFUp, hPDFDown, gen1, gen2, gen3);

    return plots;

}

TCanvas* makeZJetsPlots(TGraphAsymmErrors *grCentralStat, TGraphAsymmErrors *grCentralSyst, TH1D *hPDFUp, TH1D *hPDFDown, TH1D *gen1, TH1D *gen2, TH1D *gen3)
{

    //--- Determine how many comparison we have ---
    int numbOfGenerator = 1;
    if (gen2) numbOfGenerator = 2;
    if (gen3) numbOfGenerator = 3;
    //---------------------------------------------


    //--- Declare all additional TGraphs ---
    TGraphAsymmErrors *grCentralStatRatio = createRatioGraph(grCentralStat);
    TGraphAsymmErrors *grCentralSystRatio = createRatioGraph(grCentralSyst);
    TGraphAsymmErrors *grGen1ToCentral = createGenToCentral(gen1, grCentralStat);
    TGraphAsymmErrors *grGen1PDFSyst = createPDFSystGraph(hPDFUp, hPDFDown, grGen1ToCentral); 
    TGraphAsymmErrors *grGen2ToCentral = NULL;
    TGraphAsymmErrors *grGen2PDFSyst = NULL;
    if (gen2) {
        grGen2ToCentral = createGenToCentral(gen2, grCentralStat);
        grGen2PDFSyst = createPDFSystGraph(hPDFUp, hPDFDown, grGen2ToCentral); 
    }
    TGraphAsymmErrors *grGen3ToCentral = NULL;
    TGraphAsymmErrors *grGen3PDFSyst = NULL;
    if (gen3) {
        grGen3ToCentral = createGenToCentral(gen3, grCentralStat);
        grGen3PDFSyst = createPDFSystGraph(hPDFUp, hPDFDown, grGen3ToCentral); 
    }
    //---------------------------------------------

    //--- Main Canvas ---
    std::string variable = gen1->GetName();
    double maximum = gen1->GetMaximum();
    variable = variable.substr(3);
    TString canvasName = "plots_" + variable;
    TCanvas *plots = new TCanvas(canvasName, canvasName, 600, 800);
    //-------------------

    //--- First Pad ---
    plots->cd();
    TPad *plot1 = new TPad("plot1", "plot1", 0., 0., 0., 0.);
    setAndDrawTPad(canvasName, plot1, 1, numbOfGenerator);

    //--- TLegend ---
    TLegend *legend = new TLegend(0.47, 0.74, 0.99, 0.98);
    customizeLegend(legend, numbOfGenerator);
    //------------------

    customizeCentral(grCentralSyst, legend, "Data");
    customizeCentral(grCentralStat, (bool)false);
    customizeCentral(grCentralSystRatio, (bool)true);
    customizeCentral(grCentralStatRatio, (bool)true);
    grCentralSyst->Draw("a2");
    customizeGenHist(gen1, 1, legend, "Sherpa2 (#leq2j@NLO 3,4j@LO + PS)");
    gen1->DrawCopy("ESAME");
    if (gen2) {
        customizeGenHist(gen2, 2, legend, "Madgraph + Pythia6 (#leq4j@LO + PS)");
        gen2->DrawCopy("ESAME");
    }
    if (gen3) {
        customizeGenHist(gen3, 3, legend, "Powheg + Pythia6 (Z+2j@NLO + PS)");
        gen3->DrawCopy("ESAME");
    }

    configYaxis(grCentralSyst, gen1, gen2, gen3);
    configXaxis(grCentralSyst, gen1);
    grCentralStat->Draw("p");
    if (canvasName.Index("Eta") >= 0) {
        grCentralSyst->GetHistogram()->GetYaxis()->SetRangeUser(0.001, 1.4*maximum);
    }
    legend->Draw("same");

    //--- TLatex stuff ---
    TLatex *latexLabel = new TLatex(); 
    latexLabel->SetTextSize(0.65);
    if (gen2) latexLabel->SetTextSize(0.041);
    if (gen3) latexLabel->SetTextSize(0.0405);
    latexLabel->SetTextFont(42);
    latexLabel->SetLineWidth(2);
    latexLabel->SetNDC();

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
    ytitle->SetTextSize(0.05);
    if (gen2) ytitle->SetTextSize(0.056);
    if (gen3) ytitle->SetTextSize(0.06);
    ytitle->SetTextFont(42);
    ytitle->SetLineWidth(2);
    ytitle->SetTextColor(kBlack);
    ytitle->SetNDC();
    ytitle->SetTextAlign(33);
    ytitle->SetTextAngle(90);
    std::string strYtitle = getYaxisTitle(gen1);
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
    //-----------------------

    //--- End Of first Pad ---

    //--- Second Pad ---
    plots->cd();
    TPad *plot2 = new TPad("plot2", "plot2", 0., 0., 0., 0.);
    setAndDrawTPad(canvasName, plot2, 2, numbOfGenerator);

    //--- TLegend ---
    TLegend *legend2 = new TLegend(0.16, 0.05, 0.42, 0.20);
    customizeLegend(legend2, 1, numbOfGenerator);
    customizeGenGraph(grGen1ToCentral, grGen1PDFSyst, 1, "Sherpa2/Data", numbOfGenerator, legend2);
    configXaxis(grGen1ToCentral, gen1);
    grGen1PDFSyst->SetFillStyle(ZJetsFillStyle);
    grGen1PDFSyst->SetFillColor(ZJetsPdfFillColor[0]);
    grGen1ToCentral->Draw("a2");
    //grGen1PDFSyst->Draw("2");
    grGen1ToCentral->Draw("2");
    grCentralSystRatio->Draw("2");
    grCentralStatRatio->Draw("p");
    grGen1ToCentral->Draw("p");
    legend2->Draw("same");
    plot2->RedrawAxis();
    //--- End of Second Pad ---


    if (gen2) {
        //--- Third Pad ---
        plots->cd();
        TPad *plot3 = new TPad("plot3", "plot3", 0., 0., 0., 0.);
        setAndDrawTPad(canvasName, plot3, 3, numbOfGenerator);

        //--- TLegend ---
        TLegend *legend3 = new TLegend(0.16, 0.05, 0.42, 0.20);
        customizeLegend(legend3, 2, numbOfGenerator);
        customizeGenGraph(grGen2ToCentral, grGen2PDFSyst, 2, "MadGraph/Data", numbOfGenerator, legend3);
        configXaxis(grGen2ToCentral, gen2);
        grGen2PDFSyst->SetFillStyle(ZJetsFillStyle);
        grGen2PDFSyst->SetFillColor(ZJetsPdfFillColor[2]);
        grGen2ToCentral->Draw("a2");
        //grGen2PDFSyst->Draw("2");
        grGen2ToCentral->Draw("2");
        grCentralSystRatio->Draw("2");
        grCentralStatRatio->Draw("p");
        grGen2ToCentral->Draw("p");
        legend3->Draw("same");
        plot3->RedrawAxis();
        //--- End of Third Pad ---
    }

    if (gen3) {
        //--- Fourth Pad ---
        plots->cd();
        TPad *plot4 = new TPad("plot4", "plot4", 0., 0., 0., 0.);
        setAndDrawTPad(canvasName, plot4, 4, numbOfGenerator);

        //--- TLegend ---
        TLegend *legend4 = new TLegend(0.16, 0.05, 0.42, 0.20);
        customizeLegend(legend4, 3, numbOfGenerator);
        customizeGenGraph(grGen3ToCentral, grGen3PDFSyst, 3, "Powheg/Data", numbOfGenerator, legend4);
        configXaxis(grGen3ToCentral, gen3);
        grGen3PDFSyst->SetFillStyle(ZJetsFillStyle);
        grGen3PDFSyst->SetFillColor(ZJetsPdfFillColor[1]);
        grGen3ToCentral->Draw("a2");
        //grGen3PDFSyst->Draw("2");
        grGen3ToCentral->Draw("2");
        grCentralSystRatio->Draw("2");
        grCentralStatRatio->Draw("p");
        grGen3ToCentral->Draw("p");
        legend4->Draw("same");
        plot4->RedrawAxis();
        //--- End of Fourth Pad ---
    }

    return plots;
}

std::string getYaxisTitle(const TH1D *gen1)
{
    std::string title = "";
    int doXSec = 1, doNormalize = 0;
    if (doXSec || doNormalize) {
        std::string xtitle = gen1->GetXaxis()->GetTitle();
        std::string shortVar = xtitle.substr(0, xtitle.find(" "));
        std::string unit = "";
        if (xtitle.find("#eta") != std::string::npos) {
            xtitle = "|" + xtitle + "|";
        }
        if (xtitle.find("[") != std::string::npos){
            size_t begin = xtitle.find("[") + 1;
            unit = xtitle.substr(begin);
            unit = unit.substr(0, unit.find("]"));
        }
        title = "d#sigma/d" + shortVar;
        if (doNormalize) title = "1/#sigma " + title;
        else if (doXSec){
            title += "  [pb";
            if (unit != "" ) title += "/" + unit;
            title += "]";
        }
    }
    return title;
}

void configYaxis(TGraphAsymmErrors *grCentralSyst, TH1D *gen1, TH1D *gen2, TH1D *gen3)
{
    //--- Configure Y axis of the plot ---
    double minimumToPlot = grCentralSyst->GetHistogram()->GetMinimum();
    minimumToPlot = TMath::Min(minimumToPlot, gen1->GetBinContent(gen1->GetMinimumBin()));
    if (gen2) minimumToPlot = TMath::Min(minimumToPlot, gen2->GetBinContent(gen2->GetMinimumBin()));
    if (gen3) minimumToPlot = TMath::Min(minimumToPlot, gen3->GetBinContent(gen3->GetMinimumBin()));

    double maximumToPlot = grCentralSyst->GetHistogram()->GetMaximum();
    maximumToPlot = TMath::Max(maximumToPlot, gen1->GetBinContent(gen1->GetMaximumBin()));
    if (gen2) maximumToPlot = TMath::Max(maximumToPlot, gen2->GetBinContent(gen2->GetMaximumBin()));
    if (gen3) maximumToPlot = TMath::Max(maximumToPlot, gen3->GetBinContent(gen3->GetMaximumBin()));

    grCentralSyst->GetYaxis()->SetRangeUser(0.2*minimumToPlot, 5*maximumToPlot);
}

void configXaxis(TGraphAsymmErrors *grCentralSyst, TH1D *gen1)
{
    //--- Configure X axis of the plot ---
    double minX, tmp;
    double maxX;
    int firstBin = 0;
    TString variable = gen1->GetName();
    if (variable.Index("ZNGoodJets") >= 0) firstBin = 1;
    grCentralSyst->GetPoint(firstBin, minX, tmp);
    grCentralSyst->GetPoint(grCentralSyst->GetN()-1, maxX, tmp);
    minX -= grCentralSyst->GetErrorXlow(firstBin); 
    maxX += grCentralSyst->GetErrorXhigh(grCentralSyst->GetN()-1);
    if (variable.Index("ZNGoodJets_Zexc") >= 0) {
        grCentralSyst->GetXaxis()->Set(maxX-minX, minX, maxX);
        grCentralSyst->GetXaxis()->SetBinLabel(1, "= 1");
        grCentralSyst->GetXaxis()->SetBinLabel(2, "= 2");
        grCentralSyst->GetXaxis()->SetBinLabel(3, "= 3");
        grCentralSyst->GetXaxis()->SetBinLabel(4, "= 4");
        grCentralSyst->GetXaxis()->SetBinLabel(5, "= 5");
        grCentralSyst->GetXaxis()->SetBinLabel(6, "= 6");
        grCentralSyst->GetXaxis()->SetBinLabel(7, "= 7");
        grCentralSyst->GetXaxis()->SetLabelSize(0.15);
        grCentralSyst->GetXaxis()->SetLabelOffset(0.02);
    }
    else if (variable.Index("ZNGoodJets_Zinc") >= 0) {
        grCentralSyst->GetXaxis()->Set(maxX-minX, minX, maxX);
        grCentralSyst->GetXaxis()->SetBinLabel(1, "#geq 1");
        grCentralSyst->GetXaxis()->SetBinLabel(2, "#geq 2");
        grCentralSyst->GetXaxis()->SetBinLabel(3, "#geq 3");
        grCentralSyst->GetXaxis()->SetBinLabel(4, "#geq 4");
        grCentralSyst->GetXaxis()->SetBinLabel(5, "#geq 5");
        grCentralSyst->GetXaxis()->SetBinLabel(6, "#geq 6");
        grCentralSyst->GetXaxis()->SetBinLabel(7, "#geq 7");
        grCentralSyst->GetXaxis()->SetLabelSize(0.15);
        grCentralSyst->GetXaxis()->SetLabelOffset(0.02);
    }
    grCentralSyst->GetXaxis()->SetRangeUser(minX, maxX);
    TString xtitle = gen1->GetXaxis()->GetTitle();
    if (xtitle.Index("#eta") >= 0) xtitle = "|" + xtitle + "|";
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
    //-----------------------------------------

}

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


    if (plotNumber == 1 && canvasName.Index("Eta") < 0) plot->SetLogy();
    plot->SetRightMargin(0.1);
    plot->SetFillStyle(0);
    plot->Draw();
    plot->cd();
}

void customizeLegend(TLegend *legend, int numbOfGenerator)
{
    legend->SetFillColor(0);
    legend->SetFillStyle(1001);
    legend->SetBorderSize(1);
    legend->SetX1(0.44);
    legend->SetY1(0.8);
    legend->SetX2(0.95);
    legend->SetY2(0.98);
    legend->SetTextSize(.029);
    if (numbOfGenerator == 2) {
        legend->SetX1(0.44);
        legend->SetY1(0.77);
        legend->SetX2(0.95);
        legend->SetY2(0.98);
        legend->SetTextSize(.034);
    }
    if (numbOfGenerator == 3) {
        legend->SetX1(0.44);
        legend->SetY1(0.74);
        legend->SetX2(0.95);
        legend->SetY2(0.98);
        legend->SetTextSize(.04);
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
        legend->SetY1(0.34);
        legend->SetX2(0.4);
        legend->SetY2(0.44);
        //legend->SetTextSize(0.06);
        legend->SetTextSize(0.078);
    }

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
    grCentral->GetYaxis()->SetLabelSize(0.04);
    grCentral->GetYaxis()->SetLabelFont(42);
    grCentral->GetYaxis()->SetTitleFont(42);

    grCentral->SetTitle();
    grCentral->GetXaxis()->SetTitle();
    if (legend) legend->AddEntry(grCentral, legText, "PLEF");

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

void customizeGenGraph(TGraphAsymmErrors *gen, TGraphAsymmErrors *gPDF, int genNum, TString yTitle, int numbOfGenerator, TLegend *legend)
{
    gen->GetYaxis()->SetRangeUser(0.2, 1.8);
    gen->GetYaxis()->SetNdivisions(507);
    gen->GetYaxis()->SetLabelSize(0.15);
    gen->GetYaxis()->SetTitle(yTitle);
    gen->GetYaxis()->SetTitleSize(0.14);
    gen->GetYaxis()->SetTitleOffset(0.45);
    gen->GetYaxis()->CenterTitle();
    gen->SetTitle();
    gen->SetFillColor(ZJetsFillColor[genNum-1]);
    gen->SetFillStyle(ZJetsFillStyle);
    gen->SetLineColor(ZJetsLineColor[genNum-1]);
    gen->SetLineWidth(2);
    gen->SetMarkerColor(ZJetsLineColor[genNum-1]);
    gen->SetMarkerStyle(ZJetsMarkerStyle[genNum-1]);

    if (genNum == numbOfGenerator) {
        gen->GetYaxis()->SetLabelSize(0.09);
        if (numbOfGenerator == 2) gen->GetYaxis()->SetLabelSize(0.105);
        if (numbOfGenerator == 3) gen->GetYaxis()->SetLabelSize(0.115);
        gen->GetYaxis()->SetTitleSize(0.08);
        if (numbOfGenerator == 2) gen->GetYaxis()->SetTitleSize(0.09);
        if (numbOfGenerator == 3) gen->GetYaxis()->SetTitleSize(0.1);
        gen->GetYaxis()->SetTitleOffset(0.63);
        if (numbOfGenerator == 2) gen->GetYaxis()->SetTitleOffset(0.75);
        if (numbOfGenerator == 3) gen->GetYaxis()->SetTitleOffset(0.7);
        gen->GetXaxis()->SetLabelSize(0.10);
        gen->GetXaxis()->SetTitleSize(0.12);
        gen->GetXaxis()->SetTitleOffset(1.00);
    }
    else {
        gen->GetXaxis()->SetTitle();
    }

    if (legend) {
        TLegendEntry *leEntry = legend->AddEntry(gen, "Stat. unc. (gen)", "f");
        leEntry->SetFillColor(ZJetsFillColor[genNum-1]);
        leEntry->SetFillStyle(ZJetsFillStyle);
        //if (yTitle.find("MadGraph") == string::npos) {
        //    TLegendEntry *leEntry2 = legend->AddEntry(gPDF, "Tot. unc. (gen)", "f");
        //    leEntry2->SetFillColor(ZJetsPdfFillColor[genNum-1]);
        //    leEntry2->SetFillStyle(ZJetsFillStyle);
        //}
    }


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

TGraphAsymmErrors* createPDFSystGraph(const TH1D *hPDFUp, const TH1D *hPDFDown, const TGraphAsymmErrors *grGenToCentral)
{
    int nPoints = grGenToCentral->GetN();
    double *xCoor    = new double[nPoints];
    double *yCoor    = new double[nPoints];
    double *xErr     = new double[nPoints];
    double *yErrUp   = new double[nPoints];
    double *yErrDown = new double[nPoints];

    for (int i(0); i < nPoints; i++) {
        grGenToCentral->GetPoint(i, xCoor[i], yCoor[i]);

        xErr[i] = grGenToCentral->GetErrorXlow(i);

        yErrUp[i] = pow(grGenToCentral->GetErrorYhigh(i), 2);
        yErrUp[i] += pow(hPDFUp->GetBinContent(i+1)*yCoor[i], 2); 
        yErrUp[i] = sqrt(yErrUp[i]);

        yErrDown[i] = pow(grGenToCentral->GetErrorYlow(i), 2);
        yErrDown[i] += pow(hPDFDown->GetBinContent(i+1)*yCoor[i], 2); 
        yErrDown[i] = sqrt(yErrDown[i]);
    }

    TGraphAsymmErrors *grPDFSyst = new TGraphAsymmErrors(nPoints, xCoor, yCoor, xErr, xErr, yErrDown, yErrUp);
    delete [] xCoor; delete [] yCoor; delete [] xErr; delete [] yErrDown; delete [] yErrUp;
    return grPDFSyst;
}
