#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef struct Cow{ //ţ
    int begin;      //��ʼʱ��
    int end;        //��ֹʱ��
    int no;         //ţ�ı��
    bool operator<(const Cow& c) const{
        if(c.end == end){
            return begin < c.begin;
        }else{
            return end < c.end;
        }
    }
}Cow;
Cow c[1000];
struct Fence{   //����
    int end;    //�����Ľ���ʱ��
    int no;     //�����ı��
    Fence(int e, int n):end(e),no(n){}
    bool operator<(const Fence& f) const{       //�������ȶ���ʱ������
        return end > f.end;
    }
    
};
int Position[1000]; //����i����ţȥ���������
int main(){
    int n,total = 0;
    cout << "������ţ�ĸ�����n���� ";
    cin >> n;
    cout << "������nͷţ����ʼʱ�����ֹʱ��: " << endl;
    for(int i = 0;i < n;i++){
        cin >> c[i].begin >> c[i].end;
        c[i].no = i;
    }
    sort(c, c + n); //����ţ����
    priority_queue<Fence> pr_q; //���ȶ��� ����ʱ��С����������ǰ��
    for(int i = 0;i < n;i++){
        if(pr_q.empty()){       //��ǰû������
            total++;            //����һ������
            pr_q.push(Fence(c[i].end,total)); 
            Position[c[i].no] = total;          //���ţ��������
        }else{
            Fence f = pr_q.top();
            if(f.end < c[i].begin){     //��ǰ��������
                pr_q.pop();             //����
                Position[c[i].no] = f.no;   //�ѿ��õ�������ű��
                pr_q.push(Fence(c[i].end, f.no));   
            }else{                      //��ǰ����������
                total++;                //����һ������
                pr_q.push(Fence(c[i].end, total));  
                Position[c[i].no] = total;
            }
        }
    }
    cout << "�������� " << total << " ������" << endl;
    for(int i = 0; i < n;i++){
        cout << "ţ���: " << c[i].no + 1 << "  �������: " << Position[c[i].no] << endl; 
    } 

    system("pause");
    return 0;
}
