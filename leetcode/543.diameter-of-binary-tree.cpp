/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
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


//I am calculating height here at the same time diameter is also calculating

class Solution {
public:
    int dimeter;
    int diameter(TreeNode *root) {
        if(root == NULL) return 0;
        if(root->left==NULL and root->right==NULL) return 1;
        int lh = diameter(root->left);
        int rh = diameter(root->right);
        dimeter = max(1 + lh + rh, dimeter);
        return 1 + max(lh, rh);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        if(root->left==NULL and root->right==NULL) return 0;
        diameter(root);
        return dimeter-1;
    }
};
// @lc code=end

