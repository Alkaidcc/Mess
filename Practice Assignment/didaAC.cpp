#include<stdio.h>
#include<string.h>
char a[50000];
int sum[50];
int main(){
    int t;
    char x,y,h;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        int cnt=0,cnt2=0;
        memset(sum,0,sizeof(sum));
        scanf("%s",a);
        for(int j=0;j<strlen(a);j++){
            if(a[j]=='d'&&a[j+1]=='a'){
                int count=0;
                for(int h=j+2;h<=j+4;h++){
                    if(a[h]>='0'&&a[h]<='9'){
                        sum[cnt2++]=a[h]-'0';
                        count++;
                    }
                }
                if(count)
                    cnt++;
                j+=4;
            }
            else if(a[j]=='d'&&a[j+1]=='i'){
                if(a[j+2]>='0'&&a[j+2]<='9'){
                    sum[cnt2++]=a[j+2]-'0';
                    cnt++;
                }
                j+=2;
            }
        }
        cnt2--;
        int k=cnt2,flag=1;
        sum[k]+=cnt;
        while(sum[k]>=10){
            if(k==0){
                for(int j=cnt2;j>=0;j--)
                    sum[j+1]=sum[j];
                k++,cnt2++;
            }
            sum[k-1]+=(sum[k]-sum[k]%10)/10;
            sum[k]=sum[k]%10;
            k--;
        }
        for(int j=0;j<=cnt2;j++){
            while(flag&&sum[j]==0)j++;
            flag=0;
            printf("%d",sum[j]);
        }
        if(!cnt)printf("0");
        printf("\n");
    }
}
