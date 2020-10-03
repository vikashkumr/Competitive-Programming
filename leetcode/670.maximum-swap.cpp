/*
 * @lc app=leetcode id=670 lang=cpp
 *
 * [670] Maximum Swap
 */

// @lc code=start

//if sorted in descending order done simply return 
//else simulate corresponding to sorted order and wherever violet shift to correct position and break

class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        string tmp = str;
        sort(tmp.rbegin(), tmp.rend());
        int i = 0, idx = 0;
        for(int j=0;j<tmp.length();j++) {
            char ch = tmp[j];
            if(str[i] == ch) {
                i++;
            } else {
                ch = str[i];
                str[i] = tmp[j];
                for(int k=i+1;k<tmp.length();k++) {
                    //let this index update till last and swap with that so we can get max number don't break in between
                    //1993 eg
                    if(str[k] == tmp[j]) {
                        idx = k;
                    }
                }
                str[idx] = ch;
                break;
            }
        }
        return stoi(str);
    }
};
// @lc code=end

