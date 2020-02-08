#include<stdio.h>
#include<iostream>      //’‚Ã‚”√Õ∞≈≈–Ú.
int main(){
    int flag[10000]={0};
    int n,x,i,sum=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&x);
        if(flag[x]==1)
            continue;
        flag[x]++;
        sum++;
    }
    
    printf("%d\n",sum);
    for(i=0;i<10000;i++){
        if(flag[i])
            printf("%d ",i);
    }
    system("pause");
    return 0;
}