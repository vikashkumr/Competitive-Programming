//https://leetcode.com/problems/triangle/

class Solution {
public:
    int dp[1001][1001];
    
    int solve(int pos,int col, vector<vector<int>>& tri) {
        if(pos >= tri.size()) return 0;
        
        int &ans = dp[pos][col];
        if(ans != INT_MAX-1) return ans;
        
        int op1, op2;
        op1 = op2 = tri[pos][col];
        op1 += solve(pos+1,col,tri);
        if(pos+1<tri.size() and (col+1) < tri[pos+1].size())
        op2 += solve(pos+1,col + 1,tri);
        
        return ans = min(op1,op2);
        
    }
    
    
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i=0;i<=1000;i++) {
           for(int j=0;j<=1000;j++) 
               dp[i][j] = INT_MAX-1;
        }
        return solve(0, 0, triangle); 
    }
};