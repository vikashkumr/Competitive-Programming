/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    TreeNode* buildTree(int inStart, int inEnd, vector<int>& preorder, vector<int>& inorder) {
        if(inStart > inEnd) return NULL;

        static int preIdx;
        int val = preorder[preIdx++];
        TreeNode *root = new TreeNode(val);

        for(int i=inStart; i<=inEnd;i++) {
            if(inorder[i] == val) {
                root->left = buildTree(inStart,i-1,preorder,inorder);
                root->right = buildTree(i+1,inEnd,preorder,inorder);
                break;
            }
        }

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(0,inorder.size()-1, preorder, inorder);
    }
};
// @lc code=end

