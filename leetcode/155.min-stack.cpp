/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
class MinStack {
public:
    /** initialize your data structure here. */
    long long min;
    stack<long long> stk;
    MinStack() {
        
    }
    
    void push(int x) {
        if(stk.empty()) {
            stk.push(x);
            min = x;
        } else if(x >= min){
            stk.push(x);
        } else {
            //remember this 
            stk.push(2*(long long)x-min);
            min = x;
        }
    }
    
    void pop() {
        if(stk.top() < min) {
            //remember thiss
            min = 2*min-stk.top();
            stk.pop();
            return;
        }
        stk.pop();
    }
    
    int top() {
        if(stk.top() < min) {
            return min;
        }
        return stk.top();
    }
    
    int getMin() {
        return min;        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

