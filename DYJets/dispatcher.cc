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

    const static int NDYJETSTHREAD = 10;
    std::thread DYJetsThread[NDYJETSTHREAD];


    auto start = std::chrono::system_clock::now();
    std::cout << "Starting to dispatch" << std::endl;

    for (int i = 0; i < 2; ++i) {
        std::string lep = "DE";
        if (i == 1) lep = "DMu";

        DYJetsThread[i*5 + 0] = std::thread(runZJets, "lepSel=" + lep + " whichSyst=0", "");
        std::cout << "Central submitted" << std::endl;

        DYJetsThread[i*5 + 1] = std::thread(runZJets, "lepSel=" + lep + " whichSyst=1", "m7");
        std::cout << "Syst down submitted" << std::endl;

        DYJetsThread[i*5 + 2] = std::thread(runZJets, "lepSel=" + lep + " whichSyst=2", "m7");
        std::cout << "Syst up submitted" << std::endl;

        DYJetsThread[i*5 + 3] = std::thread(runZJets, "lepSel=" + lep + " whichSyst=3", "m8");
        std::cout << "Syst down submitted" << std::endl;

        DYJetsThread[i*5 + 4] = std::thread(runZJets, "lepSel=" + lep + " whichSyst=4", "m8");
        std::cout << "Syst up submitted" << std::endl;

    }


    //Join the threads with the main thread
    for (int i = 0; i < NDYJETSTHREAD; ++i) {
        DYJetsThread[i].join();
    }
    std::cout << "All jobs done" << std::endl;


    auto end = std::chrono::system_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << elapsed.count() << " ms\n";

    return 0;
}
