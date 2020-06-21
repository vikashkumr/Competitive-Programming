/*
 * @lc app=leetcode id=1095 lang=cpp
 *
 * [1095] Find in Mountain Array
 */

// @lc code=start
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

/*
Idea: find pivot index and then search in left part if found then return else search in right part and return , 
[NOTE]: we have to find least index so don't return in mid section.

*/

class Solution {
public:
    int n;
    int pivot(MountainArray &mountainArr) {
        int l = 0, r = n - 1;
        while(l<=r) {
            int mid = (l + r) / 2;
            if(mid==0 or mid==n-1)
                return mid;
            int m = mountainArr.get(mid);
            int m_minus1 = mountainArr.get(mid - 1);
            int m_plus1 = mountainArr.get(mid + 1);
            if (m > m_minus1 and m > m_plus1){
                return mid;
            }
            else if (m > m_minus1)            {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return -1;
    }

    int b_search_left(MountainArray &mountainArr,int target, int l, int r) {
        int ans = -1;
        while(l<=r) {
            int mid = (l + r) / 2;
            int m = mountainArr.get(mid);
            if(m == target) {
                //impportant
                ans = mid;
                r = mid - 1;
            } else if(m > target){
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }

    int b_search_right(MountainArray &mountainArr,int target, int l, int r) {
        int ans = -1;
        while(l<=r) {
            int mid = (l + r) / 2;
            int m = mountainArr.get(mid);
            if(m == target) {
                ans = mid;
                r = mid - 1;
            } else if(m > target){
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        n = mountainArr.length();
        int piv_idx = pivot(mountainArr);
        int idx_left = b_search_left(mountainArr, target, 0, piv_idx);
        if(idx_left != -1) return idx_left;
        int idx_right = b_search_right(mountainArr, target,piv_idx+1,n-1);
        return idx_right;
    }
};
// @lc code=end

