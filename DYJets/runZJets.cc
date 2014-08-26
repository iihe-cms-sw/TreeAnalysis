#include <iostream>
#include <TString.h>
#include "ConfigVJets.h"
#include "MergeTop.h"
#include "ZJets.h"

int main(int argc, char **argv)
{
    //--- Load configuration ---
    ConfigVJets cfg;
    //-----------------------------------------------------------------------

    //--- Settings ---
    // doWhat = "DATA", "BACKGROUND", "TAU", "DYJETS", 
    //          "WJETS", "ALL", "PDF", "SHERPA"

    TString outDir     = cfg.getS("outDir", "HistoFilesAugust");
    TString lepSel     = cfg.getS("lepSel", "DMu");
    TString doWhat     = cfg.getS("doWhat", "DYJETS");
    int jetPtMin       = cfg.getF("jetPtMin", 30);
    int jetEtaMax      = cfg.getF("jetEtaMax", 24);
    bool doSysRunning  = cfg.getB("doSysRunning", 0);
    bool doCentral     = cfg.getB("doCentral", 1);
    bool do10000Events = cfg.getB("do10000Events", 1);

    //--- save config to .vjets.cfg ---
    cfg.writeConfigVJets(".vjets.cfg");
    //----------------------------------------------------------------------


    //--- Internal configuration ---
    if (!outDir.EndsWith("/")) outDir += "/";
    doWhat.ToUpper();

    double lumi; 
    if      (lepSel == "DE")  lumi = 19.618;
    else if (lepSel == "DMu") lumi = 19.584;

    bool hasRecoInfo(true);
    bool hasGenInfo(true);

    int NSystData(3);
    int NSystMC(5);

    short dataSyst[5] = {0, 2, 2, 5, 5};
    short dataDir[5]  = {0,-1, 1,-1, 1};

    short ttSyst[5]  = {0, 1, 1, 3, 3};
    short ttDir[5]   = {0,-1, 1,-1, 1};
    float ttScale[5] = {1, 1, 1, 0.10, 0.10};

    short tauSyst[5]  = {0, 1, 1, 3, 3};
    short tauDir[5]   = {0,-1, 1,-1, 1};
    float tauScale[5] = {1, 1, 1, 0.05, 0.05};

    short wjSyst[5]  = {0, 1, 1, 3, 3};
    short wjDir[5]   = {0,-1, 1,-1, 1};
    float wjScale[5] = {1, 1, 1, 0.04, 0.04};

    short bgSyst[5]  = {0, 1, 1, 3, 3};
    short bgDir[5]   = {0,-1, 1,-1, 1};
    float bgScale[5] = {1, 1, 1, 0.15, 0.15};

    short dySyst[5]  = {0, 1, 1, 4, 4};
    short dyDir[5]   = {0,-1, 1,-1, 1};

    if (!doSysRunning) {
        NSystData = 1; 
        NSystMC = 1;
    }
    //----------------------------------------------------------------------
   

    //--- starting the real processing -------------------------------------
    cout << __DATE__ << " at " << __TIME__ << endl;

    if (doWhat == "DATA" || doWhat == "ALL") {
        hasRecoInfo = true;
        hasGenInfo = false;
        for (unsigned int i(0); i < NSystData; i++) {
            if (i == 0 && !doCentral) continue;
            ZJets DMudata(lepSel + "_8TeV_Data_dR", 1, 1, dataSyst[i], dataDir[i], 1, jetPtMin, jetEtaMax, do10000Events, outDir);
            DMudata.Loop(hasRecoInfo, hasGenInfo);
        }
    }

    if (doWhat == "BACKGROUND" || doWhat == "ALL") {
        hasRecoInfo = true;
        hasGenInfo = false;

        for (unsigned int i(0); i < NSystMC; i++) { 
            if (i == 0 && !doCentral) continue;

            ZJets ZZInc(lepSel + "_8TeV_ZZ_dR",              lumi*17.654        *1000/9799908.,  1, bgSyst[i], bgDir[i], bgScale[i], jetPtMin, jetEtaMax, do10000Events, outDir);
            ZZInc.Loop(hasRecoInfo, hasGenInfo);
            ZJets WZInc(lepSel + "_8TeV_WZ_dR",              lumi*33.21         *1000/10000283., 1, bgSyst[i], bgDir[i], bgScale[i], jetPtMin, jetEtaMax, do10000Events, outDir);
            WZInc.Loop(hasRecoInfo, hasGenInfo);
            ZJets WWInc(lepSel + "_8TeV_WW_dR",              lumi*54.838        *1000/10000431., 1, bgSyst[i], bgDir[i], bgScale[i], jetPtMin, jetEtaMax, do10000Events, outDir);
            WWInc.Loop(hasRecoInfo, hasGenInfo);
            ZJets ZZ(lepSel + "_8TeV_ZZJets2L2Nu_dR",        lumi*17.654*0.04039 *1000/954911.,  1, bgSyst[i], bgDir[i], bgScale[i], jetPtMin, jetEtaMax, do10000Events, outDir);
            ZZ.Loop(hasRecoInfo, hasGenInfo);
            ZJets WW(lepSel + "_8TeV_WWJets2L2Nu_dR",        lumi*54.838*0.10608 *1000/1933235., 1, bgSyst[i], bgDir[i], bgScale[i], jetPtMin, jetEtaMax, do10000Events, outDir);
            WW.Loop(hasRecoInfo, hasGenInfo);
            ZJets ZZ1(lepSel + "_8TeV_ZZJets2L2Q_dR",        lumi*17.654*0.14118 *1000/1936727., 1, bgSyst[i], bgDir[i], bgScale[i], jetPtMin, jetEtaMax, do10000Events, outDir);
            ZZ1.Loop(hasRecoInfo, hasGenInfo);
            ZJets ZZ2(lepSel + "_8TeV_ZZJets4L_dR",          lumi*17.654*0.010196*1000/4807893., 1, bgSyst[i], bgDir[i], bgScale[i], jetPtMin, jetEtaMax, do10000Events, outDir);
            ZZ2.Loop(hasRecoInfo, hasGenInfo);
            ZJets WZ(lepSel + "_8TeV_WZJets3LNu_dR",         lumi*33.21 *0.032887*1000/2017979., 1, bgSyst[i], bgDir[i], bgScale[i], jetPtMin, jetEtaMax, do10000Events, outDir);
            WZ.Loop(hasRecoInfo, hasGenInfo);
            ZJets WZ1(lepSel + "_8TeV_WZJets2L2Q_dR",        lumi*33.21 *0.068258*1000/3215990., 1, bgSyst[i], bgDir[i], bgScale[i], jetPtMin, jetEtaMax, do10000Events, outDir);
            WZ1.Loop(hasRecoInfo, hasGenInfo);
            ZJets T(lepSel + "_8TeV_T_s_channel_dR",         lumi*3.79           *1000/259961.,  1, bgSyst[i], bgDir[i], bgScale[i], jetPtMin, jetEtaMax, do10000Events, outDir);
            T.Loop(hasRecoInfo, hasGenInfo);
            ZJets T1(lepSel + "_8TeV_T_t_channel_dR",        lumi*56.4           *1000/3747932., 1, bgSyst[i], bgDir[i], bgScale[i], jetPtMin, jetEtaMax, do10000Events, outDir);
            T1.Loop(hasRecoInfo, hasGenInfo);
            ZJets T2(lepSel + "_8TeV_T_tW_channel_dR",       lumi*11.1           *1000/497658.,  1, bgSyst[i], bgDir[i], bgScale[i], jetPtMin, jetEtaMax, do10000Events, outDir);
            T2.Loop(hasRecoInfo, hasGenInfo);
            ZJets Tbar(lepSel + "_8TeV_Tbar_s_channel_dR",   lumi*1.76           *1000/139974.,  1, bgSyst[i], bgDir[i], bgScale[i], jetPtMin, jetEtaMax, do10000Events, outDir);
            Tbar.Loop(hasRecoInfo, hasGenInfo);
            ZJets Tbar1(lepSel + "_8TeV_Tbar_t_channel_dR",  lumi*30.7           *1000/1935072., 1, bgSyst[i], bgDir[i], bgScale[i], jetPtMin, jetEtaMax, do10000Events, outDir);
            Tbar1.Loop(hasRecoInfo, hasGenInfo);
            ZJets Tbar2(lepSel + "_8TeV_Tbar_tW_channel_dR", lumi*11.1           *1000/493460.,  1, bgSyst[i], bgDir[i], bgScale[i], jetPtMin, jetEtaMax, do10000Events, outDir);
            Tbar2.Loop(hasRecoInfo, hasGenInfo);
            ZJets TT(lepSel + "_8TeV_TTJets_dR",             lumi*245.           *1000/6923750., 1, ttSyst[i], ttDir[i], ttScale[i], jetPtMin, jetEtaMax, do10000Events, outDir);
            TT.Loop(hasRecoInfo, hasGenInfo);

            // Additionaly merge the top samples
            runMergeTop(lepSel, bgSyst[i]*bgDir[i], jetPtMin, jetEtaMax, do10000Events, outDir);
        }
    }

    if (doWhat == "TAU" || doWhat == "ALL") {
        hasRecoInfo = true; 
        hasGenInfo = true;

        for (unsigned int i(0); i < NSystMC; i++) { 
            if (i == 0 && !doCentral) continue;
            ZJets DYTau(lepSel + "_8TeV_DYJetsToLL_FromTau_50toInf_UNFOLDING_dR", lumi*3531.8*1000/30459503., 1, tauSyst[i], tauDir[i], tauScale[i], jetPtMin, jetEtaMax, do10000Events, outDir);
            DYTau.Loop(hasRecoInfo, hasGenInfo);
        }
    }

    if (doWhat == "DYJETS" || doWhat == "ALL") {
        hasRecoInfo = true; 
        hasGenInfo = true;

        for (unsigned int i(0); i < NSystMC; i++) { 
            if (i == 0 && !doCentral) continue;
            ZJets DYMix(lepSel + "_8TeV_DYJetsToLL_MIX_50toInf_UNFOLDING_dR", lumi*3531.8*1000/30459503., 1, dySyst[i], dyDir[i], 1, jetPtMin, jetEtaMax, do10000Events, outDir);
            DYMix.Loop(hasRecoInfo, hasGenInfo);
            //ZJets DY(lepSel + "_8TeV_DYJetsToLL_50toInf_UNFOLDING_dR", lumi*3531.8*1000/30459503., 1, dySyst[i], dyDir[i], 1, jetPtMin, jetEtaMax, do10000Events, outDir);
            //DY.Loop(hasRecoInfo, hasGenInfo);
        }
    }

    if (doWhat == "WJETS" || doWhat == "ALL") {
        hasRecoInfo = true; 
        hasGenInfo = false;

        for (unsigned int i(0); i < NSystMC; i++) { 
            if (i == 0 && !doCentral) continue;
            ZJets WJMix(lepSel + "_8TeV_WJetsALL_MIX_UNFOLDING_dR", lumi*36703.         *1000/76102995., 1, wjSyst[i], wjDir[i], wjScale[i], jetPtMin, jetEtaMax, do10000Events, outDir);
            WJMix.Loop(hasRecoInfo, hasGenInfo);
        }
    }

    if (doWhat == "PDF") {
        for (int pdfMember(0); pdfMember <= 0; pdfMember++) {
            ZJets DYMixPDF(lepSel + "_8TeV_DYJetsToLL_MIX_50toInf_UNFOLDING_dR", lumi*3531.8*1000/30459503., 1, 0, 0, 1, jetPtMin, jetEtaMax, do10000Events, outDir);
            //DYMixPDF.Loop(0, 1, "CT10.LHgrid", pdfMember);
            DYMixPDF.Loop(0, 1, "MSTW2008nlo68cl.LHgrid", pdfMember);
        }
    }

    cout << __DATE__ << " at " << __TIME__ << endl;
    //---------------------------------------------------------------------
    
    return 0;
}
