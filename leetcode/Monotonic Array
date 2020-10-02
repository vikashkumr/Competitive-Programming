class Solution {
    public boolean isMonotonic(int[] A) {
        int len = A.length;
        
        if(len == 1) return true;
        
        boolean inc = true;
        boolean dec = true;
        for(int i = 0; i < len-1; i++){
            if(A[i] > A[i+1]){
                inc = false;
                break;
            }
            if(A[i] == A[i+1]) continue;
        }
        
         for(int i = 0; i < len-1; i++){
            if(A[i] < A[i+1]){
                dec = false;
                break;
            }
            if(A[i] == A[i+1]) continue;
        }
        
        if(inc == true) return true;
        if(dec == true) return true;
        
        return false;
        
    }
}
