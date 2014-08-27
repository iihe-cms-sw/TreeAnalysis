#include <iostream>
#include <TString.h>
#include "ConfigVJets.h"
#include "UnfoldingZJets.h"

int main(int argc, char **argv)
{
    //--- Loads configuration -----------------------------------------------------
    ConfigVJets cfg;
    //-----------------------------------------------------------------------------

    std::cout << __DATE__ << " at " << __TIME__ << std::endl;
    UnfoldingZJets(&argc, argv);
    std::cout << __DATE__ << " at " << __TIME__ << std::endl;

    return 0;
}
