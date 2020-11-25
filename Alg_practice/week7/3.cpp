#include <iostream>
using namespace std;

typedef struct Components{
    int w;
    int c;
}Components;
Components Com[100][100];//Com[i][j].w 代表第i个零件在第j个供应商的重量 Com[i][j].c代表第i个零件在第j个供应商的价格
int bestWeight = 1e7;   //记录最终最小重量 最优解
int tempWeight = 0;     //记录临时最小重量
int tempPro[100];       //记录临时供应商的解    tempPro[i]代表第i个零件的供应商
int bestPro[100];       //记录最终供应商的解 最优解
int tempCost = 0;
int cost;   //规定的价格
int n;      //部件数
int m;      //供应商数


void dfs(int f){    //n代表层数，
    if(f > n - 1){//递归出口，达到叶子结点，表示已经选中一种排序方式，更新解
        bestWeight = tempWeight;
        for(int i = 0;i < n;i++){
            bestPro[i] = tempPro[i];
        }
    }
    else{
        for(int i = 0;i < m;i++){
            if(tempCost + Com[f][i].c <= cost && tempWeight + Com[f][i].w < bestWeight){
                tempPro[f] = i;
                tempCost += Com[f][i].c;
                tempWeight += Com[f][i].w;
                dfs(f + 1);
                tempCost -= Com[f][i].c;
                tempWeight -= Com[f][i].w;
            }
        }
    }
}


int main(){
    cout << "请输入部件数、供应商数、规定的价格：";
    cin >> n >> m >> cost;
    cout << "请输入部件重量矩阵：" << endl;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin >> Com[i][j].w;
        }
    }
    cout << "请输入部件价格矩阵：" << endl;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin >> Com[i][j].c;
        }
    }
    dfs(0);
    for(int i = 0;i < n;i++){
        cout << bestPro[i] + 1 << " ";
    }
    cout << endl;
    cout << bestWeight << endl;
    system("pause");
    return 0;
}
