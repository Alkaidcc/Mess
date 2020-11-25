#include <iostream>
#include <string.h>
using namespace std;

class String
{
private:
    char* data;
    size_t length;
public:
    String(const char* str = NULL);
    String(const String& str);
    ~String();
    friend ostream& operator<<(ostream& out, const String& s);//重载<<
    //重载=
    String operator=(const String& s);
    String operator=(const char* c1);
    //重载+
    String operator+(const String& s);  
    String operator+(const char* c1);   
    //重载[]
    char& operator[](const int index);
    //重载==
    bool operator==(const String& s);
    bool operator==(const char* c1);

};
//重载[]
char& String::operator[](const int index){
    return *(data + index);
}
//构造函数
String::String(const char* str)
{
    if(str == nullptr){
        this->data = new char[1];
        data[0] = '\0';
        length = 0;
    }else{
        this->data = new char[strlen(str) + 1];
        strcpy(this->data, str);
        length = strlen(str);
    }
}
String::String(const String& str){
    this->length = str.length;
    data = new char[length + 1];
    strcpy(data, str.data);
}

//析构函数
String::~String()
{
    delete[] this->data;
    this->data = NULL;
}
//重载=
String String::operator=(const String& s){
    if(this == &s){
        return *this;
    }
    delete[] data;
    this->length = s.length;
    this->data = new char[strlen(s.data) + 1];
    strcpy(this->data,s.data);
    return *this;
}
String String::operator=(const char* c1){
    delete[] data;
    this->length = strlen(c1);
    this->data = new char[length + 1];
    strcpy(this->data,c1);
    return *this;

}
//重载+
String String::operator+(const String& s){
    String str;
    str.data = new char[strlen(this->data) + strlen(s.data) + 1];
    str.length = this->length + s.length;
    sprintf(str.data, "%s%s", this->data, s.data);
    return str;
}
String String::operator+(const char* c1){
    String str;
    str.data= new char[strlen(this->data) + strlen(c1) + 1];
    str.length = this->length + strlen(c1);
    sprintf(str.data, "%s%s", this->data,c1);
    return str;
}
//重载<<
ostream& operator<<(ostream& out, const String& s){
    out << s.data;
    return out;
}
//重载==
bool String::operator==(const String& s){
    if(s.length != this->length){
        return false;
    }
    for(int i = 0;i < s.length;i++){
        if(data[i] != s.data[i]){
            return false;
        }
    }
    return true;
}
bool String::operator==(const char* c1){
    if(this->length != strlen(c1)){
        return false;
    }
    for(int i = 0;i < length;i++){
        if(c1[i] != data[i]){
            return false;
        }
    }
    return true;
}



int main(){
    //test for String
    String str1("hello ");
    String str2("world!");
    String str3 = str1 + str2;
    if(str1 + str2 == str3){
        cout << "true" << endl;
    }else{
        cout << "false" << endl;
    }
    cout << str1 << endl;
    cout << str2 << endl;
    cout << str3 << endl;
    cout << "str3[11]: " << str3[11] << endl;
    // test for char*
    String s1 = "Who ";
    String s2 = "am ";
    String s3 = "I";
    String s4 = s1 + s2 + s3 + "?";
    if(s4 == "Who am I?"){
        cout << "true" << endl;
    }else{
        cout << "false" << endl;
    }
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s4 << endl;
    system("pause");
    return 0;
}
