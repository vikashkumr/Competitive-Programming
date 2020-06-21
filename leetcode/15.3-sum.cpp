class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i=0;i<nums.size();i++) {
            if(i==0 or nums[i]!=nums[i-1]) {
                int sum = -1*nums[i];
                int l = i+1;
                int r = nums.size()-1;
                while(l<r) {
                    if(nums[l]+nums[r]==sum) {
                        res.push_back({nums[l],nums[r],nums[i]});
                        while(l<r and nums[l+1]==nums[l]) l++;
                        while(l<r and nums[r-1]==nums[r]) r--;
                        l++;r--;
                    } else if(nums[l]+nums[r]>sum) {
                        r--;
                    } else {
                        l++;
                    }
                }
            } 
        }
        return res;
        
    }
};