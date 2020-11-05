#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 1e6;
int f(int a[], int n){
    sort(a,a + n);
    int m = INF;
    for(int i = 0; i < n -1; +i){
        int temp = abs(a[i + 1] - a[i]);
        if (temp < m)
            m = temp;
    }
    return m;
}


int main(){
    int n;
    cout << "请输入数组大小: ";
    cin >> n;
    int a[n];
    cout << "请输入该数组： "<< endl;
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    int result = f(a,n);
    cout << "该数组中最小差值为：" << result;
    system("pause");
    return 0;
}
