#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class MyString
{
public:
	MyString(const char *str = NULL);	//构造函数
	MyString(const MyString &str);		//拷贝构造函数
	~MyString();						//析构函数

	MyString operator+(const MyString &str) const;	//重载+
	bool operator==(const MyString &str) const;	//重载==
	char& operator[](int n) const;				//重载[]

	size_t size() const;		//获取长度
	const char* c_str() const;	//获取C字符串

	friend istream& operator>>(istream &is, MyString &str);//输入
	friend ostream& operator<<(ostream &os, MyString &str);//输出

private:
	char *data;		//字符串
	size_t length;	//长度
};

MyString::MyString(const char *str)//构造函数
{
	if (!str)
	{
		length = 0;
		data = new char[1];
		*data = '\0';
	}
	else
	{
		length = strlen(str);
		data = new char[length + 1];
		strcpy(data, str);
	}
}

MyString::MyString(const MyString &str)//拷贝构造函数
{
	length = str.size();
	data = new char[length + 1];
	strcpy(data, str.c_str());
}

MyString::~MyString()//析构函数
{
	delete []data;
	length = 0;
}

MyString MyString::operator+(const MyString &str) const //重载+
{
	MyString newString;
	newString.length = length + str.size();
	newString.data = new char[newString.length + 1];
	strcpy(newString.data, data);
	strcat(newString.data, str.data);
	return newString;
}

inline bool MyString::operator==(const MyString &str) const//重载==
{
	if (length != str.length)	return false;
	return strcmp(data, str.data) ? false : true;
}

inline char& MyString::operator[](int n) const//重载[]
{
	if (n >= length) return data[length-1];
	else return data[n];
}

inline size_t MyString::size() const//获取长度
{
	return length;
}

istream& operator>>(istream &is, MyString &str)//输入
{
	char tem[1000];  //简单的申请一块内存
	is >> tem;
	str.length = strlen(tem);
	str.data = new char[str.length + 1];
	strcpy(str.data, tem);
	return is;
}

ostream& operator<<(ostream &os, MyString &str)//输出
{
	os << str.data;
	return os;
}

inline const char* MyString::c_str() const//获取C字符串
{
	return data;
}

int main()
{   MyString k;
    cin >> k;
    MyString a("hello ");
    MyString b("world");
    MyString c = a + b;
    MyString a1(a);

    cout << k << "的长度为： " << k.size() << endl;
    cout << a << "的长度为： " << a.size() << endl;
    cout << b << "的长度为： " << b.size() << endl;
    cout << c << "的长度为： " << c.size() << endl;
    cout << c << "的第7个字符为: " << c[7] << endl;
    cout << a1 << "(拷贝）的长度为: " << a1.size() << endl; 
    system("pause");
    return 0;
}
