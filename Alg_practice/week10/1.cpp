#include <iostream>
using namespace std;
const int N = 1000;
int m[N][N] = {0};

int Bin(int a,int b);
void Initial();

int main(){
    int  k, n;
    Initial();
    while (cin >> n >> k && k <= n)
    {
        int result = Bin(n,k);
        cout << result << endl;
    }
    

    system("pause");
    return 0;
}
void Initial(){
    for(int i = 0;i < N;i++){
        m[i][0] = 1;
        m[i][i] = 1;
        if(i){
            m[i][1] = i;    //C_i^1 = i
        }
    }
}

int Bin(int a,int b){
    if(b > a/2){
        b = a - b;
    }
    for(int i = 1;i <= a;i++){
        for(int j = 1;j < i;j++){
            m[i][j] = m[i - 1][j - 1] + m[i - 1][j];
        }
    }
    return m[a][b];
}