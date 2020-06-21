/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

// @lc code=start
/* APPROACH
Brute force sol will take O(n!) time

Efficient:

Obs1: 24'6'432 => _ _6_ _ _ (no effect changing any val as rightward elements are in decreasing order) 
                      So we have to find first element from last which is in decreasing order
Obs2: Now the found element to be swapped with element in right just greater than found element (4) in ex case
step: Now we should sort element rightward to found pos toget least overall value
Obs3: As elemnt in rightword are in decrasing order so we can simply reverse it also

*/




class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i + 1] <= nums[i]) {
            i--;
        }
        if (i >= 0) {
            int j = nums.size() - 1;
            while (j >= 0 && nums[j] <= nums[i]) {
                j--;
            }
            swap(nums[i],nums[j]);
        }
        reverse(nums.begin()+i+1, nums.end());
    }
};
// @lc code=end

