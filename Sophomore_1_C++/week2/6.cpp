/*
Filename		:6.cpp
Date			:2020/09/25 09:29:44
Author			:ZZC
Description     :��дһ�������ж�һ�����Ƿ�Ϊˮ�ɻ���,ˮ�ɻ�����ָһ�� 3 λ��������ÿ��λ�ϵ����ֵ� 3����֮�͵���������
*/
#include <iostream>

using namespace std;

int main(){
    int n, a, b, c, sum(0);
    cin >> n;
    a = n %10;
    b = n / 10 % 10;
    c = n /100;
    sum += a * a * a + b * b * b + c * c *c;
    if(sum == n){
        cout << "������ˮ�ɻ��� " << endl;
    }else {
        cout << "��������ˮ�ɻ��� " << endl;
    }
    system("pause");
    return 0;
}
