/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */

// @lc code=start
//see carefully
class Solution {
private:
    vector<vector<int>> res;
    void solve(int pos, vector<int> &nums, vector<int> &ans) {
        res.push_back(ans);
        for(int i=pos;i<nums.size();i++) {
            if(i==pos || nums[i]!=nums[i-1]) {
                ans.push_back(nums[i]);
                solve(i+1, nums, ans);
                ans.pop_back();
            }
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> ans;
        solve(0, nums, ans);
        return res;
    }
};
// @lc code=end

