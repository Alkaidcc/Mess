#include<cstdio>
#include<stdlib.h>
#include<iostream>
#define MAXN 1001
#define MINH -10001

int H[MAXN],size;
void Creat(){
    size=0;
    H[0]=MINH;  //设置哨兵 不用判别是否越界
}

void Insert(int X){
    int i;
    for(i=++size;H[i/2]>X;i/=2)
        H[i]=H[i/2];
    H[i]=X;
}

int main(){
    int N,M,Data,i,Position;
    scanf("%d %d",&N,&M);
    Creat();
    for(i=0;i<N;i++){
        scanf("%d",&Data);
        Insert(Data);
    }
    for(i=0;i<M;i++){
        scanf("%d",&Position);
        printf("%d",H[Position]);
        while(Position>1){
            Position/=2;
            printf(" %d",H[Position]);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}