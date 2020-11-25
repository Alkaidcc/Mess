#include <iostream>
#include <climits>
#include <iomanip>
using namespace std;
const int MAXN = 10;
const int n = 6;
int minCost = INT_MAX;  //最优解的成本
bool worker[MAXN] = {false};      //表示任务worker[i]是否已经分配人员
int matrix[MAXN][MAXN]= {
                        {0,0,0,0,0,0},
                        {0,5,8,6,10,4,4},
                        {0,20,4,5,17,13,16},
                        {0,12,1,6,17,8,3},
                        {0,5,1,11,6,19,3},
                        {0,10,19,3,18,5,16},
                        {0,2,19,15,9,13,5}
                        };
int cost = 0;           //临时解的成本
int temp[MAXN];         //临时解
int best_r[MAXN];       //最优解
void dfs(int i, int n){
    if(i > n){
        if(cost < minCost){
            minCost = cost;
            for(int j = 1;j <= n;j++){
                best_r[j] = temp[j];
            }
        }
    }else{
        for(int j = 1;j <= n;j++){
            if(!worker[j]){
                worker[j] = true;
                temp[i] = j; //分配j任务给人员i
                cost += matrix[i][j];
                dfs(i + 1, n);
                worker[j] = false;//重置状态
                temp[i] = 0;
                cost -= matrix[i][j];
            }
        }
    }
}

int main(){
    cout << "成本信息表为: " << endl;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            cout << setw(4) << matrix[i][j] << setw(4);
        }
        cout << endl;
    }
    cout << "任务分配为: " << endl;
    dfs(1,n);
    for(int i = 1;i <= n;i++){
        cout << best_r[i] << " ";
    }
    int sum = 0;
    for(int i = 1;i <= n;i++){
        sum += matrix[i][best_r[i]];
    }
    cout << "总花费为: " << sum << endl;
    system("pause");
    return 0;
}
