#include <iostream>
using namespace std;
const int N = 10;

class MyInt
{
private:
	int x;
public:
	MyInt(int i = 0):x(i){}
	bool operator==(const MyInt& i);
	MyInt operator+(const MyInt& i);
	MyInt& operator=(const MyInt& i);
	MyInt operator++(int);
	MyInt& operator++();
	friend ostream& operator<<(ostream& out, const MyInt& i);
};
ostream& operator<<(ostream& out, const MyInt& i){
	out << i.x << " ";
	return out;
}
bool MyInt::operator==(const MyInt& i){
	return  i.x == this->x;
}
MyInt MyInt::operator+(const MyInt& i){
	return MyInt(this->x+i.x);
}
MyInt& MyInt::operator=(const MyInt& i){
	this->x = i.x;
	return *this;
}
MyInt MyInt::operator++(int){
	MyInt old = *this;
	++(*this);
	return old;
}
MyInt& MyInt::operator++(){
	this->x++;
	return *this;
}

class MyArray
{
private:
	int x[N];
public:
	MyArray(int r = 0);
	bool operator==(const MyArray& a);
	MyArray operator+(const MyArray& a);
	MyArray& operator=(const MyArray& a);
	MyArray& operator++();
	MyArray operator++(int);
	friend ostream& operator<<(ostream& out, const MyArray& a);
};
MyArray::MyArray(int r){
	for(int i = 0;i < N;i++){
		this->x[i] = i + r;
	}
}
bool MyArray::operator==(const MyArray& a){
	for(int i = 0;i < N;i++){
		if(this->x[i] != a.x[i]){
			return false;
		} 
	}
	return true;
}
MyArray MyArray::operator+(const MyArray& a){
	MyArray temp;
	for(int i = 0;i < N;i++){
		temp.x[i] = this->x[i] + a.x[i];
	}
	return temp;
}
MyArray& MyArray::operator=(const MyArray& a){
	for(int i = 0;i < N;i++){
		this->x[i] = a.x[i];
	}
	return *this;
}
MyArray& MyArray::operator++(){
	for(int i = 0;i < N;i++){
		this->x[i]++;
	}
	return *this;
}
MyArray MyArray::operator++(int){
	MyArray temp = *this;
	++(*this);
	return temp;
}
ostream& operator<<(ostream& out, const MyArray& a){
	for(int i = 0;i < N;i++){
		out << a.x[i] << " ";
	}
	out << endl;
	return out;
}


class MyMatrix
{
private:
	int x[N][N];
public:
	MyMatrix(int r = 0);
	bool operator!=(const MyMatrix& b);
	MyMatrix operator-(const MyMatrix& b);
	MyMatrix& operator=(const MyMatrix& b);
	MyMatrix& operator--();
	MyMatrix operator--(int);
	friend ostream& operator<<(ostream& out, const MyMatrix& m);
};
MyMatrix::MyMatrix(int r){
	int c = 0;
	for(int i = 0;i < N;i++){
		for(int j = 0;j < N;j++){
			this->x[i][j] = (c++) + r;
		}
	}
}
bool MyMatrix::operator!=(const MyMatrix& b){
	for(int i = 0;i < N;i++){
		for(int j = 0;j < N;j++){
			if(this->x[i][j] != b.x[i][j]){
				return true;
			}
		}
	}
	return false;
}
MyMatrix MyMatrix::operator-(const MyMatrix& b){
	MyMatrix temp = *this;
	for(int i = 0;i < N;i++){
		for(int j = 0;j < N;j++){
			temp.x[i][j] -= b.x[i][j];
		}
	}
	return temp;
}
MyMatrix& MyMatrix::operator=(const MyMatrix& b){
	for(int i = 0;i < N;i++){
		for(int j = 0;j < N;j++){
			this->x[i][j] = b.x[i][j];
		}
	}
	return *this;
}
MyMatrix& MyMatrix::operator--(){
	for(int i = 0;i < N;i++){
		for(int j = 0;j < N;j++){
			this->x[i][j]--;
		}
	}
	return *this;
}
MyMatrix MyMatrix::operator--(int){
	MyMatrix old = *this;
	--(*this);
	return old;
}
ostream& operator<<(ostream& out, const MyMatrix& m){
	for(int i = 0;i < N;i++){
		for(int j = 0;j < N;j++){
			out << m.x[i][j] << " ";
		}
		out << endl;
	}
	return out;
}


int main(){
	// MyInt a(1);
	// MyInt b(2);
	// MyInt c = a + b;
	// MyInt d = a++;
	// ++b;
	// cout << a << " " << b << " " << c << " " << d << " ";
	// if(a == b){
	// 	cout << "a == b" << endl;
	// }else{
	// 	cout << "a != b" << endl;
	// }
	// MyArray arr1(1);
	// MyArray arr2(2);
	// if(arr1 == arr2){
	// 	cout << "arr1 == arr2" << endl;
	// }else{
	// 	cout << "arr1 != arr2" << endl;
	// }
	// MyArray arr3 = arr1;
	// MyArray arr4 = arr1 + arr2;
	// arr1++;
	// ++arr2;
	// cout << arr1 << arr2 << arr3 << arr4;
	MyMatrix ma1(1);
	MyMatrix ma2(2);
	if(ma1 != ma2){
		cout << "ma2 != ma1" << endl;
	}else{
		cout << "ma2 == ma1" << endl;
	}
	MyMatrix ma3 = ma2 - ma1;
	MyMatrix ma4 = ma1;
	ma1--;
	--ma2;
	cout << ma1 << ma2 << ma3 << ma4 << endl;
	system("pause");
	return 0;
}
