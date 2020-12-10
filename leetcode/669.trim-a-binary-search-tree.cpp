/*
 * @lc app=leetcode id=669 lang=cpp
 *
 * [669] Trim a Binary Search Tree
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
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root==NULL) return root;
        if(root->val>=low && root->val<=high) {
             root->left = trimBST(root->left, low, high);
             root->right = trimBST(root->right, low, high);
            return root;
        }
        if(root->val < low) return trimBST(root->right, low, high);
        return trimBST(root->left, low, high);    
    }
};
// @lc code=end

