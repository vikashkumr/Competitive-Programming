/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
//simpe dfs + backtracking

class Solution {
public:
    int n, m;

    bool dfs(int row, int col, vector<vector<char>>& board, int pos, string &word) {
        if(pos == word.length()) return true;
        if(row<0 or row>=n or col<0 or col>=m or board[row][col] != word[pos]) return false;
        char ch = board[row][col];
        board[row][col] = '*';
        //consider all dfs call here to reduce tle if first condition will true control won't go to next dfs call
        bool found = dfs(row-1,col,board,pos+1,word) || dfs(row+1,col,board,pos+1,word) || dfs(row,col-1,board,pos+1,word) ||  dfs(row,col+1,board,pos+1,word);
        board[row][col] = ch;
        
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(board[i][j] == word[0]) {
                    bool found = dfs(i,j,board,0,word);
                    if(found) return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end

