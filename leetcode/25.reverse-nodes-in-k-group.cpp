/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *node = head;
        int count = 0;

        //checking if less than k node is present
        while (count < k) { 
            if(node == NULL) return head;
            node = node->next;
            count++;
        }
        
        //reverse each k nodes
        ListNode *c = head, *p = NULL, *n = NULL;
        int cnt = 0;
        while(c!=NULL && cnt<k) {
            n = c->next;
            c->next = p;
            p = c;
            c = n;
            cnt++;
        }

        //fixing pointer
        if(n!=NULL) head->next = reverseKGroup(n, k);

        return p;
    }
};
// @lc code=end

