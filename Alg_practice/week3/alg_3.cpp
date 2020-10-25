/*
Filename		:alg_3.cpp
Date			:2020/10/13 20:33:01
Author			:ZZC
Description     :基于partition实现快速排序算法
*/
#include <iostream>
#include <ctime>
#include <algorithm>
#include <climits>
#include <string.h>
using namespace std;
const long N = 10000000;
long array1[N];
long array2[N];
long array3[N];

long partition(long Array[],long p, long r);
void QuickSort(long arr[], long start_index, long end_index);
void output(long arr[], long n);
void Select_Sort(long array[],long start, long end);

void Select_Sort(long array[],long start, long end){
    if(start >= end){
        return;
    }
    long index,min = INT_MAX;
    for(long i = start; i <= end; i++){
        if(min > array[i]){
            min = array[i];
            index = i;
        }
    }
    if(index != start){
        long temp = array[start];
        array[start] = array[index];
        array[index] = temp;
    }
    Select_Sort(array, start + 1, end);
}
long partition(long Array[],long startIndex, long endIndex){
    long pivot = Array[endIndex];   //选取数组末尾的值作为pivot
    long mark = startIndex - 1;      //mark标记最后一个比pivot小的数值的下标
    for(long j = startIndex;j <= endIndex - 1;j++){
        if(Array[j] <= pivot){  //如果出现比pivot小的数字，就让mark+1 然后把A[mark]和A[j]交换
            mark = mark + 1;
            swap(Array[mark],Array[j]);
        }
    }
    swap(Array[mark + 1], Array[endIndex]);//把pivot换到比pivot小的那些数的后面
    return mark + 1;//mark后面一个数就是pivot的位置
}
void QuickSort(long arr[], long start_index, long end_index){
    if(start_index >= end_index){
        return;
    }
    long pivot = partition(arr,start_index,end_index);
    QuickSort(arr, start_index, pivot - 1);
    QuickSort(arr, pivot + 1, end_index);
}
void output(long arr[], long n){
    for(long i = 1;i <= n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    cout << "please input the size of array: ";
    long size;
    while(cin >> size){
        array1[0] = array2[0] = array3[0] = 0;
        srand((unsigned long)time(NULL));
        for(long i = 1; i <= size; i++){
            array1[i] = rand() % (size + 1);
            array2[i] = array1[i];
            array3[i] = array1[i];
        }

        size_t start1, end1;
        start1 = clock();
        QuickSort(array1, 1, size);
        end1 = clock();
        cout << "The QuickSort Time is: " << double(end1 - start1) / CLOCKS_PER_SEC << endl;
        // output(array1,size);

        size_t start2, end2;
        start2 = clock();
        sort(array2 + 1, array2 + size + 1);
        end2 = clock();
        cout << "The sort(STL) Time is: " << double(end2 - start2) / CLOCKS_PER_SEC << endl;
        // output(array2,size);    

        if(size > 43000){
            cout << "Select_Sort can't work!" << endl;
        }
        else{
            size_t start3, end3;
            start3 = clock();
            Select_Sort(array3, 1, size);
            end3 = clock();
            cout << "The Select_Sort Time is: " << double(end3 - start3) / CLOCKS_PER_SEC << endl;
            // output(array3,size);
            memset(array3,0,sizeof(array3));
        }
        memset(array1,0,sizeof(array1));
        memset(array2,0,sizeof(array2));
        cout << "please input the size of array: ";      
    }
    system("pause");
    return 0;
}