#include <iostream>
#include <ctime>
using namespace std;

class Array
{
private:
    double* A;
    int arr_num;            //�洢����ĸ���
public:
    Array();
    Array(int m);
    ~Array();
    double getAve();        //��������ƽ��ֵ
    double getMax();        //�����������ֵ
    double getMin();        //����������Сֵ
    int getMaxIndex();      //�����������ֵ�±�
    int getMinIndex();      //����������Сֵ�±�

};

Array::Array()
{
}
Array::Array(int m){
    A = new double[m];
    arr_num = m;
    srand(unsigned(time(NULL)));
    for(int i = 0;i < m;i++){
        A[i] = rand() % 20 + 1;
        cout << A[i] << " ";
    }
    cout << endl;
}
Array::~Array()
{
    delete[] A;
}
double Array::getAve(){
    double sum = 0;
    for(int i = 0;i < arr_num;i++){
        sum += A[i];
    }
    return sum / arr_num;
}

double Array::getMax(){
    int max = -1e6;
    for(int i = 0;i < arr_num;i++){
        if(A[i] > max){
            max = A[i];
        }
    }
    return max;
}

double Array::getMin(){
    int min = 1e6;
    for(int i = 0;i < arr_num;i++){
        if(A[i] < min){
            min = A[i];
        }
    }
    return min;
}

int Array::getMaxIndex(){
    int index = 0;
    for(int i = 1;i < arr_num;i++){
        if(A[i] > A[index]){
            index = i;
        }
    }
    return index;
}

int Array::getMinIndex(){
    int index = 0;
    for(int i = 1;i < arr_num;i++){
        if(A[i] < A[index]){
            index = i;
        }
    }
    return index;
}

int main(){
    Array a(5);
    cout << "����ľ�ֵΪ: " << a.getAve() << endl;
    cout << "��������ֵΪ: " << a.getMax() << endl;
    cout << "�������СֵΪ: " << a.getMin() << endl;
    cout << "��������ֵ�±�Ϊ: " << a.getMaxIndex() << endl;
    cout << "�������Сֵ�±�Ϊ:" << a.getMinIndex() << endl;
    system("pause");
    return 0;
}
