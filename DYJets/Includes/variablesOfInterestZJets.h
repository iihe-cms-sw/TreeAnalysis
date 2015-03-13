#ifndef __VARIABLESOFINTERESTZJETS_H_
#define __VARIABLESOFINTERESTZJETS_H_

#include <TObject.h>
#include <TObjString.h>
#include <TList.h>

struct variableStruct{
   TString name;
   bool log, decrease;  
   int MuSVDkterm, MuBayeskterm, ESVDkterm, EBayeskterm, BayesktermCombine;
};

//--- Z Jets ------------------------------------

const unsigned int NVAROFINTERESTZJETS(22);
const variableStruct VAROFINTERESTZJETS[] = {
   //--  Name  ------------------ log - decrease - Mu SVD kterm - Mu Bayes kterm - E SVD kterm - E Bayes kterm  - E Bayes kterm COMBINE
   {"ZNGoodJets_Zexc",             1,      1,           7,              4,             3,            3 ,               3    }, // 0

   //-- jet Pt distribution
   {"FirstJetPt_Zinc1jet",         1,      1,          11,              5,             9,            9 ,               6    }, // 1
   {"SecondJetPt_Zinc2jet",        1,      1,          14,              8,            11,            7 ,               7    }, // 2
   {"ThirdJetPt_Zinc3jet",         1,      1,           6,              9,             8,            7 ,               7    }, // 3
   {"FourthJetPt_Zinc4jet",        1,      1,           4,              4,             6,            5 ,               4    }, // 4
   {"FifthJetPt_Zinc5jet",         1,      1,           3,              2,             4,            3 ,               2    }, // 5 

   //-- jets HT distribution
   {"JetsHT_Zinc1jet",             1,      1,           9,              4,             7,            3 ,               3    }, // 6
   {"JetsHT_Zinc2jet",             1,      1,           5,              3,             9,            4 ,               2    }, // 7
   {"JetsHT_Zinc3jet",             1,      1,           6,              3,             6,            6 ,               3    }, // 8
   {"JetsHT_Zinc4jet",             1,      1,           5,              5,             4,            4 ,               3    }, // 9
   {"JetsHT_Zinc5jet",             1,      1,           3,              2,             4,            3 ,               1    }, // 10       

   //-- jet Eta distribution
   {"FirstJetEta_Zinc1jet",        0,      1,          10,              4,            18,            4 ,               5    }, // 11
   {"SecondJetEta_Zinc2jet",       0,      1,           6,              5,            16,            5 ,               5    }, // 12
   {"ThirdJetEta_Zinc3jet",        0,      1,           4,              4,             8,            4 ,               5    }, // 13
   {"FourthJetEta_Zinc4jet",       0,      1,           4,              4,             4,            5 ,               4    }, // 14
   {"FifthJetEta_Zinc5jet",        0,      1,           3,              2,             2,            2 ,               1    }, // 15    

   //-- Jets Mass distribution
   {"JetsMass_Zinc2jet",           0,      1,           9,              5,            13,           11 ,               5    }, // 16
   {"ZPt_Zinc0jet",                0,      1,           9,              5,            13,           11 ,               5    }, // 17
   {"ZAbsRapidity_Zinc1jet",       0,      1,           9,              5,            13,           11 ,               5    }, // 18
   {"SumZJetRapidity_Zinc1jet",    0,      1,           9,              5,            13,           11 ,               5    }, // 19
   {"DifZJetRapidity_Zinc1jet",    0,      1,           9,              5,            13,           11 ,               5    }, // 20
   {"FirstJetAbsRapidity_Zinc1jet",0,      1,           9,              5,            13,           11 ,               5    }, // 21


}; 

int findVariable(const TString &variable);
#endif

