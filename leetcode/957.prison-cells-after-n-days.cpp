/*
 * @lc app=leetcode id=957 lang=cpp
 *
 * [957] Prison Cells After N Days
 */

// @lc code=start
class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        unordered_set<string> st;
       
        bool ok = 0;
        for(int i=0;i<N;i++) {
             string s;
            vector<int> newState(8);
            newState[0] = newState[7];

            for(int j=1;j<7;j++) newState[j] = (cells[j-1]==cells[j+1]) ? 1:0;
            for(int j=0;j<8;j++) if(newState[j]==1) s+='1'; else s+='0';
            
            if(st.find(s)!=st.end()) {
                ok = 1;
                break;
            } else {
                st.insert(s);
                cells = newState;
            }
        }
        if(ok) {
             N = N%st.size();
            for(int i=0;i<N;i++) {
                vector<int> newState(8);
                for(int j=1;j<7;j++) {
                    newState[j] = (cells[j-1]==cells[j+1]) ? 1:0;
                }
                cells = newState;
            }   
        }
        return cells;
        
    }
};
// @lc code=end

