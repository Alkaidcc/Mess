#include<stdio.h>
#include<string.h>
#include<iostream>
int a[1000][1000],score[1000];
int main(){
    int t,i,j,k,maxindex,max,n,flag=0;    
    scanf("%d",&t);
    for(i=0;i<t;i++){
        memset(score,0,sizeof(score));
        scanf("%d",&n);
        for(j=0;j<n;j++){
            for(k=0;k<n;k++){
                scanf("%d",&a[j][k]);
            }
            
        }
        for(j=0;j<n;j++){
            for(k=j+1;k<n;k++){
                if(a[j][k]>a[k][j])         score[j]+=3;
                else if(a[j][k]<a[k][j])    score[k]+=3;
                else if(a[j][k]=a[k][j]){
                    score[j]++;
                    score[k]++;
                }   
            }
        }
        max=score[0];
        maxindex=0;
        for(j=1;j<n;j++){
            if(score[j]>max){
                max=score[j];
                maxindex=j;
            }
        }
        for(j=0;j<n;j++){
            if(score[j]==max&&j!=maxindex){
                printf("找不出最强球队！\n");
                break;
            }
        }
        if(j==n) printf("%d\n",maxindex+1);
        
    }
    system("pause");
    return 0;
}