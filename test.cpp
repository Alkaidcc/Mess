#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
#define MAXN 100010
 
typedef struct Stu{
    char stuNum[10];
    char name[10];
    int grade;
}Stu;
Stu student[MAXN];
 
bool cmp1(Stu a,Stu b)
{
    return strcmp(a.stuNum,b.stuNum) < 0;
}
 
bool cmp2(Stu a,Stu b)
{
    if(strcmp(a.name, b.name) == 0)
        return cmp1(a, b);
    else return strcmp(a.name,b.name) < 0;
}
 
bool cmp3(Stu a,Stu b)
{
    if(a.grade == b.grade)
        return cmp1(a,b);
    else return a.grade < b.grade;
}
 
int main()
{
    int n,a;
    scanf("%d %d",&n,&a);
    for(int i = 0;i<n;i++)
    {
       scanf("%s %s %d",student[i].stuNum, student[i].name,&student[i].grade);
    }
    switch(a) {
        case 1:
            sort(student,student+n,cmp1);
            break;
        case 2:
            sort(student,student+n,cmp2);
            break;
        case 3:
            sort(student,student+n,cmp3);
            break;
    }
    for(int i = 0;i<n;i++)
    {
        printf("%s %s %d\n",student[i].stuNum, student[i].name, student[i].grade);
    }
    system("pause");
    return 0;
}