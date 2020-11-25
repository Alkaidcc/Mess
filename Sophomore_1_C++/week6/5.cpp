#include <iostream>
#include <ctime>
#include <iomanip>
#include <cmath>
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
    void getVariance();
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

void Array::getVariance(){
    int sum = 0;
    double ave = 0;
    double temp_sum = 0;
    double var = 0;
    for(int i = 0;i < row;i++){
        for(int j = 0; j < col;j++){
            sum += A[i][j];
        }
    }
    ave = sum / (col * row);
    for(int i = 0;i < row;i++){
        for(int j = 0; j < col;j++){
            temp_sum += pow((abs(ave - A[i][j])),2);
        }
    }
    var = temp_sum / (col * row);
    cout << "该数组的方差为: " << var << endl;

}

int main(){
    Array a(3,5);
    a.getVariance();
    system("pause");
    return 0;
}
