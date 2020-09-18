/*
Filename		:2.cpp
Date			:2020/09/18 08:28:12
Author			:ZZC
Description     :交换两个整数 void swap(int *x, int *y)
*/
#include <iostream>
using namespace std;

void my_swap(int* x, int* y);
void my_swap(int* x, int* y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main(){
    int a, b;
    cout << "Please input two numbers: ";
    cin >> a >> b;
    my_swap(&a,&b);
    cout << "The number after swapping :" << a << " " << b << endl;
    system("pause");
    return 0;
}
