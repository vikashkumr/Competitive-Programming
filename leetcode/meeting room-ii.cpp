/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */
//Greedy O(nlogn)
class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: the minimum number of conference rooms required
     */
    int minMeetingRooms(vector<Interval> &intervals) {

        //sort according to meeting start time
        sort(intervals.begin(), intervals.end(), [&](Interval a, Interval b) -> bool {
            return a.start < b.start;
        });

        priority_queue<int, vector<int>, greater<int>> pq; //keeps end time of meetings // min heap
        for(Interval &interval: intervals) {
            if(!pq.empty() and pq.top() <= interval.start) pq.pop(); //use the same room
            pq.push(interval.end);
        }
        return pq.size(); //number of rooms required
    }
};