/*
Filename		:alg_3.cpp
Date			:2020/09/29 20:53:48
Author			:ZZC
Description     :整数数列的首项a1=1，后续奇数项和偶数项的
                计算公式分别为:
                ? a_(2n)=a(2n-1) + 2
                ? a_(2n+1) = a_(2n-1) + a_(2n)-1

*/
#include <iostream>

using namespace std;

int recursive(int n){
    if(n == 1){
        return 1;
    }
    if(n % 2 == 0){
        return recursive(n - 1) + 2;
    }else{
        return recursive(n - 2) + recursive(n - 1) - 1;
    }
}

int main(){
    int n;
    cout << "Please enter a sequence size: ";
    while (cin >> n && n >= 1)
    {
        for(int i = 1;i <= n;i++){
            cout << recursive(i) << " ";
        }
        cout << endl;
        cout << "Please enter a sequence size: ";
    }
    system("pause");
    return 0;
}
