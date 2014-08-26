/**
  \class    standalone_LumiReWeighting standalone_LumiReWeighting.h "PhysicsTools/Utilities/interface/standalone_LumiReWeighting.h"
  \brief    Class to provide lumi weighting for analyzers to weight "flat-to-N" MC samples to data

  This class will trivially take two histograms:
  1. The generated "flat-to-N" distributions from a given processing (or any other generated input)
  2. A histogram generated from the "estimatePileup" macro here:

https://twiki.cern.ch/twiki/bin/view/CMS/LumiCalc#How_to_use_script_estimatePileup

and produce weights to convert the input distribution (1) to the latter (2).

\author Salvatore Rappoccio, modified by Mike Hildreth

*/
#ifndef _standalone_LumiReWeighting_h
#define _standalone_LumiReWeighting_h
#include "TH1.h"
#include "TFile.h"
#include "TH1.h"
#include <string>
#include <vector>
#include <TROOT.h>
#include <iostream>

using namespace std;

class standalone_LumiReWeighting {
    public:
        standalone_LumiReWeighting(string leptonFlavor = "Muons", int year = 2013,int mode = 0); // 0: central, -1: down, +1: up
        virtual ~standalone_LumiReWeighting();
        double weight( int npv) ;
        //void weightOOT_init();

    protected:

        //=======================================================
        // For 2012 Data and MC
        //=======================================================
        double SMu2013_Central[60] = {6.29979e-07,1.52612e-06,4.37266e-06,1.73828e-05,3.14394e-05,0.000152637,0.000893661,0.00273124,0.0065913,0.0131225,0.0226491,0.0348015,0.044744,0.0507133,0.054821,0.0579305,0.0596978,0.0601709,0.0598398,0.0589341,0.0575602,0.0558801,0.0539504,0.051543,0.0482287,0.0437719,0.0383337,0.0323181,0.0261659,0.0202902,0.0150504,0.0106788,0.00724301,0.00468522,0.0028812,0.00168047,0.000929449,0.000488791,0.000245769,0.00011911,5.62231e-05,2.61829e-05,1.22167e-05,5.81079e-06,2.86509e-06,1.48222e-06,8.07647e-07,4.61383e-07,2.73663e-07,1.66737e-07,1.03387e-07,6.47666e-08,4.07585e-08,2.56499e-08,1.60805e-08,1.0011e-08,6.17266e-09,3.76145e-09,2.26153e-09,1.33986e-09};

        double SMu2013_Low[60] = {6.73645e-07,1.98895e-06,5.43038e-06,2.24511e-05,3.9532e-05,0.000301683,0.00146885,0.0042142,0.00979108,0.0185425,0.0311013,0.0437338,0.0517443,0.056719,0.0604644,0.0627265,0.0634212,0.0631112,0.0621209,0.0605837,0.0586952,0.0564984,0.0536623,0.0496737,0.0443609,0.0380385,0.0312387,0.0244934,0.0182891,0.0129985,0.00879138,0.00564706,0.00343277,0.00196855,0.00106407,0.000543533,0.000263981,0.00012304,5.57116e-05,2.48819e-05,1.11641e-05,5.13582e-06,2.46841e-06,1.25421e-06,6.74451e-07,3.80727e-07,2.22847e-07,1.33643e-07,8.13308e-08,4.98583e-08,3.0612e-08,1.8736e-08,1.13868e-08,6.84968e-09,4.06783e-09,2.38018e-09,1.37012e-09,7.75053e-10,4.30506e-10,2.34671e-10};

