void PreorderPrintLeaves(BinTree BT){//�������ʵ��
    if(BT){
        if(!BT->Left&&!BT->Right)   //  �����޺���
            printf(" %C",BT->Data);
        PreorderPrintLeaves(BT->Left);
        PreorderPrintLeaves(BT->Right);
    }
    
}