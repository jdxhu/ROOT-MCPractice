#include"TMath.h"
#define Max 1000000

void NeutronSL(){
    double et;
    cout << "请输入Σt：" << endl;
    cin >> et;
    cin.clear();
    cin.sync();
    TCanvas *c = new TCanvas("c","Neutron Transport Length",1200,900);
    TH1D *h = new TH1D("h","L Distribution",1000,0.0,10/et);
    TRandom3 r(0);
    for(int i=0;i < Max;i++){
        double x = r.Uniform();
        double l = -log(x)/et;
        h->Fill(l);
    }
    h->Draw();
}