        double SMu2013_High[60] = {5.86176e-07,1.07066e-06,3.66823e-06,1.27713e-05,2.76951e-05,7.18353e-05,0.000486367,0.00168431,0.00417411,0.00880799,0.0156921,0.0253923,0.0361399,0.0439443,0.0487099,0.0522249,0.0548878,0.0563968,0.0568175,0.0565542,0.0558022,0.0546369,0.0531896,0.0515407,0.0495823,0.0469924,0.0434807,0.0390357,0.0339088,0.0284505,0.0230036,0.0178877,0.0133685,0.009603,0.00662515,0.00438062,0.00276852,0.00166902,0.000959523,0.000527091,0.00027785,0.000141445,7.01127e-05,3.4185e-05,1.65952e-05,8.13443e-06,4.08578e-06,2.13023e-06,1.16187e-06,6.63408e-07,3.94386e-07,2.42001e-07,1.51907e-07,9.68011e-08,6.22432e-08,4.01916e-08,2.59611e-08,1.672e-08,1.07071e-08,6.80177e-09};
        ////////////////////////////////////////
        double SE2013_Central[60] = {5.86316e-07,1.61109e-06,4.66017e-06,1.73132e-05,3.15102e-05,0.000154234,0.000904729,0.00276083,0.00662573,0.0131194,0.0226064,0.0348446,0.0449188,0.0508406,0.0547319,0.0576336,0.0594091,0.0600097,0.0597776,0.0589354,0.0576131,0.0559708,0.0540694,0.0516633,0.0483259,0.0438359,0.0383604,0.0323105,0.0261362,0.0202578,0.0150307,0.0106758,0.00725145,0.00469733,0.00289171,0.00168751,0.000933292,0.000490418,0.000246132,0.000118903,5.58592e-05,2.58553e-05,1.19823e-05,5.66296e-06,2.77883e-06,1.43424e-06,7.81717e-07,4.47624e-07,2.66478e-07,1.63057e-07,1.01555e-07,6.38897e-08,4.03611e-08,2.54835e-08,1.60195e-08,9.99427e-09,6.17232e-09,3.76574e-09,2.26605e-09,1.34334e-09};

        double SE2013_Low[60] = {6.26989e-07,2.25936e-06,5.52048e-06,2.23945e-05,3.97308e-05,0.000305048,0.00148734,0.00425042,0.00981573,0.0185093,0.0310887,0.0438783,0.0519181,0.056696,0.0601843,0.062407,0.0632369,0.0630413,0.0621223,0.0606421,0.0587946,0.0566263,0.0537852,0.0497673,0.0444155,0.038052,0.0312185,0.0244582,0.0182609,0.0129885,0.00879699,0.0056594,0.00344453,0.00197667,0.00106851,0.000545395,0.000264389,0.000122814,5.53268e-05,2.4549e-05,1.09362e-05,4.99848e-06,2.39179e-06,1.2134e-06,6.53289e-07,3.69954e-07,2.17465e-07,1.31024e-07,8.01039e-08,4.93135e-08,3.03881e-08,1.86549e-08,1.13643e-08,6.84825e-09,4.07223e-09,2.38493e-09,1.37372e-09,7.7741e-10,4.31933e-10,2.3549e-10};

        double SE2013_High[60] = {5.45519e-07,1.04218e-06,4.08219e-06,1.2694e-05,2.77056e-05,7.2498e-05,0.00049208,0.00170521,0.00420749,0.00883025,0.0156664,0.0253631,0.0362258,0.0441185,0.0488008,0.0521081,0.0545986,0.0561262,0.0566617,0.0564893,0.0557956,0.0546783,0.053267,0.0516466,0.0496991,0.0470951,0.0435569,0.0390797,0.0339199,0.028434,0.0229727,0.0178589,0.0133528,0.00960201,0.00663366,0.00439208,0.00277854,0.00167598,0.00096354,0.000528969,0.000278424,0.000141363,6.97922e-05,3.38484e-05,1.63298e-05,7.95347e-06,3.9729e-06,2.06371e-06,1.12405e-06,6.42368e-07,3.82858e-07,2.35773e-07,1.48605e-07,9.50942e-08,6.13915e-08,3.97867e-08,2.57813e-08,1.66482e-08,1.06839e-08,6.79829e-09};

        ////////////////////////////////////////

        double DE2013_Central[60] = {6.26591e-07,1.65124e-06,4.66019e-06,1.72227e-05,3.14086e-05,0.000152852,0.000892415,0.00273138,0.00658156,0.0130709,0.0225214,0.0346198,0.0445351,0.0504675,0.0544668,0.0574253,0.0591897,0.0597897,0.0595861,0.0587825,0.0575215,0.0559694,0.0541591,0.0518348,0.0485754,0.0441427,0.0386875,0.0326246,0.0264153,0.020489,0.0152103,0.0108084,0.00734602,0.00476283,0.0029355,0.00171549,0.00095031,0.000500332,0.000251741,0.000122028,5.75862e-05,2.68031e-05,1.24982e-05,5.94163e-06,2.92837e-06,1.514e-06,8.23881e-07,4.69573e-07,2.77608e-07,1.6847e-07,1.04021e-07,6.48964e-08,4.06893e-08,2.55261e-08,1.59626e-08,9.91835e-09,6.10672e-09,3.71743e-09,2.23345e-09,1.32257e-09};

