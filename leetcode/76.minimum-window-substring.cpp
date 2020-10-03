/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
//sliding window

class Solution {
public:

    string minWindow(string s, string t) {

        int n = s.length();
        int m = t.length();

        int hm[128]={0}, hm1[128]={0};
        for(char ch: t) hm[ch]++;
    
        int ws = n, st = 0, end = 0, cnt = 0;

        string res = "";

        while(end<n) {
            char ch = s[end];
            hm1[ch]++;
            if(hm[ch] > 0 and hm1[ch] <= hm[ch]) cnt++;

            //when all character found in current window
            if(cnt == m) {
                while(1) {
                    char b = s[st];
                    if(hm1[b] > hm[b]) hm1[b]--, st++;
                    else break;
                }
                int len = end-st;
                if(len < ws) {
                    ws = len;
                    res = s.substr(st, len+1);
                }
            }
            end++;
        }
        return res;
    }
};
// @lc code=end

