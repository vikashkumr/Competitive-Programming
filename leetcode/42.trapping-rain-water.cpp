/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start

//at any index max water can be stored as min(leftbuilding H, rightbuilding H) - height ofcurrent building
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()==0) return 0;
        int n = height.size();
        int leftB[100000] = {0};
        int rightB[100000] = {0};
        leftB[0] = height[0];
        rightB[n-1] = height[n-1];

        //max height left boundry for ith element
        for(int i=1;i<n;i++) {
            leftB[i] = max(height[i],leftB[i-1]);       
        }

        //max height right boundry for ith element
        for(int i=n-2;i>=0;i--) {
            rightB[i] = max(height[i],rightB[i+1]);       
        }
        int ans = 0;
        for(int i=0;i<n;i++) {
            ans+=max(min(leftB[i], rightB[i])-height[i], 0);       
        }

        return ans;
    }
};
// @lc code=end

