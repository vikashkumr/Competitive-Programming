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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        //to check whether a complete list have 0 element
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        ListNode *head = NULL, *curr=NULL;

        //head will point to the list-node having less value intially
        if(l1->val <= l2->val) {
            head = l1;
           curr = l1;
            l1 = l1->next;
        } else {
            head = l2;
            curr = l2;
            l2 = l2->next;
        }

        
        while(l1 and l2) {
            if(l1->val <= l2->val ) {
                curr->next = l1;
                l1 = l1->next;
                curr = curr->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
                curr = curr->next;
            }
        }

        //to check if any list is having some element
        if(l1) curr->next = l1;
        if(l2) curr->next = l2;
        
        return head;
        
    }
};