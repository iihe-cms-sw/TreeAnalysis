#ifndef __fileNames__
#define __fileNames__

//-- directory of input root files --------------------
string FILESDIRECTORY = "HistoFiles/";
//---------- lets add basic information on samples inot common struct -------------------------------------------
struct processInfoStruct{
   string filename ;
   double NEvents,xsec, xsecFrac, xsecError;
   int color;
   string legend;
};

const int NFilesWJets = 14 ; 
const int NFilesFull = 27 ; 
processInfoStruct ProcessInfo[] = {
   //--  Name  ------number of events           - xsec  - branch  -xsec error (%)  - coclor for plot -- name on legend
   {"Data_dR_5311",             1,                1.,        1,     1        , kBlack  ,   " Data"},
   {"WJetsALL_MIX_UNFOLDING_dR_5311", 76102995.,  37509.,    1,     0.05     , kPink     , " WJets"},
   {"ZZ_dR_5311",	9799908.,                17.654 ,    1,     0.04     , kOrange ,   " ZZ"},    
   {"WZ_dR_5311",	10000283.,	         33.21  ,    1,     0.05     , kRed+1  ,   " WZ"},	
   {"WW_dR_5311",	10000431.,	         54.838 ,    1,     0.05     , kViolet+5 , " WW"},

   {"T_s_channel_dR_5311",	     259961.,     3.79  ,    1,     0.10     , kMagenta     ," Ts"},
   {"T_t_channel_dR_5311",	    3758227.,    56.4   ,    1,     0.10     , kMagenta     ," Tt"},
   {"T_tW_channel_dR_5311",	     497658.,    11.1   ,    1,     0.10     , kMagenta     ," Ttw"},
   {"Tbar_s_channel_dR_5311",        139974.,     1.76  ,    1,     0.10     , kMagenta     ," Tbars"},
   {"Tbar_t_channel_dR_5311",       1903681.,    30.7   ,    1,     0.10     , kMagenta     ," Tbart"},
   {"Tbar_tW_channel_dR_5311",       493460.,    11.1   ,    1,     0.10     , kMagenta     ," TbartW"},

   {"TTJets_dR_5311",		    6923652.,   234.    ,    1,     0.10     , kBlue     ," TTJets"},  
   {"DYJets10to50_dR_5311",	   11707222.,   860.5   ,    1,     0.04     , kAzure-4    ," DY"},
   {"DYJets_MIX_UNFOLDING_dR_5311_Inf3", 30459503., 3503.7,  1,     0.04     , kAzure+10    ," DYJets"}, /// up to this line files are set for W+jet s and TTbar
   {"ZZJets2L2Nu_dR_5311",		 954911   , 17.654  , 0.04039,   0.04    , kSpring+5        , " ZZJets2L2Nu"},
   {"ZZJets4L_dR_5311",		        4807893   , 17.654  , 0.010196,  0.04    , kOrange    , " ZZJets4L"},
   {"ZZJets2L2Q_dR_5311",		1936727   , 17.654  , 0.14118,   0.04    , kOrange-3  , " ZZJets2L2Q"},
   {"WZJets3LNu_dR_5311",		1995334   , 33.21   , 0.032887,  0.04    , kRed+1     , " WZJets3LNu"},
   {"WZJets2L2Q_dR_5311",		3215990   , 33.21   , 0.068258,  0.04    , kPink-6    , " WZJets2L2Q"},
   {"WWJets2L2Nu_dR_5311",		1933235   , 54.838  , 0.10608 ,  0.04    , kViolet+5  , " WWJets2L2Nu"},
   {"Top_dR_5311",		         1   , 1   , 1 ,  0.04                   , kMagenta   , " Single Top"},

   {"DYJets_FromTau_UNFOLDING_dR_5311_Inf3", 30459503., 3503.7,  1,     0.04     , kAzure+4    , " DYtautau"},
   {"DYJets10toInf3_dR_5311",	         1,    1  ,  1,     0.04                 , kAzure+10   , " DY"},
   {"DataQCD_dR_5311",	                 1,    1  ,  1,     0.04              	 , kYellow     , " QCD"},
   {"WJetsALL_UNFOLDING_dR_5311",         76102995.,  37509.,    1,     0.05     , kPink       , " WJets"},
   {"WJetsALL_MIX_dR_5311",               76102995.,  37509.,    1,     0.05     , kPink       , " WJets"}, // relative weight for mixed DY and WJ files are set inthe code
   {"WJetsALL_dR_5311",                   76102995.,  37509.,    1,     0.05     , kPink       , " WJets"},

};
const int NFilesDYJets = 12 ;
int FilesDYJets[NFilesDYJets] = { 0, 13, 11, 14, 15, 16, 17 , 18, 19 ,  20, 21 , 1};
const int NFilesTTbar = 9 ;
int FilesTTbarWJets[NFilesTTbar] =   { 0, 1 , 11, 22, 20, 23 , 2,  3,  4 };
//-- file names ---------------------------------------
string FILENAMESTTbar[NFilesTTbar] = {
   "Data_dR_5311",
   "ZZ_dR_5311",
   "WZ_dR_5311",
   "WW_dR_5311",
   "WJetsALL_UNFOLDING_dR_5311",
   "DataQCD_dR_5311",
   "Top_dR_5311",
   "TTJets_dR_5311",
   "DYJets10toInf3_dR_5311",
};
const int NfilesVJets = 14 ;
string FILENAMES[NfilesVJets] = {
   "Data_dR_5311",
   "WJetsALL_MIX_dR_5311",
   "DYJets_FromTau_UNFOLDING_dR_5311_Inf3",
   "Top_dR_5311",
   "ZZJets2L2Nu_dR_5311",
   "ZZJets4L_dR_5311",
   "ZZJets2L2Q_dR_5311",
   "WZJets3LNu_dR_5311",
   "WZJets2L2Q_dR_5311",
   "WWJets2L2Nu_dR_5311",
   "TTJets_dR_5311",
   //"DYJets_UNFOLDING_NOLEPTON_5311",
   //"DYJets_UNFOLDING_dR_5311_Inf3",
   "DYJets_MIX_UNFOLDING_dR_5311_Inf3",
  // "DY01234Jets_UNFOLDING_dR_5311_Inf3",
   //"DYJets_PowhegNLO1Jet_GEN",
   "DYJets_PowhegZ2jMiNLO_dR_GEN_Cern",
   //"DYJets_UNFOLDING_Sherpa",
   "DY_Sherpa_1NLO4_HepMC_dR_Full_List"
}; 
//-----------------------------------------------------

