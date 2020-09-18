#include<cstdio>
#include<stdlib.h>
#include<iostream>
struct TreeNode{
    int Value;
    TreeNode* Left;
    TreeNode* Right;
    int Flag;
};
typedef TreeNode* Tree;
Tree MakeTree(int N);
Tree NewNode(int V);
Tree Insert(Tree T, int V);                 
int Check(Tree T,int V);
int Judge(Tree T,int N);
void ResetT(Tree T);
void FreeTree(Tree T);

int main(){                             
    int N,L,i;  //N为结点数                                                                                                                                                                                            
    Tree T;
    scanf("%d",&N);
    while (N){
        scanf("%d",&L);
        T=MakeTree(N);//建树
        for(i=0;i<L;i++){
            if(Judge(T,N))  //将数据与树比较
                printf("Yes\n");
            else
                printf("No\n");
            ResetT(T);//清除T中的Flag标记
        }
        FreeTree(T);
        scanf("%d",&N);
    }
    system("pause");
    return 0;
}

Tree Insert(Tree T,int V){
    if(!T)
        T=NewNode(V);
    else{
        if(V>T->Value)
            T->Right=Insert(T->Right,V);
        else if(V<T->Value)
            T->Left=Insert(T->Left,V);
    }
    return T;
}

Tree MakeTree(int N){
    Tree T;
    int i,V;
    scanf("%d",&V);
    T=NewNode(V);
    for(i=1;i<N;i++){
        scanf("%d",&V);
        T=Insert(T,V);
    }
    return T;
}

Tree NewNode(int V){
    Tree T=(Tree)malloc(sizeof(struct TreeNode));
    T->Value=V;
    T->Left=T->Right=NULL;
    T->Flag=0;
    return T;
}

int Check(Tree T,int V){
    if(T->Flag){
        if(V<T->Value)
            return Check(T->Left,V);
        else if(V>T->Value)
            return Check(T->Right,V);
        else
            return 0;
    }
    else{
        if(V==T->Value){
            T->Flag=1;
            return 1;
        }
        else
            return 0;
    }
}

int Judge(Tree T,int N){
    int i,V,flag=0;     //flag:0表示目前一致 1表示目前已经不一致
    scanf("%d",&V);
    if(V!=T->Value)
        flag=1;
    else
        T->Flag=1;
    for ( i = 1; i < N; i++)
    {
        scanf("%d",&V);
        if((!flag)&&(!Check(T,V)))
            flag=1;
    }
    if(flag)
        return 0;
    else
        return 1;     
}

void ResetT(Tree T){    //清除T中各结点Flag标记
    if(T->Left)
        ResetT(T->Left);
    if(T->Right)
        ResetT(T->Right);
    T->Flag=0;
}

void FreeTree(Tree T){
    if(T->Left)
        FreeTree(T->Left);
    if(T->Right)
        FreeTree(T->Right);
    free(T);
}