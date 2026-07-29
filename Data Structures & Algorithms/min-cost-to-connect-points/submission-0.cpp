class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n == 0) return 0;

        auto comp = [](const vector<int>& a, const vector<int>& b) { 
            return a[0] > b[0]; 
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp);

        vector<bool> inMST(n, false);
        int totalCost = 0;
        int edgesUsed = 0;

        pq.push({0, 0});

        while (!pq.empty() && edgesUsed < n) {
            auto top = pq.top();
            pq.pop();

            int cost = top[0];
            int u = top[1];

            if (inMST[u]) continue;

            inMST[u] = true;
            totalCost += cost;
            edgesUsed++;

            for (int v = 0; v < n; v++) {
                if (!inMST[v]) {
                    int dist = abs(points[u][0]-points[v][0]) + abs(points[u][1] - points[v][1]);
                    pq.push({dist, v});
                }
            }
        }

        return totalCost;
    }
};
