//Given a binary search tree, replace each nodes' data with the sum of all nodes' which are greater or equal than it. Include the current node's data also.(little change in buildBST)

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



Node* buildTree(int *arr, int i, int j) {
    int mid = (i+j)/2;
    if(mid>=i and mid<=j) {

        //here
        int sum = 0;
        for(int i=0;i<n;i++) {
            if(arr[i]>=arr[mid]) sum+=arr[i];
        }
        //
        Node *t = new Node(sum);
        t->left = buildTree(arr,i,mid-1);
        t->right = buildTree(arr,mid+1,j);
        return t;
    }
	return NULL;
}

int main() {
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];  
    Node *root = buildTree(arr,0,n-1);
    preorder(root);
    cout<<endl;
    return 0;
}