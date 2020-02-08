/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//�Լ�д��
struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode* memory=head;
    while(head!=NULL){
        while(head->next!=NULL&&head->val==head->next->val){
            struct ListNode* tmp=head->next->next;
            free(head->next);
            head->next=tmp;
        }
        head=head->next;
    }
    return memory;
}

//�ݹ�

struct ListNode* deleteDuplicates(struct ListNode* head){
    if(head==NULL||head->next==NULL)
        return head;
    head->next=deleteDuplicates(head->next);
    if(head->val==head->next->val)
        head=head->next;
    return head;
}