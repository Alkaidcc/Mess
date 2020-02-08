#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

map<string,string> qq;

int main(){
    int N;
    char c;
    string account,password;
    scanf("%d",&N);
    while(N--){
        getchar();
        scanf("%c",&c);
        cin>>account;
        cin>>password;
        if(c=='L'){
            if(qq.find(account)==qq.end()){//不存在
                printf("ERROR: Not Exist\n");
            }
            else{
                if(qq[account]!=password)   //密码不对
                    printf("ERROR: Wrong PW\n");
                else
                    printf("Login: OK\n");            
            }
        }
        else if(c=='N'){
            if(qq.find(account)!=qq.end())  //已经存在此qq
                printf("ERROR: Exist\n");
            else{
                qq[account]=password;
                printf("New: OK\n");
            }
        }
    }
    return 0;
}