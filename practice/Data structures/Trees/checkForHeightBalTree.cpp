// This function should return tree if passed  tree 
// is balanced, else false. gfg
bool ok;
pair<int,bool> height(pair<Node*,int> x) {
    if(ok==0) return {1,false}; 
    if(x.first == NULL) return {0,1};
    pair<int,bool> lh = height({x.first->left,x.second + 1});
    pair<int,bool> rh = height({x.first->right,x.second + 1});
    if(abs(lh.first-rh.first) <= 1) {
      ok = (lh.second&rh.second);
      return {max(lh.first,rh.first)+1,lh.second&rh.second};  
    }
    ok = 0;
    return {max(lh.first,rh.first)+1, false};
}

bool isBalanced(Node *root) {
    ok = 1;
    if(root==NULL) return true;
    auto it = height({root,1});
    return it.second;
}
