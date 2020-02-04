#include<cstdio>
#include<stdlib.h>
#define ERROR -1
#define MaxSize 101
typedef struct{
    ElementType Data;
    int Parent;
}SetType;

void Initialize(int size) {
    for(int i=0;i<size;i++){
        S[i].rank=0;
        S[i].Data=i;
    }
}

int Find(SetType S,ElementType X){   
    //默认集合元素全部初始化为-1
    if(S[X]<0)
        return x;
    else
        return S[X]=Find(S,S[X]);
}

void Union(SetType S,ElementType X1,ElementType X2){
    
    int Root1=Find(X1);
    int Root2=Find(X2);
    if(S[Root2]<S[Root1]){
        S[Root2]+=S[Root1];
        S[Root1]=Root2; 
    }
    else{
        S[Root1]+=S[Root2];
        S[Root2]=Root1;
    }
}