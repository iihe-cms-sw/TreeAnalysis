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
    //string variable = "FirstJetPt_2_Zinc1jet";
    //string variable = "SecondJetPt_2_Zinc2jet";
    string genVariable = "gen" + variable; 
    string respVariable = "response" + variable;        
    TFile *dataFile = new TFile("HistoFiles/DMu_8TeV_Data_dR_EffiCorr_1_TrigCorr_1_Syst_0_JetPtMin_30_VarWidth.root");         
    //TFile *dataFile = new TFile("HistoFiles/DMu_8TeV_Data_dR_EffiCorr_1_TrigCorr_1_Syst_2_Down_JetPtMin_30_VarWidth.root");         
    TH1D *dataHist = (TH1D*) dataFile->Get(variable.c_str());           

    //TFile *dyFile = new TFile("HistoFiles/DMu_8TeV_DYJetsToLL_50toInf_UNFOLDING_dR_EffiCorr_0_TrigCorr_1_Syst_0_JetPtMin_30_VarWidth.root");
    TFile *dyFile = new TFile("HistoFiles/DMu_8TeV_DYJetsToLL_MIX_50toInf_UNFOLDING_dR_EffiCorr_0_TrigCorr_1_Syst_0_JetPtMin_30_VarWidth.root");
    if (!dyFile) cout << "Problem with DY file" << endl;
    RooUnfoldResponse *dyResp = (RooUnfoldResponse*) dyFile->Get(respVariable.c_str());
    dyResp->UseOverflow();

    vector<string> bg;                                                                                                                  
    bg.push_back("HistoFiles/DMu_8TeV_ZZJets2L2Nu_dR_EffiCorr_0_TrigCorr_1_Syst_0_JetPtMin_30_VarWidth.root");
    bg.push_back("HistoFiles/DMu_8TeV_ZZJets2L2Q_dR_EffiCorr_0_TrigCorr_1_Syst_0_JetPtMin_30_VarWidth.root"); 
    bg.push_back("HistoFiles/DMu_8TeV_ZZJets4L_dR_EffiCorr_0_TrigCorr_1_Syst_0_JetPtMin_30_VarWidth.root");   
    bg.push_back("HistoFiles/DMu_8TeV_WWJets2L2Nu_dR_EffiCorr_0_TrigCorr_1_Syst_0_JetPtMin_30_VarWidth.root");                 
    bg.push_back("HistoFiles/DMu_8TeV_WZJets2L2Q_dR_EffiCorr_0_TrigCorr_1_Syst_0_JetPtMin_30_VarWidth.root");                  
    bg.push_back("HistoFiles/DMu_8TeV_WZJets3LNu_dR_EffiCorr_0_TrigCorr_1_Syst_0_JetPtMin_30_VarWidth.root"); 
    bg.push_back("HistoFiles/DMu_8TeV_TTJets_dR_EffiCorr_0_TrigCorr_1_Syst_0_JetPtMin_30_VarWidth.root");     
    bg.push_back("HistoFiles/DMu_8TeV_Top_dR_EffiCorr_0_TrigCorr_1_Syst_0_JetPtMin_30_VarWidth.root");        
    bg.push_back("HistoFiles/DMu_8TeV_WJetsALL_MIX_UNFOLDING_dR_EffiCorr_0_TrigCorr_1_Syst_0_JetPtMin_30_VarWidth.root");      


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

    RooUnfoldBayes *unfold = new RooUnfoldBayes(dyResp, dataHist, 4);
    TH1D *dataUnfolded = (TH1D*) unfold->Hreco();       
    dataUnfolded->Scale(1./19584.);
    dataUnfolded->Draw("text");    

    int nBins = dataUnfolded->GetNbinsX();
    cout << endl;
    for (int i(1); i <= nBins; i++) {
        cout << dataUnfolded->GetBinContent(i)*1.0/dataUnfolded->GetBinWidth(i) <<  "  "  << dataUnfolded->GetBinError(i)*1.0/dataUnfolded->GetBinWidth(i) << endl;
    }
    cout << endl;

}  
