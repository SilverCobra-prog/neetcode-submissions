class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        for(int i = 0; i < points.size(); i++) {
            points[i].push_back(points[i][0]*points[i][0]+points[i][1]*points[i][1]);
        }

        sort(points.begin(), points.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[2] < b[2];
        });

        for(int i = 0; i < points.size(); i++) {
            points[i].pop_back();
        }

        vector<vector<int>> ans;
        for(int i = 0; i < k; i++) {
            ans.push_back(points[i]);
        }

        return ans;
    }
};
