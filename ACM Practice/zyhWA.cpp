#include<stdio.h>
#include<iostream>
#include<string.h>
char s[10000];
int main(){
   int t,i,j,k,l,n;
   scanf("%d",&t);
   for(i=0;i<t;i++){
       memset(s,0,sizeof(s));
       int cnt=0;
       scanf("%d",&n);
       getchar();
       for(j=0;j<n;j++){
           scanf("%c",&s[j]);
       }
       for(j=0;j<n;j++){
           if(s[j]=='z'){
               for(k=j+1;k<n;k++){
                   if(s[k]=='y'){
                       for(l=k+1;l<n;l++){
                           if(s[l]=='h'){
                               cnt++;
            
                           }
                       }
                   }
               }
           }
       }
       printf("%d\n",cnt);
   } 
   system("pause");
   return 0;
}