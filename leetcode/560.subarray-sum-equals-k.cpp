/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& arr, int target) {
        int num_of_subarray=0;
        unordered_map<int,int> mp;
        mp.insert({0,1});
        int curr_sum=0;
        for(int i=0;i<arr.size();i++){
            curr_sum+=arr[i];
            if(mp.find(curr_sum-target)!=mp.end()) num_of_subarray+=mp[curr_sum-target];
            mp[curr_sum]++;
        }
        return num_of_subarray;
    }
};
// @lc code=end

