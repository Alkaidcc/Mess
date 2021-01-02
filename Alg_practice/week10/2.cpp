#include <iostream>
#include <vector>
using namespace std;
const int N = 1000;
int m[N][N];
int dp[N][N];
int previous[N][N];
int n;

/* 状态转移方程
    dp[0][0] = m[0][0]
    dp[i][0] = dp[i - 1][0] + m[i][0]
    dp[i][i] = dp[i - 1][i - 1] + m[i][i]
    dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + m[i][j]
    时间复杂度O(n^2)
    空间复杂度O(n^2)
*/

void Initial();
int Solve();
void showPath(int k);
int main(){
    Initial();
    int k = Solve();
    cout << "最小路径和为: " << dp[n - 1][k];
    cout << "输出路径为: ";
    showPath(k);
    system("pause");
    return 0;
}

void Initial(){
    cin >> n;
    for(int i = 0;i < n;i++){
        for(int j = 0;j <= i;j++){
            cin >> m[i][j];
        }
    }
}
int Solve(){
    dp[0][0] = m[0][0];
    for(int i = 1;i < n;i++){
        dp[i][0] = dp[i - 1][0] + m[i][0];
        previous[i][0] = 0;
    }
    for(int i = 1;i < n;i++){
        dp[i][i] = dp[i - 1][i - 1] + m[i][i];
        previous[i][i] = i -1;
    }
    for(int i = 2;i < n;i++){
        for(int j = 1;j < i;j++){
            if(dp[i - 1][j - 1] < dp[i - 1][j]){
                dp[i][j] = dp[i - 1][j - 1] + m[i][j];
                previous[i][j] = j - 1;
            }else{
                dp[i][j] = dp[i - 1][j] + m[i][j];
                previous[i][j] = j;
            }
        }
    }
    int res = dp[n - 1][0];
    int k = 0;
    for(int j = 1; j < n;j++){
        if(dp[n - 1][j] < res){
            res = dp[n - 1][j];
            k = j;
        }
    }
    return k;
}
void showPath(int k){
    int i = n - 1;//移到最后一行
    vector<int> path;
    while(i >= 0){
        path.push_back(m[i][k]);
        k = previous[i][k];
        i--;
    }
    vector<int>::reverse_iterator it;
    for(it = path.rbegin();it != path.rend();it++){
        cout << *it << " ";
    }
    cout << endl;
}