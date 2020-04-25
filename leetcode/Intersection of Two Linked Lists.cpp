class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1 = 0,l2 = 0;
        ListNode* la = headA;
        ListNode* lb = headB;
        while(la) {
            l1++;
            la= la->next;
        }   
        while(lb) {
            l2++;
            lb= lb->next;
        }   
        while(l1>l2) {
            headA = headA->next;
            l1--;
        }
        while(l2>l1) {
            headB = headB->next;
            l2--;
        }

        while(headA) {
            if(headA==headB) {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }

        return NULL;
    }
};