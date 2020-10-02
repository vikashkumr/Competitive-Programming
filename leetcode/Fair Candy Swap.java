class Solution {
    public int[] fairCandySwap(int[] A, int[] B) {
        int ans[] = new int[2];
        int totalA = 0, totalB = 0;
        
        for(int i = 0; i < A.length; i++){
            totalA += A[i];
        }
        
        for(int i = 0; i < B.length; i++){
            totalB += B[i];
        }
        
        int t1 = totalA, t2 = totalB;
        
        for(int i = 0; i < A.length; i++){
            for(int j = 0; j < B.length; j++){
                int a = totalA - A[i];
                int b = totalB - B[j];
                
                if(a+B[j] == b+A[i]){
                    ans[0] = A[i];
                    ans[1] = B[j];
                    break;
                }
                else {
                    totalA = t1;
                    totalB = t2;
                }
            }
        }
        
        return ans;
        
    }
}
