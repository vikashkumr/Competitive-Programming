/*
 * @lc app=leetcode id=264 lang=cpp
 *
 * [264] Ugly Number II
 */

// @lc code=start
class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long>st;
        st.insert(1);
        long long cnt = 1;
        while(st.size()<=n) {
            auto it = st.begin();
            if(cnt==n) return *it;
            
            if(st.find(2*(*it))==st.end()) st.insert(2*(*it));
            if(st.find(3*(*it))==st.end()) st.insert(3*(*it));
            if(st.find(5*(*it))==st.end()) st.insert(5*(*it));
            cnt++;
            st.erase(it);
        }
        while(cnt!=n) {
            auto it = st.begin();
            st.erase(it);
            cnt++;
        }
        auto it = st.begin();
        return *it;
    }
};
// @lc code=end

