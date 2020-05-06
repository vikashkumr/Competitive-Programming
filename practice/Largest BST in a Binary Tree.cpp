//find largest BST in BT formed by preorder and inorder traversal array
#include<bits/stdc++.h>
using namespace std;
int ans = INT_MAX;

class Node {
    public:
    int data;
    Node *left,*right;
    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

int search(int arr[], int strt, int end, int value)  
{  
    int i;  
    for (i = strt; i <= end; i++)  
    {  
        if (arr[i] == value)  
            return i;  
    }  
}

Node* buildTree(int in[], int pre[], int inStrt, int inEnd)  
{  
    static int preIndex = 0;  
  
    if (inStrt > inEnd)  
        return NULL;  
    Node* tNode = new Node(pre[preIndex++]);  

    if (inStrt == inEnd)  
        return tNode;  
    int inIndex = search(in, inStrt, inEnd, tNode->data);  
    tNode->left = buildTree(in, pre, inStrt, inIndex - 1);  
    tNode->right = buildTree(in, pre, inIndex + 1, inEnd);  
    return tNode;  
}  


struct Data 
{ 
    int sz; 
    int max;  
    int min;  
    int ans; 
    bool isBST;
}; 
  
Data largestBSTBT(Node* root) 
{  
    if (root == NULL) 
        return {0, INT_MIN, INT_MAX, 0, true}; 
    if (root->left == NULL && root->right == NULL) 
        return {1, root->data, root->data, 1, true};  
    Data l = largestBSTBT(root->left); 
    Data r = largestBSTBT(root->right); 
    Data ret; 
    ret.sz = (1 + l.sz + r.sz); 
    if (l.isBST && r.isBST && l.max < root->data && 
            r.min > root->data) 
    { 
        ret.min = min(l.min, min(r.min, root->data)); 
        ret.max = max(r.max, max(l.max, root->data)); 
        ret.ans = ret.sz; 
        ret.isBST = true; 
  
        return ret; 
    } 
    ret.ans = max(l.ans, r.ans); 
    ret.isBST = false; 
  
    return ret; 
}

int main() {
    int n;
    cin>>n;
    int pre[n], in[n];
    for(int i=0;i<n;i++) cin>>pre[i];  
    for(int i=0;i<n;i++) cin>>in[i];  
    Node *root = buildTree(in,pre,0,n-1);
    cout<<largestBSTBT(root).ans;
    cout<<ans;
    return 0;
}