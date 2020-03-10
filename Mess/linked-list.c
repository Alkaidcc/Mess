#include <stdio.h>
#include <stdlib.h>
#include<iostream>
typedef struct node node; //閻€劋绨惇浣烘殣struct
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
{                                     //閸旂姴鍩岄弫缈犻嚋闁炬崘銆冮惃鍕付閸氬酣娼�?
    while (currentNode->next != NULL) //鐞涖劎銇氶悳鏉挎躬娑撳秵妲搁張鈧崥搴濈娑擃亣濡悙锟�?
    {
        //婵″倹鐏夋稉宥嗘Ц閺堚偓閸氬簼绔存稉顏囧Ν閻愶拷,鐏忓崬绶氶崥搴Ｐ╅崝銊ょ娴ｏ拷
        currentNode = currentNode->next;
    }
    //瀹歌尙绮＄粔璇插煂閺堚偓閸氬簼绔存稉顏冪�?
    currentNode->next = createNode(value);
}

node *findNode(node *currentNode, int value)
{ //閺屻儲澹橀幏銉︽箒閹稿洤鐣鹃崐鑲╂畱閼哄倻鍋�?,婵″倹鐏夐幍鍙ョ瑝閸掞拷,鐏忚精绻戦崶婵禪LL
    while (currentNode != NULL && currentNode->value != value)
    { //瑜版挸澧犻懞鍌滃仯閻ㄥ嫬鈧棿绗夋稉鐑樺厒鐟曚焦鐓￠幍鍓ф畱閸婂吋妞�,妞ゅ搫绨柆宥呭�?
        currentNode = currentNode->next;
    }
    return currentNode;
}

void insertNode(node *currentNode,int value)
{                                //閸旂姴鍩屾潻娆庨嚋閼哄倻鍋ｉ惃鍕倵闂堬拷(閹绘帒鍙�?)
    node *nextNode = currentNode->next; //娣囨繂鐡ㄦ担蹇撴倵娑撯偓娑擃亣濡悙锟�
    currentNode->next = createNode(value);
    currentNode->next->next = nextNode;
}

void deleteNextNode(node *currentNode)
{                                      //閸掔娀娅庢稉瀣╃娑擃亣濡悙锟�?
    node *nextNode = currentNode->next->next; //娣囨繂鐡ㄦ担蹇撴倵娑撯偓娑擃亣濡悙鍦畱閸氬簼绔存稉顏囧Ν閻愶拷
    free(currentNode->next);
    currentNode->next = nextNode;
}

int main()
{
    node *head = createNode(100);    //閸掓稑缂撴＃鏍Ν閻愶�?
    for (int i = 1; i < 100; i *= 2) //閺嬪嫰鈧娀鎽肩悰锟�?
    {
        addNode(head, i);
    }
    node *finded_1 = findNode(head, 32); //閺屻儲澹橀崐闂磋礋32閻ㄥ嫯濡悙锟�
    node *finded_2 = findNode(head, 33); //閺屻儲澹橀崐闂磋礋33閻ㄥ嫯濡悙锟�

    insertNode(finded_1,50);
    deleteNextNode(finded_1);
    return 0;
}