class Solution {
public:

    bool flag = 0;
    void solve(int upper, int lower,int idx, vector<int>& colsum, vector<vector<int>> &v,vector<vector<int>> &vans) {
        if(flag==1) return;
        if(idx==colsum.size() and lower == 0 and upper == 0) {
            //assign vector
            if(flag==0) {
                vans = v;
                flag = 1;
            }
            return;
        }
        if(idx==colsum.size()) return;
        if(colsum[idx]==2) {
            if(upper>0 and lower>0) {
                v[0].push_back(1);
                v[1].push_back(1);
            return  solve(upper-1,lower-1,idx+1,colsum,v,vans);
            } else return;
        }

        else if(colsum[idx]==0) {
            v[0].push_back(0);
            v[1].push_back(0);
            return solve(upper,lower,idx+1,colsum,v,vans);
            
        }
        else if(colsum[idx]==1) {
            if(upper>lower and upper>0) {
                v[0].push_back(1);
                v[1].push_back(0);
              return  solve(upper-1,lower,idx+1,colsum,v,vans);
                
            }
            else if(lower>0){
                v[0].push_back(0);
                v[1].push_back(1);
              return  solve(upper,lower-1,idx+1,colsum,v,vans);
               
            } else return;
        }
    }


    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        vector<vector<int>>v(2);
         vector<vector<int>>vans(2);
        solve(upper,lower,0,colsum,v,vans);
        if(vans[0].size()==0) return {};
        return vans;
    }
};