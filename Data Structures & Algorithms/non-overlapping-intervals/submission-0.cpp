class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n <= 1) return 0;
        sort(intervals.begin(), intervals.end(),
            [](const vector<int>& a, const vector<int>& b) {
                if (a[1] == b[1]) return a[0] < b[0];
                return a[1] < b[1];
            });        
        int ans = 0;
        int currEnd = intervals[0][0];
        for(int i = 0; i < n; i++) {
            if(intervals[i][0] < currEnd) {
                ans++;
            } else {
                currEnd = intervals[i][1]; 
            }
        }
        return ans;
    }
};