/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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

//little modification to left view
//remove condition in left view last node appear at any vertical height will be our answer
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
       if(root == NULL) return {};
       int vh=0;
       queue<pair<TreeNode *,int> >q;
       q.push({root,vh});
       map<int,int> mp;
       while(!q.empty()){
           auto node = q.front(); q.pop();
           mp[node.second] = node.first->val;
           if(node.first->left){
               q.push({node.first->left,node.second+1});
           }
           if(node.first->right){
               q.push({node.first->right,node.second+1});
           }
       }
        
       vector<int>  res;
       for(auto it: mp) res.emplace_back(it.second);
       return res;
    }
};
// @lc code=end

