/*
 * @lc app=leetcode id=1140 lang=cpp
 *
 * [1140] Stone Game II
 */

// @lc code=start
//variation of optimal game strategy

class Solution {
public:
    int dp[102][102][2];
    int solve(int m, int pos, int turn, vector<int> &piles) {
        //base case
        if(pos >= piles.size()) return 0;
        //recursive case
        int n = piles.size()-1;
        int &res = dp[m][pos][turn];
        if(res != -1) return res;
        if(turn) {
            int sum = 0;
            int ans = INT_MIN;
            for(int i=pos;i<pos+2*m;i++) {
                if(i<=n) {
                    sum+=piles[i];
                    ans = max(ans, sum + solve(max(m,i-pos+1), i+1, 0, piles)); 
                }
            }
            return res = ans;
        }
        else {
            int ans = INT_MAX;
            for(int i=pos;i<pos+2*m;i++) {
                if(i<=n)
                ans = min(ans, solve(max(m,i-pos+1), i+1, 1, piles));
            }
            return res = ans;
        }
    }
	
    int stoneGameII(vector<int>& piles) {
        piles.insert(piles.begin(), 1, 0);
        memset(dp, -1, sizeof dp);
        return solve(1, 1, 1, piles);
    }
};
// @lc code=end

