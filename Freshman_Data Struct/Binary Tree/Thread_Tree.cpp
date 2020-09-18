#include<iostream>
using namespace std;
typedef char ElemType;
typedef enum PointerTag {Link, Thread};
//0是指针 1是线索
typedef struct ThreadNode {
    ElemType data;
    ThreadNode *lchild, *rchild;
    PointerTag LTag,RTag;
    Thr_BiTNode(const ElemType value):data(value),lchild(NULL), 
    rchild(NULL), LTag(Link), RTag(Link) {}
};

class ThreadTree {
    private:
        ThreadNode* root;
        ElemType RefValue;


    public:
    //构造函数
        ThreadTree():root(NULL) {}

    //指定结束标志RefValue的构造函数
        ThreadTree(ElemType value):RefValue(value), root(NULL) {}

    //使用前序遍历创建二叉树(未线索化)
        void CreateTree() {
            CreateTree(root);
        }

    //中序遍历对创建好的二叉树进行中序线索化
        void CreateInThread() {
            ThreadNode* pre = NULL;     //第一个结点的左子树置空
            if(root != NULL) {
                CreateInThread(root,pre);
                //处理中序遍历的最后一个结点，最后一个结点的右子树置为空
                pre->rchild = NULL;
                pre->RTag = Thread;
            }
        }

    //线索化二叉树上执行遍历的算法
        void InOrderTraverse() {
            InOrderTraverse(root);
        }

        void PostOrderTraverse() {
            PostOrderTraverse(root);
        }

        void PreOrderTraverse() {
            PreOrderTraverse(root);
        }


    private:

        void CreateInThread(ThreadNode* current, ThreadNode* &pre) {
            if(current == NULL) {
                return;
            }
            CreateInThread(current->lchild, pre);        //递归左子树线索化
            if(current->lchild == NULL) {       //建立当前节点的前驱节点
                current->lchild = pre;
                current->LTag = Thread;
            }
            pre = current;      //用前驱记住当前节点
            CreateInThread(current->rchild, pre);
        }




}