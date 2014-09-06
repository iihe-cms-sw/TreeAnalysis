#ifndef _functions_h_
#define _functions_h_

#include <iostream>
#include <cstdarg>
#include <vector>
#include <TLorentzVector.h>
#include <RooUnfoldResponse.h>

using namespace std;

void barre_de_progression(int);

struct leptonStruct{
    double pt, eta, phi, energy, charge, iso, scEta;
};

struct jetStruct{
    double pt, eta, phi, energy;
    int patIndex;
    bool isBJet;
};

bool LepDescendingOrder(leptonStruct, leptonStruct);
bool JetDescendingOrder(jetStruct, jetStruct);

vector<double> makeVector(int num, ...);
void insertVector(vector<double>& veca, int num, ...);

double phi0to2pi(double);

double deltaPhi(TLorentzVector, TLorentzVector);

double deltaPhi(double, double);
double deltaR(TLorentzVector, TLorentzVector);
double deltaR(double, double, double, double);
double PHI(TLorentzVector, TLorentzVector, TLorentzVector, TLorentzVector);
double PHI_T(TLorentzVector, TLorentzVector, TLorentzVector, TLorentzVector);
double SpTsub(TLorentzVector, TLorentzVector);
double SpT(TLorentzVector, TLorentzVector, TLorentzVector, TLorentzVector);
double SPhi(TLorentzVector, TLorentzVector, TLorentzVector, TLorentzVector);

class record{
    public:
        double ptLow, ptHi, etaLow, etaHi, effi, effiErrorLow, effiErrorHigh;
        record();
        record(double, double, double, double, double, double, double);
        bool belongTo(double, double);
};

class table{
    public:
        table();
        table(string);
        double getEfficiency(double, double);  
        double getEfficiencyLow(double, double);  
        double getEfficiencyHigh(double, double);  

    private:
        vector<record> recd;
};

double SmearJetPt(double, double, double, int);
void bestTwoJetsCandidatesPt(vector<jetStruct>, pair<TLorentzVector, TLorentzVector>&);
void bestTwoJetsCandidatesPhi(vector<jetStruct>, pair<TLorentzVector, TLorentzVector>&);
void BTagModification(double randNumber, double pt, double eta, int jetFlavour, bool &passBJets);

#endif
