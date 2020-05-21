//https://leetcode.com/problems/longest-happy-string/

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {

        string s = "";
        priority_queue<pair<int,char>>pq;
        pq.push({a,'a'});
        pq.push({b,'b'});
        pq.push({c,'c'});
        
        while(!pq.empty()) {
            auto pr = pq.top(); pq.pop();
            if(pr.first>=2 and (s.length()==0 or pr.second!=s[s.length()-1])) {
                s = s+pr.second+pr.second;
                pr.first-=2;
                if(pr.first>0) pq.push(pr);
            } else if(pr.first==1 and (s.length()==0 or pr.second!=s[s.length()-1])){
                 s = s+pr.second;
            } else {
                if(pq.empty()) continue;
                auto pr2 = pq.top(); pq.pop();
                if(pr2.first>=1) {
                    s = s+pr2.second;
                    pr2.first-=1;
                    if(pr2.first>0) pq.push(pr2);
                    if(pr.first>0) pq.push(pr);
                } else if(pr2.first==1){
                     s = s+pr2.second;
                    if(pr.first>0) pq.push(pr);
                }
            }
        }
        return s;
    }
};