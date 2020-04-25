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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head==NULL or head->next==NULL) return head;
        

        ListNode *p=NULL, *nt = NULL;
        ListNode *curr = head;

        //take p pointer just before of mth element
        for(int i=0;i<m-1;i++) {
            p = curr;
            curr = curr->next;
        }
       

        ListNode *con = p;

        //simple reverse code
        for(int i=m;i<=n;i++) {
            nt = curr->next;
            curr->next = p;
            p = curr;
            curr = nt;
        }

        //check case for m == 1
        if(m==1) {
            head->next = curr;
            head=p;
        } else {
           con->next->next = curr;
            con->next = p; 
        }
        
        return head;
    }
};