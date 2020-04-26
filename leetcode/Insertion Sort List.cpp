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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *curr = head;
        while(curr) {
            //if current element is less than next element simply continue to next element
            if(curr->next and curr->val <= curr->next->val){
                curr = curr->next;
            }
            //check from head element
            else if(curr->next and curr->val > curr->next->val){
                ListNode *temp = curr->next;
                curr->next = curr->next->next;
                ListNode *trav = head;
                while(trav->val < temp->val) {
                    trav = trav->next;
                }
                temp->next = trav->next;
                trav->next = temp;
                swap(trav->val,temp->val);
                // curr = curr->next;
            } else {

                //reached to last node find it's correct posiyion and place
                int x = curr->val;
                ListNode *trav = head;
                while(trav->val < x) {
                    trav = trav->next;
                }
                int value ;
                while(trav!=NULL) {
                    value = trav->val;
                    trav->val = x;
                    x = value;
                    trav = trav->next;
                }
                curr = curr->next;
            }
        }
        return head;
    }
};