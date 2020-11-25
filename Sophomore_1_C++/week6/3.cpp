#include <iostream>
#include <ctime>
using namespace std;

class Array
{
private:
    int* p;
    int arr_num;            //�洢����ĸ���
public:
    Array();
    Array(int m);
    ~Array();
    double getMax();        //�����������ֵ

};

Array::Array()
{
}
Array::Array(int m){
    p = new int[m];
    arr_num = m;
    srand(unsigned(time(NULL)));
    for(int i = 0;i < m;i++){
        p[i] = rand() % 20 + 1;
        cout << p[i] << " ";
    }
    cout << endl;
}
Array::~Array()
{
    delete[] p;
}


double Array::getMax(){
    int max = -1e6;
    for(int i = 0;i < arr_num;i++){
        if(p[i] > max){
            max = p[i];
        }
    }
    return max;
}

int main(){
    Array a(5);
    cout << "��������ֵΪ: " << a.getMax() << endl;
    system("pause");
    return 0;
}
