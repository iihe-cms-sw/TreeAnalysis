#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <TH1.h>
#include <TGraphAsymmErrors.h>
#include <TFile.h>
#include <math.h>

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

    //TH1D *histo = (TH1D*)file->Get("FirstJetPt_Zinc1jet");
    for(int index(0); index<100; index++){
        TH1D *histo = new TH1D();
        cout << "Start to loop on number " << (index+1) << " histogram ..." << endl;
        stringstream pdfHistName("");
        pdfHistName << "FirstJetPt_Zinc1jet;" << (index+1);
        //TFile *file = new TFile(pdfFileName.str().c_str());
        //TH1D *histo = (TH1D*)file->Get("genFirstJetPt_Zinc1jet");
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

    //    ratio->Reset();

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

    TFile* newfile = new TFile("outputPDFunc.root","RECREATE");
    ratio->Write();
    newfile->Close();
    counter.close();
    cout << "Finish!" << endl;
}
