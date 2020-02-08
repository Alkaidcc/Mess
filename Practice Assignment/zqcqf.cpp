#include<stdio.h>
int a[102][102],score[102];
int main(){
    int t,n;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        int max=-1,maxi=0,maxn=0;
        scanf("%d",&n);
        for(int j=1;j<=n;j++){
            for(int h=1;h<=n;h++)
                scanf("%d",&a[j][h]);
            score[j]=0;
        }
        for(int j=1;j<=n;j++){
            for(int h=j+1;h<=n;h++){
                if(a[j][h]>a[h][j])
                    score[j]+=3;                
                else if(a[j][h]==a[h][j]){
                    score[j]+=1;
                    score[h]+=1;
                }
                else 
                    score[h]+=3;
            }
            if(score[j]==max)
                maxn=1;
            if(score[j]>max){
                max=score[j];
                maxi=j;
                maxn=0;
            }            
        }
        if(maxn)
            printf("找不出最强球队！\n");
        else
            printf("%d\n",maxi);
    }
}
