//定义栈
typedef struct SNode *Stack;
struct SNode{}
{
    ElementType Data;
    struct SNode *Next;
};
//构建头结点
Stack CreateStack(){
    Stack S;
    S=(Stack)malloc(sizeof(struct SNode));
    S->Next=NULL;
    return S;
}


//判断是否为空
int IsEmpty(Stack S){
    return (S->Next==NULL);
}


//入栈
void Push(ElementType item,Stack S){
    //不用考虑是否满栈
    struct SNode *TmpCell;
    TmpCell=(struct SNode*)malloc(sizeof(struct SNode));
    TmpCell->Data=item;
    TmpCell->Next=S->Next;
    S->Next=TmpCell;
}


//出栈
ElementType Pop(Stack S){
    struct SNode *FirstCell;
    ElementType TopElem;
    if(IsEmpty(S)){
        printf("堆栈空");
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



//定义二叉树
#include<cstdio>
typedef struct TreeNode *BinTree;
typedef BinTree Position;
struct TreeNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};


//先序遍历（中左右）
void PreOrderTraversal(BinTree BT){
    if(BT){
        printf("%d",BT->Data);
        PreOrderTraversal(BT->Left);
        PreOrderTraversal(BT->Right);
    }
}

//中序遍历（左中右）
void InOrderTraversal(BinTree BT){
    if(BT){
        InOrderTraversal(BT->Left);
        printf("%d",BT->Data);
        InOrderTraversal(BT->Right);
    }
}

//后序遍历(左右中)
void PostOrderTraversal(BinTree BT){
    if(BT){
        PostOrderTraversal(BT->Left);
        PostOrderTraversal(BT->Right); 
        printf("%d",BT->Data);
    }
}


//先序遍历用栈实现
void PreOrderTraversal(BinTree BT){
    BinTree T=BT;
    Stack S=CreatStack(MaxSize);    //创建并初始化栈S
    while(T||!IsEmpty(S)){          
        while(T){                  //一直向左并将沿途结点压入堆栈    
            printf("%5d",T->Data);  //访问（打印）结点
            push(S,T);
            T=T->Left;
        }
        if(!IsEmpty(S)){
            T=Pop(S);           //结点弹出栈
            T=T->Right;        //转向右子树
        }
    }
}


//序遍历用栈实现
//思路：遇到一个结点就把它压栈，并去遍历它的左子树
//当左子树遍历结束后，从栈顶弹出这个结点并访问它
//然后按其右指针再去中序遍历该节点的右子树
void InOrderTraversal(BinTree BT){
    BinTree T=BT;
    Stack S=CreatStack(MaxSize);    //创建并初始化栈S
    while(T||!IsEmpty(S)){          
        while(T){                  //一直向左并将沿途结点压入堆栈    
            push(S,T);
            T=T->Left;
        }
        if(!IsEmpty(S)){
            T=Pop(S);           //结点弹出栈
            printf("%5d",T->Data);  //访问（打印）结点
            T=T->Right;             //转向右子树
        }
    }
}

//后序遍历用栈实现


//层序遍历
struct Node{
    ElementType Data;
    struct Node *Next;
};
struct QNode{   //链队列结构
    struct Node *rear;  //指向队尾的结点
    struct Node *front; //指向队头的结点
};
typedef struct QNode *Queue;


void LevelOederTraversal(BinTree BT){
    Queue Q;    BinTree T;
    if(!BT) return; //如果是空树，直接返回
    Q=CreateQueue(MaxSize)
    AddQ(Q,BT);
    while (!IsEmpty(Q))
    {
        T=DeleteQ(Q);
        printf("%d\n",T->Data); //访问取出队列的结点
        if(T->Left)
            Add(Q,T->Left);
        if(T->Right)
            Add(Q,T->Right);
    }
}