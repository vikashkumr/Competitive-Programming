/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
//two passes
//in first pass ans[i] store product up to ans[i-1]
//in second pass from back use first pass val and product val 
// which contains product of number ahead of i

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int product = 1;
        for(int x: nums) {
            ans.push_back(product);
            product *=x;
        }
        
        product = 1;
        for(int i=ans.size()-1;i>=0;i--) {
            ans[i] = ans[i]*product;
            product*=nums[i];
        }
    
        return ans;
    }
};
// @lc code=end

