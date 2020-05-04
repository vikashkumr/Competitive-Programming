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
        if(root==NULL || root->left==NULL && root->right==NULL) {
        	return;
        }
        
        if(root->left != NULL) {
        	flatten(root->left);
            
            TreeNode* r_temp = root->right;
            root->right = root->left;
            root->left = NULL;
            TreeNode* temp = root->right;
            while(temp->right != NULL){
            	temp = temp->right;
            }
            temp->right = r_temp;
        }
      flatten(root->right);
    }
};