        double DE2013_Low[60] = {6.7003e-07,2.28857e-06,5.52881e-06,2.2253e-05,3.96502e-05,0.000301578,0.00146764,0.004213,0.0097657,0.0184485,0.0309284,0.0435247,0.0515004,0.0563875,0.0599588,0.0621792,0.0630032,0.0628375,0.0619613,0.0605503,0.0588043,0.0567353,0.0539846,0.0500498,0.0447503,0.038395,0.0315357,0.0247288,0.018475,0.0131473,0.00890957,0.00573661,0.0034956,0.00200888,0.00108774,0.000556321,0.000270392,0.000126054,5.70603e-05,2.54691e-05,1.14201e-05,5.25092e-06,2.52255e-06,1.28063e-06,6.8745e-07,3.86942e-07,2.25612e-07,1.34709e-07,8.16177e-08,4.98306e-08,3.04883e-08,1.86079e-08,1.12846e-08,6.77743e-09,4.02041e-09,2.35063e-09,1.35242e-09,7.64781e-10,4.24711e-10,2.31481e-10};

        double DE2013_High[60] = {5.83017e-07,1.09153e-06,4.07163e-06,1.26513e-05,2.75543e-05,7.21202e-05,0.000485735,0.00168361,0.00417231,0.00878525,0.0156155,0.0252481,0.0359602,0.0437398,0.0484668,0.0518696,0.0544032,0.0559184,0.0564533,0.0563057,0.0556451,0.0545776,0.0532426,0.0517059,0.0498332,0.0473007,0.0438247,0.0393831,0.0342271,0.0287208,0.0232237,0.0180653,0.0135136,0.00972198,0.00672056,0.00445342,0.0028205,0.00170354,0.000980867,0.000539435,0.000284566,0.000144909,7.18224e-05,3.50035e-05,1.69826e-05,8.3197e-06,4.17705e-06,2.17689e-06,1.18642e-06,6.76431e-07,4.01169e-07,2.45368e-07,1.53438e-07,9.73861e-08,6.23766e-08,4.0136e-08,2.58468e-08,1.66051e-08,1.06128e-08,6.73183e-09};

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //  below DMu2013_Central is obtained with xsec 69400
        double DMu2013_Central[60] = {5.78879e-07,1.58688e-06,4.58587e-06,1.7031e-05,3.11181e-05,0.000152122,0.000890438,0.00272839,0.00658662,0.0130841,0.0225398,0.0346647,0.044676,0.0506936,0.0547484,0.057747,0.0594607,0.0599687,0.0596912,0.0588473,0.0575673,0.055748,0.0540999,0.0517223,0.0484366,0.0439955,0.0385373,0.0324698,0.0262554,0.020329,0.0150589,0.0106741,0.00723443,0.00467652,0.00287386,0.00167521,0.000926356,0.000487363,0.000245299,0.000119048,5.6279e-05,2.62493e-05,1.22686e-06,5.84791e-06,2.89061e-06,1.49893e-06,8.17857e-07,4.67111e-07,2.76548e-07,1.67975e-07,1.03766e-07,6.47544e-08,4.06055e-08,2.54751e-08,1.59312e-08,9.89894e-09,6.0948e-09,3.71018e-09,2.2291e-09,1.32e-09};

        double DMu2013_Low[60] = {6.19043e-07,2.2234e-06,5.43308e-06,2.20341e-05,3.92889e-05,0.000300528,0.00146464,0.00421232,0.00977578,0.018465,0.0309571,0.0436286,0.051717,0.0566671,0.0602952,0.0624788,0.0632019,0.0629518,0.0620297,0.060597,0.058803,0.0566622,0.0538578,0.0498999,0.044594,0.0382351,0.0313699,0.0245592,0.0183101,0.0129975,0.00878312,0.00563771,0.00342459,0.00196257,0.00106052,0.000541914,0.000263467,0.00012298,5.57736e-05,2.49502e-05,1.12156e-05,5.17163e-06,2.49224e-06,1.26913e-06,6.83051e-07,3.85195e-07,2.24864e-07,1.34356e-07,8.14328e-08,4.97264e-08,3.0427e-08,1.85712e-08,1.12625e-08,6.7642e-09,4.01257e-09,2.34605e-09,1.34978e-09,7.63292e-10,4.23884e-10,2.31031e-10};

