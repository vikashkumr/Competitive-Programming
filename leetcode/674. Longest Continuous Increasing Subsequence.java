class Solution {
    public int findLengthOfLCIS(int[] nums) {
        int len = nums.length;
        
        if(len == 1) return 1;
        if(len == 0) return 0;
        
        int c[] = new int[len];
        int p = 0, f = nums[0];
        
        for(int i = 1; i < len; i++){
            if(f < nums[i]){
                c[p] += 1;
            }
            else p++;
            
            f = nums[i];
        }
        
        int max = c[0];
        for(int i = 1; i < len; i++){
            max = Math.max(max, c[i]);
        }
        return max+1;
    }
}
