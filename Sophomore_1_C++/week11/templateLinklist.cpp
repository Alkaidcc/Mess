/*
дһ��������ģ���࣬ʵ����ع��ܡ�
*/
#include <iostream>
using namespace std;

template<class T>
struct Node{
    T data;     //�洢����
    Node<T>* next;      //nextָ��
    Node(Node<T>* ptr = NULL){
        next = ptr;
    }
    Node(const T elment, Node<T>* ptr = NULL){
        next = ptr;
        data = elment;
    }
};

template<class T>
class Linklist
{
private:
    Node<T>* head;
public:
    //���캯��
    Linklist();
    Linklist(const Linklist<T>& list);
    ~Linklist();
    Linklist(Linklist<T>& list);
    //��ȡ����
    int Length()const;
    //�ж������Ƿ�Ϊ��
    bool isEmpty();
    //����=��ֵ
    Linklist& operator=(const Linklist<T>& list);
    //��ȡͷ���
    Node<T>* getHead()const;
    //��ȡָ��λ��pos�Ľ���ֵ��ʧ�ܷ���false
    bool getData(int pos, T& data);
    //ɾ��ָ��λ��pos��Ԫ��
    bool Remove(int pos);
    //��ӡ����
    void Print();
    //Ѱ��Ԫ��Ϊelement��ָ��
    int Find(const T& element);
    //�������
    void Clear();
    //��������β
    void Add(T& elment);
    //����
    bool Insert(int pos, const T& data);
    
};

template<class T>
Linklist<T>::Linklist():head(NULL){}
template<class T>
Linklist<T>::Linklist(const Linklist<T>& list){
    int i = 1;
    while(i <= list.Length()){

    }
}
template<class T>
Linklist<T>::~Linklist(){
    Clear();
}
template<class T>
int Linklist<T>::Length()const{
    int count = 0;
    Node<T>* p = head;
    while(p != NULL){
        p = p->next;
        count++;
    }
    return count;
}
template<class T>
void Linklist<T>::Print(){
    Node<T>* p = head;
    while(p != NULL){
        cout << p->data << ends;
        p = p->next;
    }
    cout << endl;
}
template<class T>
bool Linklist<T>::isEmpty(){
    return head == NULL;
}
template<class T>
int Linklist<T>::Find(const T& element){
    int pos = -1;
    int i = 1;
    Node<T>* p = head;
    while(p != NULL){
        if(p->data == element){
            pos = i;
            break;
        }
        p = p->next;
        i++;
    }
    return pos;
}
template<class T>
Node<T>* Linklist<T>::getHead() const{
    return this->head;
}
template<class T>
bool Linklist<T>::getData(int pos, T& data){
    int i = 1;
    Node<T>* p = head;
    while(p != NULL){
        if(pos == i){
            data = p->data;
            return true;
        }
        p = p->next;
        i++;
    }
    return false;
}
template<class T>
bool Linklist<T>::Remove(int pos){
    int l = Length();
    if(pos > l || pos < 1){
        cout << "��Ч��λ��!" << endl;
        return false;
    }else{
        if(pos == 1){
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            return true;
        }else{
            Node<T>* p = head;
            int i = 1;
            while(++i < pos){
                p = p->next;
            }
            Node<T>* temp = p->next;
            p->next = temp->next;
            delete temp;
            return true;
        }
    }
    
}
template<class T>
void Linklist<T>::Clear(){
    while(head != NULL){
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
}
template<class T>
void Linklist<T>::Add(T& element){
    Node<T>* pnode = new Node<T>;
    pnode->data = element;
    pnode->next = NULL;
    if(head == NULL){
        head = pnode;
    }
    else{
        Node<T>* p = head;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = pnode;
    }
}
template<class T>
bool Linklist<T>::Insert(int pos,const T& data){
    int l = Length();
    if(pos <1 || pos > l){
        cout << "�����λ��δ�Ƿ�λ��"<< endl;
        return false;
    }else{
        if(pos == 1){
            Node<T>* temp = new Node<T>;
            temp->data = data;
            temp->next = head;
            head = temp;
        }else{
            int i = 1;
            Node<T>* p = head;
            while(++i < pos){
                p = p->next;
            }
            Node<T>* temp = new Node<T>;
            temp->data = data;
            temp->next = p->next;
            p->next = temp;
        }
        return true;
    }
}


int main(){
    Linklist<int> link;
    for(int i = 0;i < 5;i++){
        link.Add(i);
    }
    cout << "Print the linklist: ";
    link.Print();
    cout << "the linklist size: " << link.Length() << endl;
    cout << "Remove the 1st element"<< endl;
    link.Remove(1);
    link.Print();
    cout << "Insert the element in 3rd" << endl;
    link.Insert(3,55);
    link.Print();
    cout << "Clear the list" << endl;
    link.Clear();
    cout << "the size of list: " << link.Length() << endl;
    system("pause");
    return 0;
}
