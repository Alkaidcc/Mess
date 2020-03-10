/* 定义结点类型 */
typedef struct DuLNode
{ ElemType data;                //数据域
  DuLNode *prior;               //直接前驱指针
  DuLNode *next;               //直接后继指针
}DuLNode,*DuLinkList;

//函数声明
void InitList(DuLinkList *L);//产生双向循环链表
void ClearList(DuLinkList L);//清空双向循环链表
void DestroyList(DuLinkList &L);//销毁双向循环链表
int TestListEmpty(DuLinkList L);//判断双向循环链表是否为空
int GetListLength(DuLinkList L);//获取双向循环链表的长度
int GetElem(DuLinkList L,int i,ElemType *e);//获取双向循环链表中第i个元素的值
//返回L中第1个与e满足关系compare()的数据元素的位序
int LocateElem(DuLinkList L,ElemType e,int(*compare)(ElemType,ElemType));
int GetPriorElem(DuLinkList L,ElemType cur_e,ElemType *pre_e);//前驱判断与获取
int GetNextElem(DuLinkList L,ElemType cur_e,ElemType *next_e);//后继判断与获取
DuLinkList GetElemP(DuLinkList L,int i);//返回第i个元素的地址
int ListInsert(DuLinkList L,int i,ElemType e);//插入：在第i个位置之前插入元素e
int ListDelete(DuLinkList L,ElemType *e);//删除：删除表中第i个元素
void ListTraverse(DuLinkList L,void(*visit)(ElemType));//正序遍历双向循环链表
void ListTraverseBack(DuLinkList L,void(*visit)(ElemType));//逆序遍历双向循环链表

/* 产生双向循环链表L */
void InitList(DuLinkList *L)
{   
    *L=(DuLinkList)malloc(sizeof(DuLNode));
    if(NULL != (*L))
        (*L)->next = (*L)->prior = (*L);      //双向链表的头结点
    else
        exit(0);
}
/* 清空双向循环链表L */
void ClearList(DuLinkList L)
{   
    DuLinkList p = L->next;                   //p指向第一个结点
    while(p != L)                             //判断是否到链表尾部
    {  
        p = p->next;
        free(p->prior);
    }
    L->next = L->prior = L;                   //最后设置头结点的两个指针域指向其本身
}
/* 销毁双向循环链表L */
void DestroyList(DuLinkList *L)
{   
    DuLinkList q,p = (*L)->next;              //p指向第一个结点 
    while(p != (*L))                          //判断是否到链表尾部
    {
        q = p->next;
        free(p);
        p = q;
    }
    free((*L));                              //最后销毁头结点，并且为了避免野指针，将头结点指针置空
    (*L) = NULL;
}
/* 判断双向循环链表L是否为空:若L为空表，则返回TRUE，否则返回FALSE */
int TestListEmpty(DuLinkList L)
{ 
    if(L->next == L && L->prior == L)	//头和尾是不是都指向他自己
        return true;
    else
        return false;
}
/* 获取双向循环链表的长度（不包括头结点） */
int GetListLength(DuLinkList L)
{    
     int len = 0;                             //len用来存储链表的长度
     DuLinkList p = L->next;                  //p指向第一个结点
     while(p != L)
     { 
        len++;
        p = p->next;
     }
     return len;
}

