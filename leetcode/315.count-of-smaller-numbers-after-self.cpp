/*
 * @lc app=leetcode id=315 lang=cpp
 *
 * [315] Count of Smaller Numbers After Self
 */

// @lc code=start
//Approach : MergeSort , alter merge procedure and keep track of indexes of each element
//because that we need to increase. rightCnt will be added in each element present in left subarray
//take an example if find difficulties to understand

class Solution {
public:
    vector<int> cnt;
    vector<pair<int,int>> arr; // element, idx
    void merge(int l, int mid, int r) {
        vector<pair<int,int>> a; // element, idx
        int i = l;
        int j = mid+1;
        int rightCnt = 0;
        while(i<=mid and j<=r) {
            if(arr[i].first > arr[j].first) {
                a.push_back(arr[j++]);
                rightCnt++;
            } else {
                //increased index
                cnt[arr[i].second] += rightCnt;
                a.push_back(arr[i++]);
            }
        }
        while(i<=mid) {
            a.push_back(arr[i]);
            cnt[arr[i++].second] += rightCnt;
        }
        while(j<=r) a.push_back(arr[j++]);

        //element moves with index as well otherwise we will leave index track 
        for(i=0;i<a.size();i++) arr[i+l] = a[i];
        return;
    }

    void mergeSort(int l, int r) {
        if(l>=r) return;
        int mid = (l+r)/2;
        mergeSort(l,mid);
        mergeSort(mid+1,r);
        merge(l,mid,r);
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        // arr.resize(n);
        cnt.resize(n, 0);
        for(int i=0;i<n;i++) {
            arr.push_back({nums[i], i});       
        }
        mergeSort(0,nums.size()-1);
        return cnt;
    }
};
// @lc code=end

