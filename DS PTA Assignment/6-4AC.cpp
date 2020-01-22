ElementType FindKth( List L, int K ){
    if(!L||K<0)
        return ERROR;
    while(--K){
        if(L->Next==NULL)
            return ERROR;
        else
            L=L->Next;
    }
    return L->Data;
}