/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */

// @lc code=start
// for [1, 2, 3, 4]
//fi == first case [1,2,3],4 2nd case will be 1,[2,3,4]
class Solution {
public:

    int dp[50001];
    int solve(int pos,bool fi, vector<int>& v) {
        if(fi and pos>=v.size()-1) return 0;
        if(!fi and pos>=v.size()) return 0;
        int ans = 0;
        int &res = dp[pos];
        if(res != -1) return res;
        for(int i=pos+2;i<=v.size()+2;i++) {
            ans = max(ans, v[pos] + solve(i, fi, v));
        }
        return res = ans;
    }

    int rob(vector<int>& nums) {
        int ans = 0;
        if(nums.size()==1) return nums[0];
        if(nums.size()==0) return 0;
        memset(dp, -1, sizeof dp);
        ans = max(solve(0, 1, nums), solve(1, 1, nums));
        memset(dp, -1, sizeof dp);
        ans = max(solve(1, 0, nums), solve(2, 0, nums));
        return ans;
    }
};
// @lc code=end

