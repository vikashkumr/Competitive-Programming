class Solution {
public:
    ListNode* findMid(ListNode *head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode *slow = head;
        ListNode *fast = head->next;
        while(fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    void reverseLL(ListNode* &ptr) {
        ListNode *curr = ptr, *prev = NULL, *next=NULL;
        while(curr!=NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        ptr = prev;
    }
    
    
    bool isPalindrome(ListNode* head) {
        if(head==NULL) return true;
        
        //find mid and reverse from there
        ListNode *mid = findMid(head);
        mid = mid->next;
        reverseLL(mid);
        
        ListNode* curr = mid, *left = head;
        while(mid!=NULL) {
            if(head->val == mid->val) {
                mid = mid->next;
                head = head->next;
            } else {
                return false;
            }
        }
        return true;
    }
};