        double DMu2013_High[60] = {5.38595e-07,1.02824e-06,4.01617e-06,1.24865e-05,2.73116e-05,7.16334e-05,0.000484454,0.00168046,0.00417257,0.00879444,0.0156298,0.0252692,0.0360231,0.0438986,0.0486899,0.0521434,0.054707,0.0561725,0.0566248,0.0564097,0.0557096,0.0546249,0.0532607,0.0516694,0.0497424,0.0471772,0.0436882,0.0392427,0.0340837,0.0285727,0.0230719,0.0179154,0.0133731,0.00959767,0.00661694,0.00437241,0.00276152,0.00166386,0.000956322,0.00052548,0.000277233,0.000141307,7.01436e-05,3.42493e-05,1.66515e-05,8.17665e-06,4.11601e-06,2.15113e-06,1.17561e-06,6.71869e-07,3.99194e-07,2.44467e-07,1.52994e-07,9.71487e-08,6.22398e-08,4.00531e-08,2.5795e-08,1.65723e-08,1.0592e-08,6.71868e-09};

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////
        double SMuE2013_Central[60] = {6.21823e-07,1.65127e-06,4.67463e-06,1.7117e-05,3.12905e-05,0.000152031,0.000887552,0.00271688,0.00655131,0.0130219,0.0224655,0.0345708,0.0445448,0.0505251,0.0545499,0.0575411,0.0592774,0.0598094,0.0595746,0.0587769,0.0575189,0.059597,0.0541379,0.0518028,0.0485368,0.044104,0.0386576,0.0326097,0.0264152,0.0204981,0.0152226,0.0108197,0.00735412,0.0047671,0.00293639,0.00171414,0.000948014,0.000498059,0.000249976,0.000120858,5.68981e-05,2.64346e-05,1.23149e-05,5.85504e-06,2.88858e-06,1.49563e-06,8.15069e-07,4.65064e-07,2.75131e-07,1.67028e-07,1.03148e-07,6.43559e-08,4.03515e-08,2.53144e-08,1.58303e-08,9.83613e-09,6.05609e-09,3.68661e-09,2.21493e-09,1.31161e-09};

        double SMuE2013_Low[60]= {6.64945e-07,2.29084e-06,5.53114e-06,2.21225e-05,3.95134e-05,0.000299865,0.00145975,0.00419167,0.00972424,0.0183916,0.0308698,0.0435062,0.0515513,0.0564653,0.0600767,0.062281,0.063031,0.0628259,0.0619554,0.0605473,0.0587927,0.056109,0.0539489,0.0500083,0.0447116,0.038369,0.0315272,0.0247343,0.0184871,0.01316,0.00891943,0.0057423,0.00349731,0.0020078,0.00108539,0.000553902,0.000268516,0.000124838,5.63693e-05,2.51146e-05,1.1252e-05,5.1753e-06,2.48929e-06,0.26577e-06,6.80435e-07,3.83365e-07,2.23647e-07,1.33571e-07,8.09365e-08,4.94166e-08,3.02354e-08,1.84536e-08,1.1191e-08,6.72124e-09,3.98708e-09,2.33114e-09,1.3412e-09,7.58441e-10,4.2119e-10,2.29562e-10};

        double SMuE2013_High[60] = {5.78569e-07,1.08931e-06,4.09488e-06,1.2572e-05,2.74285e-05,7.17976e-05,0.000482987,0.00167457,0.0041515,0.00874792,0.015565,0.0251947,0.035925,0.0437655,0.0485247,0.0519531,0.0545134,0.056,0.0564734,0.0562952,0.0556386,0.0545756,0.0532357,0.0516894,0.0498063,0.0472662,0.0437872,0.0393494,0.0342042,0.0287121,0.0232268,0.0180752,0.0135253,0.00973234,0.00672795,0.00445738,0.00282144,0.00170241,0.000978758,0.00053723,0.000282755,0.000143634,7.10224e-05,3.4555e-05,1.67388e-05,8.19694e-06,4.11749e-06,2.14838e-06,1.17257e-06,6.69404e-07,3.97381e-07,2.43195e-07,1.52127e-07,9.65688e-08,6.18571e-08,3.98027e-08,2.56324e-08,1.64674e-08,1.05248e-08,6.67602e-09};


