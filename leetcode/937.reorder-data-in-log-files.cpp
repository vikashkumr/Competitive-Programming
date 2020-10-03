/*
 * @lc app=leetcode id=937 lang=cpp
 *
 * [937] Reorder Data in Log Files
 */

// @lc code=start
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> ans;
        for(string &s: logs) {
            bool ok = 0;
            for(char ch: s) {
                if(ch==' ') ok=1;
                if(((ch<'0' or ch>'9') and ch!=' ') and ok) {
                    ans.push_back(s);
                    break;
                }
            }   
        }
        sort(ans.begin(),ans.end(), [&](string &a, string &b) -> bool {
            int pos1 = 0, pos2 = 0;
            while(pos1 < a.length() and a[pos1]!=' ') pos1++;
            while(pos2 < b.length() and b[pos2]!=' ') pos2++;
            
            if(pos1==a.length()) return a<b;
            else pos1++;
            if(pos2==b.length()) return a<b;
            else pos2++;
            
            if(a.substr(pos1)==b.substr(pos2)) return a<b;
            
            return a.substr(pos1) < b.substr(pos2);
        });
        
        for(string &s: logs) {
            bool ok = 0;
            for(char ch: s) {
                if(ch==' ') ok=1;
                if(ch>='0' and ch<='9' and ok) {
                    ans.push_back(s);
                    break;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

