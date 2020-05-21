class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int t = 0;
        for(int num : nums) t^=num;
        int last_set = t&(-t);
        int pos = log2(last_set);
        int set1 = 0;
        int set2 = 0;
        for(int num: nums) {
            int n = num;
            int p = 0;
            while(p<=pos) {
                if(p==pos) {
                    if((n&1)) set1^=num;
                    else set2^=num;
                }
                n >>= 1;
                p++;
            }
        }
        if(set1>0) {
            return {set1,set1^t};
        } else {
            return {set2,set2^t};
        }
    }
};