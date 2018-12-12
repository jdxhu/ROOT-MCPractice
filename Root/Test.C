#include"TMath.h"
#include"NeutronML.h"

void Test(){
    int choice = -1;
    cout << "请输入测试用例介质种数(1～5)，并按回车(0为退出):" << endl;
    cin >> choice;
    cin.clear();
    cin.sync();
    switch(choice){
        case 1:{
            double et[] = {0.5};
            double L[] = {0,10};
            NeutronML(et,L,1);
            break;
        }
        case 2:{
            double et[] = {0.1,0.5};
            double L[] = {0,5,10};
            NeutronML(et,L,2);
            break;
        }
        case 3:{
            double et[] = {0.1,0.5,0.9};
            double L[] = {0,3.33,6.66,10};
            NeutronML(et,L,3);
            break;
        }
        case 4:{
            double et[] = {0.1,0.3,0.5,0.9};
            double L[] = {0,2.5,5,7.5,10};
            NeutronML(et,L,4);
            break;
        }
        case 5:{
            double et[] = {0.1,0.3,0.5,0.7,0.9};
            double L[] = {0,2,4,6,8,10};
            NeutronML(et,L,5);
            break;
        }
        case 0: break;
    }
}  
