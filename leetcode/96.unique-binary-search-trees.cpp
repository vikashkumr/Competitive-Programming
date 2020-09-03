/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 */

// @lc code=start
//2nCn / (n+1)


class Solution {
public:
    long long dp[40][20];
    long long C(long long n, long long r) {
        if(n==r or r==0) return 1;

        if(dp[n][r] != -1) return dp[n][r];
        return dp[n][r] = C(n-1,r) + C(n-1,r-1);
    }

    int numTrees(int n) {
        memset(dp, -1, sizeof dp);
        return C(2*n,n)/(n+1);
    }
};
// @lc code=end

