/*
Filename		:3.cpp
Date			:2020/10/09 08:19:23
Author			:ZZC
Description     :编写一个函数，能交换两个整型数组。
*/
#include <iostream>
using namespace std;
void swap_array(int* x, int* y, int n);
void swap_array(int* x, int* y, int n){
    for(int i = 0;i < n;i++){
        int temp = x[i];
        x[i] = y[i];
        y[i] = temp;
    }
}

int main(){
    int a[5] = {1,5,6,8,2};
    int b[5] = {9,8,7,5,3};
    int n = 5;
    for(int i = 0; i < 5;i++){
        cout << a[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < 5;i++){
        cout << b[i] << " ";
    }
    cout << endl;
    swap_array(a,b,n);
    cout << "after swapping :" << endl;
    for(int i = 0; i < 5;i++){
        cout << a[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < 5;i++){
        cout << b[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}
