//输入10位同学的姓名，学号，成绩，并把这些学生的信息输出，每位学生一行。并输出最高分，最低分和平均分
#include<iostream>
#include<cstring>
#include<string>
#include<cfloat>
using namespace std;

typedef struct book{
    string name;
    int id;
    double score;
}book;

int main(){

    book Allstudents[10]={"",0,0.0};
    int i;
    double sum = 0.0;
    double max = DBL_MIN;
    double min = DBL_MAX;
    cout << "Please enter students information: " << endl;
    
    for(i=0;i<10;i++){
        cin >> Allstudents[i].name >> Allstudents[i].id >> Allstudents[i].score;
        sum += Allstudents[i].score;
    }
        
    cout << "Name\t\t" << "ID\t\t" << "Score" << endl;
    for(i=0;i<10;i++){
        if(Allstudents[i].score > max)
            max = Allstudents[i].score;
        if(Allstudents[i].score < min)
            min = Allstudents[i].score;
        cout << Allstudents[i].name;
        cout << "\t\t";
        cout << Allstudents[i].id;
        cout << "\t\t";
        cout << Allstudents[i].score << endl;
    }
    double average = sum/10;
    cout << "min = " << min << endl;
    cout << "max = " << max << endl;
    cout << "average = " <<average << endl;

    system("pause");
    return 0;

}
