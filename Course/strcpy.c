#include <stdio.h>
#include <string.h>
#include <iostream>

char c[]="AAAAAAAAAAAAAAAAAAAAAAAAA";
int main(void)
{
    char arr[8];
    for(int i = 0;i <= 32;i++){
        printf("\\0x%x ",arr[i]);
        printf("%c \n",arr[i]);
    }
    printf("\n\n");

    /*执行复制，如果c 长度超过8，则出现缓冲区溢出*/
    // strcpy(arr, c);
    strncpy(arr, c, 8);
    // strncpy(arr,c,sizeof(arr));
    for(int i = 0;i <= 32;i++){
        printf("\\0x%x ",arr[i]);
        printf("%c \n",arr[i]);
    }
    printf("\n");
    printf("\n");

    system("pause");
    return 0;
}