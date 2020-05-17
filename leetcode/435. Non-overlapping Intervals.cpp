//https://leetcode.com/problems/non-overlapping-intervals/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size()==0) return 0;
        sort(intervals.begin(), intervals.end(), [&] (vector<int>a, vector<int>b) -> bool {
            return a[1]<b[1];
        });
        
        int cnt = 0;
        int end = intervals[0][1];
        for(int i=1;i<intervals.size();i++) {
            if(intervals[i][0]>=end) {
                end = intervals[i][1];
            } else cnt++;
        }
        return cnt;
    }
};