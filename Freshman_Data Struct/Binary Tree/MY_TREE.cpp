#include<iostream>
#include<cstdlib>
using namespace std;
typedef char ElemType; 
const int MAXTSIZE = 100;
typedef char TElemType;
typedef struct BiTNode {
    TElemType data;
    struct BiTNode *lchild, *rchild;
}BiTNode,*BinTree;

//function prototype
void Copy(BinTree T, BinTree& NewT);
BinTree InitTree(BinTree& T);
void CreateTree(BinTree& T);
bool TreeEmpty(const BinTree T);
int Depth(const BinTree T);
void InOrderTraverse(const BinTree T);
void PostOrderTraverse(const BinTree T);
void PreOrderTraverse(const BinTree T);
int NodeCount(BinTree T);

int main() {
    BinTree T;
    InitTree(T);
    CreateTree(T);
    cout << "PreOrder:";
    PreOrderTraverse(T);
    cout << endl;
    cout << "InOrder:";
    InOrderTraverse(T);
    cout << endl;
    cout << "PostOrder:";
    PostOrderTraverse(T);
    cout << endl;
    // cout << "there are " << NodeCount(T) << " nodes." << endl;
    system("pause");
    return 0;
}

BinTree InitTree(BinTree& T) {
    T = new BiTNode;
    T->lchild = NULL;
    T->rchild = NULL;
    return T;
}

void CreateTree(BinTree& T) {
    ElemType ch;
    cin >> ch;
    if(ch == '#') {     
        T = NULL;
    }else {
        T = new BiTNode;
        T->data = ch;
        CreateTree(T->lchild);
        CreateTree(T->rchild);
    }
}

void Copy(BinTree T, BinTree& NewT) {
    if(T == NULL) {     
        NewT = NULL;
        return;
    }else {
        NewT = new BiTNode;
        NewT->data = T->data;
        Copy(T->lchild,NewT->lchild);
        Copy(T->rchild,NewT->rchild);
    }
}

int Depth(const BinTree T) {
    int n,m;
    if(T == NULL) {
        return 0;
    }else {
        m = Depth(T->lchild);
        n = Depth(T->rchild);
        return m > n ? (m + 1) : (n + 1);
    }
}
bool TreeEmpty(const BinTree T) {
    return T == NULL ? true : false;
}

void InOrderTraverse(const BinTree T) {
    if(T) {
        InOrderTraverse(T->lchild);
        cout << T->data;
        InOrderTraverse(T->rchild);
    }else {
        return;
    }

}

void PreOrderTraverse(const BinTree T) {
    if(T) {
        cout << T->data;
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }else {
        return;
    }
    
}
void PostOrderTraverse(const BinTree T) {
    if(T) {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        cout << T->data;
    }else {
        return;
    }

}
int NodeCount(BinTree T) {
    if(T == NULL) {
        return 0;
    }else {
        return NodeCount(T->lchild)+NodeCount(T->rchild)+1;
    }
}