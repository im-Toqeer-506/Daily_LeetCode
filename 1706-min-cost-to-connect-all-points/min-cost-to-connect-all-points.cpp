class Solution {
public:
    int minMST(vector<vector<pair<int, int>>> adj, int n) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push({0, 0});

        vector<bool> mst(n, false);
        int sum = 0;

        while (!pq.empty()) {

            auto p = pq.top();
            pq.pop();

            int wt = p.first;
            int node = p.second;

            if (mst[node] == true)
                continue;

            mst[node] = true;
            sum += wt;

            for (auto& tmp : adj[node]) {

                int neighbor = tmp.first;
                int neighbor_wt = tmp.second;

                if (mst[neighbor] == false) {
                    pq.push({neighbor_wt, neighbor});
                }
            }
        }

        return sum;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                int d = abs(x1 - x2) + abs(y1 - y2);
                adj[i].push_back({j, d});
                adj[j].push_back({i, d});
            }
        }
        return minMST(adj, n);
    }
};