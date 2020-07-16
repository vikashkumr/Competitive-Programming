/*
 * @lc app=leetcode id=398 lang=cpp
 *
 * [398] Random Pick Index
 */

// @lc code=start
class Solution {
public:
    int n;
    vector<int> v, curr;
    Solution(vector<int>& nums) {
        
        int n = nums.size();
        v = nums;
    }
    
    int pick(int target) {
       for(int i=0;i<v.size();i++) {
           if(v[i] == target) {
               curr.push_back(i);
           }
       }
        return curr[rand()%curr.size()];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
// @lc code=end

