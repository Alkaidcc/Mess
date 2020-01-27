List Reverse( List L ){
    List head;
    List temp;
    List First;
    if(L==NULL)
        return NULL;
    head=(List)malloc(sizeof(struct Node));
    First=L;
    head->Next=L;
    while(First->Next){
        temp=First->Next;
        First->Next=temp->Next;
        temp->Next=head->Next;
        head->Next=temp;
    }
    return head->Next;
}