//build BST using sorted array and print preorder traversal

#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    Node *left,*right;
    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

void preorder(Node* root) {
    if(root) {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

Node* buildBST(int *arr, int i, int j) {
    int mid = (i+j)/2;
    if(mid>=i and mid<=j) {
        Node *t = new Node(arr[mid]);
        t->left = buildBST(arr,i,mid-1);
        t->right = buildBST(arr,mid+1,j);
        return t;
    }
	return NULL;
}
Node* findMin(Node *root) {
    while(root and root->left!=NULL) {
        root = root->left;
    }
    return root;
}

Node* deleteNode(Node* &root, int key) {
    Node *q;
    if(root==NULL) 
        return NULL;
    if(root->left==NULL and root->right==NULL and key == root->data) {
        root = NULL;
        return NULL;
    }

    if(root->data > key) deleteNode(root->left,key);
    else if(root->data < key) deleteNode(root->right,key);
    else {
        q = findMin(root->right);
        root->data = q->data;
        root->right = deleteNode(root->right,q->data);
    }
    return root;
}


int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,m;
        cin>>n>>m;
        int arr1[n], arr2[m];
        for(int i=0;i<n;i++) cin>>arr1[i]; 
        for(int i=0;i<m;i++) cin>>arr2[i]; 
         sort(arr1,arr1+n);  
        Node *root = buildBST(arr1,0,n-1);
        Node *t = root;
        for(int i=0;i<m;i++) {
            t = deleteNode(t,arr2[i]);
        }
        preorder(t);
		cout<<endl;
    }
    return 0;
}