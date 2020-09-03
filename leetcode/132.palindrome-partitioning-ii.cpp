/*
 * @lc app=leetcode id=132 lang=cpp
 *
 * [132] Palindrome Partitioning II
 */

// @lc code=start

//O(n^3) solution MCM
class Solution {
public:
    int dp[3000][3000];
    bool isPallindrome(int i, int j, string &s) {
        int len = (j-i+1);
        for(i;i<len/2;i++) {
            if(s[i]!=s[len-i-1]) return false;
        }
        return true;
    }

    int no_of_partition(int i, int j, string &s) {
        if(i>=j) return 0;
        if(isPallindrome(i,j,s)) return 0;
        int &ans = dp[i][j];
        if(ans != -1) return ans;
        int res = INT_MAX;
        for(int k = i; k<j; k++) {
            int tmp = no_of_partition(i,k,s) + no_of_partition(k+1,j,s) + 1;
            res = min(res, tmp);
        }
        return ans = res;
    }


    int minCut(string s) {
        memset(dp, -1, sizeof dp);
        return no_of_partition(0, s.length()-1, s);
    }
};

//O(n^2) Solution 1D DP + Intution
// Explanation https://www.youtube.com/watch?v=rmNK2awrhkU 7:30

class Solution {
public:
   bool isPallindrome(int i, int j, string &s) {
        while(i<=j) {
            if(s[i++] != s[j--]) return false;
        }
       return true;
    }

    int minCut(string s) {
        int n = s.length();
        if(n == 0) return 0;
        int dp[n+1];
        for(int i=0;i<=n;i++) dp[i] = INT_MAX;
        dp[n-1] = dp[n] = 0;
        for(int i = n-2; i >= 0; i--) {
            for(int j = i;j < n; j++) {
                if(isPallindrome(i,j, s)) {
                    if(j==n-1) dp[i] = 0;
                    else
                    dp[i] = min(dp[i], 1 + dp[j+1]);
                }
            }
        }
        return dp[0];
    }

};

// @lc code=end