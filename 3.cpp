/*
Filename		:3.cpp
Date			:2020/09/18 08:40:16
Author			:ZZC
Description     :复制字符串（不能用库函数） void copy_str(char *p1, char *p2)
*/
#include <iostream>
using namespace std;

void copy_str(char* p1, char* p2);
void copy_str(char* p1, char* p2){
    int i;
    for(i = 0;p1[i]!='\0';i++){
        p2[i] = p1[i];
    }
    p2[i] = '\0';
}
int main(){
    char str1[100],str2[100];
    cout << "Please input a string p1:";
    cin >> str1;
    copy_str(str1,str2);
    cout << "string p2 is: " << str2;
    system("pause");
    return 0;
}
