{
  cout << "\nI'm executing rootlogon.C\n" << endl;
  TString currentFile_ =  __FILE__;
  TString currentWorkingDir_ = currentFile_(0, currentFile_.Index("./rootlogon.C"));
  cout << "The Working Direcotry is:\n\t" << currentWorkingDir_ << "\n"<< endl;
  gErrorIgnoreLevel = kError;
  TString incdir_ = currentWorkingDir_ + "Includes/";
  TString lhapdfdir_ = "/user/aleonard/lhapdf-5.9.1/include/";
  //TString lhapdfdir = "/usr/local/include/";
  TString roounfolddir_ = currentWorkingDir_ + "RooUnfold-1.1.1/";

  cout << "--------------------------------------------------------------------------------\n" << endl; 
  cout << "Adding " << incdir_ << " to includes directories..." << endl;
  gSystem->AddIncludePath("-I" + incdir_);
  cout << "Adding " << lhapdfdir_ << " to includes directories..." << endl;
  gSystem->AddIncludePath("-I" + lhapdfdir_);
  cout << "Adding " << roounfolddir_ << "src" << " to includes directories..." << endl;
  gSystem->AddIncludePath("-I" + roounfolddir_ + "src");
  cout << "Loading RooUnfold libraries..." << endl;
  gSystem->Load(roounfolddir_ + "libRooUnfold");
  cout << "\n";
  cout << "--------------------------------------------------------------------------------\n" << endl; 
}
