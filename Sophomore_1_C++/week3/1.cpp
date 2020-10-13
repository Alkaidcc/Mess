/*
Filename		:1.cpp
Date			:2020/10/09 08:37:55
Author			:ZZC
Description     :编写一个函数，解决汉诺塔问题。
*/
#include <iostream>
using namespace std;
void hanoi(char a, char b,char c,int n);
void hanoi(char a, char b,char c,int n){
    if(n == 1)
        cout << a << " -> " << c << endl;
    else{
        hanoi(a, c, b, n - 1);  //把a上层n-1个移动到b
        cout << a << " -> " << c << endl;
        hanoi(b, a, c, n - 1);//把b的n-1个移动到c
    }
}
int main(){
    int n;
    cin >> n;
    hanoi('A','B','C',n);
    system("pause");
    return 0;
}
