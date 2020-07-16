/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
/*
    What does postorder traversal give us?
    First, the last value has to be root. Then, we know if there exists right subtree of root, then again, last value in order, must be the root of the right subtree. RIGHT because in postorder traversal we print left, root, right.
    Now, so far we understand that last unseen value in postorder must be a root of something. Let's call last unseen value in postorder rightP.

    What does inorder traversal give us?
    If you take some index pos, everything to the left to pos - 1 in its left subtree, pos + 1 right is in its right subtree at the root level where left is 0 and right is last index in inorder.
    Cool. Let's start by creating root. Then, we take that value at rightP and find its position(pos) in inorder. If there is something to the right of pos, it means it has a right subtree. If the range left,
    sright isn't empty, then we have some values essentially. We keep adjusting the range of values in left and right subtrees. If we step in recursive call and pass exiting condition, then we have a range of values for this subtree and it is rooted at postorder[rightP].
    Essentially, we keep shrinking the window of the values in each subtree.
*/

class Solution {
public:
    int rightP;
    TreeNode* buildTree(int st, int end, vector<int>& inorder, vector<int>& postorder, unordered_map<int,int> &hm){

        if(st > end) return NULL;

        // if there are some values, then root is just last one in postorder
        int rootVal = postorder[rightP--];
        int mxIdx = hm[rootVal];

        TreeNode *root = new TreeNode(rootVal);

        // assign left and right. order matter right then left
        root->right = buildTree(mxIdx+1, end, inorder, postorder, hm);
        root->left = buildTree(st, mxIdx-1, inorder, postorder, hm);
        return root;
    }



    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> hm;//store index of postorder elements

        for(int i=0;i<inorder.size();i++) {
            hm[inorder[i]] = i;       
        }
        rightP = inorder.size()-1;
        return buildTree(0,postorder.size()-1,inorder,postorder,hm);  
    }
};
// @lc code=end

