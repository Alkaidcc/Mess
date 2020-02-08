/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode* a=headA;
    struct ListNode* b=headB;
    if(a==NULL||b==NULL)
        return 0;
    while(a!=b){
        a=a==NULL?headB:a->next;
        b=b==NULL?headA:b->next;
    }
    return a;
}