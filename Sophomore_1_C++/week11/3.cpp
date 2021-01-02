/*
写一个动态数组模板类，完成构造函数、析构函数、拷贝构造函数(注意深拷贝)、
并完成=，==，[]等重载。
*/

#include <iostream>
using namespace std;

template <class T>
class Sample{
private:
    T* x;
    int length;
public:
    Sample(int n = 0);
    ~Sample();
    Sample(Sample<T>& s);
    Sample<T>& operator=(const Sample<T>& s);
    bool operator==(const Sample<T>& s) const;
    Sample<T> operator+(const Sample<T>& s);
    Sample<T> operator++(int);  //后置++
    Sample<T>& operator++();    //前置++
    T operator[](int i);
    friend istream& operator>>(istream& in, Sample<T>& s){
        for(int i = 0;i < s.length;i++){
            cout << "input the " << (i+1) <<" number: ";
            in >> s.x[i];
        }
        return in;
    }
    friend ostream& operator<<(ostream& out, Sample<T>& s){
        for(int i = 0;i < s.length;i++){
            cout << s.x[i] << ends;
        }
        cout << endl;
        return out;
    }
};

template<class T>
Sample<T>::Sample(int n){
    this->x = new T[n];
    this->length = n;
}

template<class T>
Sample<T>::~Sample<T>(){
    delete[] x;
}

template<class T>
Sample<T>::Sample(Sample<T>& s){
    this->length = s.length;
    this->x = new T[length];
    memcpy(this->x, s.x,length * sizeof(T));
}

template<class T>
T Sample<T>::operator[](int i){
    return *(this->x + i);
}

template<class T>
Sample<T>& Sample<T>::operator=(const Sample<T>& s){
    if(this != &s){
        this->length = s.length;
        delete x;
        this->x = new T[this->length];
        memcpy(this->x, s.x,length*sizeof(T));
    }
    return *this;
}

template <class T>
bool Sample<T>::operator==(const Sample<T>& s) const{
    if(this->length == s.length){
        for(int i = 0;i < this->length;i++){
            if(this->x[i] != s.x[i]){
                return false;
            }
        }
        return true;
    }
    return false;
}

template <class T>
Sample<T> Sample<T>::operator+(const Sample<T>& s){
    Sample temp(this->length);
    for(int i = 0;i < this->length;i++){
        temp.x[i] = this->x[i] + s.x[i];
    }
    return temp;
}

template<class T>
Sample<T> Sample<T>::operator++(int){
    Sample old = *this;
    for(int i = 0;i < this->length;i++){
        this->x[i] = this->x[i] + 1;
    }
    return old;
}

template<class T>
Sample<T>& Sample<T>::operator++(){
    for(int i = 0;i < this->length;i++){
        this->x[i] = this->x[i] + 1;
    }
    return *this;
}

int main(){
    int N = 5;
    Sample<int> s1(N);
    Sample<int> s2(N);
    cin >> s1;
    cin >> s2;
    if(s1 == s2){
        cout << "s1 == s2" << endl;
    }
    cout << "s1: ";
    for(int i = 0;i < N;i++){
        cout << s1[i] << ends;
    }
    cout << endl;
    cout << "s2: ";
    for(int i = 0;i < N;i++){
        cout << s2[i] << ends;
    }
    cout << endl;
    system("pause");
    return 0;
}
