/*
 * @lc app=leetcode id=1296 lang=cpp
 *
 * [1296] Divide Array in Sets of K Consecutive Numbers
 */

// @lc code=start
class Solution {
public:
    bool isPossibleDivide(vector<int>& hand, int w) {
        if(hand.size()%w!=0 && (hand.size()/w) != w) {
            return false;
        }
        
        map<int,int> mp;
        for(int x: hand) {
            mp[x]++;
        }
        
        while(!mp.empty()) {
            int curr = mp.begin()->first;
            for(int i=1;i<=w;i++) {
                if(mp[curr]==0) return false;
                else {
                    mp[curr]--;
                    if(mp[curr] == 0) mp.erase(curr);
                    curr++;
                }
            }
        }
        return true;  
    }
};
// @lc code=end

