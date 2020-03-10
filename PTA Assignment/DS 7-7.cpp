#include<iostream>
#include<stack>
#include<string>
#include<cstring>

using namespace std;

void Print(char ch){
    if(ch=='(')
        cout << "(-?" << endl;
    else if(ch=='[')
        cout << "[-?" << endl;
    else if(ch=='{')
        cout << "{-?" << endl;
    else if(ch=='<')
        cout << "/*-?" << endl;
}
int main(){
    string str;
    stack<char> s;
    bool flag = true;
    while (1){
        getline(cin,str);
        if(str[0] == '.' && str[1] == '\0')
            break;
        for(int i = 0;str[i]!='\0';i++){
            if(str[i] == '('||str[i] == '['||str[i] == '{')
                s.push(str[i]);
            else if(str[i] == '/' && str[i+1]=='*'){
                s.push('<');
                i++;
            }
            else if(str[i]==')'){
                if(!s.empty() && s.top()=='(')
                    s.pop();
                else{
                    cout << "NO" << endl;
                    flag=false;
                    if(s.empty())   //ǰ������Ŷ�ƥ���ˣ���ǰ�������Ǻ�����
                        cout << "?-)" << endl;
                    else{           //ջ����ǰ�����뵱ǰ�ĺ����Ų�ƥ��
                        Print(s.top());
                    }
                    break;
                }
            }
            else if(str[i]==']'){
                if(!s.empty() && s.top()=='[')
                    s.pop();
                else{
                    cout << "NO" << endl;
                    flag=false;
                    if(s.empty())   //ǰ������Ŷ�ƥ���ˣ���ǰ�������Ǻ�����
                        cout << "?-]" << endl;
                    else{           //ջ����ǰ�����뵱ǰ�ĺ����Ų�ƥ��
                        Print(s.top());
                    }
                    break;
                }
            }
            else if(str[i]=='}'){
                if(!s.empty() && s.top()=='{')
                    s.pop();
                else{
                    cout << "NO" << endl;
                    flag=false;
                    if(s.empty())   //ǰ������Ŷ�ƥ���ˣ���ǰ�������Ǻ�����
                        cout << "?-}" << endl;
                    else{           //ջ����ǰ�����뵱ǰ�ĺ����Ų�ƥ��
                        Print(s.top());
                    }
                    break;
                }
            }
            else if(str[i]=='*' && str[i+1]=='/'){
                i++;
                if(!s.empty() && s.top()=='<')
                    s.pop();
                else{
                    cout << "NO" << endl;
                    flag=false;
                    if(s.empty())   //ǰ������Ŷ�ƥ���ˣ���ǰ�������Ǻ�����
                        cout << "?-*/" << endl;
                    else{           //ջ����ǰ�����뵱ǰ�ĺ����Ų�ƥ��
                        Print(s.top());
                    }
                    break;
                }
            }

        }
    }
    if(flag && s.empty())
        cout << "YES" << endl;
    else if(flag){  //  ��"."֮ǰ������ǰ����
        cout << "NO" << endl;
        Print(s.top());
    }
    system("pause");
    return 0;
    
}