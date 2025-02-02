class Solution {
public:
    bool dfs(unordered_map<int, vector<int>>& adj, int u, int v,
             vector<bool>& visited) {
        if (u == v)
            return true;
        visited[u] = true;
        for (auto part : adj[u]) {
            if (visited[part])
                continue;
            if (dfs(adj, part, v, visited))
                return true;
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        unordered_map<int, vector<int>> adj;
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            vector<bool> visited(n, false);
            // bhaio If both nodes are already present or connected!
            if (adj.find(u) != adj.end() && adj.find(v) != adj.end() &&
                dfs(adj, u, v, visited))
                return edge;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return {};
    }
};