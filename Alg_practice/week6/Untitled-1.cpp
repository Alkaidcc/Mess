#include <iostream>
using namespace std;

int n = 4;
int c[MAXN][MAXN] = {{0}, {0, 9, 2, 7, 8}, {0, 6, 4, 3, 7}, {0, 5, 8, 1, 8}, {0, 7, 6, 9, 4}};
int x[MAXN];       //��ʱ��
int cost = 0;      //��ʱ��ĳɱ�
int bestx[MAXN];   //���Ž�
int mincost = INF; //���Ž�ĳɱ�
bool worker[MAXN]; //worker[j]��ʾ����j�Ƿ��Ѿ�������Ա

void dfs(int i) //Ϊ��i����Ա��������
{
    if (i > n) //����Ҷ�ӽ��
    {
        if (cost < mincost) //�Ƚ������Ž�
        {
            mincost = cost;
            for (int j = 1; j <= n; j++)
                bestx[j] = x[j];
        }
    }
    else
    {
        for (int j = 1; j <= n; j++) //Ϊ��Աi��̽����j:1��n
            if (!worker[j])          //������j��û�з���
            {
                worker[j] = true;
                x[i] = j; //����j�������Աi
                cost += c[i][j];
                dfs(i + 1);        //Ϊ��Աi+1��������
                worker[j] = false; //����
                x[j] = 0;
                cost -= c[i][j];
            }
    }
}