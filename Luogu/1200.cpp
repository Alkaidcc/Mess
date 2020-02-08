#include<stdio.h>
#include<string.h>
int main(){
    char ch1[100],ch2[100];
    int i,j,sum1=1,sum2=1;
    int n1,n2;
    gets(ch1);
    gets(ch2);
    n1=strlen(ch1);
    n2=strlen(ch2);
    for(i=0;i<n1;i++){
        sum1*=(ch1[i]-'A'+1);
    }
    for(i=0;i<n2;i++){
        sum2*=(ch2[i]-'A'+1);
    }
    if(sum1%47==sum2%47){
        printf("GO");
    }
    else
        printf("STAY");
    return 0;

}