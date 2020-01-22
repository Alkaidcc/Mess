//线性表
#include<stdio.h>
#define ERROR -1
typedef struct  LNode*List;
struct LNode
{
    ElementType Data [MAXSIZE];
    int Last;                   //如何访问元素 :L.Data[i]或PtrL->Data[i]
};                              //线性表的长度：L.Last+1或PtrL->Last+1
struct LNode L;
List Ptrl;
//初始化
List MakeEmpty(){
    List PtrL;
    PtrL=(List)malloc(sizeof(struct LNode));
    PtrL->Last=-1;
    return PtrL;
}


//查找
int Find(ElementType X,List PtrL){
    int i=0;
    for(i=0;i<=PtrL->Last;i++){
        if(X==PtrL->Data[i])
            return i;
    }
    return ERROR;
}


//插入
void Insert(ElementType X,int i,List PtrL){
    int j;
    if(PtrL->Last==MAXSIZE-1){
        printf("表满");
        return;
    }
    if(i<0||i>PtrL->Last+1){
        printf("不合法");
        return;
    }
    for(j=PtrL->Last+1;j>i;j--)
        PtrL->Data[j]=PtrL->Data[j-1];  //后面一个的值用前面的覆盖
    PtrL->Data[i]=X;                  
    PtrL->Last++;                       //长度+1
    return;
}


//删除
void Delete(int i,List PtrL){
    int j;
    if(i<0||i>PtrL->Last){
        printf("不存在第%d个元素",i);
        return;
    }
    for(j=i;j<=PtrL->Last;j++)
        PtrL->Data[j]=PtrL->Data[j+1]; //用后面的把前面的覆盖
    PtrL--;
    return;
}