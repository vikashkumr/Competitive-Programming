/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */

// @lc code=start
//buy or skip at current day
class Solution {
public:

    vector<int> dp;
    int findMax(int curr, int n, vector<int> &prices) {
        if(curr >= n) return 0;

        int &ans = dp[curr];
        if(ans != -1) return ans;

        int mxVal = 0;
        for(int i = curr+1; i<n; ++i) {
            if(prices[curr] < prices[i]) {
                mxVal = max(mxVal, prices[i] - prices[curr] + findMax(i+2, n, prices));
            }
        }

        mxVal = max(mxVal, findMax(curr+1, n, prices));
        return ans = mxVal;
    }



    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        dp.resize(len+1, -1);
        return findMax(0, len, prices);
    }
};
// @lc code=end

//state machine
//at any point of time we could have 3 states
//no stock => max profit if you don't have any stock on a perticular day
//inHand => max profit curr day with stock in hand
//sell => max profit on a given day when we sold certain stock given day



// 1. no stock                   2. inHand                         3. sell
    /          \               /        \                               |
   /            \             /          \                              |
no stock      sold      inHand          noStock-currBuy         inhand + price[today]



int maxProfit(vector<int>& prices) {
    if(prices.size() == 0 or prices.size()==1) return 0;
    int len = prices.size();
    vector<int> noStock(len), inHand(len), sell(len);
    noStock[0] = 0; sell[0] = 0; inHand[0] = -prices[0]; //inhand buyed

    for(int i=1; i<len; i++) {
        noStock[i] = max(noStock[i-1], sell[i-1]);
        inHand[i] = max(inHand[i-1], noStock[i-1]-prices[i]);
        sell[i] = inHand[i-1] + prices[i];
    }
    return max(noStock[len-1], sell[len-1]);
}


