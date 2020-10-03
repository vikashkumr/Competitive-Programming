/*
 * @lc app=leetcode id=1218 lang=cpp
 *
 * [1218] Longest Arithmetic Subsequence of Given Difference
 */

// @lc code=start
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int d) {
        unordered_map<int,int> hm;
        for(int x: arr) {
            hm[x] = 1 + hm[x-d];
        }
        int ans = 1;
        for(auto x: hm) {
            ans = max(ans, x.second);
        }
        return ans;
    }
};
// @lc code=end

