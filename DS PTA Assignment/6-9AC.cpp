void PreorderTraversal(BinTree BT)
{
    if (BT == NULL)
        return;
    printf(" %c", BT->Data);
    PreorderTraversal(BT->Left);
    PreorderTraversal(BT->Right);
}
//中序遍历
void InorderTraversal(BinTree BT)
{
    if (BT == NULL)
        return;
    InorderTraversal(BT->Left);
    printf(" %c", BT->Data);
    InorderTraversal(BT->Right);
 
}
//后序遍历
void PostorderTraversal(BinTree BT)
{
    if (BT == NULL)
        return;
    PostorderTraversal(BT->Left);
    PostorderTraversal(BT->Right);
    printf(" %c", BT->Data);
}
//层序遍历
void LevelorderTraversal(BinTree BT)
{
    if (BT == NULL)
        return;
    BinTree binTree[100];   //数组迭代存储层序遍历的节点
    int head = 0, last = 0; //
    binTree[last++] = BT;
 
    while (head < last)     //通过迭代存储和遍历节点
    {
        BinTree temp = binTree[head++];
        printf(" %c", temp->Data);
 
        if (temp->Left)     //左子树存在
            binTree[last++] = temp->Left;
        if (temp->Right)    //右子树存在
            binTree[last++] = temp->Right;
    }
}
