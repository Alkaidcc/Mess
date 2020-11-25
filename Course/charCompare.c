#include <stdio.h>
#include <string.h>
#include <iostream>

int main(){
    char a[] = "aaa";
    char b[] = "aaa";

    if(a == b){
        printf(" a == b\n");
    }else{
        printf("a != b\n");
    }
    // printf("a address: %p\n",a);
    // printf("b address: %p\n",b);
    if(strcmp(a,b) == 0){
        printf("a == b\n");
    }else{
        printf("a != b\n");
    }
    system("pause");
}