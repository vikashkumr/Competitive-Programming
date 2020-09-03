#include<bits/stdc++.h>
using namespace std;
/*
    Input 1:
    A = [40, 20, 30, 10, 30]
    Output 1:
        26000
        Explanation 1:
            Dimensions of A1 = 40 x 20
            Dimensions of A2 = 20 x 30
            Dimensions of A3 = 30 x 10
            Dimensions of A4 = 10 x 30
            First, multiply A2 and A3 ,cost = 20*30*10 = 6000
            Second, multilpy A1 and (Matrix obtained after multilying A2 and A3) =  40 * 20 * 10 = 8000
            Third, multiply (Matrix obtained after multiplying A1, A2 and A3) and A4 =  40 * 10 * 30 = 12000
            Total Cost = 12000 + 8000 + 6000 =26000

    Input 2:
        A = [10, 20, 30] 
    Output 2:
        6000
*/



// dimensions of ith matrix is dimen[i-1] x dimen[i]
int minCostOfMul(vector<int>& dimen) {
    int dp[200][200];
    memset(dp, 0, sizeof dp);
    int n = dimen.size();
    //this loop for length of chain for length 1 eg 1,1 2,2 3,3 4,4
    for(int L = 2; L < n; L++) {
        //this loop goes for all diagonol elemnt of length = L eg j-i = L
        for(int i=1;i<=n-L;i++) {
            int j = i+L-1;
            dp[i][j] = INT_MAX;
            //this loop is for partitioning or pivote form i to j-1 ABC => A|BC , AB|C
            for(int k=i;k<j;k++) {
                dp[i][j] = min(dp[i][j],dp[i][k] + dp[k+1][j] + dimen[i-1]*dimen[k]*dimen[j]);
            }
        }
    }
    return dp[1][n-1];
}


int main() {
    vector<int>v({10,20,30});
    cout<<minCostOfMul(v);
}


//recursive approach

class Solution {
public:
    int dp[1001][1001];
    int solve(int i, int j, vector<int> &p) {
    	if(i>=j) return 0;
        
        int &ans = dp[i][j];
        if(ans != -1) return ans;
        
        int mn = INT_MAX;
        for(int k=i;k<j;k++) {
        	int tmpAns = solve(i,k,p) + solve(k+1,j,p) + p[i-1]*p[k]*p[j];
            mn = min(mn, tmpAns);
        }
        
        return ans = mn;
    }

    int matrixChainMultiplication(vector<int>& p) {
        memset(dp, -1, sizeof dp);
   		return solve(1,p.size()-1,p);
    }
};