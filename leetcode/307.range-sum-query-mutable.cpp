/*
 * @lc app=leetcode id=307 lang=cpp
 *
 * [307] Range Sum Query - Mutable
 */

// @lc code=start
class NumArray {
public:
    vector<int>v;
    int n;
    vector<int>input;
    void add(int i, int val) {
        while(i<=n) {
            v[i]+=val;
            i+=i&(-i);
        }
    }
    NumArray(vector<int>& nums) {
        n = nums.size();
        v.resize(n+1,0);
        input = nums;
        for(int i=0;i<nums.size();i++) {
            add(i+1,nums[i]);
        }
       
    }
    
    void update(int i, int val) {
       add(i+1,val-input[i]);
        input[i] = val;
    }
    
    int sumRange(int i, int j) {
        
        int sum1 = 0;
        int sum2 = 0;
        j++;
        while(j>0) {
            sum1+=v[j];
            j = j-(j&(-j));
        }
     
        while(i>0) {
            sum2+=v[i];
            i = i-(i&(-i));
        }
        return sum1-sum2;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
// @lc code=end

