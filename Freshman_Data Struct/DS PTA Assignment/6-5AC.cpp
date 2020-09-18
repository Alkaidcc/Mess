Position Find( List L, ElementType X ){
    List p=L;
    if(!L)
        return ERROR;
    while(p!=NULL&&p->Data!=X)
        p=p->Next;
    return  p;
}

List Insert( List L, ElementType X, Position P ){
    List head =L;
    List p=(List)malloc(sizeof(struct LNode));
    p->Data=X;
    p->Next=NULL;
    if(L==P){
        p->Next=L;
        return p;
    }
    while(L){
        if(L->Next==P){
            List temp=L->Next;
            L->Next=p;
            p->Next=temp;
            return head;
        }
        L=L->Next;
    }
    printf("Wrong Position for Insertion\n");
    return ERROR;
}

List Delete( List L, Position P ){
    List head=L;
    if(L==P){
        L=L->Next;
        return L;
    }
    while(L){
        if(L->Next==P){
            List temp=P->Next;
            L->Next=temp;
            return head;
        }
        L=L->Next;
    }
    printf("Wrong Position for Deletion\n");
    return ERROR;
}