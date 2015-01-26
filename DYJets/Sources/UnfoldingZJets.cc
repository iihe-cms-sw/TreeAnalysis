#include <iostream>
#include <vector>
#include <math.h>
#include <TCanvas.h>
#include <RooUnfoldBayes.h>
#include <TParameter.h>
#include "fileNamesZJets.h"
#include "getFilesAndHistogramsZJets.h"
#include "variablesOfInterestZJets.h"
#include "UnfoldingZJets.h"
#include "PlotSettings.h"

using namespace std;

void UnfoldingZJets(TString lepSel, TString algo, TString histoDir, TString unfoldDir, 
        int jetPtMin, int jetEtaMax, TString variable)
{
    //--- create output directory if does not exist ---
    system("mkdir -p " + unfoldDir);

    int start = 0;
    int end = NVAROFINTERESTZJETS;

    if (variable != "") {
        start = findVariable(variable);
        if (start >= 0) {
            end = start + 1;
            cout << "Processing only variable: " << variable << endl;
        }
        else {
            cerr << "\nError: variable " << variable << " is not interesting." << endl;
            cerr << "See below the list of interesting variables:" << endl;
            for (unsigned int i = 0; i < NVAROFINTERESTZJETS; ++i) {
                cerr << "\t" << i << ": " << VAROFINTERESTZJETS[i].name << "\n" << endl;
            }
            return;
        }
    }

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

    //--- Open additional generator files -----------------------------------------------------
    TFile *fSheUnf = new TFile(histoDir + lepSel + "_8TeV_" + DYSHERPAUNFOLDINGFILENAME + "_dR_TrigCorr_1_Syst_0_JetPtMin_30_JetEtaMax_24.root");
    //TFile *fSheGen = new TFile(histoDir + lepSel + "_8TeV_" + DYSHERPAUNFOLDINGFILENAME + "_dR_TrigCorr_1_Syst_0_JetPtMin_30_JetEtaMax_24.root");
    TFile *fSheGen = new TFile(histoDir + lepSel + "_8TeV_" + "DYJetsToLL_M-50_TuneCUETP8M1_8TeV-MG-MLM-Bonzai" + "_dR_TrigCorr_1_Syst_0_JetPtMin_30_JetEtaMax_24.root");
    //TFile *fSheGen = new TFile(histoDir + lepSel + "_8TeV_" + DYSHERPAFILENAME + "_dR_TrigCorr_1_Syst_0_JetPtMin_30_JetEtaMax_24.root");
    TFile *fPowGen = new TFile(histoDir + lepSel + "_8TeV_" + DYPOWHEGFILENAME + "_dR_TrigCorr_1_Syst_0_JetPtMin_30_JetEtaMax_24.root");
    //TFile *fPowGen = new TFile(histoDir + lepSel + "_8TeV_" + DYSHERPAUNFOLDINGFILENAME + "_dR_TrigCorr_1_Syst_0_JetPtMin_30_JetEtaMax_24.root");
    //----------------------------------------------------------------------------------------- 
        std::cout << __LINE__ << std::endl;

    //----------------------------------------------------------------------------------------- 
    //--- Now run on the different variables ---
    for (int i = start; i < end; ++i) {
        variable = VAROFINTERESTZJETS[i].name;

        TString outputFileName = unfoldDir + lepSel; 
        outputFileName += "_unfolded_" + variable + "_" + algo;
        outputFileName += "_jetPtMin_";
        outputFileName += jetPtMin;
        outputFileName += "_jetEtaMax_";
        outputFileName += jetEtaMax;
        TFile *outputRootFile = new TFile(outputFileName + ".root", "RECREATE");


        //--- rec Data histograms ---
        TH1D *hRecData[3] = {NULL};
        //--- rec DYJets histograms ---
        TH1D *hRecDYJets[9] = {NULL};
        //--- fake DYJets histograms ---
        TH1D *hFakDYJets[14] = {NULL};
        //--- gen DYJets histograms ---
        TH1D *hGenDYJets[7] = {NULL};
        //--- res DYJets histograms ---
        TH2D *hResDYJets[9] = {NULL};
        //--- rec Bg histograms ---
        TH1D *hRecBg[NBGDYJETS][9] = {{NULL}};
        //--- rec Sum Bg histograms ---
        TH1D *hRecSumBg[9] = {NULL};
        //--- response DYJets objects ---
        RooUnfoldResponse *respDYJets[14] = {NULL};

        //--- Get all histograms ---
        getAllHistos(variable, hRecData, fData, 
                hRecDYJets, hGenDYJets, hResDYJets, fDYJets,
                hRecBg, hRecSumBg, fBg, NBGDYJETS, respDYJets, hFakDYJets);

        //--- Get Sherpa Unfolding response ---

        respDYJets[13] = getResp(fSheUnf, variable);
        TH1D *hSheGen = getHisto(fSheGen, "gen" + variable);
        TH1D *hPowGen = getHisto(fPowGen, "gen" + variable);
        //----------------------------------------------------------------------------------------- 

        TH1D *hMadGenCrossSection = makeCrossSectionHist(hGenDYJets[0], integratedLumi);
        hMadGenCrossSection->SetZTitle("MadGraph + Pythia6 (#leq4j@LO + PS)");
        TH1D *hSheGenCrossSection = makeCrossSectionHist(hSheGen, integratedLumi);
        hSheGenCrossSection->SetZTitle("Sherpa (#leq2j@NLO 3,4j@LO + PS)");
        hSheGenCrossSection->SetZTitle("Sherpa1.4 LO");
        hSheGenCrossSection->SetZTitle("MG+Py8 MLM LO");
        //hSheGenCrossSection->Scale(0.95); // I don't have Sherpa yet, so it is to simulate it
        TH1D *hPowGenCrossSection = makeCrossSectionHist(hPowGen, integratedLumi);
        hPowGenCrossSection->SetZTitle("Powheg + Pythia6 (Z+2j@NLO + PS)");
        hPowGenCrossSection->SetZTitle("aMC@NLO ");
        if (lepSel == "DMu") hPowGenCrossSection->Scale(9.67682344591264986e+06/1.21990572533038822e+18); 
        if (lepSel == "DE")  hPowGenCrossSection->Scale(9.68984524447932094e+06/1.26965652647094554e+18); 
        if (lepSel == "DMu")  hSheGenCrossSection->Scale(9.68984524447932094e+06/1.56860892310320000e+14); 
        if (lepSel == "DE") hSheGenCrossSection->Scale(9.68984524447932094e+06/2.07243222113040000e+14); 
        
        // Here is an array of TH1D to store the various unfolded data:
        // 0 - Central, 
        // 1 - JES up, 2 - JES down, 
        // 3 - PU up, 4 - PU down, 
        // 5 - JER up, 6 - JER down, 
        // 7 - XSEC up, 8 - XSEC down
        // 9 - Lumi up, 10 - Lumi down
        // 11 - SF up, 12 - SF down
        // 13 - SherpaUnf
        TString name[] = {"Central", "JESUp", "JESDown", "PUUp", "PUDown", "JERUp", "JERDown", 
            "XSECUp", "XSECDown", "LumiUp", "LumiDown", "SFUp", "SFDown", "SherpaUnf"};
        TH1D *hUnfData[14] = {NULL};
        TH2D *hUnfDataStatCov[14] = {NULL};
        TH2D *hUnfMCStatCov[14] = {NULL};

        int nIter; 
        if (algo == "Bayes" && lepSel == "DMu")     
            nIter = VAROFINTERESTZJETS[i].MuBayeskterm;
        else if (algo == "Bayes" && lepSel == "DE") 
            nIter = VAROFINTERESTZJETS[i].EBayeskterm;
        else if (algo == "SVD" && lepSel == "DMu")  
            nIter = VAROFINTERESTZJETS[i].MuSVDkterm;
        else if (algo == "SVD" && lepSel == "DE")   
            nIter = VAROFINTERESTZJETS[i].ESVDkterm;
        else {
            cerr << "Error: algo " << algo << " or lepSel " << lepSel << "invalid\n"; 
            cerr << "Aborting...\n";
            return;
        }
        //--- Unfold the Data histograms for each systematic ---
        for (unsigned short iSyst = 0; iSyst < 14; ++iSyst) {

            //--- only JES up and down (iSyst = 1 and 2) is applied on data ---
            unsigned short iData = (iSyst == 1 || iSyst == 2) ? iSyst : 0;
            unsigned short iBg = 0;
            if (iSyst == 0 || iSyst == 1 || iSyst == 2 || iSyst == 5 || iSyst == 6 || iSyst == 13) iBg = 0; // Central, JES, JER, Sherpa
            else if (iSyst == 3 || iSyst == 4) iBg = iSyst - 2; // PU
            else if (iSyst == 7 || iSyst == 8 || iSyst == 9 || iSyst == 10 || iSyst == 11 || iSyst == 12) iBg = iSyst - 4; // XSec, Lumi, SF

            TH1D *hRecDataMinusFakes = (TH1D*) hRecData[iData]->Clone();
            hRecDataMinusFakes->Add(hRecSumBg[iBg], -1);
            hRecDataMinusFakes->Add(hFakDYJets[iSyst], -1);

            if (iSyst == 13) cout << "SHERPAUNFOLDING" << endl;
            UnfoldData(algo, respDYJets[iSyst], hRecDataMinusFakes, nIter, hUnfData[iSyst], 
                    hUnfDataStatCov[iSyst], hUnfMCStatCov[iSyst], name[iSyst], integratedLumi);

            //--- save the unfolded histograms ---
            outputRootFile->cd(); 
            hUnfData[iSyst]->Write();
        }
        //----------------------------------------------------------------------------------------- 

        //--- Now create the covariance matrices ---
        TH2D *hCov[10] = {NULL};
        hCov[0] = (TH2D*) hUnfDataStatCov[0]->Clone("CovDataStat");
        hCov[1] = (TH2D*) hUnfMCStatCov[0]->Clone("CovMCStat");
        hCov[2] = makeCovFromUpAndDown(hUnfData[0], hUnfData[1], hUnfData[2], "CovJES");
        hCov[3] = makeCovFromUpAndDown(hUnfData[0], hUnfData[3], hUnfData[4], "CovPU");
        hCov[4] = makeCovFromUpAndDown(hUnfData[0], hUnfData[5], hUnfData[6], "CovJER");
        hCov[5] = makeCovFromUpAndDown(hUnfData[0], hUnfData[7], hUnfData[8], "CovXSec");
        hCov[6] = makeCovFromUpAndDown(hUnfData[0], hUnfData[9], hUnfData[10], "CovLumi");
        hCov[7] = makeCovFromUpAndDown(hUnfData[0], hUnfData[11], hUnfData[12], "CovSF");
        hCov[8] = makeCovFromUpAndDown(hUnfData[0], hUnfData[13], hUnfData[0], "CovSherpaUnf");
        hCov[9] = (TH2D*) hUnfMCStatCov[0]->Clone("CovTotSyst");
        for (int i = 2; i < 9; ++i) hCov[9]->Add(hCov[i]);
        TCanvas *tmpCanvas = new TCanvas();
        tmpCanvas->cd();
        hUnfData[0]->DrawCopy();
        hUnfData[1]->DrawCopy("same");
        tmpCanvas->SaveAs("sherpaComp.C");
        TCanvas *tmpCanvas2 = new TCanvas();
        tmpCanvas2->cd();
        hUnfData[1]->Divide(hUnfData[0]);
        hUnfData[1]->DrawCopy();
        tmpCanvas2->SaveAs("sherpaCompRatio.C");

        TCanvas *crossSectionPlot = makeCrossSectionPlot(lepSel, variable, hUnfData[0], hCov[9], hMadGenCrossSection, hSheGenCrossSection, hPowGenCrossSection); 
        //TCanvas *crossSectionPlot = makeCrossSectionPlot(lepSel, variable, hUnfData[0], hCov[9], hMadGenCrossSection, hPowGenCrossSection); 
        //TCanvas *crossSectionPlot = makeCrossSectionPlot(lepSel, variable, hUnfData[0], hCov[9], hMadGenCrossSection); 
        crossSectionPlot->Draw();
        crossSectionPlot->SaveAs(outputFileName + ".png");
        crossSectionPlot->SaveAs(outputFileName + ".pdf");
        crossSectionPlot->SaveAs(outputFileName + ".eps");
        crossSectionPlot->SaveAs(outputFileName + ".ps");
        crossSectionPlot->SaveAs(outputFileName + ".C");

        //hUnfData[13]->Scale(1.05); // I don't have Sherpa yet, so this is to simulate it
        //--- print out break down of errors ---
        for (int i = 2; i <= 9; ++i) {
            cout << hUnfData[0]->GetBinContent(i);
            for (int j = 0; j <= 9; ++j) {
                cout << " +/- " << sqrt(hCov[j]->GetBinContent(i,i))*100./hUnfData[0]->GetBinContent(i) << "%";
            }
            cout << endl;
        }

        createTable(lepSel, variable, hUnfData[0], hCov);
        //--------------------------------------

        //--- Save other things --- 
        outputRootFile->cd();
        hRecData[0]->Write("hRecDataCentral");
        hRecSumBg[0]->Write("hRecSumBgCentral");
        hRecDYJets[0]->Write("hRecDYJetsCentral");
        hGenDYJets[0]->Write("hGenDYJetsCentral");
        hMadGenCrossSection->Write("hMadGenDYJetsCrossSection");
        hSheGenCrossSection->Write("hSheGenDYJetsCrossSection");
        hPowGenCrossSection->Write("hPowGenDYJetsCrossSection");
        respDYJets[0]->Write("respDYJetsCentral");
        for (int i = 0; i < 9; ++i) {
            hCov[i]->Write();
        }
        TParameter<double> pIntegratedLumi("integratedLumi", integratedLumi);
        pIntegratedLumi.Write();
        TParameter<int> pNIter("nIter", nIter);
        pNIter.Write();
        crossSectionPlot->Write();
        //----------------------------------------------------------------------------------------- 

        outputRootFile->Close();

        if (end == start + 1) system("display " + outputFileName + ".png &");

    }

    //test();

    //--- Close all files ----------------------------------------------------------------------
    closeAllFiles(fData, fDYJets, fBg, NBGDYJETS);
    fSheUnf->Close();
    fSheGen->Close();
    fPowGen->Close();
    //------------------------------------------------------------------------------------------ 

}

