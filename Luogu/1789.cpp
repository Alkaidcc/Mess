#include<stdio.h>
int a[10000][10000];
int main(){
    int n,m,k,i,j,x,y,o,p;
    scanf("%d %d %d",&n,&m,&k);
    while(m--){         //���
        scanf("%d %d",&x,&y);
        for(i=y-1;i<y+4;i++)    a[x+1][i]=1;    //����ʮ��
        for(i=x-1;i<x+4;i++)    a[i][y+1]=1;
        a[x][y]=1;      //�ĸ���
        a[x+2][y]=1;    
        a[x][y+2]=1;    
        a[x+2][y+2]=1;  
    }
    while(k--){         //өʯ
        scanf("%d %d",&o,&p);
        for(i=o-1;i<o+4;i++)
        for(j=p-1;j<p+4;j++)
        a[i][j]=1;
    }
    int cnt=0;
    for(i=2;i<n+2;i++)              //�����2��ʼ�������
        for(j=2;j<n+2;j++)
            if(a[i][j]==0)
                cnt++;
    printf("%d",cnt);
    return 0;

}