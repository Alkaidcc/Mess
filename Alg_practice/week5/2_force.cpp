#include <iostream>
#include <cmath>
using namespace std;


void solve(int n, int w){
    int value[n];
    int weight[n];
    int weight1 = 0, value1 = 0, maxvalue = 0;
    cout << "���������Ʒ��ֵ��" << endl;
    for(int i = 0;i < n;i++){
        cin >> value[i];
    }
    cout << "���������Ʒ����: " << endl;
    for(int i = 0;i < n;i++){
        cin >> weight[i];
    }

    for(int num = 0;num < pow(2,n);num++){
        weight1 = value1 = 0;
        int temp = num;
        for(int i = 0;i < n;i++){
            if(temp % 2 == 1){
                weight1 = weight1 + weight[i];
                value1 = value1 + value[i];
            }
            temp = temp / 2;
        }
        if(weight1 <= w && maxvalue < value1){
            maxvalue = value1;
        }
    }
    cout << "����ֵΪ��" << maxvalue << endl;
}



int main(){
    int n, w;
    cout << "����������Ʒ��: " << endl;
    while(cin >> n){
        cout << "�����뱳��������" << endl;
        cin >> w;
        solve(n,w);
        cout << "����������Ʒ��: " << endl;
    }
    system("pause");
    return 0;
}
