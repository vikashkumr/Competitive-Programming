/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start

//Heap + hashmap + sliding window Easy-Medium

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int l = 0, r = k-1;
        unordered_map<int,int> hm;
        priority_queue<int> pq;
        for(int i=0;i<k;i++) pq.push(nums[i]);     
        res.push_back(pq.top());
        while(r<nums.size()-1) {                   
            r++; pq.push(nums[r]);
            hm[nums[l++]]++;
            if(hm[pq.top()]>0) {
                while(hm[pq.top()]>0) {
                   hm[pq.top()]--;
                   pq.pop(); 
                }
                res.push_back(pq.top());
            } else {
                res.push_back(pq.top());
            }
        }
        return res;
    }
};

//Another sol using Deque
// First preprocess for the first window . In each window keep the index of the largest element at the first index of deque.
// TC : O(n)

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> q;
        int i, n = nums.size();
        for(i=0;i<k;i++) {
            while(!q.empty() && nums[i] >= nums[q.back()]) q.pop_back();
            q.push_back(i);
        }
        while(i < n) {
            res.push_back(nums[q.front()]);
            while(!q.empty() and q.front()<=i-k) q.pop_front(); //ifindex doesn't lie in curr window
            while(!q.empty() && nums[i] >= nums[q.back()]) q.pop_back();
            q.push_back(i);
            i++;
        }
        res.push_back(nums[q.front()]);
        return res;
    }
};

// @lc code=end

