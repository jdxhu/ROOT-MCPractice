#include"TMath.h"
#define Max 1000000

int PI_Buffin(){
    TRandom3 r(0);
    const double a = 2.0;
    const double l = 1.0;
    const double pi = 3.1415926535898;
    double x,theta;
    double N=1,n=0;
    for(;N <= Max;N++){
        x = a * r.Uniform();
        theta =  pi * r.Uniform();
        if(x < l*sin(theta)) n++;
    }
    cout.precision(10);
    cout << "Pi : " << N/n << endl;
    cout << "相对误差 : " << fabs(pi - N/n)/pi * 100.f << "%" << endl;
    return 0;
}
