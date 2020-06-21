/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start
class Node {
     public:
    bool isTerminal;
    char data;
    unordered_map<char,Node*> child;
    Node(char data) {
        this->data = data;
        isTerminal = false;
    }
};


class Trie {
public:
    Node *root;
    /** Initialize your data structure here. */
    Trie() {
        this->root = new Node('\0');        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *temp = root;
        for(int i=0;i<word.length();i++) {
            char ch = word[i];
            if(temp->child.count(ch)) {
                temp = temp->child[ch];
            } else {
                Node *n = new Node(ch);
                temp->child[ch] = n;
                temp = n;
            }
        }
        temp->isTerminal = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *temp = root;
        for(int i=0;i<word.size();i++) {
            char ch = word[i];
            if(temp->child.count(ch)) {
                temp = temp->child[ch];
            } else {
                return false;
            }
        }
        return temp->isTerminal;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node *temp = root;
        int i = 0;
        while(temp->child.count(prefix[i])) {
            temp = temp->child[prefix[i]];
            i++;
        }
        return i==prefix.length();
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