        ////////////////////////////////////////////////////////////////////////////////////////////////////////////
        double Nov2012_Central[60] = {12238.3,32501.9,89449.6,260616,543074,2.97906e+06,1.7247e+07,5.06732e+07,1.1812e+08,2.36812e+08,4.12795e+08,6.32566e+08,8.10196e+08,9.08233e+08,9.67764e+08,1.01568e+09,1.046e+09,1.05573e+09,1.0491e+09,1.02804e+09,9.9728e+08,9.62081e+08,9.23545e+08,8.77362e+08,8.16772e+08,7.38343e+08,6.44644e+08,5.4167e+08,4.36101e+08,3.35059e+08,2.45401e+08,1.71628e+08,1.14806e+08,7.34147e+07,4.47675e+07,2.59638e+07,1.43107e+07,7.51341e+06,3.77855e+06,1.83544e+06,869909,406676,189518,88841.9,42160.5,20306.4,9911.73,4878.77,2404.86,1178.23,569.849,270.54,125.543,56.7699,24.9629,10.6588,4.4152,1.77316,0.690103,0.260206};

        double Nov2012_Low[60] = { 13087,45090.6,103115,333769,729427,5.87874e+06,2.80458e+07,7.66963e+07,1.75472e+08,3.36964e+08,5.6628e+08,7.93236e+08,9.30927e+08,1.00466e+09,1.06098e+09,1.09893e+09,1.11261e+09,1.10659e+09,1.08361e+09,1.04928e+09,1.0099e+09,9.66263e+08,9.12358e+08,8.40237e+08,7.47487e+08,6.38954e+08,5.22504e+08,4.06581e+08,3.00052e+08,2.10149e+08,1.40005e+08,8.87639e+07,5.34336e+07,3.04422e+07,1.63895e+07,8.35552e+06,4.05845e+06,1.89617e+06,862296,386564,172934,77993.7,35694.7,16605.9,7828.22,3713.85,1757.96,823.223,378.6,170.04,74.2799,31.4729,12.9108,5.12155,1.9631,0.726694,0.259699,0.0895752,0.0298138,0.00957399};

        double Nov2012_High[60] = {11387,21441,79825.7,200084,443810,1.39731e+06,9.44866e+06,3.19036e+07,7.56359e+07,1.57805e+08,2.84858e+08,4.62697e+08,6.56194e+08,7.94374e+08,8.69782e+08,9.2057e+08,9.62105e+08,9.88173e+08,9.96866e+08,9.91761e+08,9.74302e+08,9.47906e+08,9.17159e+08,8.83851e+08,8.45718e+08,7.9745e+08,7.34716e+08,6.57467e+08,5.69534e+08,4.76071e+08,3.82492e+08,2.94551e+08,2.17396e+08,1.54037e+08,1.04905e+08,6.86243e+07,4.30255e+07,2.57968e+07,1.47792e+07,8.10358e+06,4.27071e+06,2.17757e+06,1.08307e+06,530253,257881,125627,61711.5,30691.3,15466.6,7879.44,4038.7,2070.09,1054.4,530.666,262.665,127.406,60.4003,27.9351,12.5884,5.52232};

        double Summer2012_S10[60] = { 2.560E-06, 5.239E-06, 1.420E-05, 5.005E-05, 1.001E-04, 2.705E-04, 1.999E-03, 6.097E-03, 1.046E-02, 1.383E-02, 1.685E-02, 2.055E-02, 2.572E-02, 3.262E-02, 4.121E-02, 4.977E-02, 5.539E-02, 5.725E-02, 5.607E-02, 5.312E-02, 5.008E-02, 4.763E-02, 4.558E-02, 4.363E-02, 4.159E-02, 3.933E-02, 3.681E-02, 3.406E-02, 3.116E-02, 2.818E-02, 2.519E-02, 2.226E-02, 1.946E-02, 1.682E-02, 1.437E-02, 1.215E-02, 1.016E-02, 8.400E-03, 6.873E-03, 5.564E-03, 4.457E-03, 3.533E-03, 2.772E-03, 2.154E-03, 1.656E-03, 1.261E-03, 9.513E-04, 7.107E-04, 5.259E-04, 3.856E-04, 2.801E-04, 2.017E-04, 1.439E-04, 1.017E-04, 7.126E-05, 4.948E-05, 3.405E-05, 2.322E-05, 1.570E-05, 5.005E-06};

