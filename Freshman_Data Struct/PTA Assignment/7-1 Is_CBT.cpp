//是否为完全二叉搜索树
#include<iostream>
#include<queue>
using namespace std;

typedef struct BinNode {
    int data;
    struct BinNode* lchild;
    struct BinNode* rchild;
}BinNode,*BinTree;

//function prototype
void CreateBinTree(BinTree& BST);
void CreateBinTree(BinTree& BST, int value);
BinTree Insert(BinTree& BST, int value);
bool LevelTraverse(const BinTree BST);


int main() {
    BinTree BST;
    int N,temp;
    cin >> N;
    cin >> temp;
    CreateBinTree(BST,temp);
    for(int i =0;i < N-1;i++) {
        int num;
        cin >> num;
        Insert(BST,num);
    }
    bool judge = LevelTraverse(BST);
    cout << endl;
    if(judge) {
        printf("YES");
    }else {
        printf("NO");
    }
    system("pause");
    return 0;
}

void CreateBinTree(BinTree& BST) {
    BST = new BinNode;
    BST->lchild = NULL;
    BST->rchild = NULL;
}
void CreateBinTree(BinTree& BST, int value) {
    BST = new BinNode;
    BST->data = value;
    BST->lchild = NULL;
    BST->rchild = NULL;
}


BinTree Insert(BinTree& BST, int value) {
    if(!BST) {
        BST = new BinNode;
        BST->lchild = NULL;
        BST->rchild = NULL;
        BST->data = value;
    }else {
        if(value < BST->data) {
            BST->rchild = Insert(BST->rchild, value);
        }else {
            BST->lchild = Insert(BST->lchild, value);
        }
    }
    return BST;
}
bool LevelTraverse(const BinTree BST) {
    if(!BST) {
        return false;
    }
    queue<BinTree> q;
    int pr = 0;
    int flag =1;
    q.push(BST);
    while(!q.empty()) {
        if(q.front()->lchild && q.front()->rchild) {    //左右孩子都存在
            if(flag == 2) { //之前已经有结点没有右孩子
                flag = 0;   //不是CBT
            }
            q.push(q.front()->lchild);
            q.push(q.front()->rchild);
        }
        else if(!(q.front()->lchild) && q.front()->rchild) {//无左孩子有右孩子
            flag = 0;   //不是CBT
            q.push(q.front()->rchild);
        }
        else if(q.front()->lchild && !(q.front()->rchild)) {//无右孩子有左孩子
            if(flag == 2) { //如果之前已经存在没有右孩子的结点
                flag = 0;   //不是CBT
            }
            if(flag == 1) { //如果还未判断
                flag =2;    //标记为存在没有右孩子的结点
            }
            q.push(q.front()->lchild);
        }
        else {  //无左右孩子
            if(flag == 1) { //如果还未判断
                flag = 2;   //标记为存在没有右孩子的结点
            }
        }
        if(pr == 0) {
            printf("%d",q.front()->data);
            pr = 1;
        }else {
            printf(" %d",q.front()->data);
        }
        q.pop();
    }
    return (flag == 0) ? false : true;
}