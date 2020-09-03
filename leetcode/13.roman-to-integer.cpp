/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

// @lc code=start

// Approach: two kind of notation(operation) can be found when value of charAt[i] > value of charAt[i+1] or vice versa
//     it should be added in former condition and subtraction in later.




class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> hm;
        hm['I'] = 1;
        hm['V'] = 5;
        hm['X'] = 10;
        hm['L'] = 50;
        hm['C'] = 100;
        hm['D'] = 500;
        hm['M'] = 1000;

        int n = s.length();
        int res = 0;
        for(int i=0;i<n;i++) {
            if(i==n-1) {
                res+=hm[s[i]];
                break;
            }
            if(hm[s[i]] >= hm[s[i+1]]) {
                res+=hm[s[i]];
            } else {
                res+=hm[s[i+1]];
                res-=hm[s[i]];
                i++;
            }
        }
        return res;

    }
};
// @lc code=end