string DATAFILENAME = FILENAMES[0];

string DYMADGRAPHFILENAME = FILENAMES[10];
string DYPOWHEGFILENAME = FILENAMES[11];
string DYSHERPAFILENAME = FILENAMES[12];

string BGFILENAMES[9] = {
   FILENAMES[1],
   FILENAMES[2],
   FILENAMES[3],
   FILENAMES[4],
   FILENAMES[5],
   FILENAMES[6],
   FILENAMES[7],
   FILENAMES[8],
   FILENAMES[9],
};
string BGFILENAMESGrouped[8] = {
   FILENAMES[1],
   FILENAMES[2],
   FILENAMES[3],
   FILENAMES[4],
   FILENAMES[5],
   FILENAMES[6],
   FILENAMES[7],
   FILENAMES[9],
};

string GenMCFILENAMES[5] = {
   "DYJets_GEN_Z2_MPIoff",
   "DYJets_GEN_Z2Star",
   "DYJets_GEN_Z2Star_MPIoff",
   "DYJets_P8_ZmumJets_MPIon_GEN_Tune4C",
   "DYJets_PowhegZjjMiNLO_GEN"
};
string DYPOWHEGZjjFILENAME = GenMCFILENAMES[4];
string DYSHERPAZjFILENAME    = "DYJets_UNFOLDING_Sherpa";
#endif

