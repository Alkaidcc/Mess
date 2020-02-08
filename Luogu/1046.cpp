#include<stdio.h>
#include<iostream>
int main(){
    int i,h,cnt=0;
    int a[100];
    for(i=0;i<10;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&h);
    for(i=0;i<10;i++){
        if((h+30)>=a[i])    cnt++;
    }
    printf("%d",cnt);
    system("pause");
    return 0;
}