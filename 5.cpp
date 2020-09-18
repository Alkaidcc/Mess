/*
Filename		:5.cpp
Date			:2020/09/18 09:20:24
Author			:ZZC
Description     :将一个小数数组中的各个小数反序排列
*/
#include <iostream>
using namespace std;

void inv(int* x, int n);
void inv(int* x, int n){
    int temp;
    for(int i = 0;i < n;i++,n--){
            temp = x[i];
            x[i] = x[n-1];
            x[n-1] = temp;
    }
    
}
int main(){
    int arr[10] = {5,7,9,1,3,10,8,2,4,6};
    cout << "The origin array is :";
    for(int i = 0;i < 10;i++){
        cout << arr[i] << " ";
    }
    inv(arr,10);
    cout << endl;
    cout << "After reversing: ";
    for(int i = 0;i<10;i++){
        cout << arr[i] << " ";
    }
    system("pause");
    return 0;
}
