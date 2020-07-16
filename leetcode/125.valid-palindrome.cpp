/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        for(int i=0;i<s.length();i++) {
            if(s[i]>='A' and s[i]<='Z') s[i]+=32;
        }

        int i = 0;
        int j = s.length()-1;
        while(i<j) {
            if((s[i]<'a' or s[i]>'z') and (s[i]<'0' or s[i]>'9')) {
                i++;
            } else if((s[j]<'a' or s[j]>'z') and (s[j]<'0' or s[j]>'9')) {
                j--;
            } else if((s[i]>='a' and s[i]<='z') and (s[j]>='a' and s[j]<='z')) {
                if(s[i]!=s[j]) return false;
                i++;j--;
            } else if((s[i]>='0' and s[i]<='9') and (s[j]>='0' and s[j]<='9')) {
                if(s[i]!=s[j]) return false;
                i++;j--;
            } else return false;
        }
        return true;
    }
};
// @lc code=end

