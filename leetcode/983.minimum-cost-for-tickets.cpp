/*
 * @lc app=leetcode id=983 lang=cpp
 *
 * [983] Minimum Cost For Tickets
 */

// @lc code=start
/*
 * @lc app=leetcode id=983 lang=cpp
 *
 * [983] Minimum Cost For Tickets
 */

// @lc code=start
class Solution {
public:
    int vis[400] = {0};
    int mx;
    int dp[400];
    int solve(int pos, vector<int>& costs) {
        if(pos>mx) return 0;
    
        int &res = dp[pos];
        if(res != -1) return res;

        //recursive case
        int ans = INT_MAX;
        for(int i=0;i<3;i++) {
            if(vis[pos]) {
                int nxt_day = 30;
                if(i==0) nxt_day = 1;
                else if(i==1) nxt_day = 7;
                ans = min(ans, costs[i] + solve(pos+nxt_day, costs));
            }
        }
        if(!vis[pos]) ans = min(ans, solve(pos+1, costs));
        return res = ans;
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        mx = *max_element(days.begin(), days.end());
        memset(dp, -1, sizeof dp);
        for(int x : days) vis[x] = 1;
        return solve(0,costs);
    }
};
// @lc code=end


// @lc code=end

