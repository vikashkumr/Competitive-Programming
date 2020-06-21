/*
 * @lc app=leetcode id=1048 lang=cpp
 *
 * [1048] Longest String Chain
 */

// @lc code=start
class Solution {
public:

    bool differChar(string s1, string s2) {
        int arr[26] = {0};
        for(char ch: s1) {
            arr[ch - 'a']++;
        }
        for(char ch: s2) {
            arr[ch - 'a']--;
        }
        bool ok = 1;
        for (int i = 0; i < 26;i++) {
            if(arr[i]!=0 and ok) {
                ok = 0;
            } else if(ok==0 and arr[i]!=0){
                return false;
            }
        }
        return true;
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [&](string s1, string s2) {
            return s1.length() < s2.length();
        });
        int n = words.size();
        int dp[n];
        fill(dp, dp + n, 1);
        for (int i = 1; i < n; i++) {
            int mx = -1;
            for (int j = i-1; j >= 0; j--) {
                if(words[i].size()-words[j].size() == 1 and differChar(words[i],words[j])) {
                    mx = max(mx, dp[j]);
                }
            }
            if(mx != -1) {
                dp[i] += mx;
            }
        }
        int ans = -1;
        for (int x : dp) ans = max(ans, x);
        return ans;
    }
};
// @lc code=end

