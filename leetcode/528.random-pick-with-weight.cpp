/*
 * @lc app=leetcode id=528 lang=cpp
 *
 * [528] Random Pick with Weight
 */

// @lc code=start
//Approach: think in a way suppose 1,3 is given, we can consider 1 ones and 2 three times and take modulo % 4 
// so probability of occurance of 3 would be 3/4 and for 1 => 1/4
class Solution {
public:
    vector<pair<int,int>> v;
    int end;
    int sum = 0;
    Solution(vector<int>& w) {
        end = 0;
        for(int i=0;i<w.size();i++) {
            v.push_back({end+1,end+w[i]});
            sum+=w[i];
            end = end+w[i];
        }
    }
    
    int pickIndex() {
        int r = rand()%sum+1;
        for(int i=0;i<v.size();i++) {
            if(r>=v[i].first and r<=v[i].second)
            return i;
        }
        return -1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
// @lc code=end

