#include<iostream>
#include<cstdlib>
using namespace std;
typedef int ElemType;

class AVLNode {
    public:
        ElemType value;     //值
        int height;         //高度
        AVLNode* lchild;    //左孩子
        AVLNode* rchild;    //右孩子

        AVLNode(ElemType data, AVLNode* l, AVLNode* r):
            value(data), height(0), lchild(l), rchild(r) { }
};

class AVLTree {
    private:
        AVLNode* Root;
    public:
        //构造函数
        AVLTree():Root(NULL){

        }
        //析构函数
        ~AVLTree(){
            Destroy(Root);
        }
        //获得树高
        int height() {
            return height(Root);
        }
        int max(int a, int b) {
            return a > b ? a : b;
        }
        //先序遍历
        void PreOrderTraverse() {
            PreOrderTraverse(Root);
        }
        //中序遍历
        void InOrderTraverse() {
            InOrderTraverse(Root);
        }
        //后序遍历
        void PostOrderTraverse() {
            PostOrderTraverse(Root);
        }

        AVLNode* Search(ElemType key) {
            return Search(Root, key);
        }
        //查找最小节点，返回该结点的值
        ElemType minimum() {
            AVLNode *p = minimum(Root);
            if(p != NULL) {
                return  p->value;
            }
            return -1;  //空树 返回异常
        }
        //查找最大结点，返回该结点的值
        ElemType maximum() {
            AVLNode* p =maximum(Root);
            if(p != NULL) {
                return p->value;
            }
            return -1;
        }
        //将节点插入AVL树
        void Insert(ElemType key) {
            Insert(Root,key);
        }
        //从AVL树中删除结点
        void Delete(ElemType key) {
            AVLNode* temp;
            if((temp = Search(Root,key)) != NULL) {
                Root = Delete(Root,temp);
            }
        }
        //销毁AVL树
        void Destroy() {
            Destroy(Root);
        }




