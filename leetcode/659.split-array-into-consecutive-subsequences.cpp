/*
 * @lc app=leetcode id=659 lang=cpp
 *
 * [659] Split Array into Consecutive Subsequences
 */

// @lc code=start
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        priorirty_queue<int, vector<int>, greater<int>>pq1,pq2;
        for(auto num: nums) pq1.push(num);

        while(!pq1.empty()) {
            int t = 2;
            int last = pq1.top();pq1.pop();
            while(t--) {
                if(pq1.empty() or pq1.top()-last>1) return false;
                if(pq1.top()==last) {
                    pq2.push(pq1.top());
                    pq1.pop();  
                    t++;
                } 
            }
            while(!pq2.empty()) {
                pq1.push(pq2.top());
                pq2.pop();
            }
        }

        return true;
    }
};
// @lc code=end

