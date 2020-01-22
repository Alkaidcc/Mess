#include<stdio.h>
typedef struct SNode *Stack;
struct SNode{}
{
    ElementType Data;
    struct SNode *Next;
};


//构建头结点
Stack CreateStack(){
    Stack S;
    S=(Stack)malloc(sizeof(struct SNode));
    S->Next=NULL;
    return S;
}


//判断是否为空
int IsEmpty(Stack S){
    return (S->Next==NULL);
}


//入栈
void Push(ElementType item,Stack S){
    //不用考虑是否满栈
    struct SNode *TmpCell;
    TmpCell=(struct SNode*)malloc(sizeof(struct SNode));
    TmpCell->Data=item;
    TmpCell->Next=S->Next;
    S->Next=TmpCell;
}


//出栈
ElementType Pop(Stack S){
    struct SNode *FirstCell;
    ElementType TopElem;
    if(IsEmpty(S)){
        printf("堆栈空");
        return NULL;
    }
    else
    {
        FirstCell=S->Next;
        S->Next=FirstCell->Next;
        TopElem=FirstCell->Data;
        free(FirstCell);
        return TopElem;
    }
    

}