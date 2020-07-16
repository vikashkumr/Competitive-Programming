/*
 * @lc app=leetcode id=863 lang=cpp
 *
 * [863] All Nodes Distance K in Binary Tree
 */

// @lc code=start
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
    vector<int>ans;
    void printkdistanceNodeDown(TreeNode* root,int k) {
        if (root == NULL || k < 0)  return; 
        if (k==0) { 
            ans.push_back(root->val);
            return; 
        } 
        printkdistanceNodeDown(root->left, k-1); 
        printkdistanceNodeDown(root->right, k-1); 
    }
    
    int printkdistanceNode(TreeNode* root, TreeNode* target, int k) {
        if (root == NULL) return -1; 
        if (root == target) { 
            printkdistanceNodeDown(root, k); 
            return 0; 
        } 
  
        int dl = printkdistanceNode(root->left, target, k); 
        if (dl != -1) { 
            if (dl + 1 == k) 
                ans.push_back(root->val); 
            else
                printkdistanceNodeDown(root->right, k-dl-2); 
            return 1 + dl; 
        } 
    
        int dr = printkdistanceNode(root->right, target, k); 
        if (dr != -1) { 
            if (dr + 1 == k) 
                ans.push_back(root->val);
            else
                printkdistanceNodeDown(root->left, k-dr-2); 
            return 1 + dr; 
        } 
    
        return -1; 
    }
    

    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        printkdistanceNode(root,target,K);
        return ans;
    }
};
// @lc code=end

/*
Idea: make tree as undirected graph storing parent in hash map and use simple bfs
O(n) time and space 

class Solution {
public:
    vector<int>ans;
    
    void dfsInit(TreeNode* root,  unordered_map<TreeNode*,TreeNode*>& parent) {
        if(root) {
            if(root->left) parent[root->left] = root;
            if(root->right) parent[root->right] = root;
            dfsInit(root->left, parent);
            dfsInit(root->right, parent);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k==0) return {target->val};
        unordered_map<TreeNode*,TreeNode*> parent;
        unordered_map<int,bool> seen;
        
        //initialize parent
        
        dfsInit(root,parent);
        
        queue<TreeNode*> q;
        q.push(target);
        int level = 0;
        seen[target->val] = 1;
        while(!q.empty()) {
            level++;
            int t = q.size();
            while(t--) {
                TreeNode *node = q.front(); q.pop();
            if(node->left and seen[node->left->val]==0) {
                q.push(node->left);
                seen[node->left->val]=1;
                
                if(level==k) ans.emplace_back(node->left->val);
            }
            if(node->right and seen[node->right->val]==0) {
                q.push(node->right);
                seen[node->right->val]=1;
                
                if(level==k) ans.emplace_back(node->right->val);
            }
            if(parent[node]!=NULL and seen[parent[node]->val]==0) {
                 q.push(parent[node]);
                seen[parent[node]->val] = 1;
                
                if(level==k) ans.emplace_back(parent[node]->val);
            }   
            }
        }
        
        return ans;
    }
};
*/