    private:
        //获得树高
        int height(AVLNode* tree) {
            if(tree != NULL) {
                return tree->height;
            }
            return 0;
        }
        //先序遍历
        void PreOrderTraverse(AVLNode* tree) {
            if(tree != NULL) {
                cout << tree->value << " ";
                PreOrderTraverse(tree->lchild);
                PreOrderTraverse(tree->rchild);
            }
        }
        //中序遍历
        void InOrderTraverse(AVLNode* tree) {
            if(tree != NULL) {
                InOrderTraverse(tree->lchild);
                cout << tree->value << " ";
                InOrderTraverse(tree->rchild);
            }
        }
        //后序遍历
        void PostOrderTraverse(AVLNode* tree) {
            if(tree != NULL) {
                PostOrderTraverse(tree->lchild);
                PostOrderTraverse(tree->rchild);
                cout << tree->value << " ";
            }
        }
        //查找最小节点，返回该结点的值
        AVLNode* minimum(AVLNode* tree) {
            if(tree == NULL) {
                return NULL;
            }
            while(tree->lchild != NULL) {
                tree = tree ->lchild;
            }
            return tree;
        }
        //查找最大结点，返回该结点的值
        AVLNode* maximum(AVLNode* tree) {
            if(tree == NULL) {
                return NULL;
            }
            while(tree->rchild != NULL) {
                tree = tree->rchild;
            }
            return tree;
        }
        //将节点插入AVL树
        AVLNode* Insert(AVLNode* &tree, ElemType key) {
            if(tree == NULL) {
                //创建结点
                tree = new AVLNode(key,NULL,NULL);
                if(tree == NULL) {
                    cout << "ERROR: create avltree node failed!" << endl;
                    return NULL;
                }
            }
            else if(key < tree->value) {    //插入到左子树
                tree->lchild = Insert(tree->lchild, key);
                //如果AVL树失衡，则进行调节
                if(height(tree->lchild) - height(tree->rchild) == 2) {
                    if(key < tree->lchild->value) {
                        tree = LeftLeftRotation(tree);
                    }else {
                        tree = LeftRightRotation(tree);
                    }
                }
            }
            else if(key > tree->value) {    //插入到右子树
                tree->rchild = Insert(tree->rchild, key);
                //如果AVL树失衡，则进行调节
                if(height(tree->rchild) - height(tree->lchild) == 2) {
                    if(key > tree->rchild->value) {
                        tree = RightRightRotation(tree);
                    }else {
                        tree = RightLeftRotation(tree);
                    }
                }
            }
            else {  //key == tree->value
                cout << "Add failure: the same node is not allowed to be added!" << endl;
            }
            tree->height = max(height(tree->lchild), height(tree->rchild)) + 1;
            return tree;
        }
        //从AVL树中删除结点
        AVLNode* Delete(AVLNode* &tree, AVLNode* temp) {
            //根为空 或者 无要删除的结点
            if(tree == NULL || temp == NULL) {
                return NULL;
            }
            if(temp->value < tree->value) {     //待删除的结点在“tree的左子树”中
                tree->lchild = Delete(tree->lchild,temp);
                //若删除结点后，AVL树失衡，则进行调节
                if(height(tree->rchild) - height(tree->lchild) == 2) {
                    AVLNode* t1 = tree->rchild;
                    if(height(t1->lchild) > height(t1->rchild)) {
                        tree = RightLeftRotation(tree);
                    }else {
                        tree = RightRightRotation(tree);
                    }
                }
            }
            else if(temp->value > tree->value) {    ////待删除的结点在“tree的右子树”中
                tree->rchild = Delete(tree->rchild,temp);
                //若删除结点后，AVL树失衡，则进行调节
                if(height(tree->lchild) - height(tree->rchild) == 2) {
                    AVLNode* t2 = tree->lchild;
                    if(height(t2->rchild) > height(t2->lchild)) {
                        tree = LeftRightRotation(tree);
                    }else {
                        tree = LeftLeftRotation(tree);
                    }
                }
            }
            else {  //tree是对应要删除的结点
                
                //tree的左右孩子非空
                if((tree->lchild != NULL) && (tree->rchild != NULL)) {
                    if(height(tree->lchild) > height(tree->rchild)) {

                        // 如果tree的左子树比右子树高；
                        // 则(01)找出tree的左子树中的最大节点
                        //   (02)将该最大节点的值赋值给tree。
                        //   (03)删除该最大节点。
                        // 这类似于用"tree的左子树中最大节点"做"tree"的替身；
                        // 采用这种方式的好处是：删除"tree的左子树中最大节点"之后，AVL树仍然是平衡的。

                        AVLNode* max =maximum(tree->lchild);
                        tree->value = max->value;
                        tree->lchild = Delete(tree->lchild, max);

                    }else {
                        // 如果tree的左子树不比右子树高(即它们相等，或右子树比左子树高1)
                        //  (01)找出tree的右子树中的最小节点
                        //  (02)将该最小节点的值赋值给tree。
                        //  (03)删除该最小节点。
                        // 这类似于用"tree的右子树中最小节点"做"tree"的替身；
                        // 采用这种方式的好处是：删除"tree的右子树中最小节点"之后，AVL树仍然是平衡的。
                    
                        AVLNode* min = minimum(tree->rchild);
                        tree->value = min->value;
                        tree->rchild = Delete(tree->rchild, min);
                    
                    }
                }else {
                    AVLNode* tmp = tree;
                    tree = (tree->lchild != NULL) ? tree->lchild : tree->rchild;
                    delete tmp;
                }
            }
            return tree;
        }
        //销毁AVL树
        void Destroy(AVLNode* &tree) {
            if(tree == NULL) {
                return;
            }

            if(tree->lchild != NULL) {
                Destroy(tree->lchild);
            }
            if(tree->rchild != NULL) {
                Destroy(tree->rchild);
            }
            delete tree;
        }
        //LL: 右单旋
        AVLNode* LeftLeftRotation(AVLNode* tree) {
            AVLNode* temp;
            temp = tree->lchild;
            tree->lchild = temp->rchild;
            temp->rchild = tree;
            //更新高度
            tree->height = max(height(tree->lchild), height(tree->rchild)) + 1;
            temp->height = max(height(temp->lchild), height(temp->rchild)) + 1;
            return temp;
        }
        //RR： 左单旋
        AVLNode* RightRightRotation(AVLNode* tree) {
            AVLNode* temp;
            temp = tree->rchild;
            tree->rchild = temp->lchild;
            temp->lchild = tree;
            //更新高度
            tree->height = max(height(tree->lchild), height(tree->rchild)) + 1;
            temp->height = max(height(temp->lchild), height(temp->rchild)) + 1;
            return temp;
        }
        //LR:
        AVLNode* LeftRightRotation(AVLNode* tree) {
            tree->lchild = RightRightRotation(tree->lchild);
            return LeftLeftRotation(tree);
        }
        //RL:
        AVLNode* RightLeftRotation(AVLNode* tree) {
            tree->rchild = LeftLeftRotation(tree->rchild);
            return RightRightRotation(tree);
        }

        AVLNode* Search(AVLNode* x, ElemType key) const{
            if(x == NULL || x->value == key) {
                return x;
            }
            if(key < x->value) {
                return Search(x->lchild, key);
            }else {
                return Search(x->rchild, key);
            }
        }


};


int main() {
    AVLTree myTree;
    myTree.Insert(15);
    myTree.Insert(4);
    myTree.Insert(5);
    myTree.Insert(6);
    myTree.Insert(7);
    myTree.Insert(50);
    myTree.Insert(23);
    myTree.Insert(71);
    myTree.PreOrderTraverse();
    cout << endl;
    myTree.InOrderTraverse();
    cout << endl;
    myTree.PostOrderTraverse();
    myTree.Delete(4);
    cout << "the minimum = " << myTree.minimum() << endl;
    cout << "the maximum = " << myTree.maximum() << endl;
    system("pause");
    return 0;



}