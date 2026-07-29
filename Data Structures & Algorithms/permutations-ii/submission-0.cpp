class Solution {
public:
    vector<vector<int>> permutations(vector<vector<int>> rec, int toAdd) {
        if (rec == vector<vector<int>>{{}}) {
            return {{toAdd}};
        }

        vector<vector<int>> ans;
        map<vector<int>, bool> seen;

        for (int i = 0; i < rec.size(); i++) {
            for (int j = 0; j <= rec[i].size(); j++) {
                vector<int> copy = rec[i];
                copy.insert(copy.begin() + j, toAdd);
                if (!seen[copy]) {
                    seen[copy] = true;
                    ans.push_back(copy);
                }
            }
        }

        return ans;
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans = permutations({{}}, nums[0]);
        for (int i = 1; i < n; i++) {
            ans = permutations(ans, nums[i]);
        }
        return ans;
    }
};
