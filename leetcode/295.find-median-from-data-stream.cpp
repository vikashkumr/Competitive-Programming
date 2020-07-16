/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 */

/*Algo: left = maxheap , right = min Heap
    1. take two heap first max, 2nd min
    2. at anytime difference of size of heap should be <= 1 (median property)
    3. at each iteration if left heap is empty simply push num to that heap
        else if(num > leftHeap) push in right heap else in left heap
    4. after following above 3 steps check for size difference and fix that
    5. if(lftSize is greater (> 1) put top element into right heap) else top element of right in to left heap


// @lc code=start
class MedianFinder {
public:
    priority_queue<int> pql;
    priority_queue<int, vector<int>, greater<int>> pqr; 
    /** initialize your data structure here. */
    MedianFinder() {
      
    }
    
    void addNum(int num) {
        if(pql.empty()) pql.push(num);
        else if(num <= pql.top()) {
            pql.push(num);
        } else {
            pqr.push(num);
        }
        if(abs((int) (pql.size() - pqr.size())) <= 1) return;
        else if(pql.size() < pqr.size()) {
            pql.push(pqr.top());
            pqr.pop();
        } else {
            pqr.push(pql.top());
            pql.pop();
        }
    }
    
    double findMedian() {
        double ans = 0.0;
        if(pql.empty() and pqr.empty()) return ans;
        if(pql.empty()) return pqr.top();
        if(pqr.empty()) return pql.top();

        if((pql.size() + pqr.size())&1) {
            if(pql.size()>pqr.size()) {
                return pql.top();
            } else{
                return pqr.top();
            }
        } else {
            ans = (double) (pql.top() + pqr.top())/2;
        }
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

