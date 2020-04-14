class Solution {
public:
    
    bool arr[1000001]={0};
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        for(int i=0;i<nums1.size();i++) {
            arr[nums1[i]]=1;
        }
        for(int i=0;i<nums2.size();i++) {
            if(arr[nums2[i]]) {
                res.push_back(nums2[i]);
                arr[nums2[i]] = 0; 
            }
        }
        return res;
    }
};