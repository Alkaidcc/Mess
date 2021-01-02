#include <iostream>
#include <map>
using namespace std;
const int INF = 0x3f3f3f3f;
map<int,string> mmap;
int dist[10];   //��¼·����Сֵ
int path[10];   //��¼·��
int m[10][10] = {//�ڽӾ���
                        {INF,  2,   4,   3,  INF, INF, INF, INF, INF, INF},
                        {INF, INF, INF, INF,  7,   4,  INF, INF, INF, INF},
                        {INF, INF, INF, INF,  3,   2,   4,  INF, INF, INF},
                        {INF, INF, INF, INF,  6,   2,   5,  INF,  INF, INF},
                        {INF, INF, INF, INF, INF, INF, INF,  3,   4, INF},
                        {INF, INF, INF, INF, INF, INF, INF,  6,   3, INF},
                        {INF, INF, INF, INF, INF, INF,  INF, 3,   3, INF},
                        {INF, INF, INF, INF, INF, INF, INF,  INF,  INF, 3},
                        {INF, INF, INF, INF, INF, INF, INF, INF, INF, 4},
                        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF}
};
void findPath(){
    for(int i = 1; i < 10; i++){
            int k = INF;
            for (int j = 0; j < i; j++){
                if (m[j][i] != INF){        //���������ͨ
                    if ((dist[j] + m[j][i]) < k){   //���0-j�ľ���+��j-i���ľ���<k
                        k = dist[j] + m[j][i];      //����k
                    }
                }
            }
            dist[i] = k;        //ȫ��j��i�Ľ�������� ����0-i�ľ���
    }
}
int findRoute(){
    int j, b, k = 1, i = 9;
    path[0] = 10;
    while (i > 0)
    {
        for (j = i - 1; j >= 0; j--)
        {
            if (m[j][i] != INF)
            {
                b = dist[i] - m[j][i];
                if (b == dist[j])
                {
                    path[k++] = j + 1;
                    i = j;
                    break;
                }
            }
        }
    }
    return k;
}
int main(){
    mmap[1] = "A";
    mmap[2] = "B1";
    mmap[3] = "B2";
    mmap[4] = "B3";
    mmap[5] = "C1";
    mmap[6] = "C2";
    mmap[7] = "C3";
    mmap[8] = "D1";
    mmap[9] = "D2";
    mmap[10] = "E";
    findPath();
    cout << "���·����СΪ: " << dist[9] << endl;
    int m = findRoute();
    for(int i = m - 1;i >= 0;i--){
        if(i)cout << mmap[path[i]] << "->";
        else cout << mmap[path[i]];
    }
    system("pause");
    return 0;
}
