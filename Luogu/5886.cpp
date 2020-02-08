#include<bits/stdc++.h>
using namespace std;
int c[1000001],t,s[1000001],sum,d;
int main()
{
    int n,m,p;
    cin>>n>>m>>p;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&t);
        while(t--)
        {
            scanf("%d",&d);
            c[d]++;
        }
    }
    for(int i=1;i<=m;i++)
    if(c[i]==p)
    {
        s[sum]=i;
        sum++;
    }
    printf("%d\n",sum);
    sort(s,s+sum);
    for(int i=0;i<sum;i++)
    printf("%d ",s[i]);
    printf("\n");
    system("pause");
    return 0;
}