/*
Filename		:1.cpp
Date			:2020/09/24 16:24:08
Author			:ZZC
Description     :打印输出C++常用的数据类型的字节数 sizeof
*/

#include <iostream>

using namespace std;

int main(){
    cout << "sizeof int: " << sizeof(int) << endl;
    cout << "sizeof char: " << sizeof(char) << endl;
    cout << "sizeof bool: " << sizeof(bool) << endl;
    cout << "sizeof string: " << sizeof(string) << endl;    //鍜岀紪璇戝櫒鏈夊叧
    cout << "sizeof short: " << sizeof(short) << endl;
    cout << "sizeof float: " << sizeof(float) << endl;
    cout << "sizeof long: " << sizeof(long) << endl;
    cout << "sizeof long long: " << sizeof(long long) << endl;
    cout << "sizeof double: " << sizeof(double) << endl;
    cout << "sizeof long double: " << sizeof(long double) << endl;
    cout << "sizeof wchar_t: " << sizeof(wchar_t) << endl;
    system("pause");
    return 0;
}
