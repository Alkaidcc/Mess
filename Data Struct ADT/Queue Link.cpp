#include<cstdio>
struct Node{
    ElementType Data;
    struct Node *Next;
};
struct QNode{   //链队列结构
    struct Node *rear;  //指向队尾的结点
    struct Node *front; //指向队头的结点
};
typedef struct QNode *Queue;
Queue PtrQ;


//不带头结点的链式队列出列
ElementType DeleteQ(Queue PtrQ){

    struct Node *FrontCell;
    ElmentType FrontElem;
    if(PtrQ->front==NULL){
        printf("队列空");
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