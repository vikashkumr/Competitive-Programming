/*
* @type of arr: integer array
* @type of amount: integer
* @return type: integer
*/
class Solution {
public:
    long long dp[100000];
    long long solve(long long sum, vector<int> &arr) {
    	if(sum==0) return 0;
        
        if(dp[sum] != -1) return dp[sum];
        
        long long finalAns = INT_MAX;
        for(int coin=0;coin<arr.size();coin++) {
        	if(arr[coin] <= sum) {
            	long long ans = 1 + solve(sum - arr[coin], arr);
                if(ans < finalAns) finalAns = ans;
            }
        }
        return dp[sum] = finalAns; 
    }
    
    int minCoins(vector<int>& arr, int amount) {
   		memset(dp, -1, sizeof dp);
        long long ans = solve(amount, arr);
        if(ans>=INT_MAX) return -1;
        return ans;
    }
};