#include <iostream>
#include <thread>
#include <TString.h>
#include "ArgParser.h"
#include "ConfigVJets.h"
#include "MiniBonzai.h"

int main(int argc, char **argv)
{
    //--- Load configuration ---
    ConfigVJets cfg;
    //-----------------------------------------------------------------------

    //--- Settings ---
    // doWhat = "DATA", "BACKGROUND", "TAU", "DYJETS", 
    //          "WJETS", "ALL", "PDF", "SHERPA"

    TString bonzaiDir  = cfg.getS("bonzaiDir");
    TString outDir     = cfg.getS("outDir", "MiniBonzaiTuples");
    TString lepSel     = cfg.getS("lepSel", "DMu");
    TString doWhat     = cfg.getS("doWhat", "DYJETS");
    int lepPtMin       = cfg.getI("lepPtMin", 20);
    int lepEtaMax      = cfg.getI("lepEtaMax", 25);
    int jetPtMin       = cfg.getI("jetPtMin", 30);
    int jetEtaMax      = cfg.getI("jetEtaMax", 25);
    Long_t nMaxEvents  = cfg.getL("nMaxEvents", -1);
    double muR         = cfg.getD("muR", 0);
    double muF         = cfg.getD("muF", 0);

    //--- save config to .vjets.cfg ---
    cfg.writeConfigVJets(".vjets.cfg");
    //----------------------------------------------------------------------

    //--- Parse the arguments -----------------------------------------------------
    if (argc > 1) {
        for (int i = 1; i < argc; ++i) {
            TString currentArg = argv[i];
            //--- possible options ---
            if (currentArg.BeginsWith("bonzaiDir=")) {
                getArg(currentArg, bonzaiDir);
            }
            else if (currentArg.BeginsWith("outDir=")) {
                getArg(currentArg, outDir);
            }
            else if (currentArg.BeginsWith("lepSel=")) {
                getArg(currentArg, lepSel);
            }
            else if (currentArg.BeginsWith("doWhat=")) {
                getArg(currentArg, doWhat);
            }
            else if (currentArg.BeginsWith("lepPtMin=")) {
                getArg(currentArg, lepPtMin);
            }
            else if (currentArg.BeginsWith("lepEtaMax=")) {
                getArg(currentArg, lepEtaMax);
            }
            else if (currentArg.BeginsWith("jetPtMin=")) {
                getArg(currentArg, jetPtMin);
            }
            else if (currentArg.BeginsWith("jetEtaMax=")) {
                getArg(currentArg, jetEtaMax);
            }
            else if (currentArg.BeginsWith("nMaxEvents=")) {
                getArg(currentArg, nMaxEvents);
            }
            else if (currentArg.BeginsWith("muR=")) {
                getArg(currentArg, muR);
            }
            else if (currentArg.BeginsWith("muF=")) {
                getArg(currentArg, muF);
            }
            //--- asking for help ---
            else if (currentArg.Contains("help") || currentArg.BeginsWith("-h")) {
                std::cout << "\nUsage: ./runMiniBonzai [bonzaiDir=(path)] [outDir=(path)] [lepSel=(DMu, DE)] [lepPtMin=(int)] [lepEtaMax=(int*10)] [jetPtMin=(int)] [jetEtaMax=(int*10)] [nMaxEvents=-1|N] ";
                std::cout << "[doWhat=(sample)] [--help]" << std::endl;
                std::cout << "eg: ./runMiniBonzai lepSel=DMu jetEtaMax=25" << std::endl;
                std::cout << "unspecified options will be read from vjets.cfg\n" << std::endl;
                return 0;
            }
            //--- bad option ---
            else {
                std::cerr << "Warning: unknown option \"" << currentArg << "\"" << std::endl;
                std::cerr << "Please issue ./runMiniBonzai --help for more information on possible options" << std::endl;
                return 0;
            }
        }
    }

    if (!outDir.EndsWith("/")) outDir += "/";
    doWhat.ToUpper();

    //-----------------------------------------------------------------------------

    //--- Internal configuration ---

    double lumi; 
    if      (lepSel == "DE")  lumi = 19.618;
    else if (lepSel == "DMu") lumi = 19.584;

    bool hasRecoInfo(true);
    bool hasGenInfo(true);

    //----------------------------------------------------------------------
    //
    if (doWhat == "DATA") {
        hasRecoInfo = true;
        hasGenInfo = false;
        MiniBonzai Data(lepSel + "_8TeV_Data_dR", 1, 1, lepPtMin, lepEtaMax, jetPtMin, jetEtaMax, nMaxEvents, outDir, bonzaiDir);
        Data.Loop(hasRecoInfo, hasGenInfo);
    }

    if (doWhat == "DYJETS") {
        hasRecoInfo = true; 
        hasGenInfo = true;

        MiniBonzai DYMix(lepSel + "_8TeV_DYJetsToLL_MIX_50toInf_UNFOLDING_dR", lumi*3531.8*1000/30459503., 1, lepPtMin, lepEtaMax, jetPtMin, jetEtaMax, nMaxEvents, outDir, bonzaiDir);
        DYMix.Loop(hasRecoInfo, hasGenInfo);
    }

    if (doWhat == "SHERPA") {
        MiniBonzai DYShe(lepSel + "_8TeV_DYJets_Sherpa_Bugra_1_13_UNFOLDING_dR", lumi*3531.8*1000, 1, lepPtMin, lepEtaMax, jetPtMin, jetEtaMax, nMaxEvents, outDir, bonzaiDir);
        DYShe.Loop(1, 1);
    }

    if (doWhat == "AMCATNLO") {
        MiniBonzai DYNLO(lepSel + "_8TeV_DYJetsToLL_M-50_TuneCUETP8M1_8TeV-amcatnloFXFX-Bonzai_fixed_allWeights_dR", lumi*3531.8*1000, 1, lepPtMin, lepEtaMax, jetPtMin, jetEtaMax, nMaxEvents, outDir, bonzaiDir);
        DYNLO.Loop(0, 1);
    }

    if (doWhat == "PDF") {
        MiniBonzai DYNLOPDF(lepSel + "_8TeV_DYJetsToLL_M-50_TuneCUETP8M1_8TeV-amcatnloFXFX-Bonzai_fixed_allWeights_dR", lumi*3531.8*1000., 1, lepPtMin, lepEtaMax, jetPtMin, jetEtaMax, nMaxEvents, outDir, bonzaiDir);
        DYNLOPDF.Loop(0, 1);
    }

    //---------------------------------------------------------------------

    return 0;
}
