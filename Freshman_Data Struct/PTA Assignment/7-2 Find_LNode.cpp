//7-2 列出叶结点
#include<iostream>
#include<queue>
#include<string>
using namespace std;
const int MAXN = 15;
typedef struct Node {
    int num;
    int lchild;
    int rchild;
}Node;

Node T[MAXN];
int judge[MAXN] = {0};
//function prototype
int CreateTree();

int main() {
    int root = CreateTree();
    queue<Node> q;
    q.push(T[root]);
    int pr = 0;
    while(!q.empty()) {
        Node temp = q.front();
        q.pop();
        if(temp.lchild == -1 && temp.rchild == -1) {     //没有左右孩子
            if(pr == 0) {
                printf("%d",temp.num);
                pr = 1;
            }else {
                printf(" %d",temp.num);
            }
        }
        if(temp.lchild != -1) { //左孩子不为空
            q.push(T[temp.lchild]);
        }
        if(temp.rchild != -1) { //右孩子不为空
            q.push(T[temp.rchild]);
        }
    }
    system("pause");
    return 0;
}

int CreateTree() {  //建树 返回root
    int N;
    string lch,rch;
    cin >> N;
    for(int i = 0;i < N;i++) {
        cin >> lch >> rch;
        T[i].num = i;
        if(lch == "-") {
            T[i].lchild = -1;
        }else {
            T[i].lchild = atoi(lch.c_str());
            judge[T[i].lchild] = 1;
        }
        if(rch == "-") {
            T[i].rchild = -1;
        }else {
            T[i].rchild = atoi(rch.c_str());
            judge[T[i].rchild] = 1;
        } 
    }
    //找根结点
    int root = -1;
    for(int i = 0;i < N;i++) {
        if(judge[i] != 1) {
            root = i;
            break;
        }
    }
    return root;
}