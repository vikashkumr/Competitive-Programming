/*
 * @lc app=leetcode id=817 lang=cpp
 *
 * [817] Linked List Components
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
//think for when we can break the component 
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        int freq[10000] = {0};
        for(int x: G) freq[x]++;
        
        int components = 0;
        while(head) {
            if(freq[head->val] && (head->next==NULL || !freq[head->next->val])) {
                components++; 
            }
            head = head->next;
        }
        return components;
    }
};
// @lc code=end

