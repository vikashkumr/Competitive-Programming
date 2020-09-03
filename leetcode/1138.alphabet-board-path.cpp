/*
 * @lc app=leetcode id=1138 lang=cpp
 *
 * [1138] Alphabet Board Path
 */

// @lc code=start
class Solution {
public: 
    string alphabetBoardPath(string target) {
        int x = 0, y = 0;
        string ans = "";
        for(int i=0;i<target.length();i++) {
            char ch = target[i];
            int x1 = (ch-'a')/5;
            int y1 = (ch-'a')%5;
            //order matter think why //case "bwz"
            if(x1<x) ans+=string(x-x1,'U');
            if(y>y1) ans+=string(y-y1,'L');
            if(x1>x) ans+=string(x1-x,'D');
            if(y1>y) ans+=string(y1-y,'R');
            
            ans+='!';
            x = x1;y=y1;
        }
        return ans;
        
    }
};
// @lc code=end

