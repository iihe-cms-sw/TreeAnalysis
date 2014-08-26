{
    TString srcDir = "Sources/";

    //--- Loads configuration ---------------------------------------------------------
    gROOT->ProcessLine(".L " + srcDir + "Config.cc+");
    Config cfg;
    //----------------------------------------------------------------------------------

    //--- Load shared libraries -------------------------------------------------------
    vector<TString> sources;
    sources.push_back(srcDir + "getFilesAndHistogramsZJets.cc+");
    sources.push_back(srcDir + "UnfoldingZJets.cc+");

    unsigned int nSources = sources.size();
    for (unsigned int i(0); i < nSources; i++){
        std::cout << "Compiling or loading " << sources[i] << std::endl;
        gROOT->ProcessLine(".L " + sources[i]);
    }
    //----------------------------------------------------------------------------------
    
    cout << __DATE__ << " at " << __TIME__ << endl;
    UnfoldingZJets();
    cout << __DATE__ << " at " << __TIME__ << endl;


}