        double Summer2012_S7[60] = { 2.344E-05, 2.344E-05, 2.344E-05, 2.344E-05, 4.687E-04, 4.687E-04, 7.032E-04, 9.414E-04, 1.234E-03, 1.603E-03, 2.464E-03, 3.250E-03, 5.021E-03, 6.644E-03, 8.502E-03, 1.121E-02, 1.518E-02, 2.033E-02, 2.608E-02, 3.171E-02, 3.667E-02, 4.060E-02, 4.338E-02, 4.520E-02, 4.641E-02, 4.735E-02, 4.816E-02, 4.881E-02, 4.917E-02, 4.909E-02, 4.842E-02, 4.707E-02, 4.501E-02, 4.228E-02, 3.896E-02, 3.521E-02, 3.118E-02, 2.702E-02, 2.287E-02, 1.885E-02, 1.508E-02, 1.166E-02, 8.673E-03, 6.190E-03, 4.222E-03, 2.746E-03, 1.698E-03, 9.971E-04, 5.549E-04, 2.924E-04, 1.457E-04, 6.864E-05, 3.054E-05, 1.282E-05, 5.081E-06, 1.898E-06, 6.688E-07, 2.221E-07, 6.947E-08, 2.047E-08 };  

        double Data2012[60]={
            12238.2,32255.7,64287.7,222968,487946,2.47713e+06,1.4766e+07,4.44367e+07,1.02754e+08,1.94785e+08,3.25867e+08,4.86418e+08,6.15299e+08,6.88662e+08,7.34856e+08,7.71983e+08,7.90034e+08,7.84055e+08,7.63383e+08,7.34002e+08,6.99429e+08,6.63169e+08,6.2787e+08,5.90571e+08,5.43027e+08,4.80163e+08,4.04441e+08,3.22911e+08,2.43214e+08,1.72144e+08,1.14644e+08,7.23911e+07,4.3768e+07,2.54757e+07,1.42378e+07,7.57403e+06,3.79979e+06,1.78907e+06,792005,332422,133997,52614.4,20370.4,7837.71,3005.93,1148.24,435.67,163.716,60.8204,22.3316,8.11181,2.91896,1.0414,0.368285,0.128918,0.0445702,0.0151809,0.00508254,0.00166966,0.00053755 };

        double Data2012Down[60]={
            13086.9,44573.1,75597,293668,621047,4.9627e+06,2.41796e+07,6.75848e+07,1.48933e+08,2.70449e+08,4.39928e+08,6.04128e+08,7.05872e+08,7.62483e+08,8.06487e+08,8.31453e+08,8.28038e+08,8.06076e+08,7.73662e+08,7.35171e+08,6.94927e+08,6.55747e+08,6.12765e+08,5.55923e+08,4.8121e+08,3.93868e+08,3.03191e+08,2.18271e+08,1.46631e+08,9.24274e+07,5.52799e+07,3.16541e+07,1.73547e+07,9.03137e+06,4.41161e+06,2.00916e+06,854168,342165,131095,48838.6,17936.6,6548.13,2382.12,862.067,309.278,109.667,38.383,13.2659,4.53433,1.53477,0.514543,0.170647,0.0558512,0.0179873,0.00568486,0.00175941,0.000532467,0.00015746,4.5487e-05,1.28368e-05 };

        double Data2012Up[60]={
            11386.9,21331.8,60739.1,166488,409754,1.13997e+06,8.0458e+06,2.76488e+07,6.6662e+07,1.3398e+08,2.29599e+08,3.61554e+08,5.01758e+08,6.02696e+08,6.59594e+08,6.99205e+08,7.31195e+08,7.46184e+08,7.40824e+08,7.22924e+08,6.97447e+08,6.67162e+08,6.34873e+08,6.03124e+08,5.71259e+08,5.3341e+08,4.83644e+08,4.21257e+08,3.50554e+08,2.77657e+08,2.0845e+08,1.47996e+08,9.96339e+07,6.40728e+07,3.96809e+07,2.37605e+07,1.372e+07,7.58333e+06,3.98016e+06,1.9744e+06,926199,413321,177237,73909,30311.3,12328.8,4995.94,2018.82,812.275,324.588,128.526,50.3667,19.5335,7.50397,2.85872,1.08078,0.405437,0.150752,0.0554593,0.0201443 };

