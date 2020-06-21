/*
 * @lc app=leetcode id=172 lang=cpp
 *
 * [172] Factorial Trailing Zeroes
 */

// @lc code=start

/*
ans = n/5 + n/5^2 + n/5^3
Idea behind this is 0 can be formed by multiplication of 2*5
    and we would have unlimited supply of two's so we simply have to count no of occurance of 5

*/
class Solution {
public:
    int trailingZeroes(int n) {
        long long i = 5;
        int ans = 0;
        while (i<=n) {
            ans += n / i;
            i *= 5;
        }
        return ans;
    }
};
// @lc code=end

