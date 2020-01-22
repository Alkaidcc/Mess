List MakeEmpty(){
    List Ptr;
    Ptr=(List)malloc(sizeof(struct LNode));
    Ptr->Last=-1;
    return Ptr;
}

Position Find( List L, ElementType X ){
    int i;
    for(i=0;i<=L->Last;i++){    
        if(X==L->Data[i]){
            return i;
        }
    }
    return ERROR;
}

bool Insert( List L, ElementType X, Position P ){
    int j;
    if(L->Last==MAXSIZE-1){
        printf("FULL");
        return false;
    }
    if(P<0||P>L->Last+1){
        printf("ILLEGAL POSITION");
        return false;
    }
    for(j=L->Last+1;j>P;j--)
        L->Data[j]=L->Data[j-1];
    L->Data[P]=X;
    L->Last++;
    return true;
}

bool Delete( List L, Position P ){
    int j;
    if(P<0||P>L->Last){
        printf("POSITION %d EMPTY",P);
        return false;
    }
    for(j=P;j<=L->Last;j++)
        L->Data[j]=L->Data[j+1];
    L->Last--;
    return true;
}