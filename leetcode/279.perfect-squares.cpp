/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 
problem : break this line so that each part is perfect square 

|...................|..............|.........|.....

*/
// @lc code=start
class Solution {
public:
    int n;
    // int ans = INT_MAX;
    int dp[(int)1e6+1];
    int solve(int n) {
        if(n<=3) return n;
        int &res = dp[n];
        if(res!=-1) return res;
        int ans = INT_MAX-100;

        //breaking or jumping only to square i*i
        for(int i=1;i*i<=n;i++) {
            ans = min(ans, 1+solve(n-i*i));
        }
        return res = ans;
    }

    int numSquares(int n) {
       memset(dp, -1, sizeof dp);
       return solve(n); 
    }
};
// @lc code=end

