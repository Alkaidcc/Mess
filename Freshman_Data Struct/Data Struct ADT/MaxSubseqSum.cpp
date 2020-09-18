//sum1  T(N)=O(N^3)
int MaxSubseqSum1(int A[],int N)
{
    int ThisSum,MaxSum=0;
    int i,j,k;
    for(i=0;i<N;i++){   //i���������λ��
        for(j=i;j<N;j++){   //j�������Ҷ�λ��
            ThisSum=0;      //ThisSum�Ǵ�A[i]��A[j]�����к�
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
    for(i=0;i<N;i++){   //i���������λ��
        ThisSum=0;
        for(j=i;j<N;j++){   //j�������Ҷ�λ��
            ThisSum+=A[j];  //������ͬ��i��ͬ��jֻҪ��j-1��ѭ���Ļ������ۼ�1���
            if(ThisSum>MaxSum)
                MaxSum=ThisSum;        
        }
    }
}

//sum3  ���� T(N)=O(NlogN)

//sum4 ���ߴ��� T(N)=O(N)
int MaxSubseqSum4(int A[],int N)
{   /*�����������к�A<0 Ԫ��B>0 ��ô�ض����к�A+B<B ���� ֻҪ����ǰ������к�AȡBΪ������к�*/
    int ThisSum,MaxSum;
    int i;
    ThisSum=MaxSum=0;   //��ǰ���к�Ϊ������к�
    for(i=0;i<N;i++){   
        ThisSum+=A[j];  //�����ۼ�
        if(ThisSum>MaxSum)  
            MaxSum=ThisSum;
        else if(ThisSum<0)      //�����ǰ���к�Ϊ����  ���� ���к͹���
            ThisSum=0;        
        }
    }
    return MaxSum;
}