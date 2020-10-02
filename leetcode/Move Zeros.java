class Solution {
    public void moveZeroes(int[] nums) {
        int len = nums.length;
        int count = 0;
        int p = 0;
        for(int i = 0; i < len; i++){
            if(nums[i] != 0){
                nums[p] = nums[i];
                p++;
            }
            else count++;
        }
        int s = len - count;
        
        for(int i = s; i < len; i++){
            nums[i] = 0;
        }
        
        
    }
}
