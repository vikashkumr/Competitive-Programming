class MaxStack {
public:
    stack<int> s,ss; 
    MaxStack() {
        // do intialization if necessary
    }

    /*
     * @param number: An integer
     * @return: nothing
     */
    void push(int number) {
        s.push(number);
        if(ss.empty() or number>=ss.top()) {
            ss.push(number);
        }
        // write your code here
    }

    /*
     * @return: An integer
     */
    int pop() {
        int x = s.top();
        if(s.top() < ss.top()) {
            s.pop();
            return x;
        }
        
        if(s.top() > ss.top()) {
            //important point 
            while(s.top() > ss.top()) s.pop();
        }
        
        s.pop();ss.pop();
        return x;
        // write your code here
    }

    /*
     * @return: An integer
     */
    int top() {
        int x = s.top();
        return x;
        // write your code here
    }
    
    /*
     * @return: An integer
     */
    int peekMax() {
        int x = ss.top();
        return x;
        // write your code here
    }
    
    /*
     * @return: An integer
     */
    int popMax() {
        int x = ss.top();
        if(s.top() == ss.top()) s.pop();
        ss.pop();
        return x;
        // write your code here
    }
};