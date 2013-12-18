#ifndef __variablesOfInterest__
#define __variablesOfInterest__

#include <TObject.h>
#include <TObjString.h>
#include <TList.h>

struct variableStruct{
   string name;
   bool log, decrease;  
   int MuSVDkterm, MuBayeskterm, ESVDkterm, EBayeskterm;
};

//--- Z Jets ------------------------------------

const int NVAROFINTERESTZJETS(62);
variableStruct VAROFINTERESTZJETS[] = {
   //--  Name  ------------------ log - decrease - Mu SVD kterm - Mu Bayes kterm - E SVD kterm - E Bayes kterm
   {"ZNGoodJets_Zexc",             1,      1,           6,              4,             3,            3},

   //-- jet Pt distribution
   {"FirstJetPt_Zinc1jet",         1,      1,           9,              5,             9,            9}, 
   {"FirstJetPt_2_Zinc1jet",       1,      1,          14,              6,            14,           10}, 
   {"SecondJetPt_Zinc2jet",        1,      1,          11,              8,            11,            7}, 
   {"SecondJetPt_2_Zinc2jet",      1,      1,          15,              8,            14,            8}, 
   {"ThirdJetPt_Zinc3jet",         1,      1,           8,              9,             8,            7}, 
   {"FourthJetPt_Zinc4jet",        1,      1,           6,              4,             6,            5}, 
   {"FifthJetPt_Zinc5jet",         1,      1,           4,              2,             4,            3},

   {"FirstHighestJetPt_Zinc1jet",  1,      1,           7,              4,             8,            3},
   {"FirstHighestJetPt_Zinc2jet",  1,      1,           9,              4,             8,            4},
   {"FirstHighestJetPt_Zinc3jet",  1,      1,           8,              4,             8,            3},
   {"FirstHighestJetPt_Zinc4jet",  1,      0,           5,              2,             7,            5},
   {"FirstHighestJetPt_Zinc5jet",  1,      0,           9,              3,             5,            5},

   {"SecondHighestJetPt_Zinc2jet", 1,      1,           9,              3,            11,            3},
   {"SecondHighestJetPt_Zinc3jet", 1,      1,          10,              3,            10,            4},
   {"SecondHighestJetPt_Zinc4jet", 1,      1,           9,              3,             9,            3},
   {"SecondHighestJetPt_Zinc5jet", 1,      0,           4,              2,             6,            4},

   {"ThirdHighestJetPt_Zinc3jet",  1,      1,           6,              2,             6,            2},
   {"ThirdHighestJetPt_Zinc4jet",  1,      1,           6,              3,             5,            2},
   {"ThirdHighestJetPt_Zinc5jet",  1,      1,           5,              3,             3,            3},

   //-- jets HT distribution
   {"JetsHT_Zinc1jet",             1,      1,           7,              4,             7,            3}, 
   {"JetsHT_2_Zinc1jet",           1,      1,           9,              4,             8,            4}, 
   {"JetsHT_Zinc2jet",             1,      1,           7,              3,             9,            4},
   {"JetsHT_2_Zinc2jet",           1,      1,           7,              3,             8,            4},
   {"JetsHT_Zinc3jet",             1,      1,           6,              3,             6,            6},
   {"JetsHT_Zinc4jet",             1,      1,           5,              5,             4,            4},
   {"JetsHT_Zinc5jet",             1,      1,           3,              2,             4,            3},

   //-- jet Eta distribution
   {"FirstJetEta_Zinc1jet",        0,      1,          28,              4,            18,            4},
   {"SecondJetEta_Zinc2jet",       0,      1,          11,              5,            16,            5}, 
   {"ThirdJetEta_Zinc3jet",        0,      1,          10,              4,             8,            4}, 
   {"FourthJetEta_Zinc4jet",       0,      1,           4,              4,             4,            5}, 
   {"FifthJetEta_Zinc5jet",        0,      1,           3,              2,             2,            2}, 

   //-- Z Mass distribution
   //{"ZMass_Zinc0jet",              0,      1,          19,             17,             7,           36},

   //-- Jets Mass distribution
   {"JetsMass_Zexc2jet",           0,      1,           7,              5,            13,            6},
   {"JetsMass_Zinc2jet",           0,      1,           9,              5,            13,            7},

   //-- DPS distribution
   {"SpTJets_Zexc2jet",            0,      0,           7,              4,             6,            4},
   {"SpTJets_Zinc2jet",            0,      0,           7,              4,             8,            4},
   {"SpT_Zexc2jet",                0,      0,          14,              3,             8,            3},
   {"SpT_Zinc2jet",                0,      0,          16,              3,             5,            3},
   {"dPhiJets_Zexc2jet",           0,      0,           4,              4,             4,            4},
   {"dPhiJets_Zinc2jet",           0,      0,           6,              4,             8,            4},
   {"PHI_Zexc2jet",                0,      0,           5,              5,             6,            4},
   {"PHI_Zinc2jet",                0,      0,          14,              4,            10,            4},
   {"PHI_T_Zexc2jet",              0,      0,           6,              6,             4,            6},
   {"PHI_T_Zinc2jet",              0,      0,           6,              6,             7,            5},
   {"SPhi_Zexc2jet",               0,      0,          18,              4,             9,            4},
   {"SPhi_Zinc2jet",               0,      0,           7,              4,             9,            4},

   {"SpTJets_LowPt_Zexc2jet",      0,      1,           9,             12,             7,            9},
   {"SpTJets_LowPt_Zinc2jet",      0,      1,           8,             12,             9,            8},
   {"SpT_LowPt_Zexc2jet",          0,      1,           6,             13,             4,            9},
   {"SpT_LowPt_Zinc2jet",          0,      1,           6,             12,            14,            9},
   {"dPhiJets_LowPt_Zexc2jet",     0,      0,           6,             13,             4,            9},
   {"dPhiJets_LowPt_Zinc2jet",     0,      0,           4,             12,             8,            9},
   {"PHI_LowPt_Zexc2jet",          0,      1,           7,              5,             4,            8},
   {"PHI_LowPt_Zinc2jet",          0,      1,           5,              5,             2,           15},
   {"PHI_T_LowPt_Zexc2jet",        0,      0,           3,              5,             7,            6},
   {"PHI_T_LowPt_Zinc2jet",        0,      0,           3,              4,             3,            6},
   {"SPhi_LowPt_Zexc2jet",         0,      0,          11,              7,             3,            6},
   {"SPhi_LowPt_Zinc2jet",         0,      0,           8,              7,             6,            6},
   // additional correlations  =----- NEED TP CHECK THE UNFOLDING PARAMTERS !!!!
   {"dEtaJets_Zinc2jet",           0,      0,           8,             10,             6,            6},
   {"dEtaJets_Zexc2jet",           0,      0,           8,             10,             6,            6},
   {"dEtaBosonJet_Zinc1",          0,      0,           8,             10,             6,            6},
   {"dEtaBosonJet_Zexc1",          0,      0,           8,             10,             6,            6},
   {"dEtaFirstJetZ_Zinc2jet",      0,      0,           8,             10,             6,            6},
   {"dEtaSecondJetZ_Zinc2jet"      0,      0,           8,             10,             6,            6}

}; 

