#include <stdio.h>

int main(){
    //定义一个int变量a和一个指向int的指针p
    //让p指向a的地址
    int a = 1;
    int *p;
    p = &a;     //定义指针变量后对它初始化
    printf("Address of p: %p\n",&p);
    printf("Value of p: %p\n",p);
    printf("Address of a: %p\n",&a);
    printf("Value of *p: %d\n",*p);
    printf("Value of a: %d\n",a);
    printf("sizeof(int): %d\n",sizeof(a));
    printf("sizeof(int*): %d\n",sizeof(p));
    //定义一个指向b地址的指针q
    int b = 2;
    int* q = &b;    //定义指针变量时对它进行初始化，即定义时初始化
    printf("Address of q: %p\n",q);
    printf("Value of *q and b: %d\n",*q);
    //定义一个int类型的指针，然后将q赋值给j
    //q存储的是b的地址，所以此时j存储的也是b的地址
    int* j = p;
    printf("Address : %p\n",j);
    printf("Value: %d\n",*j);
    printf("Address: %p\n",&j);

    return 0;
}