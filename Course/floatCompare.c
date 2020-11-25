#include<stdio.h>
const double eps = 1e-8;
int main()
{
    double i = 0.1;
    double j = 0.2;
    printf("i = %.20lf\n",i);
    printf("j = %.20lf\n",j);

    if(i + j == 0.3)
        printf("True");
    else 
        printf("False");
  return 0;
}