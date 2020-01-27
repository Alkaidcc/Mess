void Selection_Sort(ElementType A[],int N){
    int i,j,k,temp;
    for (i = 0; i <N-1; i++)
    {
        k = i;
        for (j = i + 1; j <N; j++)
        {
            if (A[j] < A[k])
            {
                k = j;    /*记录最小值下标位置*/
            }
        }
        if (k != i)  /*若最小数所在的下标位置不在位置i则进行交换*/
        {
            temp = A[k];
            A[k] = A[i];
            A[i] = temp;
        }
    }
}