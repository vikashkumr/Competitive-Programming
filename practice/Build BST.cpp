//build BST using sorted array and print preorder traversal

#include<bits/stdc++.h>
using namespace std;
int n;
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

int main() {
    int t;
    cin>>t;
    while(t--) {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];  
        Node *root = buildBST(arr,0,n-1);
        preorder(root);
		cout<<endl;
    }
    return 0;
}