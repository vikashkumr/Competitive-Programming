/*
 * @lc app=leetcode id=938 lang=cpp
 *
 * [938] Range Sum of BST
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
    int ans;
    void dfs(TreeNode *root, int l, int r) {
        if(root) {
            if(root->val>=l and root->val<=r) ans+=root->val;
            dfs(root->left,l,r);
            dfs(root->right,l,r);
        }
    }
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(root==NULL) return 0;
        ans = 0;
        dfs(root,L,R);
        return ans;
    }
};
// @lc code=end

