#include "client.cpp"
#include <iostream>
using namespace std;
int CLIENT::ClientNum = 0;
string CLIENT::ServerName = "";
int main(){
    CLIENT a1("first");
    cout << a1.getClientNum() << endl;
    cout << a1.getServerName() << endl;
    CLIENT a2("second");
    a2.ChangeServerName("third");
    cout << a2.getClientNum() << endl;
    cout << a2.getServerName() << endl;
    CLIENT a3;
    cout << a3.getClientNum() << endl;
    cout << a3.getServerName() << endl;
    system("pause");
    return 0;
}
