/*
 * @lc app=leetcode id=947 lang=cpp
 *
 * [947] Most Stones Removed with Same Row or Column
 */

// @lc code=start
class Solution {
public:
    vector<int>parent, rank;
    void dsu(int n) {
        parent.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++) {
            parent[i] = i;
            rank[i] = 0;
        }
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
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        dsu(10000);
        int n = stones.size();
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                if(stones[i][0]==stones[j][0] or stones[i][1]==stones[j][1]) {
                    union_set(i,j);
                }
            }
        }
        int res = 0;
        for(int i=0;i<n;i++) {
            if(find(i)==i) res++;
        }
        return n-res;
    }
};
// @lc code=end

