#include<cstdio>
//“平衡因子”(Balanced Factor BF) BF(T)=Hl-Hr
/*AVL树  |BF(T)|<=1
空树或者任一结点左右子树高度差的绝对值不超过1
Nh=(Nh-1)[左边]+(Nh-2)[右边]+1  Nh是高度为h的平衡二叉树最少结点数
Nh=(Fh+2)-1                 Fh是斐波那契数列
h=O(log2N)[查找效率]
*/

typedef struct AVLNode *Position;
typedef Position AVLTree; /* AVL树类型 */
struct AVLNode{
    ElementType Data; /* 结点数据 */
    AVLTree Left;     /* 指向左子树 */
    AVLTree Right;    /* 指向右子树 */
    int Height;       /* 树高 */
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

AVLTree RightRotation ( AVLTree A )   //LL(右旋)
{     
 
    AVLTree B= A->Left;        //设置根结点Root的左子结点为新的根结点RootNew
    A->Left = B->Right;         //将RootNew结点的右子树作为Root结点的左子树
    B->Right = A;               //将Root结点作为RootNew的右子树
    A->Height = Max( GetHeight(A->Left), GetHeight(A->Right) ) + 1;
    B->Height = Max( GetHeight(B->Left), GetHeight(B->Right) ) + 1;
  
    return B;
}

AVLTree LeftRotation ( AVLTree A )    //RR(左旋)
{     
 
    AVLTree B = A->Right;        //设置根结点Root的右子结点为新的根结点RootNew
    A->Right = B->Left;         //将RootNew结点的左子树作为Root结点的右子树
    B->Left = A;               //将Root结点作为RootNew的左子树
    A->Height = Max( GetHeight(A->Left), GetHeight(A->Right) ) + 1;
    B->Height = Max( GetHeight(B->Left), GetHeight(B->Right) ) + 1;

    return B;
}

AVLTree DoubleRotateWithLeft ( AVLTree A )   //(LR)
{ 
    A->Left = LeftRotation(A->Left);  //对失衡结点A的左孩子B进行左旋操作(RR)
    return RightRotation(A);          //对失衡结点A做右旋操作(LL)
}

AVLTree DoubleRotateWithRight ( AVLTree A )   //(RL)
{ 
    A->Right = RightRotation(A->Right);  //对失衡结点A的左孩子B进行右旋操作(RR)
    return LeftRotation(A);          //对失衡结点A做左旋操作(LL)
}

AVLTree Insert( AVLTree T, ElementType X )
{
    if ( !T ) { /* 若插入空树，则新建包含一个结点的树 */
        T = (AVLTree)malloc(sizeof(struct AVLNode));
        T->Data = X;
        T->Height = 0;
        T->Left = T->Right = NULL;
    } 
 
    else if ( X < T->Data ){
        T->Left = Insert( T->Left, X);  //往左递归插入
        if ( GetHeight(T->Left)-GetHeight(T->Right) == 2 )  //如果不平衡
            if ( X < T->Left->Data )    //插在不平衡结点了左子树的左边
               T = RightRotation(T);//(LL)
            else    //插在了左子树的右边
               T = DoubleRotateWithLeft(T); //LR
    }
    
    else if ( X > T->Data ){
        T->Right = Insert( T->Right, X );
        if ( GetHeight(T->Left)-GetHeight(T->Right) == -2 ) //如果不平衡
            if ( X > T->Right->Data )   //插在了右子树的右边
               T = LeftRotation(T);     //(RR)
            else    //插在了不平衡结点右子树的左边
               T = DoubleRotateWithRight(T); //RL
    }
    /* else (X==T->Data)    无需插入*/
    //更新树高
    T->Height = Max( GetHeight(T->Left), GetHeight(T->Right) ) + 1;
    return T;
}

