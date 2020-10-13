/*
Filename		:3.cpp
Date			:2020/09/24 16:36:18
Author			:ZZC
Description     :提示用户“你考了几分？”，接收输入后判断其等级，并显示等级（优：90--100；良：80--90；中：60--80；差0--60）
*/
#include <iostream>

using namespace std;

int main(){
    double score;
    cout << "你考了几分？" << endl;
    cin >> score;
    int x = score / 10;
    switch (x)
    {
    case 10:
        cout << "优" << endl;
        break;
    case 9:
        cout << "优" << endl;
        break;
    case 8:
        cout << "良" << endl;
        break;
    case 7:
        cout << "中" << endl;
        break;
    case 6:
        cout << "中" << endl;
        break;
    default:
        cout << "差" << endl;
        break;
    }
    system("pause");
    return 0;
}
