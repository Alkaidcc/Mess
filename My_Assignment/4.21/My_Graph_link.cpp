#include<iostream>
#include<climits>
#include<queue>
using namespace std;

#define INFINITY INT_MAX
#define MaxWeight INT_MAX
const int MaxVertexNum = 100;
typedef char DataType;
typedef int WeightType;
typedef int ElemType; 

typedef struct Vertex { //顶点定义
    DataType data;  //顶点的值
    struct Edge* adj = NULL;   //边链表的头指针
}Vertex;

/* 边的定义 */
typedef struct Edge{
    int adjvex;   //另一顶点位置
    WeightType Weight=0;  /* 权重 */
    struct Edge* next = NULL;
}Edge;

typedef struct {
    Vertex AdjList[MaxVertexNum];
    int NumOfVertex = 0,NumOfEdge = 0;
}ALGraph;
bool visited[MaxVertexNum] = {false};
//function prototype
void CreateUDG(ALGraph& G);
void DestoryGraph(ALGraph& G);
int FirstAdjVex(ALGraph G, int v);
int NextAdjVex(ALGraph G, int v, int w);
bool InsertVex(ALGraph& G, DataType vertex);
bool InsertEdge(ALGraph& G, int v1, int v2, WeightType w);
int LocateVex(ALGraph G, DataType v);
WeightType GetWeight(ALGraph G, int v1, int v2);
void OutPutGraph(ALGraph& G);

void CreateUDG(ALGraph& G) {
    int Nv,Ne;
    cout << "Please input the numbers of Vertex and Edge:" << endl;
    cin >> Nv >> Ne;    //输入顶点数和边数
    cout << "Please input the Vertex:" <<  endl;
    DataType v1, v2;
    WeightType weight;
    for(int i = 0;i < Nv;i++) {
        cin >> v1;
        InsertVex(G, v1);
    }
    cout << "Please input the Edge and Weight:(v1 v2 weight)" << endl;
    int i = 0;
    while(i < Ne) {
        cin >> v1 >> v2 >> weight;
        int m = LocateVex(G, v1);
        int n = LocateVex(G, v2);
        if(m == -1 || n == -1) {
            cout << "ERROR! Please enter again!" << endl;
        }else {
            if(InsertEdge(G, m, n, weight)) {
                i++;
            }
        }
    }
}
void DestoryGraph(ALGraph& G) {
    for(int i = 0;i < G.NumOfVertex;i++) {
        Edge* p = G.AdjList[i].adj;
        while(p != NULL) {
            G.AdjList[i].adj = p->next;
            delete p;
            p = G.AdjList[i].adj;
        }
    }
}

DataType GetVex(ALGraph G, int v) {
    return G.AdjList[v].data;
}
void PutVex(ALGraph& G, int v, DataType value) {
    G.AdjList[v].data = value;
}

int FirstAdjVex(ALGraph G, int v) {
    if (v != -1) {
        Edge* p = G.AdjList[v].adj;
        if(p != NULL) {
            return p->adjvex;
        }
    }
    return -1;
}

int NextAdjVex(ALGraph G, int v, int w) {
    if(v != -1) {
        Edge* p = G.AdjList[v].adj;
        while(p != NULL && p->adjvex != w) {
            p = p->next;
        }
        if(p != NULL && p->next != NULL) {
            return p->next->adjvex;
        }
    }
    return -1;
}

bool InsertVex(ALGraph& G, DataType vertex) {
    if(G.NumOfVertex == MaxVertexNum) {
        return false;
    }
    G.AdjList[G.NumOfVertex].data = vertex;
    G.NumOfVertex++;
    return true;
}
bool InsertEdge(ALGraph& G, int v1, int v2, WeightType w) {
    if(v1 >=0 && v1 < G.NumOfVertex && v2 >=0 && v2 < G.NumOfVertex) {
        Edge *p = G.AdjList[v1].adj;
        Edge* q;
        while(p != NULL && p->adjvex != v2) {
            p = p->next;
        }
        if(p != NULL) {
            cout << "The Edge has been existed." << endl;
            return false;
        }
        p = new Edge;
        q = new Edge;
        p->adjvex = v2;
        p->Weight = w;
        p->next = G.AdjList[v1].adj;
        G.AdjList[v1].adj = p;
        q->adjvex = v1;
        q->Weight = w;
        q->next = G.AdjList[v2].adj;
        G.AdjList[v2].adj = q;
        G.NumOfEdge++;
        return true;
    }
    return false;
}


int LocateVex(ALGraph G, DataType v) {
    for(int i = 0;i < G.NumOfVertex;i++) {
        if(v == G.AdjList[i].data) {
            return i;
        }
    }
    return -1;
}

WeightType GetWeight(ALGraph G, int v1, int v2) {
    if(v1 != -1 && v2 != -1) {
        Edge* p = G.AdjList[v1].adj;
        while (p != NULL && p->adjvex != v2) {
            p = p->next;
        }
        if(p != NULL) {
            return p->Weight;
        }
        
    }
    return 0;
}

void OutPutGraph(ALGraph& G) {

    cout << "The number of Edges : ";
    cout << G.NumOfEdge << endl;
    cout << "The number of Vertex: ";
    cout << G.NumOfVertex << endl;
    cout << "The sides are in order:" << endl;
    for(int i = 0;i < G.NumOfVertex;i++) {
        Edge* p = G.AdjList[i].adj;
        while(p != NULL) {
            cout << "<" << G.AdjList[i].data << "," << G.AdjList[p->adjvex].data << "," << p->Weight << ">" << endl;
            p = p->next;
        }
    }
}

void DFS(ALGraph G, int v) {
    int w;
    cout << G.AdjList[v].data << " ";
    visited[v] = true;
    for(w = FirstAdjVex(G, v);w >= 0;w = NextAdjVex(G, v, w)) {
        if(!visited[w]) {
            DFS(G, w);
        }
    }
}
void DFSTraverse(ALGraph G) {
    cout << "DFSTraverse: ";
    for(int i = 0;i < G.NumOfVertex;i++) {
        visited[i] = false;

    }
    for(int i = 0;i < G.NumOfVertex;i++) {
        if(!visited[i]) {
            DFS(G,i);
        }
    }
    cout << endl;

}
void BFSTraverse(ALGraph G) {
    cout << "BFSTraverse: ";
    queue<int> q;
    Edge* p;
    int t;
    for(int i = 0;i<G.NumOfVertex;i++) {
        visited[i] = false;
    }
    for(int i =0; i < G.NumOfVertex;i++) {
        if(!visited[i]) {
            visited[i] = true;
            cout << G.AdjList[i].data << " ";
            q.push(i);
            while(!q.empty()) {
                t = q.front();
                q.pop();
                for(p = G.AdjList[t].adj;p != NULL; p = p->next) {
                    if(!visited[p->adjvex]) {
                        cout << G.AdjList[p->adjvex].data << " ";
                        visited[p->adjvex] = true;
                        q.push(p->adjvex);
                    }
                }
            }
        }
    }
    cout << endl;
}

int main() {
    ALGraph G;
    CreateUDG(G);
    // OutPutGraph(G);
    DFSTraverse(G);
    BFSTraverse(G);
    system("pause");
    return 0;
}