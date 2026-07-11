class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[1], nums[0]);
        int n = nums.size();
        vector<int> robBeg(n);
        vector<int> robEnd(n);

        robBeg[0] = nums[0];
        robBeg[1] = max(nums[0], nums[1]);
        for(int i = 2; i < n-1; i++) {
            robBeg[i] = max(robBeg[i-1], robBeg[i-2]+nums[i]);
        }
        
        robEnd[1] = nums[1];
        for(int i = 2; i < n; i++) {
            robEnd[i] = max(robEnd[i-1], robEnd[i-2]+nums[i]);
        }

        return max(robBeg[n-2], robEnd[n-1]);
    }
};