// Method that returns the bottom view.

//just take horizontal at each distance last updated node will be the answer

vector <int> bottomView(Node *root)
{
    if(root == NULL) return {};
    int curr_left = 0, curr_rt = 0;
    int hd = 0;
    
    map<int,Node*> mp; // horizontal dist, nnode*
    queue<pair<Node*, int>> q; // node*, horizontal dist
    q.push({root,hd});
    mp[0] = root;

    vector<int> res;
    while(!q.empty()) {
        auto n = q.front(); q.pop();
        mp[n.second] = n.first;
        if(n.first->left) q.push({n.first->left,n.second-1});
        if(n.first->right) q.push({n.first->right,n.second+1});
    }
    for(auto it: mp) res.push_back(it.second->data);
    return res;
}