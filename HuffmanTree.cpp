#include<iostream>
#include<stack>
#include<string>
#include<fstream>
using namespace std;
const int MAXSIZE = 56;
typedef char ElemType;
struct Node {
    ElemType data;      //保存的符号
    int weight;         //权值
    int lchild, rchild, parent; //左孩子，右孩子，跟节点
};

class HuffmanTree {
    private:
        //从文本中统计出来的出现的字符的数量
        int num;
        //保存各个叶子的权值
        int W[MAXSIZE];

        Node HuffTree[2 * MAXSIZE - 1];
        //判断位置
        int indexOf(char ch) {  //ch是想要查找的位置
            for(int i = 0;i < num;i++) {
                if(HuffTree[i].data == ch) {
                    return i;
                }
            }
            return -1;
        }

        void Select(int& i1, int& i2) {
            int i;
            bool button = true;
            for(i = 0;i < 2 * num - 1;i++) {
                if(button) {
                    if(HuffTree[i].parent == -1) {
                        i1 = i;
                        button = false;
                    }
                }else {
                    if(HuffTree[i].parent == -1) {
                        i2 = i;
                        break;
                    }
                }
            }
            for(i = 0;i < 2 * num - 1; i++) {
                if(i2 != i && HuffTree[i].parent == -1 && HuffTree[i].weight > 0) {
                    if(HuffTree[i1].weight > HuffTree[i].weight) {
                        i1 = i;
                    }
                }
            }
            for(i = 0;i < 2 * num - 1; i++) {
                if(i1 != i && HuffTree[i].parent == -1 && HuffTree[i].weight > 0) {
                    if(HuffTree[i2].weight > HuffTree[i].weight) {
                        i2 = i;
                    }
                }
            }
        }
        //读取文件
        string read_file() {
            string str;
            ifstream in("input.txt", ios::in);
            in >> str;
            in.close();
            return str;

        }
        //保存压缩文件
        void save_code(int code_cache[], int code_cache_size) {
            ofstream out("output.txt", ios::out);
            for(int i = 0;i < code_cache_size; i++) {
                out << code_cache[i];
            }
            out.close();
        }
        //统计出现字母的频率
        void CountLetter(string& str) {
            int size = 52;
            char ch[size];
            int weight[size];
            num = 0;
            ch[0] = 'A';
            ch[26] = 'a';
            for(int i = 1;i < size / 2;i++) {
                ch[i] = ch[i - 1] + 1;
                ch[i + 26] = ch[i + 26 - 1] + 1;
            }
            for(int i = 0;i < size;i++) {
                weight[i] = 0;
            }
            int h = str.size();
            for(int i = 0;i < h;i++) {
                if(str.at(i) >64 && str.at(i) < 91) {
                    weight[str.at(i) - 'A']++;
                }
                if(str.at(i) >96 && str.at(i) < 123) {
                    weight[26 + str.at(i) - 'a']++;
                }
            }
            for(int i = 0;i < size;i++) {
                if(weight[i] != 0) {
                    HuffTree[num].data = ch[i];
                    HuffTree[num].weight = weight[i];
                    W[num] = weight[i];
                    num++;
                }
            }
        }

    public:
        //构造函数
        HuffmanTree() {
            string str = read_file();
            CountLetter(str);
            for(int i = 0;i < 2 * num - 1;i++) {
                HuffTree[i].parent = -1;
                HuffTree[i].lchild = -1;
                HuffTree[i].rchild = -1;
            }
            for(int i = 0; i < 2 * num - 1;i++) {
                if(i < num) {
                    HuffTree[i].weight = W[i];  //构造2*n-1棵只含有根结点的二叉树
                }else {
                    HuffTree[i].weight = 0;
                }
            }
            for(int k = num;k < 2 * num - 1;k++) {
                int i1, i2;
                //查找权值最小的两个根结点，下标为i1，i2
                Select(i1, i2);
                //将i1.i2合并，i1，i2的双亲都是K
                HuffTree[i1].parent = k;
                HuffTree[i2].parent = k;
                HuffTree[k].weight = HuffTree[i1].weight + HuffTree[i2].weight;
                HuffTree[k].lchild = i1;
                HuffTree[k].rchild = i2;
            }
            cout << "-----------------------------" << endl;
            print();
            cout << "-----------------------------" << endl;
            condense(str);
            decoding();
        }
        
        void print() {
                cout << "Weight" << "\t";
                cout << "Parents" << "\t";
                cout << "LChild" << "\t";
                cout << "RChild" << endl;
            for(int i = 0;i < 2 * num - 1;i++) {
                cout << HuffTree[i].weight << "\t";
                cout << HuffTree[i].parent << "\t";
                cout << HuffTree[i].lchild << "\t";
                cout << HuffTree[i].rchild << endl;
            }
        }
/*  
    **huffman编码压缩
 */
        void condense(string str) {
            int code_cache_maxsize = 256;

            stack<int> s;
            //缓存转码数据数组
            int code_cache[code_cache_maxsize];
            //缓存游标
            int code_cache_index = 0;
            //判断是左子树还是右子树
            int JudgeDirection;
            //是否上溢
            bool IsOverflow = false;
            int n = str.size();
            for(int i = 0;i < n;i++) {
                int index = indexOf(str.at(i));
                JudgeDirection = HuffTree[index].parent;
                while(JudgeDirection != -1) {
                    if(index == HuffTree[JudgeDirection].lchild) {
                        s.push(0);
                    }else {
                        s.push(1);
                    }
                    index = JudgeDirection;
                    JudgeDirection = HuffTree[JudgeDirection].parent;
                }
                while(!s.empty()) {
                    code_cache[code_cache_index++] = s.top();
                    s.pop();
                }
                if(code_cache_index % code_cache_maxsize == code_cache_maxsize - 1) {
                    save_code(code_cache, code_cache_maxsize);
                    code_cache_index = 0;
                    IsOverflow = true;
                }
            }
            if(!IsOverflow) {
                save_code(code_cache,code_cache_index);
            }
        }

/** 
  *huffman算法 -解码
 */
        void decoding() {
            string str;
            ifstream in("output.txt",ios::in);
            in >> str;
            in.close();
            ofstream out("output.txt",ios::out);
            int root = 2 * num - 2;
            int temp = root;
            int h = str.size();
            for(int i = 0;i < h;i++) {
                if(str.at(i) == '0') {
                    if(HuffTree[temp].lchild != -1) {
                        temp = HuffTree[temp].lchild;
                        if(HuffTree[temp].lchild == -1) {
                            out << HuffTree[temp].data;
                            temp = root;
                        }
                    }
                }else {
                    if(HuffTree[temp].rchild != -1) {
                        temp = HuffTree[temp].rchild;
                        if(HuffTree[temp].rchild == -1) {
                            out << HuffTree[temp].data;
                            temp = root;
                        }
                    }
                }
            }
            out.close();
        }
};

int main() {
    new HuffmanTree();
    system("pause");
    return 0;
}