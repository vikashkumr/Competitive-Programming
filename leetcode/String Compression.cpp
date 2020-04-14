class Solution {
public:
    int compress(vector<char>& chars) {
        int charTrack = 0;
        for(int i=1,cnt=1;i<=chars.size();i++,cnt++) {
            if(i==chars.size() or chars[i]!=chars[i-1]) {
                chars[charTrack++] = chars[i-1];
                if(cnt>1) {
                    for(char ch : to_string(cnt)) {
                        chars[charTrack++] = ch;
                    }    
                }
                cnt = 0;
            }
        }
        return charTrack;
    }
};