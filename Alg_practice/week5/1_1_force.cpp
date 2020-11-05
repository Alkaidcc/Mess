#include <iostream>
using namespace std;

int main(){
    string target;
    string pattern;
    cout << "请输入两个字符串: " << endl;
    while(cin >> target && cin >> pattern){
        int i = 0, j = 0,ans = -1;
        while(i < target.size() && j < pattern.size()){
            if(target[i] == pattern[j]){
                i++;
                j++;
            }else{
                i = i - j + 1;
                j = 0;
            }
        }
        if(j == pattern.size()){
            ans = i - j;
        }
        cout << "pattern在target中的位置是：" << ans << endl;
        cout << "请输入两个字符串: " << endl;
    }
    system("pause");
    return 0;
}
