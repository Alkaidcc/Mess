//栈
#include<stdio.h>
#define MaxSize <最大个数>
typedef struct SNode *Stack;
struct SNode{
    ElementType Data[MaxSize];
    int Top;  //栈顶的下标  默认为0
}


//入栈
void Push(Stack PtrS,ElementType item){
    if(PtrS->Top==MaxSize-1){
        printf("堆栈满");
        return;
    }
    else{
        PtrS->Data[++(PtrS->Top)]=item;
        return;
    }
}


//出栈
ElementType Pop(Stack PtrS){
    if(PtrS->Top==-1){
        printf("堆栈空");
        return ERROR;       //ERROR是ElementType的特殊值，标志错误
    }
    else
    {
        return(PtrS->Data[(PtrS->Top)--]);
    }
    
}


//用一个数组实现两个堆栈
#define MaxSize <最大个数>
struct DStack{
    ElementType Data[MaxSize];
    int Top1;   //  初始值为-1
    int Top2;   //  初始值为MaxSize
}S;


//入栈
void Push(struct DStack *PtrS,ElementType item,int Tag){
    if(PtrS->Top2-PtrS->Top1==1){   //栈满
        printf("堆栈满");
        return;
    }
    if(Tag==1)
        PtrS->Data[++(PtrS->Top1)]=item;    //对第一个栈操作
    else
        PtrS->Data[--(PtrS->Top2)]=item;    //对第二个栈操作
}


//出栈
ElementType Pop(struct DStack *PtrS,int Tag){
    //  Tag 作为区分两个堆栈的标志 1和2
    if(Tag==1){     //对第一个堆栈进行操作
        if(PtrS->Top2==-1){     //堆栈1空
            printf("堆栈1空");
            return NULL;
        }
        else
            return PtrS->Data[(PtrS->Top1)--];
    }
    else
    {
        if(PtrS->Top2==MaxSize){    //堆栈2空
            printf("堆栈2空");
            return NULL;
        }
        else
            return PtrS->Data[(PtrS->Top2)++];
        
    }
    
}