#include<cstdio>
//��ƽ�����ӡ�(Balanced Factor BF) BF(T)=Hl-Hr
/*AVL��  |BF(T)|<=1
����������һ������������߶Ȳ�ľ���ֵ������1
Nh=(Nh-1)[���]+(Nh-2)[�ұ�]+1  Nh�Ǹ߶�Ϊh��ƽ����������ٽ����
Nh=(Fh+2)-1                 Fh��쳲���������
h=O(log2N)[����Ч��]
*/

typedef struct AVLNode *Position;
typedef Position AVLTree; /* AVL������ */
struct AVLNode{
    ElementType Data; /* ������� */
    AVLTree Left;     /* ָ�������� */
    AVLTree Right;    /* ָ�������� */
    int Height;       /* ���� */
};

int Max ( int a, int b )
{
    return a > b ? a : b;
}

int GetHeight(AVLTree Root){
    if(Root==NULL)
        return 0;
    else 
        return Root->Height;
}

AVLTree RightRotation ( AVLTree A )   //LL(����)
{     
 
    AVLTree B= A->Left;        //���ø����Root�����ӽ��Ϊ�µĸ����RootNew
    A->Left = B->Right;         //��RootNew������������ΪRoot����������
    B->Right = A;               //��Root�����ΪRootNew��������
    A->Height = Max( GetHeight(A->Left), GetHeight(A->Right) ) + 1;
    B->Height = Max( GetHeight(B->Left), GetHeight(B->Right) ) + 1;
  
    return B;
}

AVLTree LeftRotation ( AVLTree A )    //RR(����)
{     
 
    AVLTree B = A->Right;        //���ø����Root�����ӽ��Ϊ�µĸ����RootNew
    A->Right = B->Left;         //��RootNew������������ΪRoot����������
    B->Left = A;               //��Root�����ΪRootNew��������
    A->Height = Max( GetHeight(A->Left), GetHeight(A->Right) ) + 1;
    B->Height = Max( GetHeight(B->Left), GetHeight(B->Right) ) + 1;

    return B;
}

AVLTree DoubleRotateWithLeft ( AVLTree A )   //(LR)
{ 
    A->Left = LeftRotation(A->Left);  //��ʧ����A������B������������(RR)
    return RightRotation(A);          //��ʧ����A����������(LL)
}

AVLTree DoubleRotateWithRight ( AVLTree A )   //(RL)
{ 
    A->Right = RightRotation(A->Right);  //��ʧ����A������B������������(RR)
    return LeftRotation(A);          //��ʧ����A����������(LL)
}

AVLTree Insert( AVLTree T, ElementType X )
{
    if ( !T ) { /* ��������������½�����һ�������� */
        T = (AVLTree)malloc(sizeof(struct AVLNode));
        T->Data = X;
        T->Height = 0;
        T->Left = T->Right = NULL;
    } 
 
    else if ( X < T->Data ){
        T->Left = Insert( T->Left, X);  //����ݹ����
        if ( GetHeight(T->Left)-GetHeight(T->Right) == 2 )  //�����ƽ��
            if ( X < T->Left->Data )    //���ڲ�ƽ�����������������
               T = RightRotation(T);//(LL)
            else    //���������������ұ�
               T = DoubleRotateWithLeft(T); //LR
    }
    
    else if ( X > T->Data ){
        T->Right = Insert( T->Right, X );
        if ( GetHeight(T->Left)-GetHeight(T->Right) == -2 ) //�����ƽ��
            if ( X > T->Right->Data )   //���������������ұ�
               T = LeftRotation(T);     //(RR)
            else    //�����˲�ƽ���������������
               T = DoubleRotateWithRight(T); //RL
    }
    /* else (X==T->Data)    �������*/
    //��������
    T->Height = Max( GetHeight(T->Left), GetHeight(T->Right) ) + 1;
    return T;
}

