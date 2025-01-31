class Solution {
public:
    bool topoSort(unordered_map<int, vector<int>>& adj, int& n,
                  vector<int> &indegree) {
        queue<int> q;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                cnt++;
                q.push(i);
            }
        }
        while (!q.empty()) {

            int u = q.front();
            q.pop();
            for (int &v : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    cnt++;
                    q.push(v);
                }
            }
         
        }
        return cnt==n;
    }
    bool canFinish(int numCourses, vector<vector<int>>prerequisites) {
        unordered_map<int, vector<int>> adj;
        //khan's algorithem
        vector<int> indegree(numCourses, 0);
        for (auto& vec : prerequisites) {
            int a = vec[0];
            int b = vec[1];
            adj[b].push_back(a);
            indegree[a]++;
        }
        return topoSort(adj, numCourses, indegree);
    }
};