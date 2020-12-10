// preorder

void preorder(Node *root) { // Print L R
    stack<Node*> st;
    while(root || !st.empty()) {
        if(root) {
            //print curr value , push curr address to stack and move to left child
            cout<<root->val<<" ";
            st.push(root);
            root = root->left;
        } else {
            //go to parent and move to right
            root = st.top();st.pop();
            root = root->right;
        }
    }
}



// inorder

void inorder(Node *root) { // L Print R
    stack<Node*> st;
    while(root || !st.empty()) {
        if(root) { //push curr address to stack and go to left
            st.push(root);
            root = root->left;
        } else {
            //go to parent , print and move to right
            root = st.top();st.pop();
            cout<<root->val<<" ";
            root = root->right;
        }
    }

}

//post order using 2 stack

/*Algo: 
   1. push root to 1st stack
   2. loop while s1 is not empty
        i)pop top node of s1 and push to s2
        ii)push node->left and node->right to s1
   3. print contents of s2 (postorder)
   */
void postorder(Node *root) { // L R Print
    stack<Node*> st1, st2;
    while(!st1.empty()) {
        Node *currs1 = s1.top(); s1.pop();
        s2.push(currs1);
        if(currs1->left) s1.push(currs1->left); 
        if(currs1->right) s1.push(currs1->right); 
    }
    while(!st2.empty()) {
        cout<<st2.top()<<" ";
        st2.pop();
    }

}