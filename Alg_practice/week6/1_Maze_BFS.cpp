#include <iostream>
#include <deque>
#include <vector>
using namespace std;
const int N = 8;

class Maze{
    private:
        class Node{ //定义点类
            public:
                int x;
                int y;
                Node(int a = 0, int b = 0):x(a), y(b){}
                Node operator+ (const Node& other)const{
                    Node node;
                    node.x = x + other.x;
                    node.y = y + other.y;
                    return node;
                }
        };
        deque<Node> path;   //用于存储dfs时遇到的可行点
        deque<Node> result; //找到出口后用于记录路线
        Node my_start; 
        Node my_end;                                            
        vector<vector<char>> myMaze = {
            {'O','X','X','X','X','X','X','X'},
            {'O','O','O','O','O','X','X','X'},
            {'X','O','X','X','O','O','O','X'},
            {'X','O','X','X','O','X','X','O'},
            {'X','O','X','X','X','X','X','X'},
            {'X','O','X','X','O','O','O','X'},
            {'X','O','O','O','O','X','O','O'},
            {'X','X','X','X','X','X','X','O'}
        };           
        static Node offset[4];
        Node pre[N][N];   //用于存储任意节点的前一个结点位置
                   

        void searchPath(vector<vector<char>> myMaze,deque<Node> path, const Node& start, const Node& end){
            Node tempN;
            path.push_back(start);
            myMaze[start.x][start.y] = '1';
            while(!path.empty()){
                tempN = path.front();
                path.pop_front();
                for(int i = 0;i < 4;i++){
                    if((tempN + offset[i]).x == my_end.x && (tempN + offset[i]).y == my_end.y){
                        pre[my_end.x][my_end.y] = tempN;
                        return;
                    }
                    Node nextNode = tempN + offset[i];
                    if(mv_to_next(myMaze, tempN, nextNode)){
                        path.push_back(nextNode);
                        myMaze[nextNode.x][nextNode.y] = '1';
                        pre[nextNode.x][nextNode.y] = tempN;
                    }
                }
            }
            

        }
        bool mv_to_next(vector<vector<char>>& myMaze,const Node& start, const Node& next){   //用于判断是否能走到下一个点
            int x = next.x;
            int y = next.y;
            if(x < 0 || x >= N || y < 0 || y >= N || myMaze[x][y] == 'X' || myMaze[x][y] == '1')
                return false;
            if(myMaze[x][y] == 'O')
                return true;
            else
                return false;
        }

    public:
        Maze(int s_x,int s_y, int e_x, int e_y);
        void searchPath(){
            searchPath(myMaze, path, my_start, my_end);
        }
        void updatePath(){  //根据路径更新整个迷宫
            Node temp;
            temp.x = my_end.x;
            temp.y = my_end.y;
            while(temp.x != my_start.x || temp.y != my_start.y){
                result.push_back(temp);
                temp = pre[temp.x][temp.y];
            }
            myMaze[my_start.x][my_start.y] = '1';
            for(size_t i = 0;i < result.size();i++){
                myMaze[result[i].x][result[i].y] = '1';
            }
        }
        void show_maze(){//打印迷宫
            for(int i = 0;i < myMaze.size();i++){
                for(int j = 0;j < myMaze[0].size();j++){
                    cout << myMaze[i][j];
                }
                cout << endl;
            }       
        }
};


Maze::Maze(int s_x,int s_y, int e_x, int e_y){
    my_start = Node(s_x,s_y);
    my_end = Node(e_x,e_y);
    cout << "maze rows: " << N << ", cols: " << N << endl;
    show_maze();
}

Maze::Node Maze::offset[4]= {Node(0,1), Node(1,0), Node(0,-1), Node(-1,0)};

int main(){
    Maze my_maze(0,0,7,7);
    my_maze.searchPath();
    my_maze.updatePath();
    cout << "one path of the maze:" << endl;
    my_maze.show_maze();
    system("pause");
    return 0;
}
