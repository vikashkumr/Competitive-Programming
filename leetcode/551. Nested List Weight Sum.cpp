/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer,
 *     // rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds,
 *     // if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds,
 *     // if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:

    int solve(int level, vector<NestedInteger> nestedList) {
        int sum = 0;
        for(NestedInteger list: nestedList) {
            if(list.isInteger()) {
                sum += level*list.getInteger();
            } else {
                sum += solve(level+1,list.getList());
            }
        }
        return sum;
    }

    int depthSum(const vector<NestedInteger>& nestedList) {
        return solve(1, nestedList);
    }
};