//https://leetcode.com/problems/implement-stack-using-queues/

class MyStack {
public:
     queue<int> q1, q2;
    /** Initialize your data structure here. */
    MyStack() {
       
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q1.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int t;
        while(q1.size()!=1) {
            t = q1.front();
            q1.pop();
            q2.push(t);
        }
        t = q1.front();
        q1.pop();
        swap(q1,q2);
        return t;
    }
    
    /** Get the top element. */
    int top() {
        int t;
        while(q1.size()!=1) {
            t = q1.front();
            q1.pop();
            q2.push(t);
        }
        return q1.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty()==q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */