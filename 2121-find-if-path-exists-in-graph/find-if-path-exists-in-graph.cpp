// https://leetcode.com/problems/find-if-path-exists-in-graph/

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        unordered_map<int, vector<int>> addList;
        for(auto x: edges){
            vector<int>temp = x;
            
            int u = temp[0];
            int v = temp[1];
            
             addList[u].push_back(v);
             addList[v].push_back(u);
        }
        
        vector<bool>visited(n+1, false);
        
        queue<int>q;
        q.push(source);
        visited[source] = true;
        
        while(!q.empty()){
            
            int v = q.front();
            q.pop();
            
            vector<int>temp = addList[v];
            for(int i=0; i<temp.size(); i++){
                int vertex = temp[i];
                if(visited[vertex] == false){
                    q.push(vertex);
                    visited[vertex] = true;
                }

            }
            
            if(visited[destination])
                return visited[destination];
        }
        
        return visited[destination];   
    }
};