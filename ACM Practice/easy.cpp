#include<stdio.h>
#include<string.h>
#include<iostream>
int main(){
    int t,i,j;
    int a[100000];
    scanf("%d",&t);
    for(i=0;i<t;i++){
        memset(a,0,100000);
        int x;
        scanf("%d",&x);
        for(j=0;j<x;j++){
            scanf("%d",&a[j]);
        }
        for(j=0;j<x;j++){
            if(a[j]==1){
                printf("hard\n");
                break;
            }
        }
        if(j==x)    printf("easy\n");
        
    }
    system("pause");
    return 0;
}