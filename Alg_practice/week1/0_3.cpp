/*
Filename		:1.cpp
Date			:2020/09/22 19:00:57
Author			:ZZC
Description     :
*/
#include <iostream>
#include <queue>
using namespace std;

int main(){
    priority_queue <int> qu;
    qu.push(3);
    qu.push(1);
    qu.push(2);
    qu.push(5);
    printf("��ͷԪ�أ� %d\n",qu.top());
    printf("����˳�� ");
    while(!qu.empty()){
        printf("%d ",qu.top());
        qu.pop();
    }
    printf("\n");
    system("pause");
    return 0;
}
