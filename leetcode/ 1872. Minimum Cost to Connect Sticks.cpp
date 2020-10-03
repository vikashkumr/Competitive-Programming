class Solution {
public:
    /**
     * @param sticks: the length of sticks
     * @return: Minimum Cost to Connect Sticks
     */
    int MinimumCost(vector<int> &sticks) {
        int ans = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int x: sticks) pq.push(x);
        
        if(sticks.size()<=1) return 0;
        int x,y;
        while(pq.size()>=2) {
            x = pq.top();pq.pop();
            y = pq.top();pq.pop();
            ans+=x+y;
            if(pq.size()>=1)
            pq.push(x+y);
        }
        if(pq.size()!=0) ans+=pq.top();
        return ans;
    }
};