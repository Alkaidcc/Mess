#include<iostream> 
#include <string>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status; //Status 是函数返回值类型，其值是函数结果状态代码。


// struct member {
// 	int num;
// };

// typedef member ElemType;
typedef int ElemType;
#define MAXSIZE 100

typedef struct LNode {
	ElemType  data;  
	struct LNode *next; 
}LNode, *LinkList;



Status InitList_L(LinkList &L)
{
	L=new LNode;
	L->next=NULL;
	return OK;
}

void CreateList_F(LinkList& L,int n)
{
	LNode *p;
	int i;
	L=new LNode;
	 L->next=NULL;
	 for(i=n;i>0;--i)
	 {
		 p=new LNode;
		 cin>>p->data;
		 p->next=L->next;
         L->next=p;
	 }
}

Status GetElem_L(LinkList L,int i,ElemType &e)
{
	LinkList p;
	int j;
	p=L->next;j=1;
	 while(p&&j<i)
	 {
		 p=p->next;++j;
	 }
	 if(!p||j>i)return ERROR;
	 e=p->data;
	 return OK;
}

Status ListInstert_L(LinkList L,int i,ElemType e)
{
	LinkList p;
	p=L;
	int j=1;
	while(p&&j<i){
        p=p->next;
		++j;
    }
	if(!p||j>i)
		return ERROR;
	LinkList s=new LNode;
	s->data=e;
	s->next=p->next;
	p->next=s;
	return OK;
}

Status ListDelete_L(LinkList &L,int i,ElemType& e)
{
	LinkList p=L,q;
    int j=0;
	while(p->next&&j<i-1)
	{
		p=p->next;++j;
	}
	if(!(p->next)||j>i-1)return ERROR;
	q=p->next;
	p->next=q->next;
	e=q->data;
	delete q;
 return OK;
}

void printf_L(LinkList L)
{
	LNode *p;
	p=L->next;
	while(p)
	{
		cout<<p->data<<endl;
		p=p->next;
	}
}
int ListLength(LinkList L)
{
	LNode *current;
    int len=0;
	current = L;
	while (current != NULL){
		len++;
		current = current->next;
	}
	return len;
}
LinkList LocateElem( LinkList L,ElemType e)
{
	LNode *p;
	p=L->next;
	while(p&&p->data!=e)
		p=p->next;
	return p;
}


void uniont(LinkList &La, LinkList Lb){
    int La_len,Lb_len;
    ElemType e;
    La_len=ListLength(La);
    Lb_len=ListLength(Lb); 
    for(int i=1;i<=Lb_len;i++){
        GetElem_L(Lb,i,e);
        if(!LocateElem(La,e)) 
           ListInstert_L(La,++La_len,e);                        
  }
}


int main()
{
    LinkList LA,LB;
	ElemType e;
	CreateList_F(LA,4);
	CreateList_F(LB,3);
    uniont(LA,LB);
	printf_L(LA);
    system("pause");
    return 0;
}
