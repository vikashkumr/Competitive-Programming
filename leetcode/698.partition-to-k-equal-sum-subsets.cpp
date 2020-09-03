/*
 * @lc app=leetcode id=698 lang=cpp
 *
 * [698] Partition to K Equal Sum Subsets
 */

// @lc code=start
class Solution {
public:
    bool vis[16];
    int k;
    int some1;
    bool solve(int pos, vector<int> &nums, int times, int total) {
        if(times+1 == k) return true;
        if(total == some1) {
            return solve(0, nums, times+1, 0);
        }
        
        for(int i = pos; i<nums.size();i++) {
            if(!vis[i] and total + nums[i] <= some1) {
                vis[i] = 1;
                bool done = solve(i+1, nums, times, total + nums[i]);
                if(done) return true;
                vis[i] = 0;
            }
        }
        return false;
    }
    
    
    bool canPartitionKSubsets(vector<int>& nums, int K) {
        k = K;
        int sm=accumulate(nums.begin(),nums.end(),0);
        if(sm%k || k>nums.size())
        return false;
        some1 = sm/k;
        memset(vis, false, sizeof vis);
        return solve(0, nums, 0, 0);
    }
};
// @lc code=end

