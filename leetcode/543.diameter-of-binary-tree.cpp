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
    int res;
    
    int findD(TreeNode *root) {
        if(root==NULL) return 0;
        int l = findD(root->left);
        int r = findD(root->right);
        int h = 1 + max(l,r);
        res = max(res, 1+l+r);
        return h;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        findD(root);
        return res-1;
    }
};
// @lc code=end

