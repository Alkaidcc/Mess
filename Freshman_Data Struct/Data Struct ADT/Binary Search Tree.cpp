#include<cstdio>
//���������
struct TreeNode{
    ElementType Data;//������
    TreeNode* Left; //ָ����
    TreeNode* Right;//ָ����
};
typedef TreeNode* BinTree;
typedef BinTree Position;


//����
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

//��ѭ��(�ǵݹ�)ʵ��(�Ż�)
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

//������Сֵ
Position FindMin(BinTree BST){
    if(BST){
        while(BST->Left)
            BST=BST->Left;
        return BST;
    }
    else 
        return NULL;
}

//�������ֵ
Position FindMax(BinTree BST){
    if(BST){
        while (BSt->Right)
            BST=BST->Right;
        return BST;
    }
    else
        return NULL;
}

//����
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

//ɾ��
Position Delete(ElementType X,BinTree BST){
    Position temp;
    if(!BST)
        printf("δ�ҵ�Ҫɾ����Ԫ��");
    else if(X>BST->Data)
        BST->Right=Delete(X,BST->Right);    //�������ݹ�ɾ��
    else if(X<BST->Data)
        BST->Left=Delete(X,BST->Left);      //�������ݹ�ɾ��
    else{
        //�ҵ�Ҫɾ���Ľ��
        if(BST->Right&&BST->Left){          //��ɾ�������������߶����ӽ��
            temp=FindMin(BST->Right);           //����������Ѱ����СԪ�����ɾ�����
            BST->Data=temp->Data;
            BST->Right=Delete(BST->Data,BST->Right);            //��ɾ��������������ɾ����СԪ��
        }
        else{   //��ɾ���Ľ��ֻ��һ������û���ӽ��
            temp=BST;
            if(!BST->Right)     //�����һ���ӽ��
                BST=BST->Light;
            else if(!BST->Left) //�Ҳ���һ���ӽ��
                BST=bst->Right;
            free(temp);
        }
    }
    return BST;
}