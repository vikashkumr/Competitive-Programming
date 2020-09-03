/*
 * @lc app=leetcode id=1123 lang=cpp
 *
 * [1123] Lowest Common Ancestor of Deepest Leaves
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
    TreeNode *root1 =NULL, *root2 = NULL;
    int Height(TreeNode *root, int d) {
        if(root == NULL) return 0;
        return 1 + max(Height(root->left, d+1),Height(root->right, d+1));
    }
    
    
    void dfs(TreeNode *root, int d, int h) {
        if(root) {
            if(d==h) {
                if(root1 == NULL) root1 = root;
                else root2 = root;
            }
            dfs(root->left, d+1, h);
            dfs(root->right, d+1, h);
        }
    }
    
    
    TreeNode* LCA(TreeNode *root, TreeNode *p, TreeNode *q) {
        
        if(root == NULL) return NULL;
        if(root == p or root == q) return root;
        TreeNode *l = LCA(root->left,p,q);
        TreeNode *r = LCA(root->right,p,q);
        if(l and r) return root;
        return (l != NULL) ? l : r;
    }
    
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int h = Height(root,0);
        // cout<<h;
        h--;
        dfs(root,0, h);
        
        return LCA(root, root1, root2);
    }
};
// @lc code=end

