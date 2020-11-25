#include<iostream>
#include<algorithm>
#include <climits>
using namespace std;
const int N = 100;
int minn = INT_MAX, matrix[N][N];
int vis[N];
int n;

void traceback(int x, int tempCost) //x代表第几份工作 s代表当前工作费用
{
    if (x > n)
    {
        minn = min(minn, tempCost);
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            vis[i] = 1;
            if (tempCost + matrix[x][i] < minn)//剪枝
            {
                traceback(x + 1, tempCost + matrix[x][i]);
            }
            vis[i] = 0;//回溯
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cin >> matrix[i][j];
    }
    traceback(1, 0);
    cout << minn << endl;
    system("pause");
    return 0;
}
