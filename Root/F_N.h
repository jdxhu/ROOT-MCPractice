#include "TMath.h"
const double A = 0.965;
const double B = 2.29;
const double C = 0.453;

double g(){
    // 这是g(E)的取样函数
    // 输入: null
    // 输出: double
    TRandom3 r(0);
    double r1 = r.Uniform();
    return -2.0*A*log(r1);
}

double H1_M1(double E){
    // 这是求H1(E)/M1值的函数
    // 输入: double
    // 输出: double
    return exp(sqrt(B*E)-E/2/A-A*B/2);
}

double H2_M2(double E){
    // 这是求H2(E)/M2值的函数
    // 输入: double
    // 输出: double
    return 1-exp(-2*sqrt(B*E));
}