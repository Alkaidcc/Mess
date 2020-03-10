#include<iostream>
using namespace std;

typedef struct ListNode{
    int val;
    struct ListNode* next;
}ListNode;

//声明
ListNode* mergeTwoLists(ListNode* l1,ListNode* l2);
ListNode* Creat();
void Print(ListNode* currentnode);

ListNode* Creat(){
    int data;
    ListNode* head = new ListNode;
    head->next = NULL;
    head->val = 0;
    ListNode* ptr = head;
    
    while (cin >> data && data >0)
    {
        ListNode* temp = new ListNode;
        temp->val = data;
        temp->next = NULL;
        ptr->next = temp;
        ptr = ptr->next;
    }
    return head;
    
}

void Print(ListNode* currentnode){
    if(currentnode==NULL){
        cout << "NULL";
        return;
    }
    else{
        while(currentnode){
            if(currentnode->next)
                cout << currentnode->val << " ";
            else
                cout << currentnode->val << endl;
            currentnode = currentnode->next;
        }
    
    }
    
}


ListNode* mergeTwoLists(ListNode* l1,ListNode* l2){
    ListNode* head= new ListNode;
    head->val=0;
    head->next=NULL;
    ListNode* memory=head;  //记住头结点 最后要返回

    while(l1!=NULL&&l2!=NULL){	//判空
        if(l1->val==l2->val){
            head->next=l1;
            l1=l1->next;
            l2=l2->next;
            head=head->next;
        }
        else if(l1->val<l2->val){
            l1=l1->next;
        }
        else
            l2=l2->next;
    }

    return memory->next;
}

int main(){
    ListNode* S1;
    ListNode* S2;
    ListNode* S3;
    S1=Creat();
    S2=Creat();
    S3=mergeTwoLists(S1->next,S2->next);//因为S1,S2有头结点
    Print(S3);
    return 0;

}
