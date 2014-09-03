#include <iostream>
#include <thread>

void runZJets(std::string option, std::string machine) 
{
    std::string command = "./runZJets " + option;
    if (machine != "") command = "ssh " + machine + " \'source .bash_profile; cd TreeAnalysis2012/DYJets/; " + command +"\'";  
    //std::string command = "./runZJets " + option;
    std::cout << command << std::endl;
    system(command.c_str());
}

int main(int argc, char **argv)
{

    std::thread DataThread[6];
    std::thread DYJetsThread[10];
    std::thread BGThread[10];
    std::thread TAUThread[10];
    std::thread WJETSThread[10];


    auto start = std::chrono::system_clock::now();
    std::cout << "Starting to dispatch" << std::endl;

    //--- first execute the DYJets ---
    for (int i = 0; i < 2; ++i) {
        std::string lep = "DE";
        if (i == 1) lep = "DMu";

        DataThread[i*3 + 0] = std::thread(runZJets, "doWhat=DATA lepSel=" + lep + " whichSyst=0", "m5");
        DataThread[i*3 + 1] = std::thread(runZJets, "doWhat=DATA lepSel=" + lep + " whichSyst=1", "m6");
        DataThread[i*3 + 2] = std::thread(runZJets, "doWhat=DATA lepSel=" + lep + " whichSyst=2", "m7");

        DYJetsThread[i*5 + 0] = std::thread(runZJets, "doWhat=DYJETS lepSel=" + lep + " whichSyst=0", "m5");
        DYJetsThread[i*5 + 1] = std::thread(runZJets, "doWhat=DYJETS lepSel=" + lep + " whichSyst=1", "m6");
        DYJetsThread[i*5 + 2] = std::thread(runZJets, "doWhat=DYJETS lepSel=" + lep + " whichSyst=2", "m7");
        DYJetsThread[i*5 + 3] = std::thread(runZJets, "doWhat=DYJETS lepSel=" + lep + " whichSyst=3", "m8");
        DYJetsThread[i*5 + 4] = std::thread(runZJets, "doWhat=DYJETS lepSel=" + lep + " whichSyst=4", "m9");
    }

    //Join the data threads with the main thread
    for (int i = 0; i < 6; ++i) {
        DataThread[i].join();
    }

    //Join the dyjets threads with the main thread
    for (int i = 0; i < 10; ++i) {
        DYJetsThread[i].join();
    }

    
    //--- Once Data and DYJets are done execute Background ---

    for (int i = 0; i < 2; ++i) {
        std::string lep = "DE";
        if (i == 1) lep = "DMu";

        BGThread[i*5 + 0] = std::thread(runZJets, "doWhat=BACKGROUND lepSel=" + lep + " whichSyst=0", "m5");
        BGThread[i*5 + 1] = std::thread(runZJets, "doWhat=BACKGROUND lepSel=" + lep + " whichSyst=1", "m6");
        BGThread[i*5 + 2] = std::thread(runZJets, "doWhat=BACKGROUND lepSel=" + lep + " whichSyst=2", "m7");
        BGThread[i*5 + 3] = std::thread(runZJets, "doWhat=BACKGROUND lepSel=" + lep + " whichSyst=3", "m8");
        BGThread[i*5 + 4] = std::thread(runZJets, "doWhat=BACKGROUND lepSel=" + lep + " whichSyst=4", "m9");

        TAUThread[i*5 + 0] = std::thread(runZJets, "doWhat=TAU lepSel=" + lep + " whichSyst=0", "m5");
        TAUThread[i*5 + 1] = std::thread(runZJets, "doWhat=TAU lepSel=" + lep + " whichSyst=1", "m6");
        TAUThread[i*5 + 2] = std::thread(runZJets, "doWhat=TAU lepSel=" + lep + " whichSyst=2", "m7");
        TAUThread[i*5 + 3] = std::thread(runZJets, "doWhat=TAU lepSel=" + lep + " whichSyst=3", "m8");
        TAUThread[i*5 + 4] = std::thread(runZJets, "doWhat=TAU lepSel=" + lep + " whichSyst=4", "m9");

        WJETSThread[i*5 + 0] = std::thread(runZJets, "doWhat=WJETS lepSel=" + lep + " whichSyst=0", "m5");
        WJETSThread[i*5 + 1] = std::thread(runZJets, "doWhat=WJETS lepSel=" + lep + " whichSyst=1", "m6");
        WJETSThread[i*5 + 2] = std::thread(runZJets, "doWhat=WJETS lepSel=" + lep + " whichSyst=2", "m7");
        WJETSThread[i*5 + 3] = std::thread(runZJets, "doWhat=WJETS lepSel=" + lep + " whichSyst=3", "m8");
        WJETSThread[i*5 + 4] = std::thread(runZJets, "doWhat=WJETS lepSel=" + lep + " whichSyst=4", "m9");


    }

    //Join the dyjets threads with the main thread
    for (int i = 0; i < 10; ++i) {
        BGThread[i].join();
        TAUThread[i].join();
        WJETSThread[i].join();
    }

    std::cout << "All jobs done" << std::endl;


    auto end = std::chrono::system_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << elapsed.count() << " ms\n";

    return 0;
}
