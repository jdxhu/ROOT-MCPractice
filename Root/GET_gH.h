#include"TMath.h"

double g(double e0){
    //输入：e最小值e0
    //输出：分布为 1/e + e 的一次抽样
    TRandom3 r(0);
    double a1 = -log(e0);
    double a2 = (1-e0*e0)/2;
    double p1 = a1/(a1+a2);
    double r1 = r.Uniform();
    double r2 = r.Uniform();
    double r3 = r.Uniform();
    if(r1 < p1) return e0*exp(a1*r2);
    return sqrt(e0*e0+2*a2*r3);
}

double H(double e,double k){
    //输入：得到的抽样e、参数k
    //输出：函数 H 的值
    return 1 - (2*k-2*k*e-1/e+2-e)/(1+e*e)/k/k;
}