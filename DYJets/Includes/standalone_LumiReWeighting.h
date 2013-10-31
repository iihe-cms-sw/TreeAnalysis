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
#ifndef standalone_LumiReWeighting_h
#define standalone_LumiReWeighting_h
#include "TH1.h"
#include "TFile.h"
#include <string>
#include "TH1.h"
#include "TFile.h"
#include <string>
#include <vector>
#include <TROOT.h>
#include <string>
#include <iostream>

using namespace std;

class standalone_LumiReWeighting {
   public:
      standalone_LumiReWeighting(string leptonFlavor = "Muons", int year = 2013,int mode = 0); // 0: central, -1: down, +1: up
      virtual ~standalone_LumiReWeighting();
      double weight( int npv) ;
      //void weightOOT_init();

   protected:
      TH1F*      weights_;
};

//=======================================================
// For 2012 Data and MC
//=======================================================

double SMu2013_Central[60] = {11862.6,27177,80878,314489,586962,2.52369e+06,1.53224e+07,4.78456e+07,1.16354e+08,2.34272e+08,4.05788e+08,6.33028e+08,8.31646e+08,9.53025e+08,1.03325e+09,1.09486e+09,1.13261e+09,1.14547e+09,1.14204e+09,1.12788e+09,1.1047e+09,1.0752e+09,1.04104e+09,9.99364e+08,9.42484e+08,8.64236e+08,7.65581e+08,6.53419e+08,5.36297e+08,4.22265e+08,3.18454e+08,2.30009e+08,1.59081e+08,1.05188e+08,6.63017e+07,3.9729e+07,2.26067e+07,1.22327e+07,6.32063e+06,3.1395e+06,1.51267e+06,715050,336226,159800,78061.6,39752.4,21266.7,11944.3,6991.73,4222.79,2606.21,1630.73,1028.13,649.957,410.339,257.832,160.771,99.2458,60.5361,36.4299};

double SMu2013_Low[60] = {12869.6,38127.5,104288,431847,760741,5.80755e+06,2.82651e+07,8.13057e+07,1.88962e+08,3.57216e+08,5.99206e+08,8.4362e+08,9.98257e+08,1.09364e+09,1.16519e+09,1.20825e+09,1.22157e+09,1.21601e+09,1.19776e+09,1.16927e+09,1.13397e+09,1.09248e+09,1.03825e+09,9.61208e+08,8.57917e+08,7.34673e+08,6.02221e+08,4.71209e+08,3.5115e+08,2.49137e+08,1.68265e+08,1.07975e+08,6.5601e+07,3.76177e+07,2.03431e+07,1.04011e+07,5.05811e+06,2.36123e+06,1.07106e+06,479341,215574,99418,47893.3,24375.9,13117.9,7403.44,4329.24,2592.7,1575.45,964.401,591.377,361.582,219.579,132.01,78.3647,45.8402,26.3824,14.9222,8.28798,4.5176};

double SMu2013_High[60] = {11198.5,20477.6,70414.7,245571,532827,1.38279e+06,9.36071e+06,3.24233e+07,8.05489e+07,1.69994e+08,3.02344e+08,4.89101e+08,6.96923e+08,8.47874e+08,9.39487e+08,1.00677e+09,1.05757e+09,1.08628e+09,1.09438e+09,1.08965e+09,1.0758e+09,1.05423e+09,1.02725e+09,9.96256e+08,9.59043e+08,9.09304e+08,8.41323e+08,7.54832e+08,6.54883e+08,5.4855e+08,4.42708e+08,3.43625e+08,2.56389e+08,1.83915e+08,1.26745e+08,8.37417e+07,5.29041e+07,3.18945e+07,1.83443e+07,1.00852e+07,5.32224e+06,2.71303e+06,1.34687e+06,657830,319968,157177,79123.3,41336.9,22580.1,12902.6,7670.17,4703.3,2949.03,1876.75,1205.12,777.189,501.463,322.672,206.485,131.099};
////////////////////////////////////////
double May2013_Central[60] = {12260.8,32850.4,92330.3,339464,618478,3.0497e+06,1.77215e+07,5.41421e+07,1.30521e+08,2.58981e+08,4.46344e+08,6.8564e+08,8.81642e+08,9.99085e+08,1.07862e+09,1.13797e+09,1.17211e+09,1.18207e+09,1.17701e+09,1.16108e+09,1.13609e+09,1.10481e+09,1.06807e+09,1.02107e+09,9.55582e+08,8.6706e+08,7.58729e+08,6.38851e+08,5.16436e+08,3.99862e+08,2.96257e+08,2.10055e+08,1.42404e+08,9.20546e+07,5.65387e+07,3.29089e+07,1.815e+07,9.51188e+06,4.76417e+06,2.29967e+06,1.08138e+06,501998,233744,111112,54826,28402.3,15490.1,8845.44,5236.34,3180.14,1964.06,1225.15,767.779,481.279,300.644,186.558,114.687,69.6938,41.7929,24.6979};

