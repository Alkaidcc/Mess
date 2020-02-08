#include <stdio.h>
#include <stdlib.h>
#include<iostream>
typedef struct node node; //用于省略struct
struct node
{
    int value;
    node *next;
};

node *createNode(int value)
{
    node *temp = (node*)malloc(sizeof(node));
    temp->value = value;
    temp->next = NULL;
}

void addNode(node *currentNode, int value)
{                                     //加到整个链表的最后面
    while (currentNode->next != NULL) //表示现在不是最后一个节点
    {
        //如果不是最后一个节点,就往后移动一位
        currentNode = currentNode->next;
    }
    //已经移到最后一个了
    currentNode->next = createNode(value);
}

node *findNode(node *currentNode, int value)
{ //查找拥有指定值的节点,如果找不到,就返回NULL
    while (currentNode != NULL && currentNode->value != value)
    { //当前节点的值不为想要查找的值时,顺序遍历
        currentNode = currentNode->next;
    }
    return currentNode;
}

void insertNode(node *currentNode,int value)
{                                //加到这个节点的后面(插入)
    node *nextNode = currentNode->next; //保存住后一个节点
    currentNode->next = createNode(value);
    currentNode->next->next = nextNode;
}

void deleteNextNode(node *currentNode)
{                                      //删除下一个节点
    node *nextNode = currentNode->next->next; //保存住后一个节点的后一个节点
    free(currentNode->next);
    currentNode->next = nextNode;
}

int main()
{
    node *head = createNode(100);    //创建首节点
    for (int i = 1; i < 100; i *= 2) //构造链表
    {
        addNode(head, i);
    }
    node *finded_1 = findNode(head, 32); //查找值为32的节点
    node *finded_2 = findNode(head, 33); //查找值为33的节点

    insertNode(finded_1,50);
    deleteNextNode(finded_1);
    return 0;
}