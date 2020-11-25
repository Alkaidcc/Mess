#include <iostream>
#include <vector>
using namespace std;

vector <int> res;
int dfs(int a[], int op[], int i, int n, int k, int left_value, int total_value) //求解0/1背包问题
{
    if(i <= n){
        if (total_value == k){
            for (int j = 0; j < n; j++){
                if(op[j] == 1){
                    res.push_back(j);
                }
            }
            return 1;
        }
        else{
            if (total_value + a[i] <= k) //左孩子结点剪枝
            {
                op[i] = 1; //选取第i个物品
                if(dfs(a, op, i + 1, n, k, left_value - a[i], total_value + a[i])){
                    return 1;
                }
            }
            op[i] = 0;       //不选取第i个物品,回溯
            if (total_value + left_value > k){
                if(dfs(a, op, i + 1, n, k, left_value - a[i], total_value)){
                    return 1;
                }
            }
        }
    }
    return 0;
}
bool not_find(vector<int>& res){
    return res.size() == 0;
}
int main(){


    int n, k;
    int sum = 0;
    cin >> n >> k;
    int a[n];
    int op[n] = {0};
    for(int i = 0;i < n;i++){
        cin >> a[i];
        sum += a[i];
    }
    if(sum == k){
        for(int i = 0;i < n;i++){
            cout << a[i] << " ";
        }
        return 0;
    }
    int flag = dfs(a,op,0,n,k,sum,0);
    
    if(flag == 1){
        for(int i = 0;i < res.size();i++){
            cout << a[res[i]] << " ";
        }
    }else{
        cout << "No Solution!" << endl;
    }
    
//     system("pause");
    return 0;
}



