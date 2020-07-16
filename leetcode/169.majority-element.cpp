/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        
        //Moore's voting algo see Tech Doseif won't getting
        int maj = nums[0];
        int cnt = 1;
        for(int i=1;i<n;i++) {
            if(nums[i]==maj) cnt++;
            else {
                cnt--;
            } 
            
            if(cnt==0) {
                cnt=1;
                maj = nums[i];
            }
        }
        
        cnt = 0; ///now cnt work as counting for majority element
        for(int x: nums) {
            if(x == maj) cnt++;
            if(cnt>n/2) return maj;
        }
        
        return 0;  
    }
};
// @lc code=end

