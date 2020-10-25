#include "client.h"
#include <iostream>
using namespace std;
CLIENT::CLIENT()
{
    ClientNum++;
}

CLIENT::~CLIENT()
{
    ClientNum--;
}
CLIENT::CLIENT(string s){
    ServerName = s;
    ClientNum++;
}
void CLIENT::ChangeServerName(string s){
    ServerName = s;
}
