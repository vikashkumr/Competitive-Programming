//BinarySearch
class Solution {
public:
    bool possible(vector<int>& nums, int lim, int m) {
        int cnt = 1;
        int sum = 0;
        for(int x : nums) {
            sum+=x;
            if(sum>lim) {
                cnt++;
                sum = x;
            }
        }
        if(cnt>m) return false;
        return true;
    }

    int splitArray(vector<int>& nums, int m) {
        if(m==0) return 0;
        int r = accumulate(nums.begin(),nums.end(),0);
        int l = *max_element(nums.begin(),nums.end());
  
        while(l<=r) {
            int mid = l + (r-l)/2;
            // cout<<l<<" "<<r<<" "<<mid<<endl;
            if(possible(nums, mid, m)) { 
                
                r = mid-1;   
            } else {
                l = mid+1;
            }
        }
        return l;
    }
};
