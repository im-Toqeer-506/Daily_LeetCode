class Solution {
public:
    void dfs(vector<vector<int>>& heights, int row, int col, int prev,
             vector<vector<int>>& ocean) {
        if (row < 0 || row >= heights.size() || col < 0 ||
            col >= heights[0].size())
            return;
        if (heights[row][col] < prev)
            return;
        if (ocean[row][col] == -1)
            return;
        ocean[row][col] = -1;
        dfs(heights, row + 1, col, heights[row][col], ocean);
        dfs(heights, row - 1, col, heights[row][col], ocean);
        dfs(heights, row, col + 1, heights[row][col], ocean);
        dfs(heights, row, col - 1, heights[row][col], ocean);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> ans;
        if (m == 0)
            return ans;
        vector<vector<int>> pacific(m, vector<int>(n, 0));
        vector<vector<int>> atlantic(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            dfs(heights, i, 0, INT_MIN, pacific);
            dfs(heights, i, n - 1, INT_MIN, atlantic);
        }
        for (int j = 0; j < n; j++) {
            dfs(heights, 0, j, INT_MIN, pacific);
            dfs(heights, m - 1, j, INT_MIN, atlantic);
        }

        vector<int> v;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] == -1 && pacific[i][j] == atlantic[i][j]) {
                    v.clear();
                    v.push_back(i);
                    v.push_back(j);
                    ans.push_back(v);
                }
            }
        }
        return ans;
    }
};