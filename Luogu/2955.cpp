#include<stdio.h>
#include<string.h>
#include<iostream>      
int main(){
    int n;
    char s[100];        //������int����long long��������10^60�ᱬ�� �������ַ�����
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++){
        gets(s);
        if((s[strlen(s)-1]-'0')%2==0)   printf("even\n");
        else    printf("odd\n");
    }
    system("pause");
    return 0;
}