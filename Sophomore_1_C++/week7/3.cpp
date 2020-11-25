/* 设计一个员工类Worker，包含姓名、年龄。再派生出一个经理类Manager，
包含职务和部门私有数据成员以及相关的成员函数。再派生出一个设计师类Designer，
包含职称和专业私有数据成员以及相关的成员函数。然后由Manager和Designer类派生出设计部经理类DesManager，
包含工资私有数据成员以及相关的成员函数。要求使用虚基类，并在main()中采用一些数据进行测试。
*/
#include <iostream>
using namespace std;

class Worker
{
private:
    string Name;    //姓名
    int Age;        //年龄
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
    string Position;        //职位
    string Department;      //部门
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
    string Title;       //职称
    string Major;       //专业
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
    double Wage;        //薪资
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
    Worker w("张三",25);
    Manager m("李四",23,"人力资源经理","人力资源管理部门");
    Designer d("王五",21,"艺术设计总监","视觉传达");
    DesManager dm("赵六",21,"电商部总监","电子商务","电子商务运营","电子商务运营部",6500);
    //test for Worker
    cout << "姓名: " << w.getName() << endl;
    cout << "年龄: " << w.getAge() << endl;
    cout << "-------------------------" << endl;

    //test for Manager
    cout << "姓名: " << m.getName() << endl;
    cout << "年龄: " << m.getAge() << endl;
    cout << "职位: " << m.getPosition() << endl;
    cout << "部门: " << m.getDepartment() << endl;
    cout << "-------------------------" << endl;

    //test for Designer
    cout << "姓名: " << d.getName() << endl;
    cout << "年龄: " << d.getAge() << endl;
    cout << "专业: " << d.getMajor() << endl;
    cout << "职称: " << d.getTitle() << endl;
    cout << "-------------------------" << endl;

    //test for DesManager
    cout << "姓名: " << dm.getName() << endl;
    cout << "年龄: " << dm.getAge() << endl;
    cout << "职位: " << dm.getPosition() << endl;
    cout << "部门: " << dm.getDepartment() << endl;
    cout << "专业: " << dm.getMajor() << endl;
    cout << "职称: " << dm.getTitle() << endl;
    cout << "薪资: " << dm.getWage() << endl;
    dm.setName("吴林");
    dm.setAge(22);
    dm.setMajor("风景园林");
    dm.setWage(5500);
    cout << "-------------------------" << endl;
    cout << "姓名: " << dm.getName() << endl;
    cout << "年龄: " << dm.getAge() << endl;
    cout << "职位: " << dm.getPosition() << endl;
    cout << "部门: " << dm.getDepartment() << endl;
    cout << "专业: " << dm.getMajor() << endl;
    cout << "职称: " << dm.getTitle() << endl;
    cout << "薪资: " << dm.getWage() << endl;

    system("pause");
    return 0;
}
