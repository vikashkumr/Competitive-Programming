/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
// idea: A[0..lo-1] are less than pivot 1, A[lo..i-1] equal, A[hi+1..end] greater
//at any point of time if encounter zero left of which will be either 0 or 1
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int st = 0, mid = 0, end = n - 1;
        // 2,0,1 (equality reason)
        while(mid <= end) {
            if(nums[mid] == 0) {
                swap(nums[mid++], nums[st++]);
            } else if(nums[mid] == 2) {
                swap(nums[mid], nums[end--]);
            } else {
                mid++;
            }
            
        }
    }
};
// @lc code=end

