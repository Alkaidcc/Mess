#include<stdio.h>
#include<iostream>
long long fx(long x){   //����n����5�ĸ���  
    long long i,j;
    long long cnt=0;
    for(i=5;i<=x;i++){
        j=i;
        while(j%5==0){
            j/=5;
            cnt++;
        }
    }
    return cnt;
}
int main(){                 //�ܵ�100000��ʱ�ˣ�����O��n2��T_T
    long long sum=0;
    long long n;
    long long i;
    scanf("%lld",&n);
    if(n<=4)    sum=0;
    else{
        for(i=5;i<=n;i++){
            sum+=fx(i);
        }
    }
    printf("%lld",sum);
    system("pause");
    return 0;
}