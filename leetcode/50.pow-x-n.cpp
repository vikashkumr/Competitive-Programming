/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double myPow(double x, long p) {
        double res = 1.0;
        if(n<0) x = 1/x;
        n = abs(n);
        while(n>0) {
            if((n&1)) {
                res*=x;
                n--;      
            } else {
                x*=x;
                n/=2;
            }
        }
        return res;
    }
};
// @lc code=end

