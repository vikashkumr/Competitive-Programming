
//add 1 to linked list

class Solution {
public:
    ListNode * reverseLL(ListNode *root) {
        ListNode *n = NULL, *p = NULL ,*c = root;
        while(c != NULL) {
            n = c->next;
            c->next = p;
            p = c;
            c = n;
        }
        return p;
    }
     
     
    ListNode * plusOne(ListNode * head) {
        // Write your code here
        head = reverseLL(head);
        ListNode *root = head;
        int carry = 1;
        while(root) {
            if(root->val + carry < 10) {
                root->val += 1;
                carry = 0;
                break;
            } else {
                carry = (root->val + 1)/10;
                root->val = (root->val + 1)%10;
            }
            root = root->next;
        }
        if(carry) {
            
            ListNode *t = new ListNode(carry);
            ListNode *temp = head;
            while(temp->next) {
                temp = temp->next;
            } 
            temp->next = t;
        }
        return reverseLL(head);
    }
};