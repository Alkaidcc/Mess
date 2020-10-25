/*
Filename		:6.cpp
Date			:2020/10/16 15:20:38
Author			:ZZC
Description     :创建一个学生寝室类StuRoom，该类能表示寝室名、寝室电话、4个学生。该类中有构造函数、
                changeRoomName()、changeNum()函数能改变寝室的信息，display()函数把完整的寝室信息打印出来。（学生类有姓名、学号、学院、专业4个属性）
*/
#include <iostream>
using namespace std;

enum College{IT = 1,Art, Math, Garden};
enum Major{CS = 1,EE, CE};
class Student
{
private:
    string name;
    string ID;
    College college;
    Major major;
public:
    Student();
    Student(string n, string id, College c, Major m):name(n),ID(id),college(c),major(m){}
    void setName(string n){name = n;}
    void setID(string id){ID = id;}
    void setCollege(College c){college = c;}
    void setMajor(Major m){major = m;}
    void display();
    ~Student();
};

Student::Student(){}

Student::~Student(){}
void Student::display(){
    cout << "学生姓名: " << name << endl;
    cout << "学生学号: " << ID << endl;
    cout << "学院： " << college << endl;
    cout << "专业： " << major << endl;
}

class StuRoom
{
private:
    string Room_name;
    string Phonenumber;
    Student stu_info[4];

public:
    StuRoom();
    StuRoom(string room_name, string phone_number):Room_name(room_name),Phonenumber(phone_number){
        stu_info[0].setID("201905010330");
        stu_info[0].setMajor(CS);
        stu_info[0].setCollege(IT);
        stu_info[0].setName("张三");

        stu_info[1].setID("201905010311");
        stu_info[1].setMajor(EE);
        stu_info[1].setCollege(Art);
        stu_info[1].setName("李四");

        stu_info[2].setID("201905010326");
        stu_info[2].setMajor(CE);
        stu_info[2].setCollege(Garden);
        stu_info[2].setName("王五");

        stu_info[3].setID("201905010323");
        stu_info[3].setMajor(CS);
        stu_info[3].setCollege(Math);
        stu_info[3].setName("赵六");
    }
    void changeRoomName(string room_name);
    void changeNum(string room_name, string phone_number);
    void display();
    ~StuRoom();
};

StuRoom::StuRoom(){}
StuRoom::~StuRoom(){}
void StuRoom::changeNum(string room_name, string phone_number){
    Room_name = room_name;
    Phonenumber = phone_number;
}
void StuRoom::changeRoomName(string room_name){
    Room_name = room_name;
}
void StuRoom::display(){
    cout << "寝室名: " << Room_name << endl;
    cout << "寝室电话: " << Phonenumber << endl;
    for(int i = 0;i < 4;i++){
        stu_info[i].display();
    }
}

int main(){
    StuRoom sr("A4310","16759807522");
    sr.display();
    cout << "修改寝室信息：" << endl;
    sr.changeNum("A4311","12345678990");
    sr.display();
    cout << "修改寝室名" << endl;
    sr.changeRoomName("A3332");
    sr.display();
    system("pause");
    return 0;
}
