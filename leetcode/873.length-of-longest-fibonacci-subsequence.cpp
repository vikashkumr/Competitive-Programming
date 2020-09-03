/*
 * @lc app=leetcode id=873 lang=cpp
 *
 * [873] Length of Longest Fibonacci Subsequence
 */

// @lc code=start
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        unordered_set<int> s(A.begin(), A.end());
        int ans = 0;
        int n = A.size();
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                int len = 2;
                int x = A[i];
                int y = A[j];
                while(s.find(x+y) != s.end()) {
                    int z = x + y;
                    x = y;
                    y = z;
                    len++;
                    ans = max(ans, len);
                }
            }
        }
        if(ans>=3) return ans;
        return 0;
    }
};
// @lc code=end

