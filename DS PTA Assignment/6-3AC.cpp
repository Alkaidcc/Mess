int Length( List L ){
    List p=L;
    int cnt=0;
    while(p){
        p=p->Next;
        cnt++;
    }
    return cnt;
}