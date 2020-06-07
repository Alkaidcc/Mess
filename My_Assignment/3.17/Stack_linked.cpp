#include<iostream>
#include<cstdlib>
using namespace std;
const int ERROR = 0;
const int MAXSIZE = 100;
const int OVERFLOW = -2;
const int OK = 1;
typedef int ElemType;
typedef int SElemType;
typedef struct StackNode{
    ElemType data;          //�����的
    struct StackNode* next; //ָ����
}StackNode,*LinkStack;

//����
int InitStack (LinkStack& S);
int DestroyStack (LinkStack& S);
void ClearStack (LinkStack& S);
bool StackEmpty (const LinkStack S);
int StackLength (const LinkStack S);
SElemType GetTop (const LinkStack S);
int Push (LinkStack& S,SElemType e);
int Pop (LinkStack& S,SElemType& e);
void StackTraverse (const LinkStack S);
void conversion (int N);

int main() {
    int N;
    cout << "������ʮ����������";
    cin >> N;
    cout << "��ʮ���������İ˽���Ϊ��";
    conversion(N);
    cout << endl;
    system("pause");
    return 0;
}

int InitStack (LinkStack& S) {
    S = NULL;
    return OK;    
}

int Push (LinkStack& S,SElemType e) {
    LinkStack p = new StackNode;
    if(!p) {
        exit(OVERFLOW);
    }
    p->data = e;
    p->next = S;
    S = p;
    return OK;
}

int Pop (LinkStack& S,SElemType& e) {
    if(S == NULL) {   //ջ��
        return ERROR;
    }
    e = S->data;
    LinkStack p = S;
    S = S->next;
    delete p;
    return OK;
}

SElemType GetTop (const LinkStack S) {
    if(S != NULL) {   //ջ�ǿ�
        return S->data;
    }
    return ERROR;
}

bool StackEmpty (const LinkStack S) {
    return (S == NULL);
}

int DestroyStack (LinkStack& S) {
    ClearStack(S);
    delete S;
    return OK;
}

void ClearStack (LinkStack& S) {
    LinkStack p;
    while(S) {
        p = S;
        S = S->next;
        delete p;
    }
}

int StackLength (const LinkStack S) {
    int counter = 0;
    LinkStack p = S;
    while(p) {
        counter++;
        p = p->next;
    }
    return counter;
}

void StackTraverse (const LinkStack S) {
    LinkStack p = S;
    while(p) {
        cout << " " << p->data;
        p = p->next;
    }
    cout << endl;
}

void conversion (int N) {
    LinkStack S;
    ElemType e;
    InitStack(S);
    while(N) {
        Push (S,N%8);
        N/=8;
    }
    while (!StackEmpty(S))
    {
        Pop(S,e);
        cout << e;
    }
    
}