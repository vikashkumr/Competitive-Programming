//https://leetcode.com/problems/minimum-falling-path-sum/

class Solution {
public:
    int dp[101][101];
    int n;
    int solve(int pos,int i, vector<vector<int>>& arr) {
    //base case
    if(pos==n) return 0;

    //recursive case
    int &ans = dp[pos][i];
    if(ans != -1) return ans;
    int op1 = INT_MAX, op2 = INT_MAX, op3 = INT_MAX;
    op1 = arr[pos][i] + solve(pos+1,i,arr);
    if(i+1<n)
    op2 = arr[pos][i] + solve(pos+1,i+1,arr); 
    if(i-1>=0)
    op3 = arr[pos][i] + solve(pos+1,i-1,arr);
    return ans = min(op1,min(op2,op3));
    }
    
    
    int minFallingPathSum(vector<vector<int>>& A) {
        n = A.size();
        memset(dp, -1, sizeof dp);
        int ans = INT_MAX;
        for(int i = 0; i<n;i++) {
            ans = min(ans,solve(0,i,A));
        }
        return ans;
    }
};