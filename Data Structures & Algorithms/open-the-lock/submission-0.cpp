class Solution {
public:
    int bfs(unordered_set<string>& dead, string target) {
        if (dead.count("0000")) return -1;

        unordered_map<string, int> visited;
        queue<string> q;

        q.push("0000");
        visited["0000"] = 0;

        while (!q.empty()) {
            string curr = q.front();
            q.pop();

            if (curr == target) return visited[curr];

            for (int i = 0; i < 4; i++) {
                string next = curr;
                next[i]++;
                if (next[i] > '9') next[i] = '0';

                if (!dead.count(next) && !visited.count(next)) {
                    visited[next] = visited[curr] + 1;
                    q.push(next);
                }

                next = curr;
                next[i]--;
                if (next[i] < '0') next[i] = '9';

                if (!dead.count(next) && !visited.count(next)) {
                    visited[next] = visited[curr] + 1;
                    q.push(next);
                }
            }
        }

        return -1;
    }

    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        return bfs(dead, target);
    }
};