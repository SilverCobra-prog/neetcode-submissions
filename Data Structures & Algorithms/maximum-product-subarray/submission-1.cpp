class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<long long> maxPos(n + 1);
        vector<long long> maxNeg(n + 1);
        if(nums.size()==1) return nums[0];

        maxPos[0] = 1;
        maxNeg[0] = 1;

        for (int i = 1; i <= n; i++) {
            if (nums[i - 1] == 0) {
                maxPos[i] = 0;
                maxNeg[i] = 0;
            } else if (nums[i - 1] < 0) {
                maxPos[i] = max((long long)nums[i - 1], maxNeg[i - 1] * nums[i - 1]);
                maxNeg[i] = min((long long)nums[i - 1], maxPos[i - 1] * nums[i - 1]);
            } else {
                maxPos[i] = max((long long)nums[i - 1], maxPos[i - 1] * nums[i - 1]);
                maxNeg[i] = min((long long)nums[i - 1], maxNeg[i - 1] * nums[i - 1]);
            }
        }

        long long ans = 0;
        for(int i = 1; i <= n; i++) {
            ans = max(ans, maxPos[i]);
        }

        return ans;
    }
};
