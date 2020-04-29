//https://leetcode.com/problems/asteroid-collision/
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        vector<int>v;
        int sz = asteroids.size();
        for(int i = 0; i < sz; ++i) {
            if(st.empty() || asteroids[i]>0) {
                st.push(asteroids[i]);
            } 
            else {
                //astroid[i]<0
                bool flag = 0;
                while(!st.empty() && st.top()>0) {
                    if(abs(asteroids[i])==st.top()) {
                    st.pop();
                        flag = 1; break;   
                    }
                    else if(abs(asteroids[i])>st.top()) {
                        st.pop();
                    } else break;        
                }
                if(flag) continue;
                if(st.empty() || st.top()<0) st.push(asteroids[i]);
            }
        }
        while(!st.empty()) {
            v.push_back(st.top());
            st.pop();
        }
        reverse(v.begin(),v.end());
        return v;  
    }
};