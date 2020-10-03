
//sliding window
class Solution {
public:
    int ans = 0;
    int lengthOfLongestSubstringKDistinct(string &s, int k) {
        int distinct = 0;
        if(k==0) return 0;
        int l = 0;
        unordered_map<char, int> hm;
        for(int r = 0; r < s.length(); r++) {
            if(hm[s[r]]==0) {
               distinct++;
            }
            hm[s[r]]++;
            
            if(distinct<=k) {
                ans = max(ans, r-l+1);
            } else {
                while(l<=r and distinct>k) {
                    hm[s[l]]--;
                    if(hm[s[l]]==0) distinct--;
                    l++;
                }
            }
        }
        return ans;
    }
};