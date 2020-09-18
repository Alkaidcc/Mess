#include<iostream>
using namespace std;

typedef struct HTNode{
    int weight;     //权值
    int parent, lchild, rchild;     //双亲和左右孩子
}HTNode, *HuffmanTree;

//function prototype
void CreateHuffmanTree(HuffmanTree& HT, int n);
void Select(HuffmanTree& HT, int i, int& s1, int& s2);
void Print(HuffmanTree HT, int n);

int main() {
    HuffmanTree HT;
    int n;
    cin >> n;
    CreateHuffmanTree(HT,n);
    Print(HT,n);
    system("pause");
    return 0;
}
void CreateHuffmanTree(HuffmanTree& HT, int n) {
    int s1, s2;
    if(n <= 1) {
        return;
    }
    int m = 2 * n - 1;
    //HT共有2n-1个结点
    HT = new HTNode[m + 1];
    //HT初始化
    for(int i = 1;i <= m;i++) {
        HT[i].parent = HT[i].lchild = HT[i].rchild = 0;
    }
    for(int i = 1;i <= n;i++) {
        cin >> HT[i].weight;
    }

    for(int i = n + 1;i <= m;i++) {
        //查找权值最小的两个根结点，下标为s1，s2
        Select(HT, i-1, s1, s2);
        HT[s1].parent = i;
        HT[s2].parent = i;
        HT[i].lchild = s1;
        HT[i].rchild = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    }

}
//查找权值最小的两个根结点，下标为s1，s2
void Select(HuffmanTree& HT, int n, int& s1, int& s2) {
    bool flag = true;
    int i;
    for(i = 1;i <= n;i++) {
        if(flag) {
            if(HT[i].parent == 0) {
                s1 = i;
                flag =false;
            }
        }else {
            if(HT[i].parent == 0) {
                s2 = i;
                break;
            }
        }
    }
    for(i = 1;i <= n;i++) {
        if(s2 != i && HT[i].parent == 0 && HT[i].weight < HT[s1].weight) {
                s1 = i;
        }
    }
    for(i = 1;i <= n;i++) {
        if(s1 != i && HT[i].parent == 0 && HT[i].weight < HT[s2].weight) {
                s2 = i;
        }
    }
    if(HT[s1].weight > HT[s2].weight) {
        int temp;
        temp = s1;
        s1 = s2;
        s2 = temp;
    }
}

void Print(HuffmanTree HT, int n) {
    int m = 2 * n;
    cout << endl;
    cout << "Number" << "\t";
    cout << "Weight" << "\t";
    cout << "Parents" << "\t";
    cout << "LChild" << "\t";
    cout << "RChild" << endl;
    cout << "----------------------------------------" << endl;
    for(int i = 1; i < m;i++) {
        cout << i << "\t";
        cout << HT[i].weight << "\t";
        cout << HT[i].parent << "\t";
        cout << HT[i].lchild << "\t";
        cout << HT[i].rchild << endl;
    }
}