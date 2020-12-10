/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>>res;
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size()<4) return res;
        int len = nums.size();
        sort(nums.begin(),nums.end());
        for(int i = 0; i < len-3; i++){
             if(i!=0 && nums[i]==nums[i-1])
            continue;
            for(int j = i+1; j < len-2; j++){
                 if(j!=i+1 && nums[j]==nums[j-1])
                continue;
                
                int sum = nums[i]+nums[j];
                
                int lo = j+1;
                int hi = len-1;
                while(lo<hi){
                    if(sum+nums[lo]+nums[hi]==target){
                    res.push_back({nums[i],nums[j],nums[lo],nums[hi]});
                        lo++;hi--;
                        while(lo<hi &&nums[lo]==nums[lo-1] ){
                        lo++;
                     }
 
                    while(lo<hi &&nums[hi]==nums[hi+1]){
                        hi--;
                        }
                    }
                    else if(sum+nums[lo]+nums[hi]<target){
                        lo++;
                    }
                    else {
                        hi--;
                    }
   
                }                
                
            }
        }
        return res;
    }
};
// @lc code=end

