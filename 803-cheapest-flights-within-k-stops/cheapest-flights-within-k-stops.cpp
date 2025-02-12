class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // adjacency list 
        vector<vector<pair<int, int>>> adj(n);
        for (auto& flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }
        // Queue instead of PriorityQueue
        queue<pair<int, pair<int, int>>> Q;
        Q.push({src, {0, 0}}); 

        //firstly distence is  markedd infinity
        vector<int> dist(n, 1e9);
        // distenc of source node is marked das zero
        dist[src] = 0;

        while (!Q.empty()) {
            auto current = Q.front();
            Q.pop();

            int node = current.first;
            int cost = current.second.first;
            int stops = current.second.second;

            if (stops > k) continue;
            for (auto& neighbor : adj[node]) {
                int adjNode = neighbor.first;
                int price = neighbor.second;
                if (cost + price < dist[adjNode]) {
                    dist[adjNode] = cost + price;
                    Q.push({adjNode, {dist[adjNode], stops + 1}});
                }
            }
        }

        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};
