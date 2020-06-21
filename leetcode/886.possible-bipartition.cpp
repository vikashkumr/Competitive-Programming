/*
 * @lc app=leetcode id=886 lang=cpp
 *
 * [886] Possible Bipartition
 */

// @lc code=start
class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        
        // Check for bipartite graph can be done using 2-color graph coloring.
        // Idea is to use two colors and assign colors to each node such that
        // each adjacent node gets a different color, if we this assignment is not
        // possible, then it is not bipartite

        vector<int> g[N];
        for(auto edge: dislikes) {
            g[edge[0]-1].push_back(edge[1]-1);
            g[edge[1]-1].push_back(edge[0]-1);
        }
        
        // for keeping track of color of each node
        // -1: unvisited
        // 0: color 1
        // 1: color 2

        vector<int> color(N, -1);

        // in case of disconnected graph
        for(int i=0;i<N;i++) {
            if(color[i]==-1) {
                color[i] = 1;
                queue<int>q;
                q.push(i);
                while(!q.empty()) {
                    int curr = q.front();
                    q.pop();

                    // color the adjacent nodes
                    for(int child: g[curr]) {
                        if(color[child] == -1) {

                            // color it to mark visited
                            color[child] = 1-color[curr];
                            q.push(child);
                        } else if(color[child]==color[curr]) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;  
    }
};
// @lc code=end

