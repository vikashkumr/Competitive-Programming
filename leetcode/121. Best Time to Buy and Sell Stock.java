class Solution {
    public int maxProfit(int[] prices) {
        
        if(prices.length == 0) return 0;
        if(prices.length == 1) return 0;
        
        int max = 0;
        int buy = prices[0];
        
        for(int i = 1; i < prices.length; i++){
            if(max < prices[i] - buy){
                max = prices[i] - buy;
            }
            if(buy > prices[i])
                buy = prices[i];
        }
        return max;
    }
}
