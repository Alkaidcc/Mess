#include<cstdio>
#include<stdlib.h>
#define ERROR -1
#define MaxSize 101
struct Node{
    ElementType Data;
    int Parent;
    int rank;
}S[MaxSize];

void Initialize(int size) {
    for(int i=0;i<size;i++){
        S[i].rank=0;
        S[i].Data=i;
    }
}

int Find(ElementType X)
{   //在数组S中查找值为X的元素所属的集合
    if(S[X].Parent==X)
        return X;
    return Find(S[X].Parent);
}

void Union(ElementType X1,ElementType X2){
    
    int Root1=Find(X1);
    int Root2=Find(X2);
    if(Root2==Root1)
        return;
    if(S[Root1].rank<S[Root2].rank) 
        S[Root1].Parent=Root2;
    else{
        S[Root2].Parent=Root1;
        if(S[Root1].rank==S[Root2].rank)
            S[Root1].rank++;
    }
}

bool SameSet(int x,int y){
    return Find(x)==Find(y);
}