#include <iostream>
#include <string.h>
using namespace std;
const int N = 1003;
int m[N][N];
int P[N];
int W[N];
int main(){
    int n,w;
    cin >> n >> w;
    for(int i = 1;i <=n;i++){
        cin >> W[i] >> P[i];
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= w;j++){
            if(j >= W[i]){
                m[i][j] = max(m[i-1][j], m[i-1][j-W[i]]+P[i]);
            }else{
                m[i][j] = m[i-1][j];
            }
        }
    }
    cout << m[n][w] << endl;
    system("pause");
    return 0;
}
