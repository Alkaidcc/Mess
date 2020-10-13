/*
Filename		:0_2.cpp
Date			:2020/09/22 19:10:45
Author			:ZZC
Description     :
*/
#include <iostream>
#include <map>
using namespace std;

int main(){
    map <char,int> mymap;
    mymap.insert(pair<char,int>('a',1));
    mymap.insert(map<char,int>::value_type('b',2));
    mymap['c'] = 3;
    map<char,int>::iterator it;
    for(it = mymap.begin();it != mymap.end();it++){
        printf("[%c,%d] ",it->first, it->second);
    }
    printf("\n");
    system("pause");
    return 0;
}
