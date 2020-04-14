class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if(A.size()<3) return false;
        int flag = 0, i;
        for(i=1;i<A.size();i++) {
            if(A[i]>A[i-1]) continue;
            else {
               flag = 1; 
                break;
            }
        }

        //checking sorted condition //5 4 3 2 1
        if(i==1) return false;
        
        for(int j=i;j<A.size();j++) {
            if(A[j]<A[j-1] and flag == 1) continue;
            else {
               return false;
            }
        }
        if(flag==1) return 1;
        else return 0;
    }
};