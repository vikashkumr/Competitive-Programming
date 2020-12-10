class Solution {
    public List<List<Integer>> largeGroupPositions(String s) {
        int len = s.length();
        
         List<List<Integer>> outer = new ArrayList<>();
          
        
        int count = 0;
        int start = 0;
        int end = 0;
        
        for(int i = 0; i < len; i++){
            char ch = s.charAt(i);
            start = i;
            int j = i+1;
            while(j < len){
                if(ch == s.charAt(j)){
                    count++;
                }
                else break;
                
                j++;
            }
            
            if(count >= 2){
                List<Integer> inner = new ArrayList<>();
                end = start+count;
                inner.add(start);
                inner.add(end);
                outer.add(inner);
            }
            
            i += count;
            count = 0;
            
        }
           

        return outer;
    }
}
