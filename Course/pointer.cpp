#include <stdio.h>

int main(){
    //����һ��int����a��һ��ָ��int��ָ��p
    //��pָ��a�ĵ�ַ
    int a = 1;
    int *p;
    p = &a;     //����ָ������������ʼ��
    printf("Address of p: %p\n",&p);
    printf("Value of p: %p\n",p);
    printf("Address of a: %p\n",&a);
    printf("Value of *p: %d\n",*p);
    printf("Value of a: %d\n",a);
    printf("sizeof(int): %d\n",sizeof(a));
    printf("sizeof(int*): %d\n",sizeof(p));
    //����һ��ָ��b��ַ��ָ��q
    int b = 2;
    int* q = &b;    //����ָ�����ʱ�������г�ʼ����������ʱ��ʼ��
    printf("Address of q: %p\n",q);
    printf("Value of *q and b: %d\n",*q);
    //����һ��int���͵�ָ�룬Ȼ��q��ֵ��j
    //q�洢����b�ĵ�ַ�����Դ�ʱj�洢��Ҳ��b�ĵ�ַ
    int* j = p;
    printf("Address : %p\n",j);
    printf("Value: %d\n",*j);
    printf("Address: %p\n",&j);

    return 0;
}