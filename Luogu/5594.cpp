#include<stdio.h>
#include<iostream>
int a[1050][1050]={0};
int b[1050]={0};
int main(){
    int n,m,k,i,j;
    scanf("%d %d %d",&n,&m,&k);        //一共n行 每行m个数  共k天
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            int x;
            scanf("%d",&x);         
            if(a[j][x]==0)  b[x]++;     //在第x天，如果第j套没有用过，标记为用过并在第x天加一套；
            a[j][x]=1;                  
        }
    }
    for(i=1;i<=k;i++){
        printf("%d ",b[i]);
    }
    system("pause");
    return 0;
}