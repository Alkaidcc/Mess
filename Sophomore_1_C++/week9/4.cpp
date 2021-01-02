//�������塢����ģ�������ͣ�����������һ�������Ļ���containerΪ�����࣬�����ж����󣨱�����ͣ�����Ĵ��麯����ע�⣺�˻��౾����û�б������������Եġ����������ж���һ�������ĳ�Ա����radius������Ϊ������ı߳���Բ�İ뾶�����ɴ�������Ҫ������2���࣬����2��������д������������ķ�����
#include <iostream>
using namespace std;
const double PI = 3.1415;
class container
{
protected:
    double radius;
public:
    container(double r):radius(r){}
    virtual double getArea() = 0;
    virtual double getVolume() = 0;
};
class Cube:public container
{
private:
    
public:
    Cube(double s):container(s){}
    virtual double getArea(){return radius * radius * 6;}
    virtual double getVolume(){return radius * radius * radius;}
};

class Sphere:public container
{
private:
    
public:
    Sphere(double s):container(s){}
    virtual double getArea(){return 4 * PI * radius * radius;}
    virtual double getVolume(){return (4 * PI * radius * radius * radius) / 3.0; }
};



int main(){
    container* p;
    Cube c(3);
    Sphere s(5);
    //test for Cube & Sphere
    cout << "����������Ϊ: " << c.getArea() << endl;
    cout << "����������Ϊ: " << c.getVolume() << endl;
    cout << "��ı����Ϊ: " << s.getArea() << endl;
    cout << "������Ϊ: " << s.getVolume() << endl;
    //test for container*
    p = &c;
    cout << "����������Ϊ: " << p->getArea() << endl;
    cout << "����������Ϊ: " << p->getVolume() << endl;
    p = &s;
    cout << "��ı����Ϊ: " << p->getArea() << endl;
    cout << "������Ϊ: " << p->getVolume() << endl;
    system("pause");
    return 0;
}
