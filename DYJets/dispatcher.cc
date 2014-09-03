#include <iostream>
#include <thread>
#include <unistd.h>

void runZJets(std::string option) 
{
    std::string command = "./runZJets " + option;
    std::cout << command << std::endl;
    system(command.c_str());
}

int main(int argc, char **argv)
{

    auto start = std::chrono::system_clock::now();
    std::cout << "Starting to dispatch" << std::endl;
    std::thread central(runZJets, "doCentral=1 doSysRunning=0");
    //runZJets("doCentral=1 doSysRunning=0");
    std::cout << "Central submitted" << std::endl;
    //sleep(5);
    //std::thread systDown(runZJets, "whichSyst=1");
    //runZJets("whichSyst=1");
    std::cout << "Syst down submitted" << std::endl;
    //sleep(5);
    //std::thread systUp(runZJets, "whichSyst=2");
    //runZJets("whichSyst=2");
    std::cout << "Syst up submitted" << std::endl;

    central.join();
    //systDown.join();
    //systUp.join();

    std::cout << "All jobs done" << std::endl;


    auto end = std::chrono::system_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << elapsed.count() << '\n';

    return 0;
}
