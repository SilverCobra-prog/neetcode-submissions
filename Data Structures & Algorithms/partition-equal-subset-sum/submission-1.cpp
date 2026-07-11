class Solution {
public:
    bool canPartition(vector<int>& nums) {
        unordered_set<int> canMake;

        int sum = 0;


        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            vector<int> add;
            for (int n : canMake) {
                add.push_back(n + nums[i]);
            }
            canMake.insert(nums[i]);
            for (int x : add) {
                canMake.insert(x);
            }
        }

        if(sum % 2 == 1) return false;
        return canMake.contains(sum / 2);
    }
};