double May2013_Low[60] = { 13087.2,45087.6,108862,435408,777688,5.90189e+06,2.8735e+07,8.25604e+07,1.91584e+08,3.62173e+08,6.07808e+08,8.56998e+08,1.01597e+09,1.11324e+09,1.18514e+09,1.22918e+09,1.24394e+09,1.23976e+09,1.22272e+09,1.19506e+09,1.16011e+09,1.11853e+09,1.06372e+09,9.85892e+08,8.81412e+08,7.56332e+08,6.21427e+08,4.87512e+08,3.64372e+08,2.59377e+08,1.75806e+08,1.13202e+08,6.89686e+07,3.96173e+07,2.14342e+07,1.09502e+07,5.31508e+06,2.47431e+06,1.1185e+06,498629,223349,102612,49267.6,25003.3,13419.6,7552.84,4403.65,2629.33,1593.05,972.617,595.085,363.198,220.258,132.285,78.4722,45.8806,26.3971,14.9274,8.28971,4.51816};

double May2013_High[60] = {11387.2,21439.4,80594,247438,539837,1.4131e+06,9.50621e+06,3.29662e+07,8.17747e+07,1.72351e+08,3.06527e+08,4.96051e+08,7.0754e+08,8.62377e+08,9.56493e+08,1.02448e+09,1.07558e+09,1.10524e+09,1.11451e+09,1.11089e+09,1.09802e+09,1.07719e+09,1.0506e+09,1.01969e+09,9.82181e+08,9.319e+08,8.6323e+08,7.75699e+08,6.74233e+08,5.65941e+08,4.57803e+08,3.56256e+08,2.66576e+08,1.91823e+08,1.32618e+08,8.78787e+07,5.56453e+07,3.35937e+07,1.93284e+07,1.06193e+07,5.59536e+06,2.8457e+06,1.40866e+06,685720,332345,162674,81618.1,42515.4,23164.3,13204.7,7830.65,4789.32,2994.89,1900.83,1217.5,783.394,504.49,324.107,207.146,131.395};

double Ele_Jan2013_Central[60] = {12238.4,32502.1,89448.7,260312,524230,2.6615e+06,1.57489e+07,4.88939e+07,1.19465e+08,2.43265e+08,4.29338e+08,6.71368e+08,8.71877e+08,9.87852e+08,1.06108e+09,1.11724e+09,1.15207e+09,1.16278e+09,1.15716e+09,1.13979e+09,1.11266e+09,1.07876e+09,1.03971e+09,9.91838e+08,9.27814e+08,8.43258e+08,7.40655e+08,6.26902e+08,5.09645e+08,3.9657e+08,2.94928e+08,2.09692e+08,1.42498e+08,9.23628e+07,5.69232e+07,3.32769e+07,1.8448e+07,9.7236e+06,4.89898e+06,2.37798e+06,1.12355e+06,523398,244170,116089,57207,29569.8,16087.6,9167.68,5419.27,3288.54,2030.41,1266.7,794.2,498.233,311.567,193.591,119.194,72.5585,43.5935,25.8146 };

double Ele_Jan2013_Low[60] = {13087.1,45090.9,103112,332935,683241,5.26583e+06,2.60545e+07,7.57608e+07,1.79221e+08,3.47891e+08,5.95936e+08,8.49901e+08,1.00909e+09,1.09973e+09,1.16651e+09,1.21024e+09,1.22544e+09,1.2204e+09,1.20142e+09,1.17103e+09,1.1329e+09,1.08851e+09,1.03243e+09,9.55826e+08,8.55293e+08,7.36e+08,6.07063e+08,4.77922e+08,3.57996e+08,2.55039e+08,1.72843e+08,1.11255e+08,6.77832e+07,3.89643e+07,2.11132e+07,1.08106e+07,5.26171e+06,2.45651e+06,1.11337e+06,497390,223117,102591,49275.9,25009.9,13422.6,7554.01,4404.06,2629.46,1593.09,972.628,595.088,363.199,220.258,132.285,78.4722,45.8806,26.3971,14.9274,8.28971,4.51816};

