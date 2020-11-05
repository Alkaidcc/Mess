#include <iostream>
using namespace std;

void getNext(string p, int next[]){
    next[0] = -1;
    int j = 0;
    int k = -1;
    while(j < p.size()){
        if(k == -1 || p[j] == p[k]){
            j++;
            k++;
            next[j] = k;
        }else{
            k = next[k];
        }
    }
}
int KMP(string target, string pattern){
    int i = 0, j = 0;
    int next[pattern.size()];
    getNext(pattern,next);
    while(1){
        if(j == -1 || target[i] == pattern[j]){
            i++;
            j++;
        }else{
            j = next[j];
        }
        if(i == target.size() || j == pattern.size()){
            break;
        }
    }
    if(j == pattern.size()){
        return i - j;
    }else{
        return -1;
    }
}


int main(){
    string target = "aababcde";
    string pattern = "bcd";
    int ans = KMP(target, pattern);
    cout << "position: " << ans << endl;
    system("pause");
    return 0;
}
