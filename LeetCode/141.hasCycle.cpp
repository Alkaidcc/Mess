/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//用快慢指针判断是否为环形链表
bool hasCycle(struct ListNode *head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast != NULL) {
        if (fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        } else {
            return 0;
        }
        if (slow == fast) {
            return 1;
        }
    }
    return 0;
}


//最优解 本质还是快慢指针
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if (head == NULL)
        return 0;
 
    struct ListNode * pointL = head, * pointR = head->next;
    while (pointL != NULL && pointR != NULL) {
        if (pointR == pointL)
            return 1;
            
        pointL = pointL->next;
        // 因为存在中间节点的引用，所以必须对其进行判空操作，以避免出现空指针错误！！！
        if (pointR->next == NULL)
            return 0;
        pointR = pointR->next->next;
    }

    return 0;
}