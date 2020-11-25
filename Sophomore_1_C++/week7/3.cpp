/* ���һ��Ա����Worker���������������䡣��������һ��������Manager��
����ְ��Ͳ���˽�����ݳ�Ա�Լ���صĳ�Ա��������������һ�����ʦ��Designer��
����ְ�ƺ�רҵ˽�����ݳ�Ա�Լ���صĳ�Ա������Ȼ����Manager��Designer����������Ʋ�������DesManager��
��������˽�����ݳ�Ա�Լ���صĳ�Ա������Ҫ��ʹ������࣬����main()�в���һЩ���ݽ��в��ԡ�
*/
#include <iostream>
using namespace std;

class Worker
{
private:
    string Name;    //����
    int Age;        //����
public:
    Worker(string name, int age):Name(name), Age(age){}
    string getName(){return Name;}
    int getAge(){return Age;}
    void setName(string name);
    void setAge(int age);
};

class Manager:virtual public Worker
{
private:
    string Position;        //ְλ
    string Department;      //����
public:
    Manager(string name, int age, string pos, string de):Worker(name, age), Position(pos), Department(de){}
    string getPosition(){return Position;}
    string getDepartment(){return Department;}
    void setPosition(string pos);
    void setDepartment(string de);
};

class Designer:virtual public Worker
{
private:
    string Title;       //ְ��
    string Major;       //רҵ
public:
    Designer(string name, int age, string title, string major):Worker(name,age),Title(title),Major(major){}
    string getTitle(){return Title;}
    string getMajor(){return Major;}
    void setTitle(string title);
    void setMajor(string major);
};

class DesManager:public Designer, public Manager
{
private:
    double Wage;        //н��
public:
    DesManager(string name, int age, string title, string major,string pos, string de, double wage):
    Worker(name,age),
    Designer(name,age,title,major),
    Manager(name,age,pos,de),Wage(wage){}

    double getWage(){return Wage;}
    void setWage(double w);
};

void Worker::setAge(int age){
    this->Age = age;
}
void Worker::setName(string name){
    this->Name = name;
}
void Manager::setDepartment(string de){
    this->Department = de;
}
void Manager::setPosition(string pos){
    this->Position = pos;
}
void Designer::setMajor(string major){
    this->Major = major;
}
void Designer::setTitle(string title){
    this->Title = title;
}
void DesManager::setWage(double wage){
    this->Wage = wage;
}

int main(){
    Worker w("����",25);
    Manager m("����",23,"������Դ����","������Դ������");
    Designer d("����",21,"��������ܼ�","�Ӿ�����");
    DesManager dm("����",21,"���̲��ܼ�","��������","����������Ӫ","����������Ӫ��",6500);
    //test for Worker
    cout << "����: " << w.getName() << endl;
    cout << "����: " << w.getAge() << endl;
    cout << "-------------------------" << endl;

    //test for Manager
    cout << "����: " << m.getName() << endl;
    cout << "����: " << m.getAge() << endl;
    cout << "ְλ: " << m.getPosition() << endl;
    cout << "����: " << m.getDepartment() << endl;
    cout << "-------------------------" << endl;

    //test for Designer
    cout << "����: " << d.getName() << endl;
    cout << "����: " << d.getAge() << endl;
    cout << "רҵ: " << d.getMajor() << endl;
    cout << "ְ��: " << d.getTitle() << endl;
    cout << "-------------------------" << endl;

    //test for DesManager
    cout << "����: " << dm.getName() << endl;
    cout << "����: " << dm.getAge() << endl;
    cout << "ְλ: " << dm.getPosition() << endl;
    cout << "����: " << dm.getDepartment() << endl;
    cout << "רҵ: " << dm.getMajor() << endl;
    cout << "ְ��: " << dm.getTitle() << endl;
    cout << "н��: " << dm.getWage() << endl;
    dm.setName("����");
    dm.setAge(22);
    dm.setMajor("�羰԰��");
    dm.setWage(5500);
    cout << "-------------------------" << endl;
    cout << "����: " << dm.getName() << endl;
    cout << "����: " << dm.getAge() << endl;
    cout << "ְλ: " << dm.getPosition() << endl;
    cout << "����: " << dm.getDepartment() << endl;
    cout << "רҵ: " << dm.getMajor() << endl;
    cout << "ְ��: " << dm.getTitle() << endl;
    cout << "н��: " << dm.getWage() << endl;

    system("pause");
    return 0;
}
