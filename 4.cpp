/*
Filename		:4.cpp
Date			:2020/09/18 08:46:11
Author			:ZZC
Description     :判断一个字符串中是否包含另一个字符串 int find_substr(char* s1, char* s2)
*/
#include <iostream>
using namespace std;

int find_substr(char* s1, char* s2);
int find_substr(char* s1, char* s2){
    int i = 0,j = 0;
    for(i = 0;s1[i] != '\0';i++){
        if(s2[j] == '\0'){
            break;
        }
        if(s2[j] != '\0' && s2[j] == s1[i]){
            j++;
        }else {
            j=0;
        }
    }
    if(s2[j] == '\0'){
        return 1;
    }else{
        return 0;
    }
}
int main(){
    char s1[100], s2[100];
    cout << "Please input target: ";
    cin >> s1;
    cout << "Please input pattern: ";
    cin >> s2;
    if(find_substr(s1, s2)){
        cout << "OK! Find substring." << endl;
    }else{
        cout << "Not Find substring." << endl;
    }
    system("pause");
    return 0;
}
