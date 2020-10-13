/*
Filename		:alg_1.cpp
Date			:2020/09/29 19:19:05
Author			:ZZC
Description     :����ư�����ߡ�ѧ���Ա���Ϣ��ѧ���ṹ��
                 �������n(n>10)��ѧ��������ѧ������߰������������
                 ��ӡ������������ʹ��STL���е�sort�㷨��
*/
#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

typedef struct Stu
{
    double height;
    string sex;
    
}Stu;

void random_Initial(Stu& student){
    student.sex = (rand() % 2 == 0) ? "male" : "female";
    student.height = (student.sex == "male") ? rand() % 21 + 160 : rand() % 21 + 150;
}

bool comparison(Stu a, Stu b){
    return a.height > b.height;
}

int main(){
    int n;
    cout << "Please input the number of student: ";
    cin >> n;
    Stu stu_Info[n]; 
    srand(time(NULL));
    for(int i = 0;i < n;i++){
        random_Initial(stu_Info[i]);
    }
    for(int i = 0;i < n;i++){
        cout << "( " << stu_Info[i].height << ", " << stu_Info[i].sex << " )" << endl;
    }
    cout << "After sorting: " << endl;
    sort(stu_Info, stu_Info + n,comparison);
    for(int i = 0; i < n;i++){
        cout << "( " << stu_Info[i].height << ", " << stu_Info[i].sex << " )" << endl;
    }

    system("pause");
    return 0;
}
