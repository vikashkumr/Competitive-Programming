/*
 * @lc app=leetcode id=1004 lang=cpp
 *
 * [1004] Max Consecutive Ones III
 */

// @lc code=start
class Solution {
public:
     int longestOnes(vector<int>& A, int K) {
		int cnt = 0, j = 0, ans = 0;
        for(int i=0;i<A.size();i++) {
            if(A[i]==0) cnt++; /* have some hashmap or counter */

            /* Loop inside for to reduce the window size based on constraint */
            while(cnt>K && j<=i) {
                if(A[j]==0) cnt--;
                j++;
            }
            /* get the maximum value of the window which satisfies the constraint */
            ans = max(ans, i-j+1);
        }
        return ans;
    }
};
// @lc code=end

