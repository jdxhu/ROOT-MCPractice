#include"TMath.h"
#define Max 1000000

void NeutronML(double * et,double * L,int n){
    TCanvas *c = new TCanvas("c","Neutron Transport Length",1200,900);
    TH1D *h = new TH1D("h","NeutronML",1000,0.0,20);
    TRandom3 r(0);
    for(int j=0;j<Max;j++){
        double x = r.Uniform();
        double l;
        for(int i=0;i<n;i++){
            double d = exp(-L[i]*et[i])*(1-exp(-(L[i+1]-L[i])*et[i]));
            if(i<n-1 && x>d) x-=d;
            else{
                l = L[i] - log(1-x/exp(-L[i]*et[i]))/et[i];
                break;
            }
        }
        h->Fill(l);
    }
    h->Draw();
}