/* ���������� */
typedef struct DuLNode
{ ElemType data;                //������
  DuLNode *prior;               //ֱ��ǰ��ָ��
  DuLNode *next;               //ֱ�Ӻ��ָ��
}DuLNode,*DuLinkList;

//��������
void InitList(DuLinkList *L);//����˫��ѭ������
void ClearList(DuLinkList L);//���˫��ѭ������
void DestroyList(DuLinkList &L);//����˫��ѭ������
int TestListEmpty(DuLinkList L);//�ж�˫��ѭ�������Ƿ�Ϊ��
int GetListLength(DuLinkList L);//��ȡ˫��ѭ������ĳ���
int GetElem(DuLinkList L,int i,ElemType *e);//��ȡ˫��ѭ�������е�i��Ԫ�ص�ֵ
//����L�е�1����e�����ϵcompare()������Ԫ�ص�λ��
int LocateElem(DuLinkList L,ElemType e,int(*compare)(ElemType,ElemType));
int GetPriorElem(DuLinkList L,ElemType cur_e,ElemType *pre_e);//ǰ���ж����ȡ
int GetNextElem(DuLinkList L,ElemType cur_e,ElemType *next_e);//����ж����ȡ
DuLinkList GetElemP(DuLinkList L,int i);//���ص�i��Ԫ�صĵ�ַ
int ListInsert(DuLinkList L,int i,ElemType e);//���룺�ڵ�i��λ��֮ǰ����Ԫ��e
int ListDelete(DuLinkList L,ElemType *e);//ɾ����ɾ�����е�i��Ԫ��
void ListTraverse(DuLinkList L,void(*visit)(ElemType));//�������˫��ѭ������
void ListTraverseBack(DuLinkList L,void(*visit)(ElemType));//�������˫��ѭ������

/* ����˫��ѭ������L */
void InitList(DuLinkList *L)
{   
    *L=(DuLinkList)malloc(sizeof(DuLNode));
    if(NULL != (*L))
        (*L)->next = (*L)->prior = (*L);      //˫�������ͷ���
    else
        exit(0);
}
/* ���˫��ѭ������L */
void ClearList(DuLinkList L)
{   
    DuLinkList p = L->next;                   //pָ���һ�����
    while(p != L)                             //�ж��Ƿ�����β��
    {  
        p = p->next;
        free(p->prior);
    }
    L->next = L->prior = L;                   //�������ͷ��������ָ����ָ���䱾��
}
/* ����˫��ѭ������L */
void DestroyList(DuLinkList *L)
{   
    DuLinkList q,p = (*L)->next;              //pָ���һ����� 
    while(p != (*L))                          //�ж��Ƿ�����β��
    {
        q = p->next;
        free(p);
        p = q;
    }
    free((*L));                              //�������ͷ��㣬����Ϊ�˱���Ұָ�룬��ͷ���ָ���ÿ�
    (*L) = NULL;
}
/* �ж�˫��ѭ������L�Ƿ�Ϊ��:��LΪ�ձ��򷵻�TRUE�����򷵻�FALSE */
int TestListEmpty(DuLinkList L)
{ 
    if(L->next == L && L->prior == L)	//ͷ��β�ǲ��Ƕ�ָ�����Լ�
        return true;
    else
        return false;
}
/* ��ȡ˫��ѭ������ĳ��ȣ�������ͷ��㣩 */
int GetListLength(DuLinkList L)
{    
     int len = 0;                             //len�����洢����ĳ���
     DuLinkList p = L->next;                  //pָ���һ�����
     while(p != L)
     { 
        len++;
        p = p->next;
     }
     return len;
}

