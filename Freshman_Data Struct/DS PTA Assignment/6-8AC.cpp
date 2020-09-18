int GetHeight(BinTree BT){//后序遍历实现
    int HL,HR,MaxH;
    if(BT){
        HL=GetHeight(BT->Left);     //求左子树深度
        HR=GetHeight(BT->Right);    //求右子树深度
        MaxH=(HL>HR)?HL:HR;         //取左右子树最大的深度
        return (MaxH+1);            //返回树的深度
    }
    else{                           //否则树深为0
        return 0;
    }
}