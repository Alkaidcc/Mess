#include<cstdio>
struct Node{
    ElementType Data;
    struct Node *Next;
};
struct QNode{   //�����нṹ
    struct Node *rear;  //ָ���β�Ľ��
    struct Node *front; //ָ���ͷ�Ľ��
};
typedef struct QNode *Queue;
Queue PtrQ;


//����ͷ������ʽ���г���
ElementType DeleteQ(Queue PtrQ){

    struct Node *FrontCell;
    ElmentType FrontElem;
    if(PtrQ->front==NULL){
        printf("���п�");
        return ERROR;
    }
    FrontCell=PtrQ->front;
    if(PtrQ->front==PtrQ->rear)
        PtrQ->front=PtrQ->rear=NULL;
    else
    {
        PtrQ->front=PtrQ->front->Next;
    }
    FrontElem=FrontCell->Data;
    free(FrontCell);
    return FrontElem;
}