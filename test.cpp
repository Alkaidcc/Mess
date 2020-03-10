
#include<iostream>
using namespace std;
#include<string.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
struct list
{
	int no;
	char name[20];
	float score;
};
typedef list ElemType;
typedef int Status;
typedef struct LNode
{
	ElemType  data;
	struct  LNode* next;
}LNode, * LinkList;
Status InitList(LinkList& L)
{
	L = new LNode;
	L->next = NULL;
	return OK;
}
void CreatList(LinkList& L,int i)
{
	int j;
	LNode* p;
	LinkList r;
	L = new LNode;
	L->next = NULL;
	r = L;
     for(j=0;j<i;j++)
	{
		p = new LNode;
		cin >> p->data.no>>p->data.name>>p->data.score;
		p->next = NULL;
		r->next = p;
		r = p;
	}
}
Status GetElem(LinkList L, int i, ElemType& e)
{
	LinkList p;
	int j;
	p = L->next;
	j = 1;
	while (p && j < i)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i) return ERROR;
	e = p->data;
	return OK;
}
LNode* LocateElem(LinkList L, ElemType e)
{
	LinkList p;
	p = L->next;
	while (p&&p->data.no!= e.no&&p->data.name!=e.name&&p->data.score!=e.score)
		p = p->next;
	return p;
}
Status ListInsert(LinkList& L, int i, ElemType e)
{
	LinkList p, s;
	int j;
	p = L;
	j = 0;
	while (p && (j < i - 1))
	{
		p = p->next;
		++j;
	}
	if (!p || j > i - 1)
		return ERROR;
	s = new LNode;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}
Status ListDelete(LinkList& L, int i, ElemType& e)
{
	LinkList p, q;
	p = L;
	int j = 0;
	while (p->next && j < i - 1)
	{
		p = p->next;
		++j;
	}
	if (!(p->next) || j > i - 1)
		return ERROR;
	q = p->next;
	p->next = q->next;
	e = q->data;
	delete q;
	return OK;
}
Status ListLength(LinkList L)
{
	LinkList p;
	p = L;
	int j = 0;
	while (p->next != NULL)
	{
		j++;
		p = p->next;
	}
	return j;
}
void Union(LinkList& LA, LinkList LB)
{
	int m, n, i;
	ElemType e;
	m = ListLength(LA);
	n = ListLength(LB);
	for (i = 1;i <= n;i++)
	{
		GetElem(LB, i, e);
		if (!LocateElem(LA, e))
			ListInsert(LA, ++m, e);
	}
}
void printf(LinkList LA)
{
	LNode* p;
	p = LA->next;
	while (p)
	{
		cout <<'('<< p->data.no << ','<<p->data.name<<','<<p->data.score<<')'<<endl;
		p = p->next;
    }

}

int main()
{
	LinkList LA, LB;
	CreatList(LA,4);
	CreatList(LB,3);
	Union(LA, LB);
	char p[20]="result:";
	cout << p << endl;
	printf(LA);
	system("pause");
	return 0;
}
