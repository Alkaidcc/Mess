Position Find( BinTree BST, ElementType X ){
    while(BST){
        if(X>BST->Data)
            BST=BST->Right;
        else if(X<BST->Data)
            BST=BST->Left;
        else
            return BST;
    }
    return NULL;
}
Position FindMin( BinTree BST ){
    if(BST){
        while(BST->Left)
            BST=BST->Left;
        return BST;
    }
    return NULL;
}

Position FindMax( BinTree BST ){
    if(BST){
        while(BST->Right)
            BST=BST->Right;
        return BST;
    }
    return NULL;
}

BinTree Insert( BinTree BST, ElementType X ){
    if(!BST){
        BST=(BinTree)malloc(sizeof(struct TNode));
        BST->Data=X;
        BST->Left=BST->Right=NULL;
    }
    else{
        if(X>BST->Data)
            BST->Right=Insert(BST->Right,X);
        else if(X<BST->Data)
            BST->Left=Insert(BST->Left,X);
    }
    return BST;
}
BinTree Delete( BinTree BST, ElementType X ){
    Position temp;
    if(!BST)
        printf("Not Found\n");
    else if(X>BST->Data)
        BST->Right=Delete(BST->Right,X);
    else if(X<BST->Data)
        BST->Left=Delete(BST->Left,X);
    else{
        if(BST->Left&&BST->Right){
            temp=FindMin(BST->Right);
            BST->Data=temp->Data;
            BST->Right=Delete(BST->Right,BST->Data);
        }
        else{
            temp=BST;
            if(!BST->Right)
                BST=BST->Left;
            else if(!BST->Left)
                BST=BST->Right;
            free(temp);
        }
    }
    return BST;
}
