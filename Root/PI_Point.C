#include"TMath.h"
#define Max 1000000
#define Pi 3.1415926535898

int PI_Point(){
    TRandom3 r(0);
    double n=0,N=1;
    for(;N < Max;N++){
        double x = r.Uniform();
        double y = r.Uniform();
        if((x-0.5)*(x-0.5) + (y-0.5)*(y-0.5) < 0.25) n++;
    }
    cout.precision(10);
    cout << "Pi : " << 4.0*n/N << endl;
    cout << "相对误差 : " << fabs(Pi - n/N*4)/Pi * 100.f << "%" << endl;
    return 0;
}