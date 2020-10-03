/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */

// @lc code=start
//log(a/b) = log(a)-log(b)
class Solution {
public:
    int divide(int dividend, int divisor) {
        
        int sign = 1;
        if(divisor < 0 and dividend>0) sign = -1;
        if(divisor > 0 and dividend<0) sign = -1;
        long dividen = (long) abs(dividend);
        long diviso = (long) abs(divisor);
        
        long res = exp(log(dividen)-log(diviso));
        if(res>INT_MAX)
            return sign==1 ? INT_MAX:INT_MIN;
        return sign*(int)res;
    }
};
// @lc code=end

