/*
 * @lc app=leetcode id=524 lang=cpp
 *
 * [524] Longest Word in Dictionary through Deleting
 */

// @lc code=start
class Solution {
public:
    bool found(string &s1, string &s2) {
        int p1 = 0;
        int p2 = 0;
        while(p1 < s1.length() && p2 < s2.length()) {
            if(s1[p1] == s2[p2]) {
                p1++,p2++;
            } else p2++;
        }
        if(p1 == s1.length()) return true;
        return false;
    }
    
    string findLongestWord(string s, vector<string>& d) {
        string res = "";
        for(string &str : d) {
            if(found(str, s)) {
                if(res.length() == 0) {
                    res = str;
                } else if(str.length() > res.length()) {
                    res = str;
                } else if(str.length() == res.length() and str < res) {
                    res = str;
                }
            }
        }
        return res;
    }
};
// @lc code=end

