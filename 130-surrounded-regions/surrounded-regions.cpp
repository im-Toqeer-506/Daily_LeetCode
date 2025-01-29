class Solution {
private:
    bool isSafe(int r, int c, int m, int n) {
        return (r >= 0 && r < m && c >= 0 && c < n);
    }
    
    void dfs(vector<vector<char>>& board, int r, int c, int m, int n) {
        board[r][c] = '#';
        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        for (int k = 0; k < 4; k++) {
            int nr = r + dir[k][0];
            int nc = c + dir[k][1];
            if (isSafe(nr, nc, m, n) && board[nr][nc] == 'O') {
                dfs(board, nr, nc, m, n);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        
        int m = board.size();
        int n = board[0].size();

       
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') dfs(board, 0, j, m, n);
            if (board[m - 1][j] == 'O') dfs(board, m - 1, j, m, n);
        }
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') dfs(board, i, 0, m, n);
            if (board[i][n - 1] == 'O') dfs(board, i, n - 1, m, n);
        }

        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
