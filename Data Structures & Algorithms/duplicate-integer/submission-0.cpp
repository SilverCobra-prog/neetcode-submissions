class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, string> count;
        for(int i = 0; i < nums.size(); i++) {
            if(count[nums[i]] == "found") return true;
            count[nums[i]] = "found";
        }
        return false;
    }
};
