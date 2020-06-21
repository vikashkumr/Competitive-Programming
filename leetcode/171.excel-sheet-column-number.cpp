/*
 * @lc app=leetcode id=171 lang=cpp
 *
 * [171] Excel Sheet Column Number
 */

// @lc code=start

// Observed from backword

class Solution {
public:
    int titleToNumber(string s) {
        int n = s.length();
        int ans = 0;
        for (int i = 0; i < n; i++) {
                ans += pow(26,n-i-1) * (s[i] - 'A' + 1);
        }
        return ans;
    }
};
// @lc code=end

