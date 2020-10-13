#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

const int PRICE = 9856;
class Product{
private:
    int price;
public:
    Product(int p):price(p){
        int id,pro_price;
        ifstream readFile("data.txt");
        if(readFile){
            while(readFile >> id >> pro_price){
                if(pro_price == price){
                    cout << id << " " << pro_price << endl;
                }
            }
        }else{
            cout << "No such file " << endl;
        }
    }
};

int main(){
    clock_t start, end;
    start = clock();
    Product p(PRICE);
    end = clock();
    cout << "Time = " <<  double(end - start) / CLOCKS_PER_SEC << "s" << endl;
    system("pause");
    return 0;
}
