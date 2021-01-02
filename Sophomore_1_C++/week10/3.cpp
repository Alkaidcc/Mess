#include <iostream>
using namespace std;

template<class T>
class Sample
{
private:
    T s;
public:
    Sample();
    Sample(T a);
    bool operator==(const Sample<T>& s1) const;
    Sample<T> operator-(const Sample<T>& s1);
    Sample<T>& operator--();
    void show();
};

template<class T>
Sample<T>::Sample(T a):s(a){}

template<class T>
bool Sample<T>::operator==(const Sample<T>& s1) const{
    return this->s == s1.s;
}

template<class T>
Sample<T> Sample<T>::operator-(const Sample<T>& s1){
    return Sample(this->s - s1.s);
}

template<class T>
void Sample<T>::show(){
    cout << s << endl;
}

template<class T>
Sample<T>& Sample<T>::operator--(){
    --this->s;
    return *this;
}

template<class T>
Sample<T>::Sample(){}


int main(){
    Sample<int> s1(5),s2(8),s3;
    if(s1==s2){
        cout<<"s1ºÍs2ÏàµÈ";
    }
    s3=s1-s2;
    --s3;
    s3.show();
    system("pause");
    return 0;
}
