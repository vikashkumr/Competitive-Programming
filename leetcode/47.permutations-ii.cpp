/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>>res;

    void solve(vector<int> nums, int pos) {
        if(pos == nums.size()) {
            res.push_back(nums);
            return;
        }
        for(int i=pos;i<nums.size();i++) {
            if(nums[i]!=nums[pos]) {
                swap(nums[i], nums[pos]);
                solve(nums, i);
                swap(nums[i], nums[pos]);
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        solve(nums,0);
        return res;
    }
};
// @lc code=end

