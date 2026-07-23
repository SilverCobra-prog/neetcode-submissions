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
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        if (n == 0) return 0;

        vector<int> starts, ends;

        for (auto& a : intervals) {
            starts.push_back(a.start);
            ends.push_back(a.end);
        }

        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        int i = 0, j = 0;
        int rooms = 0, ans = 0;

        while (i < n) {
            if (starts[i] < ends[j]) {
                rooms++;
                i++;
                ans = max(ans, rooms);
            } else {
                rooms--;
                j++;
            }
        }

        return ans;
    }
};