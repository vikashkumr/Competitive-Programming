/**
 * Definition of Interval:
 * class Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */
// TC = O(nlogn) SC = O(1)

class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: if a person could attend all meetings
     */
    
    bool canAttendMeetings(vector<Interval> &intervals) {
        int n = intervals.size();
        if(n==0) return true;
        sort(intervals.begin(), intervals.end(), [&](Interval a, Interval b) -> bool {
            if(a.end == b.end) return a.start < b.start;
            return a.end < b.end;
        });
        
        for(int i=1;i<n;i++) {
            if(intervals[i].start < intervals[i-1].end) return false;
        }
        
        return true;
    }
};