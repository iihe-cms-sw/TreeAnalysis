#include "ArgParser.h"

void getArg(TString fullArg, TString &arg) {
    arg = fullArg(fullArg.Index("=")+1, fullArg.Length());
}

void getArg(TString fullArg, int &arg) {
    arg = TString(fullArg(fullArg.Index("=")+1, fullArg.Length())).Atoi();
}

void getArg(TString fullArg, double &arg) {
    arg = TString(fullArg(fullArg.Index("=")+1, fullArg.Length())).Atof();
}

void getArg(TString fullArg, bool &arg) {
    TString tmp = fullArg(fullArg.Index("=")+1, fullArg.Length());
    tmp.ToUpper();
    if (tmp == "TRUE" || tmp == "1") arg = true; 
    else if (tmp == "FALSE" || tmp == "0") arg = false;
    else {
        std::cerr << "Non boolean expression in " << fullArg << std::endl;
        std::cerr << "Taking vjets.cfg value for this option." << std::endl;
    }
}
