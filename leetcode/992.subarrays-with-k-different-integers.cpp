/*
 * @lc app=leetcode id=992 lang=cpp
 *
 * [992] Subarrays with K Different Integers
 */

// @lc code=start
class Solution {
public:
    int no_of_subarr(vector<int> &A, int k) {
        if(k==0) return 0;
        int diff = 0; //different integer occoured till now
        int cnt[20002]={0}; //count of occurance of i
        int i = 0; //left pointer
        int ans = 0; //total no of subarray
        for(int j=0;j<A.size();j++) {
            if(cnt[A[j]]==0) diff++; 
            cnt[A[j]]++;
            if(diff <= k) {
                ans+=j-i+1; // number of subarray considering element at j
            } else {
                while(j<A.size() && i<=j && diff>k) {
                    cnt[A[i]]--;
                    if(cnt[A[i]]==0) diff--;
                    //for every step incrementing becz its deleting single assumed to delete 
                    //element due to that index not by every index
                    i++;
                }
                ans+=j-i+1;
            }
        }
        return ans;
    }

    int subarraysWithKDistinct(vector<int>& A, int K) {
        //no_of_subarr(A,k) => all subarray of atmost k distinct element
        return no_of_subarr(A,k) - no_of_subarr(A,k-1);
    }
};
// @lc code=end

