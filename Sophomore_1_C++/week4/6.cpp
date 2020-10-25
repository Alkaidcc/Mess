/*
Filename		:6.cpp
Date			:2020/10/16 15:20:38
Author			:ZZC
Description     :����һ��ѧ��������StuRoom�������ܱ�ʾ�����������ҵ绰��4��ѧ�����������й��캯����
                changeRoomName()��changeNum()�����ܸı����ҵ���Ϣ��display()������������������Ϣ��ӡ��������ѧ������������ѧ�š�ѧԺ��רҵ4�����ԣ�
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
    cout << "ѧ������: " << name << endl;
    cout << "ѧ��ѧ��: " << ID << endl;
    cout << "ѧԺ�� " << college << endl;
    cout << "רҵ�� " << major << endl;
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
        stu_info[0].setName("����");

        stu_info[1].setID("201905010311");
        stu_info[1].setMajor(EE);
        stu_info[1].setCollege(Art);
        stu_info[1].setName("����");

        stu_info[2].setID("201905010326");
        stu_info[2].setMajor(CE);
        stu_info[2].setCollege(Garden);
        stu_info[2].setName("����");

        stu_info[3].setID("201905010323");
        stu_info[3].setMajor(CS);
        stu_info[3].setCollege(Math);
        stu_info[3].setName("����");
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
    cout << "������: " << Room_name << endl;
    cout << "���ҵ绰: " << Phonenumber << endl;
    for(int i = 0;i < 4;i++){
        stu_info[i].display();
    }
}

int main(){
    StuRoom sr("A4310","16759807522");
    sr.display();
    cout << "�޸�������Ϣ��" << endl;
    sr.changeNum("A4311","12345678990");
    sr.display();
    cout << "�޸�������" << endl;
    sr.changeRoomName("A3332");
    sr.display();
    system("pause");
    return 0;
}
