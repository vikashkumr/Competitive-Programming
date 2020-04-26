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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        ListNode *curr = head;
        ListNode *prev = dummy;
        dummy->next = head;
        while(curr != NULL) {
           if(curr->next!=NULL && curr->val == curr->next->val) curr = curr->next;
           if(prev->next == curr) prev = prev->next; //No duplicates
           else prev->next = curr->next; // duplicates
           curr = curr->next;
        }
        return dummy->next;
    }
};