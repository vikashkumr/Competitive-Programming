/*
 * @lc app=leetcode id=622 lang=cpp
 *
 * [622] Design Circular Queue
 */

// @lc code=start

//keep 4 variable front, rare, current size, max size

class MyCircularQueue {
public:
    int front, rear;
     int arr[1000];
    int f,r,ms,cs;
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
       f = 0;
       r = k-1;
       ms = k;
       cs = 0;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(!isFull()) {
            r = (r+1)%ms;
            arr[r] = value;
            cs++;
            return true;
        }
        return false;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(!isEmpty()) {
            f = (f+1)%ms;
            cs--;
            return true;
        }
        return false;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(isEmpty()) return -1;
        return arr[f];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(isEmpty()) return -1;
        return arr[r];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return cs==0;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return cs==ms;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
// @lc code=end

