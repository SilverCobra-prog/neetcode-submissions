class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = cost.size();
        vector<int> netGas(n);
        int totalNet = 0;
        int currNet = 0;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            netGas[i] = gas[i] - cost[i];
            currNet += netGas[i];
            totalNet += netGas[i];
            if(currNet < 0) {
                currNet = 0;
                ans = i+1;
            }
        }

        if(totalNet < 0) return -1;
        return ans;
    }
};
