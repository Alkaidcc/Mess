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
            while(a[i]>=a[i+1]&&i<n-1) //若i=n-1那么i+1=n越界了
            i++;
            if(i!=n-1)
                cnt++;
        }
    }
    printf("%d",cnt);
    system("pause");
    return 0;
}