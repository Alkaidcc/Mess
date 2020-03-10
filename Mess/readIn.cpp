#include<iostream>
#include<fstream>
#include<cstdlib>
const int SIZE = 60;

int main(){
    using namespace std;
    char filename[SIZE];
    ifstream inFile;    //定义一个ifstream类型的对象
    cout << "Enter name of data file: ";
    cin.getline(filename,SIZE);
    inFile.open(filename);  //与文件关联
    if(!inFile.is_open()){  //判断是否能打开
        cout << "Could not open the file " << filename << endl;
        cout << "Program terminating.\n";
        exit(EXIT_FAILURE);
    }
    double value;
    double sum =0.0;
    int count = 0;
    inFile >> value;
    while(inFile.good()){
        ++count;
        sum+=value;
        inFile >> value;
    }
    // while(inFile >> value){
    //     ++count;
    //     sum += value;
    // }
    if(inFile.eof())//是否读到了末尾
        cout << "End of file reached.\n";
    else if (inFile.fail()) //数据类型有没有错误
        cout << "Input terminated by data mismatch.\n";
    else
        cout << "Input terminated for unknown reason.\n";
    if(count == 0)
        cout << "No data processed.\n";
    else{
        cout << "Items read: " << count << endl;
        cout << "Sum: " << sum << endl;
        cout << "Average: " << sum / count << endl;

    }
    inFile.close();
    system("pause");
    return 0;
}