/*
 * @lc app=leetcode id=942 lang=cpp
 *
 * [942] DI String Match
 */

// @lc code=start
//Two pointer smallest and greatest


class Solution {
public:
    vector<int> diStringMatch(string s) {
        int len = s.length();
        vector<int> v(len+1);
        int small = 0, greatest = len;
        for(int i = 0;i <len; i++) {
            if(s[i]=='I') {
                 v[i] = small++;
            } else if(s[i]=='D') {
                v[i] = greatest--;
            }
            if(i==len-1) {
                if(s[i]=='I') v[i+1] = greatest;
                else v[i+1] = small;
            }
        }
        return v;
    }
};
// @lc code=end

