class Solution {
public:
    /**
     * @param nestedList: a list of NestedInteger
     * @return: the sum
     */
     
    int findDepth(vector<NestedInteger> nestedList) {
        int cur_lvl = 1;
        for(NestedInteger list: nestedList) {
            if(!list.isInteger()) {
                cur_lvl = max(cur_lvl, 1 + findDepth(list.getList()));
            }
        }
        return cur_lvl;
    }
    
    int solve(int level, vector<NestedInteger> nestedList) {
        int sum = 0;
        for(NestedInteger list: nestedList) {
            if(list.isInteger()) {
                sum += level*list.getInteger();
            } else {
                sum += solve(level-1,list.getList());
            }
        }
        return sum;
    }
    
    
    int depthSumInverse(vector<NestedInteger> nestedList) {
        int n = findDepth(nestedList);
        return solve(n, nestedList);
    }
};