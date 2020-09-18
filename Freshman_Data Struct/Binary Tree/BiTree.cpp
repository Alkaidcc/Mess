#include<iostream>
using namespace std;
typedef int ElemType;
typedef struct node {
    ElemType data;
    struct node* lchild;
    struct node* rchild;
}BiTNode,*BiTree;

void CreateBiTree(BiTree& T);
void Copy(BiTree T,BiTree& NewT);
int Depth(const BiTree T);
int NodeCount(BiTree T);
int main() {



    system("pause");
    return 0;

}

void CreateBiTree(BiTree& T) {
    ElemType ch;
    cin >> ch;
    if(ch == '#') {
        T = NULL;
    }else {
        T = new BiTNode;
        T->data = ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}

void Copy(BiTree T,BiTree& NewT) {
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

int Depth(const BiTree T) {
    int lh,rh;
    if(T == NULL) {
        return 0;
    }else {
        lh = Depth(T->lchild);
        rh = Depth(T->rchild);
        return m > n ? (m+1) : (n+1);
    }
}

int NodeCount(BiTree T) {
    if(T == NULL) {
        return 0;
    }else {
        return NodeCount(T->lchild)+NodeCount(T->rchild)+1;
    }
}