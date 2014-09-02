#include "PlotSettings.h"
#include "TStyle.h"


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
        legend->SetX1(0.44);
        legend->SetY1(0.8);
        legend->SetX2(0.97);
        legend->SetY2(0.98);
        legend->SetTextSize(.029);
    }
    else if (numbOfGenerator == 2) {
        legend->SetX1(0.44);
        legend->SetY1(0.77);
        legend->SetX2(0.95);
        legend->SetY2(0.98);
        legend->SetTextSize(.034);
    }
    else if (numbOfGenerator == 3) {
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
        gen->GetYaxis()->SetTitleOffset(0.8);
        if (numbOfGenerator == 2) gen->GetYaxis()->SetTitleOffset(0.75);
        if (numbOfGenerator == 3) gen->GetYaxis()->SetTitleOffset(0.7);
        gen->GetXaxis()->SetLabelSize(0.10);
        gen->GetXaxis()->SetTitleSize(0.12);
        gen->GetXaxis()->SetTitleOffset(1.10);
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
        grCentralSyst->GetXaxis()->SetLabelSize(0.14);
        grCentralSyst->GetXaxis()->SetLabelOffset(0.01);
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
        grCentralSyst->GetXaxis()->SetLabelSize(0.14);
        grCentralSyst->GetXaxis()->SetLabelOffset(0.01);
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



