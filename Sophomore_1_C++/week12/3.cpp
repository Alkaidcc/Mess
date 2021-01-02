// π”√list£¨¿€º”1-100
#include <iostream>
#include <list>
#include <numeric>
#include <algorithm>
using namespace std;

int main(){
    list<int> l;
    for(int i = 1;i <= 100;i++){
        l.push_back(i);
    }
    int result = accumulate(l.begin(),l.end(),0);
    cout << result << endl;
    system("pause");
    return 0;
}
