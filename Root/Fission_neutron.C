#include "F_N.h"
#define Max 1000000

void Fission_neutron(){
    // 主函数
    TCanvas *c = new TCanvas("c","Fission Neutron",1200,900);
    TH1D *h = new TH1D("h","Fission Neutron Distribution",500,0.0,12.0);
    TRandom3 r(0);
    for(int i=0;i<Max;i++){
        double ita = g();
        double x = r.Uniform();
        // 舍选
        if(x <= H1_M1(ita)*H2_M2(ita)) h->Fill(ita);
    }
    // 拟合
    TF1  *f = new TF1("f","[0]*[1]*0.453*exp(-x/0.965)*(exp(sqrt(2.29*x))-exp(-sqrt(2.29*x)))",0.0,12.0);
    f->SetParameter(1,1);
    h->SetXTitle("Energy");
    h->SetYTitle("Entry");
    h->Fit("f");
    h->Draw();
}