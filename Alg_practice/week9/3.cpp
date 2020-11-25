#include <iostream>
#include <string.h>
#include <map>
#include <queue>
using namespace std;
const int MAX = 10001;
int Freq[128] = {0};
int n = 0;//27
struct HTreeNode //���������������
{
    char data;  //�ַ�
    int weight; //Ȩֵ
    int parent; //˫�׵�λ��
    int lchild; //���ӵ�λ��
    int rchild; //�Һ��ӵ�λ��
};
HTreeNode ht[MAX];        //��Ź�������
map<char, string> ht_code; //��Ź���������
map<string, char> reverse;
struct NodeType           //���ȶ��н������
{
    int no;     //��Ӧ��������ht�е�λ��
    char data;  //�ַ�
    int weight; //Ȩֵ
    bool operator<(const NodeType &s) const
    { //���ڴ���С����
        return weight > s.weight;
    }
};

void CreateHTree() //�����������
{
    NodeType e, e1, e2;
    priority_queue<NodeType> qu;
    for (int k = 0; k < 2 * n - 1; k++) //�������н���ָ����
        ht[k].lchild = ht[k].rchild = ht[k].parent = -1;
    for (int i = 0; i < n; i++) //��n��������qu
    {
        e.no = i;
        e.data = ht[i].data;
        e.weight = ht[i].weight;
        qu.push(e);
    }
    for (int j = n; j < 2 * n - 1; j++) //�������������n-1����Ҷ�ӽ��
    {
        e1 = qu.top();
        qu.pop(); //����Ȩֵ��С�Ľ��e1
        e2 = qu.top();
        qu.pop();                             //����Ȩֵ��С�Ľ��e2
        ht[j].weight = e1.weight + e2.weight; //������������ķ�Ҷ�ӽ��j
        ht[j].lchild = e2.no;
        ht[j].rchild = e1.no;
        ht[e1.no].parent = j; //�޸�e1.no��˫��Ϊ���j
        ht[e2.no].parent = j; //�޸�e2.no��˫��Ϊ���j
        e.no = j;             //������н��e
        e.weight = e1.weight + e2.weight;
        qu.push(e);
    }
}

void CreateHCode() //�������������
{
    string code;
    code.reserve(MAX);
    for (int i = 0; i < n; i++) //����Ҷ�ӽ��i�Ĺ���������
    {
        code = "";
        int cur_no = i;
        int f = ht[cur_no].parent;
        while (f != -1) //ѭ���������
        {
            if (ht[f].lchild == cur_no) //curnoΪ˫��f������
                code = '0' + code;
            else //curnoΪ˫��f���Һ���
                code = '1' + code;
            cur_no = f;
            f = ht[cur_no].parent;
        }
        ht_code[ht[i].data] = code; //�õ�ht[i].data�ַ��Ĺ���������
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
    cout << "Huffman����: " << endl;
    //Encode
    for(int i = 0;i < str.size();i++){
        cout << ht_code[str[i]];
        reverse.insert(pair<string,char>(ht_code[str[i]], str[i]));
    }
    cout << endl;
    //Decode
    cout << "����: " << endl;
    for(int i = 0;i < str.size();i++){
        cout << reverse[ht_code[str[i]]];
    }
    cout << endl;
    system("pause");
    return 0;
}