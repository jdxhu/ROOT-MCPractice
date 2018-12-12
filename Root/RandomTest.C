#include "TMath.h"
#define Max 1000000

int RandomTest(){
    TRandom3 r(0);
        
    int c = -1;
        cout << "输入数字并按回车:\n1. 1维均匀分布\n2. 2维均匀分布\n3. 3维均匀分布\n4. 高斯分布\n5. 指数分布\n6. 二项分布\n0. 退出\n" << endl;
        cin >> c;
    switch(c){
        case 1:{
            TCanvas* c1 = new TCanvas("Uniform1D","Uniform1D",1200,900);
            TH1D* hUniform1 = new TH1D("hUniform1","Uniform1D",100,0.0,1.0);
            for(int i=0;i<Max;i++){
                double x = r.Uniform(0.0,1.0);
                hUniform1->Fill(x);
            } 
            hUniform1->Draw();
            break;
        }
        case 2:{
            TCanvas* c1 = new TCanvas("Uniform2D","Uniform2D",1200,900);
            TH2D* hUniform2 = new TH2D("hUniform2","Uniform2D",100,0.0,1.0,100,0.0,1.0);
            for(int i=0;i<Max;i++){
                double x = r.Uniform(0.0,1.0);
                double y = r.Uniform(0.0,1.0);
                hUniform2->Fill(x,y);
            }
            hUniform2->Draw();
            break;
        }
        case 3:{
            TCanvas* c1 = new TCanvas("Uniform3D","Uniform3D",1200,900);
            TH3D* hUniform3 = new TH3D("hUniform3","Uniform3D",100,0.0,1.0,100,0.0,1.0,100,0.0,1.0);
            for(int i=0;i<Max;i++){
                double x = r.Uniform(0.0,1.0);
                double y = r.Uniform(0.0,1.0);
                double z = r.Uniform(0.0,1.0);
                hUniform3->Fill(x,y,z);
            } 
            hUniform3->Draw();
            break;
        }
        case 4:{
            TCanvas* c1 = new TCanvas("Gaus","Gaus",1200,900);
            TH1D* hGaus = new TH1D("hGaus","Gaus Distribution",100,-5.0,5.0);
            for(int i=0;i<Max;i++){
                double x = r.Gaus(0.0,1.0);
                hGaus->Fill(x);
            } 
            hGaus->Draw();
            break;
        }
        case 5:{
            TCanvas* c1 = new TCanvas("Exp","Exp",1200,900);
            TH1D* hExp = new TH1D("hExp","Exponential Distribution",100,0.0,10.0);
            for(int i=0;i<Max;i++){
                double x = r.Exp(1.5);
                hExp->Fill(x);
            } 
            hExp->Draw();
            break;
        }
        case 6:{
            TCanvas* c1 = new TCanvas("Binomial","Binomial",1200,900);
            TH1D* hBinomial = new TH1D("hBinomial","Binomial Distribution",100,0.0,1000.0);
            for(int i=0;i<Max;i++){
                double x = r.Binomial(1000,0.5);
                hBinomial->Fill(x);
            } 
            hBinomial->Draw();
            break;
        }
        case 0:{
            break;
        }
    }
    return 0;
}