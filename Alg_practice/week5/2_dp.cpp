#include <iostream>
#include <string.h>
using namespace std;
const int N = 20;
int m[N][N];
int main(){
    int P[N] = {0, 10, 5, 15, 7, 6, 18, 3};
    int W[N] = {0, 2, 3, 5, 7, 1, 4, 1};
    int n = 7, w = 15;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= w;j++){
            if(j >= W[i]){
                m[i][j] = max(m[i-1][j], m[i-1][j-W[i]]+P[i]);
            }else{
                m[i][j] = m[i-1][j];
            }
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= w;j++){
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
    cout << "最优解为：" << m[n][w] << endl;
    system("pause");
    return 0;
}
