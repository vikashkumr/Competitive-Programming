/*
 * @lc app=leetcode id=701 lang=cpp
 *
 * [701] Insert into a Binary Search Tree
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
    
    void insert(TreeNode *root, int val) {
        
        if(root->val > val && root->left==NULL) {
            TreeNode* n = new TreeNode(val);
            root->left = n;
            return;
        }
        if(root->val < val && root->right==NULL) {
            TreeNode* n = new TreeNode(val);
            root->right = n;
            return;
        }
        
        if(val < root->val) return insert(root->left, val);
        if(val > root->val) return insert(root->right, val);
    }
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL)
        return root = new TreeNode(val);
        insert(root, val);
        return root;
    }
};
// @lc code=end

