int GetHeight(BinTree BT){//�������ʵ��
    int HL,HR,MaxH;
    if(BT){
        HL=GetHeight(BT->Left);     //�����������
        HR=GetHeight(BT->Right);    //�����������
        MaxH=(HL>HR)?HL:HR;         //ȡ���������������
        return (MaxH+1);            //�����������
    }
    else{                           //��������Ϊ0
        return 0;
    }
}