TList *LISTOFVAROFINTERESTZJETS = new TList();

void makeLISTOFVAROFINTERESTZJETS(){
    for (int i(0); i < NVAROFINTERESTZJETS; i++){
        TObjString *name = new TObjString(VAROFINTERESTZJETS[i].name.c_str());
        LISTOFVAROFINTERESTZJETS->Add(name);
    }
}

//--- W Jets ------------------------------------

const int NVAROFINTERESTWJETS(54);
variableStruct VAROFINTERESTWJETS[] = {
    //--  Name  ------------------ log - decrease - Mu SVD kterm - Mu Bayes kterm - E SVD kterm - E Bayes kterm
    {"ZNGoodJets_Zexc",             1,      1,           4,              4,             4,            3},

    //-- jet Pt distribution
    {"FirstJetPt_Zinc1jet",         1,      1,           9,              5,             9,            5}, 
    {"SecondJetPt_Zinc2jet",        1,      1,           8,              6,             8,            7}, 
    {"ThirdJetPt_Zinc3jet",         1,      1,           5,              4,             5,            5}, 
    {"FourthJetPt_Zinc4jet",        1,      1,           5,              3,             4,            4}, 
    {"FifthJetPt_Zinc5jet",         1,      1,           4,              3,             3,            2},

    {"FirstHighestJetPt_Zinc1jet",  1,      1,           9,              4,             9,            3},
    {"FirstHighestJetPt_Zinc2jet",  1,      1,           9,              7,             9,            4},
    {"FirstHighestJetPt_Zinc3jet",  1,      1,           3,              4,             5,            4},
    {"FirstHighestJetPt_Zinc4jet",  1,      0,           3,              5,             3,            5},
    {"FirstHighestJetPt_Zinc5jet",  1,      0,           3,              2,             2,            2},

    {"SecondHighestJetPt_Zinc2jet", 1,      1,           8,              3,             8,            3},
    {"SecondHighestJetPt_Zinc3jet", 1,      1,           5,              4,             6,            4},
    {"SecondHighestJetPt_Zinc4jet", 1,      1,           3,              4,             3,            5},
    {"SecondHighestJetPt_Zinc5jet", 1,      0,           3,              2,             2,            4},

    {"ThirdHighestJetPt_Zinc3jet",  1,      1,           5,              2,             5,            4},
    {"ThirdHighestJetPt_Zinc4jet",  1,      1,           4,              3,             5,            2},
    {"ThirdHighestJetPt_Zinc5jet",  1,      1,           3,              3,             3,            3},

    //-- jets HT distribution
    {"JetsHT_Zinc1jet",             1,      1,           8,              4,             9,            3}, 
    {"JetsHT_Zinc2jet",             1,      1,          10,              4,            10,            4},
    {"JetsHT_Zinc3jet",             1,      1,           7,              3,             7,            5},
    {"JetsHT_Zinc4jet",             1,      1,           6,              3,             5,            9},
    {"JetsHT_Zinc5jet",             1,      1,           3,              2,             4,            2},

    //-- jet Eta distribution
    {"FirstJetEta_Zinc1jet",        0,      1,          13,              3,            15,            3},
    {"SecondJetEta_Zinc2jet",       0,      1,          11,              5,            11,            4}, 
    {"ThirdJetEta_Zinc3jet",        0,      1,          10,              4,             8,            4}, 
    {"FourthJetEta_Zinc4jet",       0,      1,           5,              4,             3,            4}, 
    {"FifthJetEta_Zinc5jet",        0,      1,           3,              2,             2,            2}, 

    //-- Z Mass distribution
    //{"ZMass_Zinc0jet",              0,      1,          19,             17,             7,           36},

    //-- Jets Mass distribution
    {"JetsMass_Zexc2jet",           0,      1,           9,              6,            10,            7},
    {"JetsMass_Zinc2jet",           0,      1,           9,              7,             9,            6},

    //-- DPS distribution
    {"SpTJets_Zexc2jet",            0,      0,           7,              4,             5,            4},
    {"SpTJets_Zinc2jet",            0,      0,           7,              5,             5,            4},
    {"SpT_Zexc2jet",                0,      0,          10,              4,             6,            4},
    {"SpT_Zinc2jet",                0,      0,          11,              5,             6,            3},
    {"dPhiJets_Zexc2jet",           0,      0,           7,              4,             5,            3},
    {"dPhiJets_Zinc2jet",           0,      0,           7,              4,             8,            3},
    {"PHI_Zexc2jet",                0,      0,           5,              5,             6,            6},
    {"PHI_Zinc2jet",                0,      0,          14,              6,            10,            5},
    {"PHI_T_Zexc2jet",              0,      0,           5,              7,             5,            6},
    {"PHI_T_Zinc2jet",              0,      0,           5,              7,             4,            6},
    {"SPhi_Zexc2jet",               0,      0,          18,              5,             9,            6},
    {"SPhi_Zinc2jet",               0,      0,           7,              5,             9,            5},

    {"SpTJets_LowPt_Zexc2jet",      0,      1,           4,              7,             6,           11},
    {"SpTJets_LowPt_Zinc2jet",      0,      1,           4,              7,             9,            8},
    {"SpT_LowPt_Zexc2jet",          0,      1,           4,              7,             3,            5},
    {"SpT_LowPt_Zinc2jet",          0,      1,           6,              8,             8,            5},
    {"dPhiJets_LowPt_Zexc2jet",     0,      0,           4,              6,             6,            7},
    {"dPhiJets_LowPt_Zinc2jet",     0,      0,           4,              7,             2,            6},
    {"PHI_LowPt_Zexc2jet",          0,      1,           7,              6,             4,           14},
    {"PHI_LowPt_Zinc2jet",          0,      1,           5,              5,             2,           15},
    {"PHI_T_LowPt_Zexc2jet",        0,      0,           3,              5,             7,            6},
    {"PHI_T_LowPt_Zinc2jet",        0,      0,           3,              4,             3,            6},
    {"SPhi_LowPt_Zexc2jet",         0,      0,          11,              7,             3,            6},
    {"SPhi_LowPt_Zinc2jet",         0,      0,           8,              7,             6,            6},
}; 

TList *LISTOFVAROFINTERESTWJETS = new TList();

void makeLISTOFVAROFINTERESTWJETS(){
    for (int i(0); i < NVAROFINTERESTWJETS; i++){
        TObjString *name = new TObjString(VAROFINTERESTWJETS[i].name.c_str());
        LISTOFVAROFINTERESTWJETS->Add(name);
    }
}
#endif

