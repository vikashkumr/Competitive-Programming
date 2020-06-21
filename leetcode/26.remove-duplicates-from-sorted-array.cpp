/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        int left = 0;
        for(int i=1;i<nums.size();i++) {
            if(nums[left] != nums[i]) {
                nums[++left] = nums[i];
            }
        }
        return left+1;
    }
};
// @lc code=end

