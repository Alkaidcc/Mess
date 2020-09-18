#include<stdio.h>
typedef struct SNode *Stack;
struct SNode{}
{
    ElementType Data;
    struct SNode *Next;
};


//����ͷ���
Stack CreateStack(){
    Stack S;
    S=(Stack)malloc(sizeof(struct SNode));
    S->Next=NULL;
    return S;
}


//�ж��Ƿ�Ϊ��
int IsEmpty(Stack S){
    return (S->Next==NULL);
}


//��ջ
void Push(ElementType item,Stack S){
    //���ÿ����Ƿ���ջ
    struct SNode *TmpCell;
    TmpCell=(struct SNode*)malloc(sizeof(struct SNode));
    TmpCell->Data=item;
    TmpCell->Next=S->Next;
    S->Next=TmpCell;
}


//��ջ
ElementType Pop(Stack S){
    struct SNode *FirstCell;
    ElementType TopElem;
    if(IsEmpty(S)){
        printf("��ջ��");
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