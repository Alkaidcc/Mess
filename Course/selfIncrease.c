#include <stdio.h>
#include <iostream>
int main(){
    int b=20;
    //����++���ص����ݴ������ֵ��ǰ��++���ص��Ǳ��������ֵ
    printf("%d,%d\n",b++,++b);// 21 22
    printf("%d,%d\n",b++,b++); //21  20 
    printf("%d,%d\n",++b,++b); //22  22
    printf("%d,%d\n",++b,b++); //22  20
    system("pause");
}