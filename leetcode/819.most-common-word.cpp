/*
 * @lc app=leetcode id=819 lang=cpp
 *
 * [819] Most Common Word
 */

// @lc code=start
class Solution {
public:
    string mostCommonWord(string p, vector<string>& banned) {
        transform(p.begin(), p.end(),p.begin(),::tolower);
        string tmp="";
        for(char ch: p) {
            if((ch>='a' and ch<='z')) {
                tmp += ch;
            } else if(ch==',' or ch==' ') {
                if(tmp.back()!=' ')
                tmp+=' ';
            }
        }
       // cout<<tmp;

        unordered_map<string, int> hm;
        stringstream check1(tmp);
        string token;
        while(getline(check1,token,' ')) {
            hm[token]++;
        }
        for(string s: banned) {
            hm.erase(s);
        }
        string res = "";
        int deside = -1;
        for(auto it: hm) {
            if(it.second > deside) {
                res = it.first;
                deside = it.second;
            }
        }
        return res;
    }
};
// @lc code=end

