/*
 * @lc app=leetcode id=1278 lang=cpp
 *
 * [1278] Palindrome Partitioning III
 */

// @lc code=start
class Solution {
public:
	//count no of character to be changed to make the string pallindrome
    int operation(int i, int j, string &s) {
        int cnt = 0;
        while(i <= j) {
            if(s[i] != s[j]) {
                cnt++;
            }
            i++,j--;
        }
        return cnt;
    }
    
    int dp[101][101][101];
    
    int part(int i, int j, int k, string &s) {
		//if length if string is less than k there is No way to partition so let inf and return large number
        if(j-i+1 < k) return 9999;
		
		//here we left with single string base case
        if(k==1) {
           return operation(i, j, s);
        }
		
        int &res = dp[i][j][k];
        if(res != -1) return res;
		
        int ans = 9999;
        for(int idx = i+1; idx <= j; idx++) {
			//here I'm just considering every case recursively and took possibility which take  min operation among them
            int x = part(idx, j, k-1, s);
            ans = min(ans, operation(i, idx-1, s) + x);
        }
        
        return res = ans;
    }
    
    
    int palindromePartition(string s, int k) {
        memset(dp, -1, sizeof dp);
        return part(0,s.length()-1,k,s);
    }
};

// @lc code=end

