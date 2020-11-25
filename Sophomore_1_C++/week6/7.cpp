#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class MyString
{
public:
	MyString(const char *str = NULL);	//���캯��
	MyString(const MyString &str);		//�������캯��
	~MyString();						//��������

	MyString operator+(const MyString &str) const;	//����+
	bool operator==(const MyString &str) const;	//����==
	char& operator[](int n) const;				//����[]

	size_t size() const;		//��ȡ����
	const char* c_str() const;	//��ȡC�ַ���

	friend istream& operator>>(istream &is, MyString &str);//����
	friend ostream& operator<<(ostream &os, MyString &str);//���

private:
	char *data;		//�ַ���
	size_t length;	//����
};

MyString::MyString(const char *str)//���캯��
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

MyString::MyString(const MyString &str)//�������캯��
{
	length = str.size();
	data = new char[length + 1];
	strcpy(data, str.c_str());
}

MyString::~MyString()//��������
{
	delete []data;
	length = 0;
}

MyString MyString::operator+(const MyString &str) const //����+
{
	MyString newString;
	newString.length = length + str.size();
	newString.data = new char[newString.length + 1];
	strcpy(newString.data, data);
	strcat(newString.data, str.data);
	return newString;
}

inline bool MyString::operator==(const MyString &str) const//����==
{
	if (length != str.length)	return false;
	return strcmp(data, str.data) ? false : true;
}

inline char& MyString::operator[](int n) const//����[]
{
	if (n >= length) return data[length-1];
	else return data[n];
}

inline size_t MyString::size() const//��ȡ����
{
	return length;
}

istream& operator>>(istream &is, MyString &str)//����
{
	char tem[1000];  //�򵥵�����һ���ڴ�
	is >> tem;
	str.length = strlen(tem);
	str.data = new char[str.length + 1];
	strcpy(str.data, tem);
	return is;
}

ostream& operator<<(ostream &os, MyString &str)//���
{
	os << str.data;
	return os;
}

inline const char* MyString::c_str() const//��ȡC�ַ���
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

    cout << k << "�ĳ���Ϊ�� " << k.size() << endl;
    cout << a << "�ĳ���Ϊ�� " << a.size() << endl;
    cout << b << "�ĳ���Ϊ�� " << b.size() << endl;
    cout << c << "�ĳ���Ϊ�� " << c.size() << endl;
    cout << c << "�ĵ�7���ַ�Ϊ: " << c[7] << endl;
    cout << a1 << "(�������ĳ���Ϊ: " << a1.size() << endl; 
    system("pause");
    return 0;
}
