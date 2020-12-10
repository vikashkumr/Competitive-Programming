/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string res, word;
        for(int i=0;i<n;i++) {
            if(s[i] == ' ') continue;
            while(i<n && s[i]!=' ') {
                res+=s[i++];
            }
            if(i<n) res+=' ';
        }
        reverse(res.begin(), res.end());
        stringstream check1(res);
        string token; res = "";
        while(getline(check1, token, ' ')) {
            res+=resverse(token.begin(), token.end());
        }
        return res;
    }
};


// Another method: Efficient No extra space
// 1. reverse each word 
// 2. reverse whole string
// @lc code=end

