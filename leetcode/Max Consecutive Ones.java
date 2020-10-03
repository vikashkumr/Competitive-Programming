class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        
        int p = 0;
        int a[] = new int[nums.length];
        for(int i = 0; i < nums.length; i++){
            if(nums[i] == 1){
                a[p] += 1;
            }
            
            else {
                p++;
            }
        }
        int max = a[0];
        for(int i = 1; i < a.length; i++){
            if(max < a[i]){
                max = a[i];
            }
        }
        
        return max;
    }
}
