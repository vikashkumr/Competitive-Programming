/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//Easy just keep two pointer for even and odd and transfer it accoedingly 


class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL) return head;
        //keep address of even start node
        ListNode *head2 = head->next;
        
        //root1 for odd and root2 for even LL
        ListNode *root1 = head, *root2 = head->next;
        while(root1->next and root2->next) {
            root2 = root1->next;
            root1->next = root1->next->next;
            root2->next = root2->next->next;
            root1 = root1->next;
            root2 = root2->next;
        }

        //attached even LL to odd LL
        root1->next = head2;
        
        return head;
    }
};