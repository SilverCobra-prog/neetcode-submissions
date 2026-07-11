class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> sols;
        sort(nums.begin(), nums.end());
        for(int j = 1; j < nums.size()-1; j++) {
            int i = 0;
            int k = nums.size()-1;
            while (i < j && j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    vector<int> trip = {nums[i], nums[j], nums[k]};
                    sort(trip.begin(), trip.end());
                    sols.push_back(trip);
                    i++;
                    k--;
                } else if (sum > 0) {
                    k--;
                } else {
                    i++;
                }
            }
        }
        sort(sols.begin(), sols.end());
        sols.erase(unique(sols.begin(), sols.end()), sols.end());
        return sols;

    }
};
