#include<bits/stdc++.h>
using namespace std;
int n,l,r;
int cnt = 0;
class Node {
    public:
    int data;
    Node *left,*right;
    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};
bool check(Node *root) {
    if(root==NULL){              
        return true;
    }
    if(root) {
        bool lft = check(root->left);
        bool rgt = check(root->right);
        if(root->data>=l and root->data<=r and lft and rgt) {cnt++;return true;}
    }
    return false;
}

Node* buildBST(int *arr, int i, int j) {
    if(i>j) return NULL;
    int mid = (i+j)/2;
    Node *t = new Node(arr[mid]);
    t->left = buildBST(arr,i,mid-1);
    t->right = buildBST(arr,mid+1,j);
    return t;
}

int main() {
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];  
    cin>>l>>r;
    Node *root = buildBST(arr,0,n-1);
    check(root);
    cout<<cnt;
    return 0;
}