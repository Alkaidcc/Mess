//���Ա�
#include<stdio.h>
#define ERROR -1
typedef struct  LNode*List;
struct LNode
{
    ElementType Data [MAXSIZE];
    int Last;                   //��η���Ԫ�� :L.Data[i]��PtrL->Data[i]
};                              //���Ա�ĳ��ȣ�L.Last+1��PtrL->Last+1
struct LNode L;
List Ptrl;
//��ʼ��
List MakeEmpty(){
    List PtrL;
    PtrL=(List)malloc(sizeof(struct LNode));
    PtrL->Last=-1;
    return PtrL;
}


//����
int Find(ElementType X,List PtrL){
    int i=0;
    for(i=0;i<=PtrL->Last;i++){
        if(X==PtrL->Data[i])
            return i;
    }
    return ERROR;
}


//����
void Insert(ElementType X,int i,List PtrL){
    int j;
    if(PtrL->Last==MAXSIZE-1){
        printf("����");
        return;
    }
    if(i<0||i>PtrL->Last+1){
        printf("���Ϸ�");
        return;
    }
    for(j=PtrL->Last+1;j>i;j--)
        PtrL->Data[j]=PtrL->Data[j-1];  //����һ����ֵ��ǰ��ĸ���
    PtrL->Data[i]=X;                  
    PtrL->Last++;                       //����+1
    return;
}


//ɾ��
void Delete(int i,List PtrL){
    int j;
    if(i<0||i>PtrL->Last){
        printf("�����ڵ�%d��Ԫ��",i);
        return;
    }
    for(j=i;j<=PtrL->Last;j++)
        PtrL->Data[j]=PtrL->Data[j+1]; //�ú���İ�ǰ��ĸ���
    PtrL--;
    return;
}