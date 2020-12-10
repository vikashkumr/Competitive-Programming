/*
 * @lc app=leetcode id=421 lang=cpp
 *
 * [421] Maximum XOR of Two Numbers in an Array
 */

// @lc code=start


class Solution {
    class TrieNode {
        public:
            TrieNode *left;
            TrieNode *right;
    };
public:
    //simple insertion 1->right 0->left
    void insert(TrieNode *head, int val) {
        TrieNode *curr = head;
        for(int i=31;i>=0;i--) {
            int bit = (val>>i)&1;
            if(bit) {
                if(!curr->right) {
                    curr->right = new TrieNode();
                }
                curr = curr->right;
            } else {
                if(!curr->left) {
                    curr->left = new TrieNode();
                }
                curr = curr->left;
            }
        }
    }

    int find_xor(TrieNode *head, vector<int> &nums) {
        
        int max_xor = 0;
        for(int num: nums) {
            //try to maximize xor for each number if curr is 0 trie to move into right so val will be 1 and vice versa
            TrieNode *curr = head;
            int curr_xor = 0;
            for(int i=31;i>=0;i--) {
                int bit = (num>>i)&1;
                if(bit) {
                    //check for opposite bit so that xor could me maximised
                    if(curr->left) curr = curr->left, curr_xor += pow(2,i);
                    else curr = curr->right;
                } else {
                    if(curr->right) curr = curr->right, curr_xor += pow(2,i);
                    else curr = curr->left;
                }
            }
            max_xor = max(max_xor, curr_xor);
        }
        return max_xor;
    }


    int findMaximumXOR(vector<int>& nums) {
        TrieNode *head = new TrieNode();
        for(int num: nums) {
            insert(head, num);       
        }
        return find_xor(head, nums);
    }
};
// @lc code=end

