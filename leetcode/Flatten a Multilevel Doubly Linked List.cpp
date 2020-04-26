/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        stack<Node*>st;
        Node *curr = head;
        while(curr) {
            if(curr->child!=NULL) {
                //agle level pe ja rha hai
                if(curr->next){
                    st.push(curr->next);
                    curr->next->prev = NULL;
                }
                curr->next = curr->child;
                if(curr->next) {
                    curr->next->prev = curr;
                }
                curr->child = NULL;
                curr = curr->next;
            } else {
                if(curr->next)
                curr = curr->next;
                else if(!st.empty()) {
                    //connection jodne hain
                    curr->next = st.top();
                    if(curr->next)
                    curr->next->prev = curr;
                    curr = curr->next;
                    st.pop();
                } 
                else curr = curr->next;
            }
        }
        return head;
    }
};