class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for (int i = 0; i < times.size(); i++) {
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            //Directed graph tha bhaio
            adj[u].push_back({v, w});
        }
        //infinity distence rakhna hai bhaio
        vector<int> dist(n + 1, INT_MAX); 
        dist[k] = 0; 

        set<pair<int, int>> st;
        st.insert({0, k}); 

        while (!st.empty()) {
            auto top = *st.begin();
            int nodeDist = top.first; 
            int topNode = top.second; 
            st.erase(st.begin());
            for (auto neighbor : adj[topNode]) {
                int neighborNode = neighbor.first;
                int edgeWeight = neighbor.second;
                if (nodeDist + edgeWeight < dist[neighborNode]) {
                    // Ager node already set ma hai tu uss ko remove karna hai bhaio
                    auto record = st.find({dist[neighborNode], neighborNode});
                    if (record != st.end()) {
                        st.erase(record);
                    }

                    //defunate hai pher distence ko update karna hai
                    dist[neighborNode] = nodeDist + edgeWeight;
                    st.insert({dist[neighborNode], neighborNode});
                }
            }
        }

        
        int maxDist = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1; 
            maxDist = max(maxDist, dist[i]);
        }
        return maxDist;
    }
};
