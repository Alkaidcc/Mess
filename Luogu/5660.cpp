#include<stdio.h>
#include<iostream>
int main(){
    char ch;
    int cnt=0;
    for(int i=0;i<8;i++){
        scanf("%c",&ch);
        if(ch=='1')
        cnt++;
    }
    printf("%d",cnt);
    system("pause");
    return 0;
}