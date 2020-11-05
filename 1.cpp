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
    cout << "�����������С: ";
    cin >> n;
    int a[n];
    cout << "����������飺 "<< endl;
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    int result = f(a,n);
    cout << "����������С��ֵΪ��" << result;
    system("pause");
    return 0;
}
