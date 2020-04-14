class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int w) {
        
        if(hand.size()%w!=0 && (hand.size()/w) != w) {
            return false;
        }
        
        map<int,int> mp;
        for(int x : hand) mp[x]++;
        
        while(!mp.empty()) {
            int curr_ele = mp.begin()->first; 
            for(int i=1;i<=w;i++) {
                if(mp[curr_ele]<=0) return false;
                else {
                    mp[curr_ele]--;
                    if(mp[curr_ele]<=0) mp.erase(curr_ele);
                    curr_ele++;
                }    
            }
        }
        return mp.empty();
    }
};