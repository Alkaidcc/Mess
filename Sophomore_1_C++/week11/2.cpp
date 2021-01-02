/*
编写一个模板类，内有2个模板，2个成员变量分别为该2种模板的类型。
请实现构造函数，拷贝构造函数，“=”，“==”，“+”，前置“++”，后置“++”的运算符重载。
*/
#include <iostream>
using namespace std;
template <class T,class P>
class Sample{
private:
    T* x;
    P* y;
    int length_x;
    int length_y;
public:
    Sample(int l_x = 0,int l_y = 0);
    ~Sample();
    Sample(Sample<T,P>& s);
    Sample<T,P>& operator=(const Sample<T,P>& s);
    bool operator==(const Sample<T,P>& s) const;
    Sample<T,P> operator+(const Sample<T,P>& s);
    Sample<T,P> operator++(int);  //后置++
    Sample<T,P>& operator++();    //前置++
    T* getX(){return x;}
    P* getY(){return y;}
    int getLx(){return length_x;}
    int getLy(){return length_y;}
    friend istream& operator>>(istream& in, Sample<T,P>& s){
        int l_x = s.getLx();
        int l_y = s.getLy();
        for(int i = 0;i < l_x;i++){
            cout << "input the T" << (i+1) << " number: ";
            in >> *(s.getX()+i);
        }
        for(int j = 0;j < l_y;j++){
            cout << "input the P" << (j+1) << " number: ";
            cin >> *(s.getY()+j);
        }
        return in;
    }
    friend ostream& operator<<(ostream& out, Sample<T,P>& s){
        int l_x = s.getLx();
        int l_y = s.getLy();
        cout << "output the T:" << endl;
        for(int i = 0;i < l_x;i++){
            cout << *(s.getX()+i) << ends;
        }
        cout << endl;
        cout << "output the P:" << endl;
        for(int j = 0;j < l_y;j++){
            cout << *(s.getY()+j) << ends;
        }
        cout << endl;
        return out;
    }
};

template<class T,class P>
Sample<T,P>::Sample(int l_x, int l_y){
    this->x = new T[l_x];
    this->y = new P[l_y];
    this->length_x = l_x;
    this->length_y = l_y;
}

template <class T,class P>
Sample<T,P>::~Sample<T,P>(){
    delete[] x;
    delete[] y;
}

template <class T,class P>
Sample<T,P>::Sample(Sample<T,P>& s){
    this->length_x = s.length_x;
    this->length_y = s.length_y;
    this->x = new T[length_x];
    this->y = new P[length_y];
    memcpy(this->x, s.x,length_x * sizeof(T));
    memcpy(this->y, s.y,length_y * sizeof(P));
}

template <class T,class P>
Sample<T,P>& Sample<T,P>::operator=(const Sample<T,P>& s){
    if(this != &s){
        this->length_x = s.length_x;
        this->length_y = s.length_y;
        delete y;
        delete x;
        this->x = new T[this->length_x];
        this->y = new P[this->length_y];
        memcpy(this->x, s.x, length_x * sizeof(T));
        memcpy(this->y, s.y, length_y * sizeof(P));
    }
    return *this;
}

template <class T,class P>
bool Sample<T,P>::operator==(const Sample<T,P>& s) const{
    if(this->length_x == s.length_x && this->length_y == s.length_y){
        for(int i = 0;i < this->length_x;i++){
            if(this->x[i] != s.x[i]){
                return false;
            }
        }
        for(int j = 0;j < this->length_y;j++){
            if(this->y[j] != s.y[j]){
                return false;
            }
        }
        return true;
    }
    return false;
}

template <class T,class P>
Sample<T,P> Sample<T,P>::operator+(const Sample<T,P>& s){
    Sample temp(this->length_x, this->length_y);
    for(int i = 0;i < this->length_x;i++){
        temp.x[i] = this->x[i] + s.x[i];
    }
    for(int j = 0;j < this->length_y;j++){
        temp.y[j] = this->y[j] + s.y[j];
    }
    return temp;
}

template <class T,class P>
Sample<T,P> Sample<T,P>::operator++(int){
    Sample old = *this;
    for(int i = 0;i < this->length_x;i++){
        this->x[i] = this->x[i] + 1;
    }
    for(int j = 0;j < this->length_y;j++){
        this->y[j] = this->y[j] + 1;
    }
    return old;
}

template <class T,class P>
Sample<T,P>& Sample<T,P>::operator++(){
    for(int i = 0;i < this->length_x;i++){
        this->x[i] = this->x[i] + 1;
    }
    for(int j = 0;j < this->length_y;j++){
        this->y[j] = this->y[j] + 1;
    }
    return *this;
}

int main(){
    int n_x = 5;
    int n_y = 3;
    Sample<int,double> s1(n_x,n_y);
    Sample<int,double> s2(n_x,n_y);
    cin >> s1;
    cin >> s2;
    Sample<int,double> s3;
    s3 = s1 + s2;
    if(s1 == s2){
        cout << "s1 == s2" << endl;
    }
    cout << s3;
    s1++;
    cout << s1;
    cout << (++s2);
    system("pause");
    return 0;
}
