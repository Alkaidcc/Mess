
#include<stdio.h>
#include<string.h>
char x[10002];
int main(){
    FILE *fin,*fout;
    fin=fopen("test2.in","rb");
    fout=fopen("test2.out","wb");
    int t,n;
    fscanf(fin,"%d",&t);
    for(int i=1;i<=t;i++){
        int sum1=0,sum2=0,sum3=0;
        fscanf(fin,"%d",&n);
        fscanf(fin,"%s",x);
        for(int j=0;j<n;j++){
            if(x[j]=='z')sum1++;
            if(x[j]=='y')sum2+=sum1;
            if(x[j]=='h')sum3+=sum2;
        }       
        fprintf(fout,"%d\n",sum3);
    }
    fclose(fin);
    fclose(fout);
}
