#include<iostream>
#include<string>
using namespace std;

int main(){
    int N,size;
    int flag=0;
    string str;
    bool book = true;
    cin >> N >>size;
    for(int i=0;i<N;i++){
        cin >> str;
        int length=str.length();
        for(int j=0;j<length;j++){
            if(str[j]=='S'){
                if(flag<size)
                    flag++;
                else{
                    book = false;
                    break;
                }
            }
            else{
                if(flag)
                    flag--;
                else{
                    book = false;
                    break;
                }
            }
        }
        if(flag==0&&book)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        flag=0;
        book=true;
    }
    system("pause");
    return 0;
}