        //=======================================================
        // For 2011 Data and MC
        //=======================================================

        double CENTRAL2011[50] = {5.37039e+06,1.25306e+06,9.11898e+06,1.1986e+08,3.81237e+08,5.40025e+08,5.45187e+08,4.93182e+08,4.38355e+08,4.03233e+08,3.7262e+08,3.46901e+08,3.27696e+08,3.0181e+08,2.58952e+08,1.98323e+08,1.31701e+08,7.46387e+07,3.57587e+07,1.44475e+07,4.97014e+06,1.4923e+06,405908,104272,26235.1,6600.02,1659.27,415.404,109.906,41.2309,33.2132,43.8802,63.9808,91.6263,126.102,166.165,209.506,252.713,291.616,321.941,340.153,343.94,332.511,307.736,272.51,230.858,187.096,145.067,107.618,76.3918};


        double LOW2011[50] = {5.43105e+06,1.41149e+06,1.46718e+07,1.72075e+08,4.5793e+08,5.8127e+08,5.57902e+08,4.94818e+08,4.42632e+08,4.08675e+08,3.75906e+08,3.5296e+08,3.28549e+08,2.87695e+08,2.2503e+08,1.51263e+08,8.55545e+07,4.02287e+07,1.5665e+07,5.10339e+06,1.43125e+06,360929,85884.8,20077,4699.5,1096.48,256.996,69.7713,35.4979,39.7273,58.0342,85.6779,121.581,164.519,212.022,260.171,303.964,338.138,358.297,361.584,347.27,317.767,276.884,229.704,181.44,136.467,97.7427,66.6703,43.3105,26.7966};


        double HIGH2011[50] = {5.31069e+06,1.15504e+06,6.00855e+06,8.15998e+07,3.10116e+08,4.9306e+08,5.27584e+08,4.89563e+08,4.36883e+08,3.97081e+08,3.69796e+08,3.42461e+08,3.22897e+08,3.04691e+08,2.7688e+08,2.32927e+08,1.75234e+08,1.15356e+08,6.56347e+07,3.20356e+07,1.33956e+07,4.84198e+06,1.54594e+06,450181,123968,33354.9,8955.57,2407.16,643.666,174.949,56.3123,31.9003,34.8057,48.5878,69.5207,96.7445,129.626,166.92,206.5,245.404,280.142,307.214,323.747,327.857,318.729,297.838,267.405,230.625,191.063,152.057};


        double Fall2011[50] = { 0.003388501, 0.010357558, 0.024724258, 0.042348605, 0.058279812, 0.068851751, 0.072914824, 0.071579609, 0.066811668, 0.060672356, 0.054528356, 0.04919354, 0.044886042, 0.041341896, 0.0384679, 0.035871463, 0.03341952, 0.030915649, 0.028395374, 0.025798107, 0.023237445, 0.020602754, 0.0180688, 0.015559693, 0.013211063, 0.010964293, 0.008920993, 0.007080504, 0.005499239, 0.004187022, 0.003096474, 0.002237361, 0.001566428, 0.001074149, 0.000721755, 0.000470838, 0.00030268, 0.000184665, 0.000112883, 6.74043E-05, 3.82178E-05, 2.22847E-05, 1.20933E-05, 6.96173E-06, 3.4689E-06, 1.96172E-06, 8.49283E-07, 5.02393E-07, 2.15311E-07, 9.56938E-08 };

        double Data2011_HLT17[50]={4.53155e+06,903521,6.27819e+06,1.00002e+08,3.07751e+08,4.32399e+08,4.56412e+08,4.46275e+08,4.24072e+08,4.00489e+08,3.72179e+08,3.46831e+08,3.27685e+08,3.01808e+08,2.58952e+08,1.98323e+08,1.31701e+08,7.46387e+07,3.57587e+07,1.44475e+07,4.97014e+06,1.4923e+06,405908,104272,26235.1,6600.02,1659.27,415.404,109.906,41.2309,33.2132,43.8802,63.9808,91.6263,126.102,166.165,209.506,252.713,291.616,321.941,340.153,343.94,332.511,307.736,272.51,230.858,187.096,145.067,107.618,76.3918};

