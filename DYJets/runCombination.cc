#include <iostream>
#include "ArgParser.h"
#include "ConfigVJets.h"
#include "Combination.h"


int main(int argc, char **argv)
{
    
    //--- Load configuration ---
    ConfigVJets cfg;
    //-----------------------------------------------------------------------

    //--- Settings ---
    // doWhat = "DATA", "BACKGROUND", "TAU", "DYJETS", 
    //          "WJETS", "ALL", "PDF", "SHERPA"

    TString unfoldDir  = cfg.getS("unfoldDir");
    TString combDir    = cfg.getS("combDir", "CombinationAugust");
    TString algo       = cfg.getS("algo");
    int jetPtMin       = cfg.getI("jetPtMin", 30);
    int jetEtaMax      = cfg.getI("jetEtaMax", 24);

    if (!unfoldDir.EndsWith("/")) unfoldDir += "/";
    if (!combDir.EndsWith("/")) combDir += "/";

    Combination(unfoldDir, combDir, algo, jetPtMin, jetEtaMax);
    return 0;
}
