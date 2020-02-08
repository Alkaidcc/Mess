#include<stdio.h>
#include<iostream>
int main(){
    int n,i,j,temp;             //√∞≈›≈≈–Ú
    int a[1000];
    int cnt=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){   //◊¢“‚j<n-i-1;   œÚœ¬√∞≈›
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                cnt++;
            }
             
        }
    }
    printf("%d",cnt);
    system("pause");
    return 0;
}