/*
step 1: pick every row check first col if it is 0 flip row else go to next row
step 2: Now consider every col and count number of 1's if it is less than 0's flip all bits in that column 
step 3: Finally traverse row wise and cal ans and return
*/

class Solution {
public:
    void flipRow(vector<vector<int>>& A, int row) {
        for (int i = 0; i < A[0].size(); i++) {
            A[row][i] = 1 - A[row][i];
        }
    }
    
    int calAns(vector<vector<int>>& A) {
        int ans = 0;
        for (int i = 0; i < A.size(); i++) {
            int tmpAns = 0;
            int n = A[i].size();
            for (int j = 0; j < n; j++) {
                tmpAns += A[i][j]*pow(2,n-j-1);
            }
            ans += tmpAns;
        }
        return ans;
    }
    
    void flipCol(vector<vector<int>>& A, int col) {
        for (int i = 0; i < A.size(); i++) {
            A[i][col] = 1 - A[i][col];
        }
    }
    //return true if no of 1's >= no of 0's
    bool count1s(vector<vector<int>>& A, int col) {
        int one = 0, zero = 0;
        for (int i = 0; i < A.size(); i++) {
            if (A[i][col] == 1) one++;
            else zero++;
        }
        return one>=zero;
    }
    
    int matrixScore(vector<vector<int>>& A) {
        for (int i = 0; i< A.size(); i++) {
            if (A[i][0] == 0) flipRow(A, i);
        }
        
        for (int i = 0; i < A[0].size(); i++) {
            if(!count1s(A, i)) flipCol(A, i);
        }
        return calAns(A);
    }
};