double Ele_Jan2013_High[60] = {11387.1,21441.2,79825.6,199983,437025,1.25637e+06,8.51809e+06,2.99828e+07,7.51204e+07,1.61205e+08,2.9369e+08,4.84679e+08,6.9998e+08,8.57103e+08,9.47857e+08,1.01002e+09,1.05847e+09,1.0884e+09,1.09794e+09,1.09359e+09,1.07924e+09,1.05633e+09,1.02723e+09,9.93821e+08,9.54541e+08,9.03944e+08,8.36908e+08,7.5291e+08,6.56175e+08,5.52703e+08,4.48558e+08,3.49863e+08,2.62079e+08,1.88616e+08,1.30362e+08,8.63621e+07,5.4693e+07,3.30436e+07,1.90387e+07,1.0481e+07,5.53582e+06,2.8227e+06,1.40074e+06,683320,331725,162551,81608.9,42523.2,23170.4,13207.8,7832.01,4789.86,2995.09,1900.9,1217.52,783.401,504.492,324.107,207.146,131.395};

double Mu_Jan2013_Central[60] = {12238.4,32502.1,89450,260617,543077,2.97914e+06,1.72488e+07,5.06917e+07,1.18292e+08,2.38357e+08,4.2249e+08,6.64259e+08,8.67356e+08,9.84298e+08,1.05724e+09,1.11316e+09,1.14718e+09,1.15778e+09,1.15216e+09,1.13404e+09,1.1061e+09,1.07241e+09,1.03487e+09,9.88991e+08,9.2627e+08,8.41951e+08,7.38987e+08,6.24845e+08,5.07442e+08,3.94494e+08,2.93182e+08,2.08373e+08,1.41599e+08,9.18082e+07,5.66113e+07,3.3116e+07,1.83712e+07,9.68949e+06,4.88484e+06,2.37249e+06,1.12156e+06,522729,243961,116028,57190.8,29565.8,16086.8,9167.5,5419.23,3288.53,2030.41,1266.7,794.2,498.233,311.567,193.591,119.194,72.5585,43.5935,25.8146};


double Mu_Jan2013_Low[60] = {13087.1,45090.9,103115,333771,729432,5.87898e+06,2.80505e+07,7.67441e+07,1.75996e+08,3.41507e+08,5.88169e+08,8.44022e+08,1.00532e+09,1.09573e+09,1.16233e+09,1.20521e+09,1.22015e+09,1.21514e+09,1.19535e+09,1.16411e+09,1.12633e+09,1.08376e+09,1.02982e+09,9.54363e+08,8.53824e+08,7.34066e+08,6.04791e+08,4.75633e+08,3.55977e+08,2.53463e+08,1.71747e+08,1.10574e+08,6.74022e+07,3.87709e+07,2.10234e+07,1.07721e+07,5.24643e+06,2.45088e+06,1.11145e+06,496783,222941,102545,49264.6,25007.4,13422.1,7553.92,4404.05,2629.45,1593.09,972.628,595.088,363.199,220.258,132.285,78.4722,45.8806,26.3971,14.9274,8.28971,4.51816};

double Mu_Jan2013_High[60] = {11387.1,21441.2,79826,200085,443811,1.39733e+06,9.44925e+06,3.19105e+07,7.56894e+07,1.58267e+08,2.8814e+08,4.77802e+08,6.93848e+08,8.5334e+08,9.44444e+08,1.00639e+09,1.05458e+09,1.08377e+09,1.09321e+09,1.0889e+09,1.07393e+09,1.05024e+09,1.02105e+09,9.88699e+08,9.51189e+08,9.02098e+08,8.35679e+08,7.5155e+08,6.5443e+08,5.50679e+08,4.46488e+08,3.47963e+08,2.60502e+08,1.87425e+08,1.29541e+08,8.58444e+07,5.43923e+07,3.28818e+07,1.89576e+07,1.04429e+07,5.519e+06,2.8157e+06,1.39799e+06,682311,331377,162439,81575.3,42513.8,23167.9,13207.3,7831.88,4789.83,2995.09,1900.9,1217.52,783.401,504.492,324.107,207.146,131.395};

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

