/*
Filename		:numOfString.cpp
Date			:2020/10/01 16:47:40
Author			:ZZC
Description     :用递归算法求字符串长度
*/

#include <iostream>

using namespace std;

int count_string(char* s);
int count_string(char* s){
    if(*s == '\0')
        return 0;
    return count_string(s+1) + 1;
}

int main(){
    char str[] = "Hello World";
    int num = count_string(str);
    cout << "The string length is: " << num << endl;
    system("pause");
    return 0;
}
