/*
Filename		:4.cpp
Date			:2020/10/09 08:01:01
Author			:ZZC
Description     :struct student 
{

    int num;       //ѧ��

    char name[20];  //����

    char gender;    //�Ա�

    int age;        //����

    char addr[30];  //����

};
�붨��2���ṹ���������ʼ����ͨ��swap()��������2���ṹ���������Ϣ��
*/
#include <iostream>
using namespace std;
typedef struct student{
    int num;//ѧ��
    char name[20];//����
    char gender;//�Ա�
    int age;//����
    char addr[30];//����
}student;

void my_swap(student& a, student& b);
void my_swap(student& a, student& b){
    student temp;
    temp = a;
    a = b;
    b = temp;
}

int main(){
    student a = {
        30,
        "zzc",
        'f',
        20,
        "310"
    };
    student b = {
        16,
        "Tom",
        'm',
        22,
        "309"
    };
    cout << a.num << " " << a.name << " " << a.gender << " " << a.age << " " << a.addr << endl;
    cout << b.num << " " << b.name << " " << b.gender << " " << b.age << " " << b.addr << endl;
    my_swap(a, b);
    cout << "after swapping: " << endl;
    cout << a.num << " " << a.name << " " << a.gender << " " << a.age << " " << a.addr << endl;
    cout << b.num << " " << b.name << " " << b.gender << " " << b.age << " " << b.addr << endl;
    system("pause");
    return 0;
}
