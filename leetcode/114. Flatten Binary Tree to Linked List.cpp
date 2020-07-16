//https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void flatten(TreeNode* root) {
        if(root==NULL || (root->left==NULL and root->right==NULL)) return;
        if(root->left) flatten(root->left);
        
        TreeNode *t = root->right;
        root->right = root->left;
        root->left = NULL;
        
        while(root->right != NULL) root = root->right;
        root->right = t;
        flatten(root->right);
    }
};