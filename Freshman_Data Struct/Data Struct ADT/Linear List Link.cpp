#include<stdio.h>
#include<stdio.h>
#define ERROR -1
typedef struct  LNode*List;
struct LNode
{
    int Data;
    List Next;                   //��η���Ԫ�� :L.Data[i]��PtrL->Data[i]
};                              //���Ա�ĳ��ȣ�L.Last+1��PtrL->Last+1
struct LNode L;
List Ptrl;

//��ʼ��
List creatNode(int value)
{
    List temp=malloc(sizeof(LNode));
    temp->Data=value;
    temp->Next=NULL;
}

//���

int Length(List PtrL){
    List p=PtrL;    //pָ���ĵ�һ�����
    int cnt=0;
    while (p){
        p=p->Next;
        cnt++;        //��ǰpָ����ǵ�j�����
    }
    return cnt;
}


//����Ų���
List FindKth(int K,List PtrL){
    if(!PtrL||K<0)
        return ERROR;
    while (--K){
        if(PtrL->Next==NULL)
            return ERROR;
        else
            PtrL=PtrL->Next;
    }
    return PtrL->Data;
    
    
}


//��ֵ����
List Find(ElementType X,List PtrL){
    List p=PtrL;
    while (p!=NULL&&p->Data!=X)
    {
        p=p->Next;
    }
    return p;
}



//����
List Insert(ElementType X,int i,List PtrL){
    List p,s;
    if(i==1){                                  //�½����ڱ�ͷ
        s=(List)malloc(sizeof(struct LNode));  //����һ���ռ�
        s->Data=X;
        s->Next=PtrL;
        return s;
    }
    p=FindKth(i-1,PtrL);
    if(p==NULL){
        printf("����i��");
        return NULL;
    }
    else
    {
        s=(List)malloc(sizeof(struct LNode));
        s->Data=X;
        s->Next=p->Next;
        p->Next=s;
        return PtrL;
    }
    
}


//ɾ��
List Delete(int i,List PtrL){
    List p,s;
    if(i==1){
        s=PtrL;
        if(PtrL!=NULL)
            PtrL=PtrL->Next:
        else                //ͷ��㱾��Ϊ�� ɾ�����ɹ�
            return NULL��
        free(s);
        return PtrL;
    }
    p=FindKth(i-1,PtrL);
    if(p==NULL){
        printf("��%d����㲻����",i-1);
        return NULL;
    }
    else if(p->Next==NULL){
        printf("��%d����㲻����",i);
        return NULL;
    }
    else
    {
        s=p->Next;
        p->Next=s->Next;
        free(s);
        return PtrL;
    }
    
}