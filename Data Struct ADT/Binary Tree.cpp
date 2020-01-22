//����ջ
typedef struct SNode *Stack;
struct SNode{}
{
    ElementType Data;
    struct SNode *Next;
};
//����ͷ���
Stack CreateStack(){
    Stack S;
    S=(Stack)malloc(sizeof(struct SNode));
    S->Next=NULL;
    return S;
}


//�ж��Ƿ�Ϊ��
int IsEmpty(Stack S){
    return (S->Next==NULL);
}


//��ջ
void Push(ElementType item,Stack S){
    //���ÿ����Ƿ���ջ
    struct SNode *TmpCell;
    TmpCell=(struct SNode*)malloc(sizeof(struct SNode));
    TmpCell->Data=item;
    TmpCell->Next=S->Next;
    S->Next=TmpCell;
}


//��ջ
ElementType Pop(Stack S){
    struct SNode *FirstCell;
    ElementType TopElem;
    if(IsEmpty(S)){
        printf("��ջ��");
        return NULL;
    }
    else
    {
        FirstCell=S->Next;
        S->Next=FirstCell->Next;
        TopElem=FirstCell->Data;
        free(FirstCell);
        return TopElem;
    }
    

}



//���������
#include<cstdio>
typedef struct TreeNode *BinTree;
typedef BinTree Position;
struct TreeNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};


//��������������ң�
void PreOrderTraversal(BinTree BT){
    if(BT){
        printf("%d",BT->Data);
        PreOrderTraversal(BT->Left);
        PreOrderTraversal(BT->Right);
    }
}

//��������������ң�
void InOrderTraversal(BinTree BT){
    if(BT){
        InOrderTraversal(BT->Left);
        printf("%d",BT->Data);
        InOrderTraversal(BT->Right);
    }
}

//�������(������)
void PostOrderTraversal(BinTree BT){
    if(BT){
        PostOrderTraversal(BT->Left);
        PostOrderTraversal(BT->Right); 
        printf("%d",BT->Data);
    }
}


//���������ջʵ��
void PreOrderTraversal(BinTree BT){
    BinTree T=BT;
    Stack S=CreatStack(MaxSize);    //��������ʼ��ջS
    while(T||!IsEmpty(S)){          
        while(T){                  //һֱ���󲢽���;���ѹ���ջ    
            printf("%5d",T->Data);  //���ʣ���ӡ�����
            push(S,T);
            T=T->Left;
        }
        if(!IsEmpty(S)){
            T=Pop(S);           //��㵯��ջ
            T=T->Right;        //ת��������
        }
    }
}


//�������ջʵ��
//˼·������һ�����Ͱ���ѹջ����ȥ��������������
//�����������������󣬴�ջ�����������㲢������
//Ȼ������ָ����ȥ��������ýڵ��������
void InOrderTraversal(BinTree BT){
    BinTree T=BT;
    Stack S=CreatStack(MaxSize);    //��������ʼ��ջS
    while(T||!IsEmpty(S)){          
        while(T){                  //һֱ���󲢽���;���ѹ���ջ    
            push(S,T);
            T=T->Left;
        }
        if(!IsEmpty(S)){
            T=Pop(S);           //��㵯��ջ
            printf("%5d",T->Data);  //���ʣ���ӡ�����
            T=T->Right;             //ת��������
        }
    }
}

//���������ջʵ��


//�������
struct Node{
    ElementType Data;
    struct Node *Next;
};
struct QNode{   //�����нṹ
    struct Node *rear;  //ָ���β�Ľ��
    struct Node *front; //ָ���ͷ�Ľ��
};
typedef struct QNode *Queue;


void LevelOederTraversal(BinTree BT){
    Queue Q;    BinTree T;
    if(!BT) return; //����ǿ�����ֱ�ӷ���
    Q=CreateQueue(MaxSize)
    AddQ(Q,BT);
    while (!IsEmpty(Q))
    {
        T=DeleteQ(Q);
        printf("%d\n",T->Data); //����ȡ�����еĽ��
        if(T->Left)
            Add(Q,T->Left);
        if(T->Right)
            Add(Q,T->Right);
    }
}