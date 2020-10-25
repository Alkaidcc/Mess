#ifndef CLIENT_H_
#define CLIENT_H_
#include <iostream>
using namespace std;
class CLIENT
{
private:
    static string ServerName;
    static int ClientNum;

public:
    CLIENT();
    ~CLIENT();
    CLIENT(string s);
    static void ChangeServerName(string s);
    int getClientNum(){return ClientNum;}
    string getServerName(){return ServerName;}
};
# endif
