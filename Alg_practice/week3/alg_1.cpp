/*
Filename		:alg_1.cpp
Date			:2020/10/13 19:02:41
Author			:ZZC
Description     :采用递归方式实现按升序排序的选择排序算法
*/
#include <iostream>
#include <climits>
#include <algorithm>
#include <string.h>
using namespace std;

void Select_Sort(int array[],int start, int end);
void Select_Sort(int array[],int start, int end){
    if(start >= end){
        return;
    }
    int index,min = INT_MAX;
    for(int i = start; i <= end; i++){
        if(min > array[i]){
            min = array[i];
            index = i;
        }
    }
    if(index != start){
        int temp = array[start];
        array[start] = array[index];
        array[index] = temp;
    }
    Select_Sort(array, start + 1, end);
}

int main(){
    int array1[1001],array2[1001];
    int size;
    cout << "Enter the size of array: ";
    while(cin >> size){
        for(int i = 0;i < size; i++){
            cin >> array1[i];
            array2[i] = array1[i];
        }

        //my_Select_Sort
        cout << "mySort the array: " << endl;
        Select_Sort(array1, 0, size - 1);
        for(int i = 0;i < size;i++){
            cout << array1[i] << " ";
        }
        cout << endl;

        //STL - sort
        cout << "Sort the array: " << endl;
        sort(array2, array2 + size);
        for(int i = 0;i < size;i++){
            cout << array2[i] << " ";
        }
        cout << endl;
        
        memset(array1, 0, sizeof(array1));        
        memset(array2, 0, sizeof(array2));
        cout << "Enter the size of array: ";
    }
    system("pause");
    return 0;
}
