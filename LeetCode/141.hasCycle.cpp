/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//�ÿ���ָ���ж��Ƿ�Ϊ��������
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


//���Ž� ���ʻ��ǿ���ָ��
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
        // ��Ϊ�����м�ڵ�����ã����Ա����������пղ������Ա�����ֿ�ָ����󣡣���
        if (pointR->next == NULL)
            return 0;
        pointR = pointR->next->next;
    }

    return 0;
}