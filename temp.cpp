#include <iostream>
#include <deque>
#include <vector>
using namespace std;
const int N = 8;

class Maze{
    private:
        class Node{
            public:
                int x;
                int y;
                Node(int a = 0, int b = 0):x(a), y(b){}
                // ~Node();
                Node operator+ (const Node& other)const{
                    Node node;
                    node.x = x + other.x;
                    node.y = y + other.y;
                    return node;
                }
        };
        deque<Node> path;
        deque<Node> result;      
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

        void searchPath(deque<Node>& path, const Node& start, const Node& end){
            if(start.x == end.x && start.y == end.y){
                for(int i = 0;i < path.size();i++){
                    result.push_back(path[i]);
                }
                return;
            }
            for(int i = 0;i < 4;i++){
                Node nextNode = start + offset[i];
                if(mv_to_next(start, nextNode)){
                    myMaze[nextNode.x][nextNode.y] = '1';
                    path.push_back(nextNode);
                    searchPath(path,nextNode,end);
                    myMaze[(*path.rbegin()).x][(*path.rbegin()).y] = 'O';
                    path.pop_back();
                }
            }
        }
        bool mv_to_next(const Node& start, const Node& next){
            int x = next.x;
            int y = next.y;
            if(x < 0 || x >= N || y < 0 || y >= N || myMaze[x][y] == 'X')
                return false;
            if(myMaze[x][y] == 'O')
                return true;
            else
                return false;
        }

    public:
        Maze(int s_x,int s_y, int e_x, int e_y);
        void searchPath(){
            searchPath(path, my_start, my_end);
        }
        void updatePath(){
            myMaze[my_start.x][my_start.y] = '1';
            for(size_t i = 0;i < result.size();i++){
                myMaze[result[i].x][result[i].y] = '1';
            }
        }
        void show_maze(){
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
