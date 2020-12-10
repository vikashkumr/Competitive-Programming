/*
 * @lc app=leetcode id=445 lang=cpp
 *
 * [445] Add Two Numbers II
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1,s2;
        while(l1!=NULL) s1.push(l1->val), l1 = l1->next;
        while(l2!=NULL) s2.push(l2->val), l2 = l2->next;
        ListNode *head = NULL;
        int carry = 0;
        while(s1.size() > 0 and s2.size() > 0) {
            int add = s1.top() + s2.top() + carry;
            if(add < 10) {
                ListNode *n = new ListNode(add);
                ListNode *temp = head;
                head = n;
                n->next = temp;
                carry = 0;
            } else {
                ListNode *n = new ListNode(add%10);
                ListNode *temp = head;
                head = n;
                n->next = temp;
                carry = 1;
            }
            s1.pop(); s2.pop();
        }
        while(s1.size() > 0) {
            int add = s1.top() + carry;
            if(add < 10) {
                ListNode *n = new ListNode(add);
                ListNode *temp = head;
                head = n;
                n->next = temp;
                carry = 0;
            } else {
                ListNode *n = new ListNode(add%10);
                ListNode *temp = head;
                head = n;
                n->next = temp;
                carry = 1;
            }
            s1.pop();
        } 
        while(s2.size() > 0) {
            int add = s2.top() + carry;
            if(add < 10) {
                ListNode *n = new ListNode(add);
                ListNode *temp = head;
                head = n;
                n->next = temp;
                carry = 0;
            } else {
                ListNode *n = new ListNode(add%10);
                ListNode *temp = head;
                head = n;
                n->next = temp;
                carry = 1;
            }
            s2.pop();
        }
        if(carry) {
            ListNode *n = new ListNode(1);
            ListNode *temp = head;
            head = n;
            n->next = temp;
        }
        return head;
    }
};
// @lc code=end

