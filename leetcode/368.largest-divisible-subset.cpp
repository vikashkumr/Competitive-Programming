/*
 * @lc app=leetcode id=368 lang=cpp
 *
 * [368] Largest Divisible Subset
 */

// @lc code=start
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if(n<=1) return nums;
        vector<vector<int>> v(n);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            v[i].push_back(nums[i]);
        }
        for (int i = 1; i < n; i++) {
            int idx = -1;
            int sz = 0;
            for (int j = i - 1; j >= 0; j--) {
                if(nums[i]%nums[j]==0 and v[j].size()>sz) {
                    sz = v[j].size();
                    idx = j;
                }
            }
            if(idx != -1) {
                vector<int> loc = v[idx];
                loc.push_back(nums[i]);
                v[i] = loc;
            } 
        }
        int idx = -1;
        int len = -1;
        int i = 0;
        for(auto vec: v) {
            int sz = vec.size();
            if(sz>len) {
                idx = i;
                len = sz;
            }
            i++;
        }
        return v[idx];
    }
};
// @lc code=end

