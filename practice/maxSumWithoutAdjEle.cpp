//INterview Bit

int Solution::adjacent(vector<vector<int> > &A) 
{
    int n=A[0].size();//size of arr
    
    for(int i=0;i<n;i++) //store max for each coloum
        A[0][i]=max(A[0][i],A[1][i]);
        
    A[0][1]=max(A[0][0],A[0][1]); //for 2nd element choose max among first end second
    
    for(int i=2;i<n;i++)
        A[0][i]=max(A[0][i-1],A[0][i-2]+A[0][i]);
    
    return max(A[0][n-1],A[0][n-2]);
}