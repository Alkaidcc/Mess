#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main(){

    char ch;
    int count = 0;
    cin.get(ch);                //����ַ�����
    while(cin.fail() == false){ //�ȼ���while��cin��
    //!=EOF   (ctrl+z+Enter)
        cout << ch;            //����ַ����
        ++count;
        cin.get(ch);            //����ַ�����
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