#include <iostream>
#include <climits>
#include <iomanip>
using namespace std;
const int MAXN = 10;
const int n = 6;
int minCost = INT_MAX;  //���Ž�ĳɱ�
bool worker[MAXN] = {false};      //��ʾ����worker[i]�Ƿ��Ѿ�������Ա
int matrix[MAXN][MAXN]= {
                        {0,0,0,0,0,0},
                        {0,5,8,6,10,4,4},
                        {0,20,4,5,17,13,16},
                        {0,12,1,6,17,8,3},
                        {0,5,1,11,6,19,3},
                        {0,10,19,3,18,5,16},
                        {0,2,19,15,9,13,5}
                        };
int cost = 0;           //��ʱ��ĳɱ�
int temp[MAXN];         //��ʱ��
int best_r[MAXN];       //���Ž�
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
                temp[i] = j; //����j�������Աi
                cost += matrix[i][j];
                dfs(i + 1, n);
                worker[j] = false;//����״̬
                temp[i] = 0;
                cost -= matrix[i][j];
            }
        }
    }
}

int main(){
    cout << "�ɱ���Ϣ��Ϊ: " << endl;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            cout << setw(4) << matrix[i][j] << setw(4);
        }
        cout << endl;
    }
    cout << "�������Ϊ: " << endl;
    dfs(1,n);
    for(int i = 1;i <= n;i++){
        cout << best_r[i] << " ";
    }
    int sum = 0;
    for(int i = 1;i <= n;i++){
        sum += matrix[i][best_r[i]];
    }
    cout << "�ܻ���Ϊ: " << sum << endl;
    system("pause");
    return 0;
}
