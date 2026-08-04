class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<vector<int>> ps(n);
        for(int i = 0; i < position.size(); i++) {
            ps[i] = {position[i], speed[i]};
        }

        sort(ps.begin(), ps.end());
        long long dist = target-ps[n-1][0];
        long long pace = ps[n-1][1];
        int ans = 1;
        for(int i = n-2; i >= 0; i--) {
            if(pace * (target-ps[i][0]) > ps[i][1]*dist) {
                dist = (target-ps[i][0]);
                pace = ps[i][1];
                ans++;
            }
        }
        return ans;
    }
};