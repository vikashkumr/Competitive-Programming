/*
 * @lc app=leetcode id=1695 lang=cpp
 *
 * [1695] Maximum Erasure Value
 */

// @lc code=start
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        unordered_map<int,int> hmp;
        int ans = 0, sum = 0;
        while(l<=r && r<n) {
            hmp[nums[r]]++;
            while(hmp[nums[r]] > 1) {
                hmp[nums[l]]--;
                sum-=nums[l];
                l++;
            }
            sum += nums[r];
            ans = max(ans, sum);
            r++;
        }
        return ans;
    }
};
// @lc code=end

