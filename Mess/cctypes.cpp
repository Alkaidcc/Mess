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
//****                     �ַ�����                     ****
//*********************************************************
/*
isalnum()  //�����������ĸ�������� ����true

isalpha()   //�����������ĸ ����true

iscntrl()   //��������ǿ����ַ� ����true

isdigit()   //�������������0-9 ����true

isgraph()   //��������ǳ��ո�֮��Ĵ�ӡ�ַ����ú�������true

islower()   //���������Сд��ĸ ����true

isprint()   //��������Ǵ�ӡ�ַ��������ո� ����true

ispunct()   //��������Ǳ����� ����true

isspace()   //��������Ǳ�׼�հ��ַ�����ո񣬽�ֽ�����з����س���ˮƽ�Ʊ�����ߴ�ֱ�Ʊ�� ����true

isupper()   //��������Ǵ�д��ĸ ����true

isxdigit()  //���������ʮ���������� ��0-9��a-f��A-F ����true

tolower()   //��������Ǵ�д�ַ��򷵻���Сд ���򷵻ظò���

toupper()   //���������Сд�ַ��򷵻����д�����򷵻ظò���
*/