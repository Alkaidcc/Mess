//ʹ��vector����100-200�ķ�Χ��ҳ������ܱ�7��������������ӡ���
#include <iostream>
#include <vector>
using namespace std;

void printer(int val){
    cout << val << ends;
}
int main(){
    vector<int> v;
    for(int i = 100;i <= 200;i++){
        if(i % 7 == 0){
            v.push_back(i);
        }
    }
    for(auto it:v){
        cout << it << ends;
    }
    cout << endl;
    system("pause");
    return 0;
}
