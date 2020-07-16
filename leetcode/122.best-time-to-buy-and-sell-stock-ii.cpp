/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start

/*Approach: 
    Observation: if(price[i]>price[i-1]) we can sell on ith day and buy at (i-1)th day add all those interval
    doubt may come that in this approach range is overapping but it's not 

    if slope is  
                      /
     /\  /\      or  /
    /  \/  \        /      diff of 0 to n is equal to 0 to n1 >< n1 to n2 and so on n_last to n, it's a beutifu ovservation

    ==> If didn't understand this approach watch Tech Dose video Youtube



  ==> another idea is we can use memoization + recc , each state divide in to 3 part , it will not pass a test case

*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1) return 0;

        int ans = 0;
        for(int i = 1; i < prices.size(); i++) {
            int curr = prices[i] - prices[i-1];
            ans += (curr > 0) ? curr : 0;
        }

        return ans;
    }
};
// @lc code=end

