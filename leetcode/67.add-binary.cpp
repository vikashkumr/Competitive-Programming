/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        int la = a.length();
        int lb = b.length();

        int diff = abs(la-lb);
        if(la < lb) {
            while(diff--) a = '0'+a;
        } else {
            while(diff--) b = '0'+b;
        }
        string res = "";
        for(int i=a.size()-1;i>=0;i--) {
            int val = a[i]-48 + b[i] - 48 + carry;
            if(val==0) {
                res+= '0';
            } else if(val==1) {
                res+='1';
                carry = 0;
            } else if(val == 2) {
                res+='0';
                carry = 1;
            } else if(val == 3) {
                res+='1';
                carry = 1;
            }
        }
        if(carry) res+='1';
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

