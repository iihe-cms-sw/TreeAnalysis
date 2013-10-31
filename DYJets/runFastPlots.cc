{
  string srcdir = "Sources/";
  string incdir = "Includes/";

  vector<string> sources;
  sources.push_back("getFilesAndHistograms");
  sources.push_back("functions");
  sources.push_back("writeFastPlotsTex");
  sources.push_back("unfoldingFunctions");
  sources.push_back("FastPlots");
  
  //--- Load shaared libraries ---
  //gSystem->Load("checkForCompilationNeeds.so");
  //checkForCompilationNeeds(srcdir, sources);
  unsigned int nSources = sources.size();
  for (unsigned int i(0); i < nSources; i++){
    //gSystem->Load(string(sources[i] + "_cc.so").c_str());
    cout <<"Compiling " << srcdir + sources[i] << ".cc" << endl;
    gROOT->ProcessLine(string(".L " + srcdir + sources[i] + ".cc++").c_str());
  }
  
  //FastPlots();
  FastPlots("FirstJetPt_Zinc1jet");
  //FastPlots("FirstJetPt_1_Zinc1jet");
  //FastPlots("FirstJetPt_2_Zinc1jet");
  //FastPlots("FirstJetPt_3_Zinc1jet");
  //FastPlots("FirstJetPt_4_Zinc1jet");
}
