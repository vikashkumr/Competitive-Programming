class Solution {
public:
    
    int myAtoi(string str) {
        long long res = 0;
        bool minus = 0;
        int idx = 0;
        for(idx=0;idx<str.length();idx++) {
            if(str[idx]==' ') continue;
            else break;
        }
        if(idx<str.length() and str[idx]=='-') {
            minus = 1;
            idx++;
        } 
        else if(idx<str.length() and str[idx]=='+') {
            idx++;
        }
        int i = idx;
        while(i<str.length() and str[i]>='0' and str[i]<='9') {
            res = res*10+str[i]-'0';
            if(res>INT_MAX) break;
            i++;
        }
        if(res>INT_MAX and minus==0) return INT_MAX;
        if(minus==1) {
            if(res>INT_MAX) return INT_MIN;
            else return -res;
        }
        return res;
    }
};