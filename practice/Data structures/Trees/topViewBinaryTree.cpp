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
        queue<pair<Node *,int> >q;
        int hd=0;
        map<int,int>m;
        q.push(make_pair(root,hd));
        m[hd]=root->data;
        while(!q.empty()){
            pair<Node *,int> curr;
            curr=q.front();
            hd=curr.second;
            q.pop();
            if(curr.first->left){
                q.push(make_pair(curr.first->left,hd-1));
                if(!m[hd-1])
                  m[hd-1] = curr.first->left->data;
            }
            if(curr.first->right){
                q.push(make_pair(curr.first->right,hd+1));
                if (!m[hd+1])
                  m[hd+1] = curr.first->right->data;
            }
        }
        for(map<int,int>::iterator it=m.begin();it!=m.end();it++)
        cout<<it->second<<" ";

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