void createTable(TString lepSel, TString variable, TH1D *hUnfData, TH2D *hCov[])
{
    cout << "Hello" << endl;    
    //--- print out break down of errors ---
    
    TString title = hUnfData->GetTitle();
    int nBins = hUnfData->GetNbinsX();
    TString var = "";
    TString dSigma = "";
    TString xtitle = hUnfData->GetXaxis()->GetTitle();
    createTitleVariableAnddSigma(xtitle, title, var, dSigma);
    cout << "Title: " << title << endl;
    cout << "Var: " << var << endl;
    cout << "dSig: " << dSigma << endl;
    cout << "nBins: " << nBins << endl;

    TString table = "\\begin{table}[htb!]\n\\begin{center}\n";
    table += "\\caption{Differential cross section in " + title;
    table += " and break down of the systematic uncertainites for the ";
    if (lepSel == "DMu") table += "muon decay channel.}\n";
    if (lepSel == "DE") table += "electron decay channel.}\n";
    if (lepSel == "") table += "combinaton of both decay channels.}\n";
    table += "\\scriptsize{\n";
    table += "\\begin{tabular}{c|cc|cccccccc}\n";
    table += "\\multicolumn{11}{c}{" + title + "} \\\\\n";
    table += var + " & " + dSigma + " & \\tiny{Tot. Unc [\\%]} & ";
    table += "\\tiny{stat [\\%]} & \\tiny{JES [\\%]} & \\tiny{JER [\\%]} & ";
    table += "\\tiny{PU [\\%]} & \\tiny{XSEC [\\%]} & \\tiny{Lumi [\\%]} & ";
    table += "\\tiny{Unf [\\%]} & \\tiny{Eff [\\%]} \\\\\\hline\n";

    int start = 1;
    if (title.Index("multiplicity", 0, TString::ECaseCompare::kIgnoreCase) >= 0) start = 2; 
    if (title.Index("jet $p_{\\text{T}}$", 0, TString::ECaseCompare::kIgnoreCase) >= 0) start = 3; 

    for (int i = start; i <= nBins; ++i) {
        double xs = hUnfData->GetBinContent(i);
        TString numbers;
        if (title.Index("multiplicity", 0,  TString::ECaseCompare::kIgnoreCase) >= 0) {
            numbers.Form("= %d", i - 1);
        }
        else {
            numbers.Form("$%g \\ -\\ %g$", hUnfData->GetBinLowEdge(i), hUnfData->GetBinLowEdge(i+1));
        }
        table += numbers + " & "; 
        numbers.Form("%#.3g", xs);
        table += numbers + " & ";
        numbers.Form("%#.2g", sqrt(hCov[0]->GetBinContent(i,i) + hCov[9]->GetBinContent(i,i))*100./xs);
        table += numbers + " & ";
        numbers.Form("%#.2g", sqrt(hCov[0]->GetBinContent(i,i))*100./xs);
        table += numbers + " & ";
        numbers.Form("%#.2g", sqrt(hCov[2]->GetBinContent(i,i))*100./xs);
        table += numbers + " & ";
        numbers.Form("%#.2g", sqrt(hCov[4]->GetBinContent(i,i))*100./xs);
        table += numbers + " & ";
        numbers.Form("%#.2g", sqrt(hCov[3]->GetBinContent(i,i))*100./xs);
        table += numbers + " & ";
        numbers.Form("%#.2g", sqrt(hCov[5]->GetBinContent(i,i))*100./xs);
        table += numbers + " & ";
        numbers.Form("%#.2g", sqrt(hCov[6]->GetBinContent(i,i))*100./xs);
        table += numbers + " & ";
        numbers.Form("%#.2g", sqrt(hCov[8]->GetBinContent(i,i))*100./xs);
        table += numbers + " & ";
        numbers.Form("%#.2g", sqrt(hCov[7]->GetBinContent(i,i))*100./xs);
        table += numbers + " \\\\\n";
    }

    table += "\\end{tabular}}\n";
    table += "\\label{tab:" + lepSel + variable + "}\n";
    table += "\\end{center}\\end{table}\n";

    cout << table << endl;
}

