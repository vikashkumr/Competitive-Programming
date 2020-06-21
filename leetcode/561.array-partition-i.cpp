/*
 * @lc app=leetcode id=561 lang=cpp
 *
 * [561] Array Partition I
 */

// @lc code=start
//simple approach is to sort array and take alternate element O(nlogn)
//below Solution is in O(n) using counting sort

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int n = nums.size();
        int count[20001] = {0};
        for(int i=0;i<n;i++) {
            count[nums[i]+10000]++;
        }
        
        bool left = 0;
        int ans = 0;
        //if freq even add n/2(flag==0) else n/2 +1(flag==1)
        //if(flag==1) reduce next freq by 1
        for(int i=0;i<=20000;i++) {
            if(count[i]!=0) {
                if(left) {
                    count[i]--;
                    if(count[i]&1) {
                        ans+=(i-10000)*(count[i]/2 +1);
                    } else {
                        ans+=(i-10000)*(count[i]/2);
                        left = !left;
                    }
                } else {
                    if(count[i]&1) {
                        ans+=(i-10000)*(count[i]/2 +1);
                        left = !left;
                    } else {
                        ans+=(i-10000)*(count[i]/2);
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end