        double Data2011Down_HLT17[50]={4.58571e+06,972464,1.07178e+07,1.43112e+08,3.67284e+08,4.69332e+08,4.78557e+08,4.61668e+08,4.3506e+08,4.07494e+08,3.75735e+08,3.52936e+08,3.28546e+08,2.87695e+08,2.2503e+08,1.51263e+08,8.55545e+07,4.02287e+07,1.5665e+07,5.10339e+06,1.43125e+06,360929,85884.8,20077,4699.5,1096.48,256.996,69.7713,35.4979,39.7273,58.0342,85.6779,121.581,164.519,212.022,260.171,303.964,338.138,358.297,361.584,347.27,317.767,276.884,229.704,181.44,136.467,97.7427,66.6703,43.3105,26.7966};

        double Data2011Up_HLT17[50]={4.47791e+06,869281,3.91862e+06,6.7883e+07,2.52345e+08,3.93437e+08,4.33566e+08,4.30062e+08,4.1343e+08,3.91397e+08,3.68755e+08,3.4228e+08,3.22866e+08,3.04686e+08,2.76879e+08,2.32927e+08,1.75234e+08,1.15356e+08,6.56347e+07,3.20356e+07,1.33956e+07,4.84198e+06,1.54594e+06,450181,123968,33354.9,8955.57,2407.16,643.666,174.949,56.3123,31.9003,34.8057,48.5878,69.5207,96.7445,129.626,166.92,206.5,245.404,280.142,307.214,323.747,327.857,318.729,297.838,267.405,230.625,191.063,152.057};

        double Data2011[50]={5.54422e+06,1.25309e+06,9.11919e+06,1.19861e+08,3.81257e+08,5.40125e+08,5.45336e+08,4.93285e+08,4.38377e+08,4.03235e+08,3.72621e+08,3.46901e+08,3.27696e+08,3.0181e+08,2.58952e+08,1.98323e+08,1.31701e+08,7.46387e+07,3.57587e+07,1.44475e+07,4.97014e+06,1.4923e+06,405908,104272,26235.1,6600.02,1659.27,415.404,109.906,41.2309,33.2132,43.8802,63.9808,91.6263,126.102,166.165,209.506,252.713,291.616,321.941,340.153,343.94,332.511,307.736,272.51,230.858,187.096,145.067,107.618,76.3918};

        double Data2011Up[50]={5.60487e+06,1.41152e+06,1.46721e+07,1.72078e+08,4.57969e+08,5.81393e+08,5.58058e+08,4.94886e+08,4.4264e+08,4.08676e+08,3.75906e+08,3.5296e+08,3.28549e+08,2.87695e+08,2.2503e+08,1.51263e+08,8.55545e+07,4.02287e+07,1.5665e+07,5.10339e+06,1.43125e+06,360929,85884.8,20077,4699.5,1096.48,256.996,69.7713,35.4979,39.7273,58.0342,85.6779,121.581,164.519,212.022,260.171,303.964,338.138,358.297,361.584,347.27,317.767,276.884,229.704,181.44,136.467,97.7427,66.6703,43.3105,26.7966};

        double Data2011Down[50]={5.48452e+06,1.15506e+06,6.00869e+06,8.16009e+07,3.10126e+08,4.93136e+08,5.27715e+08,4.89691e+08,4.36927e+08,3.97087e+08,3.69796e+08,3.42461e+08,3.22897e+08,3.04691e+08,2.7688e+08,2.32927e+08,1.75234e+08,1.15356e+08,6.56347e+07,3.20356e+07,1.33956e+07,4.84198e+06,1.54594e+06,450181,123968,33354.9,8955.57,2407.16,643.666,174.949,56.3123,31.9003,34.8057,48.5878,69.5207,96.7445,129.626,166.92,206.5,245.404,280.142,307.214,323.747,327.857,318.729,297.838,267.405,230.625,191.063,152.057};

        TH1F*      weights_;
};

#endif
