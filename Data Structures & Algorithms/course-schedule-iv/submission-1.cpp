class Solution {
public:

    void floydWarshall(int numCourses, vector<vector<bool>>& adj) {
        for(int k = 0; k < numCourses; k++) {
            for(int i = 0; i < numCourses; i++) {
                for(int j = 0; j < numCourses; j++) {
                    adj[i][j] = (adj[i][k] && adj[k][j]) || adj[i][j];
                }
            }
        }
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> adj(numCourses, vector<bool>(numCourses, false));
        for(int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][0]][prerequisites[i][1]] = true;
        }   

        floydWarshall(numCourses, adj);

        vector<bool> ans(queries.size());

        for(int i = 0; i < queries.size(); i++) {
            ans[i] = adj[queries[i][0]][queries[i][1]];
        }
        return ans;
    }
};