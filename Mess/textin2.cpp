#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main(){

    char ch;
    int count = 0;
    cin.get(ch);                //逐个字符输入
    while(cin.fail() == false){ //等价于while（cin）
    //!=EOF   (ctrl+z+Enter)
        cout << ch;            //逐个字符输出
        ++count;
        cin.get(ch);            //逐个字符输入
    }
    cout << endl << count << "characters read \n";
    system("pause");
    return 0;
}
// int main(){

//     char ch;
//     int count = 0;
//                     
//     while(cin.get(ch)){
//         cout << ch;           
//         ++count;               
//     }
//     cout << endl << count << "characters read \n";
//     system("pause");
//     return 0;
// }