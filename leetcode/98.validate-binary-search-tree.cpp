/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//limit the range at each node

class Solution {
public:
    bool testBST(TreeNode *root, long long l_limit, long long r_limit) {
       if(root==NULL) return true;
       if(root->val <= l_limit || root->val >= r_limit) return false;
       return testBST(root->left,l_limit,root->val) && testBST(root->right,root->val,r_limit); 
    }
    
    
    bool isValidBST(TreeNode* root) {
        long long r = 1e15;
        long long l = -1*r;
        return testBST(root, l, r);
    }
};
// @lc code=end

