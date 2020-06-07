#include<iostream>
#include<cstdlib>
using namespace std;
const int ERROR = 0;
const int MAXSIZE = 100;
const int OVERFLOW = -2;
const int OK = 1;
typedef int ElemType;
typedef int SElemType;
typedef struct stack{
    SElemType *base;    //栈底指针
    SElemType *top;     //栈顶指针
    int stacksize;      //最大容量
}Sq_stack;

//声明
int InitStack (Sq_stack& S);
void DestroyStack (Sq_stack& S);
void ClearStack (Sq_stack& S);
bool StackEmpty (const Sq_stack S);
int StackLength (const Sq_stack S);
SElemType GetTop (const Sq_stack S);
int Push (Sq_stack& S,SElemType e);
int Pop (Sq_stack& S,SElemType& e);
void StackTraverse (const Sq_stack S);
void conversion (int N);

int main() {
    int N;
    cout << "请输入十进制整数：";
    cin >> N;
    cout << "该十进制整数的八进制为：";
    conversion(N);
    cout << endl;
    system("pause");
    return 0;
}

int InitStack (Sq_stack& S) {
    S.base = new SElemType[MAXSIZE];
    if(!S.base) {
        exit (OVERFLOW);
    }
    S.top = S.base;
    S.stacksize = MAXSIZE;
    return OK;    
}

int Push (Sq_stack& S,SElemType e) {
    if(S.top - S.base == S.stacksize) {
        return ERROR;
    }
    *S.top++ = e;
    return OK;
}

int Pop (Sq_stack& S,SElemType& e) {
    if(S.top == S.base) {   //栈空
        return ERROR;
    }
    e = *(--S.top);
    return OK;
}

SElemType GetTop (const Sq_stack S) {
    if(S.base != S.top) {   //栈非空
        return *(S.top-1);
    }
    return ERROR;
}

bool StackEmpty (const Sq_stack S) {
    if(S.base == S.top) {
        return true;
    }
    return false;
}


int StackLength (const Sq_stack S) {
    return (S.top - S.base);
}

void StackTraverse (const Sq_stack S) {
    auto p =S.base;
    while(p != S.top){
        cout << *p << " " ;
        p++;
    }
}
void conversion (int N) {
    Sq_stack S;
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