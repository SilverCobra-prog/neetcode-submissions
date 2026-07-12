class Solution {
public:

    unordered_map<int, vector<int>> graph;

    bool dfs(int i, vector<int>& seen) {
        if(seen[i] == 1) return false;
        if(seen[i] == 2) return true;

        seen[i] = 1;

        for(int j = 0; j < graph[i].size(); j++) {
            if(!dfs(graph[i][j], seen)) return false;
        }

        seen[i] = 2;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i = 0; i < prerequisites.size(); i++) {
            int course = prerequisites[i][0];
            int prereq = prerequisites[i][1];

            graph[prereq].push_back(course);
        }
        vector<int> seen(numCourses);
        for (int i = 0; i < numCourses; i++) {
            if (seen[i] == 0) {
                if (!dfs(i, seen)) return false;
            }
        }
        return true;
    }
};