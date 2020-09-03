/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 */

// @lc code=start
class Solution {
public:
    int MAH(vector<int>&v, vector<int>&nsl, vector<int>&nsr) {
        int ans = 0;
        int n = v.size();
        for(int i=0;i<n;i++) {
            int width = nsr[i]-nsl[i]-1;
            ans = max(ans, width*v[i]);
            // cout<<"ans"<<ans<<" ";
        }
        return ans;
    }

    void NSR(vector<int>&nsr, vector<int>&v) {
        stack<int> stk;
        int n = v.size();
        for(int i=n-1;i>=0;i--) {
            while(!stk.empty() and v[stk.top()] >= v[i]) {
                stk.pop();
            }
            if(stk.empty()) {
                nsr.push_back(n);
            } else {
                nsr.push_back(stk.top());
            }
            stk.push(i);
        }
        reverse(nsr.begin(), nsr.end());
    }
    
    void NSL(vector<int>&nsl, vector<int>&v) {
        stack<int> stk;
        int n = v.size();
        for(int i=0;i<n;i++) {
            while(!stk.empty() and v[stk.top()] >= v[i]) {
                stk.pop();
            }
            if(stk.empty()) {
                nsl.push_back(-1);
            } else {
                nsl.push_back(stk.top());
            }
            stk.push(i);
        }
    }


    int maximalRectangle(vector<vector<char>>& mat) {
        vector<int> v,nsl,nsr;
        int n = mat.size();
        if(n==0) return 0;
        int m = mat[0].size();
        v.resize(m);
        int ans = 0;
        for(int i=0;i<n;i++) {
            nsl.clear();
            nsr.clear();
            for(int j=0;j<m;j++) {
                if(mat[i][j]=='0') v[j] = 0;
                else v[j]+=1;
            }
            NSL(nsl,v);
            NSR(nsr,v);
            ans = max(ans, MAH(v, nsl, nsr));
        }
        return ans;
    }
};
// @lc code=end

