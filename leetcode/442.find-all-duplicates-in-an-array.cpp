/*
 * @lc app=leetcode id=442 lang=cpp
 *
 * [442] Find All Duplicates in an Array
 */

// @lc code=start

/*
Obs: all the array elements are in  1 ≤ a[i] ≤ n it means we can use indexes in some short of manner
Algo: 
step1: whenever we reach a element check if element of that pos is +ve if it is make it negative 
       which means this element has encountered for the first timr
step2: else if negative push it to result array this means that element already has occured and it's second time

*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            if(nums[abs(nums[i])-1] < 0) res.push_back(abs(nums[i]));
            else {
                nums[abs(nums[i]) - 1] *= -1;
            }
        }
        return res;
    }
};
// @lc code=end

