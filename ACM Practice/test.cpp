#include<stdio.h>
#include<string.h>
#include<iostream>
char s[30000];
int main(){
    FILE *fin,*fout;
    fin=fopen("test1.in","rb");
    fout=fopen("test1.out","wb");
    long long  t,i,j,k,num1=0,di=0,da=0,cnt=0;
    fscanf(fin,"%lld",&t);
    for(i=0;i<t;i++){
        memset(s,0,sizeof(s));
        num1=0;
        di=0;
        da=0;
        fscanf(fin,"%s",s);
        for(j=0;j<strlen(s);j++){
            if(s[j]=='d'&&s[j+1]=='a'){
                cnt=0;
                for(k=j+2;k<j+5&&k<strlen(s);k++){
                    if(s[k]>='0'&&s[k]<='9'){
                        num1=num1*10+s[k]-'0';
                        cnt++;
                    }
                }
                if(cnt) da++;
                j=j+4;
            }
            else if(s[j]=='d'&&s[j+1]=='i'){
                if(s[j+2]>='0'&&s[j+2]<='9'){
                    di++;
                    num1=num1*10+s[j+2]-'0';
                }
                j=j+2;
            }
        }
        fprintf(fout,"%lld\n",num1+di+da);
        
    }
    fclose(fin);
    fclose(fout);
    system("pause");
    return 0;

}