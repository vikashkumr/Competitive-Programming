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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL){
    		return head;
    	}
        ListNode *oddh, *evenh, *c, *n;
        c = oddh = head;
        n = evenh  = head->next;
        int cnt = 0;
        while(n->next) {
            c->next = n->next;
            c = n;
            n = n->next;
            cnt++;
        }
        c->next = NULL;

        if(cnt&1) {
           n->next =evenh;
       } 
        else {
            c->next = evenh;
        }

        return head;

    }
};