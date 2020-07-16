/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
    bool checkMirror(TreeNode *p, TreeNode *q) {
        if(p == NULL and q == NULL) return true;
        if(p == NULL or q == NULL) return false;
        if(p->val != q->val) return false;

        //important instead of swapping node we can simpy pass different pointer
        bool l = checkMirror(p->left, q->right);
        bool r = checkMirror(p->right, q->left);
        return l&r;
    }

    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return checkMirror(root->left, root->right);
    }
};
// @lc code=end

