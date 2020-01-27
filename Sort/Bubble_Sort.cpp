
//√∞≈›≈≈–Ú £®Œ»∂®£©
void Bubble_Sort(ElementType A[],int N){
    int temp,flag,j,i;
    for(i=0;i<N-1;i++){
        flag=0;
        for(j=0;j<N-i-1;j++){
            if(A[j]>A[j+1]){
                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
                flag=1;
            }
        }
        if(flag==0)
            break;
    }
}