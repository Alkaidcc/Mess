#include<stdio.h>
#define MaxSize <最大个数>
struct QNode{
    ElementType Data[MaxSize];
    int rear;   //  初始值为-1
    int front;  //初始值为-1
};
typedef struct QNode *Queue;

//循环队列


//入列(从后面入)
void AddQ(Queue PtrQ,ElementType item){

    if((PtrQ->rear+1)%MaxSize==PtrQ->front){
        printf("队列满");
        return;
    }
    else{
        PtrQ->rear=(PtrQ->rear+1)%MaxSize;
        PtrQ->Data[PtrQ->rear]=item;
        return;
    }
}


//出列(从前面出)
ElementType DeleteQ(Queue PtrQ){
    
    if(PtrQ->front==PtrQ->rear){
        printf("队列空");
        return ERROR;   //返回错误标志
    }
    else
    {
        PtrQ->front=(PtrQ->front+1)%MaxSize;
        return PtrQ->Data[PtrQ->front];
    }
    
}