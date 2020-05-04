//https://leetcode.com/problems/online-stock-span/
class StockSpanner {
public:
    stack<pair<int,int>>stk;
    StockSpanner() {
        
    }
    int next(int price) {
        int cnt = 1;
        while(!stk.empty() and stk.top().first<=price) {
            cnt+= stk.top().second;
            stk.pop();
        }
        stk.push({price,cnt});
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */