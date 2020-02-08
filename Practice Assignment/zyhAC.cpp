#include<iostream>
#include<stdio.h>
#include<string.h>
char x[10002];
int main(){
    int t,n;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        int sum1=0,sum2=0,sum3=0;
        scanf("%d",&n);
        getchar();
        scanf("%s",x);
        for(int j=0;j<n;j++){
            if(x[j]=='z')sum1++;
            if(x[j]=='y')sum2+=sum1;
            if(x[j]=='h')sum3+=sum2;
        }       
        printf("%d\n",sum3);
    }
    system("pause");
}
