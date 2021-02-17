/*
 * @lc app=leetcode id=1248 lang=cpp
 *
 * [1248] Count Number of Nice Subarrays
 */

// @lc code=start
class Solution {
public:
    
    int upto(vector<int>& nums, int k) {
        int l = 0, r = 0, cnt = 0, kCnt = 0;
        while(l <= r && r<nums.size()) {
            if(nums[r]&1) kCnt++;
            while(kCnt > k) {
                if(nums[l]&1) kCnt--;
                l++;
            }
            if(kCnt <= k) cnt+=r-l+1;
            r++;
        }
        return cnt;
    }
    
    int numberOfSubarrays(vector<int>& nums, int k) {
        return upto(nums,k) - upto(nums,k-1);
    }
};
// @lc code=end

