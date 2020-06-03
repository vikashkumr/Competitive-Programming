/*
 * @lc app=leetcode id=684 lang=cpp
 *
 * [684] Redundant Connection
 */

// @lc code=start
class Solution {
public:
    vector<int>parent, rank;
    int totalComponents;
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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        dsu(edges.size());
        for(int i=0;i<edges.size();i++) {
            if(find(edges[i][0]-1)==find(edges[i][1]-1)) {
                return {edges[i][0],edges[i][1]};
            } else {
                union_set(edges[i][0]-1,edges[i][1]-1);
            }
        }
        return {};
    }
};
// @lc code=end

