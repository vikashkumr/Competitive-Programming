// https://practice.geeksforgeeks.org/problems/swapping-pairs-make-sum-equal4142/1

class Solution{

	public:
	int findSwapValues(int A[], int n, int B[], int m)
	{
        int s1 = accumulate(A,A+n, 0);
        int s2 = accumulate(B,B+m, 0);
        int d = abs(s1-s2);
        if(d&1) return -1;
        d>>=1;
        // sumA - a + b = sumB - b + a;
        sort(A,A+n);
        sort(B,B+m);
        if(d==0) return -1;
        if(s1 > s2) {
            int i = 0, j=0;
            while(i<n&&j<m) {
                if(A[i] -B[j] == d) return 1;
                else if(A[i]-B[j] > d) j++;
                else i++;
            }
            
        } else {
            int i = 0, j=0;
            while(i<n&&j<m) {
                if(B[j] -A[i] == d) return 1;
                else if(B[j]-A[i] > d) i++;
                else j++;
            }
        }
        return -1;
	}