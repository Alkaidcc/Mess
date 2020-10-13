/*
Filename		:4.cpp
Date			:2020/09/24 16:44:28
Author			:ZZC
Description     :找出1-1000间的所有整数，数本身及反序后的数都能被3整除，并显示。分别使用while do-while for 实现
*/
#include <iostream>

using namespace std;

void fun1(){
    int i = 3;
    while(i <= 999){
        cout << i << " ";
        i+=3;
    }
    cout << endl;
}

void fun2(){
    int i = 3;
    do{
        cout << i << " ";
        i+=3;
    }while(i <= 999);
    cout << endl;
}

void fun3(){
    int i = 3;
    for(i = 3;i <= 999;i=i+3){
        cout << i << " ";
    }
    cout << endl;
}

int main(){
    cout << "while: " << endl;
    fun1();
    cout  << "do-while: " << endl;
    fun2();
    cout << "for: " << endl;
    fun3();
    system("pause");
    return 0;
}