void createTitleVariableAnddSigma(TString xtitle, TString& title, TString& var, TString& dSigma) 
{

    // jet multiplicity
    if (xtitle.Index("N_{jets}") >= 0) {
        title = "Exclusive jet multiplicity";
        var = "$N_{\\text{jets}}$";
        dSigma = "$\\frac{d\\sigma}{N_{\\text{jets}}} \\tiny{\\left[\\text{pb}\\right]}$";
    }

    // jet pt distributions
    if (xtitle.Index("p_{T}(j_{1})") >= 0) {
        title = "$1^{\\text{st}}$ jet $p_{\\text{T}}$ ($N_{\\text{jets}} \\geq 1$)";
        var = "$p_{\\text{T}}(j_{1})$ \\tiny{[GeV]}";
        dSigma = "$\\frac{d\\sigma}{p_{\\text{T}}(j_{1})} \\tiny{\\left[\\frac{\\text{pb}}{\\text{GeV}}\\right]}$";
    }
    if (xtitle.Index("p_{T}(j_{2})") >= 0) {
        title = "$2^{\\text{nd}}$ jet $p_{\\text{T}}$ ($N_{\\text{jets}} \\geq 2$)";
        var = "$p_{\\text{T}}(j_{2})$ \\tiny{[GeV]}";
        dSigma = "$\\frac{d\\sigma}{p_{\\text{T}}(j_{2})} \\tiny{\\left[\\frac{\\text{pb}}{\\text{GeV}}\\right]}$";
    }
    if (xtitle.Index("p_{T}(j_{3})") >= 0) {
        title = "$3^{\\text{rd}}$ jet $p_{\\text{T}}$ ($N_{\\text{jets}} \\geq 3$)";
        var = "$p_{\\text{T}}(j_{3})$ \\tiny{[GeV]}";
        dSigma = "$\\frac{d\\sigma}{p_{\\text{T}}(j_{3})} \\tiny{\\left[\\frac{\\text{pb}}{\\text{GeV}}\\right]}$";
    }
    if (xtitle.Index("p_{T}(j_{4})") >= 0) {
        title = "$4^{\\text{th}}$ jet $p_{\\text{T}}$ ($N_{\\text{jets}} \\geq 4$)";
        var = "$p_{\\text{T}}(j_{4})$ \\tiny{[GeV]}";
        dSigma = "$\\frac{d\\sigma}{p_{\\text{T}}(j_{4})} \\tiny{\\left[\\frac{\\text{pb}}{\\text{GeV}}\\right]}$";
    }
    if (xtitle.Index("p_{T}(j_{5})") >= 0) {
        title = "$5^{\\text{th}}$ jet $p_{\\text{T}}$ ($N_{\\text{jets}} \\geq 5$)";
        var = "$p_{\\text{T}}(j_{5})$ \\tiny{[GeV]}";
        dSigma = "$\\frac{d\\sigma}{p_{\\text{T}}(j_{5})} \\tiny{\\left[\\frac{\\text{pb}}{\\text{GeV}}\\right]}$";
    }
    if (xtitle.Index("p_{T}(j_{6})") >= 0) {
        title = "$6^{\\text{th}}$ jet $p_{\\text{T}}$ ($N_{\\text{jets}} \\geq 6$)";
        var = "$p_{\\text{T}}(j_{6})$ \\tiny{[GeV]}";
        dSigma = "$\\frac{d\\sigma}{p_{\\text{T}}(j_{6})} \\tiny{\\left[\\frac{\\text{pb}}{\\text{GeV}}\\right]}$";
    }

    // jet HT distributions
    if (xtitle.Index("H_{T}") >= 0 && title.Index("N_{jets} #geq 1") >= 0) {
        title = "$H_{\\text{T}}$ ($N_{\\text{jets}} \\geq 1$)";
        var = "$H_{\\text{T}}$ \\tiny{[GeV]}";
        dSigma = "$\\frac{d\\sigma}{H_{\\text{T}}} \\tiny{\\left[\\frac{\\text{pb}}{\\text{GeV}}\\right]}$";
    }
    if (xtitle.Index("H_{T}") >= 0 && title.Index("N_{jets} #geq 2") >= 0) {
        title = "$H_{\\text{T}}$ ($N_{\\text{jets}} \\geq 2$)";
        var = "$H_{\\text{T}}$ \\tiny{[GeV]}";
        dSigma = "$\\frac{d\\sigma}{H_{\\text{T}}} \\tiny{\\left[\\frac{\\text{pb}}{\\text{GeV}}\\right]}$";
    }
    if (xtitle.Index("H_{T}") >= 0 && title.Index("N_{jets} #geq 3") >= 0) {
        title = "$H_{\\text{T}}$ ($N_{\\text{jets}} \\geq 3$)";
        var = "$H_{\\text{T}}$ \\tiny{[GeV]}";
        dSigma = "$\\frac{d\\sigma}{H_{\\text{T}}} \\tiny{\\left[\\frac{\\text{pb}}{\\text{GeV}}\\right]}$";
    }
    if (xtitle.Index("H_{T}") >= 0 && title.Index("N_{jets} #geq 4") >= 0) {
        title = "$H_{\\text{T}}$ ($N_{\\text{jets}} \\geq 4$)";
        var = "$H_{\\text{T}}$ \\tiny{[GeV]}";
        dSigma = "$\\frac{d\\sigma}{H_{\\text{T}}} \\tiny{\\left[\\frac{\\text{pb}}{\\text{GeV}}\\right]}$";
    }
    if (xtitle.Index("H_{T}") >= 0 && title.Index("N_{jets} #geq 5") >= 0) {
        title = "$H_{\\text{T}}$ ($N_{\\text{jets}} \\geq 5$)";
        var = "$H_{\\text{T}}$ \\tiny{[GeV]}";
        dSigma = "$\\frac{d\\sigma}{H_{\\text{T}}} \\tiny{\\left[\\frac{\\text{pb}}{\\text{GeV}}\\right]}$";
    }
    if (xtitle.Index("H_{T}") >= 0 && title.Index("N_{jets} #geq 6") >= 0) {
        title = "$H_{\\text{T}}$ ($N_{\\text{jets}} \\geq 6$)";
        var = "$H_{\\text{T}}$ \\tiny{[GeV]}";
        dSigma = "$\\frac{d\\sigma}{H_{\\text{T}}} \\tiny{\\left[\\frac{\\text{pb}}{\\text{GeV}}\\right]}$";
    }

    // jet eta distributions
    if (xtitle.Index("\\eta(j_{1})") >= 0) {
        title = "$1^{\\text{st}}$ jet $p_{\\text{T}}$ ($N_{\\text{jets}} \\geq 1$)";
        var = "$\\eta(j_{1})$";
        dSigma = "$\\frac{d\\sigma}{\\eta(j_{1})} \\tiny{\\left[\\text{pb}\\right]}$";
    }
    if (xtitle.Index("\\eta(j_{2})") >= 0) {
        title = "$2^{\\text{nd}}$ jet $p_{\\text{T}}$ ($N_{\\text{jets}} \\geq 2$)";
        var = "$\\eta(j_{2})$";
        dSigma = "$\\frac{d\\sigma}{\\eta(j_{2})} \\tiny{\\left[\\text{pb}\\right]}$";
    }
    if (xtitle.Index("\\eta(j_{3})") >= 0) {
        title = "$3^{\\text{rd}}$ jet $p_{\\text{T}}$ ($N_{\\text{jets}} \\geq 3$)";
        var = "$\\eta(j_{3})$";
        dSigma = "$\\frac{d\\sigma}{\\eta(j_{3})} \\tiny{\\left[\\text{pb}\\right]}$";
    }
    if (xtitle.Index("\\eta(j_{4})") >= 0) {
        title = "$4^{\\text{th}}$ jet $p_{\\text{T}}$ ($N_{\\text{jets}} \\geq 4$)";
        var = "$\\eta(j_{4})$";
        dSigma = "$\\frac{d\\sigma}{\\eta(j_{4})} \\tiny{\\left[\\text{pb}\\right]}$";
    }
    if (xtitle.Index("\\eta(j_{5})") >= 0) {
        title = "$5^{\\text{th}}$ jet $p_{\\text{T}}$ ($N_{\\text{jets}} \\geq 5$)";
        var = "$\\eta(j_{5})$";
        dSigma = "$\\frac{d\\sigma}{\\eta(j_{5})} \\tiny{\\left[\\text{pb}\\right]}$";
    }
    if (xtitle.Index("\\eta(j_{6})") >= 0) {
        title = "$6^{\\text{th}}$ jet $p_{\\text{T}}$ ($N_{\\text{jets}} \\geq 6$)";
        var = "$\\eta(j_{6})$";
        dSigma = "$\\frac{d\\sigma}{\\eta(j_{6})} \\tiny{\\left[\\text{pb}\\right]}$";
    }

}

