#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int character[130] = {0};


void find_unique(){
    for(int i = 48;i < 123;i++){
        if(character[i] >= 2){
            cout << (char)i;
        }
    }
    cout << endl;
}

int main(){
    char a[100];
    char b[100];
    cout << "ÇëÊäÈëÁ½¸ö×Ö·û´®: " << endl;
    cin >> a;
    cin >> b;
    int len_a = strlen(a);
    int len_b = strlen(b);
    for(int i = 0;i < len_a;i++){
        character[int(a[i])]++;
    }
    for(int i = 0;i < len_b;i++){
        character[(int)b[i]]++;
    }
    find_unique();
    system("pause");
    return 0;
}
