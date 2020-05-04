//https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

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

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL) return {};
        deque<TreeNode*>dq;
        vector<vector<int>>v;
        vector<int> temp;
        bool l = true;
        dq.push_back(root);
        while(!dq.empty()) {
            temp.clear();
            int len = dq.size();
            while(len--) {
                temp.push_back(dq.front()->val); 
                if(dq.front()->left) {
                    dq.push_back(dq.front()->left);
                }
                if(dq.front()->right) {
                    dq.push_back(dq.front()->right);
                }
                dq.pop_front();
            }
            if(l==1){
                v.push_back(temp);
                l=0;
            } else {
                reverse(temp.begin(),temp.end());
                v.push_back(temp);
                l=1;
            }
        }
        return v;
    }
};