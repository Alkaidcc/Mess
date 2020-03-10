#include<iostream>
#include<cstring>
#include<string>
#include<cctype>
using namespace std;
int main(){
    cout << "Enter text for analysis, and type @"
            " to terminate input.\n";
    char ch;
    int whitespace = 0;
    int digits = 0;
    int chars = 0;
    int punct = 0;
    int others = 0;

    cin.get(ch);
    while(ch != '@'){
        if(isalpha(ch))
            chars++;
        else if(isspace(ch))
            whitespace++;
        else if(isdigit(ch))
            digits++;
        else if(ispunct(ch))
            punct++;
        else
            others++;
        cin.get(ch);
    }
    cout << chars << " letters, " << whitespace << " whitespace, "
         << digits << " digits, " << punct << " punctuations, "
         << others << " others.\n";

    system("pause");
    return 0;
}

//*********************************************************
//****                     字符函数                     ****
//*********************************************************
/*
isalnum()  //如果参数是字母或者数字 返回true

isalpha()   //如果参数是字母 返回true

iscntrl()   //如果参数是控制字符 返回true

isdigit()   //如果参数是数字0-9 返回true

isgraph()   //如果参数是除空格之外的打印字符，该函数返回true

islower()   //如果参数是小写字母 返回true

isprint()   //如果参数是打印字符（包括空格） 返回true

ispunct()   //如果参数是标点符号 返回true

isspace()   //如果参数是标准空白字符，如空格，进纸，换行符，回车，水平制表符或者垂直制表符 返回true

isupper()   //如果参数是大写字母 返回true

isxdigit()  //如果参数是十六进制数字 即0-9，a-f或A-F 返回true

tolower()   //如果参数是大写字符则返回其小写 否则返回该参数

toupper()   //如果参数是小写字符则返回其大写，否则返回该参数
*/