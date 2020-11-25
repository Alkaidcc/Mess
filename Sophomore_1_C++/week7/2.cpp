#include <iostream>
using namespace std;

class Student
{
private:
    string Name;
    int Age;
    string Hometown;
    string PhoneNumber;
public:
    Student(string name, int age, string home, string phone):Name(name),Age(age),Hometown(home),PhoneNumber(phone){}
    string getName() {return Name;}
    string getHometown() {return Hometown;}
    int getAge() {return Age;}
    string getPhoneNumber(){return PhoneNumber;}
    void setAge(int age);
    void setName(string name);
    void setHometown(string hometown);
    void setPhoneNumber(string number);
};

class StuCollege:public Student
{
private:
    string College;
    string Major;
    string Address;
    string Grade;
public:
    StuCollege(string name, int age, string home, string phone,string college, string major, string address, string grade):
    Student(name,age,home,phone), College(college), Major(major), Address(address), Grade(grade){}
    string getCollege(){return College;}
    string getMajor(){return Major;}
    string getAddress(){return Address;}
    string getGrade(){return Grade;}
    void setCollege(string college);
    void setMajor(string major);
    void setAddress(string address);
    void setGrade(string grade);

};

class StuZAFU:public StuCollege
{
private:
    string Campus;
public:
    StuZAFU(string name, int age, string home, string phone,string college, string major, string address, string grade, string campus):
    StuCollege(name,age,home,phone,college,major,address,grade),Campus(campus){}
    string getCampus(){return Campus;}
    void setCampus(string campus);

};

void Student::setAge(int age){
    this->Age = age;
}
void Student::setHometown(string hometown){
    this->Hometown = hometown;
}
void Student::setName(string name){
    this->Name = name;
}
void Student::setPhoneNumber(string number){
    this->PhoneNumber = number;
}
void StuCollege::setAddress(string address){
    this->Address = address;
}
void StuCollege::setCollege(string college){
    this->College = college;
}
void StuCollege::setGrade(string grade){
    this->Grade = grade;
}
void StuCollege::setMajor(string major){
    this->Grade = major;
}
void StuZAFU::setCampus(string campus){
    this->Campus = campus;
}



int main(){
    Student s("����",20,"�㽭","13754869544");
    StuCollege sc("����",21,"����","18266495315","��Ϣ����ѧԺ","�������ѧ�뼼��","A4310","���");
    StuZAFU sz("����",22,"����","13654952188","�������ѧԺ","��װ���","A6210","����","����У��");
    
    //test for Student
    cout << "����: " << s.getName() << endl;
    cout << "����: " << s.getAge() << endl;
    cout << "����: " << s.getHometown() << endl;
    cout << "�ֻ�����: " << s.getPhoneNumber() << endl;
    cout << "-------------------------" << endl;

    //test for StuCollege
    cout << "����: " << sc.getName() << endl;
    cout << "����: " << sc.getAge() << endl;
    cout << "����: " << sc.getHometown() << endl;
    cout << "�ֻ�����: " << sc.getPhoneNumber() << endl;
    cout << "סַ: " << sc.getAddress() << endl;
    cout << "ѧԺ: " << sc.getCollege() << endl;
    cout << "�꼶: " << sc.getGrade() << endl;
    cout << "רҵ: " << sc.getMajor() << endl;
    cout << "-------------------------" << endl;

    //test for StuZAFU
    cout << "����: " << sz.getName() << endl;
    cout << "����: " << sz.getAge() << endl;
    cout << "����: " << sz.getHometown() << endl;
    cout << "�ֻ�����: " << sz.getPhoneNumber() << endl;
    cout << "סַ: " << sz.getAddress() << endl;
    cout << "ѧԺ: " << sz.getCollege() << endl;
    cout << "�꼶: " << sz.getGrade() << endl;
    cout << "רҵ: " << sz.getMajor() << endl;
    cout << "У��: " << sz.getCampus() << endl;
    sz.setAddress("A4310");
    sz.setAge(18);
    sz.setCampus("�½�У��");
    cout << "-------------------------" << endl;
    cout << "����: " << sz.getName() << endl;
    cout << "����: " << sz.getAge() << endl;
    cout << "����: " << sz.getHometown() << endl;
    cout << "�ֻ�����: " << sz.getPhoneNumber() << endl;
    cout << "סַ: " << sz.getAddress() << endl;
    cout << "ѧԺ: " << sz.getCollege() << endl;
    cout << "�꼶: " << sz.getGrade() << endl;
    cout << "רҵ: " << sz.getMajor() << endl;
    cout << "У��: " << sz.getCampus() << endl;
    system("pause");
    return 0;
}
