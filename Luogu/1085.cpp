#include<stdio.h>
#include<iostream>
int main(){
    int i,a,b,max=0;
    int s[10];
    for(i=1;i<=7;i++){
        scanf("%d %d",&a,&b);
        s[i]=a+b-8;
    }
    max=1;
    for(i=2;i<=7;i++){
        if(s[i]>s[max])
            max=i;
    }
    printf("%d",max);
    system("pause");
    return 0;
}