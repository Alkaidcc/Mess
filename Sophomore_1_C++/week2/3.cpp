/*
Filename		:3.cpp
Date			:2020/09/24 16:36:18
Author			:ZZC
Description     :��ʾ�û����㿼�˼��֣���������������ж���ȼ�������ʾ�ȼ����ţ�90--100������80--90���У�60--80����0--60��
*/
#include <iostream>

using namespace std;

int main(){
    double score;
    cout << "�㿼�˼��֣�" << endl;
    cin >> score;
    int x = score / 10;
    switch (x)
    {
    case 10:
        cout << "��" << endl;
        break;
    case 9:
        cout << "��" << endl;
        break;
    case 8:
        cout << "��" << endl;
        break;
    case 7:
        cout << "��" << endl;
        break;
    case 6:
        cout << "��" << endl;
        break;
    default:
        cout << "��" << endl;
        break;
    }
    system("pause");
    return 0;
}
