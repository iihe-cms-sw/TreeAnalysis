#include <iostream>
#include <TROOT.h>
#include <TString.h>
#include "ConfigVJets.h"
#include "getFilesAndHistogramsZJets.h"
#include "RecoComparison.h"

int main(int argc, char **argv)
{
    //--- Loads configuration -----------------------------------------------------
    ConfigVJets cfg;
    //-----------------------------------------------------------------------------
    
    gROOT->SetBatch();
    gErrorIgnoreLevel = kError;

    bool doPASPlots = false;

    if (argc == 2) {
        TString argPAS = argv[1];
        if (argPAS == "PAS") doPASPlots = true;
    }
    //Plotter("Electrons", 30);
    //PlotterPAS("Electrons");
    Plotter(&argc, argv, doPASPlots, "DMu", 30);
    //PlotterPAS("Muons");

    //getStatistics("Electrons", 30);
    //getStatistics("Muons", 30);
    //getStatistics("Muons", 30,0,0,1,0,1);
    //getStatistics("Electrons", 30,0,0,1,0,1);


    return 0;
}
