//https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

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
    map<int,vector<int> >mp;
    queue<pair<TreeNode*,int>> que;
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root==NULL) return {};
        que.push({root,0});
        while(!que.empty()) {
            set<pair<int,int>> st;
            int len=que.size();
            while(len--) {
                auto it = que.front();que.pop();
                st.insert(make_pair(it.first->val,it.second ));
                if(it.first->left) que.push({it.first->left,it.second-1});
                if(it.first->right) que.push({it.first->right,it.second+1});
            }
            
            for(auto p : st) mp[p.second].push_back(p.first);
            
        }
        vector<vector<int>> v(mp.size());
        int i = 0;
        for(auto it : mp) {
            v[i++] = it.second;
        }
        return v;
    }
};