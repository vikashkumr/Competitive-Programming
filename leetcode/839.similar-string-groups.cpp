// @lc code=start
/*
 * @lc app=leetcode id=839 lang=cpp
 *
 * [839] Similar String Groups
 */

// @lc code=start
class Solution {
public:
    vector<int> parent;
    bool partner(string &a, string &b) {
        int cnt =  0;
        for(int i=0;i<a.length();i++) {
            if(a[i]!=b[i]) cnt++;
            if(cnt>2) return false;       
        }
        return true;
    }
    
    int root(int idx) {
        if(parent[idx]==idx) return idx;
        return parent[idx] = root(parent[idx]);
    }

    void merge(int i, int j) {
        parent[root(i)] = root(j);
    }
    
    int numSimilarGroups(vector<string>& A) {
        int n = A.size();
        parent.resize(n);
       
        for(int i=0;i<n;i++) parent[i] = i;
        int cnt = n;
        for(int i=1;i<n;i++) {
            for(int j=i-1;j>=0;j--) {
                if(root(i) != root(j) && partner(A[i], A[j])) {
                    merge(i,j);
                    cnt--;
                }
            }
        }
        
        return cnt;
    }
};
// @lc code=end


// @lc code=end

