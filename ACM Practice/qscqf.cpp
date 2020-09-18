#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int cnt=i%2;
        for(int j=1;j<=n;j++){
            if((cnt++)%2==1)
                printf("B");
            else
                printf("R");
        }
        printf("\n");
    }
}