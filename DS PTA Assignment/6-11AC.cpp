void PreorderPrintLeaves(BinTree BT){//先序遍历实现
    if(BT){
        if(!BT->Left&&!BT->Right)   //  左右无孩子
            printf(" %C",BT->Data);
        PreorderPrintLeaves(BT->Left);
        PreorderPrintLeaves(BT->Right);
    }
    
}