/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 */

// @lc code=start
class Solution {
public:
    //TC: O(max-min) SC: O(size of arr)
    int firstMissingPositive(vector<int>& nums) {
        if(arr.size()==0) return 1;
        unordered_map<int,bool> hm;
        for(int x: arr) hm[x] = 1;
        int mn = *min_element(arr.begin(),arr.end());
        int curr=1;
        if(mn<=0) 
            curr = 1;
        if(mn>1) return 1;
        int mx = *max_element(arr.begin(),arr.end());
        for(int i=1;i<=mx;i++) {
            if(!hm[i]) return i;
        }

        return max(1,mx+1);
    }

    // ===================================================
    //TC: O(n) SC: O(1)
    
    int firstMissingPositive(vector<int>& arr) {
        
        int n = arr.size();
        for(int i=0;i<n;i++) if(arr[i]<=0) arr[i] = n+1; //beacause n+1 out of arr index range
        for(int i=0;i<n;i++) {
            if(abs(arr[i])<=n && arr[abs(arr[i])-1]>0) {
                arr[abs(arr[i])-1] *= -1;
            }
        }
        for(int i=0;i<n;i++) if(arr[i]>0) return i+1;
        return n+1;
    }
};
// @lc code=end