/* OLD 2011
double CENTRAL2011[50] = {5.31487e+06,1.10132e+06,7.12972e+06,9.52355e+07,3.22028e+08,4.82238e+08,5.03604e+08,4.66425e+08,4.20118e+08,3.91552e+08,3.66074e+08,3.43878e+08,3.26074e+08,3.00816e+08,2.58457e+08,1.98127e+08,1.31635e+08,7.46212e+07,3.57554e+07,1.44471e+07,4.9701e+06,1.4923e+06,405908,104272,26235.1,6600.02,1659.27,415.404,109.906,41.2309,33.2132,43.8802,63.9808,91.6263,126.102,166.165,209.506,252.713,291.616,321.941,340.153,343.94,332.511,307.736,272.51,230.858,187.096,145.067,107.618,76.3918};

double LOW2011[50] = {5.37094e+06,1.22111e+06,1.14936e+07,1.3812e+08,3.92728e+08,5.25042e+08,5.20119e+08,4.70702e+08,4.26699e+08,3.99231e+08,3.7135e+08,3.50853e+08,3.27295e+08,2.87039e+08,2.24769e+08,1.51177e+08,8.5532e+07,4.02247e+07,1.56645e+07,5.10336e+06,1.43125e+06,360929,85884.8,20077,4699.5,1096.48,256.996,69.7713,35.4979,39.7273,58.0342,85.6779,121.581,164.519,212.022,260.171,303.964,338.138,358.297,361.584,347.27,317.767,276.884,229.704,181.44,136.467,97.7427,66.6703,43.3105,26.7966};

double HIGH2011[50] = {5.25975e+06,1.03166e+06,4.70594e+06,6.44071e+07,2.58174e+08,4.34862e+08,4.82941e+08,4.59787e+08,4.16655e+08,3.8331e+08,3.61259e+08,3.38018e+08,3.20752e+08,3.03383e+08,2.76095e+08,2.32552e+08,1.75086e+08,1.15305e+08,6.56209e+07,3.20329e+07,1.33953e+07,4.84195e+06,1.54594e+06,450181,123968,33354.9,8955.57,2407.16,643.666,174.949,56.3123,31.9003,34.8057,48.5878,69.5207,96.7445,129.626,166.92,206.5,245.404,280.142,307.214,323.747,327.857,318.729,297.838,267.405,230.625,191.063,152.057};
*/

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

