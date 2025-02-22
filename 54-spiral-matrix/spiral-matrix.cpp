class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty())
            return {};

        int m = matrix.size(), n = matrix[0].size();
        int sr = 0, sc = 0, er = m - 1, ec = n - 1;
        vector<int> ans;

        while (sr <= er &&sc <= ec) {
            // left to right
            for (int j = sc; j <= ec; j++)
                ans.push_back(matrix[sr][j]);
            // top to bottom
            for (int i = sr + 1; i <= er; i++)
                ans.push_back(matrix[i][ec]);
            // right to left
            if (sr < er) {
                for (int j = ec - 1; j >= sc; j--)
                    ans.push_back(matrix[er][j]);
            }
            // bottom to top
            if (sc < ec) {
                for (int i = er - 1; i > sr; i--)
                    ans.push_back(matrix[i][sc]);
            }
            sr++, sc++, er--, ec--;
        }
        return ans;
    }
};
