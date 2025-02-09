class Solution {
public:
    unordered_map<string, vector<string>> adj; 
    vector<string> result;

    void DFS(string fromAirPort) {
        vector<string>& neighbours = adj[fromAirPort];
        while (!neighbours.empty()) {
            string toAirPort = neighbours.front();
            neighbours.erase(neighbours.begin());
            DFS(toAirPort);
        }

        result.push_back(fromAirPort);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // Source to destination adjacency list
        for (auto& t : tickets) {
            string u = t[0]; 
            string v = t[1];
            adj[u].push_back(v);
        }

        for (auto& edges : adj) {
            sort(edges.second.begin(), edges.second.end());
        }

        DFS("JFK");

       
        reverse(result.begin(), result.end());
        return result;
    }
};
