/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 */

// @lc code=start
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> res;
        int i = nums1.size()-1;
        int j = nums2.size()-1;
        while(i>=0 and j>=0) {
            if(nums1[i] == nums2[j]) {
                res.push_back(nums1[i]);
                i--;j--;
            } else if(nums1[i] < nums2[j]) {
                j--;
            } else {
                i--;
            }
        }
        return res;
    }
};
// @lc code=end

