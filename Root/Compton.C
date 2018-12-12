#include"TMath.h"
#include"GET_gH.h"
#define MAX 1000000
#define K 1.0 // 入射能量 = K * 静止电子能量

void Compton(){
    // 这是用以康普顿散射模拟的主函数
    double e0 = 1/(2*K + 1); // 根据参数K，求得出射能量与入射能量之比的最小值
    TCanvas *c = new TCanvas("Compton","Compton Effect Distribution",1200,900);
    TH1D *h = new TH1D("Compton","Compton Effect Distribution",300,e0,1.0);
    TRandom3 r(0);
    double j = 0;
    for(int i = 0;i < MAX;i++){
        double r3 = r.Uniform();
        double ita = g(e0);// 从分布函数g抽取一个样本ita
        if(r3 < H(ita,K)){// 样本舍选的判断条件
            h->Fill(ita);
            j++;
        }
    }
    TF1  *f1 = new TF1("f1","[0]*(1/x + x)*(1 - (2*[1]-2*[1]*x-1/x+2-x)/(1+x*x)/[1]/[1])",e0,1);
    f1->SetParameter(1,K);// 定义拟合函数f1，定义两参量自然单位制的1和参数K
    h->SetXTitle("epsilon");
    h->SetYTitle("Entry");
    h->Fit("f1","R");
    h->Draw();
    cout << "抽样效率：" << j/MAX << endl;
}