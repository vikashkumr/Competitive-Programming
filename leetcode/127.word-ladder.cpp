/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 */

// @lc code=start
class Solution {
public: 
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>uset(wordList.begin(), wordList.end()); //unvisited set
        queue<string> q;
        q.push(beginWord);
        int level = 0;
        int level_node = q.size();
        while(!q.empty()) {
            string node = q.front();
            q.pop();
            if(node==endWord) return level + 1;

            // try reaching another word by replacing characters in different positions
            for(int i=0;i<node.length();i++) {
                char curr_ch = node[i];
                // replace with a-z char
                for(char ch = 'a';ch<='z';ch++) {

                    // replace the char and check if that word is connected to the
                    // current word via a transformation(edge)
                    node[i] = ch;

                    // add the word to queue if it has not been visited and is part of dict
                    if(uset.find(node) !=uset.end()) {
                        q.push(node);
                        uset.erase(node);
                    }
                }
                node[i] = curr_ch;
            }
            level_node--;
            // end of nodes in current level
            if(level_node==0) {
                level++;
                level_node = q.size();
            }
        }
        return 0;
    }
};
// @lc code=end