void UnfoldData(const TString algo, RooUnfoldResponse *resp, TH1D *hRecDataMinusFakes, int nIter, 
        TH1D* &hUnfData, TH2D* &hUnfDataStatCov, TH2D* &hUnfMCStatCov, TString name, 
        double integratedLumi)
{
    //--- make sure we use OverFlow (should already be set to true) ---
    resp->UseOverflow();

    //--- Set the required unfolding algorithm ---
    RooUnfold::Algorithm alg;
    if (algo == "Bayes") {
        alg = RooUnfold::kBayes;
    }
    else if (algo == "SVD") {
        alg = RooUnfold::kSVD;
    }
    else {
        cerr << "Error: the specified algo: " << algo << " is not implemented!" << endl;
        cerr << "       I will proceed with kBayes algo" << endl;
        alg = RooUnfold::kBayes;
    }

    //std::cout << "-----------------------" << std::endl;
    TFile *f = new TFile("Test_" + name + ".root", "RECREATE"); 
    TH1D *hchi2 = new TH1D("hchi2", "hchi2", 100, 0, 100);
    f->cd();
    for (int i = 1; i <= 100; ++i) {
        RooUnfold *RObjectForDataTmp = RooUnfold::New(alg, resp, hRecDataMinusFakes, i);
        int nBinsToSkip = (TString(hRecDataMinusFakes->GetName()).Index("JetPt_Zinc") > 0) ? 2 : 0;
        RObjectForDataTmp->IncludeSystematics(0); // new version of RooUnfold: will compute Cov based on Data Statistics only
        std::cout << "niter = " << i << std::endl;
        hUnfData = (TH1D*) RObjectForDataTmp->Hreco(RooUnfold::kCovariance);
        TString tmpName = "Unf" + name + "_"; 
        tmpName += i; 
        hUnfData->SetName(tmpName);
        hUnfData->SetTitle(tmpName);
        tmpName = "fol" + name + "_"; 
        tmpName += i; 
        TH1D *hfoldUnfData = foldUnfData(hUnfData, resp);
        hfoldUnfData->SetName(tmpName);
        hfoldUnfData->SetTitle(tmpName);
        TH1D *hgen = (TH1D*) resp->Htruth();
        tmpName = "gen" + name + "_";
        tmpName += i;
        hgen->SetName(tmpName);
        hgen->SetTitle(tmpName);
        hgen->Write();
        TH1D *hfoldgen = foldUnfData(hgen, resp);
        tmpName = "folgen" + name + "_";
        tmpName += i;
        hfoldgen->SetName(tmpName);
        hfoldgen->SetTitle(tmpName);
        hfoldgen->Write();
        TH1D *hmes = (TH1D*) resp->Hmeasured();
        tmpName = "mes" + name + "_";
        tmpName += i;
        hmes->SetName(tmpName);
        hmes->SetTitle(tmpName);
        hmes->Write();

        double mychi2 = MyChi2Test(hfoldUnfData, hRecDataMinusFakes, nBinsToSkip);
        hchi2->SetBinContent(i, mychi2);
        if (i==1) hRecDataMinusFakes->Write("Unf" + name + "_0"); 
        hUnfData->Write();
        hfoldUnfData->Write();
        nIter = i;
        if (mychi2 < 1./sqrt(2)) {
            std::cout << "Will use " << nIter << " iterations with a final Chi2/ndf of: " << mychi2 << std::endl;
            break;
        }
    }

    hchi2->Write();
    f->Close();

    std::cout << "\n---------------------------------------------------------------------------------------------------------------\n-" << std::endl;

    //--- Unfold data minus background ---
    RooUnfold *RObjectForData = RooUnfold::New(alg, resp, hRecDataMinusFakes, nIter);
    //RooUnfold *RObjectForData = RooUnfold::New(alg, resp, hRecDataMinusFakes, 3);
    //RObject->SetVerbose(0);

    //--- get the unfolded result ---
    RObjectForData->IncludeSystematics(0); // new version of RooUnfold: will compute Cov based on Data Statistics only
    hUnfData = (TH1D*) RObjectForData->Hreco(RooUnfold::kCovariance);
    hUnfData->SetName("UnfData" + name);
    hUnfData->SetTitle(hRecDataMinusFakes->GetTitle());

    if (algo == "Bayes") {
        //--- get covariance from statistics on Data ---
        hUnfDataStatCov = M2H(RObjectForData->Ereco(RooUnfold::kCovariance)); // new version of RooUnfold   
        hUnfDataStatCov->SetName("UnfDataStatCov" + name);
        hUnfDataStatCov->SetTitle(hRecDataMinusFakes->GetTitle());

        //--- get covariance from MC stat ---
        RooUnfold *RObjectForMC = RooUnfold::New(alg, resp, hRecDataMinusFakes, nIter);
        RObjectForMC->IncludeSystematics(2); // new version of RooUnfold: will compute Cov based on MC Statistics only
        hUnfMCStatCov = M2H(RObjectForMC->Ereco(RooUnfold::kCovariance)); // new version of RooUnfold
        hUnfMCStatCov->SetName("UnfMCStatCov" + name);
        hUnfMCStatCov->SetTitle(hRecDataMinusFakes->GetTitle());
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
}


//--- This is needed because we use overflow and the matrices have 2 additional bins ---
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

    for (int i = 1; i <= nBins; ++i) {
        double sigmaMeani = 0.5*fabs(hUnfDataUp->GetBinContent(i) - hUnfDataDown->GetBinContent(i)); 
        if (name.Index("Sherpa") >= 0) sigmaMeani *= 2;
        int signi = (hUnfDataUp->GetBinContent(i) - hUnfDataDown->GetBinContent(i) < 0) ? -1 : 1;

        for (int j = 1; j <= nBins; ++j) {
            double sigmaMeanj = 0.5*fabs(hUnfDataUp->GetBinContent(j) - hUnfDataDown->GetBinContent(j)); 
            if (name.Index("Sherpa") >= 0) sigmaMeanj *= 2;
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

TH1D* foldUnfData(TH1D *hUnfData, RooUnfoldResponse *hresp)
{
    TH1D *hfoldUnfData = (TH1D*) hUnfData->Clone();
    RooUnfoldResponse *resp = (RooUnfoldResponse*) hresp->Clone();
    TH2D *hres = (TH2D*) resp->Hresponse();
    TH1D *hgen = (TH1D*) resp->Htruth();


    int nBins = hfoldUnfData->GetNbinsX();

    for (int i = 0; i <= nBins; ++i) {
        double totGen = hgen->GetBinContent(i);
        for (int j = 0; j <= nBins; ++j) {
            if (totGen != 0.0) {
                hres->SetBinContent(j, i, hres->GetBinContent(j, i)/totGen);
                hres->SetBinError(j, i, hres->GetBinError(j, i)/totGen);
            }
            else {
                hres->SetBinContent(i, j, 0);
                hres->SetBinError(i, j, hres->GetBinError(i, j));
            }
        }
    }

    for (int i = 0; i <= nBins; ++i) {
        double sum = 0.0;
        double error2 = 0.0;
        for (int j = 0; j <= nBins; ++j) {
            sum += hres->GetBinContent(i, j) * hUnfData->GetBinContent(j);
            error2 += pow(hres->GetBinContent(i, j) * hUnfData->GetBinError(j), 2);
        }
        hfoldUnfData->SetBinContent(i, sum);
        hfoldUnfData->SetBinError(i, sqrt(error2));
    }
    return hfoldUnfData;
}


void test()
{
    TH1D *hreco = new TH1D("hreco", "hreco", 2, 0, 2);
    TH1D *hgen = new TH1D("hgen", "hgen", 2, 0, 2);
    TH2D *hresp = new TH2D("hresp", "hresp", 2, 0, 2, 2, 0, 2);

    hreco->Sumw2();
    hgen->Sumw2();
    hresp->Sumw2();

    hreco->Fill(0.5, 3.5);
    hreco->Fill(1.5, 5);

    hgen->Fill(0.5, 4);
    hgen->Fill(1.5, 6);

    hresp->Fill(0.5, 0.5, 3);
    hresp->Fill(0.5,1.5,0.5);
    hresp->Fill(1.5,0.5,0.5);
    hresp->Fill(1.5,1.5,4.5);

    RooUnfoldResponse *resp = new RooUnfoldResponse(NULL, hgen, hresp);

    RooUnfold *RObjectForData = RooUnfold::New(RooUnfold::kBayes, resp, hreco, 3);
    TH1D *hUnfData = (TH1D*) RObjectForData->Hreco(RooUnfold::kCovariance);

    TH1D *hfoldUnfData = foldUnfData(hUnfData, resp);

    std::cout << "reco: " << hreco->GetBinContent(1) << "   " << hreco->GetBinContent(2) << std::endl; 
    std::cout << "gen : " << hgen->GetBinContent(1) << "   " << hgen->GetBinContent(2) << std::endl; 
    std::cout << "unf : " << hUnfData->GetBinContent(1) << "   " << hUnfData->GetBinContent(2) << std::endl; 
    std::cout << "fol : " << hfoldUnfData->GetBinContent(1) << "   " << hfoldUnfData->GetBinContent(2) << std::endl; 



}

double MyChi2Test(TH1D *h1, TH1D *h2, int nBinsToSkip)
{
    TH1D *h1Copy = (TH1D*) h1->Clone();
    TH1D *h2Copy = (TH1D*) h2->Clone();

    for (int i = 0; i <= nBinsToSkip; ++i) {
        h1Copy->SetBinContent(i, 0.0);
        h2Copy->SetBinContent(i, 0.0);
    }
    return h1Copy->Chi2Test(h2Copy, "WW,P,CHI2/NDF");

}
