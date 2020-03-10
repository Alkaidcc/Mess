#include <stdio.h>
#include <iostream>
using namespace std;

class node{//鍗曞悜涓嶅惊鐜摼琛�
    public:

    //鏁版嵁鎴愬憳
    int value;
    node* next=NULL;

    //鍑芥暟鎴愬憳,鍦∣OP涓篃鎴愭柟娉�

    node(int value=0){//鏋勯€犲嚱鏁�,鍦ㄤ娇鐢╪ew鎿嶄綔绗︽椂浼氳皟鐢�
        this->value=value;
    }

    void addNode(int value){//鍔犲埌鏁翠釜閾捐〃鐨勬渶鍚庨潰
        node* currentNode=this;//澹版槑鏌ユ壘鐢ㄧ殑鑺傜偣,鍒濆鍖栦负鑷繁
        while (currentNode->next!=NULL)//琛ㄧず鐜板湪涓嶆槸鏈€鍚庝竴涓妭鐐�
        {
            //濡傛灉涓嶆槸鏈€鍚庝竴涓妭鐐�,灏卞線鍚庣Щ鍔ㄤ竴浣�
            currentNode=currentNode->next;
        }
        //宸茬粡绉诲埌鏈€鍚庝竴涓簡
        currentNode->next=new node(value);
    }

    node* findNode(int value){//鏌ユ壘鎷ユ湁鎸囧畾鍊肩殑鑺傜偣,濡傛灉鎵句笉鍒�,灏辫繑鍥濶ULL
        node* currentNode=this;
        while(currentNode!=NULL&&currentNode->value!=value){//褰撳墠鑺傜偣鐨勫€间笉涓烘兂瑕佹煡鎵剧殑鍊兼椂,椤哄簭閬嶅巻
            currentNode=currentNode->next;
        }
        return currentNode;
    }

    void insertNode(int value){//鍔犲埌杩欎釜鑺傜偣鐨勫悗闈�(鎻掑叆)
        node* nextNode=this->next;//淇濆瓨浣忓悗涓€涓妭鐐�
        this->next=new node(value);
        this->next->next=nextNode;
    }

    void deleteNextNode(){//鍒犻櫎涓嬩竴涓妭鐐�
        node* nextNode=this->next->next;//淇濆瓨浣忓悗涓€涓妭鐐圭殑鍚庝竴涓妭鐐�
        delete this->next;
        this->next=nextNode;
    }
};

int main(){
    node head=node();
    for (int i = 1; i < 100; i*=2)//鏋勯€犻摼琛�
    {
        head.addNode(i);
    }
    node* finded_1=head.findNode(32);//鏌ユ壘鍊间负32鐨勮妭鐐�
    node* finded_2=head.findNode(33);//鏌ユ壘鍊间负33鐨勮妭鐐�

    finded_1->insertNode(50);
    finded_1->deleteNextNode();
    return 0;
}