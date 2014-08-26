#ifndef _FILENAMESZJETS_h_
#define _FILENAMESZJETS_h_

//-- directory of input root files --------------------
const string FILESDIRECTORY("HistoFilesAugust/");
//---------- lets add basic information on samples inot common struct -------------------------------------------
struct processInfoStruct{
    string filename;
    double NEvents, xsec, xsecFrac, xsecError;
    int color;
    string legend;
};

const int DATAFILENAME(0);
const int DYMADGRAPHFILENAME(11); // Exclusive files
const processInfoStruct ProcessInfo[] = {
    //--  Name  ------------------------------- #events ---- xsec - branch - xsec error (%) -- color for plot -- name on legend
    {"Data_dR",                                  1,          1.,      1,         1,             kBlack,      " Data"},
    {"WJetsALL_MIX_UNFOLDING_dR",                76102995.,  36864.,  1,         0.03,          kPink,       " WJets"},
    {"TTJets_dR",		                         6923652.,   234.,    1,         0.10,          kBlue,       " TTJets"},  
    {"ZZJets2L2Nu_dR",		                     954911.,    17.654,  0.04039,   0.04,          kSpring+5,   " ZZJets2L2Nu"},
    {"ZZJets4L_dR",		                         4807893.,   17.654,  0.010196,  0.04,          kOrange,     " ZZJets4L"},
    {"ZZJets2L2Q_dR",		                     1936727.,   17.654,  0.14118,   0.04,          kOrange-3,   " ZZJets2L2Q"},
    {"WZJets3LNu_dR",		                     1995334.,   33.21,   0.032887,  0.04,          kRed+1,      " WZJets3LNu"},
    {"WZJets2L2Q_dR",		                     3215990.,   33.21,   0.068258,  0.04,          kPink-6,     " WZJets2L2Q"},
    {"WWJets2L2Nu_dR",		                     1933235.,   54.838,  0.10608 ,  0.04,          kViolet+5,   " WWJets2L2Nu"},
    {"Top_dR",		                             1.,         1,       1,         0.04,          kMagenta,    " Single Top"},
    {"DYJetsToLL_FromTau_50toInf_UNFOLDING_dR",  30459503.,  3531.8,  1,         0.033,         kAzure+4,    " DYtautau"},
    {"DYJetsToLL_MIX_50toInf_UNFOLDING_dR",      30459503.,  3531.8,  1,         0.04,          kAzure+10,   " DYJets"}, 
//    {"DYJetsToLL_50toInf_UNFOLDING_dR",          30459503.,  3531.8,  1,         0.04,          kAzure+10,   " DYJets"}, 
};

//--- first element must point to the data
//--- last element must point to the MC Signal
const int NFILESDYJETS(12);
const int FilesDYJets[NFILESDYJETS] = {0, 1, 10, 4, 9, 3, 5, 8, 7, 6, 2, 11};

const string DYPOWHEGFILENAME("DYJets_PowhegZ2jMiNLO_dR_GEN_CernMOJ");
const string DYSHERPAFILENAME("DY_Sherpa_2NLO4_HepMC_dR_Full_ListALL");

#endif
