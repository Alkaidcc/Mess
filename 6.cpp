/*
Filename		:6.cpp
Date			:2020/09/18 09:32:49
Author			:ZZC
Description     :将一个整型数组中的所有整数按从小到大的顺序进行排序（排序算法不限）
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int arr[10] = {6,9,2,3,1,8,4,7,5,10};
    sort(arr,arr+10);
    for(int i = 0;i < 10;i++){
        cout << arr[i] << " ";
    }
    system("pause");
    return 0;
}
