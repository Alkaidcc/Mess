#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

class Array
{
private:
    int col;
    int row;
    double** A;
public:
    Array();
    Array(int r, int c);
    ~Array();
    void getValue();
};

Array::Array()
{
}
Array::Array(int r, int c){
    row = r;
    col = c;
    A = new double* [row];
    for(int i = 0;i < row;i++){
        A[i] = new double [col];
    }
    srand(unsigned(time(NULL)));
    for(int i = 0;i < row;i++){
        for(int j = 0;j < col;j++){
            A[i][j] = rand() % 20 + 1;
            cout << setw(4) << A[i][j] << setw(4);
        }
        cout << endl;
    }
}

Array::~Array()
{
    for(int i = 0; i < row;i++){
        delete[]A[i];
    }
    delete[] A;
}

void Array::getValue(){
    double sum = 0;
    double max = -1e6;
    double min = 1e6;
    for(int i = 0;i < row;i++){
        for(int j = 0; j < col;j++){
            sum += A[i][j];
            if(max < A[i][j])
                max = A[i][j];
            if(min > A[i][j])
                min = A[i][j];
        }
    }
    cout << "二维数组最大值为: " << max << endl;
    cout << "二维数组最小值为: " << min << endl;
    cout << "二维数组的平均值为: " << sum / (row * col) << endl;
}

int main(){
    Array a(3,5);
    a.getValue();
    system("pause");
    return 0;
}
