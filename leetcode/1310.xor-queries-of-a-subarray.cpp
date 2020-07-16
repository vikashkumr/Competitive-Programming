/*
 * @lc app=leetcode id=1310 lang=cpp
 *
 * [1310] XOR Queries of a Subarray
 */

// @lc code=start

/*
Approach: 
Based on XOR propery a^b = c => c^a = b  and a^a = 0

*/

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        
        int n = arr.size();
        if(n==0) return {};
        int prefix_xor[30000]={0};
        prefix_xor[0] = arr[0];
        for(int i=1;i<n;i++) {
            prefix_xor[i]=prefix_xor[i-1]^arr[i];
        }

        vector<int> res;
        for(auto it: queries) {
            int l = (it[0]>0) ? prefix_xor[it[0]-1] : 0;
            res.push_back(prefix_xor[it[1]]^l);
        }
        return res;
    }
};
// @lc code=end

