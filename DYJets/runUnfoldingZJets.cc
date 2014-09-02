#include <iostream>
#include <TString.h>
#include "ArgParser.h"
#include "ConfigVJets.h"
#include "UnfoldingZJets.h"

int main(int argc, char **argv)
{
    //--- Loads configuration -----------------------------------------------------
    ConfigVJets cfg;

    TString histoDir  = cfg.getS("histoDir");
    TString unfoldDir = cfg.getS("unfoldDir");
    TString lepSel    = cfg.getS("lepSel");
    TString algo      = cfg.getS("algo");
    int jetPtMin      = cfg.getI("jetPtMin");
    int jetEtaMax     = cfg.getI("jetEtaMax");

    //-----------------------------------------------------------------------------
    
    //--- Parse the arguments -----------------------------------------------------
    if (argc > 1) {
        for (int i = 1; i < argc; ++i) {
            TString currentArg = argv[i];
            if (currentArg.BeginsWith("histoDir=")) {
                getArg(currentArg, histoDir);
            }
            else if (currentArg.BeginsWith("unfoldDir=")) {
                getArg(currentArg, unfoldDir);
            }
            else if (currentArg.BeginsWith("lepSel=")) {
                getArg(currentArg, lepSel);
            }
            else if (currentArg.BeginsWith("algo=")) {
                getArg(currentArg, algo);
            }
            else if (currentArg.BeginsWith("jetPtMin=")) {
                getArg(currentArg, jetPtMin);
            }
            else if (currentArg.BeginsWith("jetEtaMax=")) {
                getArg(currentArg, jetEtaMax);
            }
            else if (currentArg.BeginsWith("--help") || currentArg.BeginsWith("-h")) {
                std::cout << "\nUsage: ./runUnfolding [lepSel=(DMu, DE)] [algo=(Bayes, SVD)] [jetPtMin=(int)] [jetEtaMax=(int*10)] [histoDir=(path)] [unfoldDir=(path)] [--help]" << std::endl;
                std::cout << "eg: ./runUnfolding lepSel=DMu jetEtaMax=24" << std::endl;
                std::cout << "unspecified options will be read from vjets.cfg\n" << std::endl;
                return 0;
            }
            else {
                std::cerr << "Warning: unknown option \"" << currentArg << "\"" << std::endl;
                std::cerr << "Please issue ./runUnfolding --help for more information on possible options" << std::endl;
                return 0;
            }
        }
    }

    if (!histoDir.EndsWith("/")) histoDir += "/";
    if (!unfoldDir.EndsWith("/")) unfoldDir += "/";

    std::cout << "\n executing UnfoldingZJets(\"" << lepSel << "\", \"" <<  algo << "\", \"" << histoDir << "\", \"" << unfoldDir << "\", " << jetPtMin << ", " << jetEtaMax << ", &argc, argv);" << std::endl;
    //-----------------------------------------------------------------------------
    
    std::cout << __DATE__ << " at " << __TIME__ << std::endl;
    UnfoldingZJets(lepSel, algo, histoDir, unfoldDir, jetPtMin, jetEtaMax, &argc, argv);
    std::cout << __DATE__ << " at " << __TIME__ << std::endl;

    return 0;
}