/* ��ȡ˫��ѭ�������е�i��Ԫ�ص�ֵ������i��Ԫ�ش���ʱ������ֵ����e������OK�����򷵻�ERROR */
int GetElem(DuLinkList L,int i,ElemType *e)
{ 
    int j =1 ;
    if(i > GetListLength(L))                // ���ȶ�i�ĺϷ��Խ����ж�
        return -1;
    DuLinkList p = L->next;                 //pָ���һ�����
    while(p != L && j < i)                  //˳ָ��������ֱ��pָ���i��Ԫ��
    { 
        j++;
        p = p->next;
    }
    if(p == L || j > i)                    //�жϲ�������Ƿ����쳣���
        return -1;
    *e = p->data;                          //���ص�i��Ԫ�ص�ֵ
    return 0;
}
/* ����˫��ѭ������L�е�1����e�����ϵcompare()������Ԫ�ص�λ��������������Ԫ�ز����ڣ��򷵻�ֵΪ0��
����compare()������Ԫ���ж��ȽϺ������ɸ���ʵ�������д�������ж���ȣ����ǲ����ˣ� ���� С�ڵȵȡ� */
int LocateElem(DuLinkList L,ElemType e,int(*compare)(ElemType,ElemType))
{ 
    int i = 0;
    DuLinkList p = L->next;                //pָ���һ�����
    while(p != L)                          //��û������ĩβ
    { 
        i++;
        if(compare(p->data,e))        //�ҵ�������Ԫ��
            return i;
        p = p->next;
    }
    return 0;                            //������û���ҵ��ͷ���
}
/* ��cur_e��˫��ѭ������L������Ԫ�أ��Ҳ��ǵ�һ��������pre_eָ�뱣�淵������ǰ������ֵ�������򣩣���������ɹ���������0ֵ���������ʧ�ܣ�pre_e�޶��壬��������-1ֵ*/
int GetPriorElem(DuLinkList L,ElemType cur_e,ElemType *pre_e)
{ 
    DuLinkList p = L->next->next;       //pָ���2��Ԫ��
    while(p != L)
    { 
        if(p->data == cur_e)           //pָ�����������cur_eֵ���бȽ��ж�
        {
            *pre_e = p->prior->data;   //��p��ǰ������ֵ����*pre_e��pre_e���淵��
            return 0;                  //��������0ֵ��ʾ�����ɹ�
        }
        p = p->next;
    }
    return -1;                         //��������-1ֵ��ʾ����ʧ��
}
/* ��cur_e��˫��ѭ������L������Ԫ�أ��Ҳ������һ��������next_eָ�뱣�淵�����ĺ�̽���ֵ�������򣩣���������ɹ���������0ֵ���������ʧ�ܣ�next_e�޶��壬��������-1ֵ */
int GetNextElem(DuLinkList L,ElemType cur_e,ElemType *next_e)
{
     DuLinkList p = L->next->next;     //pָ��ڶ���Ԫ��
     while(p != L)
     { 
        if(p->prior->data == cur_e)    //p��ָ����ǰ����cur_e���бȽ��ж�
        { 
            *next_e = p->data;         //��p��ָ����ֵ����*next_e��next_e���淵��
            return 0;                  //��������0ֵ��ʾ�����ɹ�
        }
        p = p->next;
     }
     return -1;                        //��������-1ֵ��ʾ����ʧ��
}
/* ��˫������L�з��ص�i��Ԫ�صĵ�ַ��iΪ0������ͷ���ĵ�ַ������i��Ԫ�ز����ڣ�����NULL*/
DuLinkList GetElemP(DuLinkList L,int i)
{
    int j;
    DuLinkList p = L;                  //pָ��ͷ���
    if(i < 0 || i > GetListLength(L))  //��i�ĺϷ��Խ����ж�
        return NULL;
    for(j = 1;j <= i;j++)              //pָ���i�����
        p = p->next; 
    return p;                         //���ص�i��Ԫ�صĵ�ַ
}
/* ���룺 ��˫��ѭ������L�е�i��λ��֮ǰ����Ԫ��e������i�ĺϷ�ֵΪ1��i�ܱ�+1 */
int ListInsert(DuLinkList L,int i,ElemType e)
{ 
    DuLinkList p,s;
    if(i < 1 || i > GetListLength(L)+1)
        return -1;
    p = GetElemP(L,i-1);             //��L��ȷ����i�����ǰ����λ��ָ��p��ȷ����i������ǰ��λ��
    if(!p) 
        return -1;
    s = (DuLinkList)malloc(sizeof(DuLNode));  //�����½��
    if(!s) 
        return -1;
    s->data = e;                    //��e�����µĽ��
    s->prior = p;                   //�½���ǰ��Ϊ��i-1�����
    s->next = p->next;             //�½��ĺ��Ϊ��i�����
    p->next->prior = s;            //��i������ǰ��ָ���½��
    p->next = s;                  //��i-1�����ĺ��ָ���½��
    return 0;                     //�����ɹ�������0
}
/* ɾ����ɾ��˫��ѭ������L�ĵ�i��Ԫ�أ�����Ҫɾ����Ԫ�ط���ָ��e�б��淵�أ�����i�ĺϷ�ֵΪ1��i�ܱ� */
int ListDelete(DuLinkList L, int i, ElemType *e)
{  
    DuLinkList p;
    if(i < 1 || i > GetListLength(L)+1)
        return -1;
    p = GetElemP(L,i);            //��L��ȷ����i��Ԫ�ص�λ��ָ��
    if(!p) 
        return -1;
    *e = p->data;                //�ѵ�i������Ԫ�ص�ֵ����e
    p->prior->next = p->next;    //��ԭi-1�����ĺ��ָ��ԭ��i+1�����
    p->next->prior = p->prior;   //��ԭi+1������ǰ��ָ��ԭ��i-1�����
    free(p);                     //�ͷ�pָ����ָ��Ľ��
    return OK;
}
/* �������˫��ѭ�����������ǵ���visit�������� */
void ListTraverse(DuLinkList L,void(*visit)(ElemType))
{
    DuLinkList p = L->next;     //pָ���һ�����
    while(p != L)
    { 
        visit(p->data);         //��p��ָ�����ú���visit()
        p = p->next;
    }
    printf("\n");
}
/* �������˫��ѭ�����������ǵ���visit�������� */
void ListTraverseBack(DuLinkList L,void(*visit)(ElemType))
{ 
    DuLinkList p = L->prior;    //pָ��β���
    while(p != L)
    { 
        visit(p->data);         //��p��ָ�����ú���visit()
        p=p->prior;
    }
    printf("\n");
}
/* compare����������������Ը���ʵ��������б�д������ֻ����򵥵ıȽ��Ƿ���Ⱥ��� 
   ����Ƚ�����Ԫ����Ⱦͷ���1�����򷵻�-1�� */
   int compare(ElemType datai,ElemType dataj)
   {
    if(datai == dataj)
        return 1;
    else
        return -1;
   }
   /* visit����������������Ը���ʵ��������б�д������ֻ����򵥵����Ԫ�ء�*/
   void visit(ElemType data)
   {
    printf("%d\n", data);
   }
