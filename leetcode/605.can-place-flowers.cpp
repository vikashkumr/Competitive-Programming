/*
 * @lc app=leetcode id=605 lang=cpp
 *
 * [605] Can Place Flowers
 */

// @lc code=start
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n<=0) return true;
        if(flowerbed.size() == 1 and flowerbed[0]==1) return false;
        if(flowerbed.size() == 1 and flowerbed[0]==0) return true;
        int x = n;
        if(flowerbed[0] == 0 and flowerbed[1] == 0) flowerbed[0] = 1, x--;
        for(int i=1;i<flowerbed.size()-1;i++) {
            if(flowerbed[i] == 0 and flowerbed[i-1] == 0 and flowerbed[i+1]==0) {
                x--;
                flowerbed[i] = 1;
            }      
        }
        if(flowerbed[flowerbed.size()-1]==0 and flowerbed[flowerbed.size()-2]==0) x--;
        if(x<=0) return true;
        return false;
    }
};
// @lc code=end

