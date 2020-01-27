//插入排序 （稳定）
//如果序列基本有序 插入排序很快 ->Shell_Sort
void Insertion_Sort(ElementType A[],int N){
    int p,tmp,i;
    for(p=1;p<N;p++){
        tmp=A[p];
        for(i=p;i>0&&A[i-1]>tmp;i--){
            A[i]=A[i-1];    //移出空位
        }
        A[i]=tmp;
    }
}