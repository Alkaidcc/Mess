#include<iostream>
#include<climits>
using namespace std;
#define MaxVertexNum 100    
#define INFINITY 65535      
typedef int Vertex;         
typedef int WeightType;       
typedef char DataType;        

typedef struct ENode{
    Vertex V1, V2;      
    WeightType Weight;  
}ENode, *PtrToENode;
typedef PtrToENode Edge;
        
typedef struct GNode{
    int NumOfVertex = 0;
    int NumOfEdge = 0;
    WeightType G[MaxVertexNum][MaxVertexNum]; 
    DataType Data[MaxVertexNum];      
    
}GNode, *PtrToGNode;
typedef PtrToGNode MGraph; 
 
bool visited[MaxVertexNum] = {false};
 //function prototype
void CreateDirectedGraph(MGraph& Graph);
bool InsertEdge( MGraph Graph, int v1, int v2, WeightType weight);
bool InsertVertex(MGraph Graph, DataType vertex);
int LocateVex(MGraph Graph, DataType vertex);
void OutPutGraph(MGraph Graph);

void CreateDirectedGraph(MGraph& Graph)
{ 
    DataType v1, v2;
    WeightType weight;
    Graph = new GNode; 
    int VertexNum, EdgeNum;
    cout << "Please input the numbers of Vertex and Edge:" << endl;
    cin >> VertexNum >> EdgeNum;
    Graph->NumOfVertex = VertexNum;
    Graph->NumOfEdge = EdgeNum;
    cout << "Please input the Vertex:" <<  endl;
    for (int i = 0; i < Graph->NumOfVertex; i++){
        cin >> Graph->Data[i];
    }
    for(int i = 0;i < VertexNum;i++) {
        for(int j = 0; j < VertexNum;j++) {
            Graph->G[i][j] = (i == j) ? 0 : INFINITY;
        }
    }
    cout << "Please input the Edge and Weight:(v1 v2 weight)" << endl;
    int i = 0;
    while(i < Graph->NumOfEdge) {
        cin >> v1 >> v2 >> weight;
        int m = LocateVex(Graph, v1);
        int n = LocateVex(Graph, v2);
        if(m == -1 || n == -1) {
            cout << "ERROR! Please enter again!" << endl;
        }else {
            if(InsertEdge(Graph, m, n, weight)) {
                i++;
            }
        }

    }
}
        
bool InsertEdge( MGraph Graph, int v1, int v2, WeightType weight) {
    if(v1 > -1 && v1 < Graph->NumOfVertex && v2 > -1 && v2 < Graph->NumOfVertex) {
        if(Graph->G[v1][v2] == INFINITY) {
            Graph->G[v1][v2] = weight;
            return true;
        }else {
            cout << "The Edge has been existed." << endl;
            return false;
        }
    }else {
        return false;
    }
}
bool InsertVertex(MGraph Graph, DataType vertex) {
    if(Graph->NumOfVertex == MaxVertexNum) {
        return false;
    }
    Graph->Data[Graph->NumOfVertex++] = vertex;
    return true;
}
 
int LocateVex(MGraph Graph, DataType vertex) {
    for(int i = 0;i < Graph->NumOfVertex;i++) {
        if(Graph->Data[i] == vertex) {
            return i;
        }
    }
    return -1;
}
void OutPutGraph(MGraph Graph) {
    int i,j;
    cout << "The number of Edges : ";
    cout << Graph->NumOfEdge << endl;
    cout << "The number of Vertex: ";
    cout << Graph->NumOfVertex << endl;
    cout << "The sides are in order:" << endl;
    for(i =0;i < Graph->NumOfVertex;i++) {
        for(j = 0;j < Graph->NumOfVertex;j++) {
            if(Graph->G[i][j] != INFINITY && Graph->G[i][j] != 0) {
                cout << "<" << Graph->Data[i] << "," << Graph->Data[j] << "," << Graph->G[i][j] << ">" << endl;
            }
        } 
    }
}
void ShortestPath_DIJ(MGraph Graph, int v0) {
    //初始化
    bool S[MaxVertexNum];   //集合
    int D[MaxVertexNum];    //最短路径
    int path[MaxVertexNum];//前驱结点
    int w, v;
    int n = Graph->NumOfVertex;     //顶点个数
    for(int i = 0;i < n;i++) {
        path[i] = i;
    }
    for(v = 0;v < n;v++) {
        S[v] = false;
        D[v] = Graph->G[v0][v];
        if(D[v] < INFINITY) {     //如果v0和v之间有弧，则将v的前驱置为v0
            path[v] = v0;
        }else {
            path[v] = -1;
        }
    }
    S[v0] = true;
    D[v0] = 0;

    for(int i = 1;i < n;i++) {  //对n-1个顶点计算
        int min = INFINITY;
        for(w = 0;w < n;w++) {
            
            if(!S[w] && D[w] < min) {   //选择一条当前的最短路径，终点为V
                v = w;
                min = D[w];
            }
        }
        S[v] =true; //将V加入S
        for(int w =0;w < n;w++) {       //更新从V0出发到集合V-S上所有顶点的最短路径
            if(!S[w] && D[v] + Graph->G[v][w] < D[w]) {
                D[w] = D[v] + Graph->G[v][w];       //更新路径
                path[w] = v;        //更改前驱
            }
        }
    }
    cout << "Dijkstra:" << Graph->Data[v0] << endl;
    for(int i = 0;i < Graph->NumOfVertex;i++) {
        cout << "shortest ( " << Graph->Data[v0] << "," << Graph->Data[i] << ") = " << D[i] << endl;
    }

}




int main() {
    MGraph Graph;
    CreateDirectedGraph(Graph);
    ShortestPath_DIJ(Graph, 0);
    // OutPutGraph(Graph);
    system("pause");
    return 0;
}