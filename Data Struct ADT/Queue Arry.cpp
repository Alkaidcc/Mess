#include<stdio.h>
#define MaxSize <������>
struct QNode{
    ElementType Data[MaxSize];
    int rear;   //  ��ʼֵΪ-1
    int front;  //��ʼֵΪ-1
};
typedef struct QNode *Queue;

//ѭ������


//����(�Ӻ�����)
void AddQ(Queue PtrQ,ElementType item){

    if((PtrQ->rear+1)%MaxSize==PtrQ->front){
        printf("������");
        return;
    }
    else{
        PtrQ->rear=(PtrQ->rear+1)%MaxSize;
        PtrQ->Data[PtrQ->rear]=item;
        return;
    }
}


//����(��ǰ���)
ElementType DeleteQ(Queue PtrQ){
    
    if(PtrQ->front==PtrQ->rear){
        printf("���п�");
        return ERROR;   //���ش����־
    }
    else
    {
        PtrQ->front=(PtrQ->front+1)%MaxSize;
        return PtrQ->Data[PtrQ->front];
    }
    
}