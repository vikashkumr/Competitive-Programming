/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

// @lc code=start
/*Aproach
1. shift all element of 1st array n pos right
2. take two pointer one at starting point of nums1 and other at starting point of nums2
3. keep another pointer at 1st index of nums1
3. apply merge procedure for two sorted array and keep feeling nums1 
4. take care of base case
*/


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(nums2.size() == 0) return;
        if(m==0) {
            nums1 = nums2;
            return;
        }
        
        for (int i = m - 1; i >= 0; i--) {
            nums1[i + n] = nums1[i];
        }
        int p1 = 0, p2 = n, p3 = 0;
        while(p2 <= (m+n-1) and p3 <= n-1) {
            if(nums1[p2] < nums2[p3]) {
                nums1[p1++] = nums1[p2++];
            } else {
                nums1[p1++] = nums2[p3++];
            }
        }
        
        while(p3 < n and p1 < m+n) {
            nums1[p1++] = nums2[p3++];
        }
    }
};
// @lc code=end

