#include<stdio.h>
int A[100000],N;
int MaxSubseqSum(int A[],int N){
    int i,ThisSum,MaxSum;
    ThisSum=MaxSum=0;
    for(i=0;i<N;i++){
        ThisSum+=A[i];
        if(ThisSum>MaxSum)
            MaxSum=ThisSum;
        else if(ThisSum<0)
            ThisSum=0;
    }
    return MaxSum;
}
int main(){
    int sum=0;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&A[i]);
    }
    sum=MaxSubseqSum(A,N);
    printf("%d",sum);
    return 0;
}