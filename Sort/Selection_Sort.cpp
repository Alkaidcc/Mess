void Selection_Sort(ElementType A[],int N){
    int i,j,k,temp;
    for (i = 0; i <N-1; i++)
    {
        k = i;
        for (j = i + 1; j <N; j++)
        {
            if (A[j] < A[k])
            {
                k = j;    /*��¼��Сֵ�±�λ��*/
            }
        }
        if (k != i)  /*����С�����ڵ��±�λ�ò���λ��i����н���*/
        {
            temp = A[k];
            A[k] = A[i];
            A[i] = temp;
        }
    }
}