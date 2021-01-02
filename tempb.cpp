#include<iostream>
#include<string>
#include<vector>
#include<set>
using namespace std;
vector<vector<int>>G(501);
int color[501] = { 0 };
bool check(int V)
{
    for (int i = 1; i <= V; i++)
        for (int j = 0; j < G[i].size(); j++)
            if (color[i] == color[G[i][j]])//当前颜色和相邻颜色是否相同
                return false;
    return true;
}
int main()
{
    int V, E, K, N;
    cin >> V >> E >> K;
    for (int i = 0; i < E; i++)
    {
        int start, end;
        cin >> start >> end;
        G[start].push_back(end);
        G[end].push_back(start);
    }
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        set<int>color_kind;
        for (int j = 1; j <=V; j++)
        {
            cin >> color[j];
            color_kind.insert(color[j]);
        }
        if (check(V) && color_kind.size() == K)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    system("pause");
    return 0;
}