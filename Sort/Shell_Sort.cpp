void Shell_Sort(ElementType A[],int N){
    int Gap,p,tmp,i;
    for(Gap=N/2;Gap>0;Gap/=2){  
        for(p=Gap;p<N;p++){     
            tmp=A[p];
            for(i=p;i>=Gap&&A[i-Gap]<tmp;i-=Gap){
                A[i]=A[i-Gap];
            }
            A[i]=tmp;
        }
    }
}