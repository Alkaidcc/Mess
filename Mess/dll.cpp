#include <stdio.h>
#include <iostream>
using namespace std;

class node{//双向不循环链表
    public:

    //数据成员
    int value;
    node* next=NULL;
    node* forward=NULL;

    //函数成员,在OOP中也成方法

    node(int value=0){//构造函数,在使用new操作符时会调用
        this->value=value;
    }

    void addNode(int value){//加到整个链表的最后面
        node* currentNode=this;//声明查找用的节点,初始化为自己
        while (currentNode->next!=NULL)//表示现在不是最后一个节点
        {
            //如果不是最后一个节点,就往后移动一位
            currentNode=currentNode->next;
        }
        //已经移到最后一个了
        currentNode->next=new node(value);
        currentNode->next->forward=currentNode;
    }

    node* findNode(int value){//查找拥有指定值的节点,如果找不到,就返回NULL
        node* currentNode=this;
        while(currentNode!=NULL&&currentNode->value!=value){//当前节点的值不为想要查找的值时,顺序遍历
            currentNode=currentNode->next;
        }
        return currentNode;
    }

    void insertNode(int value){//加到这个节点的后面(插入)
        node* nextNode=this->next;//保存住后一个节点
        this->next=new node(value);
        this->next->next=nextNode;
        this->next->forward=this;
        this->next->next->forward=this->next;
    }

    void deleteNextNode(){//删除下一个节点
        node* nextNode=this->next->next;//保存住后一个节点的后一个节点
        delete this->next;
        this->next=nextNode;
    }
    void deleteCurrentNode(){//删除当前节点
        this->forward->next=this->next;
        this->next->forward=this->forward;
        delete this;
    }
};

int main(){
    node head=node();
    for (int i = 1; i < 100; i*=2)//构造链表
    {
        head.addNode(i);
    }
    node* finded_1=head.findNode(32);//查找值为32的节点
    node* finded_2=head.findNode(33);//查找值为33的节点

    finded_1->insertNode(50);
    finded_1->deleteCurrentNode();
    return 0;
}