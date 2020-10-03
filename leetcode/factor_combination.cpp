class Solution {
public:
    /**
     * @param n: a integer
     * @return: return a 2D array
     */
     
    vector<vector<int>> res;
    void solve(int start, int product, int n, vector<int> &v) {
        
        if(start>n or product>n) return;
        if(product==n) {
            res.push_back(v);
            return;
        }
        
        for(int i=start; i<n;i++) {
            if(i*product > n) break;
            if(n%i==0) {
                v.push_back(i);
                solve(i, i*product, n, v);
                v.pop_back();
            }
        }
    } 
     
    vector<vector<int>> getFactors(int n) {
        vector<int>v;
        solve(2,1,n,v);
        return res;
    }
};