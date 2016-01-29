#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <TH1.h>
#include <TGraphAsymmErrors.h>
#include <TFile.h>
#include <math.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TLatex.h>
#include <TROOT.h>
#include "tdrstyle.C"
using namespace std;

void CalculatePDFunc(){
    TFile* file = new TFile("FirstJetPtPDFReweight.root");

    vector<vector<double>> bincont;
    vector<double> media;
    vector<double> avebin;
    vector<double> rms;
    int nBins = 0;

    TH1D* ratio = new TH1D();
    ofstream counter("summary.txt",ios::out);

    for(int index(0); index<100; index++){
        TH1D *histo = new TH1D();
        cout << "Start to loop on number " << (index+1) << " histogram ..." << endl;
        stringstream pdfHistName("");
        pdfHistName << "FirstJetPt_Zinc1jet_" << (index+1);
        file->GetObject(pdfHistName.str().c_str(),histo);
        ratio = (TH1D*)histo->Clone();

        nBins = histo->GetNbinsX();
        cout << "This variable contains " << nBins << "bins..." << endl;

        if(index == 0){
            for(int ibin=1; ibin<=nBins; ibin++){
                avebin.push_back(0);
                rms.push_back(0);
                media.push_back(0);
            }
            cout << "finish initialize the vector..." << endl;
        }

        // --- initialize the vector with another mediate empty vector ---

        for(int ibin=1; ibin<=nBins; ibin++){
            double number = histo->GetBinContent(ibin);
            media[ibin-1] = number;
            avebin[ibin-1] += number;
        }

        bincont.push_back(media);

    }

    cout << "finish looping on all the files!" << endl;

    counter << "PDF average and RMS of leading jet pt" << endl << endl;
    for(int i=1; i<=nBins; i++){
        double ave = avebin[i-1]/100.0;
        double temp = 0;
        for(int j=0;j<100;j++){
            temp += pow(bincont[j][i-1]-ave,2);
        }
        rms[i-1] = sqrt(1.0/99.0*temp);
        ratio->SetBinContent(i,ave);
        ratio->SetBinError(i,rms[i-1]);
        counter << "Bin " << i << " " << "content is: " << ave << " ; " << "RMS is: " << rms[i-1] << " ; " << "PDF Unc: " << rms[i-1]/ave << endl; 
    }

    TH1D *xsec = (TH1D*)ratio->Clone();
    for (int k = 1; k <= nBins; ++k) {
        xsec->SetBinContent(k, xsec->GetBinError(k)/xsec->GetBinContent(k));
        xsec->SetBinError(k, 0);
    }

    ///////////////////////Latex and legend definition////////////////////////
    gROOT->ProcessLine(".L tdrstyle.C");
    setTDRStyle();

    TLegend *leg1 = new TLegend(0.65,0.86,0.95,0.93);

    leg1->SetFillColor(kWhite);

    TLatex *tex1 = new TLatex(0.20,0.96,"2012, 8TeV");
    TLatex *tex2 = new TLatex(0.20,0.86,"CMS");
    TLatex *tex3 = new TLatex(0.20,0.81,"Prediction");	

    tex1->SetNDC();
    tex2->SetNDC();
    tex3->SetNDC();

    tex1->SetTextFont(22);
    tex2->SetTextFont(62);
    tex3->SetTextFont(52);

    tex1->SetTextSize(0.04);
    tex2->SetTextSize(0.04);
    tex3->SetTextSize(0.04);

    /////////////Drawing configurations for matching RecoJets//////////////////////////
    TCanvas *c1 = new TCanvas("c1","c1",1000,800);
    xsec->SetMinimum(0);
    xsec->SetMaximum(1);

    xsec->SetLineColor(kBlue);
    xsec->SetMarkerStyle(20);

    xsec->SetLineWidth(4);
    xsec->SetMarkerSize(0.1);

    leg1->AddEntry(xsec,"MG5_aMC@NLO","L");

    xsec->Draw();
    xsec->GetXaxis()->SetTitle("p_{T}^{j1} [GeV]");
    xsec->GetYaxis()->SetTitle("Relative PDF uncertainty");
    xsec->GetYaxis()->SetTitleOffset(1.25);
    leg1->Draw("same");
    tex1->Draw("same");
    tex2->Draw("same");
    tex3->Draw("same");
    c1->SaveAs("PDFUncVSXsec.pdf");

    TFile* newfile = new TFile("outputPDFunc.root","RECREATE");
    ratio->Write();
    xsec->Write();
    newfile->Close();
    counter.close();
    cout << "Finish!" << endl;
}
