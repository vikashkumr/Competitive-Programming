//https://leetcode.com/problems/backspace-string-compare/

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> s, t;
        for(char ch : S) {
            if(ch=='#') {
                if(!s.empty()) s.pop();
            } else {
                s.push(ch);
            }
        }
        for(char ch : T) {
            if(ch=='#') {
                if(!t.empty()) t.pop();
            } else {
                t.push(ch);
            }
        }
        if(s.size()!=t.size()) return 0;
        else if(s.empty() and t.empty()) return true;
        else {
            while(s.size() and t.size()) {
                if(s.top()==t.top()) {
                s.pop(); t.pop();
                } else {
                    return false;
                }
            }
            
        }
        return s.empty()==t.empty();
    }
};