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
    
    TreeNode* findMin(TreeNode *root) {
        while(root and root->left!=NULL) {
            root = root->left;
        }
        return root;
    }
    TreeNode* findMax(TreeNode *root) {
        while(root and root->right!=NULL) {
            root = root->right;
        }
        return root;
    }
    
    
    int Height(TreeNode *root) {
        if(root==NULL) return 0;
        return 1+max(Height(root->left),Height(root->right));
    }
    
    TreeNode* deleteNode(TreeNode* &root, int key) {
        TreeNode *q;
        if(root==NULL) 
            return NULL;
        if(root->left==NULL and root->right==NULL and key == root->val) {
            root = NULL;
            return NULL;
        }
    
        if(root->val > key) deleteNode(root->left,key);
        else if(root->val < key) deleteNode(root->right,key);
        else {
            if(Height(root->left) > Height(root->right)) {
                q = findMax(root->left);
                root->val = q->val;
                root->left = deleteNode(root->left,q->val);
            } 
            else {
                q = findMin(root->right);
                root->val = q->val;
                root->right = deleteNode(root->right,q->val);
            }
        }
        return root;
    }
};