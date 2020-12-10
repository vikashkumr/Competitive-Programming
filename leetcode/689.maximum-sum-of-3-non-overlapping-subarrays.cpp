/*
 * @lc app=leetcode id=689 lang=cpp
 *
 * [689] Maximum Sum of 3 Non-Overlapping Subarrays
 */

// @lc code=start
// https://www.youtube.com/watch?v=wN1nPANp3hk&ab_channel=happygirlzt (refer for more clarity)

class Solution {
public:

    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int len = nums.size();
        //no of subarray of size k
        int n = len-k+1;
        int dp[n];
        int sum = 0;
        for(int i=0;i<len;i++) {
            sum+=nums[i];
            //excluding element bcz size become greater than k outside of box
            if(i>=k) sum-=nums[i-k];
            if(i>=k-1) dp[i-k+1] = sum;
        }
        // these arr keep index of max sum till i from left and right respectively
        int left[n], right[n];
        int idx = 0;
        for(int i=0;i<n;i++) {
            // should not be >= because we have to return lexicographically
            if(dp[i] > dp[idx]) {
                idx = i;
            }       
            left[i] = idx;
        }
        idx = n-1;
        for(int i=n-1;i>=0;i--) {
            if(dp[i]>=dp[idx]) {
                idx = i;
            }
            right[i] = idx;
        }
        vector<int> res(3,-1);
        for(int i=k;i<n-k;i++) {
            if(res[0] == -1 || dp[res[0]]+ dp[res[1]] + dp[res[2]] < dp[left[i-k]] + dp[i] + dp[right[i+k]]) {
                res[0] = left[i-k];
                res[1] = i;
                res[2] = right[i+k];
            }
        }
        return res;
    }
};
// @lc code=end

