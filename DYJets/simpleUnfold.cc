#include <iostream>
#include <TRandom.h>
#include <RooUnfoldResponse.h>
#include <RooUnfoldBayes.h>
#include <RooUnfoldSvd.h>
#include <RooUnfoldInvert.h>
#include <RooUnfoldBinByBin.h>
#include <TFile.h>
#include <TCanvas.h>
#include <TH1.h>
#include <TH2.h>
#include <vector>
#include <string>

void simpleUnfold()
{  
    cout << " in simpleUnfold " << endl;                                                                                                
    TFile *fout = new TFile("SimpleUnfold.root", "RECREATE");

    //string variable = "ZNGoodJets_Zexc";
    string variable = "FirstJetPt_Zinc1jet";
    //string variable = "SecondJetPt_2_Zinc2jet";
    //string variable = "JetsMass_Zinc2jet";
    string genVariable = "gen" + variable; 
    string respVariable = "response" + variable;        
    string hrespVariable = "hresponse" + variable;        
    TFile *dataFile = new TFile("HistoFilesAugust/DMu_8TeV_Data_dR_EffiCorr_0_TrigCorr_1_Syst_0_JetPtMin_30.root");         
    //TFile *dataFile = new TFile("HistoFiles/DMu_8TeV_Data_dR_EffiCorr_1_TrigCorr_1_Syst_0_JetPtMin_30_VarWidth.root");         
    //TFile *dataFile = new TFile("HistoFiles/DMu_8TeV_Data_dR_EffiCorr_1_TrigCorr_1_Syst_2_Down_JetPtMin_30_VarWidth.root");         
    TH1D *dataHist = (TH1D*) dataFile->Get(variable.c_str());           

    //TFile *dyFile = new TFile("HistoFiles/DMu_8TeV_DYJetsToLL_50toInf_UNFOLDING_dR_EffiCorr_0_TrigCorr_1_Syst_0_JetPtMin_30_VarWidth.root");
    TFile *dyFile = new TFile("HistoFilesAugust/DMu_8TeV_DYJetsToLL_MIX_50toInf_UNFOLDING_dR_EffiCorr_1_TrigCorr_1_Syst_0_JetPtMin_30.root");
    //TFile *dyFile = new TFile("HistoFilesAugustNoSF/DMu_8TeV_DYJetsToLL_MIX_50toInf_UNFOLDING_dR_EffiCorr_1_TrigCorr_1_Syst_0_JetPtMin_30.root");
    //TFile *dyFile = new TFile("TEST.root");
    if (!dyFile) cout << "Problem with DY file" << endl;
    TH1D *genHist = (TH1D*) dyFile->Get(genVariable.c_str());           
    TH1D *mcHist = (TH1D*) dyFile->Get(variable.c_str());           
    TH2D *hresp = (TH2D*) dyFile->Get(hrespVariable.c_str());
    //RooUnfoldResponse *dyResp = (RooUnfoldResponse*) dyFile->Get(respVariable.c_str());
    RooUnfoldResponse *dyResp = new RooUnfoldResponse(mcHist, genHist, hresp);
    dyResp->UseOverflow();

    vector<string> bg;                                                                                                                  
    bg.push_back("HistoFilesAugust/DMu_8TeV_ZZJets2L2Nu_dR_EffiCorr_1_TrigCorr_1_Syst_0_JetPtMin_30.root");
    bg.push_back("HistoFilesAugust/DMu_8TeV_ZZJets2L2Q_dR_EffiCorr_1_TrigCorr_1_Syst_0_JetPtMin_30.root"); 
    bg.push_back("HistoFilesAugust/DMu_8TeV_ZZJets4L_dR_EffiCorr_1_TrigCorr_1_Syst_0_JetPtMin_30.root");   
    bg.push_back("HistoFilesAugust/DMu_8TeV_WWJets2L2Nu_dR_EffiCorr_1_TrigCorr_1_Syst_0_JetPtMin_30.root");                 
    bg.push_back("HistoFilesAugust/DMu_8TeV_WZJets2L2Q_dR_EffiCorr_1_TrigCorr_1_Syst_0_JetPtMin_30.root");                  
    bg.push_back("HistoFilesAugust/DMu_8TeV_WZJets3LNu_dR_EffiCorr_1_TrigCorr_1_Syst_0_JetPtMin_30.root"); 
    bg.push_back("HistoFilesAugust/DMu_8TeV_TTJets_dR_EffiCorr_1_TrigCorr_1_Syst_0_JetPtMin_30.root");     
    bg.push_back("HistoFilesAugust/DMu_8TeV_Top_dR_EffiCorr_1_TrigCorr_1_Syst_0_JetPtMin_30.root");        
    bg.push_back("HistoFilesAugust/DMu_8TeV_WJetsALL_MIX_UNFOLDING_dR_EffiCorr_0_TrigCorr_1_Syst_0_JetPtMin_30.root");      

    cout << "OK" << endl;


    int nBg = bg.size();           

    TH1D *bgHist = NULL;

    for (int i = 0; i < nBg; i++) {
        TFile *bgFile = new TFile(bg[i].c_str());       
        TH1D *tmp = (TH1D*) bgFile->Get(variable.c_str());              
        if (i == 0) {                                                                                                                   
            bgHist = (TH1D*) tmp->Clone();                                                                                              
            bgHist->SetDirectory(0);
        }                                                                                                                               
        else {
            bgHist->Add(tmp);      
        }
        bgFile->Close();                                                                                                                
    }

    cout << "OK" << endl;
    //bgHist->Draw("text");
    //dataHist->DrawCopy("text");     
    dataHist->Add(bgHist, -1);     
    cout << "OK" << endl;

    RooUnfoldBayes *unfold = new RooUnfoldBayes(dyResp, dataHist, 9);
    //RooUnfoldSvd *unfold = new RooUnfoldSvd(dyResp, dataHist, 6);
    //RooUnfoldInvert *unfold = new RooUnfoldInvert(dyResp, dataHist);
    //RooUnfoldBinByBin *unfold = new RooUnfoldBinByBin(dyResp, dataHist);
    cout << "OK" << endl;
    TH1D *dataUnfolded = (TH1D*) unfold->Hreco();       
    TH1D *chi2 = (TH1D*) unfold->Chi2OfChange;
    //chi2->Draw();
    cout << "OK" << endl;

    //TH1D *h00 = new TH1D("h00", "h00", 100, 6000000, 16000000);
    //TH1D *h01 = new TH1D("h01", "h01", 100, -1000000, 1000000);
    //TH1D *h02 = new TH1D("h02", "h02", 100, -1000000, 1000000);
    //TH1D *h11 = new TH1D("h11", "h11", 100, 1000000, 6000000);
    //TH1D *h12 = new TH1D("h12", "h12", 100, -1000000, 1000000);
    //TH1D *h22 = new TH1D("h22", "h22", 100, 100000, 1000000);

    //for (int i(0); i < 1000; i++) { 
    //    RooUnfoldBayes *unfoldToy = new RooUnfoldBayes(dyResp, dataHist, 4);
    //    unfoldToy->SetNToys(1000);
    //    unfoldToy->SetVerbose(0);

    //    TH2D *covToy = new TH2D(unfoldToy->Ereco(RooUnfold::kCovToy));
    //    h00->Fill(covToy->GetBinContent(2,2));
    //    h01->Fill(covToy->GetBinContent(2,3));
    //    h02->Fill(covToy->GetBinContent(2,4));
    //    h11->Fill(covToy->GetBinContent(3,3));
    //    h12->Fill(covToy->GetBinContent(3,4));
    //    h22->Fill(covToy->GetBinContent(4,4));
    //}
    //TCanvas *c = new TCanvas();
    //fout->cd();
    //h00->Write();
    //h01->Write();
    //h02->Write();
    //h11->Write();
    //h12->Write();
    //h22->Write();


    dataUnfolded->Scale(1./19618.);
    genHist->Scale(1./19618.);
    //genHist->Divide(dataUnfolded);
    //mcHist->Divide(dataHist);
    cout << "OK" << endl;
    //dataUnfolded->Draw();    
    //genHist->Draw();    
    //mcHist->Draw("same");    

    int nBins = dataUnfolded->GetNbinsX();
    cout << endl;
    for (int i(1); i <= nBins; i++) {
        cout << " --- " << dataUnfolded->GetBinContent(i)*1.0 <<  "  "  << dataUnfolded->GetBinError(i)*1.0/dataUnfolded->GetBinWidth(i) << endl;
        cout << dataUnfolded->GetBinContent(i)*1.0/dataUnfolded->GetBinWidth(i) <<  "  "  << dataUnfolded->GetBinError(i)*1.0/dataUnfolded->GetBinWidth(i) << endl;
    }
    cout << endl;
    fout->Close();

}  
