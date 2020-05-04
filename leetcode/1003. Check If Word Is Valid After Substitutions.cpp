//https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/

class Solution {
public:
    bool isValid(string S) {
        stack<char> stk;
        for(int i=0;i<S.length();i++) {
            char ch = S[i];
            stk.push(ch);
            while(!stk.empty() and stk.top()=='c' and stk.size()>=3) {
                char t1 = stk.top(); stk.pop();
                char t2 = stk.top(); stk.pop();
                char t3 = stk.top(); stk.pop();
                if(t1!='c' or t2 != 'b' or t3!='a') {
                    stk.push(t3);
                    stk.push(t2);
                    stk.push(t1);
                    break;
                }
            }
        }
        return stk.empty();
    }
};