standalone_LumiReWeighting::standalone_LumiReWeighting(string leptonFlavor, int year,int mode) {

   //std::cout << "=======================================================================" << std::endl;

   std::vector<float> MC_distr;
   std::vector<float> Lumi_distr;

   MC_distr.clear();
   Lumi_distr.clear();
   //std::cout << "Year " << year << std::endl;
   if(year!=2011 && year!=2012 && year!=2013 && year!=201117 && leptonFlavor != "Muons" && leptonFlavor != "Electrons")
   {
      std::cout << "The year is not correct!! Reset to year 2012." << 
	 std::endl;
      year=2012;
      std::cout << "Year " << year << std::endl;
   }

   if (leptonFlavor == "Muons"){
      cout << "Muons PU distribution" << endl;
   }
   else if (leptonFlavor == "Electrons"){
      cout << "Electrons PU distribution" << endl;
   }
   switch (mode)
   {
      case 0:
	 //std::cout << "Using central value " << std::endl;
	 break;
      case 1:
	 //std::cout << "Using +1 sigma 5% value " << std::endl;
	 break;
      case -1:
	 //std::cout << "Using -1 sigma 5% value " << std::endl;
	 break;
      default:
	 //std::cout << "Using central value " << std::endl;
	 break;
   } // end of switch

   Int_t NBins = 60;
   if (year == 2011 || year == 201117) NBins = 50;

   for( int i=0; i< NBins; ++i) {
      if (year == 2011)
      {
	 switch (mode){
	    case 0:
	       //Lumi_distr.push_back(Data2011[i]);
	       Lumi_distr.push_back(CENTRAL2011[i]);
	       break;
	    case 1:
	       //Lumi_distr.push_back(Data2011Up[i]);
	       Lumi_distr.push_back(HIGH2011[i]);
	       break;
	    case -1:
	       //Lumi_distr.push_back(Data2011Down[i]);
	       Lumi_distr.push_back(LOW2011[i]);
	       break;
	    default:
	       //Lumi_distr.push_back(Data2011[i]);
	       Lumi_distr.push_back(CENTRAL2011[i]);
	       break;
	 } // end of switch
	 MC_distr.push_back(Fall2011[i]);
      }
      else if (year == 201117) {
	 switch (mode){
	    case 0:
	       Lumi_distr.push_back(Data2011_HLT17[i]);
	       break;
	    case 1:
	       Lumi_distr.push_back(Data2011Up_HLT17[i]);
	       break;
	    case -1:
	       Lumi_distr.push_back(Data2011Down_HLT17[i]);
	       break;
	    default:
	       Lumi_distr.push_back(Data2011_HLT17[i]);
	       break;
	 } // end of switch
	 MC_distr.push_back(Fall2011[i]);
      }
      else if (year == 2012)
      {
	 switch (mode){
	    case 0:
	       Lumi_distr.push_back(Data2012[i]);
	       break;
	    case 1:
	       Lumi_distr.push_back(Data2012Up[i]);
	       break;
	    case -1:
	       Lumi_distr.push_back(Data2012Down[i]);
	       break;
	    default:
	       Lumi_distr.push_back(Data2012[i]);
	       break;
	 } // end of switch
	 MC_distr.push_back(Summer2012_S10[i]);
      }
      
      else if (year == 20131){
	 if (leptonFlavor == "Muons" || leptonFlavor == "SingleMuon"){
	    switch (mode){
	       case 0:
		  Lumi_distr.push_back(Mu_Jan2013_Central[i]);
		  break;
	       case 1:
		  Lumi_distr.push_back(Mu_Jan2013_High[i]);
		  break;
	       case -1:
		  Lumi_distr.push_back(Mu_Jan2013_Low[i]);
		  break;
	       default:
		  Lumi_distr.push_back(Mu_Jan2013_Central[i]);
		  break;
	    }
	 }
	 else if (leptonFlavor == "Electrons"){
	    switch (mode){
	       case 0:
		  Lumi_distr.push_back(Ele_Jan2013_Central[i]);
		  break;
	       case 1:
		  Lumi_distr.push_back(Ele_Jan2013_High[i]);
		  break;
	       case -1:
		  Lumi_distr.push_back(Ele_Jan2013_Low[i]);
		  break;
	       default:
		  Lumi_distr.push_back(Ele_Jan2013_Central[i]);
		  break;
	    }
	 }
	 MC_distr.push_back(Summer2012_S10[i]);
      }

      else if ( year == 2013 ){
	  if (leptonFlavor == "SingleMuon" || leptonFlavor == "TTMuE" ){
                switch (mode){
                case 0:
                  Lumi_distr.push_back(SMu2013_Central[i]);
                  break;
               case 1:
                  Lumi_distr.push_back(SMu2013_High[i]);
                  break;
               case -1:
                  Lumi_distr.push_back(SMu2013_Low[i]);
                  break;
               default:
                  Lumi_distr.push_back(SMu2013_Central[i]);
                  break;
            }

          }
	  else if ( leptonFlavor == "Muons" || leptonFlavor == "Electrons"){
	 	switch (mode){
               	case 0:
                  Lumi_distr.push_back(May2013_Central[i]);
                  break;
               case 1:
                  Lumi_distr.push_back(May2013_High[i]);
                  break;
               case -1:
                  Lumi_distr.push_back(May2013_Low[i]);
                  break;
               default:
                  Lumi_distr.push_back(May2013_Central[i]);
                  break;
            }
      	}
	 MC_distr.push_back(Summer2012_S10[i]);
	}	
   } // end of loop over bins

   if( MC_distr.size() != Lumi_distr.size() ){   
      std::cout << "MC_distr.size() = " << MC_distr.size() << std::endl;
      std::cout << "Lumi_distr.size() = " << Lumi_distr.size() << std::endl;
      std::cerr <<"ERROR: standalone_LumiReWeighting: input vectors have different sizes. Quitting... \n";
   }

   weights_ = new TH1F(Form("luminumer_%d",mode),
	 Form("luminumer_%d",mode),
	 NBins,0., float(NBins));

   TH1F* den = new TH1F(Form("lumidenom_%d",mode),
	 Form("lumidenom_%d",mode),
	 NBins,0., float(NBins));

   for(int ibin = 1; ibin<NBins+1; ++ibin ) {
      weights_->SetBinContent(ibin, Lumi_distr[ibin-1]);
      den->SetBinContent(ibin,MC_distr[ibin-1]);
   }

   //std::cout << "Data Input " << std::endl;
   //for(int ibin = 1; ibin<NBins+1; ++ibin){
   //std::cout << "   " << ibin-1 << " " << weights_->GetBinContent(ibin) << std::endl;
   //}
   //std::cout << "MC Input " << std::endl;
   //for(int ibin = 1; ibin<NBins+1; ++ibin){
   //std::cout << "   " << ibin-1 << " " << den->GetBinContent(ibin) << std::endl;
   //}

   // check integrals, make sure things are normalized

   float deltaH = weights_->Integral();
   if(fabs(1.0 - deltaH) > 0.02 ) { //*OOPS*...
      weights_->Scale( 1.0/ weights_->Integral() );
   }
   float deltaMC = den->Integral();
   if(fabs(1.0 - deltaMC) > 0.02 ) {
      den->Scale(1.0/ den->Integral());
   }

   weights_->Divide( den );  // so now the average weight should be 1.0    

   //std::cout << "Reweighting: Computed Weights per In-Time Nint " << std::endl;


   //for(int ibin = 1; ibin<NBins+1; ++ibin){
   //std::cout << "   " << ibin-1 << " " << weights_->GetBinContent(ibin) << std::endl;
   //}

   //   weightOOT_init();
   //std::cout << "=======================================================================" << std::endl;

}

