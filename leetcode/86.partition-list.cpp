/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL or head->next==NULL) return head;

        //handling length having 2
        if(head->next->next == NULL) {
            if(head->val < x or head->next->val >= x) return head;
            else {
                swap(head->val,head->next->val);
                return head;
            }  

        }
        ListNode *temp1 = NULL, *temp2 = NULL, *root1 = NULL, *root2 = NULL;
        
        //setting first element
        if(head->val < x) temp1 = head, root1 = head;
        else temp2 = head, root2 = head;
        
        head = head->next;
        while(head != NULL) {
            if(head->val < x) {
                
                if(temp1==NULL) {
                    temp1 = head;
                    root1 = head;
                }
                else {
                    temp1->next = head;
                    temp1 = temp1->next;
                }   
                
            } else {
                if(temp2==NULL) {
                    temp2 = head;
                    root2 = head;
                }
                else {
                    temp2->next = head;
                    temp2 = temp2->next;
                }
            }
            head = head->next;
        }

        //corner case when 1 of the pointer remain empty
        if(root1==NULL or root2==NULL) return (root1==NULL) ? root2 : root1;

        //joining two list
        temp2->next = NULL;
        temp1->next = root2;
        return root1;
    }
};
// @lc code=end

