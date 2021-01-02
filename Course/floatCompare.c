#include<stdio.h>
#include<iostream>
const double eps = 1e-8;
int main()
{
    double i = 0.1;
    double j = 0.2;
    printf("i = %.20lf\n",i);
    printf("j = %.20lf\n",j);

    if(i + j == 0.3){
        printf("True\n");
    }
    else{ 
        printf("False\n");
    }
    if(i + j - 0.3 < eps){
        printf("i+j==0.3\n");
    }else{
        printf("i+j!=0.3\n");
    }
    system("pause");
    return 0;
}