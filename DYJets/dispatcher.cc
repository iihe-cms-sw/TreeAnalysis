#include <iostream>
#include <thread>

void runZJets(std::string option) 
{
    std::string command = "./runZJets " + option;
    std::cout << command << std::endl;
    system(command.c_str());
}

int main(int argc, char **argv)
{

    std::thread t[3];


    auto start = std::chrono::system_clock::now();
    std::cout << "Starting to dispatch" << std::endl;
    t[0] = std::thread(runZJets, "whichSyst=0");
    //runZJets("doCentral=1 doSysRunning=0");
    std::cout << "Central submitted" << std::endl;
    t[1] = std::thread(runZJets, "whichSyst=1");
    //runZJets("whichSyst=1");
    std::cout << "Syst down submitted" << std::endl;
    t[2] = std::thread(runZJets, "whichSyst=2");
    //runZJets("whichSyst=2");
    std::cout << "Syst up submitted" << std::endl;

    //Join the threads with the main thread
    for (int i = 0; i < 3; ++i) {
        t[i].join();
    }
    std::cout << "All jobs done" << std::endl;


    auto end = std::chrono::system_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << elapsed.count() << '\n';

    return 0;
}
