#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int main(){

    char ch;
    int count = 0;
    cout << "Enter characters: enter '#' to quit:\n";
    cin.get(ch);
    while(ch!='#')
    {
        cout << ch;         //>> 是会过滤掉不可见字符（如 空格 回车，TAB 等）
        ++count;
        cin.get(ch);    //逐个字符输入
    }
    cout << endl << count << "characters read\n";
    system("pause");
    return 0;
}