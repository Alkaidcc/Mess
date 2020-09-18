//sum1  T(N)=O(N^3)
int MaxSubseqSum1(int A[],int N)
{
    int ThisSum,MaxSum=0;
    int i,j,k;
    for(i=0;i<N;i++){   //i是子列左端位置
        for(j=i;j<N;j++){   //j是子列右端位置
            ThisSum=0;      //ThisSum是从A[i]到A[j]的子列和
            for(k=i;k<=j;k++)
                ThisSum+=A[k];
            if(ThisSum>MaxSum)
                MaxSum=ThisSum;        
        }
    }
}

//sum2 T(N)=O(N^2)
int MaxSubseqSum2(int A[],int N)
{
    int ThisSum,MaxSum=0;
    int i,j,k;
    for(i=0;i<N;i++){   //i是子列左端位置
        ThisSum=0;
        for(j=i;j<N;j++){   //j是子列右端位置
            ThisSum+=A[j];  //对于相同的i不同的j只要在j-1次循环的基础上累加1项即可
            if(ThisSum>MaxSum)
                MaxSum=ThisSum;        
        }
    }
}

//sum3  分治 T(N)=O(NlogN)

//sum4 在线处理 T(N)=O(N)
int MaxSubseqSum4(int A[],int N)
{   /*假设连续子列和A<0 元素B>0 那么必定子列和A+B<B 所以 只要放弃前面的子列和A取B为最大子列和*/
    int ThisSum,MaxSum;
    int i;
    ThisSum=MaxSum=0;   //当前子列和为最大子列和
    for(i=0;i<N;i++){   
        ThisSum+=A[j];  //向右累加
        if(ThisSum>MaxSum)  
            MaxSum=ThisSum;
        else if(ThisSum<0)      //如果当前子列和为负数  抛弃 子列和归零
            ThisSum=0;        
        }
    }
    return MaxSum;
}