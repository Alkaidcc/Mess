#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

typedef int ElemType;

class node
{ //����ѭ������ڵ�
public:
    ElemType data;
    node *next;
    node()
    { //���캯��,��ʹ��new������ʱ�����
        this->next = NULL;
    }
    node(int val)
    { //���캯��,��ʹ��new������ʱ�����
        this->data = val;
        this->next = NULL;
    }
    void insertNode(int val)
    {                                //�ӵ�����ڵ�ĺ���(����)
        node *nextNode = this->next; //����ס��һ���ڵ�
        this->next = new node(val);
        this->next->next = nextNode;
    }
    void deleteNextNode()
    {                                      //ɾ����һ���ڵ�
        node *nextNode = this->next->next; //����ס��һ���ڵ�ĺ�һ���ڵ�
        delete this->next;
        this->next = nextNode;
    }
};

class List
{ //����ѭ������
public:
    node *head, *hail;

    List(); //�׽ڵ�Ϊ��
    ~List();
    void addNode(int val)
    { //�ӵ���������������
        this->hail->next = new node(val);
        this->hail=this->hail->next;
    }
    void insertNodeById(int id,int val)
    { //��0�����,�ڵ�Id��λ�ò���һ��Ԫ��
        node *cuNode=this->head;
        for (int i = 0; i < id; i++)
        {
            cuNode=cuNode->next;
        }
        cuNode->insertNode(val);
    }
    void deleteNodeById(int id)
    { //��0�����,ɾ����Id��λ�õ�һ��Ԫ��
        node *cuNode=this->head;
        for (int i = 0; i < id; i++)
        {
            cuNode=cuNode->next;
        }
        cuNode->deleteNextNode();
    }
    node* getNodeById(int id)
    { //��0�����
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
    List* myListA=new List();//�ȼ���CreateList_L
    myListA->addNode(7);
    myListA->addNode(5);
    myListA->addNode(3);
    myListA->addNode(11);
    List* myListB=new List();//�ȼ���CreateList_L
    myListB->addNode(2);
    myListB->addNode(6);
    myListB->addNode(3);
    myListA->merge(myListB);
    myListA->print();
    delete myListA,myListB;
    return 0;
}