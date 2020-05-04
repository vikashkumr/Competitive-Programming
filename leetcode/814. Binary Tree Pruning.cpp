//https://leetcode.com/problems/binary-tree-pruning/

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
    bool postorder(TreeNode *root) {
        if(root) {
            bool x = postorder(root->left);
            bool y = postorder(root->right);
            if(x==0 and y==0) {
                root->left=NULL;root->right=NULL;
                return root->val;
            } else if(x!=0 and y!=0) {
                return 1;
            }
            else if(x==0) {root->left = NULL; return 1;}
            if(y==0) {root->right = NULL; return 1;}  
        }
        return 0;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        int b = postorder(root);
        if(b==0) return NULL;
        return root;
    }
};