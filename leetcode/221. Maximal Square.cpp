// https://leetcode.com/problems/maximal-square/


class Solution {
public:
    int max(int a,int b) {
        return a>b?a:b;
    }
    
    int maximalSquare(vector<vector<char>>& m) {
        if(m.size()==0) return 0;
        int n = 0;
        
        int row = m.size();
        int col = m[0].size();
        if(row==1 and col==1) return m[row-1][col-1]-'0';
        int matrix[row+1][col+1];
        
        for(int i=0;i<row;i++) {
            matrix[i][0] = m[i][0]-'0';
            n = max(n, matrix[i][0]);
        }
        
        for(int i=0;i<col;i++) {
            matrix[0][i] = m[0][i]-'0';
            n = max(n, matrix[0][i]);
        }
        
        for(int i=1;i<row;i++) {
            for(int j=1;j<col;j++) {
               if(m[i][j]=='1') {
                   matrix[i][j] = 1 + min(matrix[i-1][j-1], min(matrix[i-1][j],matrix[i][j-1]));
                   n = max(n, matrix[i][j]);
               }
                else matrix[i][j] = 0;
            }
        }
        return n*n;
    }
};