/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Add and Search Word - Data structure design
 */

// @lc code=start


class Node {
public:
    char data;
    bool terminal;
    unordered_map<char,Node*> child;
    Node(char data) {
        this->data = data;
        terminal = false;
    }
};


class WordDictionary {
public: 
    /** Initialize your data structure here. */
    Node *root;
    WordDictionary() {
        root = new Node('/');
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
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
        temp->terminal = true; 
    }
    
    bool find(Node *temp, string word) {
        for(int i=0;i<word.length();i++) {
            char ch = word[i];
            if(ch=='.') {
                for(auto it: temp->child) {
                    bool found = find(temp->child[it.first],word.substr(i+1));
                    if(found) return true;
                }
                return false;
            } else {
                if(temp->child.count(ch)) {
                    temp = temp->child[ch];
                } else {
                    return false;
                }
            }
        }
        return temp->terminal;
    }


    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return  find(root, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

