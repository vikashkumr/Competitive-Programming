/*
 * @lc app=leetcode id=671 lang=cpp
 *
 * [671] Second Minimum Node In a Binary Tree
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
    int findSecondMinimumValue(TreeNode* root) {
        if(root == NULL) return -1;
        queue<TreeNode*> q;
        q.push(root);
        int min1 = INT_MAX;
        int min2 = -1;
        while(!q.empty()) {
            auto node = q.front(); q.pop();
            min1 = min(node->val, min1);
            if(node->val > min1 and (node->val < min2 or min2==-1)) {
                min2 = node->val;
            }
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        return min2;
    }
};
// @lc code=end

