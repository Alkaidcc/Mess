#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

typedef struct
{
    char no[8];
    char name[20];
    float price;
} ElemType;

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
private:
    node *head, *hail;

public:
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
};

List::List()
{
    this->hail = this->head = new node();
}

List::~List()
{
    int i=0,j=1;
    float max=-1000000000000;
    while (this->head != this->hail)
    {
        node *next;
        next = this->head->next;
        if (max<next->data.price)
        {
            max=next->data.price;
            i=j;
        }
        printf("%s %s %f\n",(next->data).no,(next->data).name,(next->data).price);
        j++;
        delete this->head;
        this->head = next;
    }
    delete this->head;
    printf("most expansive:%d",i);
}

int main()
{
    List* myList=new List();//�ȼ���CreateList_L
    puts("Input:");
    char no[8];
    char name[20];
    float price;
    for (int i = 0; i < 6; i++)
    {
        scanf("%s %s %f",no,name,&price);
        myList->addNode(no,name,price);
    }
    puts("Id=3,print:");
    node* tmp=myList->getNodeById(3-1);
    printf("%s %s %f\n",(tmp->data).no,(tmp->data).name,(tmp->data).price,(tmp->data));
    puts("Instert-Input:");
    scanf("%s %s %f",no,name,&price);
    myList->insertNodeById(1-1,no,name,price);
    myList->deleteNodeById(5-1);
    puts("Print:");
    delete myList;
    system("pause");
    return 0;
}