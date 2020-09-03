/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 */

// @lc code=start
class Solution {
public:
    string intToRoman(int num) {
        map<int,string> mp;
        mp[1] = "I";
        mp[4] = "IV";
        mp[5] = "V";
        mp[9] = "IX";
        mp[10] = "X";
        mp[40] = "XL";
        mp[50] = "L";
        mp[90] = "XC";
        mp[100] = "C";
        mp[400] = "CD";
        mp[500] = "D";
        mp[900] = "CM";
        mp[1000] = "M";

        string res = "";
        while(num > 0) {
            if(num > 1000) {
                num-=1000;
                res+='M';
            } else if(mp.count(num) > 0) {
                res+=mp[num];
                return res;
            } else {
                int tmp;
                for(auto it: mp) {
                    if(it.first < num) {
                        tmp = it.first;
                    } else break;
                }
                res+=mp[tmp];
                num-=tmp;
            }
        }
        
        return res;
    }
};
// @lc code=end

