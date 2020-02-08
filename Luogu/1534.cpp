#include<stdio.h>
#include<iostream>
int main(){
    int n,a,b;
    int yu=0,ans=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d",&a,&b);
            yu=yu+a+b-8;
            ans+=yu;
    }
    printf("%d",ans);
    system("pause");
    return 0;
}