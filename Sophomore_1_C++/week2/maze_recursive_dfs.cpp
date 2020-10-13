/*
Filename		:maze_recursive_dfs.cpp
Date			:2020/09/24 20:45:01
Author			:ZZC
Description     :
*/
#include <iostream>
#include <deque>
#include <vector>
using namespace std;


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
        size_t min_size = 88888;
        size_t min_index = 0;
        deque<Node> curr_path;              //存储当前路径
        vector<deque<Node>> all_path;       //存储所有路径
        Node my_start;                      //入口
        Node my_end;                        //出口
        static int myMaze[7][13];           //迷宫矩阵
        static Node offset[4];              //偏移量

        void searchPath(deque<Node>& path, const Node& start, const Node& end){
            if(start.x == end.x && start.y == end.y){
                all_path.push_back(curr_path);
                return;
            }
            for(int i = 0;i < 4;i++){
                Node nextNode = start + offset[i];
                if(mv_to_next(start, nextNode)){
                    // myMaze[nextNode.x][nextNode.y] = (nextNode.x == end.x && nextNode.y ==end.y) ? 0 : 1;
                    myMaze[nextNode.x][nextNode.y] = 1;
                    path.push_back(nextNode);
                    searchPath(path,nextNode,end);
                    myMaze[(*path.rbegin()).x][(*path.rbegin()).y] = 0;
                    path.pop_back();
                }
            }
        }
        bool mv_to_next(const Node& start, const Node& next){
            int x = next.x;
            int y = next.y;
            if(x < 0 || x >= 7 || y < 0 || y >= 13 || myMaze[x][y] == -1)
                return false;
            if(myMaze[x][y] == 0)
                return true;
            else
                return false;
        }

    public:
        Maze(size_t start_x, size_t start_y, size_t end_x, size_t end_y):
        my_start(Node(start_x, start_y)), my_end(Node(end_x, end_y)){
            myMaze[start_x][start_y] = 0;
        }
        // ~Maze();
        void searchPath(){
            searchPath(curr_path,my_start, my_end);
        }
        void print_allPath(){
            cout << "The maze has " << all_path.size() << " ways" << endl;
            cout << "The shortest path: ";
            for(size_t i = 0;i < all_path.size();i++){
                if(all_path[i].size() < min_size){
                    min_index = i;
                    min_size = all_path[i].size();
                }
            }
            cout << "(" << my_start.x + 1 << "," << my_start.y + 1 << ") ";
            while(!all_path[min_index].empty()){
                cout << "(" << all_path[min_index].front().x + 1
                    << "," << all_path[min_index].front().y + 1 << ") ";
                    all_path[min_index].pop_front();
            }
            cout << endl;
            int count = 1;
            for(size_t i = 0;i < all_path.size();i++){
                if(all_path[i].empty())
                    continue;
                cout << "Path" << (count++) << " " << "(" << my_start.x + 1 << "," << my_start.y + 1 << ") ";
                while(!all_path[i].empty()){
                    cout << "(" << all_path[i].front().x + 1
                    << "," << all_path[i].front().y + 1 << ") ";
                    all_path[i].pop_front();
                }
                cout << endl;
            }
        }
        void show_maze(){
            cout << "AAIAAAAAAAAAA" << endl;
            cout << "AA AA     AAA" << endl;
            cout << "A     A A   A" << endl;
            cout << "AAA AA   AA A" << endl;
            cout << "AA      AA  A" << endl;
            cout << "A  AAAA    AA" << endl;
            cout << "AAAAAAAAAAOAA" << endl;
        }

};

int Maze::myMaze[][13] = {
    {-1, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {-1, -1, 0, -1, -1,  0,  0,  0,  0,  0, -1, -1, -1},
    {-1,  0, 0,  0,  0,  0, -1,  0, -1,  0,  0,  0, -1},
    {-1, -1, -1, 0, -1, -1,  0,  0,  0, -1, -1,  0, -1},
    {-1, -1, 0,  0,  0,  0,  0,  0, -1, -1,  0,  0, -1},
    {-1,  0, 0, -1, -1, -1, -1,  0,  0,  0,  0, -1, -1},
    {-1, -1,-1, -1, -1, -1, -1, -1, -1, -1,  0, -1, -1}
};
Maze::Node Maze::offset[4]= {Node(0,1), Node(1,0), Node(0,-1), Node(-1,0)};

int main(){
    Maze my_maze(0,2,6,10);
    my_maze.show_maze();
    cout << endl;
    my_maze.searchPath();
    my_maze.print_allPath();
    system("pause");
    return 0;
}
