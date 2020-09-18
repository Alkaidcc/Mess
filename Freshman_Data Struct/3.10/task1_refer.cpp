#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

typedef int ElemType;

class node
{ //单向不循环链表节点
public:
    ElemType data;
    node *next;
    node()
    { //构造函数,在使用new操作符时会调用
        this->next = NULL;
    }
    node(int val)
    { //构造函数,在使用new操作符时会调用
        this->data = val;
        this->next = NULL;
    }
    void insertNode(int val)
    {                                //加到这个节点的后面(插入)
        node *nextNode = this->next; //保存住后一个节点
        this->next = new node(val);
        this->next->next = nextNode;
    }
    void deleteNextNode()
    {                                      //删除下一个节点
        node *nextNode = this->next->next; //保存住后一个节点的后一个节点
        delete this->next;
        this->next = nextNode;
    }
};

class List
{ //单向不循环链表
public:
    node *head, *hail;

    List(); //首节点为空
    ~List();
    void addNode(int val)
    { //加到整个链表的最后面
        this->hail->next = new node(val);
        this->hail=this->hail->next;
    }
    void insertNodeById(int id,int val)
    { //从0起计数,在第Id个位置插入一个元素
        node *cuNode=this->head;
        for (int i = 0; i < id; i++)
        {
            cuNode=cuNode->next;
        }
        cuNode->insertNode(val);
    }
    void deleteNodeById(int id)
    { //从0起计数,删除第Id个位置的一个元素
        node *cuNode=this->head;
        for (int i = 0; i < id; i++)
        {
            cuNode=cuNode->next;
        }
        cuNode->deleteNextNode();
    }
    node* getNodeById(int id)
    { //从0起计数
        node *cuNode=this->head;
        for (int i = 0; i < id; i++)
        {
            cuNode=cuNode->next;
        }
        return cuNode->next;
    }

    bool locate(int val){
        node *cuNode=this->head;
        while (cuNode!=this->hail)
        {
            if (cuNode->next->data==val)
            {
                return true;
            }
            cuNode=cuNode->next;
        }
        return false;
    }

    void merge(List* target){
        node *cuNode=target->head;
        while (cuNode!=target->hail)
        {
            if (!this->locate(cuNode->next->data))
            {
                this->addNode(cuNode->next->data);
            }
            cuNode=cuNode->next;
        }
    }
    void print(){
        node *cuNode=this->head;
        while (cuNode!=this->hail)
        {
            printf("%d ",cuNode->next->data);
            cuNode=cuNode->next;
        }
        printf("\n");
    }
};

List::List()
{
    this->hail = this->head = new node();
}

List::~List()
{
    node* nextNode;
    while (this->head != this->hail)
    {
        nextNode=this->head->next;
        delete this->head;
        this->head=nextNode;
    }
}

int main()
{
    List* myListA=new List();//等价于CreateList_L
    myListA->addNode(7);
    myListA->addNode(5);
    myListA->addNode(3);
    myListA->addNode(11);
    List* myListB=new List();//等价于CreateList_L
    myListB->addNode(2);
    myListB->addNode(6);
    myListB->addNode(3);
    myListA->merge(myListB);
    myListA->print();
    delete myListA,myListB;
    return 0;
}