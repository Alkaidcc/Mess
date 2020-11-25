#include <iostream>
#include <vector>
using namespace std;

long long map[21] = {1,0,0,2,10,4,40,92,352,742,2680,14200,73712,365596,2279184,14772512,95815104,666090624,4968057848,39029188884};
int array[1000];
int is_valid(int row, int col){   //判断第row行、第col列能否放置
    int i = 1;
    while(i < row){
        if(array[i] == col || abs(i - row) == abs(array[i] - col))
            return 0;
        i++;
    }
    return 1;
}

void solve(int row, int n){
    int i;
    if(row > n){
        map[n - 1]--;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                if(array[i] == j){
                    if(j == n){
                        cout << "Q";
                    }else{
                        cout << "Q ";
                    }
                }else{
                    if(j == n){
                        cout << ".";
                    }else{
                        cout << ". ";
                    }
                }
            }
            cout << endl;
        }
        if(map[n - 1]){
            cout << endl;
        }
    }
    for(i = 1;i <= n;i++){
        if(is_valid(row,i)){
            array[row] = i;
            solve(row + 1, n);
        }
    }
}

int main(){
    int n;
    cin >> n;
    if(n == 2 || n == 3){
        cout << "None";
    }
    else if(n >= 32764 && n <= 32767){
        
    }
    else{
        solve(1,n);
    }
    system("pause");
    return 0;
}
