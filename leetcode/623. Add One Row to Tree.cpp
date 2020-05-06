
//https://leetcode.com/problems/add-one-row-to-tree/

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
    void dfs(TreeNode *root,int v,int d,int h) {
      if(root) {
        if(h==d-1) {
            if(root) {
            TreeNode *t1 = new TreeNode(v);
            t1->left = root->left;
            root->left =  t1;
                TreeNode *t2 = new TreeNode(v);
            t2->right = root->right;
            root->right =  t2;
            }
            return;
        }
        dfs(root->left,v,d,h+1);
        dfs(root->right,v,d,h+1);
      }
    }
    
    
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d==1) {
            TreeNode *t1 = new TreeNode(v);
            t1->left = root;
            root = t1;
            return root;
        }
        dfs(root,v,d,1);
        return root;
    }
};