standalone_LumiReWeighting::~standalone_LumiReWeighting()
{
}



double standalone_LumiReWeighting::weight( int npv ) {
   int bin = weights_->GetXaxis()->FindBin( npv );
   return weights_->GetBinContent( bin );
}
/*
void standalone_LumiReWeighting::weightOOT_init() {

   // The following are poisson distributions with different means, where the maximum
   // of the function has been normalized to weight 1.0
   // These are used to reweight the out-of-time pileup to match the in-time distribution.
   // The total event weight is the product of the in-time weight, the out-of-time weight,
   // and a residual correction to fix the distortions caused by the fact that the out-of-time
   // distribution is not flat.

   static double weight_24[25] = { 0, 0, 0, 0, 2.46277e-06, 2.95532e-05, 0.000104668, 0.000401431, 0.00130034, 0.00342202, 0.00818132, 0.0175534, 0.035784, 0.0650836, 0.112232, 0.178699, 0.268934, 0.380868, 0.507505, 0.640922, 0.768551, 0.877829, 0.958624, 0.99939, 1 };

   static double weight_23[25] = { 0, 1.20628e-06, 1.20628e-06, 2.41255e-06, 1.20628e-05, 6.39326e-05, 0.000252112, 0.000862487, 0.00244995, 0.00616527, 0.0140821, 0.0293342, 0.0564501, 0.100602, 0.164479, 0.252659, 0.36268, 0.491427, 0.627979, 0.75918, 0.873185, 0.957934, 0.999381, 1, 0.957738 };

   static double weight_22[25] = { 0, 0, 0, 5.88636e-06, 3.0609e-05, 0.000143627, 0.000561558, 0.00173059, 0.00460078, 0.0110616, 0.0238974, 0.0475406, 0.0875077, 0.148682, 0.235752, 0.343591, 0.473146, 0.611897, 0.748345, 0.865978, 0.953199, 0.997848, 1, 0.954245, 0.873688 };

   static double weight_21[25] = { 0, 0, 1.15381e-06, 8.07665e-06, 7.1536e-05, 0.000280375, 0.00107189, 0.00327104, 0.00809396, 0.0190978, 0.0401894, 0.0761028, 0.13472, 0.216315, 0.324649, 0.455125, 0.598241, 0.739215, 0.861866, 0.953911, 0.998918, 1, 0.956683, 0.872272, 0.76399 };


   static double weight_20[25] = { 0, 0, 1.12532e-06, 2.58822e-05, 0.000145166, 0.000633552, 0.00215048, 0.00592816, 0.0145605, 0.0328367, 0.0652649, 0.11893, 0.19803, 0.305525, 0.436588, 0.581566, 0.727048, 0.8534, 0.949419, 0.999785, 1, 0.953008, 0.865689, 0.753288, 0.62765 }; 

   static double weight_19[25] = { 0, 0, 1.20714e-05, 5.92596e-05, 0.000364337, 0.00124994, 0.00403953, 0.0108149, 0.025824, 0.0544969, 0.103567, 0.17936, 0.283532, 0.416091, 0.562078, 0.714714, 0.846523, 0.947875, 1, 0.999448, 0.951404, 0.859717, 0.742319, 0.613601, 0.48552 };

   static double weight_18[25] = { 0, 3.20101e-06, 2.88091e-05, 0.000164319, 0.000719161, 0.00250106, 0.00773685, 0.0197513, 0.0443693, 0.0885998, 0.159891, 0.262607, 0.392327, 0.543125, 0.69924, 0.837474, 0.943486, 0.998029, 1, 0.945937, 0.851807, 0.729309, 0.596332, 0.467818, 0.350434 };

   static double weight_17[25] = { 1.03634e-06, 7.25437e-06, 4.97443e-05, 0.000340956, 0.00148715, 0.00501485, 0.0143067, 0.034679, 0.0742009, 0.140287, 0.238288, 0.369416, 0.521637, 0.682368, 0.828634, 0.939655, 1, 0.996829, 0.94062, 0.841575, 0.716664, 0.582053, 0.449595, 0.331336, 0.234332 };

   static double weight_16[25] = { 4.03159e-06, 2.41895e-05, 0.000141106, 0.00081942, 0.00314565, 0.00990662, 0.026293, 0.0603881, 0.120973, 0.214532, 0.343708, 0.501141, 0.665978, 0.820107, 0.938149, 1, 0.99941, 0.940768, 0.837813, 0.703086, 0.564023, 0.42928, 0.312515, 0.216251, 0.14561 };

   static double weight_15[25] = { 9.76084e-07, 5.07564e-05, 0.000303562, 0.00174036, 0.00617959, 0.0188579, 0.047465, 0.101656, 0.189492, 0.315673, 0.474383, 0.646828, 0.809462, 0.934107, 0.998874, 1, 0.936163, 0.827473, 0.689675, 0.544384, 0.40907, 0.290648, 0.198861, 0.12951, 0.0808051 };

   static double weight_14[25] = { 1.13288e-05, 0.000124617, 0.000753365, 0.00345056, 0.0123909, 0.0352712, 0.0825463, 0.16413, 0.287213, 0.44615, 0.625826, 0.796365, 0.930624, 0.999958, 1, 0.934414, 0.816456, 0.672939, 0.523033, 0.386068, 0.269824, 0.180342, 0.114669, 0.0698288, 0.0406496 };

   static double weight_13[25] = { 2.54296e-05, 0.000261561, 0.00167018, 0.00748083, 0.0241308, 0.0636801, 0.138222, 0.255814, 0.414275, 0.600244, 0.779958, 0.92256, 0.999155, 1, 0.927126, 0.804504, 0.651803, 0.497534, 0.35976, 0.245834, 0.160904, 0.0991589, 0.0585434, 0.0332437, 0.0180159 };

   static double weight_12[25] = { 5.85742e-05, 0.000627706, 0.00386677, 0.0154068, 0.0465892, 0.111683, 0.222487, 0.381677, 0.5719, 0.765001, 0.915916, 1, 0.999717, 0.921443, 0.791958, 0.632344, 0.475195, 0.334982, 0.223666, 0.141781, 0.0851538, 0.048433, 0.0263287, 0.0133969, 0.00696683 };

   static double weight_11[25] = { 0.00015238, 0.00156064, 0.00846044, 0.0310939, 0.0856225, 0.187589, 0.343579, 0.541892, 0.74224, 0.909269, 0.998711, 1, 0.916889, 0.77485, 0.608819, 0.447016, 0.307375, 0.198444, 0.121208, 0.070222, 0.0386492, 0.0201108, 0.0100922, 0.00484937, 0.00222458 };

   static double weight_10[25] = { 0.000393044, 0.00367001, 0.0179474, 0.060389, 0.151477, 0.302077, 0.503113, 0.720373, 0.899568, 1, 0.997739, 0.909409, 0.75728, 0.582031, 0.415322, 0.277663, 0.174147, 0.102154, 0.0566719, 0.0298642, 0.0147751, 0.00710995, 0.00319628, 0.00140601, 0.000568796 };

   static double weight_9[25] = { 0.00093396, 0.00854448, 0.0380306, 0.113181, 0.256614, 0.460894, 0.690242, 0.888781, 1, 0.998756, 0.899872, 0.735642, 0.552532, 0.382726, 0.246114, 0.147497, 0.0825541, 0.0441199, 0.0218157, 0.0103578, 0.00462959, 0.0019142, 0.000771598, 0.000295893, 0.000111529 };

   static double weight_8[25] = { 0.00240233, 0.0192688, 0.0768653, 0.205008, 0.410958, 0.65758, 0.875657, 0.999886, 1, 0.889476, 0.711446, 0.517781, 0.345774, 0.212028, 0.121208, 0.0644629, 0.0324928, 0.0152492, 0.00673527, 0.0028547, 0.00117213, 0.000440177, 0.000168471, 5.80689e-05, 1.93563e-05 };

   static double weight_7[25] = { 0.00617233, 0.0428714, 0.150018, 0.350317, 0.612535, 0.856525, 0.999923, 1, 0.87544, 0.679383, 0.478345, 0.303378, 0.176923, 0.0950103, 0.0476253, 0.0222211, 0.00972738, 0.00392962, 0.0015258, 0.000559168, 0.000183928, 6.77983e-05, 1.67818e-05, 7.38398e-06, 6.71271e-07 };

   static double weight_6[25] = { 0.0154465, 0.0923472, 0.277322, 0.55552, 0.833099, 0.999035, 1, 0.855183, 0.641976, 0.428277, 0.256804, 0.139798, 0.0700072, 0.0321586, 0.0137971, 0.00544756, 0.00202316, 0.000766228, 0.000259348, 8.45836e-05, 1.80362e-05, 8.70713e-06, 3.73163e-06, 6.21938e-07, 0 };

   static double weight_5[25] = { 0.0382845, 0.191122, 0.478782, 0.797314, 1, 0.997148, 0.831144, 0.59461, 0.371293, 0.205903, 0.103102, 0.0471424, 0.0194997, 0.00749415, 0.00273709, 0.000879189, 0.000286049, 0.000102364, 1.70606e-05, 3.98081e-06, 2.27475e-06, 0, 0, 0, 0 };

   static double weight_4[25] = { 0.0941305, 0.373824, 0.750094, 1, 0.997698, 0.800956, 0.532306, 0.304597, 0.152207, 0.0676275, 0.0270646, 0.00975365, 0.00326077, 0.00101071, 0.000301781, 7.41664e-05, 1.58563e-05, 3.58045e-06, 1.02299e-06, 0, 5.11493e-07, 0, 0, 0, 0 };

   static double weight_3[25] = { 0.222714, 0.667015, 1, 0.999208, 0.750609, 0.449854, 0.224968, 0.0965185, 0.0361225, 0.012084, 0.00359618, 0.000977166, 0.000239269, 6.29422e-05, 1.16064e-05, 1.78559e-06, 0, 4.46398e-07, 0, 0, 0, 0, 0, 0, 0 };

   static double weight_2[25] = { 0.499541, 0.999607, 1, 0.666607, 0.333301, 0.13279, 0.0441871, 0.0127455, 0.00318434, 0.00071752, 0.000132204, 2.69578e-05, 5.16999e-06, 2.21571e-06, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

   static double weight_1[25] = { 0.999165, 1, 0.499996, 0.166868, 0.0414266, 0.00831053, 0.00137472, 0.000198911, 2.66302e-05, 2.44563e-06, 2.71737e-07, 2.71737e-07, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0  };

   static double weight_0[25] = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0  };

   
      double* WeightPtr = NULL;

      for(int iint = 0; iint<25; ++iint){
      if(iint ==0) WeightPtr = weight_0;
      if(iint ==1) WeightPtr = weight_1;
      if(iint ==2) WeightPtr = weight_2;
      if(iint ==3) WeightPtr = weight_3;
      if(iint ==4) WeightPtr = weight_4;
      if(iint ==5) WeightPtr = weight_5;
      if(iint ==6) WeightPtr = weight_6;
      if(iint ==7) WeightPtr = weight_7;
      if(iint ==8) WeightPtr = weight_8;
      if(iint ==9) WeightPtr = weight_9;
      if(iint ==10) WeightPtr = weight_10;
      if(iint ==11) WeightPtr = weight_11;
      if(iint ==12) WeightPtr = weight_12;
      if(iint ==13) WeightPtr = weight_13;
      if(iint ==14) WeightPtr = weight_14;
      if(iint ==15) WeightPtr = weight_15;
      if(iint ==16) WeightPtr = weight_16;
      if(iint ==17) WeightPtr = weight_17;
      if(iint ==18) WeightPtr = weight_18;
      if(iint ==19) WeightPtr = weight_19;
      if(iint ==20) WeightPtr = weight_20;
      if(iint ==21) WeightPtr = weight_21;
      if(iint ==22) WeightPtr = weight_22;
      if(iint ==23) WeightPtr = weight_23;
      if(iint ==24) WeightPtr = weight_24;
      }
      
}
*/

#endif
