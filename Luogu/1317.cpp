#include<stdio.h>
#include<iostream>
int main(){
    int n,i,cnt=0;
    int a[1000];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=1;i<n;i++){
        if(a[i-1]>a[i]){
            while(a[i]>=a[i+1]&&i<n-1) //��i=n-1��ôi+1=nԽ����
            i++;
            if(i!=n-1)
                cnt++;
        }
    }
    printf("%d",cnt);
    system("pause");
    return 0;
}