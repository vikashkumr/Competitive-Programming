class KthLargest {
public:
    priority_queue<int,vector<int> , greater<int> >pq;
    int n;
    int max(int x, int y) {
        return (x>y) ? x : y;
    }
    KthLargest(int k, vector<int>& nums) {
              n = k;
        if(nums.size()>0) {
             sort(nums.begin(),nums.end());
             for(int i=max(nums.size()-k,0);i<nums.size();i++) pq.push(nums[i]); 
        }
        
    }
    
    int add(int val) {
        if(pq.empty() || pq.size()<n) {
           pq.push(val);
            return pq.top();
        } else
        if(val<=pq.top()) {
            return pq.top();
        } else {
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */