//����10λͬѧ��������ѧ�ţ��ɼ���������Щѧ������Ϣ�����ÿλѧ��һ�С��������߷֣���ͷֺ�ƽ����
#include<iostream>
#include<cstring>
#include<string>
#include<cfloat>
using namespace std;

typedef struct student{
    string name;
    int id;
    double score;
    struct student* next;
}student;

//����
student* Creatnode(string name1,int id1,double score1);
void Add(student* currentstudent,string nam,int ID,double sco);
void Print(student* currentstudent);
void Destroy(student* currentstudent);
void Traverse(student* currentstudent);

int main(){
    //��ʼ��ͷ��� 
    student* head = new student;
    head->name = " ";
    head->id = -1;
    head->score = -1;
    head->next =NULL;

    int ID; //ѧ��
    double sco; //�ɼ�
    string nam; //����
    cout << "Please enter students information: " << endl;
    for(int i=0;i<10;i++){
        cin >> nam >> ID >> sco;
        Add(head,nam,ID,sco);
    }

    Print(head->next);  //�����ӡ
    cout << endl;
    Traverse(head->next);
    Destroy(head);      //�ջ��ڴ�
    system("pause");
    return 0;
}

student* Creatnode(string name1,int id1,double score1)
{   //�������
    student* temp = new student;
    temp->name = name1;
    temp->id = id1;
    temp->score = score1;
    temp->next = NULL;
}

void Add(student* currentstudent,string nam,int ID,double sco)
{   //���ӽ��
    while(currentstudent->next!=NULL)
        currentstudent = currentstudent->next;
    currentstudent->next = Creatnode(nam,ID,sco);
}

void Print(student* currentstudent)
{   //����鼮
    cout << "Name\t\t" << "ID\t\t" << "Score" << endl;
    while(currentstudent!=NULL){
        cout << currentstudent->name;
        cout << "\t\t";
        cout << currentstudent->id;
        cout << "\t\t";
        cout << currentstudent->score << endl;
        currentstudent = currentstudent->next;
    }
}
void Destroy(student* currentstudent)
{   //�ջؿռ�
    while(currentstudent){
        student* temp = currentstudent->next;
        delete currentstudent;
        currentstudent = temp;
    }
}

void Traverse(student* currentstudent)
{
    double min = DBL_MAX;
    double max = DBL_MIN;
    double sum = 0.0;
    int cnt =0;
    while(currentstudent!=NULL){
        cnt++;
        sum += currentstudent->score;
        if(currentstudent->score < min)
            min = currentstudent->score;
        if(currentstudent->score > max)
            max = currentstudent->score;
        currentstudent = currentstudent->next;
    }
    double average = sum/cnt;
    cout << "max = " << max << endl;
    cout << "min = " << min << endl;
    cout << "average = " << average << endl;
}