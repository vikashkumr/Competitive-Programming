//https://leetcode.com/problems/merge-k-sorted-lists/

//space => O(k) for heap
//Time => O(k + nlog(k))

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>, greater<pair<int,ListNode*>> >pq;
        ListNode *dummy = new ListNode(0);
        ListNode *head = dummy;
        for(int i=0;i<lists.size();i++) {
            if(lists[i]!=NULL) {
                pq.push({lists[i]->val,lists[i]});
            }
        }
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            ListNode *t = new ListNode(it.first);
            head->next = t;
            head = head->next;
            it.second = it.second->next;
            if(it.second!=NULL) {
                pq.push({it.second->val,it.second});
            }
        }
        return dummy->next;
    }
};