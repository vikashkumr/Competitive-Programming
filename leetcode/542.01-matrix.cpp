/* Approach:
    use bfs to update cells
    step1: insert all cell having val = 0 of matrix in to queue 
    step2: go upto that size pop if upcoming cell is not vis and val != 0 and update it's value by step
    step3: indert adjacent cell to queue
    step4: repeat step 2 and 3 and finally return matrix;

*/


class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if(matrix.empty()) return matrix;
        
        int dx[] = {0,0,-1,1};
        int dy[] = {-1,1,0,0};
        int row = matrix.size();
        int col = matrix[0].size();
        
        vector<vector<bool>> vis(row,vector<bool>(col,0));
        queue<pair<int,int>>q;
        for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++) {
                if(matrix[i][j] == 0) {
                    for(int k=0;k<4;k++) q.push({i+dx[k], j+dy[k]});
                }
            }
        }
        
        int steps = 0;
        while(!q.empty()) {
            steps++;
            int sz = q.size();
            for(int size = 0;size<sz;size++) {
                auto node = q.front();
                q.pop();
                int i = node.first;
                int j = node.second;
                if(i>=0 and i<row and j>=0 and j<col and !vis[i][j] and matrix[i][j]) {
                    matrix[i][j] = steps;
                    vis[i][j] = 1;
                    for(int k=0;k<4;k++) q.push({i+dx[k], j+dy[k]});
                }   
            }
        }
        return matrix;
    }
};