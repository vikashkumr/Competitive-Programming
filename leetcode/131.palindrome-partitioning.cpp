/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

// @lc code=start
class Solution {
public:

    bool isPallindrome(string s) {
        for(int i= 0;i<s.length()/2;i++) {
            if(s[i]!=s[s.length()-i-1]) return false;
        }
        return true;
    }

    vector<vector<string>> res;
    void solve(int pos, string &s, vector<string> v) {

        //base case
        if(pos == s.length()) {
            res.push_back(v);
            return;
        }

        //recursive case
        for(int i=1;i <= s.length()-pos; i++) {
            string tmpstr = s.substr(pos,i);
            if(isPallindrome(tmpstr)) {
                v.push_back(tmpstr);
                solve(pos+i, s, v);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> v;
        solve(0,s,v);
        return res;
    }
};
// @lc code=end

