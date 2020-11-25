#include <stdio.h>
#include <string.h>
#include <iostream>
int main(){

    char str1[] = "hello";
    char str2[6] = {'h','e','l','l','o'};
    printf("%s\n",str1);
    printf("str1_len: %d\n", strlen(str1));
    printf("str2_len: %d\n", strlen(str2));
    printf("str1[5]: %c\n", str1[4]);
    printf("str1[6]: %c\n", str1[5]);
    printf("str2[5]: %c\n", str2[4]);
    printf("str2[6]: %c\n", str2[5]);

    system("pause");
    return 0;
}