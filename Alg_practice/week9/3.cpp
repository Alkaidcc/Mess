#include <iostream>
#include <string.h>
#include <map>
#include <queue>
using namespace std;
const int MAX = 10001;
int Freq[128] = {0};
int n = 0;//27
struct HTreeNode //哈夫曼树结点类型
{
    char data;  //字符
    int weight; //权值
    int parent; //双亲的位置
    int lchild; //左孩子的位置
    int rchild; //右孩子的位置
};
HTreeNode ht[MAX];        //存放哈夫曼树
map<char, string> ht_code; //存放哈夫曼编码
map<string, char> reverse;
struct NodeType           //优先队列结点类型
{
    int no;     //对应哈夫曼树ht中的位置
    char data;  //字符
    int weight; //权值
    bool operator<(const NodeType &s) const
    { //用于创建小根堆
        return weight > s.weight;
    }
};

void CreateHTree() //构造哈夫曼树
{
    NodeType e, e1, e2;
    priority_queue<NodeType> qu;
    for (int k = 0; k < 2 * n - 1; k++) //设置所有结点的指针域
        ht[k].lchild = ht[k].rchild = ht[k].parent = -1;
    for (int i = 0; i < n; i++) //将n个结点进队qu
    {
        e.no = i;
        e.data = ht[i].data;
        e.weight = ht[i].weight;
        qu.push(e);
    }
    for (int j = n; j < 2 * n - 1; j++) //构造哈夫曼树的n-1个非叶子结点
    {
        e1 = qu.top();
        qu.pop(); //出队权值最小的结点e1
        e2 = qu.top();
        qu.pop();                             //出队权值次小的结点e2
        ht[j].weight = e1.weight + e2.weight; //构造哈夫曼树的非叶子结点j
        ht[j].lchild = e2.no;
        ht[j].rchild = e1.no;
        ht[e1.no].parent = j; //修改e1.no的双亲为结点j
        ht[e2.no].parent = j; //修改e2.no的双亲为结点j
        e.no = j;             //构造队列结点e
        e.weight = e1.weight + e2.weight;
        qu.push(e);
    }
}

void CreateHCode() //构造哈夫曼编码
{
    string code;
    code.reserve(MAX);
    for (int i = 0; i < n; i++) //构造叶子结点i的哈夫曼编码
    {
        code = "";
        int cur_no = i;
        int f = ht[cur_no].parent;
        while (f != -1) //循环到根结点
        {
            if (ht[f].lchild == cur_no) //curno为双亲f的左孩子
                code = '0' + code;
            else //curno为双亲f的右孩子
                code = '1' + code;
            cur_no = f;
            f = ht[cur_no].parent;
        }
        ht_code[ht[i].data] = code; //得到ht[i].data字符的哈夫曼编码
    }
}

void CreateHT(){
    int j = 0;
    for(int i = 0;i < 128;i++){
        if(Freq[i]){
            ht[j].data = char(i);
            ht[j].lchild = ht[j].rchild = ht[j].parent = -1;
            ht[j].weight = Freq[i];
            n++;
            j++;
        }
    }
}

int main()
{
    string str = "It was the best of times,\nit was the worst of times,\nit was the age of wisdom,\nit was the age of foolishness,\nit was the epoch of belief,\nit was the epoch of incredulity,\nit was the season of Light,\nit was the season of Darkness,\nit was the spring of hope,\nit was the winter of despair";
    for (int i = 0; i < str.size(); i++){
        Freq[str[i]]++;
    }
    CreateHT();
    CreateHTree();
    CreateHCode();
    cout << "Huffman编码: " << endl;
    //Encode
    for(int i = 0;i < str.size();i++){
        cout << ht_code[str[i]];
        reverse.insert(pair<string,char>(ht_code[str[i]], str[i]));
    }
    cout << endl;
    //Decode
    cout << "解码: " << endl;
    for(int i = 0;i < str.size();i++){
        cout << reverse[ht_code[str[i]]];
    }
    cout << endl;
    system("pause");
    return 0;
}