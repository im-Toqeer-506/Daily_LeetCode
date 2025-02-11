class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        //min-heap  to proocess the cells
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        //puting the starting nodes in the heap
        pq.push({grid[0][0], 0, 0});
        //a visited vector
        vector<vector<int>> vis(n, vector<int>(m, 0));
        //marking the first node to visited
        vis[0][0] = 1;
        vector<int> dr = {0, -1, 0, 1, 0};
        while (!pq.empty()) {
            vector<int> top = pq.top();
            pq.pop();

            int t = top[0];
            int x = top[1];
            int y = top[2];
            //if we reached the end the time will return
            if (x == n - 1 && y == m - 1)
                return t;
            //neighbors are fine
            for (int i = 0; i < 4; i++) {
                int nx = x + dr[i];
                int ny = y + dr[i + 1];
                if (nx >= 0 && ny >= 0 && nx < n && ny < m && vis[nx][ny] == 0) {
                    vis[nx][ny] = 1;
                    pq.push({max(t, grid[nx][ny]), nx, ny});
                }
            }
        }
        return -1; 
    }
};
