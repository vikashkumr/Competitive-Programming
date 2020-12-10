/*
 * @lc app=leetcode id=572 lang=cpp
 *
 * [572] Subtree of Another Tree
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

    bool check(TreeNode *root1, TreeNode *root2) {
        if(root1 == NULL and root2 == NULL) return true;
        if(root1==NULL or root2==NULL) return false;
        if(root1->val != root2->val) return false;
        return check(root1->left, root2->left) && check(root1->right, root2->right);  
    }

    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s==NULL and t!=NULL) return false;
        if(check(s,t)) return true;
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};
// @lc code=end

