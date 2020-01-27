List MakeEmpty(){
    
    List head=(List)malloc(sizeof(struct LNode));
    head->Next=NULL;
    return head;
}


Position Find( List L, ElementType X ){
    List NOWLIST=L;
    while(NOWLIST){
        if(NOWLIST->Data==X)
            return NOWLIST;
        NOWLIST=NOWLIST->Next;
    }
    return ERROR;
}

bool Insert( List L, ElementType X, Position P ){
    if(P==L->Next){
        List p=(List)malloc(sizeof(struct LNode));
        p->Data=X;
        p->Next=L->Next;
        L->Next=p;
        return true;
    }
    List p=L;
    while(p){
        if(p->Next==P){
            List q=(List)malloc(sizeof(struct LNode));
            q->Data=X;
            q->Next=P;
            p->Next=q;
            return true;
        }
        p=p->Next;
    }
    printf("Wrong Position for Insertion\n");
    return false;
}


bool Delete( List L, Position P ){
    List q=L;
    while(q){
        if(q->Next==P){
            q->Next=P->Next;
            return true;
        }
        q=q->Next;
    }
    printf("Wrong Position for Deletion\n");
    return false;
}