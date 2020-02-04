#include<stdio.h>
#include<stdio.h>
#define ERROR -1
typedef struct  LNode*List;
struct LNode
{
    int Data;
    List Next;                   //如何访问元素 :L.Data[i]或PtrL->Data[i]
};                              //线性表的长度：L.Last+1或PtrL->Last+1
struct LNode L;
List Ptrl;

//初始化
List creatNode(int value)
{
    List temp=malloc(sizeof(LNode));
    temp->Data=value;
    temp->Next=NULL;
}

//求表长

int Length(List PtrL){
    List p=PtrL;    //p指向表的第一个结点
    int cnt=0;
    while (p){
        p=p->Next;
        cnt++;        //点前p指向的是第j个结点
    }
    return cnt;
}


//按序号查找
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


//按值查找
List Find(ElementType X,List PtrL){
    List p=PtrL;
    while (p!=NULL&&p->Data!=X)
    {
        p=p->Next;
    }
    return p;
}



//插入
List Insert(ElementType X,int i,List PtrL){
    List p,s;
    if(i==1){                                  //新结点插在表头
        s=(List)malloc(sizeof(struct LNode));  //创建一个空间
        s->Data=X;
        s->Next=PtrL;
        return s;
    }
    p=FindKth(i-1,PtrL);
    if(p==NULL){
        printf("参数i错");
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


//删除
List Delete(int i,List PtrL){
    List p,s;
    if(i==1){
        s=PtrL;
        if(PtrL!=NULL)
            PtrL=PtrL->Next:
        else                //头结点本身为空 删除不成功
            return NULL；
        free(s);
        return PtrL;
    }
    p=FindKth(i-1,PtrL);
    if(p==NULL){
        printf("第%d个结点不存在",i-1);
        return NULL;
    }
    else if(p->Next==NULL){
        printf("第%d个结点不存在",i);
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