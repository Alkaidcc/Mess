//�������� ���ȶ���
//������л������� ��������ܿ� ->Shell_Sort
void Insertion_Sort(ElementType A[],int N){
    int p,tmp,i;
    for(p=1;p<N;p++){
        tmp=A[p];
        for(i=p;i>0&&A[i-1]>tmp;i--){
            A[i]=A[i-1];    //�Ƴ���λ
        }
        A[i]=tmp;
    }
}