/*
 * @lc app=leetcode id=1031 lang=cpp
 *
 * [1031] Maximum Sum of Two Non-Overlapping Subarrays
 */

// @lc code=start
class Solution {
public:
    int n;
    int getMax(int i, int j, vector<int>& pre, int wsz) {
        if(i<1 or i>n or j<1 or j>n) return 0;
        if(wsz > j-i+1) return 0;
        int sum = pre[wsz+i - 1]-pre[i-1];
        int tmpi = i+1, tmpj = wsz+i;
        while(tmpj<=j) {
            if(pre[tmpj] - pre[tmpi-1] > sum) {
                sum = pre[tmpj] - pre[tmpi-1];
            }
            tmpi++;
            tmpj++;
        }
        return sum;
    }

    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        int ans = 0;
        n = A.size();
        vector<int> pre(n+1,0);
        pre[1] = A[0];
        for(int i=1;i<n;i++) pre[i+1]+=A[i]+pre[i];
        if(L>M) swap(L,M);

        int st = 0;
        for(int i=L;i<=n;i++) {
            int ans1 = pre[i]-pre[st];
            int ans2 = max(getMax(i+1,n,pre,M),getMax(1,st,pre,M));
            ans = max(ans,ans1+ans2);
            st++;
        }
        return ans;
    }
};
// @lc code=end

