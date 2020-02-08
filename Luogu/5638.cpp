#include<stdio.h>
#include<iostream>
#define min(a,b) (((a)<(b))?(a):(b))
int main(){
   long long  n,k,x,ans=0;
   long long  q[1000000]={0};
   long long  h[1000000]={0};
   scanf("%lld %lld",&n,&k);
   for(int i=1;i<=n-1;i++){
        int x;
        scanf("%lld",&x);
        q[i]=q[i-1]+x;          //利用前缀和储存1 -> i 的距离
   } 
   for(int i=1;i<=n;i++){
       h[i]=q[i]+q[n-1]-q[i+k];
   }
   for(int i;i<=n;i++){
       ans=min(ans,h[i]);
   }
   printf("%lld",ans);
   system("pause");
   return 0;

}