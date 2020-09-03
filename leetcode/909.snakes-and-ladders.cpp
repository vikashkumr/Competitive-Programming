/*
 * @lc app=leetcode id=909 lang=cpp
 *
 * [909] Snakes and Ladders
 */

// @lc code=start
class Solution {
public:
    int r,c,n;

   /* This requires knowing the coordinates get(s2) of square s2.
    This is a small puzzle in itself: we know that the row changes every N squares,
    and so is only based on quot = (currRow-1) / N; also the column is 
    only based on rem = (s2-1) % N and what row we are on (forwards or backwards.)*/

    void getCell(int sq) {
        int r_mirrored=(sq-1)/n;
        r=n-1-r_mirrored;
        c=(r_mirrored%2==0)?(sq-1)%n:(n-1-(sq-1)%n);
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size();
        int dest = n*n;
        queue<int> q;
        q.push(1);
        unordered_map<int,int> dist;
        dist[1] = 0;

        while(!q.empty()) {
            int curr = q.front(); q.pop();
            if(curr == dest) return dist[curr];
            
            for(int i=1;i<=6 and (curr+i)<=dest;i++) {
                int next = curr+i;
                getCell(curr+i); 
                if(board[r][c] > -1) {
                    next = board[r][c];
                } 
                
                if(dist.count(next)) continue;
                q.push(next);
                dist[next] = dist[curr] + 1;
                
            }
        }
        return -1;
    }
};
// @lc code=end

