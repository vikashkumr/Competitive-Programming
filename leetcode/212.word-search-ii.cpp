/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 */

// @lc code=start
/*Approach====
optimise as for each word we are iterating through whole board
this can be optimised by storing the pos for starting character of each word
and only move to that cell having start point as current char
Time Complexity: O(nm*nm*words) worst case is when all word start with same char and complete board has filled with that char only
============
This problem can be solved using Trie Data structure as well 
Time Complexity: O(nm*nm)

*/
//===============using dfs + map =======================
class Solution {
public:
    int n,m;
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



    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        n = board.size();
        m = board[0].size();
        unordered_map<char,vector<pair<int,int>>> mp;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mp[board[i][j]].push_back({i,j});
            }
        }
        set<string> res;
        vector<string>ans;
        for(string word: words) {
            char ch = word[0];
            for(auto it: mp[ch]) {
                bool found = dfs(it.first,it.second,board,0,word);
                if(found) res.insert(word);
            }
        }
        for(auto it: res) ans.push_back(it);
        return ans;
    }
};

// ================== dfs + Trie ===================
// dfs is used here in other manner(yet to do)

// @lc code=end

