/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](const Interval& a, const Interval& b) {
                 return a.start < b.start;
             });

        int currEnd = 0;
        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i].start < currEnd) return false;
            currEnd = intervals[i].end;
        }

        return true;
    }
};