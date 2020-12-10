class Solution {
    public int[] sortArrayByParity(int[] A) {
        int len = A.length;
        List<Integer> list = new ArrayList<>();
        
        for(int i = 0; i < len; i++){
            if(A[i]%2 == 0){
                list.add(A[i]);
            }
        }
        
        for(int i = 0; i < len; i++){
            if(A[i]%2 != 0){
                list.add(A[i]);
            }
        }
        
        int v = 0;
        for(Integer x : list){
            A[v] = x;
            v++;
        }
            return A;
    }
}
