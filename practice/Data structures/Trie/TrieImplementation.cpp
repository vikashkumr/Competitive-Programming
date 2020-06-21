//Implementation of Trie

#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    char data;
    bool isTerminal;
    unordered_map<char,Node*> children;
    Node(char data){
        this->data = data;
        this->isTerminal = false;
    }
};

class Trie {
    Node *root;
    int count;
    public:
    Trie(){
        this->root = new Node('\0');
        this->count = 0;
    }
    void addWord(string str){
        Node *temp = root;
        for(int i=0;i<str.length();i++){
            char ch = str[i];
            if(temp->children.count(ch)){
                temp = temp->children[ch];
            }
            else {
                Node *n = new Node(ch);
                temp->children[ch] = n;
                temp = n;
            }
        }
        temp->isTerminal = true;
    }

    bool search(string str){
        Node *temp = root;
        for(int i=0;i<str.length();i++){
            char ch = str[i];
            if(temp->children.count(ch)){
                temp = temp->children[ch];
            }
            else {
                return false;
            }
        }
        
        return temp->isTerminal;
    }

};


int main(){
    Trie t;
    int n;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        t.addWord(s);
    }
    int q;
    cin>>q;
    while(q--){
        string s;
        cin>>s;
        cout<<t.search(s)<<"\n";
    }
    return 0;
}