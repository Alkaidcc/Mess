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
    Student s("张三",20,"浙江","13754869544");
    StuCollege sc("李四",21,"湖南","18266495315","信息工程学院","计算机科学与技术","A4310","大二");
    StuZAFU sz("王五",22,"河南","13654952188","艺术设计学院","服装设计","A6210","大三","东湖校区");
    
    //test for Student
    cout << "姓名: " << s.getName() << endl;
    cout << "年龄: " << s.getAge() << endl;
    cout << "籍贯: " << s.getHometown() << endl;
    cout << "手机号码: " << s.getPhoneNumber() << endl;
    cout << "-------------------------" << endl;

    //test for StuCollege
    cout << "姓名: " << sc.getName() << endl;
    cout << "年龄: " << sc.getAge() << endl;
    cout << "籍贯: " << sc.getHometown() << endl;
    cout << "手机号码: " << sc.getPhoneNumber() << endl;
    cout << "住址: " << sc.getAddress() << endl;
    cout << "学院: " << sc.getCollege() << endl;
    cout << "年级: " << sc.getGrade() << endl;
    cout << "专业: " << sc.getMajor() << endl;
    cout << "-------------------------" << endl;

    //test for StuZAFU
    cout << "姓名: " << sz.getName() << endl;
    cout << "年龄: " << sz.getAge() << endl;
    cout << "籍贯: " << sz.getHometown() << endl;
    cout << "手机号码: " << sz.getPhoneNumber() << endl;
    cout << "住址: " << sz.getAddress() << endl;
    cout << "学院: " << sz.getCollege() << endl;
    cout << "年级: " << sz.getGrade() << endl;
    cout << "专业: " << sz.getMajor() << endl;
    cout << "校区: " << sz.getCampus() << endl;
    sz.setAddress("A4310");
    sz.setAge(18);
    sz.setCampus("衣锦校区");
    cout << "-------------------------" << endl;
    cout << "姓名: " << sz.getName() << endl;
    cout << "年龄: " << sz.getAge() << endl;
    cout << "籍贯: " << sz.getHometown() << endl;
    cout << "手机号码: " << sz.getPhoneNumber() << endl;
    cout << "住址: " << sz.getAddress() << endl;
    cout << "学院: " << sz.getCollege() << endl;
    cout << "年级: " << sz.getGrade() << endl;
    cout << "专业: " << sz.getMajor() << endl;
    cout << "校区: " << sz.getCampus() << endl;
    system("pause");
    return 0;
}
