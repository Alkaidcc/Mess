/*
Filename		:7.cpp
Date			:2020/09/25 09:30:12
Author			:ZZC
Description     :¼ÆËã×Ö·û´®³¤¶È int mystrlen(char *p)
*/
#include <iostream>

using namespace std;

int mystrlen(char *p){
    int i = 0;
    while(p[i] != '\0')
        i++;
    return i
}

int main(){
    char s[] = "";
    cin >> s;
    cout << mystrlen(s) << endl;
    system("pause");
    return 0;
}
