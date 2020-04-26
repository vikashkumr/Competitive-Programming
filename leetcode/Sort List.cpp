/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* findMid(ListNode* head) {
        if(head == NULL || head->next==NULL)
            return head->next;

        ListNode *slow = head;
        ListNode *fast = head->next;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *t= slow->next;
        slow->next = NULL;
        return t;
    }

    ListNode* merge(ListNode *l1, ListNode *l2) {
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        if(l1->val < l2->val) {
            l1->next = merge(l1->next, l2);
            return l1;
        } else {
            l2->next = merge(l2->next, l1);
            return l2;
        }
    }


    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next==NULL)
            return head;
        ListNode *mid = findMid(head);
        ListNode *left = sortList(head);
        ListNode *right = sortList(mid);
        return merge(left,right);

    }
};