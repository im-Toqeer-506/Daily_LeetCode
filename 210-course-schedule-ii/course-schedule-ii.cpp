

class Solution {
public:
     vector<int> topoSort(unordered_map<int, vector<int>>& adj, int& n,
                  vector<int> &indegree) {
        queue<int> q;
        vector<int>vec;
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
            vec.push_back(u);
            for (int &v : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    cnt++;
                    q.push(v);
                }
            }
         
        }
       if (vec.size() == n) return vec;
       else return{}; 
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
      unordered_map<int, vector<int>> adj;
      vector<int> indegree(numCourses, 0);
       for (auto& vec : prerequisites) 
       {
            int a = vec[0];
            int b = vec[1];
            adj[b].push_back(a);
            indegree[a]++;
        }  
        return topoSort(adj, numCourses, indegree);
    }
};
