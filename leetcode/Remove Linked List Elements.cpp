class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL) return head;
        ListNode *p=NULL;
        while(head and head->val==val){
            p = head;
            head = head->next;
        }
        
        ListNode *curr = head;
        
        while(curr) {
            if(curr->val == val) {
                p->next = curr->next;
                curr= curr->next;
            } else {
                p = curr;
                curr= curr->next;   
            }    
        }
        return head;
    }
};