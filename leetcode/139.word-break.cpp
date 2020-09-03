/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
class Solution {
public:
    unordered_map<string,bool> hm;
    int *dp;
    int solve(int pos, string s) {
        //base case
        if(pos == s.length()) {
            return 1;
        }
        int &ans = dp[pos];
        if(ans != -1) return ans;
        
        //recursive case
        for(int i=pos+1;i<=s.length();i++) {
            string t = s.substr(pos,i-pos);
            if(hm.count(t) && solve(i,s)) {
                return ans = 1;
            }
        }
        return ans = 0;
        
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        for(string word : wordDict) hm.insert({word,true});
        dp = new int[s.length()+1];
        for(int i=0;i<=s.length();i++) dp[i]=-1;
        // memset(dp, -1, sizeof dp);
        return solve(0,s);
    }
};
// @lc code=end

