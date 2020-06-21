/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
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
    
    void reverseList(ListNode* &head) {
       ListNode *prev = NULL, *curr = head, *next = NULL;
        while(curr!=NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
    
    
    ListNode* rotateRight(ListNode* head, int k) {
      if(head==NULL or k==0) return head;
        ListNode *temp = head;
        
        int n = 0;
        while(temp!=NULL) {
            temp = temp->next;
            n++;
        }
        k = k%n;
        if(k==0) return head;
        
        
        reverseList(head);
        ListNode *l1 = head,*l2 = head;
        temp = head;

        k--;
        if(k<0) k = 0;
        while(k--) {
            l2 = l2->next;
        }
        temp = l2->next;
        reverseList(temp);
        l2->next = NULL;
        reverseList(l1);
        head = l1;
        while(head->next!=NULL) {
            head = head->next;
        }
        head->next = temp;
        return l1;
    }
};
// @lc code=end

