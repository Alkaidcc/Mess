/*
Filename		:1.cpp
Date			:2020/09/22 19:00:57
Author			:ZZC
Description     :
*/
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector <int> myv;
    vector <int>::iterator it;
    myv.push_back(1);
    it = myv.begin();
    myv.insert(it,2);
    myv.push_back(3);
    myv.push_back(4);
    it = myv.end();
    it--;
    myv.erase(it);
    for(it = myv.begin();it != myv.end();++it){
        printf("%d ", *it);
    }
    printf("\n");
    system("pause");
    return 0;
}
