#include <iostream>
#include <vector>
using namespace std;

vector <int> res(1000);
vector <int> temp;
void dfs(int a[], int op[], int i, int n, int k, int left_value, int total_value) //求解0/1背包问题
{
    if(i <= n){
        if (total_value == k){
            for (int j = 0; j < n; j++){
                if(op[j] == 1){
                    temp.push_back(j);
                }
            }
            if(temp.size() < res.size()){
                res.clear();
                for(int i = 0;i < temp.size();i++){
                    res.push_back(temp[i]);
                }
            }
            temp.clear();
        }
        else{
            if (total_value + a[i] <= k) //左孩子结点剪枝
            {
                op[i] = 1; //选取第i个物品
                dfs(a, op, i + 1, n, k, left_value - a[i], total_value + a[i]);
            }
            op[i] = 0;       //不选取第i个物品,回溯
            if (total_value + left_value > k) //右孩子结点剪枝
                dfs(a, op, i + 1, n, k, left_value - a[i], total_value);
        }
    }
}
bool not_find(vector<int>& res){
    for(int i = 1;i < res.size();i++){
        if(res[i] != res[i - 1]){
            return false;
        }
    }
    return true;
}
int main(){

    cout << "请输入数组大小: ";
    int n;
    int sum = 0;
    cin >> n;
    int a[n];
    int op[n] = {0};
    cout << "请输入该数组：" << endl;
    for(int i = 0;i < n;i++){
        cin >> a[i];
        sum += a[i];
    }
    cout << "请输入K: ";
    int k;
    cin >> k;
    dfs(a,op,0,n,k,sum,0);
    if(not_find(res)){
        cout << "未找到" << endl;
    }else{
        for(int i = 0;i < res.size();i++){
            cout << a[res[i]] << " ";
        }
    }
    
    system("pause");
    return 0;
}



