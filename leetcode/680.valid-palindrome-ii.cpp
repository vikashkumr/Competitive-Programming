/*
 * @lc app=leetcode id=680 lang=cpp
 *
 * [680] Valid Palindrome II
 */

// @lc code=start
class Solution {
public:
    bool isPallindrome(string &s, int i, int j) {
        while(i<j) {
            if(s[i]==s[j]) {
                i++,j--;
            } else return false;
        }
        return true; 
    }
    
    bool validPalindrome(string s) {
        int i=0, j = s.length()-1;
        while(i<j) {
            if(s[i]==s[j]) {
                i++,j--;
            } else {
                if(isPallindrome(s,i+1,j) || isPallindrome(s,i,j-1)) return true;
                else return false;
            }
        }
        return true;
    }
};
// @lc code=end

