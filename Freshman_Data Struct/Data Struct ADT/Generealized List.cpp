//广义表
#include<stdio.h>
typedef struct GNode *GList;
strcut GNode{
    int Tag;            //标志域：0表示结点是单元素，1表示节点是广义表
    union{              //子表指针域SubList（Tag==1）与单元素数据域Data（Tag==0）共用存储空间
        ElementType Data;
        GList SubList;
    }URegion;
    GList Next;
};