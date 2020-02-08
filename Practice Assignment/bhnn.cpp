#include<stdio.h>
int main(){
    int n,t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        if(n<=3&&n!=0)printf("milk will die!!!\n");
        else printf("milk is alive!!!\n");
    }
}
