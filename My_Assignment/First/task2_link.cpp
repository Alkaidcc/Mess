//输入10位同学的姓名，学号，成绩，并把这些学生的信息输出，每位学生一行。并输出最高分，最低分和平均分
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

//声明
student* Creatnode(string name1,int id1,double score1);
void Add(student* currentstudent,string nam,int ID,double sco);
void Print(student* currentstudent);
void Destroy(student* currentstudent);
void Traverse(student* currentstudent);

int main(){
    //初始化头结点 
    student* head = new student;
    head->name = " ";
    head->id = -1;
    head->score = -1;
    head->next =NULL;

    int ID; //学号
    double sco; //成绩
    string nam; //姓名
    cout << "Please enter students information: " << endl;
    for(int i=0;i<10;i++){
        cin >> nam >> ID >> sco;
        Add(head,nam,ID,sco);
    }

    Print(head->next);  //输出打印
    cout << endl;
    Traverse(head->next);
    Destroy(head);      //收回内存
    system("pause");
    return 0;
}

student* Creatnode(string name1,int id1,double score1)
{   //创建结点
    student* temp = new student;
    temp->name = name1;
    temp->id = id1;
    temp->score = score1;
    temp->next = NULL;
}

void Add(student* currentstudent,string nam,int ID,double sco)
{   //增加结点
    while(currentstudent->next!=NULL)
        currentstudent = currentstudent->next;
    currentstudent->next = Creatnode(nam,ID,sco);
}

void Print(student* currentstudent)
{   //输出书籍
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
{   //收回空间
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