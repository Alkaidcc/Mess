#include<stdio.h>
#include<iostream>
int a[1050][1050]={0};
int b[1050]={0};
int main(){
    int n,m,k,i,j;
    scanf("%d %d %d",&n,&m,&k);        //һ��n�� ÿ��m����  ��k��
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            int x;
            scanf("%d",&x);         
            if(a[j][x]==0)  b[x]++;     //�ڵ�x�죬�����j��û���ù������Ϊ�ù����ڵ�x���һ�ף�
            a[j][x]=1;                  
        }
    }
    for(i=1;i<=k;i++){
        printf("%d ",b[i]);
    }
    system("pause");
    return 0;
}