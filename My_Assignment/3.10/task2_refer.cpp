#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

typedef struct ElemType ElemType;
typedef struct ElemType
{
    char no[8];
    char name[20];
    float price;
    bool operator==(ElemType &target);
} ElemType;

bool ElemType::operator==(ElemType &target){
    if (!strcmp(this->no,target.no)&&!strcmp(this->name,target.name)&&this->price-target.price<10e-4)
    {
        return true;
    }
    return false;
}

class node
{ //����ѭ������ڵ�
public:
    ElemType data;
    node *next;
    node()
    { //���캯��,��ʹ��new������ʱ�����
        this->next = NULL;
    }
    node(char no[], char name[], float price)
    { //���캯��,��ʹ��new������ʱ�����
        strcpy((this->data).no, no);
        strcpy((this->data).name, name);
        (this->data).price = price;
        this->next = NULL;
    }
    void insertNode(char no[], char name[], float price)
    {                                //�ӵ�����ڵ�ĺ���(����)
        node *nextNode = this->next; //����ס��һ���ڵ�
        this->next = new node(no, name, price);
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
    void addNode(char no[], char name[], float price)
    { //�ӵ���������������
        this->hail->next = new node(no, name, price);
        this->hail=this->hail->next;
    }
    void insertNodeById(int id,char no[], char name[], float price)
    { //��0�����,�ڵ�Id��λ�ò���һ��Ԫ��
        node *cuNode=this->head;
        for (int i = 0; i < id; i++)
        {
            cuNode=cuNode->next;
        }
        cuNode->insertNode(no, name, price);
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
    bool locate(ElemType val){
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
                this->addNode((cuNode->next->data).no,(cuNode->next->data).name,(cuNode->next->data).price);
            }
            cuNode=cuNode->next;
        }
    }
    void print(){
        node *cuNode=this->head;
        while (cuNode!=this->hail)
        {
            printf("(%s %s %.0f) ",(cuNode->next->data).no,(cuNode->next->data).name,(cuNode->next->data).price);
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
    node *next;
    while (this->head != this->hail)
    {
        next = this->head->next;
        delete this->head;
        this->head = next;
    }
    delete this->head;
}

int main()
{
    List* myListA=new List();//�ȼ���CreateList_L
    myListA->addNode("301","AAA",90);
    myListA->addNode("205","DDD",87);
    myListA->addNode("307","CCC",82);
    myListA->addNode("304","DDD",70);
    List* myListB=new List();//�ȼ���CreateList_L
    myListB->addNode("308","fff",90);
    myListB->addNode("304","DDD",70);
    myListB->addNode("302","eee",100);
    myListA->merge(myListB);
    myListA->print();
    delete myListA,myListB;
    return 0;
}