class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> lastSeen;
        for(int i = 0; i < nums.size(); i++) {
            lastSeen[nums[i]] = INT_MAX;
        }

        for(int i = 0; i < nums.size(); i++) {
            if(abs(i - lastSeen[nums[i]]) <= k) {
                return true;
            } else {
                lastSeen[nums[i]] = i;
            }
        }
        return false;
    }
};