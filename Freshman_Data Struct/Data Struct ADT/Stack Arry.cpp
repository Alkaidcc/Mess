//ջ
#include<stdio.h>
#define MaxSize <������>
typedef struct SNode *Stack;
struct SNode{
    ElementType Data[MaxSize];
    int Top;  //ջ�����±�  Ĭ��Ϊ0
}


//��ջ
void Push(Stack PtrS,ElementType item){
    if(PtrS->Top==MaxSize-1){
        printf("��ջ��");
        return;
    }
    else{
        PtrS->Data[++(PtrS->Top)]=item;
        return;
    }
}


//��ջ
ElementType Pop(Stack PtrS){
    if(PtrS->Top==-1){
        printf("��ջ��");
        return ERROR;       //ERROR��ElementType������ֵ����־����
    }
    else
    {
        return(PtrS->Data[(PtrS->Top)--]);
    }
    
}


//��һ������ʵ��������ջ
#define MaxSize <������>
struct DStack{
    ElementType Data[MaxSize];
    int Top1;   //  ��ʼֵΪ-1
    int Top2;   //  ��ʼֵΪMaxSize
}S;


//��ջ
void Push(struct DStack *PtrS,ElementType item,int Tag){
    if(PtrS->Top2-PtrS->Top1==1){   //ջ��
        printf("��ջ��");
        return;
    }
    if(Tag==1)
        PtrS->Data[++(PtrS->Top1)]=item;    //�Ե�һ��ջ����
    else
        PtrS->Data[--(PtrS->Top2)]=item;    //�Եڶ���ջ����
}


//��ջ
ElementType Pop(struct DStack *PtrS,int Tag){
    //  Tag ��Ϊ����������ջ�ı�־ 1��2
    if(Tag==1){     //�Ե�һ����ջ���в���
        if(PtrS->Top2==-1){     //��ջ1��
            printf("��ջ1��");
            return NULL;
        }
        else
            return PtrS->Data[(PtrS->Top1)--];
    }
    else
    {
        if(PtrS->Top2==MaxSize){    //��ջ2��
            printf("��ջ2��");
            return NULL;
        }
        else
            return PtrS->Data[(PtrS->Top2)++];
        
    }
    
}