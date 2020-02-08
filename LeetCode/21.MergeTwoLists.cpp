/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//�õݹ�ʵ�� �鲢���򣡣�������������
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if(l1==NULL)
        return l2;
    if(l2==NULL)
        return l1;
    if(l1->val <= l2->val){
        l1->next = mergeTwoLists(l1->next,l2);
        return l1;
    }else{
        l2->next = mergeTwoLists(l1,l2->next);
        return l2;
    }
}

//ͨ�⣨�ǵݹ飩
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    ListNode* head=(ListNode*)malloc(sizeof(struct ListNode));
    head->val=0;
    head->next=NULL;
    ListNode* memory=head;  //��סͷ��� ���Ҫ����
    while(l1!=NULL&&l2!=NULL)
        if(l1->val<=l2->val){
            head->next=l1;
            l1=l1->next;
            head=head->next;
        }
        else{
            head->next=l2;
            l2=l2->next;
            head=head->next;
        }
    while(l1!=NULL){
        head->next=l1;
        l1=l1->next;
        head=head->next;
    }
    while(l2!=NULL){
        head->next=l2;
        l2=l2->next;
        head=head->next;
    }
    return memory->next;
}