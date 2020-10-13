/*
Filename		:1.cpp
Date			:2020/10/09 08:37:55
Author			:ZZC
Description     :��дһ�������������ŵ�����⡣
*/
#include <iostream>
using namespace std;
void hanoi(char a, char b,char c,int n);
void hanoi(char a, char b,char c,int n){
    if(n == 1)
        cout << a << " -> " << c << endl;
    else{
        hanoi(a, c, b, n - 1);  //��a�ϲ�n-1���ƶ���b
        cout << a << " -> " << c << endl;
        hanoi(b, a, c, n - 1);//��b��n-1���ƶ���c
    }
}
int main(){
    int n;
    cin >> n;
    hanoi('A','B','C',n);
    system("pause");
    return 0;
}
