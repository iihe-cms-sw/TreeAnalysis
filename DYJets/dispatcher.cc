#include <iostream>
#include <thread>
#include "ArgParser.h"

void executeInThread(std::string executable, std::string option, std::string machine) 
{
    std::string command = executable + " " + option;
    if (machine != "") command = "ssh -o StrictHostKeyChecking=no " + machine + " \'source .bash_profile; cd TreeAnalysis2012/DYJets/; " + command + "\'";  
    //std::string command = "./runZJets " + option;
    std::cout << command << std::endl;
    system(command.c_str());
}

int main(int argc, char **argv)
{

    bool doHisto = true;
    bool doRecoComp = true;
    bool doUnfold = true;
    bool doCombination = true;
    bool doCopyToMac = false;
    std::string machines[] = {"m7.iihe.ac.be", "m6.iihe.ac.be", "m7.iihe.ac.be", "m8.iihe.ac.be", "m8.iihe.ac.be"};

    //--- Parse the arguments -----------------------------------------------------
    if (argc > 1) {
        for (int i = 1; i < argc; ++i) {
            TString currentArg = argv[i];
            //--- possible options ---
            if (currentArg.BeginsWith("doHisto=")) {
                getArg(currentArg, doHisto);
            }
            else if (currentArg.BeginsWith("doRecoComp=")) {
                getArg(currentArg, doRecoComp);
            }
            else if (currentArg.BeginsWith("doUnfold=")) {
                getArg(currentArg, doUnfold);
            }
            else if (currentArg.BeginsWith("doCombination=")) {
                getArg(currentArg, doCombination);
            }
            else if (currentArg.BeginsWith("doCopyToMac=")) {
                getArg(currentArg, doCopyToMac);
            }
            else if (currentArg.BeginsWith("lxplus")) {
                machines[0] = "lxplus0159.cern.ch";
                machines[1] = "lxplus0138.cern.ch";
                machines[2] = "lxplus0139.cern.ch";
                machines[3] = "lxplus0149.cern.ch";
                machines[4] = "lxplus0171.cern.ch";
            }
            //--- asking for help ---
            else if (currentArg.Contains("help") || currentArg.BeginsWith("-h")) {
                std::cout << "\nUsage: ./dispatcher [doHisto=(1,0)] [doRecoComp=(1, 0)] [doUnfold=(1, 0)] [doCombination=(1, 0)] [doCopyToMac=(0, 1)] ";
                std::cout << "[lxplus] [--help]" << std::endl;
                std::cout << "eg: ./dispatcher doHisto=0" << std::endl;
                std::cout << "unspecified options will be read from vjets.cfg\n" << std::endl;
                return 0;
            }
            //--- bad option ---
            else {
                std::cerr << "Warning: unknown option \"" << currentArg << "\"" << std::endl;
                std::cerr << "Please issue ./dispatcher -help for more information on possible options" << std::endl;
                return 0;
            }
        }
    }

    auto start = std::chrono::system_clock::now();
    std::cout << "Starting to dispatch" << std::endl;

    if (doHisto) {
        //--- Generate the histofiles ---
        std::thread DataThread[6];
        std::thread DYJetsThread[10];
        std::thread BGThread[10];
        std::thread TAUThread[10];
        std::thread WJETSThread[10];

        //--- first execute the DYJets ---
        for (int i = 0; i < 2; ++i) {
            std::string lep = "DE";
            if (i == 1) lep = "DMu";

            DataThread[i*3 + 0] = std::thread(executeInThread, "./runZJets", "doWhat=DATA lepSel=" + lep + " whichSyst=0", machines[0]);
            DataThread[i*3 + 1] = std::thread(executeInThread, "./runZJets", "doWhat=DATA lepSel=" + lep + " whichSyst=1", machines[1]);
            DataThread[i*3 + 2] = std::thread(executeInThread, "./runZJets", "doWhat=DATA lepSel=" + lep + " whichSyst=2", machines[2]);

            DYJetsThread[i*5 + 0] = std::thread(executeInThread, "./runZJets", "doWhat=DYJETS lepSel=" + lep + " whichSyst=0", machines[0]);
            DYJetsThread[i*5 + 1] = std::thread(executeInThread, "./runZJets", "doWhat=DYJETS lepSel=" + lep + " whichSyst=1", machines[1]);
            DYJetsThread[i*5 + 2] = std::thread(executeInThread, "./runZJets", "doWhat=DYJETS lepSel=" + lep + " whichSyst=2", machines[2]);
            DYJetsThread[i*5 + 3] = std::thread(executeInThread, "./runZJets", "doWhat=DYJETS lepSel=" + lep + " whichSyst=3", machines[3]);
            DYJetsThread[i*5 + 4] = std::thread(executeInThread, "./runZJets", "doWhat=DYJETS lepSel=" + lep + " whichSyst=4", machines[4]);

            BGThread[i*5 + 0] = std::thread(executeInThread, "./runZJets", "doWhat=BACKGROUND lepSel=" + lep + " whichSyst=0", machines[0]);
            BGThread[i*5 + 1] = std::thread(executeInThread, "./runZJets", "doWhat=BACKGROUND lepSel=" + lep + " whichSyst=1", machines[1]);
            BGThread[i*5 + 2] = std::thread(executeInThread, "./runZJets", "doWhat=BACKGROUND lepSel=" + lep + " whichSyst=2", machines[2]);
            BGThread[i*5 + 3] = std::thread(executeInThread, "./runZJets", "doWhat=BACKGROUND lepSel=" + lep + " whichSyst=3", machines[3]);
            BGThread[i*5 + 4] = std::thread(executeInThread, "./runZJets", "doWhat=BACKGROUND lepSel=" + lep + " whichSyst=4", machines[4]);

            TAUThread[i*5 + 0] = std::thread(executeInThread, "./runZJets", "doWhat=TAU lepSel=" + lep + " whichSyst=0", machines[0]);
            TAUThread[i*5 + 1] = std::thread(executeInThread, "./runZJets", "doWhat=TAU lepSel=" + lep + " whichSyst=1", machines[1]);
            TAUThread[i*5 + 2] = std::thread(executeInThread, "./runZJets", "doWhat=TAU lepSel=" + lep + " whichSyst=2", machines[2]);
            TAUThread[i*5 + 3] = std::thread(executeInThread, "./runZJets", "doWhat=TAU lepSel=" + lep + " whichSyst=3", machines[3]);
            TAUThread[i*5 + 4] = std::thread(executeInThread, "./runZJets", "doWhat=TAU lepSel=" + lep + " whichSyst=4", machines[4]);

            WJETSThread[i*5 + 0] = std::thread(executeInThread, "./runZJets", "doWhat=WJETS lepSel=" + lep + " whichSyst=0", machines[0]);
            WJETSThread[i*5 + 1] = std::thread(executeInThread, "./runZJets", "doWhat=WJETS lepSel=" + lep + " whichSyst=1", machines[1]);
            WJETSThread[i*5 + 2] = std::thread(executeInThread, "./runZJets", "doWhat=WJETS lepSel=" + lep + " whichSyst=2", machines[2]);
            WJETSThread[i*5 + 3] = std::thread(executeInThread, "./runZJets", "doWhat=WJETS lepSel=" + lep + " whichSyst=3", machines[3]);
            WJETSThread[i*5 + 4] = std::thread(executeInThread, "./runZJets", "doWhat=WJETS lepSel=" + lep + " whichSyst=4", machines[4]);
        }

        //Join the data threads with the main thread
        for (int i = 0; i < 6; ++i) {
            DataThread[i].join();
        }

        //Join the threads with the main thread
        for (int i = 0; i < 10; ++i) {
            DYJetsThread[i].join();
            BGThread[i].join();
            TAUThread[i].join();
            WJETSThread[i].join();
        }

        std::cout << "All jobs done" << std::endl;
    }

    if (doRecoComp) {

        //--- Now proceed to reco comparison ---
        std::thread recoComp[4];
        for (int i = 0; i < 2; ++i) {
            std::string lep = "DE";
            if (i == 1) lep = "DMu";
            recoComp[2*i + 0] = std::thread(executeInThread, "./runRecoComparison", "doPASPlots=1 lepSel=" + lep, "");
            recoComp[2*i + 1] = std::thread(executeInThread, "./runRecoComparison", "doPASPlots=0 lepSel=" + lep, "");
        }

        //Join the reco threads with the main thread
        for (int i = 0; i < 4; ++i) {
            recoComp[i].join();
        }
    }

    if (doUnfold) {
        //--- Now proceed to reco comparison ---
        std::thread unfolding[2];
        for (int i = 0; i < 2; ++i) {
            std::string lep = "DE";
            if (i == 1) lep = "DMu";
            unfolding[i] = std::thread(executeInThread, "./runUnfoldingZJets", "lepSel=" + lep, "");
        }

        //Join the reco threads with the main thread
        for (int i = 0; i < 2; ++i) {
            unfolding[i].join();
        }
    }

    if (doCombination) {
        executeInThread("./runCombination", "", "");
    }

    if (doCopyToMac) {

    }

    auto end = std::chrono::system_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << elapsed.count() << " ms\n";

    return 0;
}
