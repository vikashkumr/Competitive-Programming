/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start
class Solution {
public:
    long long max(long a, long b) {
        return (a>b)?a:b;
    }
    int maxProduct(vector<int>& nums) {
        long long n = nums.size();
        long long curr_mx = 1;
        long long pre[n], suff[n];
        for(long long i=0;i<n;i++) {
            curr_mx *=nums[i];
            pre[i] = max(nums[i], curr_mx);
            if(curr_mx==0) curr_mx = 1;
        }
        curr_mx = 1;
        for(long long i=n-1;i>=0;i--) {
            curr_mx *=nums[i];
            suff[i] = max(nums[i], curr_mx);
            if(curr_mx==0) curr_mx = 1;
        }
        long long ans = *max_element(nums.begin(),nums.end());
        for(long long i=0;i<n-1;i++) {
            ans = max(ans, max(pre[i]*suff[i+1],max(pre[i],suff[i+1])));
        }
        
        return max(ans,pre[n-1]);
    }
};
// @lc code=end

