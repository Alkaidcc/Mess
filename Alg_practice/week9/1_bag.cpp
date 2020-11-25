#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

const int n = 7;
int w = 15;
typedef struct stuff{
    double weight;
    double value;
    double vperw;
    bool operator<(const stuff& s){
        return vperw > s.vperw;
    }
}stuff;
stuff A[7];
int main(){
    double best_v = 0;
    cout << "请输入物品重量: " << endl;
    for(int i = 0; i < n;i++){
        cin >> A[i].weight;
    }
    cout << "请输入物品价值: " << endl;
    for(int i = 0;i < n;i++){
        cin >> A[i].value;
    }
    for(int i = 0;i < n;i++){
        A[i].vperw = A[i].value / A[i].weight;
    }
    sort(A,A + n);
    for(int i = 0;i < n;i++){
        if(A[i].weight <= w){
            best_v += A[i].value;
            w -= (int)A[i].weight;
        }else{
            best_v += A[i].vperw * w;
            break;
        }
    }
    cout.setf(ios::fixed);
    cout << "最优解为: " << setprecision(2) << best_v << endl;
    system("pause");
    return 0;
}
