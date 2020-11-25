#include <iostream>
#include <queue>
#include <deque>
using namespace std;
#define INF 0x3f3f3f3f //表示∞
#define MAXN 10
int n = 8;             //图顶点个数
int a[MAXN][MAXN] = {   //图的邻接矩阵
                        {INF, INF, INF, INF, INF, INF, INF, INF, INF},
                        {INF,  0,   1,   4,   4,  INF, INF, INF, INF},
                        {INF, INF,  0,   2,  INF,  9,  INF, INF, INF},
                        {INF, INF, INF,  0,   3,   6,   3,   4,  INF},
                        {INF, INF, INF, INF,  0,  INF, INF,  7,  INF},
                        {INF, INF, INF, INF, INF,  0,  INF, INF,  1},
                        {INF, INF, INF, INF, INF,  1,   0,  INF,  5},
                        {INF, INF, INF, INF, INF, INF,  2,   0,   3},
                        {INF, INF, INF, INF, INF, INF, INF, INF,  0}
                    }; 
int v;             //源点
//求解结果表示
int dist[MAXN]; //dist[i]源点到顶点i的最短路径长度
int pre[MAXN]; //pre[i]表示源点到i的最短路径中顶点i的前驱顶点
typedef struct NodeType //队列结点类型
{
    int vno;    //顶点编号
    int length; //路径长度
}NodeType;

void bfs(int v) //求解算法
{
    NodeType e, e1;
    queue<NodeType> pqu;
    e.vno = v; //建立源点结点e（根结点）
    e.length = 0;
    pqu.push(e); //源点结点e进队
    dist[v] = 0;
    while (!pqu.empty()) //队列不空循环
    {
        e = pqu.front();
        pqu.pop(); //出队列结点e
        for (int j = 1; j <= n; j++)
        {
            if (a[e.vno][j] < INF && e.length + a[e.vno][j] < dist[j])  //搜索与该顶点联通的点
            { //剪枝：e.vno到顶点j有边并且路径长度更短
                dist[j] = e.length + a[e.vno][j];
                pre[j] = e.vno;
                e1.vno = j; //建立相邻顶点j的结点e1
                e1.length = dist[j];
                pqu.push(e1); //结点e1进队
            }
        }
    }
}

int main(){
    for(int i = 1;i <= n;i++){
        dist[i] = INF;
    }
    bfs(1);
    cout << "最短路径长度为：" << dist[n] << endl;
    deque<int> result;
    int temp = 8;
    while(temp != 0){
        result.push_front(temp);
        temp = pre[temp];
    }
    for(int i = 0;i < result.size();i++){
        if(i == result.size() - 1){
            cout << result[i];
        }else{
            cout << result[i] << "->";
        }
    }
    system("pause");
    return 0;
}