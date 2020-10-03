class Solution {
    public int[] plusOne(int[] digits) {
        int len = digits.length;
        
        int lastVal = digits[len-1];
        
        boolean check = false;
        if((lastVal+1) % 10 != 0){
            digits[len-1] += 1;
            check = true;
        }
        if(check) return digits;

        int d [] = new int[len+1];
        if(len == 1){
            d[0] = 1;
            d[1] = 0;
            check = true;
        }
        if(check) return d;
        
        
        d[len] = 0;
        
        for(int i = len-1; i >= 0; i--){
            int p = i;
            if(digits[i] == 9){
                d[p+1] = 0;
                digits[i] = 0;
                p--;
            }else {
                
                 digits[i] += 1;
                return digits;
            }
            
            d[p+1] += 1;
            
            
        }
        return d;
    } 
}