/* 获取双向循环链表中第i个元素的值：当第i个元素存在时，将其值赋给e并返回OK，否则返回ERROR */
int GetElem(DuLinkList L,int i,ElemType *e)
{ 
    int j =1 ;
    if(i > GetListLength(L))                // 首先对i的合法性进行判断
        return -1;
    DuLinkList p = L->next;                 //p指向第一个结点
    while(p != L && j < i)                  //顺指针向后查找直到p指向第i个元素
    { 
        j++;
        p = p->next;
    }
    if(p == L || j > i)                    //判断查找完后是否有异常情况
        return -1;
    *e = p->data;                          //返回第i个元素的值
    return 0;
}
/* 返回双向循环链表L中第1个与e满足关系compare()的数据元素的位序。若这样的数据元素不存在，则返回值为0。
其中compare()是数据元素判定比较函数，可根据实际情况编写，比如判断相等（就是查找了） 大于 小于等等。 */
int LocateElem(DuLinkList L,ElemType e,int(*compare)(ElemType,ElemType))
{ 
    int i = 0;
    DuLinkList p = L->next;                //p指向第一个结点
    while(p != L)                          //还没到链表末尾
    { 
        i++;
        if(compare(p->data,e))        //找到这样的元素
            return i;
        p = p->next;
    }
    return 0;                            //最后如果没有找到就返回
}
/* 若cur_e是双向循环链表L的数据元素，且不是第一个，则用pre_e指针保存返回它的前驱结点的值（数据域），如果操作成功函数返回0值，如果操作失败，pre_e无定义，函数返回-1值*/
int GetPriorElem(DuLinkList L,ElemType cur_e,ElemType *pre_e)
{ 
    DuLinkList p = L->next->next;       //p指向第2个元素
    while(p != L)
    { 
        if(p->data == cur_e)           //p指向结点的数据与cur_e值进行比较判断
        {
            *pre_e = p->prior->data;   //将p的前驱结点的值赋给*pre_e，pre_e保存返回
            return 0;                  //函数返回0值表示操作成功
        }
        p = p->next;
    }
    return -1;                         //函数返回-1值表示操作失败
}
/* 若cur_e是双向循环链表L的数据元素，且不是最后一个，则用next_e指针保存返回它的后继结点的值（数据域），如果操作成功函数返回0值，如果操作失败，next_e无定义，函数返回-1值 */
int GetNextElem(DuLinkList L,ElemType cur_e,ElemType *next_e)
{
     DuLinkList p = L->next->next;     //p指向第二个元素
     while(p != L)
     { 
        if(p->prior->data == cur_e)    //p所指结点的前驱与cur_e进行比较判断
        { 
            *next_e = p->data;         //将p所指结点的值赋给*next_e，next_e保存返回
            return 0;                  //函数返回0值表示操作成功
        }
        p = p->next;
     }
     return -1;                        //函数返回-1值表示操作失败
}
/* 在双向链表L中返回第i个元素的地址。i为0，返回头结点的地址。若第i个元素不存在，返回NULL*/
DuLinkList GetElemP(DuLinkList L,int i)
{
    int j;
    DuLinkList p = L;                  //p指向头结点
    if(i < 0 || i > GetListLength(L))  //对i的合法性进行判断
        return NULL;
    for(j = 1;j <= i;j++)              //p指向第i个结点
        p = p->next; 
    return p;                         //返回第i个元素的地址
}
/* 插入： 在双向循环链表L中第i个位置之前插入元素e，其中i的合法值为1≤i≤表长+1 */
int ListInsert(DuLinkList L,int i,ElemType e)
{ 
    DuLinkList p,s;
    if(i < 1 || i > GetListLength(L)+1)
        return -1;
    p = GetElemP(L,i-1);             //在L中确定第i个结点前驱的位置指针p即确定第i个结点的前驱位置
    if(!p) 
        return -1;
    s = (DuLinkList)malloc(sizeof(DuLNode));  //生成新结点
    if(!s) 
        return -1;
    s->data = e;                    //将e赋给新的结点
    s->prior = p;                   //新结点的前驱为第i-1个结点
    s->next = p->next;             //新结点的后继为第i个结点
    p->next->prior = s;            //第i个结点的前驱指向新结点
    p->next = s;                  //第i-1个结点的后继指向新结点
    return 0;                     //操作成功，返回0
}
/* 删除：删除双向循环链表L的第i个元素，并将要删除的元素放在指针e中保存返回，其中i的合法值为1≤i≤表长 */
int ListDelete(DuLinkList L, int i, ElemType *e)
{  
    DuLinkList p;
    if(i < 1 || i > GetListLength(L)+1)
        return -1;
    p = GetElemP(L,i);            //在L中确定第i个元素的位置指针
    if(!p) 
        return -1;
    *e = p->data;                //把第i个结点的元素的值赋给e
    p->prior->next = p->next;    //第原i-1个结点的后继指向原第i+1个结点
    p->next->prior = p->prior;   //第原i+1个结点的前驱指向原第i-1个结点
    free(p);                     //释放p指针所指向的结点
    return OK;
}
/* 正序遍历双向循环链表，遍历是调用visit函数进行 */
void ListTraverse(DuLinkList L,void(*visit)(ElemType))
{
    DuLinkList p = L->next;     //p指向第一个结点
    while(p != L)
    { 
        visit(p->data);         //对p所指结点调用函数visit()
        p = p->next;
    }
    printf("\n");
}
/* 逆序遍历双向循环链表，遍历是调用visit函数进行 */
void ListTraverseBack(DuLinkList L,void(*visit)(ElemType))
{ 
    DuLinkList p = L->prior;    //p指向尾结点
    while(p != L)
    { 
        visit(p->data);         //对p所指结点调用函数visit()
        p=p->prior;
    }
    printf("\n");
}
/* compare函数，这个函数可以根据实际情况进行编写，这里只是最简单的比较是否相等函数 
   如果比较两个元素相等就返回1，否则返回-1。 */
   int compare(ElemType datai,ElemType dataj)
   {
    if(datai == dataj)
        return 1;
    else
        return -1;
   }
   /* visit函数，这个函数可以根据实际情况进行编写，这里只是最简单的输出元素。*/
   void visit(ElemType data)
   {
    printf("%d\n", data);
   }
