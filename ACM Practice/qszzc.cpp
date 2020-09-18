#include<stdio.h>
#include<iostream>
int main(){
    int N,i,j;
    scanf("%d",&N);
    for(i=1;i<=N;i++){
        if(i%2!=0){
            for(j=1;j<=N;j++){
                if(j%2==0)  printf("R");
                else        printf("B");
            }
            printf("\n");
        }
        else{
            for(j=1;j<=N;j++){
                if(j%2==0)  printf("B");
                else        printf("R");
            }
            printf("\n");
        }
    }
    system("pause");
    return 0;
}