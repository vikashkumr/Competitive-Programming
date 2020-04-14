class Solution {
public:
    bool arr[1001] = {0};
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> res;
        sort(arr1.begin(),arr1.end());
        for(int i=0;i<arr2.size();i++) {
            int idx1 = lower_bound(arr1.begin(),arr1.end(),arr2[i])-arr1.begin();
            int idx2 = upper_bound(arr1.begin(),arr1.end(),arr2[i])-arr1.begin();
            for(int j = idx1;j<idx2;j++) {
                res.push_back(arr1[j]);
                arr[arr1[j]] = true;
            }
        }
        for(int i=0;i<arr1.size();i++) {
            if(arr[arr1[i]]==0) res.push_back(arr1[i]);
        }
        return res;
    }
};