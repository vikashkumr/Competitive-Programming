//English JAN 20 long challange

#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ans;
class Node {
    public:
    char data;
    ll cnt;
    unordered_map<char,Node*> children;
    Node(ll data){
        this->data = data;
        this->cnt = 0;
    }
};

class Trie {
    
    public:
    Node *root;
    Trie(){
        this->root = new Node('\0');
    }
    void addWord(string str){
        Node *temp = root;
        for(ll i=0;i<str.length();i++){
            char ch = str[i];
            if(temp->children.count(ch)){
                temp = temp->children[ch];
                temp->cnt++;
            }
            else {
                Node *n = new Node(ch);
                temp->children[ch] = n;
                temp = n;
                temp->cnt = temp->cnt+1;
            }
        }
    }
    ll dfs(Node* rt, ll height){
        if(rt == NULL) return 0;
        ll cnt = 0;
        for(auto i : rt->children){
            cnt += dfs(rt->children[i.first],height+1);
        }

        rt->cnt = rt->cnt - cnt;
        if(rt->cnt > 1){
            ll n = (rt->cnt)>>1;
            ll temp = (height>>1)*(height>>1);
            ans+=n*temp;
            cnt+=2*n;
        } 
        delete rt;
        return cnt;
    }

};

string getStr(string s){
    string str;
    int l = str.length();
    for(int i=0;i<l;i++){
        str.push_back(s[i]);
        str.push_back(s[l-i-1]);
    }
    return str;
}
int main(){
    ll t;
    cin>>t;
    while(t--){
    Trie t;
    ll n;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        s = getStr(s);
        t.addWord(s);
    }
      ans = 0;
        //cout<<"t.root"<<t.root;
        t.dfs(t.root,0);
        cout<<ans<<endl;
    }
    return 0;
}