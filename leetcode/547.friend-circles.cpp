/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Friend Circles
 */

// @lc code=start

class Solution {
    vector<int>parent, rank;
    int totalComponents;
public:
    void dsu(int n) {
        parent.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++) {
            parent[i] = i;
            rank[i] = 0;
        }
        totalComponents = n;
    }

    int find(int x) {
        if(x == parent[x]) return x;
        return parent[x] = find(parent[x]); //path compression 
    }

    void union_set(int a, int b) {
        a = find(a);
        b = find(b);
        if(a != b) {
            if(rank[a] < rank[b])
                swap(a,b);
            parent[b] = a;
            if(rank[a] == rank[b]) 
                rank[a]++;
            totalComponents--;
        }
    }
    int findCircleNum(vector<vector<int>>& M) {
        dsu(M.size());
        int n = M.size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(M[i][j]) {
                    union_set(i,j);
                }
            }
        }
        int ans = 0;
        set<int> st;
        for(int i=0;i<n;i++) {
            st.insert(find(i));
        }
        return st.size();
    }
};
// @lc code=end

