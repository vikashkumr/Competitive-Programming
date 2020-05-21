https://leetcode.com/problems/total-hamming-distance/

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int arr[33][2]={0};
        int mx = -1;
        int bits = 0;
        for(int num: nums) mx = max(mx,num);
        while(mx>0) {
            bits++;
            mx>>=1;
        }
        for(int num : nums) {
            int pos = 0;
            while(pos<bits) {
                if(num&1) {
                    arr[pos][1]++;
                } else {
                    arr[pos][0]++;
                }
                pos++;
                num>>=1;
            }
        }
        int ans= 0;
        for(int i=0;i<=32;i++) {
            ans+=((!arr[i][0] || !arr[i][1]) ? 0 : arr[i][0]*arr[i][1]);
        }
        
        return ans;
    }
};