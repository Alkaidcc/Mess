#include <iostream>
#include <queue>
#include <deque>
using namespace std;
#define INF 0x3f3f3f3f //��ʾ��
#define MAXN 10
int n = 8;             //ͼ�������
int a[MAXN][MAXN] = {   //ͼ���ڽӾ���
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
int v;             //Դ��
//�������ʾ
int dist[MAXN]; //dist[i]Դ�㵽����i�����·������
int pre[MAXN]; //pre[i]��ʾԴ�㵽i�����·���ж���i��ǰ������
typedef struct NodeType //���н������
{
    int vno;    //������
    int length; //·������
}NodeType;

void bfs(int v) //����㷨
{
    NodeType e, e1;
    queue<NodeType> pqu;
    e.vno = v; //����Դ����e������㣩
    e.length = 0;
    pqu.push(e); //Դ����e����
    dist[v] = 0;
    while (!pqu.empty()) //���в���ѭ��
    {
        e = pqu.front();
        pqu.pop(); //�����н��e
        for (int j = 1; j <= n; j++)
        {
            if (a[e.vno][j] < INF && e.length + a[e.vno][j] < dist[j])  //������ö�����ͨ�ĵ�
            { //��֦��e.vno������j�б߲���·�����ȸ���
                dist[j] = e.length + a[e.vno][j];
                pre[j] = e.vno;
                e1.vno = j; //�������ڶ���j�Ľ��e1
                e1.length = dist[j];
                pqu.push(e1); //���e1����
            }
        }
    }
}

int main(){
    for(int i = 1;i <= n;i++){
        dist[i] = INF;
    }
    bfs(1);
    cout << "���·������Ϊ��" << dist[n] << endl;
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