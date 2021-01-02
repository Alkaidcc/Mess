#include <stdio.h>
#include <iostream>
int main(){
    int b=20;
    //后置++返回的是暂存区里的值，前置++返回的是变量本身的值
    printf("%d,%d\n",b++,++b);// 21 22
    printf("%d,%d\n",b++,b++); //21  20 
    printf("%d,%d\n",++b,++b); //22  22
    printf("%d,%d\n",++b,b++); //22  20
    system("pause");
}