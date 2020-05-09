//https://leetcode.com/problems/target-sum/

class Solution {
public:
    int dp[2001][21];
    int shift = 1000;
    int solve(vector<int>& nums, int pos,int s, int Tot) {
        //base case
        if(pos==nums.size() and s==Tot) return 1;
        if(pos>=nums.size()) return 0;
        
        int &ans = dp[s+shift][pos];
        if(ans != -1) return ans;
        
        //recursive case
        
        int op1 = solve(nums, pos+1, s + nums[pos],Tot);
        int op2 = solve(nums, pos+1, s - nums[pos],Tot);
        return ans = (op1 + op2);  
        
    }
    
    int findTargetSumWays(vector<int>& nums, int S) {
        memset(dp, -1, sizeof dp);
        return solve(nums,0,0,S);    
    }
};