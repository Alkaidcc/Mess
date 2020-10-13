#include <iostream>
#include <fstream>
#include <ctime>
#include <map>
using namespace std;

class Product{
private:
    multimap<int,int> my_map;
public:
    Product(){
        int id,pro_price;
        ifstream readFile("./data.txt");
        if(readFile){
            while(readFile >> id >> pro_price){
                my_map.insert(make_pair(pro_price,id));
            }
        }else{
            cout << "No such file " << endl;
        }
    }
    void my_Sort();
};

void Product::my_Sort(){
    ofstream writeFile("./sortdata.txt");
    multimap<int,int>::iterator it;
    for(it = my_map.begin();it != my_map.end();it++){
        writeFile << it->second << " " << it->first << endl;
    }
}

int main(){
    clock_t start, end;
    Product p;
    start = clock();
    p.my_Sort();
    end = clock();
    cout << "Time = " <<  double(end - start) / CLOCKS_PER_SEC << "s" << endl;
    system("pause");
    return 0;
}
