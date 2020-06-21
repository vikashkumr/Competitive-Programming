/*
 * @lc app=leetcode id=330 lang=cpp
 *
 * [330] Patching Array
 */

// @lc code=start
/*
Approach: Greedy
idea: take a miss = 1 which should be less than n, which represents what is tne next value we have to add

Algo: 
step1: while(miss<=n) we will see which element is present and which are not present
step2: if miss is x and array's last element is less than x we will add that element to miss 
        miss's range will increase upto miss+nums[i]
    else
        miss += miss; and ans++;




*/

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long int miss = 1;
        int i = 0, add = 0;
        while(miss <= n) {
            if(i < nums.size() and miss >= nums[i]) {
                miss += nums[i];
                i++;
            } else {
                miss+=miss;
                add++;
            }
        }
        return add;
    }
};
// @lc code=end

