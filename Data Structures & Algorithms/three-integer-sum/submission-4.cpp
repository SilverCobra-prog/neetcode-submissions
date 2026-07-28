class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums.size() < 3) return {};
        set<vector<int>> ans;
        for(int i = 0; i < nums.size()-2; i++) {
            int left = i+1;
            int right = nums.size()-1;
            while(left < right) {
                if(nums[i] + nums[left] + nums[right] == 0) {
                    ans.insert({nums[i], nums[left], nums[right]});
                    left++;
                } else if (nums[i] + nums[left] + nums[right] > 0) {
                    right--;
                } else {
                    left++;
                }
            }
        }
        vector<vector<int>> anss(ans.begin(), ans.end());
        return anss;
    }
};
