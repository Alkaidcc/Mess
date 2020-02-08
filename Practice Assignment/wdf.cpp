#include <stdio.h>
#include <math.h>
int main()
{
    int n, i, j, k = 0;
    int a[100];
    int sum = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i++)
    {
        k = a[i];
        sum = 0;
        for (j = 0; j < 5; j++)
        {
            sum += pow((a[i] % 10), 5);
            a[i] /= 10;
        }
        if (sum == k)
            printf("YES\n");
        else if (sum != k)
            printf("NO\n");
        /*else if(sum==k&&i==n-1)
printf("YES");
else if(sum!=k&&i==n-1)
printf("NO");*/
    }
    return 0;
}