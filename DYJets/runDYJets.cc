{
    string start = __TIME__;
    //----------------------------------------------------------//
    // Configuration of the job  //
    //--------------------------//

    //--- user config: change the settings here ---
    string lep = "DE"; 

    bool doRoch    = 0;
    bool doFlat    = 0;
    bool doBJets   = 0;
    int doQCD      = 0;
    int doPUStudy  = -10 ; // default int the ZJets
    bool doSSign   = 0;   // contribution of QCD to emu in TTbar 
    int jetPtMin   = 30;
    int jetPtMax   = 0;
    int ZEtaMin    = -999999; // factor 100 to keep things integer: eta 2.4 => 240 
    int ZEtaMax    = 999999; 
    bool doMassCut = 0; 
    bool doDataEff = 1;
    int NSystData  = 3;
    int NSystMC    = 5;
    int NSystTau   = 5;
    bool doSyst    = 1;
    int doWhat     = 100 ; // 0 - data, 1 - background , 2 - tau ???, 3 - DY, 4 - W+jets, 51 - MC gen
    //----------------------------------------------------------//



    //--- list of the different source files needed ---
    string srcdir = "Sources/";
    vector<string> sources;
    sources.push_back("getFilesAndHistograms");
    sources.push_back("functions");
    sources.push_back("HistoSet");
    sources.push_back("ZJetsAndDPS");

    //--- Load shaared libraries ---
    unsigned int nSources = sources.size();
    for (unsigned int i(0); i < nSources; i++){
        cout <<"Compiling " << srcdir + sources[i] << ".cc" << endl;
        gROOT->ProcessLine(string(".L " + srcdir + sources[i] + ".cc++").c_str());
        //gROOT->LoadMacro(string(srcdir + sources[i] + ".cc+").c_str());
    }
    //----------------------------------------------------------//

    //--- set the lumi according to the selected sample ---
    double  lumi = 0.0;
    if      (lep.find("MuE") == 0)  lumi = 19.578;
    else if (lep.find("DE") == 0)   lumi = 19.599;
    else if (lep.find("SMuE") == 0) lumi = 19.650;
    else if (lep.find("SMu") == 0)  lumi = 19.238;
    else if (lep.find("SE") == 0)   lumi = 19.091;
    //----------------------------------------------------------//


    short dataSyst[3] = {0, 2,2};
    short dataDir[3]  = {0,-1,1};

    short ttSyst[5]   = {0, 1, 1, 3, 3};
    short ttDir[5]    = {0,-1, 1,-1, 1};
    float ttScale[5]  = {1, 1, 1, 0.07, 0.07};

    short tauSyst[5]  = {0, 1, 1, 3, 3};
    short tauDir[5]   = {0,-1, 1,-1, 1};
    float tauScale[5] = {1, 1, 1, 0.05, 0.05};

    short bgSyst[5]   = {0, 1, 1, 3, 3};
    short bgDir[5]    = {0,-1, 1,-1, 1};
    float bgScale[5]  = {1, 1, 1, 0.15, 0.15};


    if (!doSyst){
        NSystData = 1; 
        NSystMC   = 1; 
        NSystTau  = 1; 
    }

    if (doWhat == 0 || doWhat == 100){
        for (unsigned int i(0); i < NSystData; i++){
            ZJetsAndDPS DMudata(lep+"_8TeV_Data_dR_5311",             1.,                                   1, 1, doDataEff, dataSyst[i], dataDir[i], 1, jetPtMin, jetPtMax, ZEtaMin, ZEtaMax, 0);
            DMudata.Loop(1, 0, doQCD, doSSign, doMassCut, doBJets, doPUStudy);
        }
    }

    if (doWhat == 1 || doWhat == 100){
        for (unsigned int i(0); i < NSystMC; i++){ 
            ZJetsAndDPS DMuTT(lep+"_8TeV_TTJets_dR_5311",             lumi*245.           *1000/6923652., 1, 1, !doDataEff, ttSyst[i], ttDir[i], ttScale[i], jetPtMin, jetPtMax, ZEtaMin, ZEtaMax);
            DMuTT.Loop(1, 0, doQCD, doSSign, doMassCut, doBJets, doPUStudy);
            if ((lep.find("SE") == string::npos && lep.find("SMu") == string::npos) || lep.find("SMuE") != string::npos){
                ZJetsAndDPS DMuWJ(lep+"_8TeV_WJetsALL_UNFOLDING_dR_5311",           lumi*37509.         *1000/76102995.,1, 1, !doDataEff, bgSyst[i], bgDir[i], bgScale[i], jetPtMin, jetPtMax, ZEtaMin, ZEtaMax);
                DMuWJ.Loop(1, 0, doQCD, doSSign, doMassCut, doBJets, doPUStudy);
            }
            ZJetsAndDPS DMuZZInc(lep+"_8TeV_ZZ_dR_5311",              lumi*17.654        *1000/9799908.,  1, 1, !doDataEff, bgSyst[i], bgDir[i], bgScale[i], jetPtMin, jetPtMax, ZEtaMin, ZEtaMax);
            DMuZZInc.Loop(1, 0, doQCD, doSSign, doMassCut, doBJets, doPUStudy);
            ZJetsAndDPS DMuWZInc(lep+"_8TeV_WZ_dR_5311",              lumi*33.21         *1000/10000283., 1, 1, !doDataEff, bgSyst[i], bgDir[i], bgScale[i], jetPtMin, jetPtMax, ZEtaMin, ZEtaMax);
            DMuWZInc.Loop(1, 0, doQCD, doSSign, doMassCut, doBJets, doPUStudy);
            ZJetsAndDPS DMuWWInc(lep+"_8TeV_WW_dR_5311",              lumi*54.838        *1000/10000431., 1, 1, !doDataEff, bgSyst[i], bgDir[i], bgScale[i], jetPtMin, jetPtMax, ZEtaMin, ZEtaMax);
            DMuWWInc.Loop(1, 0, doQCD, doSSign, doMassCut, doBJets, doPUStudy);
            ZJetsAndDPS DMuZZ(lep+"_8TeV_ZZJets2L2Nu_dR_5311",        lumi*17.654*0.04039 *1000/954911.,  1, 1, !doDataEff, bgSyst[i], bgDir[i], bgScale[i], jetPtMin, jetPtMax, ZEtaMin, ZEtaMax);
            DMuZZ.Loop(1, 0, doQCD, doSSign, doMassCut, doBJets, doPUStudy);
            ZJetsAndDPS DMuWW(lep+"_TeV_WWJets2L2Nu_dR_5311",        lumi*54.838*0.10608 *1000/1933235., 1, 1, !doDataEff, bgSyst[i], bgDir[i], bgScale[i], jetPtMin, jetPtMax, ZEtaMin, ZEtaMax);
            DMuWW.Loop(1, 0, doQCD, doSSign, doMassCut, doBJets, doPUStudy);
            ZJetsAndDPS DMuZZ1(lep+"_8TeV_ZZJets2L2Q_dR_5311",        lumi*17.654*0.14118 *1000/1936727., 1, 1, !doDataEff, bgSyst[i], bgDir[i], bgScale[i], jetPtMin, jetPtMax, ZEtaMin, ZEtaMax);
            DMuZZ1.Loop(1, 0, doQCD, doSSign, doMassCut, doBJets, doPUStudy);
            ZJetsAndDPS DMuZZ2(lep+"_8TeV_ZZJets4L_dR_5311",          lumi*17.654*0.010196*1000/4807893., 1, 1, !doDataEff, bgSyst[i], bgDir[i], bgScale[i], jetPtMin, jetPtMax, ZEtaMin, ZEtaMax);
            DMuZZ2.Loop(1, 0, doQCD, doSSign, doMassCut, doBJets, doPUStudy);
            ZJetsAndDPS DMuWZ(lep+"_8TeV_WZJets3LNu_dR_5311",         lumi*33.21 *0.032887*1000/1995334., 1, 1, !doDataEff, bgSyst[i], bgDir[i], bgScale[i], jetPtMin, jetPtMax, ZEtaMin, ZEtaMax);
            DMuWZ.Loop(1, 0, doQCD, doSSign, doMassCut, doBJets, doPUStudy);
            ZJetsAndDPS DMuWZ1(lep+"_8TeV_WZJets2L2Q_dR_5311",        lumi*33.21 *0.068258*1000/3215990., 1, 1, !doDataEff, bgSyst[i], bgDir[i], bgScale[i], jetPtMin, jetPtMax, ZEtaMin, ZEtaMax);
            DMuWZ1.Loop(1, 0, doQCD, doSSign, doMassCut, doBJets, doPUStudy);
            ZJetsAndDPS DMuT(lep+"_8TeV_T_s_channel_dR_5311",         lumi*3.79           *1000/259961.,  1, 1, !doDataEff, bgSyst[i], bgDir[i], bgScale[i], jetPtMin, jetPtMax, ZEtaMin, ZEtaMax);
            DMuT.Loop(1, 0, doQCD, doSSign, doMassCut, doBJets, doPUStudy);
            ZJetsAndDPS DMuT1(lep+"_8TeV_T_t_channel_dR_5311",        lumi*56.4           *1000/3758227., 1, 1, !doDataEff, bgSyst[i], bgDir[i], bgScale[i], jetPtMin, jetPtMax, ZEtaMin, ZEtaMax);
            DMuT1.Loop(1, 0, doQCD, doSSign, doMassCut, doBJets, doPUStudy);
            ZJetsAndDPS DMuT2(lep+"_8TeV_T_tW_channel_dR_5311",       lumi*11.1           *1000/497658.,  1, 1, !doDataEff, bgSyst[i], bgDir[i], bgScale[i], jetPtMin, jetPtMax, ZEtaMin, ZEtaMax);
            DMuT2.Loop(1, 0, doQCD, doSSign, doMassCut, doBJets, doPUStudy);
            ZJetsAndDPS DMuTbar(lep+"_8TeV_Tbar_s_channel_dR_5311",   lumi*1.76           *1000/139974.,  1, 1, !doDataEff, bgSyst[i], bgDir[i], bgScale[i], jetPtMin, jetPtMax, ZEtaMin, ZEtaMax);
            DMuTbar.Loop(1, 0, doQCD, doSSign, doMassCut, doBJets, doPUStudy);
            ZJetsAndDPS DMuTbar1(lep+"_8TeV_Tbar_t_channel_dR_5311",  lumi*30.7           *1000/1903681., 1, 1, !doDataEff, bgSyst[i], bgDir[i], bgScale[i], jetPtMin, jetPtMax, ZEtaMin, ZEtaMax);
            DMuTbar1.Loop(1, 0, doQCD, doSSign, doMassCut, doBJets, doPUStudy);
            ZJetsAndDPS DMuTbar2(lep+"_8TeV_Tbar_tW_channel_dR_5311", lumi*11.1           *1000/493460.,  1, 1, !doDataEff, bgSyst[i], bgDir[i], bgScale[i], jetPtMin, jetPtMax, ZEtaMin, ZEtaMax);
            DMuTbar2.Loop(1, 0, doQCD, doSSign, doMassCut, doBJets, doPUStudy);
            ZJetsAndDPS DMuDY10(lep+"_8TeV_DYJets10to50_dR_5311",     lumi*860.5          *1000/11707222.,  1, 1, !doDataEff, bgSyst[i], bgDir[i], bgScale[i], jetPtMin, jetPtMax, ZEtaMin, ZEtaMax);
            DMuDY10.Loop(1, 0, doQCD, doSSign, doMassCut, doBJets, doPUStudy);
        }
    }

    if (doWhat == 2 || doWhat == 100){
        for (unsigned int i(0); i < NSystTau; i++){ 
            ZJetsAndDPS DMuDYTau(lep+"_8TeV_DYJets_FromTau_UNFOLDING_dR_5311_Inf3", lumi*3503.7*1000/3045950, 1, 1, !doDataEff, tauSyst[i], tauDir[i], tauScale[i], jetPtMin, jetPtMax, ZEtaMin, ZEtaMax);
            DMuDYTau.Loop(1, 1, doQCD, doSSign, doMassCut, doBJets, doPUStudy);
        }
    }

    if (doWhat == 3 || doWhat == 100){
        int doGen = 0;
        if (lep.find("DMu") == 0 || lep.find("DE") == 0) doGen = 1;

        ZJetsAndDPS DMuDY(lep+"_8TeV_DYJets_UNFOLDING_dR_5311_Inf3",  lumi*3503.7*1000/30459503., 1., 1, !doDataEff, 0, 0, 1, jetPtMin, jetPtMax, ZEtaMin, ZEtaMax);
        DMuDY.Loop(1, doGen, doQCD, doSSign, doMassCut, doBJets, doPUStudy);
        ZJetsAndDPS DMuDYMix(lep+"_8TeV_DYJets_MIX_UNFOLDING_dR_5311_Inf3", lumi*3503.7*1000/30459503., 1., 1, !doDataEff, 0, 0, 1, jetPtMin, jetPtMax, ZEtaMin, ZEtaMax, 0);
        DMuDYMix.Loop(1, doGen, doQCD, doSSign, doMassCut, doBJets, doPUStudy);

        if (doSyst){
            //PU
            ZJetsAndDPS DMuDYMix(lep+"_8TeV_DYJets_MIX_UNFOLDING_dR_5311_Inf3", lumi*3503.7*1000/30459503., 1., 1, !doDataEff, 1, 1, 1, jetPtMin, jetPtMax, ZEtaMin, ZEtaMax, 0);
            DMuDYMix.Loop(1, doGen, doQCD,  doSSign, doMassCut, doBJets, doPUStudy);
            ZJetsAndDPS DMuDYMix(lep+"_8TeV_DYJets_MIX_UNFOLDING_dR_5311_Inf3", lumi*3503.7*1000/30459503., 1., 1, !doDataEff, 1,-1, 1, jetPtMin, jetPtMax, ZEtaMin, ZEtaMax, 0);
            DMuDYMix.Loop(1, doGen, doQCD, doSSign, doMassCut, doBJets, doPUStudy);

            // jet smearing part
            if (doGen){ 
                ZJetsAndDPS DMuDYMix(lep+"_8TeV_DYJets_MIX_UNFOLDING_dR_5311_Inf3", lumi*3503.7*1000/30459503., 1., 1, !doDataEff, 4, 1, 1, jetPtMin, jetPtMax, ZEtaMin, ZEtaMax, 0);
                DMuDYMix.Loop(1, doGen, doQCD, doSSign, doMassCut, doBJets, doPUStudy);
            }
            else { // xsec offsets
                ZJetsAndDPS DMuDYMix(lep+"_8TeV_DYJets_MIX_UNFOLDING_dR_5311_Inf3", lumi*3503.7*1000/30459503., 1., 1, !doDataEff, 3, 1, 0.04, jetPtMin, jetPtMax, ZEtaMin, ZEtaMax, 0);
                DMuDYMix.Loop(1, doGen, doQCD, doSSign, doMassCut, doBJets, doPUStudy);

                ZJetsAndDPS DMuDYMix(lep+"_8TeV_DYJets_MIX_UNFOLDING_dR_5311_Inf3", lumi*3503.7*1000/30459503., 1., 1, !doDataEff, 3, -1, 0.04, jetPtMin, jetPtMax, ZEtaMin, ZEtaMax, 0);
                DMuDYMix.Loop(1, doGen, doQCD, doSSign, doMassCut, doBJets, doPUStudy);

            } 
            ZJetsAndDPS DMuDYMix(lep+"_8TeV_DYJets_MIX_UNFOLDING_dR_5311_Inf3", lumi*3503.7*1000/30459503., 1., 1, !doDataEff, 1, 1, 1, jetPtMin, jetPtMax, ZEtaMin, ZEtaMax, 0);
            DMuDYMix.Loop(1, doGen, doQCD, doSSign, doMassCut, doBJets, doPUStudy);
            ZJetsAndDPS DMuDYMix(lep+"_8TeV_DYJets_MIX_UNFOLDING_dR_5311_Inf3", lumi*3503.7*1000/30459503., 1., 1, !doDataEff, 1,-1, 1, jetPtMin, jetPtMax, ZEtaMin, ZEtaMax, 0);
            DMuDYMix.Loop(1, doGen, doQCD, doSSign, doMassCut, doBJets, doPUStudy);
        }
    }
    /// this is unfolding part for W+jets 
    if (doWhat == 4 || doWhat == 100){
        int doGen = 0;
        if ((lep.find("SE") == 0 || lep.find("SMu") == 0) && lep.find("SMuE") != string::npos) doGen = 1;

        ZJetsAndDPS DMuWJ(lep+"_8TeV_WJetsALL_UNFOLDING_dR_5311",  lumi*37509.         *1000/76102995., 1., 1, !doDataEff, 0, 0, 1, jetPtMin, jetPtMax, ZEtaMin, ZEtaMax);
        DMuWJ.Loop(1, doGen, doQCD,  doSSign, doMassCut, doBJets, doPUStudy);
        ZJetsAndDPS DMuWJMix(lep+"_8TeV_WJetsALL_MIX_UNFOLDING_dR_5311", lumi*37509.         *1000/76102995., 1., 1, !doDataEff, 0, 0, 1, jetPtMin, jetPtMax, ZEtaMin, ZEtaMax, 0);
        DMuWJMix.Loop(1, doGen, doQCD, doSSign, doMassCut, doBJets, doPUStudy);

        if (doSyst){
            //PU
            ZJetsAndDPS DMuWJMix(lep+"_8TeV_WJetsALL_UNFOLDING_dR_5311", lumi*37509*1000/76102995., 1., 1, !doDataEff, 1, 1, 1, jetPtMin, jetPtMax, ZEtaMin, ZEtaMax, 0);
            DMuWJMix.Loop(1, doGen, doQCD,  doSSign, doMassCut, doBJets, doPUStudy);
            ZJetsAndDPS DMuWJMix(lep+"_8TeV_WJetsALL_UNFOLDING_dR_5311", lumi*37509*1000/76102995., 1., 1, !doDataEff, 1,-1, 1, jetPtMin, jetPtMax, ZEtaMin, ZEtaMax, 0);
            DMuWJMix.Loop(1, doGen, doQCD,  doSSign, doMassCut, doBJets, doPUStudy);

            // jet smearing part
            if ( doGen ) {
                ZJetsAndDPS DMuWJMix(lep+"_8TeV_WJetsALL_UNFOLDING_dR_5311", lumi*37509*1000/76102995., 1., 1, !doDataEff, 4, 1, 1, jetPtMin, jetPtMax, ZEtaMin, ZEtaMax, 0);
                DMuWJMix.Loop(1, doGen, doQCD,  doSSign, doMassCut, doBJets, doPUStudy);
            }
            else { // xsec offsets
                ZJetsAndDPS DMuWJMix(lep+"_8TeV_WJetsALL_UNFOLDING_dR_5311", lumi*37509*1000/76102995., 1., 1, !doDataEff, 3, 1, 0.04, jetPtMin, jetPtMax, ZEtaMin, ZEtaMax, 0);
                DMuWJMix.Loop(1, doGen, doQCD,  doSSign, doMassCut, doBJets, doPUStudy);

                ZJetsAndDPS DMuWJMix(lep+"_8TeV_WJetsALL_UNFOLDING_dR_5311", lumi*37509*1000/76102995., 1., 1, !doDataEff, 3, -1, 0.04, jetPtMin, jetPtMax, ZEtaMin, ZEtaMax, 0);
                DMuWJMix.Loop(1, doGen, doQCD,  doSSign, doMassCut, doBJets, doPUStudy);

            }
            ZJetsAndDPS DMuWJMix(lep+"_8TeV_WJetsALL_UNFOLDING_dR_5311", lumi*37509*1000/76102995., 1., 1, !doDataEff, 1, 1, 1, jetPtMin, jetPtMax, ZEtaMin, ZEtaMax, 0);
            DMuWJMix.Loop(1, doGen, doQCD, doSSign, doMassCut, doBJets, doPUStudy);
            ZJetsAndDPS DMuWJMix(lep+"_8TeV_WJetsALL_UNFOLDING_dR_5311", lumi*37509*1000/76102995., 1., 1, !doDataEff, 1,-1, 1, jetPtMin, jetPtMax, ZEtaMin, ZEtaMax, 0);
            DMuWJMix.Loop(1, doGen, doQCD, doSSign, doMassCut, doBJets, doPUStudy);
        }


    }

    if (doWhat == 51){

        // this is setup for sherpa NLO 
        ZJetsAndDPS DESherpaTest1NLO("DE_8TeV_DY_Sherpa_1NLO4_HepMC_dR_Full_List",  eleLumi         * 1000.          , 1.,    0,   0,     0,    0,     1.,  jetPtMin,  jetPtMax, ZEtaMin, ZEtaMax );
        DESherpaTest1NLO.Loop(0, 1, 0, 0); 

        ZJetsAndDPS DESherpaTest1NLOScaleDown("DE_8TeV_DY_Sherpa_1NLO4_scaleDown_HepMC_dR_Full_List",  eleLumi         * 1000.          , 1.,    0,   0,     0,    0,     1.,  jetPtMin,  jetPtMax, ZEtaMin, ZEtaMax );
        DESherpaTest1NLOScaleDown.Loop(0, 1, 0, 0); 

        ZJetsAndDPS DESherpaTest1NLOScaleUp("DE_8TeV_DY_Sherpa_1NLO4_scaleUp_HepMC_dR_Full_List",  eleLumi         * 1000.          , 1.,    0,   0,     0,    0,     1.,  jetPtMin,  jetPtMax, ZEtaMin, ZEtaMax );
        DESherpaTest1NLOScaleUp.Loop(0, 1, 0, 0); 



        //ZJetsAndDPS DMuSherpa(lep+"_DYJets_Sherpa_mcEveWeight",   lumi * 3503.7           * 1000 / 30459503.,    1.,  0,  0,  0,  0,  1.,  jetPtMin,  jetPtMax, ZEtaMin, ZEtaMax );
        //ZJetsAndDPS DESherpALL("DE_8TeV_Sherpa_HepMC_Z2jetNLO4jetLO_multithread_ALL_dR",  eleLumi         * 1000.          , 1.,    0,   0,     0,    0,     1.,  jetPtMin,  jetPtMax, ZEtaMin, ZEtaMax );
        //DESherpALL.Loop(0, 1,  doQCD,  doSSign, doMassCut, doBJets, doPUStudy ); 


        ZJetsAndDPS DMuPowMiNLO("DMu_8TeV_DYJets_PowhegZ2jMiNLO_dR_GEN_Cern",                             lumi * 1.            * 1000 / 1964662.,    1.013,    0,   0,     0,    0,     1.,  jetPtMin,  jetPtMax, ZEtaMin, ZEtaMax   ); 
        DMuPowMiNLO.Loop(0, 1, 0, 0);
        //	ZJetsAndDPS DEPow("DE_8TeV_DYJets_PowhegNLO1Jet_dR_GEN",                             lumi * 334.            * 1000 / 2948078.,    1.013,    0,   0,     0,    0,     1.,  jetPtMin,  jetPtMax, ZEtaMin, ZEtaMax   ); 
        //	DEPow.Loop(0, 1, 0, 0);
        //	ZJetsAndDPS DEPowSU("DE_8TeV_DYJets_PowhegNLO1Jet_dR_ScaleUp_GEN",                             lumi * 318.4            * 1000 / 5446372.,    1.013,    0,   0,     0,    0,     1.,  jetPtMin,  jetPtMax, ZEtaMin, ZEtaMax   ); 
        //	DEPowSU.Loop(0, 1, 0, 0);
        //	ZJetsAndDPS DEPowSD("DE_8TeV_DYJets_PowhegNLO1Jet_dR_ScaleDown_GEN",                             lumi * 357.2            * 1000 / 5856584.,    1.013,    0,   0,     0,    0,     1.,  jetPtMin,  jetPtMax, ZEtaMin, ZEtaMax   ); 
        //	DEPowSD.Loop(0, 1, 0, 0);

        //ZJetsAndDPS DESherpaTest("DE_8TeV_DY_Sherpa_HepMC_dR_Full_List",  eleLumi         * 1000.          , 1.,    0,   0,     0,    0,     1.,  jetPtMin,  jetPtMax, ZEtaMin, ZEtaMax );
        //ZJetsAndDPS DESherpaTest("Sherpa\/DE_8TeV_Sherpa_HepMC_num*",  eleLumi         * 1000.          , 1.,    0,   0,     0,    0,     1.,  jetPtMin,  jetPtMax, ZEtaMin, ZEtaMax );
        //DESherpaTest.Loop(0, 1,  doQCD,  doSSign, doMassCut, doBJets, doPUStudy ); 

    }
    /*
    //--- clean the _cc.d and _cc.so files ---
    string cmd = "if ls *_cc.d &> .ls_tmp.list; then rm *_cc.d; fi";
    system(cmd.c_str());
    cmd = "if ls *_cc.so &> .ls_tmp.list; then rm *_cc.so; fi";
    system(cmd.c_str());
    cmd = "if ls " + srcdir + "*_cc.d &> .ls_tmp.list; then rm " + srcdir + "*_cc.d; fi";
    system(cmd.c_str());
    cmd = "if ls " + srcdir + "*_cc.so &> .ls_tmp.list; then rm " + srcdir + "*_cc.so; fi";
    system(cmd.c_str());
    system("rm .ls_tmp.list");

    string stop = __TIME__;

    cout << "Started at\t" << start << endl;
    cout << "Ended at\t" << stop << endl;
    */
}

