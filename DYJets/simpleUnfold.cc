
#include <iostream>
#include <RooUnfoldResponse.h>
#include <RooUnfoldBayes.h>
#include <TFile.h>
#include <TH1.h>
#include <vector>
#include <string>
 
void simpleUnfold()
{  
    cout << " in simpleUnfold " << endl;                                                                                                
    string variable = "ZNGoodJets_Zexc";
    string genVariable = "gen" + variable; 
    string respVariable = "response" + variable;        
    string ntupleDir ="HistoFilesTest";    
    TFile *dataFile = new TFile("HistoFilesTest/DE_8TeV_Data_dR_5311_EffiCorr_1_TrigCorr_1_Syst_0_JetPtMin_30_VarWidth.root");         
    TH1D *dataHist = (TH1D*) dataFile->Get(variable.c_str());           
                                                                                                                                        
    TFile *dyFile = new TFile("HistoFilesTest/DE_8TeV_DYJets_UNFOLDING_dR_5311_Inf3_EffiCorr_0_TrigCorr_1_Syst_0_JetPtMin_30_VarWidth.root");
    //TFile *dyFile = new TFile("HistoFilesTest/DE_8TeV_DYJets_MIX_UNFOLDING_dR_5311_Inf3_EffiCorr_0_TrigCorr_1_Syst_0_JetPtMin_30_VarWidth_SRANJE3.root");
    RooUnfoldResponse *dyResp = (RooUnfoldResponse*) dyFile->Get(respVariable.c_str());
    dyResp->UseOverflow();
   
    vector<string> bg;                                                                                                                  
    bg.push_back("HistoFilesTest/DE_8TeV_ZZJets2L2Nu_dR_5311_EffiCorr_0_TrigCorr_1_Syst_0_JetPtMin_30_VarWidth.root");
    bg.push_back("HistoFilesTest/DE_8TeV_ZZJets2L2Q_dR_5311_EffiCorr_0_TrigCorr_1_Syst_0_JetPtMin_30_VarWidth.root"); 
    bg.push_back("HistoFilesTest/DE_8TeV_ZZJets4L_dR_5311_EffiCorr_0_TrigCorr_1_Syst_0_JetPtMin_30_VarWidth.root");   
    bg.push_back("HistoFilesTest/DE_8TeV_WWJets2L2Nu_dR_5311_EffiCorr_0_TrigCorr_1_Syst_0_JetPtMin_30_VarWidth.root");                 
    bg.push_back("HistoFilesTest/DE_8TeV_WZJets2L2Q_dR_5311_EffiCorr_0_TrigCorr_1_Syst_0_JetPtMin_30_VarWidth.root");                  
    bg.push_back("HistoFilesTest/DE_8TeV_WZJets3LNu_dR_5311_EffiCorr_0_TrigCorr_1_Syst_0_JetPtMin_30_VarWidth.root"); 
    bg.push_back("HistoFilesTest/DE_8TeV_TTJets_dR_5311_EffiCorr_0_TrigCorr_1_Syst_0_JetPtMin_30_VarWidth.root");     
    bg.push_back("HistoFilesTest/DE_8TeV_Top_dR_5311_EffiCorr_0_TrigCorr_1_Syst_0_JetPtMin_30_VarWidth.root");        
    bg.push_back("HistoFilesTest/DE_8TeV_WJetsALL_MIX_UNFOLDING_dR_5311_EffiCorr_0_TrigCorr_1_Syst_0_JetPtMin_30_VarWidth.root");      
   
   
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
   
    bgHist->Draw("text");
    dataHist->Add(bgHist, -1);     
   
    RooUnfoldBayes *unfold = new RooUnfoldBayes(dyResp, dataHist, 3);   
    TH1D *dataUnfolded = (TH1D*) unfold->Hreco();       
    dataUnfolded->Scale(1./19602.);
    dataUnfolded->Draw("text");    
   

}  
