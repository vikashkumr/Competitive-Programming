class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        int len = flowerbed.length;
        int count = 0;
        
        for(int i = 0; i < len; i++){
            if(flowerbed[i] == 0 
              && (i == 0 || flowerbed[i-1] == 0)
              && (i == len-1 || flowerbed[i+1] == 0)){
                count++;
                i++;
            }
        }
        
        if(count >= n) return true;
        else return false;
    }
}
