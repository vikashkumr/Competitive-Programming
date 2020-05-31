class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> v;
        map<char,int> lastindex;
        for(int i = 0; i < S.length(); i++) {
            lastindex[S[i]] = i;
        }
        
        int last_pos = 0;
        int last_ans = 0;
        for(int i = 0; i<S.length(); i++) {
            last_pos = max(last_pos, lastindex[S[i]]);
            if(last_pos == i or i == S.length()-1) {
               v.push_back(i+1-last_ans);
                last_ans = i+1;
            } 
        }
        
        return v;
    }
};

//store last index of each character
//untill all character satisfies it last index property we will go on 
//  else we can consider another part