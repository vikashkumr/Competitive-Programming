Node *head = NULL, *pre = NULL;

//inorder traversal
void solve(Node *root) {
    if(root == NULL) return;
    
    solve(root->left);
    if(pre == NULL) {
        head = root;
    } else {
        root->left = pre;
        pre->right = root;
    }
    pre = root;
    solve(root->right);
}

Node * bToDLL(Node *root)
{
    solve(root);
    return head;
}