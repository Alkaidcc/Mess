#include<stdio.h>
#include<iostream>
int main(){
    long long a,b,n,d,sum=0;
    scanf("%lld %lld %lld",&a,&b,&n);
    d=b-a;
    sum=a*n+((n-1)*n*d)/2;
    printf("%lld",sum);
    system("pause");
    return 0;

}