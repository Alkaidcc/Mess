//�����
#include<stdio.h>
typedef struct GNode *GList;
strcut GNode{
    int Tag;            //��־��0��ʾ����ǵ�Ԫ�أ�1��ʾ�ڵ��ǹ����
    union{              //�ӱ�ָ����SubList��Tag==1���뵥Ԫ��������Data��Tag==0�����ô洢�ռ�
        ElementType Data;
        GList SubList;
    }URegion;
    GList Next;
};