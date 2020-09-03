/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.length()==1) return 0;
        int n = s.length();
        int arr[1000001]={0};
        for(int i=1;i<s.length();i++) {
             if(s[i]==')') {
                if(s[i-1]=='(') {
                arr[i] = 2 + ((i-2>=0) ? arr[i-2]:0);
                } 
                else {
                    if(i-arr[i-1]-1>=0 and s[i-arr[i-1]-1]=='(') 
                        arr[i] = 2 + arr[i-1] + ((i-arr[i-1]-2>=0)?arr[i-arr[i-1]-2]:0);
                }
            }
        }
        int ans = 0;  
        for(int i=0;i<s.length();i++) {
            ans = max(ans,arr[i]);
        }
        return ans;
    }
};
// @lc code=end

