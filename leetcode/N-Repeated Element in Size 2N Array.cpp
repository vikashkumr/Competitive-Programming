class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        sort(A.begin(),A.end());
        int ans = A.size()/2;
        int st = 1;
        for(int i=1;i<A.size();i++) {
            if(A[i]==A[i-1]) {
                st++;
                if(st==ans) return A[i];
            } else {
                st = 1;
            }
        }
        return 0;
    }
};