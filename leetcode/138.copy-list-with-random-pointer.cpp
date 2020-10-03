/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
/*
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return head;
        unordered_map<Node*,int> add_idx, add_rnd;
        int i = 1;
        Node *tmp = head;
        while(tmp!=NULL) {
            add_idx.insert({tmp, i++});
            tmp = tmp->next;
        }
        
        tmp = head;
        while(tmp!=NULL) {
            add_rnd.insert({tmp, add_idx[tmp->random]});
            tmp = tmp->next;
        }
        
        Node *root = new Node(head->val);
        tmp = head;
        
        vector<Node*>v;
        v.push_back(NULL);
        
        //creating skelaton of clone and storing address of clone nodes in vec
        // Node *root = new Node(tmp->val);
        Node *n = root;
        v.push_back(n);
        tmp = tmp->next;
        Node *last = n;
        while(tmp!=NULL) {
            n = new Node(tmp->val);
            v.push_back(n);
            tmp = tmp->next;
            last->next = n;
            last = n;
        }
        
        //setting random pointers
        n = root;
        tmp = head;
        while(n!=NULL) {
            n->random = v[add_rnd[tmp]];
            tmp = tmp->next;
            n = n->next;
        }
        
        return root;
        
    }
};
// @lc code=end

