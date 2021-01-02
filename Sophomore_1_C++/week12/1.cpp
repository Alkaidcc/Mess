//使用vector，在100-200的范围里，找出所有能被7整除的数，并打印输出
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
