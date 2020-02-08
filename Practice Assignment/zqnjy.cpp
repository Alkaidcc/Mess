#include <stdio.h>
int main()
{
    int n,m,j,h,b[101][101],i,max,maxx,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        int count=0;
        int a[101]={0};
        scanf("%d",&m);
        for(j=0;j<m;j++)
            for(h=0;h<m;h++)
            scanf("%d",&b[j][h]);
        for(j=0;j<m;j++)
            for(h=0;h<m;h++)
            {
                if(b[j][h]>b[h][j])
                {
                    a[j]+=3;
                }
                if(b[j][h]<b[h][j])
                {
                    a[h]+=3;
                }
                if(b[j][h]==b[h][j])
                {
                    a[j]++;
                    a[h]++;
                }
            }
        max=a[0];maxx=0;
        for(k=0;k<m;k++)
        {
            if(max<a[k])
            {
                max=a[k];
                maxx=k;
            }
        }
        for(k=0;k<m;k++)
        {
            if(max==a[k])
            {
                count++;
            }
        }
        if(count==1) printf("%d\n",maxx+1);
        else printf("找不出最强球队！\n");
    }
    return 0;
}
