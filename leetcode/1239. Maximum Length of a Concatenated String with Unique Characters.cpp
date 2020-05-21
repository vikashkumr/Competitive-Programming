//https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/

class Solution {
public:
    
    void updateMask(string s, int *arr) {
        for(char ch : s) {
            arr[ch-'a']++;
        }
    }
    
    bool colide(int *arr) {
        for(int i=0;i<=26;i++) {
            if(arr[i]>1) return 1;
        }
        return 0;
    }
    
    int maxLength(vector<string>& arr) {
        int ans = 0;
        int n = arr.size();
        int mask[27]={0};
        for(int i=0;i<(1<<n);i++) {
            int t = i;
            int pos = 0;
            int len = 0;
            memset(mask,0,sizeof mask);
            while(t>0){
                if(t&1) {
                   updateMask(arr[pos],mask); 
                    len+=arr[pos].length();
                }
                pos++;
                t>>=1;
            }
            if(!colide(mask)) ans = max(ans,len); 
        }
        return ans;
    }
};