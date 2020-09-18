#include<cstdio>
//定义二叉树
struct TreeNode{
    ElementType Data;//数据域
    TreeNode* Left; //指针域
    TreeNode* Right;//指针域
};
typedef TreeNode* BinTree;
typedef BinTree Position;


//查找
Position Find1(ElementType X,BinTree BST){
    if(!BST)
        return NULL;
    if(X>BST->Data)
        return Find1(X,BST->Right);
    else if(X<BST->Data)
        return Find1(X,BST->Left);
    else
        return BST;
}

//用循环(非递归)实现(优化)
Position Find2(ElementType X,BinTree BST){
    while (BST)
    {
        if(X>BST->Data)
            BST=BST->Right;
        else if(X<BST->Data)
            BST=BST->Left;
        else
            return BST;
    }
    return NULL;
}

//查找最小值
Position FindMin(BinTree BST){
    if(BST){
        while(BST->Left)
            BST=BST->Left;
        return BST;
    }
    else 
        return NULL;
}

//查找最大值
Position FindMax(BinTree BST){
    if(BST){
        while (BSt->Right)
            BST=BST->Right;
        return BST;
    }
    else
        return NULL;
}

//插入
Position Insert(ElementType X,BinTree BST){
    if(!BST){
        BST=(BinTree)malloc(sizeof(struct TreeNode));
        BST->Data=X;
        BST->Left=BST->Right=NULL;
    }
    else{
        if(X>BST->Data)
            BST->Right=Insert(X,BST->Right);
        else if(X<BST->Data)
            BST->Left=Insert(X,BST->Left);
    }
    return BST;
}

//删除
Position Delete(ElementType X,BinTree BST){
    Position temp;
    if(!BST)
        printf("未找到要删除的元素");
    else if(X>BST->Data)
        BST->Right=Delete(X,BST->Right);    //左子树递归删除
    else if(X<BST->Data)
        BST->Left=Delete(X,BST->Left);      //右子树递归删除
    else{
        //找到要删除的结点
        if(BST->Right&&BST->Left){          //被删除结点的左右两边都有子结点
            temp=FindMin(BST->Right);           //在右子树中寻找最小元素填充删除结点
            BST->Data=temp->Data;
            BST->Right=Delete(BST->Data,BST->Right);            //在删除结点的有子树中删除最小元素
        }
        else{   //被删除的结点只有一个或者没有子结点
            temp=BST;
            if(!BST->Right)     //左侧有一个子结点
                BST=BST->Light;
            else if(!BST->Left) //右侧有一个子结点
                BST=bst->Right;
            free(temp);
        }
    }
    return BST;
}