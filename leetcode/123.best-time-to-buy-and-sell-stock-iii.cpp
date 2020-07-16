/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 */

// @lc code=start
/*
Approach:
    since we have to do atmost 2 transaction 
    so we can calculate frofit from left side and right side separately
    ans would be max(left[i]+right[i+1]) for i=0 to n-2
    left[i] == max profit till date o to i for first transection if buyed at ith day
    right[i] == max profite till date i to n-1 if purchased at ith day
    this is the reason we need bidirection calculation of profit
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        
        int n = prices.size();
        int left_profit[200000] = {0};
        int right_profit[200000] = {0};
        
        //profit from left (similar to best time to buy and sell 1)
        int mn = prices[0];
        for(int i=1;i<n;i++) {
            left_profit[i] = max(prices[i]-mn,left_profit[i-1]);
            mn = min(mn, prices[i]);
            
        }
        
        //profit from right
        int mx = prices.back();
        for(int i=n-2;i>=0;i--) {
            right_profit[i] = max(right_profit[i+1],mx-prices[i]);
            mx = max(mx, prices[i]);
            
        }
        
        
        int ans = 0;
        for(int i=0;i<n;i++) {
            ans = max(ans, left_profit[i] + right_profit[i+1]);
        }
        return max(ans,max(left_profit[n-1],right_profit[0]));
    }
};
// @lc code=end

