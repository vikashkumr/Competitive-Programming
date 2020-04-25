class Node {
public:
    int val;
    Node *next;
    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};
class MyLinkedList  {
    Node *head;
public:
    /** Initialize your data structure here. */
    
    MyLinkedList() {
        head = NULL;  
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
       Node *node = head;
        int i = 0;
        while(node!=NULL ) {
            if(i==index) return node->val;
            i++;
            node = node->next;
        }
        return -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node *node = new Node(val);
        node->next = head;
        head = node;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node *n = new Node(val);
        Node *node = head;
        while(node->next!=NULL) {
            node = node->next;
        }
        node->next = n;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        Node *node = new Node(val);
         Node *n = head;
        if(index==0) {
            node->next = head;
            head = node;
            return;
        }
        int i = 0;
        while(n!=NULL) {
            if(i==index-1) break;
            n = n->next;
            i++;
        }
        if(n==NULL) return;
        node->next = n->next;
        n->next = node;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
         Node *n = head;
        if(index==0) {
            head = head->next;
            return;
        }
        int i = 0;
        while(n!=NULL) {
            if(i==index-1) break;
            n = n->next;
            i++;
        }
        if(n==NULL) return;
        if(n->next!=NULL)
        n->next = n->next->next;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */