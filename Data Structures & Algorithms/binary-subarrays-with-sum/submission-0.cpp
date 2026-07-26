class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        vector<int> prefixSum(nums.size()+1);
        prefixSum[0] = nums[0];
        
        for(int i = 0; i < nums.size(); i++) {
            prefixSum[i + 1] = nums[i] + prefixSum[i];
        }



        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i; j < nums.size(); j++) {
                if(prefixSum[j+1]-prefixSum[i] == goal) {
                    ans++;
                }
            }
        }
        return ans;
    }
};