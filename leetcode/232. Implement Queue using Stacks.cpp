//https://leetcode.com/problems/implement-queue-using-stacks/

class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> st1,st2;
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        st1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int t;
        if(!st2.empty()) {
            t = st2.top();
            st2.pop();
            return t;
        } else {
            while(!st1.empty()) {
                t = st1.top();
                st2.push(t);
                st1.pop();
            }
            t = st2.top();
            st2.pop();
            return t;
        }
    }
    
    /** Get the front element. */
    int peek() {
        int t;
        if(!st2.empty()) {
            return st2.top();
        } else {
            while(!st1.empty()) {
                t = st1.top();
                st2.push(t);
                st1.pop();
            }
            return st2.top();
        }
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return st1.empty()==st2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */