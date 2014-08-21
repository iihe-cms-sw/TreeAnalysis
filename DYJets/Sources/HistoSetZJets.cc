#define PI 3.14159265359
#include <iostream>
#include <TH1.h>
#include <TH2.h>
#include <RooUnfoldResponse.h>
#include <sstream>
#include "HistoSetZJets.h"

using namespace std;

ClassImp(HistoSetZJets)

HistoSetZJets::~HistoSetZJets()
{
}

vector<double> HistoSetZJets::makeVector(int num, ...)
{
    va_list list;
    va_start(list, num);
    vector<double> vec;
    for (int i(0); i < num; i++) {
        double next = va_arg(list, double);
        vec.push_back(next);
    }
    va_end(list);
    return vec;
}

void HistoSetZJets::insertVector(vector<double>& veca, int num, ...)
{
    va_list list;
    va_start(list, num);
    vector<double> vecb;
    for (int i(0); i < num; i++) {
        double next = va_arg(list, double);
        vecb.push_back(next);
    }
    va_end(list);
    veca.insert(veca.end(), vecb.begin(), vecb.end());
}

TH1D* HistoSetZJets::newTH1D(string name, string title, string xTitle, int nBins, double *xBins){
    TH1D* hist = new TH1D(name.c_str(), title.c_str(), nBins, xBins);
    hist->GetXaxis()->SetTitle(xTitle.c_str());
    hist->GetYaxis()->SetTitle("# Events");
    listOfHistograms.push_back(hist);
    return hist;
}

TH1D* HistoSetZJets::newTH1D(string name, string title, string xTitle, vector<double>& xBinsVect)
{
    int nBins = xBinsVect.size()-1;
    double *xBins = new double[xBinsVect.size()];
    std::copy(xBinsVect.begin(), xBinsVect.end(), xBins);
    TH1D* hist = new TH1D(name.c_str(), title.c_str(), nBins, xBins);
    hist->GetXaxis()->SetTitle(xTitle.c_str());
    hist->GetYaxis()->SetTitle("# Events");
    delete [] xBins;
    listOfHistograms.push_back(hist);
    return hist;
}


TH1D* HistoSetZJets::newTH1D(string name, string title, string xTitle, int nBins, double xLow, double xUp){
    TH1D* hist = new TH1D(name.c_str(), title.c_str(), nBins, xLow, xUp);
    hist->GetXaxis()->SetTitle(xTitle.c_str());
    hist->GetYaxis()->SetTitle("# Events");
    hist->SetOption("HIST");
    listOfHistograms.push_back(hist);
    return hist;
}

TH2D* HistoSetZJets::newTH2D(string name, string title, int nBinsX, double *xBins, int nBinsY, double *yBinsY){
    TH2D* hist = new TH2D(name.c_str(), title.c_str(), nBinsX, xBins, nBinsY, yBinsY);
    hist->GetZaxis()->SetTitle("# Events");
    listOfHistograms.push_back(hist);
    return hist;
}

TH2D* HistoSetZJets::newTH2D(string name, string title, int nBinsX, double *xBins, int nBinsY, double yLow, double yUp){
    TH2D* hist = new TH2D(name.c_str(), title.c_str(), nBinsX, xBins, nBinsY, yLow, yUp);
    hist->GetZaxis()->SetTitle("# Events");
    listOfHistograms.push_back(hist);
    return hist;
}

TH2D* HistoSetZJets::newTH2D(string name, string title, int nBinsX, double xLow, double xUp, int nBinsY, double *yBins){
    TH2D* hist = new TH2D(name.c_str(), title.c_str(), nBinsX, xLow, xUp, nBinsY, yBins);
    hist->GetZaxis()->SetTitle("# Events");
    listOfHistograms.push_back(hist);
    return hist;
}

TH2D* HistoSetZJets::newTH2D(string name, string title, int nBinsX, double xLow, double xUp, int nBinsY, double yLow, double yUp){
    TH2D* hist = new TH2D(name.c_str(), title.c_str(), nBinsX, xLow, xUp, nBinsY, yLow, yUp);
    hist->GetZaxis()->SetTitle("# Events");
    hist->SetOption("HIST");
    listOfHistograms.push_back(hist);
    return hist;
}

RooUnfoldResponse* HistoSetZJets::newResp(TH1D* reco, TH1D* gen)
{
    RooUnfoldResponse *response = new RooUnfoldResponse(reco, gen);
    listOfResponses.push_back(response);
    return response;
}

RooUnfoldResponse* HistoSetZJets::newResp(TH2D* reco, TH2D* gen)
{
    RooUnfoldResponse *response = new RooUnfoldResponse(reco, gen);
    listOfResponses.push_back(response);
    return response;
}

HistoSetZJets::HistoSetZJets(string leptonFlavor)
{
    TH1::SetDefaultSumw2();
    TH2::SetDefaultSumw2();

    string ZpT = "p_{T}(Z) [GeV]", Zrap = "y(Z)", Zeta = "#eta(Z)";
    string HT = "H_{T}(jets) [GeV]", Mjj = "M_{j_{1}j_{2}} [GeV]", jSpt = "#Delta_{pT}^{rel}(j_{1}j_{2})", jdPhi = "#Delta#phi(j_{1}j_{2})", jdEta = "#Delta#eta(j_{1}j_{2})";
    string Mll = "M_{#mu#mu} [GeV]", leta = "#eta(#mu)", lphi = "#phi(#mu)",lpT = "p_{T}(#mu) [GeV]", ldPhi = "#Delta#phi(#mu_{1}#mu_{2})", ldEta = "#Delta#eta(#mu_{1}#mu_{2})", ldR = "#DeltaR(#mu_{1}#mu_{2})";
    string lSpt = "#Delta_{pT}^{rel}(#mu_{1}#mu_{2})";
    string Spt = "#Delta_{pT}^{rel}(j_{1}j_{2}#mu_{1}#mu_{2})";
    string Sphi = "Sphi(j_{1}j_{2}#mu_{1}#mu_{2})";
    string lJetdEta = "#Delta#eta(#mu_{1}#mu_{2},j_{1})";

    bool doWJets = false;
    if (leptonFlavor == "Electrons" || leptonFlavor == "DE" || leptonFlavor == "DE_") {
        Mll = "M_{ee} [GeV]";
        leta = "#eta(e)";
        lpT = "p_{T}(e) [GeV]";
        ldPhi = "#Delta#phi(e_{1}e_{2})";
        ldEta = "#Delta#eta(e_{1}e_{2})";
        ldR = "#DeltaR(e_{1}e_{2})";
        lSpt = "#Delta_{pT}^{rel}(e_{1}e_{2})";
        Spt = "#Delta_{pT}^{rel}(j_{1}j_{2}e_{1}e_{2})";
        Sphi = "Sphi(j_{1}j_{2}e_{1}e_{2})";
        lJetdEta = "#Delta#eta(e_{1}e_{2},j_{1})";
    }
    else if ( leptonFlavor == "Electron" || leptonFlavor == "SE" || leptonFlavor == "SE_") {
        doWJets = true ; 
        Mll = "M_{e#nu} [GeV]";
        leta = "#eta(e)";
        lpT = "p_{T}(e) [GeV]";
        ldPhi = "#Delta#phi(e_{1}#nu_{2})";
        ldEta = "#Delta#eta(e_{1}#nu_{2})";
        ldR = "#DeltaR(e_{1}#nu_{2})";
        lSpt = "#Delta_{pT}^{rel}(e_{1}#nu_{2})";
        Spt = "#Delta_{pT}^{rel}(j_{1}j_{2}e_{1}#nu_{2})";
        Sphi = "Sphi(j_{1}j_{2}e_{1}#nu_{2})";
        lJetdEta = "#Delta#eta(e,j_{1})";

    } 
    else if ( leptonFlavor == "Muon" || leptonFlavor == "SMu" || leptonFlavor == "SMu_") {
        doWJets = true ;
        Mll = "M_{#mu#nu} [GeV]";
        ldPhi = "#Delta#phi(#mu_{1}#nu_{2})";
        ldEta = "#Delta#eta(#mu_{1}#nu_{2})";
        ldR = "#DeltaR(e_{1}#nu_{2})";
        lSpt = "#Delta_{pT}^{rel}(#mu_{1}#nu_{2})";
        Spt = "#Delta_{pT}^{rel}(j_{1}j_{2}#mu_{1}#nu_{2})";
        Sphi = "Sphi(j_{1}j_{2}#mu_{1}#nu_{2})";
        lJetdEta = "#Delta#eta(#mu,j_{1})";

    }


    /*
    /// for 7TeV
    int nJetPt_Zinc1jet(12);
    double jetPt_Zinc1jet[13] = {20, 30, 40, 52, 68, 88, 113, 144, 184, 234, 297, 377, 480};
    int nJetPt_Zinc2jet(11);
    double jetPt_Zinc2jet[12] = {20, 30, 40, 52, 68, 88, 113, 144, 184, 234, 297, 377};
    int nJetPt_Zinc3jet(8);
    double jetPt_Zinc3jet[9] =  {20, 30, 40, 52, 68, 88, 113, 144, 184};
    int nJetPt_Zinc4jet(6);
    double jetPt_Zinc4jet[7] =  {20, 30, 40, 52, 68, 88, 113};
    int nJetPt_Zinc5jet(5);
    double jetPt_Zinc5jet[6] =  {20, 30, 40, 52, 68, 88};

    // for extend to 10
    //int nJetPt_Zinc1jet(14);
    //double jetPt_Zinc1jet[15] = {10, 15, 20, 30, 40, 52, 68, 88, 113, 144, 184, 234, 297, 377, 480};
    //int nJetPt_Zinc2jet(13);
    //double jetPt_Zinc2jet[12] = {10, 15, 20, 30, 40, 52, 68, 88, 113, 144, 184, 234, 297, 377};
    //int nJetPt_Zinc3jet(10);
    //double jetPt_Zinc3jet[11] =  {10, 15, 20, 30, 40, 52, 68, 88, 113, 144, 184};
    //int nJetPt_Zinc4jet(8);
    //double jetPt_Zinc4jet[9] =  {10, 15, 20, 30, 40, 52, 68, 88, 113};
    //int nJetPt_Zinc5jet(7);
    //double jetPt_Zinc5jet[8] =  {10, 15, 20, 30, 40, 52, 68, 88};

    int nJetHT_Zinc1jet(12);
    double jetHT_Zinc1jet[13] = {20, 30, 45, 65, 91, 125, 170, 230, 306, 406, 536, 707, 932};
    int nJetHT_Zinc2jet(12);
    double jetHT_Zinc2jet[13] = {40, 60, 75, 95, 121, 155, 200, 260, 336, 436, 566, 737, 962};
    int nJetHT_Zinc3jet(12);
    double jetHT_Zinc3jet[13] = {60, 75, 90, 105, 125, 151, 185, 230, 290, 366, 466, 586, 767};
    int nJetHT_Zinc4jet(11);
    double jetHT_Zinc4jet[12] = {80, 100, 120, 140, 167, 203, 253, 320, 410, 530, 690, 910};
    int nJetHT_Zinc5jet(9);
    double jetHT_Zinc5jet[10] = {100, 125, 150, 180, 222, 282, 365, 485, 650, 880};
    */

    /// for 8TeV
    /*int nJetPt_Zinc1jet(11);
      double jetPt_Zinc1jet[12] = {30, 40, 52, 68, 88, 113, 144, 184, 234, 297, 377, 480};
      int nJetPt_Zinc2jet(10);
      double jetPt_Zinc2jet[11] = {30, 40, 52, 68, 88, 113, 144, 184, 234, 297, 377};
      int nJetPt_Zinc3jet(7);
      double jetPt_Zinc3jet[8] =  {30, 40, 52, 68, 88, 113, 144, 184};
      int nJetPt_Zinc4jet(5);
      double jetPt_Zinc4jet[6] =  {30, 40, 52, 68, 88, 113};
      int nJetPt_Zinc5jet(4);
      double jetPt_Zinc5jet[5] =  {30, 40, 52, 68, 88};
      */
    // for extend to 20
    //int nJetPt_Zinc1jet(13);
    //double jetPt_Zinc1jet[14] = {20, 24, 30, 40, 52, 68, 88, 113, 144, 184, 234, 297, 377, 480};
    //int nJetPt_Zinc2jet(12);
    //double jetPt_Zinc2jet[13] = {20, 24, 30, 40, 52, 68, 88, 113, 144, 184, 234, 297, 377};
    //int nJetPt_Zinc3jet(9);
    //double jetPt_Zinc3jet[10] = {20, 24, 30, 40, 52, 68, 88, 113, 144, 184};

    int nJetPt_Zinc1jet(22);
    double jetPt_Zinc1jet[23] = {20, 24, 30, 39, 49, 60, 72, 85, 100, 117, 136, 157, 187, 220, 258, 300, 350, 400, 450, 500, 590, 700, 1000};

    int nJetPt_Zinc2jet(21);
    double jetPt_Zinc2jet[22] = {20, 24, 30, 39, 49, 60, 72, 85, 100, 117, 136, 157, 187, 220, 258, 300, 350, 400, 450, 500, 590, 800};

    int nJetPt_Zinc3jet(11);
    double jetPt_Zinc3jet[12]   = {20, 24, 30, 39, 49, 62, 78, 105, 142, 185, 235, 300};

    int nJetPt_Zinc4jet(8);
    double jetPt_Zinc4jet[9]   = {20, 24, 30, 39, 49, 62, 78, 96, 150};

    int nJetPt_Zinc5jet(6);
    double jetPt_Zinc5jet[7] =  {20, 24, 30, 39, 49, 62, 100};

    int nJetHT_Zinc1jet(17);
    double jetHT_Zinc1jet[18] = {30, 39, 49, 62, 78, 96, 118, 150, 190, 240, 300, 370, 450, 540, 650, 800, 1000, 1500};

    int nJetHT_Zinc2jet(13);
    double jetHT_Zinc2jet[14] = {60, 78, 96, 118, 150, 190, 240, 300, 370, 450, 540, 650, 800, 1200};

    int nJetHT_Zinc3jet(10);
    double jetHT_Zinc3jet[11]   = {90, 105, 125, 151, 185, 230, 290, 366, 466, 586, 767};

    int nJetHT_Zinc4jet(9);
    double jetHT_Zinc4jet[10] = {120, 140, 167, 203, 253, 320, 410, 530, 690, 910};

    int nJetHT_Zinc5jet(7);
    double jetHT_Zinc5jet[8] =  {150, 180, 222, 282, 365, 485, 650, 880};


    NumberPFcandidates                  = newTH1D("NumberPFcandidates",                  "NumberPFcandidates",           "Number of lepton PF candidates",    20, -0.5, 19.5);

    ZMass_lowDeltaR                     = newTH1D("ZMass_lowDeltaR",                     "ZMass_lowDeltaR",                             Mll,    120, 50, 169);
    ZMass_Zinc0jet                      = newTH1D("ZMass_Zinc0jet",                      "Z Invariant Mass (N_{jets} #geq 0)",          Mll,    111, 50, 260 );

    genZMass_Zinc0jet                   = newTH1D("genZMass_Zinc0jet",                   "Z Invariant Mass (N_{jets} #geq 0)",          Mll,    111, 50, 260 );

    ZPt_Zinc0jet                        = newTH1D("ZPt_Zinc0jet",                        "Z p_{T} (N_{jets} #geq 0)",                   ZpT,    40, 0, 400);
    ZPt_Zinc1jet                        = newTH1D("ZPt_Zinc1jet",                        "Z p_{T} (N_{jets} #geq 1)",                   ZpT,    40, 0, 400);
    ZPt_Zinc2jet                        = newTH1D("ZPt_Zinc2jet",                        "Z p_{T} (N_{jets} #geq 2)",                   ZpT,    40, 0, 400);

    genZPt_Zinc0jet                     = newTH1D("genZPt_Zinc0jet",                     "gen Z p_{T} (N_{jets} #geq 0)",               ZpT,    40, 0, 400);
    genZPt_Zinc1jet                     = newTH1D("genZPt_Zinc1jet",                     "gen Z p_{T} (N_{jets} #geq 1)",               ZpT,    40, 0, 400);
    genZPt_Zinc2jet                     = newTH1D("genZPt_Zinc2jet",                     "gen Z p_{T} (N_{jets} #geq 2)",               ZpT,    40, 0, 400);

    ZPt_Zexc0jet                        = newTH1D("ZPt_Zexc0jet",                        "Z p_{T} (N_{jets} = 0)",                      ZpT,    40, 0, 400);
    ZPt_Zexc1jet                        = newTH1D("ZPt_Zexc1jet",                        "Z p_{T} (N_{jets} = 1)",                      ZpT,    40, 0, 400);
    ZPt_Zexc2jet                        = newTH1D("ZPt_Zexc2jet",                        "Z p_{T} (N_{jets} = 2)",                      ZpT,    40, 0, 400);

    ZRapidity_Zinc0jet                  = newTH1D("ZRapidity_Zinc0jet",                  "Z Rapidity (N_{jets} #geq 0)",                Zrap,   30,-3, 3);
    ZRapidity_Zinc1jet                  = newTH1D("ZRapidity_Zinc1jet",                  "Z Rapidity (N_{jets} #geq 1)",                Zrap,   30,-3, 3);
    ZRapidity_Zinc2jet                  = newTH1D("ZRapidity_Zinc2jet",                  "Z Rapidity (N_{jets} #geq 2)",                Zrap,   30,-3, 3);

    genZRapidity_Zinc0jet               = newTH1D("genZRapidity_Zinc0jet",               "gen Z Rapidity (N_{jets} #geq 0)",            Zrap,   30,-3, 3);
    genZRapidity_Zinc1jet               = newTH1D("genZRapidity_Zinc1jet",               "gen Z Rapidity (N_{jets} #geq 1)",            Zrap,   30,-3, 3);
    genZRapidity_Zinc2jet               = newTH1D("genZRapidity_Zinc2jet",               "gen Z Rapidity (N_{jets} #geq 2)",            Zrap,   30,-3, 3);

    ZRapidity_Zexc0jet                  = newTH1D("ZRapidity_Zexc0jet",                  "Z Rapidity (N_{jets} = 0)",                   Zrap,   30,-3, 3);
    ZRapidity_Zexc1jet                  = newTH1D("ZRapidity_Zexc1jet",                  "Z Rapidity (N_{jets} = 1)",                   Zrap,   30,-3, 3);
    ZRapidity_Zexc2jet                  = newTH1D("ZRapidity_Zexc2jet",                  "Z Rapidity (N_{jets} = 2)",                   Zrap,   30,-3, 3);

    ZEta_Zinc0jet                       = newTH1D("ZEta_Zinc0jet",                       "Z #eta (N_{jets} #geq 0)",                    Zeta,   30,-3, 3);
    ZEta_Zinc1jet                       = newTH1D("ZEta_Zinc1jet",                       "Z #eta (N_{jets} #geq 1)",                    Zeta,   30,-3, 3);
    ZEta_Zinc2jet                       = newTH1D("ZEta_Zinc2jet",                       "Z #eta (N_{jets} #geq 2)",                    Zeta,   30,-3, 3);

    genZEta_Zinc0jet                    = newTH1D("genZEta_Zinc0jet",                    "gen Z #eta (N_{jets} #geq 0)",                Zeta,   30,-3, 3);
    genZEta_Zinc1jet                    = newTH1D("genZEta_Zinc1jet",                    "gen Z #eta (N_{jets} #geq 1)",                Zeta,   30,-3, 3);
    genZEta_Zinc2jet                    = newTH1D("genZEta_Zinc2jet",                    "gen Z #eta (N_{jets} #geq 2)",                Zeta,   30,-3, 3);

    ZEta_Zexc0jet                       = newTH1D("ZEta_Zexc0jet",                       "Z #eta (N_{jets} = 0)",                       Zeta,   30,-3, 3);
    ZEta_Zexc1jet                       = newTH1D("ZEta_Zexc1jet",                       "Z #eta (N_{jets} = 1)",                       Zeta,   30,-3, 3);
    ZEta_Zexc2jet                       = newTH1D("ZEta_Zexc2jet",                       "Z #eta (N_{jets} = 2)",                       Zeta,   30,-3, 3);

    lepEta_Zinc0jet                     = newTH1D("lepEta_Zinc0jet",                     "1st & 2nd lep #eta (N_{jets} #geq 0)",        leta,   24,-2.4, 2.4);

    lepPhi_Zinc0jet                     = newTH1D("lepPhi_Zinc0jet",                     "1st & 2nd lep #phi (N_{jets} #geq 0)",           lphi,   24,-PI, PI);

    genlepEta_Zinc0jet                  = newTH1D("genlepEta_Zinc0jet",                  "1st & 2nd lep #eta (N_{jets} #geq 0)",        leta,   24,-2.4, 2.4);  

    lepEta_Zexc0jet                     = newTH1D("lepEta_Zexc0jet",                     "1st & 2nd lep #eta (N_{jets} = 0)",           leta,   24,-2.4, 2.4);  

    lepPhi_Zexc0jet                     = newTH1D("lepPhi_Zexc0jet",                     "1st & 2nd lep #phi (N_{jets} = 0)",           lphi,   24,-PI, PI);


    FirstJetEtaFull_Zinc1jet                = newTH1D("FirstJetEtaFull_Zinc1jet",                "1st jet #eta (N_{jets} #geq 1)",              "#eta(j_{1})",  48,-2.4, 2.4);
    SecondJetEtaFull_Zinc2jet               = newTH1D("SecondJetEtaFull_Zinc2jet",               "2nd jet #eta (N_{jets} #geq 2)",              "#eta(j_{2})",  48,-2.4, 2.4);
    ThirdJetEtaFull_Zinc3jet                = newTH1D("ThirdJetEtaFull_Zinc3jet",                "3rd jet #eta (N_{jets} #geq 3)",              "#eta(j_{3})",  16,-2.4, 2.4);
    FourthJetEtaFull_Zinc4jet               = newTH1D("FourthJetEtaFull_Zinc4jet",               "4th jet #eta (N_{jets} #geq 4)",              "#eta(j_{4})",   8,-2.4, 2.4);
    FifthJetEtaFull_Zinc5jet                = newTH1D("FifthJetEtaFull_Zinc5jet",                "5th jet #eta (N_{jets} #geq 5)",              "#eta(j_{5})",   4,-2.4, 2.4);
    SixthJetEtaFull_Zinc6jet                = newTH1D("SixthJetEtaFull_Zinc6jet",                "#geq 6th jets #eta (N_{jets} #geq 6)",        "#eta(j_{6})",   4,-2.4, 2.4);


    FirstJetEta_Zinc1jet                = newTH1D("FirstJetEta_Zinc1jet",                "1st jet #eta (N_{jets} #geq 1)",              "#eta(j_{1})",  32, 0., 2.4);  
    SecondJetEta_Zinc2jet               = newTH1D("SecondJetEta_Zinc2jet",               "2nd jet #eta (N_{jets} #geq 2)",              "#eta(j_{2})",  32, 0., 2.4);  
    ThirdJetEta_Zinc3jet                = newTH1D("ThirdJetEta_Zinc3jet",                "3rd jet #eta (N_{jets} #geq 3)",              "#eta(j_{3})",  24, 0., 2.4);  
    FourthJetEta_Zinc4jet               = newTH1D("FourthJetEta_Zinc4jet",               "4th jet #eta (N_{jets} #geq 4)",              "#eta(j_{4})",  12, 0., 2.4);  
    FifthJetEta_Zinc5jet                = newTH1D("FifthJetEta_Zinc5jet",                "5th jet #eta (N_{jets} #geq 5)",              "#eta(j_{5})",   6, 0., 2.4);  
    SixthJetEta_Zinc6jet                = newTH1D("SixthJetEta_Zinc6jet",                "6th jet #eta (N_{jets} #geq 6)",              "#eta(j_{6})",   6, 0., 2.4);  

    genFirstJetEta_Zinc1jet             = newTH1D("genFirstJetEta_Zinc1jet",             "gen 1st jet #eta (N_{jets} #geq 1)",          "#eta(j_{1})",  32, 0., 2.4);
    genSecondJetEta_Zinc2jet            = newTH1D("genSecondJetEta_Zinc2jet",            "gen 2nd jet #eta (N_{jets} #geq 2)",          "#eta(j_{2})",  32, 0., 2.4);
    genThirdJetEta_Zinc3jet             = newTH1D("genThirdJetEta_Zinc3jet",             "gen 3rd jet #eta (N_{jets} #geq 3)",          "#eta(j_{3})",  24, 0., 2.4);
    genFourthJetEta_Zinc4jet            = newTH1D("genFourthJetEta_Zinc4jet",            "gen 4th jet #eta (N_{jets} #geq 4)",          "#eta(j_{4})",  12, 0., 2.4);
    genFifthJetEta_Zinc5jet             = newTH1D("genFifthJetEta_Zinc5jet",             "gen 5th jet #eta (N_{jets} #geq 5)",          "#eta(j_{5})",   6, 0., 2.4);
    genSixthJetEta_Zinc6jet             = newTH1D("genSixthJetEta_Zinc6jet",             "gen 6th jet #eta (N_{jets} #geq 6)",          "#eta(j_{6})",   6, 0., 2.4);


    FirstJetEta_Zexc1jet                = newTH1D("FirstJetEta_Zexc1jet",                "1st jet #eta (N_{jets} = 1)",                 "#eta(j_{1})",  47,-4.7, 4.7);  
    SecondJetEta_Zexc2jet               = newTH1D("SecondJetEta_Zexc2jet",               "2nd jet #eta (N_{jets} = 2)",                 "#eta(j_{2})",  47,-4.7, 4.7);  

    FirstJetPhi_Zinc1jet                = newTH1D("FirstJetPhi_Zinc1jet",                "1st jet #phi (N_{jets} #geq 1)",              "#phi(j_{1})",  30,-PI, PI );
    SecondJetPhi_Zinc2jet               = newTH1D("SecondJetPhi_Zinc2jet",               "2nd jet #phi (N_{jets} #geq 2)",              "#phi(j_{2})",  30,-PI, PI );
    ThirdJetPhi_Zinc3jet                = newTH1D("ThirdJetPhi_Zinc3jet",                "3rd jet #phi (N_{jets} #geq 3)",              "#phi(j_{3})",  30,-PI, PI );
    FourthJetPhi_Zinc4jet               = newTH1D("FourthJetPhi_Zinc4jet",               "4th jet #phi (N_{jets} #geq 4)",              "#phi(j_{4})",  30,-PI, PI );
    FifthJetPhi_Zinc5jet                = newTH1D("FifthJetPhi_Zinc5jet",                "5th jet #phi (N_{jets} #geq 5)",              "#phi(j_{5})",  30,-PI, PI );
    SixthJetPhi_Zinc6jet                = newTH1D("SixthJetPhi_Zinc6jet",                "6th jet #phi (N_{jets} #geq 6)",              "#phi(j_{6})",  30,-PI, PI );

    FirstJetPhi_Zexc1jet                = newTH1D("FirstJetPhi_Zexc1jet",                "1st jet #phi (N_{jets} = 1)",                 "#phi(j_{1})",  30,-PI, PI );
    SecondJetPhi_Zexc2jet               = newTH1D("SecondJetPhi_Zexc2jet",               "2nd jet #phi (N_{jets} = 2)",                 "#phi(j_{2})",  30,-PI, PI );

    lepPt_Zinc0jet                      = newTH1D("lepPt_Zinc0jet",                      "1st & 2nd lep p_{T} (N_{jets} #geq 0)",       lpT,     40, 0, 200);
    genlepPt_Zinc0jet                   = newTH1D("genlepPt_Zinc0jet",                   "gen 1st & 2nd lep p_{T} (N_{jets} #geq 0)",   lpT,     40, 0, 200);
    lepPt_Zexc0jet                      = newTH1D("lepPt_Zexc0jet",                      "1st & 2nd lep p_{T} (N_{jets} = 0)",          lpT,     40, 0, 200);

    dPhiLeptons_Zexc0jet                = newTH1D("dPhiLeptons_Zexc0jet",                "#Delta #phi btw lep (N_{jets} = 0)",          ldPhi,     50, 0, PI);

    dPhiLeptons_Zinc0jet                = newTH1D("dPhiLeptons_Zinc0jet",                "#Delta #phi btw lep (N_{jets} #geq 0)",       ldPhi,     50, 0, PI);

    dEtaLeptons_Zexc0jet                = newTH1D("dEtaLeptons_Zexc0jet",                "#Delta #eta btw lep (N_{jets} = 0)",          ldEta,      50,-5, 5);

    dEtaLeptons_Zinc0jet                = newTH1D("dEtaLeptons_Zinc0jet",                "#Delta #eta btw lep (N_{jets} #geq 0)",       ldEta,      50,-5, 5);

    dRLeptons_Zinc0jet                  = newTH1D("dRLeptons_Zinc0jet",                  "#Delta R btw lep (N_{jets} #geq 0)",          ldR,        50, 0, 5);

    SpTLeptons_Zexc0jet                 = newTH1D("SpTLeptons_Zexc0jet",                 "#Delta_{pT}^{rel} lep (N_{jets} = 0)",            lSpt,          50, 0, 1);
    SpTLeptons_Zexc1jet                 = newTH1D("SpTLeptons_Zexc1jet",                 "#Delta_{pT}^{rel} lep (N_{jets} = 1)",            lSpt,          50, 0, 1);
    SpTLeptons_Zexc2jet                 = newTH1D("SpTLeptons_Zexc2jet",                 "#Delta_{pT}^{rel} lep (N_{jets} = 2)",            lSpt,          50, 0, 1);

    genSpTLeptons_Zexc2jet              = newTH1D("genSpTLeptons_Zexc2jet",              "gen #Delta_{pT}^{rel} lep (N_{jets} = 2)",        lSpt,          50,0.,1.);

    SpTLeptons_Zinc0jet                 = newTH1D("SpTLeptons_Zinc0jet",                 "#Delta_{pT}^{rel} lep (N_{jets} #geq 0)",         lSpt,          50, 0, 1);
    SpTLeptons_Zinc1jet                 = newTH1D("SpTLeptons_Zinc1jet",                 "#Delta_{pT}^{rel} lep (N_{jets} #geq 1)",         lSpt,          50, 0, 1);
    SpTLeptons_Zinc2jet                 = newTH1D("SpTLeptons_Zinc2jet",                 "#Delta_{pT}^{rel} lep (N_{jets} #geq 2)",         lSpt,          50, 0, 1);

    genSpTLeptons_Zinc2jet              = newTH1D("genSpTLeptons_Zinc2jet",              "gen #Delta_{pT}^{rel} lep (N_{jets} #geq 2)",     lSpt,          50, 0, 1);

    JetsHT_Zinc1jet                     = newTH1D("JetsHT_Zinc1jet",                     "Scalar sum jets p_{T} (N_{jets} #geq 1)",     HT,     nJetHT_Zinc1jet, jetHT_Zinc1jet);  
    JetsHT_Zinc2jet                     = newTH1D("JetsHT_Zinc2jet",                     "Scalar sum jets p_{T} (N_{jets} #geq 2)",     HT,     nJetHT_Zinc2jet, jetHT_Zinc2jet);  
    JetsHT_Zinc3jet                     = newTH1D("JetsHT_Zinc3jet",                     "Scalar sum jets p_{T} (N_{jets} #geq 3)",     HT,     nJetHT_Zinc3jet, jetHT_Zinc3jet);  
    JetsHT_Zinc4jet                     = newTH1D("JetsHT_Zinc4jet",                     "Scalar sum jets p_{T} (N_{jets} #geq 4)",     HT,     nJetHT_Zinc4jet, jetHT_Zinc4jet);  
    JetsHT_Zinc5jet                     = newTH1D("JetsHT_Zinc5jet",                     "Scalar sum jets p_{T} (N_{jets} #geq 5)",     HT,     nJetHT_Zinc5jet, jetHT_Zinc5jet);  
    JetsHT_Zinc6jet                     = newTH1D("JetsHT_Zinc6jet",                     "Scalar sum jets p_{T} (N_{jets} #geq 6)",     HT,     nJetHT_Zinc5jet, jetHT_Zinc5jet);  

    genJetsHT_Zinc1jet                  = newTH1D("genJetsHT_Zinc1jet",                  "Scalar sum jets p_{T} (N_{jets} #geq 1)",     HT,     nJetHT_Zinc1jet, jetHT_Zinc1jet);  
    genJetsHT_Zinc2jet                  = newTH1D("genJetsHT_Zinc2jet",                  "Scalar sum jets p_{T} (N_{jets} #geq 2)",     HT,     nJetHT_Zinc2jet, jetHT_Zinc2jet);  
    genJetsHT_Zinc3jet                  = newTH1D("genJetsHT_Zinc3jet",                  "Scalar sum jets p_{T} (N_{jets} #geq 3)",     HT,     nJetHT_Zinc3jet, jetHT_Zinc3jet);  
    genJetsHT_Zinc4jet                  = newTH1D("genJetsHT_Zinc4jet",                  "Scalar sum jets p_{T} (N_{jets} #geq 4)",     HT,     nJetHT_Zinc4jet, jetHT_Zinc4jet);  
    genJetsHT_Zinc5jet                  = newTH1D("genJetsHT_Zinc5jet",                  "Scalar sum jets p_{T} (N_{jets} #geq 5)",     HT,     nJetHT_Zinc5jet, jetHT_Zinc5jet);  
    genJetsHT_Zinc6jet                  = newTH1D("genJetsHT_Zinc6jet",                  "Scalar sum jets p_{T} (N_{jets} #geq 6)",     HT,     nJetHT_Zinc5jet, jetHT_Zinc5jet);  

    FirstJetPt_Zinc1jet               = newTH1D("FirstJetPt_Zinc1jet",               "1st jet p_{T} (N_{jets} #geq 1)",             "p_{T}(j_{1}) [GeV]",     nJetPt_Zinc1jet, jetPt_Zinc1jet); 

    SecondJetPt_Zinc2jet              = newTH1D("SecondJetPt_2_Zinc2jet",              "2nd jet p_{T} (N_{jets} #geq 2)",           "p_{T}(j_{2}) [GeV]",     nJetPt_Zinc2jet, jetPt_Zinc2jet); 

    ThirdJetPt_Zinc3jet                 = newTH1D("ThirdJetPt_Zinc3jet",                 "3rd jet p_{T} (N_{jets} #geq 3)",             "p_{T}(j_{3}) [GeV]",     nJetPt_Zinc3jet, jetPt_Zinc3jet); 

    FourthJetPt_Zinc4jet                = newTH1D("FourthJetPt_Zinc4jet",                "4th jet p_{T} (N_{jets} #geq 4)",             "p_{T}(j_{4}) [GeV]",     nJetPt_Zinc4jet, jetPt_Zinc4jet); 
    FifthJetPt_Zinc5jet                 = newTH1D("FifthJetPt_Zinc5jet",                 "5th jet p_{T} (N_{jets} #geq 5)",             "p_{T}(j_{5}) [GeV]",     nJetPt_Zinc5jet, jetPt_Zinc5jet); 
    SixthJetPt_Zinc6jet                 = newTH1D("SixthJetPt_Zinc6jet",                 "#geq 6th jets p_{T} (N_{jets} #geq 6)",       "p_{T}(j_{6}) [GeV]",     nJetPt_Zinc5jet, jetPt_Zinc5jet); 



    genFirstJetPt_Zinc1jet            = newTH1D("genFirstJetPt_Zinc1jet",            "gen 1st jet p_{T} (N_{jets} #geq 1)",       "p_{T}(j_{1}) [GeV]",     nJetPt_Zinc1jet, jetPt_Zinc1jet);

    genSecondJetPt_Zinc2jet           = newTH1D("genSecondJetPt_Zinc2jet",           "gen 2nd jet p_{T} (N_{jets} #geq 2)",       "p_{T}(j_{2}) [GeV]",     nJetPt_Zinc2jet, jetPt_Zinc2jet); 

    genThirdJetPt_Zinc3jet              = newTH1D("genThirdJetPt_Zinc3jet",              "gen 3rd jet p_{T} (N_{jets} #geq 3)",         "p_{T}(j_{3}) [GeV]",     nJetPt_Zinc3jet, jetPt_Zinc3jet);

    genFourthJetPt_Zinc4jet             = newTH1D("genFourthJetPt_Zinc4jet",             "gen 4th jet p_{T} (N_{jets} #geq 4)",         "p_{T}(j_{4}) [GeV]",     nJetPt_Zinc4jet, jetPt_Zinc4jet);
    genFifthJetPt_Zinc5jet              = newTH1D("genFifthJetPt_Zinc5jet",              "gen 5th jet p_{T} (N_{jets} #geq 5)",         "p_{T}(j_{5}) [GeV]",     nJetPt_Zinc5jet, jetPt_Zinc5jet);
    genSixthJetPt_Zinc6jet              = newTH1D("genSixthJetPt_Zinc6jet",              "gen #geq 6th jets p_{T} (N_{jets} #geq 6)",   "p_{T}(j_{6}) [GeV]",     nJetPt_Zinc5jet, jetPt_Zinc5jet);

    FirstJetPt_Zexc1jet                 = newTH1D("FirstJetPt_Zexc1jet",                 "1st jet p_{T} (N_{jets} = 1)",                "p_{T}(j_{1}) [GeV]",     nJetPt_Zinc1jet, jetPt_Zinc1jet); 
    SecondJetPt_Zexc2jet                = newTH1D("SecondJetPt_Zexc2jet",                "2nd jet p_{T} (N_{jets} = 2)",                "p_{T}(j_{2}) [GeV]",     nJetPt_Zinc2jet, jetPt_Zinc2jet); 

    genFirstJetPt_Zexc1jet              = newTH1D("genFirstJetPt_Zexc1jet",              "gen 1st jet p_{T} (N_{jets} = 1)",            "p_{T}(j_{1}) [GeV]",     nJetPt_Zinc1jet, jetPt_Zinc1jet);
    genSecondJetPt_Zexc2jet             = newTH1D("genSecondJetPt_Zexc2jet",             "gen 2nd jet p_{T} (N_{jets} = 2)",            "p_{T}(j_{2}) [GeV]",     nJetPt_Zinc2jet, jetPt_Zinc2jet);

    ZNGoodJets_Zexc = newTH1D("ZNGoodJets_Zexc","Jet Counter (excl.)", "N_{jets}", 8, -0.5, 7.5);
    ZNGoodJets_Zexc->GetXaxis()->SetBinLabel(1, "= 0");
    ZNGoodJets_Zexc->GetXaxis()->SetBinLabel(2, "= 1");
    ZNGoodJets_Zexc->GetXaxis()->SetBinLabel(3, "= 2");
    ZNGoodJets_Zexc->GetXaxis()->SetBinLabel(4, "= 3");
    ZNGoodJets_Zexc->GetXaxis()->SetBinLabel(5, "= 4");
    ZNGoodJets_Zexc->GetXaxis()->SetBinLabel(6, "= 5");
    ZNGoodJets_Zexc->GetXaxis()->SetBinLabel(7, "= 6");
    ZNGoodJets_Zexc->GetXaxis()->SetBinLabel(8, "= 7");

    hresponseZNGoodJets_Zexc = newTH2D("hresponseZNGoodJets_Zexc", "hresp ZNGoodJets_Zexc", 8, -0.5, 7.5, 8, -0.5, 7.5);

    hresponseFirstJetPt_Zinc1jet      = newTH2D("hresponseFirstJetPt_Zinc1jet", "hresp 1st jet pt", nJetPt_Zinc1jet, jetPt_Zinc1jet, nJetPt_Zinc1jet, jetPt_Zinc1jet);
    hresponseSecondJetPt_Zinc2jet     = newTH2D("hresponseSecondJetPt_Zinc2jet","hresp 2nd jet pt", nJetPt_Zinc2jet, jetPt_Zinc2jet, nJetPt_Zinc2jet, jetPt_Zinc2jet);
    hresponseThirdJetPt_Zinc3jet      = newTH2D("hresponseThirdJetPt_Zinc3jet", "hresp 3rd jet pt", nJetPt_Zinc3jet, jetPt_Zinc3jet, nJetPt_Zinc3jet, jetPt_Zinc3jet);
    hresponseFourthJetPt_Zinc4jet     = newTH2D("hresponseFourthJetPt_Zinc4jet","hresp 4th jet pt", nJetPt_Zinc4jet, jetPt_Zinc4jet, nJetPt_Zinc4jet, jetPt_Zinc4jet);
    hresponseFifthJetPt_Zinc5jet      = newTH2D("hresponseFifthJetPt_Zinc5jet", "hresp 5th jet pt", nJetPt_Zinc5jet, jetPt_Zinc5jet, nJetPt_Zinc5jet, jetPt_Zinc5jet);

    hresponseJetsHT_Zinc1jet          = newTH2D("hresponseJetsHT_Zinc1jet", "hresp Scalar sum jets p_{T} (N_{jets} #geq 1)", nJetHT_Zinc1jet, jetHT_Zinc1jet, nJetHT_Zinc1jet, jetHT_Zinc1jet);  
    hresponseJetsHT_Zinc2jet          = newTH2D("hresponseJetsHT_Zinc2jet", "hresp Scalar sum jets p_{T} (N_{jets} #geq 2)", nJetHT_Zinc2jet, jetHT_Zinc2jet, nJetHT_Zinc2jet, jetHT_Zinc2jet);  
    hresponseJetsHT_Zinc3jet          = newTH2D("hresponseJetsHT_Zinc3jet", "hresp Scalar sum jets p_{T} (N_{jets} #geq 3)", nJetHT_Zinc3jet, jetHT_Zinc3jet, nJetHT_Zinc3jet, jetHT_Zinc3jet);  
    hresponseJetsHT_Zinc4jet          = newTH2D("hresponseJetsHT_Zinc4jet", "hresp Scalar sum jets p_{T} (N_{jets} #geq 4)", nJetHT_Zinc4jet, jetHT_Zinc4jet, nJetHT_Zinc4jet, jetHT_Zinc4jet);  
    hresponseJetsHT_Zinc5jet          = newTH2D("hresponseJetsHT_Zinc5jet", "hresp Scalar sum jets p_{T} (N_{jets} #geq 5)", nJetHT_Zinc5jet, jetHT_Zinc5jet, nJetHT_Zinc5jet, jetHT_Zinc5jet);  

    hresponseFirstJetEta_Zinc1jet     = newTH2D("hresponseFirstJetEta_Zinc1jet",  "hresp 1st jet #eta (N_{jets} #geq 1)", 32, 0., 2.4, 32, 0., 2.4);  
    hresponseSecondJetEta_Zinc2jet    = newTH2D("hresponseSecondJetEta_Zinc2jet", "hresp 2nd jet #eta (N_{jets} #geq 2)", 32, 0., 2.4, 32, 0., 2.4);  
    hresponseThirdJetEta_Zinc3jet     = newTH2D("hresponseThirdJetEta_Zinc3jet",  "hresp 3rd jet #eta (N_{jets} #geq 3)", 24, 0., 2.4, 24, 0., 2.4);  
    hresponseFourthJetEta_Zinc4jet    = newTH2D("hresponseFourthJetEta_Zinc4jet", "hresp 4th jet #eta (N_{jets} #geq 4)", 12, 0., 2.4, 12, 0., 2.4);  
    hresponseFifthJetEta_Zinc5jet     = newTH2D("hresponseFifthJetEta_Zinc5jet",  "hresp 5th jet #eta (N_{jets} #geq 5)",  6, 0., 2.4,  6, 0., 2.4);  

    ZNGoodJetsNVtx_Zexc = newTH2D("ZNGoodJetsNVtx_Zexc","NVtx vs Jet Counter (excl.)", 11, -0.5, 10.5, 45, 0.5, 45.5);
    ZNGoodJetsNVtx_Zexc->GetXaxis()->SetBinLabel(1, "= 0");
    ZNGoodJetsNVtx_Zexc->GetXaxis()->SetBinLabel(2, "= 1");
    ZNGoodJetsNVtx_Zexc->GetXaxis()->SetBinLabel(3, "= 2");
    ZNGoodJetsNVtx_Zexc->GetXaxis()->SetBinLabel(4, "= 3");
    ZNGoodJetsNVtx_Zexc->GetXaxis()->SetBinLabel(5, "= 4");
    ZNGoodJetsNVtx_Zexc->GetXaxis()->SetBinLabel(6, "= 5");
    ZNGoodJetsNVtx_Zexc->GetXaxis()->SetBinLabel(7, "= 6");
    ZNGoodJetsNVtx_Zexc->GetXaxis()->SetBinLabel(8, "= 7");
    ZNGoodJetsNVtx_Zexc->GetXaxis()->SetBinLabel(9, "= 8");
    ZNGoodJetsNVtx_Zexc->GetXaxis()->SetBinLabel(10,"= 9");
    ZNGoodJetsNVtx_Zexc->GetXaxis()->SetBinLabel(11,"= 10");

    ZNGoodJets_Zinc = newTH1D("ZNGoodJets_Zinc","Jet Counter (incl.)", "N_{jets}", 11, -0.5, 10.5);
    ZNGoodJets_Zinc->GetXaxis()->SetBinLabel(1, "#geq 0");
    ZNGoodJets_Zinc->GetXaxis()->SetBinLabel(2, "#geq 1");
    ZNGoodJets_Zinc->GetXaxis()->SetBinLabel(3, "#geq 2");
    ZNGoodJets_Zinc->GetXaxis()->SetBinLabel(4, "#geq 3");
    ZNGoodJets_Zinc->GetXaxis()->SetBinLabel(5, "#geq 4");
    ZNGoodJets_Zinc->GetXaxis()->SetBinLabel(6, "#geq 5");
    ZNGoodJets_Zinc->GetXaxis()->SetBinLabel(7, "#geq 6");
    ZNGoodJets_Zinc->GetXaxis()->SetBinLabel(8, "#geq 7");
    ZNGoodJets_Zinc->GetXaxis()->SetBinLabel(9, "#geq 8");
    ZNGoodJets_Zinc->GetXaxis()->SetBinLabel(10,"#geq 9");
    ZNGoodJets_Zinc->GetXaxis()->SetBinLabel(11,"#geq 10");

    ZNGoodJets_Zexc_NoWeight = newTH1D("ZNGoodJets_Zexc_NoWeight","Unweighted jet Counter (excl.)", "N_{jets}", 8, -0.5, 7.5);
    ZNGoodJets_Zexc_NoWeight->GetXaxis()->SetBinLabel(1,"= 0");
    ZNGoodJets_Zexc_NoWeight->GetXaxis()->SetBinLabel(2,"= 1");
    ZNGoodJets_Zexc_NoWeight->GetXaxis()->SetBinLabel(3,"= 2");
    ZNGoodJets_Zexc_NoWeight->GetXaxis()->SetBinLabel(4,"= 3");
    ZNGoodJets_Zexc_NoWeight->GetXaxis()->SetBinLabel(5,"= 4");
    ZNGoodJets_Zexc_NoWeight->GetXaxis()->SetBinLabel(6,"= 5");
    ZNGoodJets_Zexc_NoWeight->GetXaxis()->SetBinLabel(7,"= 6");
    ZNGoodJets_Zexc_NoWeight->GetXaxis()->SetBinLabel(8,"= 7");

    ZNGoodJets_Zinc_NoWeight = newTH1D("ZNGoodJets_Zinc_NoWeight","Unweighted jet Counter (incl.)", "N_{jets}", 8, -0.5, 7.5);
    ZNGoodJets_Zinc_NoWeight->GetXaxis()->SetBinLabel(1,"#geq 0");
    ZNGoodJets_Zinc_NoWeight->GetXaxis()->SetBinLabel(2,"#geq 1");
    ZNGoodJets_Zinc_NoWeight->GetXaxis()->SetBinLabel(3,"#geq 2");
    ZNGoodJets_Zinc_NoWeight->GetXaxis()->SetBinLabel(4,"#geq 3");
    ZNGoodJets_Zinc_NoWeight->GetXaxis()->SetBinLabel(5,"#geq 4");
    ZNGoodJets_Zinc_NoWeight->GetXaxis()->SetBinLabel(6,"#geq 5");
    ZNGoodJets_Zinc_NoWeight->GetXaxis()->SetBinLabel(7,"#geq 6");
    ZNGoodJets_Zinc_NoWeight->GetXaxis()->SetBinLabel(8,"#geq 7");

    //DPS histograms
    //binning 
    int nbinSpt=21;
    double binSpt[22]={0,0.05,0.1,0.15,0.2,0.25,0.3,0.35,0.4,.45,.5,.55,.6,.65,0.7,0.75,0.8,0.85,0.9,0.94,0.98,1};

    //-- jets and Z
    TwoJetsPtDiff_Zexc2jet        = newTH1D("TwoJetsPtDiff_Zexc2jet",        "pT diff of the two highest jet (N_{jets} = 2)",                                "#Delta pT(j_{1}j_{2}) [GeV]",      10,  0, 100);
    genTwoJetsPtDiff_Zexc2jet     = newTH1D("genTwoJetsPtDiff_Zexc2jet",     "gen pT diff of the two highest jet (N_{jets} = 2)",                            "#Delta pT(j_{1}j_{2}) [GeV]",      10,  0, 100);
    JetsMass_Zexc2jet             = newTH1D("JetsMass_Zexc2jet",             "2Jets Invariant Mass (N_{jets} = 2)",                                          Mjj, 25, 0, 625);
    genJetsMass_Zexc2jet          = newTH1D("genJetsMass_Zexc2jet",          "gen 2Jets Invariant Mass (N_{jets} = 2)",                                      Mjj, 25, 0, 625);
    ptBal_Zexc2jet                = newTH1D("ptBal_Zexc2jet",                "Vectorial pT sum: Z_{pT} + DiJet_{pT} (N_{jets} = 2)",                          "#Sigma pT [GeV]",      50,  0, 100);
    genptBal_Zexc2jet             = newTH1D("genptBal_Zexc2jet",             "gen Vectorial pT sum: Z_{pT} + DiJet_{pT} (N_{jets} = 2)",                      "#Sigma pT [GeV]",      50,  0, 100);
    dPhiJets_Zexc2jet             = newTH1D("dPhiJets_Zexc2jet",             "#Delta#phi btwn jets (N_{jets} = 2)",                                          jdPhi,           20,  0, PI);
    gendPhiJets_Zexc2jet          = newTH1D("gendPhiJets_Zexc2jet",          "gen #Delta#phi btwn jets (N_{jets} = 2)",                                      jdPhi,           20,  0, PI);
    dEtaJets_Zexc2jet             = newTH1D("dEtaJets_Zexc2jet",             "#Delta#eta btwn jets (N_{jets} = 2)",                                          jdEta,           48, 0, 4.8);
    gendEtaJets_Zexc2jet          = newTH1D("gendEtaJets_Zexc2jet",          "gen #Delta#eta btwn jets (N_{jets} = 2)",                                      jdEta,           48, 0, 4.8);
    dEtaFirstJetZ_Zexc2jet        = newTH1D("dEtaFirstJetZ_Zexc2jet",        "#Delta#eta btwn Jet_{1} and Z (N_{jets} = 2)",                                 "#Delta#eta(j_{1}Z)",           50, -6, 6);
    gendEtaFirstJetZ_Zexc2jet     = newTH1D("gendEtaFirstJetZ_Zexc2jet",     "gen #Delta#eta btwn Jet_{1} and Z (N_{jets} = 2)",                             "#Delta#eta(j_{1}Z)",           50, -6, 6);
    dEtaSecondJetZ_Zexc2jet       = newTH1D("dEtaSecondJetZ_Zexc2jet",       "#Delta#eta btwn Jet_{2} and Z (N_{jets} = 2)",                                 "#Delta#eta(j_{2}Z)",           50, -6, 6);
    gendEtaSecondJetZ_Zexc2jet    = newTH1D("gendEtaSecondJetZ_Zexc2jet",    "gen #Delta#eta btwn Jet_{2} and Z (N_{jets} = 2)",                             "#Delta#eta(j_{2}Z)",           50, -6, 6);
    dEtaJet1Plus2Z_Zexc2jet       = newTH1D("dEtaJet1Plus2Z_Zexc2jet",       "#Delta#eta btwn jets and Z (N_{jets} = 2)",                                    "#Delta#eta(j_{12}Z)",           120, -6, 6);
    gendEtaJet1Plus2Z_Zexc2jet    = newTH1D("gendEtaJet1Plus2Z_Zexc2jet",    "gen #Delta#eta btwn jets and Z (N_{jets} = 2)",                                "#Delta#eta(j_{12}Z)",           120, -6, 6);
    PHI_Zexc2jet                  = newTH1D("PHI_Zexc2jet",                  "#phi: Angle btwn the two subsystems planes (N_{jets} = 2)",                    "#phi(j_{12}Z)",                 25,  0, PI);
    genPHI_Zexc2jet               = newTH1D("genPHI_Zexc2jet",               "gen #phi: Angle btwn the two subsystems planes (N_{jets} = 2)",                "#phi(j_{12}Z)",                 25,  0, PI);
    PHI_T_Zexc2jet                = newTH1D("PHI_T_Zexc2jet",                "#Delta S Angle btwn lep and jet pair in T-plane (N_{jets} = 2)",            "#Delta S(j_{12}Z)",             10,  0, PI);
    genPHI_T_Zexc2jet             = newTH1D("genPHI_T_Zexc2jet",             "gen #Delta S Angle btwn lep and jet pair in T-plane (N_{jets} = 2)",        "#Delta S(j_{12}Z)",             10,  0, PI);
    SpT_Zexc2jet                  = newTH1D("SpT_Zexc2jet",                  "#Delta_{pT}^{rel} lep and jets combined (N_{jets} = 2)",                   Spt,    20,  0, 1);
    genSpT_Zexc2jet               = newTH1D("genSpT_Zexc2jet",               "gen #Delta_{pT}^{rel} lep and jets combined (N_{jets} = 2)",               Spt,    20,  0, 1);
    SpTJets_Zexc2jet              = newTH1D("SpTJets_Zexc2jet",              "#Delta_{pT}^{rel} jets (N_{jets} = 2)",                                  jSpt,   20,  0, 1);
    genSpTJets_Zexc2jet           = newTH1D("genSpTJets_Zexc2jet",           "gen #Delta_{pT}^{rel} jets (N_{jets} = 2)",                              jSpt,   20,  0, 1);
    SPhi_Zexc2jet                 = newTH1D("SPhi_Zexc2jet",                 "S_{#phi} lep and jets combined (N_{jets} = 2)",                            Sphi,   50,  0, PI);
    genSPhi_Zexc2jet              = newTH1D("genSPhi_Zexc2jet",              "gen S_{#phi} lep and jets combined (N_{jets} = 2)",                        Sphi,   50,  0, PI);

    TwoJetsPtDiff_Zinc2jet        = newTH1D("TwoJetsPtDiff_Zinc2jet",        "pT diff of the two highest jet (N_{jets} #geq 2)",                             "#Delta pT(j_{1}j_{2}) [GeV]",      10,  0, 100);
    genTwoJetsPtDiff_Zinc2jet     = newTH1D("genTwoJetsPtDiff_Zinc2jet",     "gen pT diff of the two highest jet (N_{jets} #geq 2)",                         "#Delta pT(j_{1}j_{2}) [GeV]",      10,  0, 100);
    BestTwoJetsPtDiff_Zinc2jet    = newTH1D("BestTwoJetsPtDiff_Zinc2jet",    "Best pT diff of the two highest jet (N_{jets} #geq 2)",                        "#Delta pT(j_{1}j_{2}) [GeV]",      10,  0, 100);
    genBestTwoJetsPtDiff_Zinc2jet = newTH1D("genBestTwoJetsPtDiff_Zinc2jet", "gen Best pT diff of the two highest jet (N_{jets} #geq 2)",                    "#Delta pT(j_{1}j_{2}) [GeV]",      10,  0, 100);
    JetsMass_Zinc2jet             = newTH1D("JetsMass_Zinc2jet",             "2Jets Invariant Mass (N_{jets} #geq 2)",                                       Mjj, 25, 0, 625);
    genJetsMass_Zinc2jet          = newTH1D("genJetsMass_Zinc2jet",          "gen 2Jets Invariant Mass (N_{jets} #geq 2)",                                   Mjj, 25, 0, 625);
    BestJetsMass_Zinc2jet         = newTH1D("BestJetsMass_Zinc2jet",         "Best 2Jets Invariant Mass (N_{jets} #geq 2)",                                  Mjj, 25, 0, 625);
    genBestJetsMass_Zinc2jet      = newTH1D("genBestJetsMass_Zinc2jet",      "gen Best 2Jets Invariant Mass (N_{jets} #geq 2)",                              Mjj, 25, 0, 625);
    ptBal_Zinc2jet                = newTH1D("ptBal_Zinc2jet",                "Vectorial pT sum: Z_{pT} + DiJet_{pT} (N_{jets} #geq 2)",                       "#Sigma pT [GeV]",      50,  0, 100);
    genptBal_Zinc2jet             = newTH1D("genptBal_Zinc2jet",             "gen Vectorial pT sum: Z_{pT} + DiJet_{pT} (N_{jets} #geq 2)",                   "#Sigma pT [GeV]",      50,  0, 100);
    dPhiJets_Zinc2jet             = newTH1D("dPhiJets_Zinc2jet",             "#Delta#phi btwn jets (N_{jets} #geq 2)",                                       jdPhi,           20,  0, PI);
    gendPhiJets_Zinc2jet          = newTH1D("gendPhiJets_Zinc2jet",          "gen #Delta#phi btwn jets (N_{jets} #geq 2)",                                   jdPhi,           20,  0, PI);
    BestdPhiJets_Zinc2jet         = newTH1D("BestdPhiJets_Zinc2jet",         "Best #Delta#phi btwn jets (N_{jets} #geq 2)",                                  jdPhi,           20,  0, PI);
    genBestdPhiJets_Zinc2jet      = newTH1D("genBestdPhiJets_Zinc2jet",      "gen Best #Delta#phi btwn jets (N_{jets} #geq 2)",                              jdPhi,           20,  0, PI);
    dEtaJets_Zinc2jet             = newTH1D("dEtaJets_Zinc2jet",             "#Delta#eta btwn jets (N_{jets} #geq 2)",                                       jdEta,           48, 0, 4.8);
    gendEtaJets_Zinc2jet          = newTH1D("gendEtaJets_Zinc2jet",          "gen #Delta#eta btwn jets (N_{jets} #geq 2)",                                   jdEta,           48, 0, 4.8);
    dEtaFirstJetZ_Zinc2jet        = newTH1D("dEtaFirstJetZ_Zinc2jet",        "#Delta#eta btwn Jet_{1} and Z (N_{jets} #geq 2)",                              "#Delta#eta(j_{1}Z)",           50, -6, 6);
    gendEtaFirstJetZ_Zinc2jet     = newTH1D("gendEtaFirstJetZ_Zinc2jet",     "gen #Delta#eta btwn Jet_{1} and Z (N_{jets} #geq 2)",                          "#Delta#eta(j_{1}Z)",           50, -6, 6);
    dEtaSecondJetZ_Zinc2jet       = newTH1D("dEtaSecondJetZ_Zinc2jet",       "#Delta#eta btwn Jet_{2} and Z (N_{jets} #geq 2)",                              "#Delta#eta(j_{2}Z)",           50, -6, 6);
    gendEtaSecondJetZ_Zinc2jet    = newTH1D("gendEtaSecondJetZ_Zinc2jet",    "gen #Delta#eta btwn Jet_{2} and Z (N_{jets} #geq 2)",                          "#Delta#eta(j_{2}Z)",           120, -6, 6);
    dEtaJet1Plus2Z_Zinc2jet       = newTH1D("dEtaJet1Plus2Z_Zinc2jet",       "#Delta#eta btwn jets and Z (N_{jets} #geq 2)",                                 "#Delta#eta(j_{12}Z)",          120, -6, 6);
    gendEtaJet1Plus2Z_Zinc2jet    = newTH1D("gendEtaJet1Plus2Z_Zinc2jet",    "gen #Delta#eta btwn jets and Z (N_{jets} #geq 2)",                             "#Delta#eta(j_{12}Z)",          120, -6, 6);
    PHI_Zinc2jet                  = newTH1D("PHI_Zinc2jet",                  "#phi: Angle btwn the two subsystems planes (N_{jets} #geq 2)",                 "#phi(j_{12}Z)",                 25,  0, PI);
    genPHI_Zinc2jet               = newTH1D("genPHI_Zinc2jet",               "gen #phi: Angle btwn the two subsystems planes (N_{jets} #geq 2)",             "#phi(j_{12}Z)",                 25,  0, PI);
    BestPHI_Zinc2jet              = newTH1D("BestPHI_Zinc2jet",              "Best #phi: Angle btwn the two subsystems planes (N_{jets} #geq 2)",            "#phi(j_{12}Z)",                 25,  0, PI);
    genBestPHI_Zinc2jet           = newTH1D("genBestPHI_Zinc2jet",           "gen Best #phi: Angle btwn the two subsystems planes (N_{jets} #geq 2)",        "#phi(j_{12}Z)",                 25,  0, PI);
    PHI_T_Zinc2jet                = newTH1D("PHI_T_Zinc2jet",                "#Delta S Angle btwn lep and jet pair in T-plane (N_{jets} #geq 2)",         "#Delta S(j_{12}Z)",             10,  0, PI);
    genPHI_T_Zinc2jet             = newTH1D("genPHI_T_Zinc2jet",             "gen #Delta S Angle btwn lep and jet pair in T-plane (N_{jets} #geq 2)",     "#Delta S(j_{12}Z)",             10,  0, PI);
    BestPHI_T_Zinc2jet            = newTH1D("BestPHI_T_Zinc2jet",            "Best #Delta S Angle btwn lep and jet pair in T-plane (N_{jets} #geq 2)",    "#Delta S(j_{12}Z)",             10,  0, PI);
    genBestPHI_T_Zinc2jet         = newTH1D("genBestPHI_T_Zinc2jet",         "gen Best #Delta S Angle btwn lep and jet pair in T-plane (N_{jets} #geq 2)","#Delta S(j_{12}Z)",             10,  0, PI);
    SpT_Zinc2jet                  = newTH1D("SpT_Zinc2jet",                  "#Delta_{pT}^{rel} lep and jets combined (N_{jets} #geq 2)",                 Spt,    20,  0, 1);
    genSpT_Zinc2jet               = newTH1D("genSpT_Zinc2jet",               "gen #Delta_{pT}^{rel} lep and jets combined (N_{jets} #geq 2)",             Spt,    20,  0, 1);
    BestSpT_Zinc2jet              = newTH1D("BestSpT_Zinc2jet",              "Best #Delta_{pT}^{rel} lep and jets combined (N_{jets} #geq 2)",            Spt,    20,  0, 1);
    genBestSpT_Zinc2jet           = newTH1D("genBestSpT_Zinc2jet",           "gen Best #Delta_{pT}^{rel} lep and jets combined (N_{jets} #geq 2)",         Spt,    20,  0, 1);
    SpTJets_Zinc2jet              = newTH1D("SpTJets_Zinc2jet",              "#Delta_{pT}^{rel} jets (N_{jets} #geq 2)",                                jSpt,   20,  0, 1);
    genSpTJets_Zinc2jet           = newTH1D("genSpTJets_Zinc2jet",           "gen #Delta_{pT}^{rel} jets (N_{jets} #geq 2)",                            jSpt,   20,  0, 1);
    BestSpTJets_Zinc2jet          = newTH1D("BestSpTJets_Zinc2jet",          "Best #Delta_{pT}^{rel} jets (N_{jets} #geq 2)",                           jSpt,   20,  0, 1);
    genBestSpTJets_Zinc2jet       = newTH1D("genBestSpTJets_Zinc2jet",       "gen Best #Delta_{pT}^{rel} jets (N_{jets} #geq 2)",                       jSpt,   20,  0, 1);
    SPhi_Zinc2jet                 = newTH1D("SPhi_Zinc2jet",                 "S_{#phi} lep and jets combined (N_{jets} #geq 2)",                          Sphi,   50,  0, PI);
    genSPhi_Zinc2jet              = newTH1D("genSPhi_Zinc2jet",              "gen S_{#phi} lep and jets combined (N_{jets} #geq 2)",                      Sphi,   50,  0, PI);
    BestSPhi_Zinc2jet             = newTH1D("BestSPhi_Zinc2jet",             "Best S_{#phi} lep and jets combined (N_{jets} #geq 2)",                     Sphi,   50,  0, PI);
    genBestSPhi_Zinc2jet          = newTH1D("genBestSPhi_Zinc2jet",          "gen Best S_{#phi} lep and jets combined (N_{jets} #geq 2)",                 Sphi,   50,  0, PI);

    //-- low Z pT
    TwoJetsPtDiff_LowPt_Zexc2jet  = newTH1D("TwoJetsPtDiff_LowPt_Zexc2jet",  "pT diff of the two highest jet at low Z_{pT} (N_{jets} = 2)",                  "#Delta pT(j_{1}j_{2}) [GeV]",      10,  0, 100);
    genTwoJetsPtDiff_LowPt_Zexc2jet = newTH1D("genTwoJetsPtDiff_LowPt_Zexc2jet", "gen pT diff of the two highest jet at low Z_{pT} (N_{jets} = 2)",          "#Delta pT(j_{1}j_{2}) [GeV]",      10,  0, 100);
    JetsMass_LowPt_Zexc2jet       = newTH1D("JetsMass_LowPt_Zexc2jet",       "2Jets Invariant Mass at low Z_{pT} (N_{jets} = 2)",                            Mjj, 25, 0, 625);
    genJetsMass_LowPt_Zexc2jet    = newTH1D("genJetsMass_LowPt_Zexc2jet",    "gen 2Jets Invariant Mass at low Z_{pT} (N_{jets} = 2)",                        Mjj, 25, 0, 625);
    ptBal_LowPt_Zexc2jet          = newTH1D("ptBal_LowPt_Zexc2jet",          "Vectorial pT sum: Z_{pT} + DiJet_{pT} at low Z_{pT} (N_{jets} = 2)",            "#Sigma pT [GeV]",      50, 0, 100);
    genptBal_LowPt_Zexc2jet       = newTH1D("genptBal_LowPt_Zexc2jet",       "gen Vectorial pT sum: Z_{pT} + DiJet_{pT} at low Z_{pT} (N_{jets} = 2)",        "#Sigma pT [GeV]",      50, 0, 100);
    dPhiJets_LowPt_Zexc2jet       = newTH1D("dPhiJets_LowPt_Zexc2jet",       "#Delta#phi btwn jets at low Z_{pT} (N_{jets} = 2)",                            jdPhi,           15, 0, PI);
    gendPhiJets_LowPt_Zexc2jet    = newTH1D("gendPhiJets_LowPt_Zexc2jet",    "gen #Delta#phi btwn jets at low Z_{pT} (N_{jets} = 2)",                        jdPhi,           15, 0, PI);
    dPhiLeptons_LowPt_Zexc2jet    = newTH1D("dPhiLeptons_LowPt_Zexc2jet",    "#Delta#phi btwn leptons at low Z_{pT} (N_{jets} = 2)",                         ldPhi,           50, 0, PI);
    gendPhiLeptons_LowPt_Zexc2jet = newTH1D("gendPhiLeptons_LowPt_Zexc2jet", "gen #Delta#phi btwn leptons at low Z_{pT} (N_{jets} = 2)",                     ldPhi,           50, 0, PI);
    PHI_LowPt_Zexc2jet            = newTH1D("PHI_LowPt_Zexc2jet",            "#phi: Angle btwn the two subsystems planes at low Z_{pT} (N_{jets} = 2)",      "#phi(j_{12}Z)", 25, 0, PI);
    genPHI_LowPt_Zexc2jet         = newTH1D("genPHI_LowPt_Zexc2jet",         "gen #phi: Angle btwn the two subsystems planes at low Z_{pT} (N_{jets} = 2)",  "#phi(j_{12}Z)", 25, 0, PI);
    PHI_T_LowPt_Zexc2jet          = newTH1D("PHI_T_LowPt_Zexc2jet",          "#Delta S Angle btwn lepton and jet pair in T-plane at low Z_{pT} (N_{jets} = 2)",    "#Delta S(j_{12}Z)",             10, 0, PI);
    genPHI_T_LowPt_Zexc2jet       = newTH1D("genPHI_T_LowPt_Zexc2jet",       "gen #Delta S Angle btwn lepton and jet pair in T-plane at low Z_{pT} (N_{jets} = 2)","#Delta S(j_{12}Z)",             10, 0, PI);
    SpT_LowPt_Zexc2jet            = newTH1D("SpT_LowPt_Zexc2jet",            "#Delta_{pT}^{rel} leptons and jets combined at low Z_{pT} (N_{jets} = 2)",     Spt,    25, 0, 1);
    genSpT_LowPt_Zexc2jet         = newTH1D("genSpT_LowPt_Zexc2jet",         "gen #Delta_{pT}^{rel} leptons and jets combined at low Z_{pT} (N_{jets} = 2)", Spt,    25, 0, 1);
    SpTJets_LowPt_Zexc2jet        = newTH1D("SpTJets_LowPt_Zexc2jet",        "#Delta_{pT}^{rel} jets at low Z_{pT} (N_{jets} = 2)",                    jSpt,   15, 0, 1);
    genSpTJets_LowPt_Zexc2jet     = newTH1D("genSpTJets_LowPt_Zexc2jet",     "gen #Delta_{pT}^{rel} jets at low Z_{pT} (N_{jets} = 2)",                jSpt,   15, 0, 1);
    SpTLeptons_LowPt_Zexc2jet     = newTH1D("SpTLeptons_LowPt_Zexc2jet",     "#Delta_{pT}^{rel} leptons at low Z_{pT} (N_{jets} = 2)",                 lSpt,   50, 0, 1);
    genSpTLeptons_LowPt_Zexc2jet  = newTH1D("genSpTLeptons_LowPt_Zexc2jet",  "gen #Delta_{pT}^{rel} leptons at low Z_{pT} (N_{jets} = 2)",             lSpt,   50, 0, 1);
    SPhi_LowPt_Zexc2jet           = newTH1D("SPhi_LowPt_Zexc2jet",           "S_{#phi}: leptons and jets combined at low Z_{pT} (N_{jets} = 2)",             Sphi,   50, 0, PI);
    genSPhi_LowPt_Zexc2jet        = newTH1D("genSPhi_LowPt_Zexc2jet",        "gen S_{#phi}: leptons and jets combined at low Z_{pT} (N_{jets} = 2)",         Sphi,   50, 0, PI);

    TwoJetsPtDiff_LowPt_Zinc2jet  = newTH1D("TwoJetsPtDiff_LowPt_Zinc2jet",  "pT diff of the two highest jet at low Z_{pT} (N_{jets} #geq 2)",                              "#Delta pT(j_{1}j_{2}) [GeV]",   10,  0, 100);
    genTwoJetsPtDiff_LowPt_Zinc2jet = newTH1D("genTwoJetsPtDiff_LowPt_Zinc2jet", "gen pT diff of the two highest jet at low Z_{pT}  (N_{jets} #geq 2)",                     "#Delta pT(j_{1}j_{2}) [GeV]",   10,  0, 100);
    BestTwoJetsPtDiff_LowPt_Zinc2jet = newTH1D("BestTwoJetsPtDiff_LowPt_Zinc2jet", "Best pT diff of the two highest jet at low Z_{pT} (N_{jets} #geq 2)",                   "#Delta pT(j_{1}j_{2}) [GeV]",   10,  0, 100);
    genBestTwoJetsPtDiff_LowPt_Zinc2jet = newTH1D("genBestTwoJetsPtDiff_LowPt_Zinc2jet", "gen Best pT diff of the two highest jet at low Z_{pT} (N_{jets} #geq 2)",         "#Delta pT(j_{1}j_{2}) [GeV]",   10,  0, 100);
    JetsMass_LowPt_Zinc2jet       = newTH1D("JetsMass_LowPt_Zinc2jet",       "2Jets Invariant Mass at low Z_{pT} (N_{jets} #geq 2)",                                        Mjj, 25, 0, 625);
    genJetsMass_LowPt_Zinc2jet    = newTH1D("genJetsMass_LowPt_Zinc2jet",    "gen 2Jets Invariant Mass at low Z_{pT} (N_{jets} #geq 2)",                                    Mjj, 25, 0, 625);
    BestJetsMass_LowPt_Zinc2jet   = newTH1D("BestJetsMass_LowPt_Zinc2jet",   "Best 2Jets Invariant Mass at low Z_{pT} (N_{jets} #geq 2)",                                   Mjj, 25, 0, 625);
    genBestJetsMass_LowPt_Zinc2jet = newTH1D("genBestJetsMass_LowPt_Zinc2jet", "gen Best 2Jets Invariant Mass at low Z_{pT} (N_{jets} #geq 2)",                             Mjj, 25, 0, 625);
    ptBal_LowPt_Zinc2jet          = newTH1D("ptBal_LowPt_Zinc2jet",          "Vectorial pT sum: Z_{pT} + DiJet_{pT} at low Z_{pT} (N_{jets} #geq 2)",                        "#Sigma pT [GeV]",      50, 0, 100);
    genptBal_LowPt_Zinc2jet       = newTH1D("genptBal_LowPt_Zinc2jet",       "gen Vectorial pT sum: Z_{pT} + DiJet_{pT} at low Z_{pT} (N_{jets} #geq 2)",                    "#Sigma pT [GeV]",      50, 0, 100);
    dPhiJets_LowPt_Zinc2jet       = newTH1D("dPhiJets_LowPt_Zinc2jet",       "#Delta#phi btwn jets at low Z_{pT} (N_{jets} #geq 2)",                                        jdPhi,           15, 0, PI);
    gendPhiJets_LowPt_Zinc2jet    = newTH1D("gendPhiJets_LowPt_Zinc2jet",    "gen#Delta#phi btwn jets at low Z_{pT} (N_{jets} #geq 2)",                                     jdPhi,           15, 0, PI);
    BestdPhiJets_LowPt_Zinc2jet   = newTH1D("BestdPhiJets_LowPt_Zinc2jet",   "Best #Delta#phi btwn jets at low Z_{pT} (N_{jets} #geq 2)",                                   jdPhi,           15, 0, PI);
    genBestdPhiJets_LowPt_Zinc2jet= newTH1D("genBestdPhiJets_LowPt_Zinc2jet","gen Best #Delta#phi btwn jets at low Z_{pT} (N_{jets} #geq 2)",                               jdPhi,           15, 0, PI);
    dPhiLeptons_LowPt_Zinc2jet    = newTH1D("dPhiLeptons_LowPt_Zinc2jet",    "#Delta #phi btwn leptons at low Z_{pT} (N_{jets} #geq 2)",                                    ldPhi,           50, 0, PI);
    gendPhiLeptons_LowPt_Zinc2jet = newTH1D("gendPhiLeptons_LowPt_Zinc2jet", "gen #Delta #phi btwn leptons at low Z_{pT} (N_{jets} #geq 2)",                                ldPhi,           50, 0, PI);
    PHI_LowPt_Zinc2jet            = newTH1D("PHI_LowPt_Zinc2jet",            "#phi: Angle btwn the two subsystems planes at low Z_{pT} (N_{jets} #geq 2)",                  "#phi(j_{12}Z)",        25, 0, PI);
    genPHI_LowPt_Zinc2jet         = newTH1D("genPHI_LowPt_Zinc2jet",         "gen #phi: Angle btwn the two subsystems planes at low Z_{pT} (N_{jets} #geq 2)",              "#phi(j_{12}Z)",        25, 0, PI);
    BestPHI_LowPt_Zinc2jet        = newTH1D("BestPHI_LowPt_Zinc2jet",        "Best #phi: Angle btwn the two subsystems planes at low Z_{pT} (N_{jets} #geq 2)",             "#phi(j_{12}Z)",        25, 0, PI);
    genBestPHI_LowPt_Zinc2jet     = newTH1D("genBestPHI_LowPt_Zinc2jet",     "gen Best #phi: Angle btwn the two subsystems planes at low Z_{pT} (N_{jets} #geq 2)",         "#phi(j_{12}Z)",        25, 0, PI);
    PHI_T_LowPt_Zinc2jet          = newTH1D("PHI_T_LowPt_Zinc2jet",          "#Delta S Angle btwn lepton and jet pair in T-plane at low Z_{pT} (N_{jets} #geq 2)",          "#Delta S(j_{12}Z)",    10, 0, PI);
    genPHI_T_LowPt_Zinc2jet       = newTH1D("genPHI_T_LowPt_Zinc2jet",       "gen #Delta S Angle btwn lepton and jet pair in T-plane at low Z_{pT} (N_{jets} #geq 2)",      "#Delta S(j_{12}Z)",    10, 0, PI);
    BestPHI_T_LowPt_Zinc2jet      = newTH1D("BestPHI_T_LowPt_Zinc2jet",      "Best #Delta S Angle btwn lepton and jet pair in T-plane at low Z_{pT} (N_{jets} #geq 2)",     "#Delta S(j_{12}Z)",    10, 0, PI);
    genBestPHI_T_LowPt_Zinc2jet   = newTH1D("genBestPHI_T_LowPt_Zinc2jet",   "gen Best #Delta S Angle btwn lepton and jet pair in T-plane at low Z_{pT} (N_{jets} #geq 2)", "#Delta S(j_{12}Z)",    10, 0, PI);
    SpT_LowPt_Zinc2jet            = newTH1D("SpT_LowPt_Zinc2jet",            "#Delta_{pT}^{rel} leptons and jets combined at low Z_{pT} (N_{jets} #geq 2)",                 Spt,    25, 0, 1);
    genSpT_LowPt_Zinc2jet         = newTH1D("genSpT_LowPt_Zinc2jet",         "gen #Delta_{pT}^{rel} leptons and jets combined at low Z_{pT} (N_{jets} #geq 2)",             Spt,    25, 0, 1);
    BestSpT_LowPt_Zinc2jet        = newTH1D("BestSpT_LowPt_Zinc2jet",        "Best #Delta_{pT}^{rel} leptons and jets combined at low Z_{pT} (N_{jets} #geq 2)",            Spt,    25, 0, 1);
    genBestSpT_LowPt_Zinc2jet     = newTH1D("genBestSpT_LowPt_Zinc2jet",     "gen Best #Delta_{pT}^{rel} leptons and jets combined at low Z_{pT} (N_{jets} #geq 2)",        Spt,    25, 0, 1);
    SpTJets_LowPt_Zinc2jet        = newTH1D("SpTJets_LowPt_Zinc2jet",        "#Delta_{pT}^{rel} jets at low Z_{pT} (N_{jets} #geq 2)",                                jSpt,   15, 0, 1);
    genSpTJets_LowPt_Zinc2jet     = newTH1D("genSpTJets_LowPt_Zinc2jet",     "gen #Delta_{pT}^{rel} jets at low Z_{pT} (N_{jets} #geq 2)",                            jSpt,   15, 0, 1);
    BestSpTJets_LowPt_Zinc2jet    = newTH1D("BestSpTJets_LowPt_Zinc2jet",    "Best #Delta_{pT}^{rel} jets at low Z_{pT} (N_{jets} #geq 2)",                           jSpt,   15, 0, 1);
    genBestSpTJets_LowPt_Zinc2jet = newTH1D("genBestSpTJets_LowPt_Zinc2jet", "gen Best #Delta_{pT}^{rel} jets at low Z_{pT} (N_{jets} #geq 2)",                       jSpt,   15, 0, 1);
    SpTLeptons_LowPt_Zinc2jet     = newTH1D("SpTLeptons_LowPt_Zinc2jet",     "#Delta_{pT}^{rel} leptons at low Z_{pT} (N_{jets} #geq 2)",                             lSpt,   50, 0, 1);
    genSpTLeptons_LowPt_Zinc2jet  = newTH1D("genSpTLeptons_LowPt_Zinc2jet",  "gen #Delta_{pT}^{rel} leptons at low Z_{pT} (N_{jets} #geq 2)",                         lSpt,   50, 0, 1);
    SPhi_LowPt_Zinc2jet           = newTH1D("SPhi_LowPt_Zinc2jet",           "S_{#phi}: leptons and jets combined at low Z_{pT} (N_{jets} #geq 2)",                         Sphi,   50, 0, PI);
    genSPhi_LowPt_Zinc2jet        = newTH1D("genSPhi_LowPt_Zinc2jet",        "gen S_{#phi}: leptons and jets combined at low Z_{pT} (N_{jets} #geq 2)",                     Sphi,   50, 0, PI);
    BestSPhi_LowPt_Zinc2jet       = newTH1D("BestSPhi_LowPt_Zinc2jet",       "Best S_{#phi}: leptons and jets combined at low Z_{pT} (N_{jets} #geq 2)",                    Sphi,   50, 0, PI);
    genBestSPhi_LowPt_Zinc2jet    = newTH1D("genBestSPhi_LowPt_Zinc2jet",    "gen Best S_{#phi}: leptons and jets combined at low Z_{pT} (N_{jets} #geq 2)",                Sphi,   50, 0, PI);

    //-- low Z pT and low SpT
    PHI_LowSpT_LowPt_Zexc2jet     = newTH1D("PHI_LowSpT_LowPt_Zexc2jet",     "#phi: Angle btwn the two subsystems planes at low #Delta_{pT}^{rel} and low Z_{pT} (N_{jets} = 2)","#phi",     25,0.,PI);
    genPHI_LowSpT_LowPt_Zexc2jet  = newTH1D("genPHI_LowSpT_LowPt_Zexc2jet",  "gen #phi: Angle btwn the two subsystems planes at low #Delta_{pT}^{rel} and low Z_{pT} (N_{jets} = 2)","#phi", 25,0.,PI);
    SPhi_LowSpT_LowPt_Zexc2jet    = newTH1D("SPhi_LowSpT_LowPt_Zexc2jet",    "S_{#phi}: leptons and jets combined at low #Delta_{pT}^{rel} and low Z_{pT} (N_{jets} = 2)","S_{#phi}",           50,2.5,PI);
    genSPhi_LowSpT_LowPt_Zexc2jet = newTH1D("genSPhi_LowSpT_LowPt_Zexc2jet", "gen S_{#phi}: leptons and jets combined at low #Delta_{pT}^{rel} and low Z_{pT} (N_{jets} = 2)","S_{#phi}",       50,2.5,PI);

    PHI_LowSpT_LowPt_Zinc2jet     = newTH1D("PHI_LowSpT_LowPt_Zinc2jet",     "#phi: Angle btwn the two subsystems planes at low #Delta_{pT}^{rel} and low Z_{pT} (N_{jets} #geq 2)","#phi",     25,0.,PI);
    genPHI_LowSpT_LowPt_Zinc2jet  = newTH1D("genPHI_LowSpT_LowPt_Zinc2jet",  "gen #phi: Angle btwn the two subsystems planes at low #Delta_{pT}^{rel} and low Z_{pT} (N_{jets} #geq 2)","#phi", 25,0.,PI);
    SPhi_LowSpT_LowPt_Zinc2jet    = newTH1D("SPhi_LowSpT_LowPt_Zinc2jet",    "S_{#phi}: leptons and jets combined at low #Delta_{pT}^{rel} and low Z_{pT} (N_{jets} #geq 2)","S_{#phi}",           50,2.5,PI);
    genSPhi_LowSpT_LowPt_Zinc2jet = newTH1D("genSPhi_LowSpT_LowPt_Zinc2jet", "gen S_{#phi}: leptons and jets combined at low #Delta_{pT}^{rel} and low Z_{pT} (N_{jets} #geq 2)","S_{#phi}",       50,2.5,PI);

    //-- low Z pT and high SpT
    PHI_HighSpT_LowPt_Zexc2jet    = newTH1D("PHI_HighSpT_LowPt_Zexc2jet",    "#phi: Angle btwn the two subsystems planes at high #Delta_{pT}^{rel} and low Z_{pT} (N_{jets} = 2)","#phi",    50,0.,PI);
    genPHI_HighSpT_LowPt_Zexc2jet = newTH1D("genPHI_HighSpT_LowPt_Zexc2jet", "gen #phi: Angle btwn the two subsystems planes at high #Delta_{pT}^{rel} and low Z_{pT} (N_{jets} = 2)","#phi",50,0.,PI);
    SPhi_HighSpT_LowPt_Zexc2jet   = newTH1D("SPhi_HighSpT_LowPt_Zexc2jet",   "S_{#phi}: leptons and jets combined at high #Delta_{pT}^{rel} and low Z_{pT} (N_{jets} = 2)","S_{#phi}",          50,0.,PI);
    genSPhi_HighSpT_LowPt_Zexc2jet  = newTH1D("genSPhi_HighSpT_LowPt_Zexc2jet",   "gen S_{#phi}: leptons and jets combined at high #Delta_{pT}^{rel} and low Z_{pT} (N_{jets} = 2)","S_{#phi}", 50,0.,PI);

    PHI_HighSpT_LowPt_Zinc2jet    = newTH1D("PHI_HighSpT_LowPt_Zinc2jet",    "#phi: Angle btwn the two subsystems planes at high #Delta_{pT}^{rel} and low Z_{pT} (N_{jets} #geq 2)","#phi",    50,0.,PI);
    genPHI_HighSpT_LowPt_Zinc2jet = newTH1D("genPHI_HighSpT_LowPt_Zinc2jet", "gen #phi: Angle btwn the two subsystems planes at high #Delta_{pT}^{rel} and low Z_{pT} (N_{jets} #geq 2)","#phi",50,0.,PI);
    SPhi_HighSpT_LowPt_Zinc2jet   = newTH1D("SPhi_HighSpT_LowPt_Zinc2jet",   "S_{#phi}: leptons and jets combined at high #Delta_{pT}^{rel} and low Z_{pT} (N_{jets} #geq 2)","S_{#phi}",          50,0.,PI);
    genSPhi_HighSpT_LowPt_Zinc2jet  = newTH1D("genSPhi_HighSpT_LowPt_Zinc2jet",   "gen S_{#phi}: leptons and jets combined at high #Delta_{pT}^{rel} and low Z_{pT} (N_{jets} #geq 2)","S_{#phi}", 50,0.,PI);

    //-- low Z pT and low SPhi
    SpT_LowSPhi_LowPt_Zexc2jet    = newTH1D("SpT_LowSPhi_LowPt_Zexc2jet",    "#Delta_{pT}^{rel} leptons and jets combined at low S_{#phi} and low Z_{pT} (N_{jets} = 2)","#Delta_{pT}^{rel}",             50,0.,1.);
    genSpT_LowSPhi_LowPt_Zexc2jet    = newTH1D("genSpT_LowSPhi_LowPt_Zexc2jet",    "gen #Delta_{pT}^{rel} leptons and jets combined at low S_{#phi} and low Z_{pT} (N_{jets} = 2)","#Delta_{pT}^{rel}",   50,0.,1.);

    SpT_LowSPhi_LowPt_Zinc2jet    = newTH1D("SpT_LowSPhi_LowPt_Zinc2jet",    "#Delta_{pT}^{rel} leptons and jets combined at low S_{#phi} and low Z_{pT} (N_{jets} #geq 2)","#Delta_{pT}^{rel}",             50,0.,1.);
    genSpT_LowSPhi_LowPt_Zinc2jet    = newTH1D("genSpT_LowSPhi_LowPt_Zinc2jet",    "gen #Delta_{pT}^{rel} leptons and jets combined at low S_{#phi} and low Z_{pT} (N_{jets} #geq 2)","#Delta_{pT}^{rel}",   50,0.,1.);

    //-- low Z pT and high SPhi
    SpT_HighSPhi_LowPt_Zexc2jet   = newTH1D("SpT_HighSPhi_LowPt_Zexc2jet",   "#Delta_{pT}^{rel} leptons and jets combined at high S_{#phi} and low Z_{pT} (N_{jets} = 2)","#Delta_{pT}^{rel}",            50,0.,1.);
    genSpT_HighSPhi_LowPt_Zexc2jet   = newTH1D("genSpT_HighSPhi_LowPt_Zexc2jet",   "gen #Delta_{pT}^{rel} leptons and jets combined at high S_{#phi} and low Z_{pT} (N_{jets} = 2)","#Delta_{pT}^{rel}",  50,0.,1.);

    SpT_HighSPhi_LowPt_Zinc2jet   = newTH1D("SpT_HighSPhi_LowPt_Zinc2jet",   "#Delta_{pT}^{rel} leptons and jets combined at high S_{#phi} and low Z_{pT} (N_{jets} #geq 2)","#Delta_{pT}^{rel}",            50,0.,1.);
    genSpT_HighSPhi_LowPt_Zinc2jet   = newTH1D("genSpT_HighSPhi_LowPt_Zinc2jet",   "gen #Delta_{pT}^{rel} leptons and jets combined at high S_{#phi} and low Z_{pT} (N_{jets} #geq 2)","#Delta_{pT}^{rel}",  50,0.,1.);

    //-- high Z pT
    ptBal_HighPt_Zexc2jet         = newTH1D("ptBal_HighPt_Zexc2jet",         "Vectorial pT sum: Z_{pT} + DiJet_{pT} at high Z_{pT} (N_{jets} = 2)","#Sigma pT [GeV]",                 50,0.,100.);
    genptBal_HighPt_Zexc2jet      = newTH1D("genptBal_HighPt_Zexc2jet",      "gen Vectorial pT sum: Z_{pT} + DiJet_{pT} at high Z_{pT} (N_{jets} = 2)","#Sigma pT [GeV]",             50,0.,100.);
    dPhiJets_HighPt_Zexc2jet      = newTH1D("dPhiJets_HighPt_Zexc2jet",      "#Delta#phi btwn jets at high Z_{pT} (N_{jets} = 2)",                                          jdPhi,            15, 0, PI);
    gendPhiJets_HighPt_Zexc2jet   = newTH1D("gendPhiJets_HighPt_Zexc2jet",   "gen #Delta#phi btwn jets at high Z_{pT} (N_{jets} = 2)",                                      jdPhi,            15, 0, PI);
    dPhiLeptons_HighPt_Zexc2jet   = newTH1D("dPhiLeptons_HighPt_Zexc2jet",   "#Delta#phi btwn leptons at high Z_{pT} (N_{jets} = 2)",                                       ldPhi,            50,0.,PI);
    gendPhiLeptons_HighPt_Zexc2jet = newTH1D("gendPhiLeptons_HighPt_Zexc2jet",   "gen #Delta#phi btwn leptons at high Z_{pT} (N_{jets} = 2)",                               ldPhi,            50,0.,PI);
    PHI_HighPt_Zexc2jet           = newTH1D("PHI_HighPt_Zexc2jet",           "#phi: Angle btwn the two subsystems planes at high Z_{pT} (N_{jets} = 2)","#phi",                   50,0.,PI);
    genPHI_HighPt_Zexc2jet        = newTH1D("genPHI_HighPt_Zexc2jet",        "gen #phi: Angle btwn the two subsystems planes at high Z_{pT} (N_{jets} = 2)","#phi",               50,0.,PI);
    PHI_T_HighPt_Zexc2jet         = newTH1D("PHI_T_HighPt_Zexc2jet",         "#Delta S Angle btwn lepton and jet pair in T-plane at high Z_{pT} (N_{jets} = 2)","#Delta S",                 10,0.,PI);
    genPHI_T_HighPt_Zexc2jet      = newTH1D("genPHI_T_HighPt_Zexc2jet",      "gen #Delta S Angle btwn lepton and jet pair in T-plane at high Z_{pT} (N_{jets} = 2)","#Delta S",             10,0.,PI);
    SpT_HighPt_Zexc2jet           = newTH1D("SpT_HighPt_Zexc2jet",           "#Delta_{pT}^{rel} leptons and jets combined at high Z_{pT} (N_{jets} = 2)","#Delta_{pT}^{rel}",                             50,0.,1.);
    genSpT_HighPt_Zexc2jet        = newTH1D("genSpT_HighPt_Zexc2jet",        "gen #Delta_{pT}^{rel} leptons and jets combined at high Z_{pT} (N_{jets} = 2)","#Delta_{pT}^{rel}",                         50,0.,1.);
    SpTJets_HighPt_Zexc2jet       = newTH1D("SpTJets_HighPt_Zexc2jet",       "#Delta_{pT}^{rel} jets at high Z_{pT} (N_{jets} = 2)","#Delta_{pT}^{rel}",                                            15,0.,1.);
    genSpTJets_HighPt_Zexc2jet    = newTH1D("genSpTJets_HighPt_Zexc2jet",    "gen #Delta_{pT}^{rel} jets at high Z_{pT} (N_{jets} = 2)","#Delta_{pT}^{rel}",                                        15,0.,1.);
    SpTLeptons_HighPt_Zexc2jet    = newTH1D("SpTLeptons_HighPt_Zexc2jet",    "#Delta_{pT}^{rel} leptons at high Z_{pT} (N_{jets} = 2)","#Delta_{pT}^{rel}",                                         50,0.,1.);
    genSpTLeptons_HighPt_Zexc2jet = newTH1D("genSpTLeptons_HighPt_Zexc2jet", "gen #Delta_{pT}^{rel} leptons at high Z_{pT} (N_{jets} = 2)","#Delta_{pT}^{rel}",                                     50,0.,1.);
    SPhi_HighPt_Zexc2jet          = newTH1D("SPhi_HighPt_Zexc2jet",          "S_{#phi}: leptons and jets combined at high Z_{pT} (N_{jets} = 2)","S_{#phi}",                         50,0.,PI);
    genSPhi_HighPt_Zexc2jet       = newTH1D("genSPhi_HighPt_Zexc2jet",       "gen S_{#phi}: leptons and jets combined at high Z_{pT} (N_{jets} = 2)","S_{#phi}",                     50,0.,PI);

    ptBal_HighPt_Zinc2jet         = newTH1D("ptBal_HighPt_Zinc2jet",         "Vectorial pT sum: Z_{pT} + DiJet_{pT} at high Z_{pT} (N_{jets} #geq 2)","#Sigma pT [GeV]",                 50,0.,100.);
    genptBal_HighPt_Zinc2jet      = newTH1D("genptBal_HighPt_Zinc2jet",      "gen Vectorial pT sum: Z_{pT} + DiJet_{pT} at high Z_{pT} (N_{jets} #geq 2)","#Sigma pT [GeV]",             50,0.,100.);
    dPhiJets_HighPt_Zinc2jet      = newTH1D("dPhiJets_HighPt_Zinc2jet",      "#Delta#phi btwn jets at high Z_{pT} (N_{jets} #geq 2)",                                       jdPhi,      15, 0, PI);
    gendPhiJets_HighPt_Zinc2jet   = newTH1D("gendPhiJets_HighPt_Zinc2jet",   "gen #Delta#phi btwn jets at high Z_{pT} (N_{jets} #geq 2)",                                   jdPhi,      15, 0, PI);
    dPhiLeptons_HighPt_Zinc2jet   = newTH1D("dPhiLeptons_HighPt_Zinc2jet",   "#Delta#phi btwn leptons at high Z_{pT (N_{jets} #geq 2)}",                                    ldPhi,      50,0.,PI);
    gendPhiLeptons_HighPt_Zinc2jet   = newTH1D("gendPhiLeptons_HighPt_Zinc2jet",   "gen #Delta#phi btwn leptons at high Z_{pT} (N_{jets} #geq 2)",                          ldPhi,      50,0.,PI);
    PHI_HighPt_Zinc2jet           = newTH1D("PHI_HighPt_Zinc2jet",           "#phi: Angle btwn the two subsystems planes at high Z_{pT} (N_{jets} #geq 2)","#phi",                   50,0.,PI);
    genPHI_HighPt_Zinc2jet        = newTH1D("genPHI_HighPt_Zinc2jet",        "gen #phi: Angle btwn the two subsystems planes at high Z_{pT} (N_{jets} #geq 2)","#phi",               50,0.,PI);
    PHI_T_HighPt_Zinc2jet         = newTH1D("PHI_T_HighPt_Zinc2jet",         "#Delta S Angle btwn lepton and jet pair in T-plane at high Z_{pT} (N_{jets} #geq 2)","#Delta S",                 10,0.,PI);
    genPHI_T_HighPt_Zinc2jet      = newTH1D("genPHI_T_HighPt_Zinc2jet",      "gen#Delta S Angle btwn lepton and jet pair in T-plane at high Z_{pT} (N_{jets} #geq 2)","#Delta S",              10,0.,PI);
    SpT_HighPt_Zinc2jet           = newTH1D("SpT_HighPt_Zinc2jet",           "#Delta_{pT}^{rel} leptons and jets combined at high Z_{pT} (N_{jets} #geq 2)","#Delta_{pT}^{rel}",                             50,0.,1.);
    genSpT_HighPt_Zinc2jet        = newTH1D("genSpT_HighPt_Zinc2jet",        "gen #Delta_{pT}^{rel} leptons and jets combined at high Z_{pT} (N_{jets} #geq 2)","#Delta_{pT}^{rel}",                         50,0.,1.);
    SpTJets_HighPt_Zinc2jet       = newTH1D("SpTJets_HighPt_Zinc2jet",       "#Delta_{pT}^{rel} jets at high Z_{pT} (N_{jets} #geq 2)","#Delta_{pT}^{rel}",                                            15,0.,1.);
    genSpTJets_HighPt_Zinc2jet    = newTH1D("genSpTJets_HighPt_Zinc2jet",    "gen #Delta_{pT}^{rel} jets at high Z_{pT} (N_{jets} #geq 2)","#Delta_{pT}^{rel}",                                        15,0.,1.);
    SpTLeptons_HighPt_Zinc2jet    = newTH1D("SpTLeptons_HighPt_Zinc2jet",    "#Delta_{pT}^{rel} leptons at high Z_{pT} (N_{jets} #geq 2)","#Delta_{pT}^{rel}",                                         50,0.,1.);
    genSpTLeptons_HighPt_Zinc2jet = newTH1D("genSpTLeptons_HighPt_Zinc2jet", "gen #Delta_{pT}^{rel} leptons at high Z_{pT} (N_{jets} #geq 2)","#Delta_{pT}^{rel}",                                     50,0.,1.);
    SPhi_HighPt_Zinc2jet          = newTH1D("SPhi_HighPt_Zinc2jet",          "S_{#phi}: leptons and jets combined at high Z_{pT} (N_{jets} #geq 2)","S_{#phi}",                         50,0.,PI);
    genSPhi_HighPt_Zinc2jet       = newTH1D("genSPhi_HighPt_Zinc2jet",       "gen S_{#phi}: leptons and jets combined at high Z_{pT} (N_{jets} #geq 2)","S_{#phi}",                     50,0.,PI);

    //-- high Z pT and low SpT
    PHI_LowSpT_HighPt_Zexc2jet    = newTH1D("PHI_LowSpT_HighPt_Zexc2jet",    "#phi: Angle btwn the two subsystems planes at low #Delta_{pT}^{rel} and high Z_{pT} (N_{jets} = 2)","#Phi",    50,0.,PI);
    SPhi_LowSpT_HighPt_Zexc2jet   = newTH1D("SPhi_LowSpT_HighPt_Zexc2jet",   "S_{#phi}: leptons and jets combined at low #Delta_{pT}^{rel} and high Z_{pT} (N_{jets} = 2)","S_{#phi}",          50,2.5,PI);

    PHI_LowSpT_HighPt_Zinc2jet    = newTH1D("PHI_LowSpT_HighPt_Zinc2jet",    "#phi: Angle btwn the two subsystems planes at low #Delta_{pT}^{rel} and high Z_{pT} (N_{jets} #geq 2)","#Phi",    50,0.,PI);
    SPhi_LowSpT_HighPt_Zinc2jet   = newTH1D("SPhi_LowSpT_HighPt_Zinc2jet",   "S_{#phi}: leptons and jets combined at low #Delta_{pT}^{rel} and high Z_{pT} (N_{jets} #geq 2)","S_{#phi}",          50,2.5,PI);

    //-- high Z pT and high SpT
    PHI_HighSpT_HighPt_Zexc2jet   = newTH1D("PHI_HighSpT_HighPt_Zexc2jet",   "#phi: Angle btwn the two subsystems planes at high #Delta_{pT}^{rel} and high Z_{pT} (N_{jets} = 2)","#phi",   50,0.,PI);
    SPhi_HighSpT_HighPt_Zexc2jet  = newTH1D("SPhiHighSpT_HighPt_Zexc2jet",   "S_{#phi}: leptons and jets combined at high #Delta_{pT}^{rel} and low Z_{pT} (N_{jets} = 2)","S_{#phi}",          50,0.,PI);

    PHI_HighSpT_HighPt_Zinc2jet   = newTH1D("PHI_HighSpT_HighPt_Zinc2jet",   "#phi: Angle btwn the two subsystems planes at high #Delta_{pT}^{rel} and high Z_{pT} (N_{jets} #geq 2)","#phi",   50,0.,PI);
    SPhi_HighSpT_HighPt_Zinc2jet  = newTH1D("SPhiHighSpT_HighPt_Zinc2jet",   "S_{#phi}: leptons and jets combined at high #Delta_{pT}^{rel} and low Z_{pT} (N_{jets} #geq 2)","S_{#phi}",          50,0.,PI);

    //-- high Z pT and low SPhi
    SpT_LowSPhi_HighPt_Zexc2jet   = newTH1D("SpT_LowSPhi_HighPt_Zexc2jet",   "#Delta_{pT}^{rel} leptons and jets combined at low S_{#phi} and high Z_{pT} (N_{jets} = 2)","#Delta_{pT}^{rel}",            50,0.,1.);

    SpT_LowSPhi_HighPt_Zinc2jet   = newTH1D("SpT_LowSPhi_HighPt_Zinc2jet",   "#Delta_{pT}^{rel} leptons and jets combined at low S_{#phi} and high Z_{pT} (N_{jets} #geq 2)","#Delta_{pT}^{rel}",            50,0.,1.);

    //-- high Z pT and high SPhi
    SpT_HighSPhi_HighPt_Zexc2jet  = newTH1D("SpT_HighSPhi_HighPt_Zexc2jet",  "#Delta_{pT}^{rel} leptons and jets combined at high S_{#phi} and high Z_{pT} (N_{jets} = 2)","#Delta_{pT}^{rel}",           50,0.,1.);

    SpT_HighSPhi_HighPt_Zinc2jet  = newTH1D("SpT_HighSPhi_HighPt_Zinc2jet",  "#Delta_{pT}^{rel} leptons and jets combined at high S_{#phi} and high Z_{pT} (N_{jets} #geq 2)","#Delta_{pT}^{rel}",           50,0.,1.);

    //-- low SPhi
    SpT_LowSPhi_Zexc2jet          = newTH1D("SpT_LowSPhi_Zexc2jet",          "#Delta_{pT}^{rel} leptons and jets combined at low S_{#phi} (N_{jets} = 2)","#Delta_{pT}^{rel}",                            50,0.,1.);

    SpT_LowSPhi_Zinc2jet          = newTH1D("SpT_LowSPhi_Zinc2jet",          "#Delta_{pT}^{rel} leptons and jets combined at low S_{#phi} (N_{jets} #geq 2)","#Delta_{pT}^{rel}",                            50,0.,1.);

    //-- high SPhi
    SpT_HighSPhi_Zexc2jet         = newTH1D("SpT_HighSPhi_Zexc2jet",         "#Delta_{pT}^{rel} leptons and jets combined at high S_{#phi} (N_{jets} = 2)","#Delta_{pT}^{rel}",                           50,0.,1.);

    SpT_HighSPhi_Zinc2jet         = newTH1D("SpT_HighSPhi_Zinc2jet",         "#Delta_{pT}^{rel} leptons and jets combined at high S_{#phi} (N_{jets} #geq 2)","#Delta_{pT}^{rel}",                           50,0.,1.);

    //-- low SpT
    PHI_LowSpT_Zexc2jet           = newTH1D("PHI_LowSpT_Zexc2jet",           "#phi: Angle btwn the two subsystems planes at low #Delta_{pT}^{rel} (N_{jets} = 2)","#Phi",                    50,0.,PI);
    SPhi_LowSpT_Zexc2jet          = newTH1D("SPhi_LowSpT_Zexc2jet",          "S_{#phi}: leptons and jets combined at low #Delta_{pT}^{rel} (N_{jets} = 2)","S_{#phi}",                          50,2.5,PI);

    PHI_LowSpT_Zinc2jet           = newTH1D("PHI_LowSpT_Zinc2jet",           "#phi: Angle btwn the two subsystems planes at low #Delta_{pT}^{rel} (N_{jets} #geq 2)","#Phi",                    50,0.,PI);
    SPhi_LowSpT_Zinc2jet          = newTH1D("SPhi_LowSpT_Zinc2jet",          "S_{#phi}: leptons and jets combined at low #Delta_{pT}^{rel} (N_{jets} #geq 2)","S_{#phi}",                          50,2.5,PI);

    //-- high SpT
    PHI_HighSpT_Zexc2jet          = newTH1D("PHI_HighSpT_Zexc2jet",          "#phi: Angle btwn the two subsystems planes at high #Delta_{pT}^{rel} (N_{jets} = 2)","#Phi",                   50,0.,PI);
    SPhi_HighSpT_Zexc2jet         = newTH1D("SPhi_HighSpT_Zexc2jet",         "S_{#phi}: leptons and jets combined at high #Delta_{pT}^{rel} (N_{jets} = 2)","S_{#phi}",                         50,0.,PI);

    PHI_HighSpT_Zinc2jet          = newTH1D("PHI_HighSpT_Zinc2jet",          "#phi: Angle btwn the two subsystems planes at high #Delta_{pT}^{rel} (N_{jets} #geq 2)","#Phi",                   50,0.,PI);
    SPhi_HighSpT_Zinc2jet         = newTH1D("SPhi_HighSpT_Zinc2jet",         "S_{#phi}: leptons and jets combined at high #Delta_{pT}^{rel} (N_{jets} #geq 2)","S_{#phi}",                         50,0.,PI);

    //-- gen stuff
    gendPhiJetsDeltaR_Zexc2jet    = newTH1D("gendPhiJetsDeltaR_Zexc2jet",    "#Delta #phi btwn gen jets with #Delta R < 0.5 (N_{jets} = 2)","#Delta#phi",                         50,0.,PI);
    resdPhiJetsDeltaR_Zexc2jet    = newTH1D("resdPhiJetsDeltaR_Zexc2jet",    "#Delta #phi btwn gen jets with #Delta R < 0.5 (N_{jets} = 2)","#Delta#phi",                         50,-2.5,2.5);
    genPHI_TDeltaR_Zexc2jet       = newTH1D("genPHI_TDeltaR_Zexc2jet",       "#Delta S Angle btwn gen lep and gen jet pair in T-plane with #Delta R < 0.5 (N_{jets} = 2)","#Delta S",    50,0.,PI);
    resPHI_TDeltaR_Zexc2jet       = newTH1D("resPHI_TDeltaR_Zexc2jet",       "#Delta S Angle btwn gen lep and gen jet pair in T-plane with #Delta R < 0.5 (N_{jets} = 2)","#Delta S",    50,-2.5,2.5);
    genSpTJetsDeltaR_Zexc2jet     = newTH1D("genSpTJetsDeltaR_Zexc2jet",     "#Delta_{pT}^{rel} Gen jets with #Delta R < 0.5 (N_{jets} = 2)","#Delta_{pT}^{rel}",                                   50,0.,1.);
    resSpTJetsDeltaR_Zexc2jet     = newTH1D("resSpTJetsDeltaR_Zexc2jet",     "#Delta_{pT}^{rel} Gen jets with #Delta R < 0.5 (N_{jets} = 2)","#Delta_{pT}^{rel}",                                   50,-2.5,2.5);
    genSpTDeltaR_Zexc2jet         = newTH1D("genSpTDeltaR_Zexc2jet",         "#Delta_{pT}^{rel} with #Delta R < 0.5 (N_{jets} = 2)","#Delta_{pT}^{rel}",                                                   50,0.,1.);
    resSpTDeltaR_Zexc2jet         = newTH1D("resSpTDeltaR_Zexc2jet",         "#Delta_{pT}^{rel} with #Delta R < 0.5 (N_{jets} = 2)","#Delta_{pT}^{rel}",                                                   50,-2.5,2.5);

    gendPhiJetsDPS_Zexc2jet       = newTH1D("gendPhiJetsDPS_Zexc2jet",       "#Delta #phi btwn gen jets matching DPS parton (N_{jets} = 2)","#Delta#phi_{j_{1}j_{2}}",            50,0.,PI);
    gendPhiJetsDPSDeltaR_Zexc2jet = newTH1D("gendPhiJetsDPSDeltaR_Zexc2jet", "#Delta #phi btwn gen jets matching DPS parton with #Delta R < 0.5 (N_{jets} = 2)","#Delta#phi",     50,0.,PI);
    genPHI_TDPS_Zexc2jet          = newTH1D("genPHI_TDPS_Zexc2jet",          "#Delta S Angle btwn gen lepton and jet pair in T-plane (N_{jets} = 2)","#Delta S",                         50,0.,PI);
    genPHI_TDPSDeltaR_Zexc2jet    = newTH1D("genPHI_TDPSDeltaR_Zexc2jet",    "#Delta S Angle btwn gen lepton and jet pair in T-plane with #Delta R < 0.5 (N_{jets} = 2)","#Delta S",     50,0.,PI);
    genSpTJetsDPS_Zexc2jet        = newTH1D("genSpTJetsDPS_Zexc2jet",        "#Delta_{pT}^{rel} Gen jets matching DPS parton (N_{jets} = 2)","#Delta_{pT}^{rel}",nbinSpt,binSpt);
    genSpTJetsDPSDeltaR_Zexc2jet  = newTH1D("genSpTJetsDPSDeltaR_Zexc2jet",  "#Delta_{pT}^{rel} Gen jets matching DPS parton with #Delta R < 0.5 (N_{jets} = 2)","#Delta_{pT}^{rel}",nbinSpt,binSpt);
    genSpTDPS_Zexc2jet            = newTH1D("genSpTDPS_Zexc2jet",            "#Delta_{pT}^{rel} with gen jets matching DPS parton (N_{jets} = 2)","#Delta_{pT}^{rel}",nbinSpt,binSpt);
    genSpTDPSDeltaR_Zexc2jet      = newTH1D("genSpTDPSDeltaR_Zexc2jet",      "#Delta_{pT}^{rel} with gen jets matching DPS parton with #Delta R < 0.5 (N_{jets} = 2)","#Delta_{pT}^{rel}",nbinSpt,binSpt);
    genSpTDPSPartons_Zexc2jet     = newTH1D("genSpTDPSPartons_Zexc2jet",     "#Delta_{pT}^{rel} DPS partons (N_{jets} = 2)","#Delta_{pT}^{rel}",nbinSpt,binSpt);

    genZNGoodJets_Zinc = newTH1D("genZNGoodJets_Zinc","Jet Counter (incl.)", "N_{jets}", 11, -0.5, 10.5);
    genZNGoodJets_Zinc->GetXaxis()->SetBinLabel(1,"#geq 0");
    genZNGoodJets_Zinc->GetXaxis()->SetBinLabel(2,"#geq 1");
    genZNGoodJets_Zinc->GetXaxis()->SetBinLabel(3,"#geq 2");
    genZNGoodJets_Zinc->GetXaxis()->SetBinLabel(4,"#geq 3");
    genZNGoodJets_Zinc->GetXaxis()->SetBinLabel(5,"#geq 4");
    genZNGoodJets_Zinc->GetXaxis()->SetBinLabel(6,"#geq 5");
    genZNGoodJets_Zinc->GetXaxis()->SetBinLabel(7,"#geq 6");
    genZNGoodJets_Zinc->GetXaxis()->SetBinLabel(8,"#geq 7");
    genZNGoodJets_Zinc->GetXaxis()->SetBinLabel(9,"#geq 8");
    genZNGoodJets_Zinc->GetXaxis()->SetBinLabel(10,"#geq 9");
    genZNGoodJets_Zinc->GetXaxis()->SetBinLabel(11,"#geq 10");

    if ( doWJets )  genZNGoodJets_Zexc = newTH1D("genZNGoodJets_Zexc","Jet Counter (excl.)", "N_{jets}", 11, -0.5, 10.5);
    else genZNGoodJets_Zexc = newTH1D("genZNGoodJets_Zexc","Jet Counter (excl.)", "N_{jets}", 8, -0.5, 7.5);
    genZNGoodJets_Zexc->GetXaxis()->SetBinLabel(1,"= 0");
    genZNGoodJets_Zexc->GetXaxis()->SetBinLabel(2,"= 1");
    genZNGoodJets_Zexc->GetXaxis()->SetBinLabel(3,"= 2");
    genZNGoodJets_Zexc->GetXaxis()->SetBinLabel(4,"= 3");
    genZNGoodJets_Zexc->GetXaxis()->SetBinLabel(5,"= 4");
    genZNGoodJets_Zexc->GetXaxis()->SetBinLabel(6,"= 5");
    genZNGoodJets_Zexc->GetXaxis()->SetBinLabel(7,"= 6");
    genZNGoodJets_Zexc->GetXaxis()->SetBinLabel(8,"= 7"); 
    if ( doWJets ){
        genZNGoodJets_Zexc->GetXaxis()->SetBinLabel(9,"#geq 8");
        genZNGoodJets_Zexc->GetXaxis()->SetBinLabel(10,"#geq 9");
        genZNGoodJets_Zexc->GetXaxis()->SetBinLabel(11,"#geq 10");
    }
    //Correlations

    gendPhiJetsDPSDeltaR_ZpT_Zexc2jet = newTH2D("gendPhiJetsDPSDeltaR_ZpT_Zexc2jet", "gendPhiJetsDPSDeltaR_ZpT_Zexc2jet", 50, 0, PI, 100, 0, 100);
    partonX2D                          = newTH2D("partonX2D","parton X: x1 vs x2",100,0.0001,0.2,100,0.0001,0.2);

    gendeltaRjetMu                     = newTH1D("gendeltaRjetMu", "gen delta R btwn jet and muon", "#R", 50, 0., 2.5);

    /// additional information
    // Muoisolation

    MuDetIsoRhoCorr                    = newTH1D("MuDetIsoRhoCorr",  "Muon Detect. Iso #rho corr.", "l_{Iso}^{Det.}", 30, 0, 1.5);
    MuPFIsoDBetaCorr                   = newTH1D("MuPFIsoDBetaCorr", "Muon PF Iso DBeta corr.",     "l_{Iso}^{PF}",   30, 0, 1.5);

    deltaRjetMu                        = newTH1D("deltaRjetMu", "delta R btwn jet and muon", "#R", 50, 0., 2.5);
    deltaPtjetMu                       = newTH1D("deltaPtjetMu", "delta Pt btwn jet and muon if dR<0.5", "#R", 150, -75., 75.);

    //TH2D* jecVspt=newTH1D("jecVspt","jec Vs pt","jec","pt",80,0.,400,100,0,0.5);
    NVtx                          = newTH1D("NVtx","Number of vertices","#Vtx",45,0.5,45.5);
    TruePU_0                      = newTH1D("TruePU_0","True pile-up 0 jet","#pu",45,0.5,45.5);
    TruePU_1                      = newTH1D("TruePU_1","True pile-up 1 jet","#pu",45,0.5,45.5);
    TruePU_2                      = newTH1D("TruePU_2","True pile-up 2 jets","#pu",45,0.5,45.5);
    TruePU_3                      = newTH1D("TruePU_3","True pile-up 3 jets","#pu",45,0.5,45.5);
    TruePU_4                      = newTH1D("TruePU_4","True pile-up 4 jets","#pu",45,0.5,45.5);
    TruePU_5                      = newTH1D("TruePU_5","True pile-up 5 jets","#pu",45,0.5,45.5);
    TruePU_6                      = newTH1D("TruePU_6","True pile-up 6 jets","#pu",45,0.5,45.5);
    TruePU_7                      = newTH1D("TruePU_7","True pile-up 7 jets","#pu",45,0.5,45.5);
    PU_0                      = newTH1D("PU_0","pile-up 0 jet","#pu",45,0.5,45.5);
    PU_1                      = newTH1D("PU_1","pile-up 1 jet","#pu",45,0.5,45.5);
    PU_2                      = newTH1D("PU_2","pile-up 2 jets","#pu",45,0.5,45.5);
    PU_3                      = newTH1D("PU_3","pile-up 3 jets","#pu",45,0.5,45.5);
    PU_4                      = newTH1D("PU_4","pile-up 4 jets","#pu",45,0.5,45.5);
    PU_5                      = newTH1D("PU_5","pile-up 5 jets","#pu",45,0.5,45.5);
    PU_6                      = newTH1D("PU_6","pile-up 6 jets","#pu",45,0.5,45.5);
    PU_7                      = newTH1D("PU_7","pile-up 7 jets","#pu",45,0.5,45.5);
    ZNGoodJetsBeta_Zexc = newTH2D("ZNGoodJetsBeta_Zexc","Beta cut vs Jet Counter (excl.) ", 11, -0.5, 10.5, 10, -0.5, 9.5);
    ZNGoodJetsBeta_Zexc->GetXaxis()->SetBinLabel(1, "= 0");
    ZNGoodJetsBeta_Zexc->GetXaxis()->SetBinLabel(2, "= 1");
    ZNGoodJetsBeta_Zexc->GetXaxis()->SetBinLabel(3, "= 2");
    ZNGoodJetsBeta_Zexc->GetXaxis()->SetBinLabel(4, "= 3");
    ZNGoodJetsBeta_Zexc->GetXaxis()->SetBinLabel(5, "= 4");
    ZNGoodJetsBeta_Zexc->GetXaxis()->SetBinLabel(6, "= 5");
    ZNGoodJetsBeta_Zexc->GetXaxis()->SetBinLabel(7, "= 6");
    ZNGoodJetsBeta_Zexc->GetXaxis()->SetBinLabel(8, "= 7");
    ZNGoodJetsBeta_Zexc->GetXaxis()->SetBinLabel(9, "= 8");
    ZNGoodJetsBeta_Zexc->GetXaxis()->SetBinLabel(10,"= 9");
    ZNGoodJetsBeta_Zexc->GetXaxis()->SetBinLabel(11,"= 10");


    Beta                          = newTH1D("Beta","Jet PU variable Beta","Beta",50,0.,1.);
    BetaStar                      = newTH1D("BetaStar","Jet PU variable BetaStar","BetaStar",50,0.,1.);
    puBeta_JetsMatchGenJets       = newTH1D("puBeta_JetsMatchGenJets", "puBeta_JetsMatchGenJets", "Beta", 50, 0, 1);
    puBetaStar_JetsMatchGenJets   = newTH1D("puBetaStar_JetsMatchGenJets", "puBetaStar_JetsMatchGenJets", "Beta", 50, 0, 1);
    puBeta_JetsNoMatchGenJets     = newTH1D("puBeta_JetsNoMatchGenJets", "puBeta_JetsNoMatchGenJets", "Beta", 50, 0, 1);
    puBetaStar_JetsNoMatchGenJets = newTH1D("puBetaStar_JetsNoMatchGenJets", "puBetaStar_JetsNoMatchGenJets", "Beta", 50, 0, 1);
    puMVA                         = newTH1D("puMVA","Jet PU variable from MVA","puMVA",40,-1.,1.);
    puMVA_JetsMatchGenJets        = newTH1D("puMVA_JetsMatchGenJets","Jet PU variable from MVA for matching jets","puMVA",40,-1.,1.);
    puMVA_JetsNoMatchGenJets      = newTH1D("puMVA_JetsNoMatchGenJets","Jet PU variable from MVA for non matching jets","puMVA",40,-1.,1.);
    jetsEta_JetsMatchGenJets      = newTH1D("jetsEta_JetsMatchGenJets","Jet Eta for matching jets","puMVA",48,-2.4,2.4);
    jetsEta_JetsNoMatchGenJets    = newTH1D("jetsEta_JetsNoMatchGenJets","Jet Eta for non matching jets","puMVA",48,-2.4,2.4);
    FirstJetdEtaGenReco_Zinc1	= newTH1D("FirstJetdEtaGenReco_Zinc1","#delta#eta(gen,reco) for 1st leading jet","#delta#eta",300,0.,7.5);
    FourthJetdEtaGenReco_Zinc4	= newTH1D("FourthJetdEtaGenReco_Zinc4","#delta#eta(gen,reco) for 4th leading jet","#delta#eta",300,0.,7.5);
    puMVAvsBeta                   = newTH2D("puMVA vs beta","Jet PU variable from MVA vs Beta",50,-1.,1.,50,0.,1.);


    PUWeight   = newTH1D("PUWeight","PU weight Z all","PU weight Z all",500,0.,14.);
    PUWeight0  = newTH1D("PUWeight0","PU weight Z+0jet","PU weight Z+0jet",500,0.,14.);
    PUWeight1  = newTH1D("PUWeigh1","PU weight Z+jet>0 ","PU weight Z+jet>0",500,0.,14.);

    partonsN          = newTH1D("partonsN","Number of ME partons ", "N_{partons}", 16, -0.5, 15.5);
    partonsNWeighted  = newTH1D("partonsNWeighted","Number of ME partons: weighted ", "N_{partons}", 16, -0.5, 15.5);
    partonsNAfterGenCut         = newTH1D("partonsNAfterGenCut","Number of ME partons passing the gen cut", "N_{partons}", 16, -0.5, 15.5);
    partonsNAfterGenCutWeighted = newTH1D("partonsNAfterGenCutWeighted","Number of ME partons passing the gen cut:weighted", "N_{partons}", 16, -0.5, 15.5);

    // vector boson and single jet
    dEtaBosonJet_Zexc1jet    = newTH1D("dEtaBosonJet_Zexc1",             "#Delta#eta btwn leading jet and V (N_{jets} #eq )) ",                                                   lJetdEta,           72, 0, 4.8);
    dEtaBosonJet_Zinc1jet    = newTH1D("dEtaBosonJet_Zinc1",             "#Delta#eta btwn leading jet and V (N_{jets} #geq )) ",                                                   lJetdEta,           72, 0, 4.8);
    gendEtaBosonJet_Zexc1jet = newTH1D("gendEtaBosonJet_Zexc1",             "gen #Delta#eta btwn leading jet and V (N_{jets} #eq )) ",                                                   lJetdEta,           72, 0, 4.8);
    gendEtaBosonJet_Zinc1jet = newTH1D("gendEtaBosonJet_Zinc1",             "gen #Delta#eta btwn leading jet and V (N_{jets} #geq )) ",                                                   lJetdEta,           72, 0, 4.8);

    trMass = newTH1D("trMass", "trMass", "tr Mass", 150, -50, 100);
    trE = newTH1D("trE", "trE", "tr E", 150, -50, 100);
    E = newTH1D("E", "E", "E", 150, -50, 100);
    eta = newTH1D("eta", "eta", "eta", 50, -5, 5);
    rapidity = newTH1D("rapidity", "rapidity", "rapidity", 50, -10, 10);

    for (int i(0); i < 5; i++) {
        stringstream i_str; 
        i_str << "_" << i;
        tau_sum_Zinc1jet[i]      = newTH1D(string("tau_sum_Zinc1jet" + i_str.str()).c_str(), "#Sigma#tau", "", 100, 0, 100);
        tau_max_Zinc1jet[i]      = newTH1D(string("tau_max_Zinc1jet" + i_str.str()).c_str(), "max#tau", "", 100, 0, 100);
        tau_c_sum_Zinc1jet[i]    = newTH1D(string("tau_c_sum_Zinc1jet" + i_str.str()).c_str(), "#Sigma#tau^{c}", "", 100, 0, 100);
        tau_c_max_Zinc1jet[i]    = newTH1D(string("tau_c_max_Zinc1jet" + i_str.str()).c_str(), "max#tau^{c}", "", 100, 0, 100);
        tau_cm_sum_Zinc1jet[i]   = newTH1D(string("tau_cm_sum_Zinc1jet" + i_str.str()).c_str(), "#Sigma#tau_{cm}", "", 100, 0, 100);
        tau_cm_max_Zinc1jet[i]   = newTH1D(string("tau_cm_max_Zinc1jet" + i_str.str()).c_str(), "max#tau_{cm}", "", 100, 0, 100);
        tau_c_cm_sum_Zinc1jet[i] = newTH1D(string("tau_c_cm_sum_Zinc1jet" + i_str.str()).c_str(), "#Sigma#tau^{c}_{cm}", "", 100, 0, 100);
        tau_c_cm_max_Zinc1jet[i] = newTH1D(string("tau_c_cm_max_Zinc1jet" + i_str.str()).c_str(), "max#tau^{c}_{cm}", "", 100, 0, 100);

        gentau_sum_Zinc1jet[i]      = newTH1D(string("gentau_sum_Zinc1jet" + i_str.str()).c_str(), "#Sigma#tau", "", 100, 0, 100);
        gentau_max_Zinc1jet[i]      = newTH1D(string("gentau_max_Zinc1jet" + i_str.str()).c_str(), "max#tau", "", 100, 0, 100);
        gentau_c_sum_Zinc1jet[i]    = newTH1D(string("gentau_c_sum_Zinc1jet" + i_str.str()).c_str(), "#Sigma#tau^{c}", "", 100, 0, 100);
        gentau_c_max_Zinc1jet[i]    = newTH1D(string("gentau_c_max_Zinc1jet" + i_str.str()).c_str(), "max#tau^{c}", "", 100, 0, 100);
        gentau_cm_sum_Zinc1jet[i]   = newTH1D(string("gentau_cm_sum_Zinc1jet" + i_str.str()).c_str(), "#Sigma#tau_{cm}", "", 100, 0, 100);
        gentau_cm_max_Zinc1jet[i]   = newTH1D(string("gentau_cm_max_Zinc1jet" + i_str.str()).c_str(), "max#tau_{cm}", "", 100, 0, 100);
        gentau_c_cm_sum_Zinc1jet[i] = newTH1D(string("gentau_c_cm_sum_Zinc1jet" + i_str.str()).c_str(), "#Sigma#tau^{c}_{cm}", "", 100, 0, 100);
        gentau_c_cm_max_Zinc1jet[i] = newTH1D(string("gentau_c_cm_max_Zinc1jet" + i_str.str()).c_str(), "max#tau^{c}_{cm}", "", 100, 0, 100);

        hresponsetau_sum_Zinc1jet[i]      = newTH2D(string("hresponsetau_sum_Zinc1jet" + i_str.str()).c_str(), "#Sigma#tau", 100, 0, 100, 100, 0, 100);
        hresponsetau_max_Zinc1jet[i]      = newTH2D(string("hresponsetau_max_Zinc1jet" + i_str.str()).c_str(), "max#tau", 100, 0, 100, 100, 0, 100);
        hresponsetau_c_sum_Zinc1jet[i]    = newTH2D(string("hresponsetau_c_sum_Zinc1jet" + i_str.str()).c_str(), "#Sigma#tau^{c}", 100, 0, 100, 100, 0, 100);
        hresponsetau_c_max_Zinc1jet[i]    = newTH2D(string("hresponsetau_c_max_Zinc1jet" + i_str.str()).c_str(), "max#tau^{c}", 100, 0, 100, 100, 0, 100);
        hresponsetau_cm_sum_Zinc1jet[i]   = newTH2D(string("hresponsetau_cm_sum_Zinc1jet" + i_str.str()).c_str(), "#Sigma#tau_{cm}", 100, 0, 100, 100, 0, 100);
        hresponsetau_cm_max_Zinc1jet[i]   = newTH2D(string("hresponsetau_cm_max_Zinc1jet" + i_str.str()).c_str(), "max#tau_{cm}", 100, 0, 100, 100, 0, 100);
        hresponsetau_c_cm_sum_Zinc1jet[i] = newTH2D(string("hresponsetau_c_cm_sum_Zinc1jet" + i_str.str()).c_str(), "#Sigma#tau^{c}_{cm}", 100, 0, 100, 100, 0, 100);
        hresponsetau_c_cm_max_Zinc1jet[i] = newTH2D(string("hresponsetau_c_cm_max_Zinc1jet" + i_str.str()).c_str(), "max#tau^{c}_{cm}", 100, 0, 100, 100, 0, 100);
    }


    //--- RooUnfoldResponses ---

    //responseZNGoodJets_Zexc             = newResp(ZNGoodJets_Zexc,                   genZNGoodJets_Zexc);
    //responseZMass                       = newResp(ZMass_Zinc0jet,                    genZMass_Zinc0jet);
    //responseTwoJetsPtDiffExc            = newResp(TwoJetsPtDiff_Zexc2jet,            genTwoJetsPtDiff_Zexc2jet);
    //responseTwoJetsPtDiffInc            = newResp(TwoJetsPtDiff_Zinc2jet,            genTwoJetsPtDiff_Zinc2jet);
    //responseBestTwoJetsPtDiffInc        = newResp(BestTwoJetsPtDiff_Zinc2jet,        genBestTwoJetsPtDiff_Zinc2jet);
    //responseTwoJetsPtDiffLowPtExc       = newResp(TwoJetsPtDiff_LowPt_Zexc2jet,      genTwoJetsPtDiff_LowPt_Zexc2jet);
    //responseTwoJetsPtDiffLowPtInc       = newResp(TwoJetsPtDiff_LowPt_Zinc2jet,      genTwoJetsPtDiff_LowPt_Zinc2jet);
    //responseBestTwoJetsPtDiffLowPtInc   = newResp(BestTwoJetsPtDiff_LowPt_Zinc2jet,  genBestTwoJetsPtDiff_LowPt_Zinc2jet);
    //responseJetsMassExc                 = newResp(JetsMass_Zexc2jet,                 genJetsMass_Zexc2jet);
    //responseJetsMassInc                 = newResp(JetsMass_Zinc2jet,                 genJetsMass_Zinc2jet);
    //responseBestJetsMassInc             = newResp(BestJetsMass_Zinc2jet,             genBestJetsMass_Zinc2jet);
    //responseJetsMassLowPtExc            = newResp(JetsMass_LowPt_Zexc2jet,           genJetsMass_LowPt_Zexc2jet);
    //responseJetsMassLowPtInc            = newResp(JetsMass_LowPt_Zinc2jet,           genJetsMass_LowPt_Zinc2jet);
    //responseBestJetsMassLowPtInc        = newResp(BestJetsMass_LowPt_Zinc2jet,       genBestJetsMass_LowPt_Zinc2jet);

    //responseFirstJetPt                  = newResp(FirstJetPt_Zinc1jet,               genFirstJetPt_Zinc1jet);
    //responseSecondJetPt                 = newResp(SecondJetPt_Zinc2jet,              genSecondJetPt_Zinc2jet);
    //responseThirdJetPt                  = newResp(ThirdJetPt_Zinc3jet,               genThirdJetPt_Zinc3jet);
    //responseFourthJetPt                 = newResp(FourthJetPt_Zinc4jet,              genFourthJetPt_Zinc4jet);
    //responseFifthJetPt                  = newResp(FifthJetPt_Zinc5jet,               genFifthJetPt_Zinc5jet);
    //responseSixthJetPt                  = newResp(SixthJetPt_Zinc6jet,               genSixthJetPt_Zinc6jet);

    //responseFirstJetEta                 = newResp(FirstJetEta_Zinc1jet,              genFirstJetEta_Zinc1jet);
    //responseSecondJetEta                = newResp(SecondJetEta_Zinc2jet,             genSecondJetEta_Zinc2jet);
    //responseThirdJetEta                 = newResp(ThirdJetEta_Zinc3jet,              genThirdJetEta_Zinc3jet);
    //responseFourthJetEta                = newResp(FourthJetEta_Zinc4jet,             genFourthJetEta_Zinc4jet);
    //responseFifthJetEta                 = newResp(FifthJetEta_Zinc5jet,              genFifthJetEta_Zinc5jet);
    //responseSixthJetEta                 = newResp(SixthJetEta_Zinc6jet,              genSixthJetEta_Zinc6jet);

    //responseJetsHt1Jet                  = newResp(JetsHT_Zinc1jet,                   genJetsHT_Zinc1jet);
    //responseJetsHt2Jet                  = newResp(JetsHT_Zinc2jet,                   genJetsHT_Zinc2jet);
    //responseJetsHt3Jet                  = newResp(JetsHT_Zinc3jet,                   genJetsHT_Zinc3jet);
    //responseJetsHt4Jet                  = newResp(JetsHT_Zinc4jet,                   genJetsHT_Zinc4jet);
    //responseJetsHt5Jet                  = newResp(JetsHT_Zinc5jet,                   genJetsHT_Zinc5jet);
    //responseJetsHt6Jet                  = newResp(JetsHT_Zinc6jet,                   genJetsHT_Zinc6jet);

    //responseSpTJets_Zexc2jet            = newResp(SpTJets_Zexc2jet,                  genSpTJets_Zexc2jet);
    //responseSpTJets_Zinc2jet            = newResp(SpTJets_Zinc2jet,                  genSpTJets_Zinc2jet);
    //responseBestSpTJets_Zinc2jet        = newResp(BestSpTJets_Zinc2jet,              genBestSpTJets_Zinc2jet);
    //responseSpTJets_LowPt_Zexc2jet      = newResp(SpTJets_LowPt_Zexc2jet,            genSpTJets_LowPt_Zexc2jet);
    //responseSpTJets_LowPt_Zinc2jet      = newResp(SpTJets_LowPt_Zinc2jet,            genSpTJets_LowPt_Zinc2jet);
    //responseBestSpTJets_LowPt_Zinc2jet  = newResp(BestSpTJets_LowPt_Zinc2jet,        genBestSpTJets_LowPt_Zinc2jet);
    //responseSpT_Zexc2jet                = newResp(SpT_Zexc2jet,                      genSpT_Zexc2jet);
    //responseSpT_Zinc2jet                = newResp(SpT_Zinc2jet,                      genSpT_Zinc2jet);
    //responseBestSpT_Zinc2jet            = newResp(BestSpT_Zinc2jet,                  genBestSpT_Zinc2jet);
    //responseSpT_LowPt_Zexc2jet          = newResp(SpT_LowPt_Zexc2jet,                genSpT_LowPt_Zexc2jet);
    //responseSpT_LowPt_Zinc2jet          = newResp(SpT_LowPt_Zinc2jet,                genSpT_LowPt_Zinc2jet);
    //responseBestSpT_LowPt_Zinc2jet      = newResp(BestSpT_LowPt_Zinc2jet,            genBestSpT_LowPt_Zinc2jet);
    //responsedPhiJets_Zexc2jet           = newResp(dPhiJets_Zexc2jet,                 gendPhiJets_Zexc2jet);
    //responsedPhiJets_Zinc2jet           = newResp(dPhiJets_Zinc2jet,                 gendPhiJets_Zinc2jet);
    //responseBestdPhiJets_Zinc2jet       = newResp(BestdPhiJets_Zinc2jet,             genBestdPhiJets_Zinc2jet);
    //responsedPhiJets_LowPt_Zexc2jet     = newResp(dPhiJets_LowPt_Zexc2jet,           gendPhiJets_LowPt_Zexc2jet);
    //responsedPhiJets_LowPt_Zinc2jet     = newResp(dPhiJets_LowPt_Zinc2jet,           gendPhiJets_LowPt_Zinc2jet);
    //responseBestdPhiJets_LowPt_Zinc2jet = newResp(BestdPhiJets_LowPt_Zinc2jet,       genBestdPhiJets_LowPt_Zinc2jet);
    //responsePHI_Zexc2jet                = newResp(PHI_Zexc2jet,                      genPHI_Zexc2jet);
    //responsePHI_Zinc2jet                = newResp(PHI_Zinc2jet,                      genPHI_Zinc2jet);
    //responseBestPHI_Zinc2jet            = newResp(BestPHI_Zinc2jet,                  genBestPHI_Zinc2jet);
    //responsePHI_LowPt_Zexc2jet          = newResp(PHI_LowPt_Zexc2jet,                genPHI_LowPt_Zexc2jet);
    //responsePHI_LowPt_Zinc2jet          = newResp(PHI_LowPt_Zinc2jet,                genPHI_LowPt_Zinc2jet);
    //responseBestPHI_LowPt_Zinc2jet      = newResp(BestPHI_LowPt_Zinc2jet,            genBestPHI_LowPt_Zinc2jet);
    //responsePHI_T_Zexc2jet              = newResp(PHI_T_Zexc2jet,                    genPHI_T_Zexc2jet);
    //responsePHI_T_Zinc2jet              = newResp(PHI_T_Zinc2jet,                    genPHI_T_Zinc2jet);
    //responseBestPHI_T_Zinc2jet          = newResp(BestPHI_T_Zinc2jet,                genBestPHI_T_Zinc2jet);
    //responsePHI_T_LowPt_Zexc2jet        = newResp(PHI_T_LowPt_Zexc2jet,              genPHI_T_LowPt_Zexc2jet);
    //responsePHI_T_LowPt_Zinc2jet        = newResp(PHI_T_LowPt_Zinc2jet,              genPHI_T_LowPt_Zinc2jet);
    //responseBestPHI_T_LowPt_Zinc2jet    = newResp(BestPHI_T_LowPt_Zinc2jet,          genBestPHI_T_LowPt_Zinc2jet);
    //responseSPhi_Zexc2jet               = newResp(SPhi_Zexc2jet,                     genSPhi_Zexc2jet);
    //responseSPhi_Zinc2jet               = newResp(SPhi_Zinc2jet,                     genSPhi_Zinc2jet);
    //responsedEtaJets_Zexc2jet           = newResp(dEtaJets_Zexc2jet,                 gendEtaJets_Zexc2jet);
    //responsedEtaJets_Zinc2jet           = newResp(dEtaJets_Zinc2jet,                 gendEtaJets_Zinc2jet);
    //responseBestSPhi_Zinc2jet           = newResp(BestSPhi_Zinc2jet,                 genBestSPhi_Zinc2jet);
    //responseSPhi_LowPt_Zexc2jet         = newResp(SPhi_LowPt_Zexc2jet,               genSPhi_LowPt_Zexc2jet);
    //responseSPhi_LowPt_Zinc2jet         = newResp(SPhi_LowPt_Zinc2jet,               genSPhi_LowPt_Zinc2jet);
    //responseBestSPhi_LowPt_Zinc2jet     = newResp(BestSPhi_LowPt_Zinc2jet,           genBestSPhi_LowPt_Zinc2jet);

    //// vector boson and single jet
    //responsedEtaBosonJet_Zexc1          = newResp(dEtaBosonJet_Zexc1jet,            gendEtaBosonJet_Zexc1jet);
    //responsedEtaBosonJet_Zinc1          = newResp(dEtaBosonJet_Zinc1jet,            gendEtaBosonJet_Zinc1jet);

}
