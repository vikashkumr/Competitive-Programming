/*
 * @lc app=leetcode id=1016 lang=cpp
 *
 * [1016] Binary String With Substrings Representing 1 To N
 */

// @lc code=start

// Approach: 
// For every i < N/2, the binary string of "2*i" will contain binary string of "i". That is, binary string of "i"will be a sub-string.

class Solution {
    
    string convertBinary(int n) {
        
        string res;
        while (n) {
            res += to_string(n%2);
            n /= 2;
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
public:
    bool queryString(string S, int N) {
        
        for (int i = N; i >= N/2; i--) {
            string str = convertBinary(i);
            if (S.find(str) == string::npos)
                return false;
        }
        
        return true;
        
    }
};
// @lc code=end

