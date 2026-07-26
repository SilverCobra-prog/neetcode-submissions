class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int n = heights.size();
        int prevMax = 0;
        vector<int> ans;
        for(int i = n-1; i >= 0; i--) {
            if(heights[i] > prevMax) ans.push_back(i);
            prevMax = max(heights[i], prevMax);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};