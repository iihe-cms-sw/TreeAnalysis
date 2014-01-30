{
  string srcdir = "Sources/";

  vector<string> sources;
  sources.push_back("getFilesAndHistograms");
  sources.push_back("functions");
  sources.push_back("writeFastPlotsTex");
  sources.push_back("unfoldingFunctions");
  sources.push_back("FinalUnfold");
  sources.push_back("FinalUnfoldAndCombination");

  //--- Load shaared libraries ---
  unsigned int nSources = sources.size();
  for (unsigned int i(0); i < nSources; i++){
      cout <<"Compiling " << srcdir + sources[i] << ".cc" << endl;
      gROOT->ProcessLine(string(".L " + srcdir + sources[i] + ".cc+").c_str());
  }

  FinalUnfold(0, 1);
}
