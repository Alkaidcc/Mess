/*
Filename		:4.cpp
Date			:2020/10/09 08:01:01
Author			:ZZC
Description     :struct student 
{

    int num;       //学号

    char name[20];  //姓名

    char gender;    //性别

    int age;        //年龄

    char addr[30];  //寝室

};
请定义2个结构体变量，初始化后通过swap()函数交换2个结构体变量的信息。
*/
#include <iostream>
using namespace std;
typedef struct student{
    int num;//学号
    char name[20];//姓名
    char gender;//性别
    int age;//年龄
    char addr[30];//寝室
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
