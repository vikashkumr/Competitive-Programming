#include<bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};
class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }
void topView(Node * root) {
        if(root == NULL)
        return;
        int curr_left = 0, curr_rt = 0;
        int hd = 0;
        map<int,Node*> mp; // horizontal dist, nnode*
        queue<pair<Node*, int>> q; // node*, horizontal dist
        q.push({root,hd});
        mp[0] = root;
        
        while(!q.empty()) {
            auto n = q.front(); q.pop();
            if(n.first->left) q.push({n.first->left,n.second-1});
            if(n.first->right) q.push({n.first->right,n.second+1});
            if(n.second<curr_left) mp[n.second] = n.first, curr_left--;
            if(n.second>curr_rt) mp[n.second] = n.first, curr_rt++;
        }
        for(auto it: mp) cout<<it.second->data<<" ";
    }
};
int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    cin >> t;

    while(t-- > 0) {
        cin >> data;
        root = myTree.insert(root, data);
    }
  
	myTree.topView(root);
    return 0;
}