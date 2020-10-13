/*
Filename		:2.cpp
Date			:2020/09/24 16:33:51
Author			:ZZC
Description     :打印输出ASCII码为32-127的字符
*/
#include <iostream>

using namespace std;

int main(){
    for(int i = 32;i < 128;i++){
        cout << char(i) << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}
