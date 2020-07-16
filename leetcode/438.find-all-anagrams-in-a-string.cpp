/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */

// @lc code=start

// sliding window


class Solution {
public:
    
    bool check(int *parr, vector<int> &out) {
        for(int i=0;i<26;i++) {
            if(parr[i]!=out[i]) return false;
        }
        return true;
    }
    
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if(p.length()==0 || s.length()==0 || p.length() > s.length()) return ans;
        
        int parr[26] = {0};
        for(char ch: p) {
            parr[ch-'a']++;
        }
        
        vector<int> out(26,0);
        int plen = p.length();
        for(int i=0;i<plen;i++) {
            out[s[i]-'a']++;
        }
        
        bool ok = check(parr,out);
       
        if(ok) ans.push_back(0);
        int l = 1, r = plen; 
        while(r<s.length()) {
            out[s[l-1]-'a']--;out[s[r]-'a']++;
            bool ok = check(parr,out);
            if(ok) {
                ans.push_back(l);
            }
            l++;r++;
        }
        return ans;
    }
};
// @lc code=end

